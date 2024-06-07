/*!	
	\file    ast.cpp
	\brief   Code of funcitons of AST clas
	\author  
	\date    2018-12-13
	\version 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

// Para usar la funciones pow y std::abs
#include <cmath>

#include "ast.hpp"

#include "../table/table.hpp"

// warning
#include "../error/error.hpp"

// Macros for the screen
#include "../includes/macros.hpp"

// 
#include "../table/numericVariable.hpp"
#include "../table/logicalVariable.hpp"
#include "../table/stringVariable.hpp"

#include "../table/numericConstant.hpp"
#include "../table/logicalConstant.hpp"
#include "../table/stringConstant.hpp"

#include "../table/builtinParameter0.hpp"
#include "../table/builtinParameter1.hpp"
#include "../table/builtinParameter2.hpp"

#include "../parser/interpreter.tab.h"



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

extern lp::Table table; //!< Reference to the Table of Symbols


extern lp::AST *root; //!< Reference to the object at the base of the AST


///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::VariableNode::getType() 
{ 
	// Get the identifier in the table of symbols as Variable
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Return the type of the Variable
	return var->getType();
}


void lp::VariableNode::printAST() 
{
  std::cout << "VariableNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}


double lp::VariableNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *var = (lp::NumericVariable *) table.getSymbol(this->_id);

		// Copy the value of the NumericVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the variable is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}


bool lp::VariableNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalVariable
		lp::LogicalVariable *var = (lp::LogicalVariable *) table.getSymbol(this->_id);

		// Copy the value of the LogicalVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the variable is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}

std::string lp::VariableNode::evaluateString()
{
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringVariable
		lp::StringVariable *var = (lp::StringVariable *) table.getSymbol(this->_id);

		// Copy the value of the StringVariable
		result = var->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the variable is not string",
				   this->_id);
	}

	// Return the value of the StringVariable
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConstantNode::printAST() 
{
  std::cout << "ConstantNode: " << this->_id;
  std::cout << " (Type: " << this->getType() << ")" << std::endl;
}

int lp::ConstantNode::getType() 
{ 
	// Get the identifier in the table of symbols as Constant
	lp::Constant *var = (lp::Constant *) table.getSymbol(this->_id);

	// Return the type of the Constant
	return var->getType();
}


double lp::ConstantNode::evaluateNumber() 
{ 
	double result = 0.0;

	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as NumericConstant
		lp::NumericConstant *constant = (lp::NumericConstant *) table.getSymbol(this->_id);

		// Copy the value of the NumericConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateNumber(): the constant is not numeric", 
				   this->_id);
	}

	// Return the value of the NumericVariable
	return result;
}

bool lp::ConstantNode::evaluateBool() 
{ 
	bool result = false;

	if (this->getType() == BOOL)
	{
		// Get the identifier in the table of symbols as LogicalConstant
		lp::LogicalConstant *constant = (lp::LogicalConstant *) table.getSymbol(this->_id);

		// Copy the value of the LogicalConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateBool(): the constant is not boolean",
				   this->_id);
	}

	// Return the value of the LogicalVariable
	return result;
}

std::string lp::ConstantNode::evaluateString()
{
	std::string result = "";

	if (this->getType() == STRING)
	{
		// Get the identifier in the table of symbols as StringConstant
		lp::StringConstant *constant = (lp::StringConstant *) table.getSymbol(this->_id);

		// Copy the value of the StringConstant
		result = constant->getValue();
	}
	else
	{
		warning("Runtime error in evaluateString(): the constant is not string",
				   this->_id);
	}

	// Return the value of the StringVariable
	return result;

}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
 

int lp::NumberNode::getType()
{
	return NUMBER;
}


void lp::NumberNode::printAST()
{
  std::cout << "NumberNode: " << this->_number << std::endl;
}

double lp::NumberNode::evaluateNumber() 
{ 
    return this->_number; 
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::StringNode::getType()
{
	return STRING;
}

void lp::StringNode::printAST()
{
  std::cout << "StringNode: " << this->_string << std::endl;
}

std::string lp::StringNode::evaluateString() 
{ 
	return this->_string; 
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::NumericUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == NUMBER)
	{
		result = NUMBER;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Numeric Unary Operator");
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalUnaryOperatorNode::getType()
{
	int result;

	if(this->_exp->getType() == BOOL)
	{
		result = BOOL;
	}
	else
	{
		warning("Runtime error: incompatible types for", "Logical Unary Operator");
	}
	
	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::NumericOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = NUMBER;
	else
		warning("Runtime error: incompatible types for", "Numeric Operator");

	return	result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


int lp::RelationalOperatorNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == NUMBER) and (this->_right->getType() == NUMBER))
		result = BOOL;
	else if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
		result = BOOL;
	else if( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = BOOL;
	else
		warning("Runtime error: incompatible types for", "Relational Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::LogicalOperatorNode:: getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == BOOL) and (this->_right->getType() == BOOL))
	{
		// 
		result = BOOL;
	}
	else
		warning("Runtime error: incompatible types for", "Logical Operator");

	return	result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryMinusNode::printAST() 
{
  std::cout << "UnaryMinusNode: -"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryMinusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Minus
		result = - this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "UnaryMinus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::UnaryPlusNode::printAST() 
{
  std::cout << "UnaryPlusNode: +"  << std::endl;
  std::cout << "\t"; 
  this->_exp->printAST();
}

double lp::UnaryPlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		result = this->_exp->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","UnaryPlus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PlusNode::printAST() 
{
  std::cout << "PlusNode: +"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PlusNode::evaluateNumber()
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() + this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Plus");
	}

  return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::MinusNode::printAST() 
{
  std::cout << "MinusNode: -"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MinusNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() - this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ", "Minus");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


void lp::MultiplicationNode::printAST() 
{
  std::cout << "MultiplicationNode: *"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::MultiplicationNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = this->_left->evaluateNumber() * this->_right->evaluateNumber();
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for ","Multiplication");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::DivisionNode::printAST()
{
  std::cout << "DivisionNode: /" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::DivisionNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
		// The divisor is not zero
    	if(std::abs(rightNumber) > ERROR_BOUND)
		{
				result = leftNumber / rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Division");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::IntegerDivisionNode::printAST()
{
  std::cout << "IntegerDivisionNode: //" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::IntegerDivisionNode::evaluateNumber()
{
	int result = 0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		int leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();

	
		// The divisor is not zero
		if(std::abs(rightNumber) > ERROR_BOUND)
		{
			result = (int) leftNumber / (int) rightNumber;
		}
		else
		{
			warning("Runtime error", "Division by zero");
		}
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Integer Division");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ConcatenationNode::printAST()
{
  std::cout << "ConcatenationNode: &" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

int lp::ConcatenationNode::getType()
{
	int result = 0;
		
	if ( (this->_left->getType() == STRING) and (this->_right->getType() == STRING))
		result = STRING;
	else
		warning("Runtime error: incompatible types for", "Concatenation");

	return	result;
}

std::string lp::ConcatenationNode::evaluateString() 
{
	std::string result = "";

	// Ckeck the types of the expressions
	if (this->getType() == STRING)
	{
		result = this->_left->evaluateString() + this->_right->evaluateString();
	}
	else
	{
		warning("Runtime error: the expressions are not string for", "Concatenation");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ModuloNode::printAST()
{
  std::cout << "ModuloNode: %" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::ModuloNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		double leftNumber, rightNumber;

		leftNumber = this->_left->evaluateNumber();
		rightNumber = this->_right->evaluateNumber();
	
    	if(std::abs(rightNumber) > ERROR_BOUND)
				result = (int) leftNumber % (int) rightNumber;
		else
			warning("Runtime error", "Division by zero");
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Modulo");
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PowerNode::printAST() 
{
  std::cout << "PowerNode: ^"  << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

double lp::PowerNode::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		result = pow(this->_left->evaluateNumber(), this->_right->evaluateNumber());
	}
	else
	{
		warning("Runtime error: the expressions are not numeric for", "Power");
	}

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int lp::BuiltinFunctionNode_0::getType()
{
	return	NUMBER;
}


void lp::BuiltinFunctionNode_0::printAST() 
{
  std::cout << "BuiltinFunctionNode_0: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
}

double lp::BuiltinFunctionNode_0::evaluateNumber() 
{
	// Get the identifier in the table of symbols as BuiltinParameter0
	lp::BuiltinParameter0 *f = (lp::BuiltinParameter0 *) table.getSymbol(this->_id);

	// Apply the function and copy the result
   	return f->getFunction()();
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_1::getType()
{
	int result = 0;
		
	if (this->_exp->getType() == NUMBER)
		result = NUMBER;
	else
		warning("Runtime error: incompatible type for", "BuiltinFunctionNode_1");

	return	result;
}

void lp::BuiltinFunctionNode_1::printAST() 
{
  std::cout << "BuiltinFunctionNode_1: "  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;  
  std::cout << "\t";
	this->_exp->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_1::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the type of the expression
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter1
		lp::BuiltinParameter1 *f = (lp::BuiltinParameter1 *) table.getSymbol( this->_id);

		// Apply the function to the parameter and copy the result
		result = f->getFunction()(this->_exp->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible type of parameter for ", this->_id);
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

int lp::BuiltinFunctionNode_2::getType()
{
	int result = 0;
		
	if (this->_exp1->getType() == this->_exp2->getType())
		result = this->_exp1->getType();
	else
		warning("Runtime error: incompatible types for", "BuiltinFunctionNode_2");

	return	result;
}


void lp::BuiltinFunctionNode_2::printAST() 
{
  std::cout << "BuiltinFunctionNode_2: " << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";
  this->_exp1->printAST();
  std::cout << "\t";
	this->_exp2->printAST();
	std::cout << std::endl;
}

double lp::BuiltinFunctionNode_2::evaluateNumber() 
{
	double result = 0.0;

	// Ckeck the types of the expressions
	if (this->getType() == NUMBER)
	{
		// Get the identifier in the table of symbols as BuiltinParameter2
		lp::BuiltinParameter2 *f = (lp::BuiltinParameter2 *) table.getSymbol(this->_id);

		// Apply the function to the parameters and copy the result
	  	result = f->getFunction()(this->_exp1->evaluateNumber(),this->_exp2->evaluateNumber());
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", this->_id);
	}

  return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterThanNode::printAST()
{
  std::cout << "GreaterThanNode: >" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString > rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber > rightNumber);
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::GreaterOrEqualNode::printAST()
{
  std::cout << "GreaterOrEqualNode: >= " << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::GreaterOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString >= rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber >= rightNumber);
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Greater or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessThanNode::printAST()
{
  std::cout << "LessThanNode: <" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessThanNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString < rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber < rightNumber);
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less than");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::LessOrEqualNode::printAST()
{
  std::cout << "LessOrEqualNode: <=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::LessOrEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		if(this->_left->getType() == STRING && this->_right->getType() == STRING)
		{
			std::string leftString, rightString;
			leftString = this->_left->evaluateString();
			rightString = this->_right->evaluateString();

			result = (leftString <= rightString);
		}
		else if(this->_left->getType() == NUMBER && this->_right->getType() == NUMBER)
		{
			double leftNumber, rightNumber;
			leftNumber = this->_left->evaluateNumber();
			rightNumber = this->_right->evaluateNumber();

			result = (leftNumber <= rightNumber);
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Less or equal than");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EqualNode::printAST()
{
  std::cout << "EqualNode: ==" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::EqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		double leftNumber = 0.0, rightNumber = 0.0;
		std::string leftString = "", rightString = "";
		bool leftBoolean = false, rightBoolean = false;

		switch(this->_left->getType()){
			case NUMBER:
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) < ERROR_BOUND );
				break;
			case STRING:
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				//  Compare the strings
				result = (leftString == rightString);
				break;
			case BOOL:
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean == rightBoolean);
				break;
			default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", 
						"Equal operator");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotEqualNode::printAST()
{
  std::cout << "NotEqualNode: !=" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::NotEqualNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		std::string leftString, rightString;
		switch(this->_left->getType()){
			case NUMBER:
				double leftNumber, rightNumber;
				leftNumber = this->_left->evaluateNumber();
				rightNumber = this->_right->evaluateNumber();

				// ERROR_BOUND to control the precision of real numbers
				result = ( std::abs(leftNumber - rightNumber) >= ERROR_BOUND );
			break;
			case STRING:
				leftString = this->_left->evaluateString();
				rightString = this->_right->evaluateString();

				//  Compare the strings
				result = (leftString != rightString);
			break;
			case BOOL:
				bool leftBoolean, rightBoolean;
				leftBoolean = this->_left->evaluateBool();
				rightBoolean = this->_right->evaluateBool();

				// 
				result = (leftBoolean != rightBoolean);
				break;
		  default:
				warning("Runtime error: incompatible types of parameters for ", 
								"Not Equal operator");				
		}
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "Not Equal operator");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AndNode::printAST()
{
  std::cout << "AndNode: &&" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::AndNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool and rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator And");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::OrNode::printAST()
{
  std::cout << "OrNode: ||" << std::endl;
  std::cout << "\t"; 
	this->_left->printAST();
	std::cout << "\t"; 
	this->_right->printAST();
}

bool lp::OrNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		bool leftBool, rightBool;

		leftBool = this->_left->evaluateBool();
		rightBool = this->_right->evaluateBool();

		result = leftBool or rightBool;
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Or");
	}

	return result;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::NotNode::printAST()
{
  std::cout << "NotNode: !" << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
}

bool lp::NotNode::evaluateBool() 
{
	bool result = false;

	if (this->getType() == BOOL)
	{
		result = not this->_exp->evaluateBool();
	}
	else
	{
		warning("Runtime error: incompatible types of parameters for ", "operator Not");
	}

	return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AssignmentStmt::printAST() 
{
  std::cout << "assignment_node: ="  << std::endl;
  std::cout << "\t";
  std::cout << this->_id << std::endl;
  std::cout << "\t";

  // Check the expression
	if (this->_exp != NULL)
	{
	  this->_exp->printAST();
    std::cout << std::endl;
  }
  // this->_asgn is not NULL: multiple assingment
  else 
    this->_asgn->printAST();

}

void lp::AssignmentStmt::evaluate() 
{
	/* Get the identifier in the table of symbols as Variable */
	/* 
		a = 2;
		a = b = 2;

		a: firstVar
		b: secondVar
	*/
	lp::Variable *firstVar = (lp::Variable *) table.getSymbol(this->_id);

	// Check the expression
	if (this->_exp != NULL)
	{
		// Check the type of the expression of the asgn
		switch(this->_exp->getType())
		{
			case NUMBER:
			{
				double value;
				// evaluate the expression as NUMBER
			 	value = this->_exp->evaluateNumber();

				// Check the type of the first varible
				if (firstVar->getType() == NUMBER)
				{
				  	// Get the identifier in the table of symbols as NumericVariable
					lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value 
					lp::NumericVariable *v = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,value);
					table.installSymbol(v);
				}
			}
			break;

			case STRING:
			{
				std::string value;
				// evaluate the expression as STRING
			 	value = this->_exp->evaluateString();

				if (firstVar->getType() == STRING)
				{
					std::cout << "STRING" << std::endl;
				  	// Get the identifier in the table of symbols as StringVariable
					lp::StringVariable *v = (lp::StringVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not STRING
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as StringVariable 
					// with the type STRING and the value 

					lp::StringVariable *v = new lp::StringVariable(this->_id,
											VARIABLE,STRING,value);
					

					table.installSymbol(v);
				}
			}
			break;

			case BOOL:
			{
				bool value;
				// evaluate the expression as BOOL
			 	value = this->_exp->evaluateBool();

				if (firstVar->getType() == BOOL)
				{
				  	// Get the identifier in the table of symbols as LogicalVariable
					lp::LogicalVariable *v = (lp::LogicalVariable *) table.getSymbol(this->_id);

					// Assignment the value to the identifier in the table of symbols
					v->setValue(value);
				}
				// The type of variable is not BOOL
				else
				{
					// Delete the variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value 
					lp::LogicalVariable *v = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,value);
					table.installSymbol(v);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}

	}

	//////////////////////////////////////////////
	// Allow multiple assigment -> a = b = c = 2;

	else // this->_asgn is not NULL
	{
		// IMPORTANT
		//  evaluate the assigment child
		this->_asgn->evaluate();


		/* Get the identifier of the previous asgn in the table of symbols as Variable */
		lp::Variable *secondVar = (lp::Variable *) table.getSymbol(this->_asgn->_id);

		// Get the type of the variable of the previous asgn
		switch(secondVar->getType())
		{
			case NUMBER:
			{
				/* Get the identifier of the previous asgn in the table of symbols as NumericVariable */
				lp::NumericVariable *secondVar = (lp::NumericVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == NUMBER)
				{
				/* Get the identifier of the first variable in the table of symbols as NumericVariable */
				lp::NumericVariable *firstVar = (lp::NumericVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not NUMBER
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type NUMBER and the value of the previous variable 
					lp::NumericVariable *firstVar = new lp::NumericVariable(this->_id,
											VARIABLE,NUMBER,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			case STRING:
			{
				/* Get the identifier of the previous asgn in the table of symbols as StringVariable */
				lp::StringVariable *secondVar = (lp::StringVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == STRING)
				{
				/* Get the identifier of the first variable in the table of symbols as StringVariable */
				lp::StringVariable *firstVar = (lp::StringVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as StringVariable
					//lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);	

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not STRING
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as StringVariable 
					// with the type STRING and the value of the previous variable 
					lp::StringVariable *firstVar = new lp::StringVariable(this->_id,
											VARIABLE,STRING,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}

			case BOOL:
			{
				/* Get the identifier of the previous asgn in the table of symbols as LogicalVariable */
				lp::LogicalVariable *secondVar = (lp::LogicalVariable *) table.getSymbol(this->_asgn->_id);
				// Check the type of the first variable
				if (firstVar->getType() == BOOL)
				{
				/* Get the identifier of the first variable in the table of symbols as LogicalVariable */
				lp::LogicalVariable *firstVar = (lp::LogicalVariable *) table.getSymbol(this->_id);
				  	// Get the identifier o f the in the table of symbols as NumericVariable
//					lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);

					// Assignment the value of the second variable to the first variable
					firstVar->setValue(secondVar->getValue());

				}
				// The type of variable is not BOOL
				else
				{
					// Delete the first variable from the table of symbols 
					table.eraseSymbol(this->_id);

					// Insert the first variable in the table of symbols as NumericVariable 
					// with the type BOOL and the value of the previous variable 
					lp::LogicalVariable *firstVar = new lp::LogicalVariable(this->_id,
											VARIABLE,BOOL,secondVar->getValue());
					table.installSymbol(firstVar);
				}
			}
			break;

			default:
				warning("Runtime error: incompatible type of expression for ", "Assigment");
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::PrintStmt::printAST() 
{
  std::cout << "printASTStmt: printAST"  << std::endl;
  std::cout << "\t";
  this->_exp->printAST();
  std::cout << std::endl;
}


void lp::PrintStmt::evaluate() 
{
	// std::cout << BIYELLOW; 
	// std::cout << "print: ";
	// std::cout << RESET; 

	std::string str;

	switch(this->_exp->getType())
	{
		case NUMBER:
				std::cout << this->_exp->evaluateNumber() << std::endl;
				break;
		case STRING:
				str = this->_exp->evaluateString();
				// Quitar comillas si existen
				if (!str.empty() && str[0] == '\'' && str[str.length() -1] == '\'') {
					str = str.substr(1, str.size() - 2);
				}
				for(std::size_t i = 0; i < str.size(); i++)
				{
					if (str[i] == '\\')
					{
						if (str[i+1] == 'n')
						{
							std::cout << std::endl;
							i++;
						}else if (str[i+1] == 't')
						{
							std::cout << "\t";
							i++;
						}else if(str[i+1] == '\\')
						{
							std::cout << str[i+1];
							i++;
						}
						else
							std::cout << str[i];
					}
					else
						std::cout << str[i];
				}
				break;
		case BOOL:
			if (this->_exp->evaluateBool())
				std::cout << "verdadero" << std::endl;
			else
				std::cout << "falso" << std::endl;
		
			break;

		default:
			warning("Runtime error: incompatible type for ", "print");
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStmt::printAST() 
{
  std::cout << "ReadStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}


void lp::ReadStmt::evaluate() 
{   
	double value;
	// std::cout << BIYELLOW; 
	// std::cout << "Insert a numeric value --> " ;
	// std::cout << RESET; 
	std::cin >> value;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is NUMBER
	if (var->getType() == NUMBER)
	{
		/* Get the identifier in the table of symbols as NumericVariable */
		lp::NumericVariable *n = (lp::NumericVariable *) table.getSymbol(this->_id);
						
		/* Assignment the read value to the identifier */
		n->setValue(value);
	}
	// The type of variable is not NUMBER
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as NumericVariable 
		// with the type NUMBER and the read value 
		lp::NumericVariable *n = new lp::NumericVariable(this->_id, 
									  VARIABLE,NUMBER,value);

		table.installSymbol(n);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::ReadStringStmt::printAST() 
{
  std::cout << "ReadStringStmt: read"  << std::endl;
  std::cout << "\t";
  std::cout << this->_id;
  std::cout << std::endl;
}

void lp::ReadStringStmt::evaluate(){
	std::string value;
	std::cout << BIYELLOW; 
	std::cout << "Insert a string value --> " ;
	std::cout << RESET; 
	std::cin >> value;

	/* Get the identifier in the table of symbols as Variable */
	lp::Variable *var = (lp::Variable *) table.getSymbol(this->_id);

	// Check if the type of the variable is STRING
	if (var->getType() == STRING)
	{
		/* Get the identifier in the table of symbols as StringVariable */
		lp::StringVariable *n = (lp::StringVariable *) table.getSymbol(this->_id);
						
		/* Assignment the read value to the identifier */
		n->setValue(value);
	}
	// The type of variable is not STRING
	else
	{
		// Delete $1 from the table of symbols as Variable
		table.eraseSymbol(this->_id);

			// Insert $1 in the table of symbols as StringVariable 
		// with the type STRING and the read value 
		lp::StringVariable *n = new lp::StringVariable(this->_id, 
									  VARIABLE,STRING,value);

		table.installSymbol(n);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::EmptyStmt::printAST() 
{
  std::cout << "EmptyStmt "  << std::endl;
}

void lp::EmptyStmt::evaluate() 
{
  // Empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::IfStmt::printAST() 
{
  std::cout << "IfStmt: "  << std::endl;
  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  // Consequent
  std::cout << "\t";
  std::list<Statement*>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
  {
	(*stmtIter)->printAST();
  }

  // Alternative
  if (this->_stmts2 != NULL)
  {
	std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
	{
		(*stmtIter)->printAST();
	}
  }

  std::cout << std::endl;
}


void lp::IfStmt::evaluate() 
{
   // If the condition is true,
	if (this->_cond->evaluateBool() == true){
		std::list<Statement*>::iterator stmtIter;

		for (stmtIter = this->_stmts1->begin(); stmtIter != this->_stmts1->end(); stmtIter++) 
		{
			(*stmtIter)->evaluate();
		}
	}
    // Otherwise, the alternative is run if exists
	else if (this->_stmts2 != NULL){
		std::list<Statement*>::iterator stmtIter;

		for (stmtIter = this->_stmts2->begin(); stmtIter != this->_stmts2->end(); stmtIter++) 
		{
			(*stmtIter)->evaluate();
		}
	}
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::WhileStmt::printAST() 
{
  	std::cout << "WhileStmt: "  << std::endl;
  // Condition
	std::cout << "\t";
	this->_cond->printAST();

  // Body of the while loop
    std::list<Statement*>::iterator stmtIter;

	std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->printAST();
	}

 	std::cout << std::endl;
}


void lp::WhileStmt::evaluate() 
{
  // While the condition is true. the body is run 
	while (this->_cond->evaluateBool() == true)
	{	
		std::list<Statement*>::iterator stmtIter;

		for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
		{
			(*stmtIter)->evaluate();
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::RepeatStmt::printAST() 
{
  std::cout << "RepeatStmt: "  << std::endl;
  // Body of the repeat loop
  std::cout << "\t";
  std::list<Statement*>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
	 (*stmtIter)->printAST();
  }

  // Condition
  std::cout << "\t";
  this->_cond->printAST();

  std::cout << std::endl;
}

void lp::RepeatStmt::evaluate() 
{
  // Repeat the body until the condition is true
  do
  {
	std::list<Statement*>::iterator stmtIter;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
	  (*stmtIter)->evaluate();
	}
  }
  while (this->_cond->evaluateBool() == false);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::ForStmt::printAST() 
{
	std::cout << "ForStmt: "  << std::endl;
  	// Initialization
  	std::cout << "\t";
  	std::cout << this->_id << std::endl;

  	std::cout << "\t";
  	this->_exp1->printAST();

  	std::cout << "\t";
  	this->_exp2->printAST();

	std::cout << "\t";
  	this->_step->printAST();

  	// Body of the for loop
  	std::cout << "\t";
  	std::list<Statement*>::iterator stmtIter;

	std::cout << "BlockStmt: "  << std::endl;
	
  	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
	{
		(*stmtIter)->printAST();
	}

  	std::cout << std::endl;
}

void lp::ForStmt::evaluate() 
{
	if(this->_exp1->getType() == NUMBER and this->_exp2->getType() == NUMBER and this->_step->getType() == NUMBER)
	{
		if(table.lookupSymbol(this->_id) == true)
		{
			if(table.getSymbol(this->_id)->getToken() == VARIABLE)
			{
				table.eraseSymbol(this->_id);
				lp::NumericVariable *v = new lp::NumericVariable(this->_id, VARIABLE, NUMBER, this->_exp1->evaluateNumber());
				table.installSymbol(v);
			}
		}
		if(this->_step == NULL)
		{
			this->_step = new NumberNode(1);
			
			if(this->_exp1->evaluateNumber() > this->_exp2->evaluateNumber())
			{
				this->_step = new NumberNode(-1);
			}
		} else {

			if((this->_step->evaluateNumber() > 0 && this->_exp1->evaluateNumber() > this->_exp2->evaluateNumber()) || 
				(this->_step->evaluateNumber() < 0 && this->_exp1->evaluateNumber() < this->_exp2->evaluateNumber()))
			{
				warning("For loop is infinite", this->_id);
			}
		}

		// Get the initial value
		double value1 = this->_exp1->evaluateNumber();
		// Get the final value
		double value2 = this->_exp2->evaluateNumber();
		// Get the step
		double value3 = this->_step->evaluateNumber();

		// Get the identifier in the table of symbols as NumericVariable
		lp::NumericVariable *v = (lp::NumericVariable *) table.getSymbol(this->_id);

		if(v != NULL){
			// The step is not zero
			if (value3 != 0){

				// The step is positive
				if (value1 < value2)
				{
					// The body is run
					for (double i = value1; i <= value2; i += value3)
					{
						v->setValue(i);

						std::list<Statement *>::iterator stmtIter;
						for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
						{
							(*stmtIter)->evaluate();
						}
					}
				}
				// The step is negative
				else
				{
					// The body is run
					for (double i = value1; i >= value2; i += value3)
					{
						v->setValue(i);

						std::list<Statement *>::iterator stmtIter;
						for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
						{
							(*stmtIter)->evaluate();
						}
					}
				}
			}
			else
			{
				warning("Runtime error: the step is zero in the for loop", "");
			}
		}
	}else
	{
		warning("Runtime error: incompatible types for ", "For loop");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::DefaultStmt::printAST() 
{
	std::cout << "DefaultStmt: "  << std::endl;
	std::cout << "\t";
	std::list<Statement*>::iterator stmtIter;

	std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->printAST();
	}
	std::cout << std::endl;
}

void lp::DefaultStmt::evaluate() 
{
	std::list<Statement*>::iterator stmtIter;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::ValueStmt::printAST() 
{
	std::cout << "ValueStmt: "  << std::endl;
	std::cout << "\t";
	switch(this->getExp()->getType())
	{
		case NUMBER:
		{
			std::cout << this->getExp()->evaluateNumber() << std::endl;
			break;
		}
			
		case STRING:
		{
			std::cout << this->getExp()->evaluateString() << std::endl;
			break;
		}
			
		case BOOL:
		{
			if (this->getExp()->evaluateBool())
				std::cout << "verdadero" << std::endl;
			else
				std::cout << "falso" << std::endl;
			break;
		}
			
		case CONSTANT:
		{
			std::cout << this->getExp()->evaluateNumber() << std::endl;
			break;
		}
			
		case VARIABLE:
		{
			VariableNode *v = (VariableNode *) this->_exp;

			switch(v->getType())
			{
				case NUMBER:
					std::cout << v->evaluateNumber() << std::endl;
					break;
				case STRING:
					std::cout << v->evaluateString() << std::endl;
					break;
				case BOOL:
					if (v->evaluateBool())
						std::cout << "verdadero" << std::endl;
					else
						std::cout << "falso" << std::endl;
					break;
				default:
					warning("Runtime error: incompatible type for ", "Value");
			}
			break;
		}
			
		default:
		{
			warning("Runtime error: incompatible type for ", "Value");
		}	
	}

	std::list<Statement*>::iterator stmtIter;

	std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		std::cout << "\t";
		(*stmtIter)->printAST();
	}

	std::cout << std::endl;
}

void lp::ValueStmt::evaluate() 
{
	std::list<Statement*>::iterator stmtIter;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->evaluate();
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::CaseStmt::printAST() 
{
	std::cout << "CaseStmt: "  << std::endl;
	std::cout << "\t";
	this->_exp->printAST();
	std::cout << "\t";
	std::list<ValueStmt*>::iterator stmtIter;

	std::cout << "BlockStmt: "  << std::endl;

	for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
	{
		(*stmtIter)->printAST();
		std::cout << std::endl;
	}

	if(this->_default != NULL)
	{
		std::cout << "DefaultStmt: "  << std::endl;
		std::cout << "\t";
		this->_default->printAST();
		std::cout << std::endl;
	}else
	{
		std::cout << "No DefaultStmt"  << std::endl;
	}

	std::cout << std::endl;
}

void lp::CaseStmt::evaluate()
{
	bool finish = false, error = false;

	switch(this->_exp->getType())
	{
		case NUMBER:
		{
			double value = this->_exp->evaluateNumber();
			std::list<ValueStmt*>::iterator stmtIter;

			for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				if((*stmtIter)->getExp()->getType() == NUMBER)
				{
					if((*stmtIter)->getExp()->evaluateNumber() == value)
					{
						(*stmtIter)->evaluate();
						finish = true;
						break;
					}
				}
				else
				{
					warning("Runtime error: incompatible type for ", "Case");
					error = true;
					break;
				}
			}

			if(!finish && !error)
			{
				if(this->_default != NULL)
				{
					this->_default->evaluate();
					finish = true;
				}
			}
			break;
		}
		
		case STRING:
		{
			std::string value = this->_exp->evaluateString();
			std::list<ValueStmt*>::iterator stmtIter;

			for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				if((*stmtIter)->getExp()->getType() == STRING)
				{
					if((*stmtIter)->getExp()->evaluateString() == value)
					{
						(*stmtIter)->evaluate();
						finish = true;
						break;
					}
				}
				else
				{
					warning("Runtime error: incompatible type for ", "Case");
					error = true;
					break;
				}
			}

			if(!finish && !error)
			{
				if(this->_default != NULL)
				{
					this->_default->evaluate();
					finish = true;
				}
			}
			break;
		}
		case BOOL:
		{
			bool value = this->_exp->evaluateBool();
			std::list<ValueStmt*>::iterator stmtIter;

			for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
			{
				if((*stmtIter)->getExp()->getType() == BOOL)
				{
					if((*stmtIter)->getExp()->evaluateBool() == value)
					{
						(*stmtIter)->evaluate();
						finish = true;
						break;
					}
				}
				else
				{
					warning("Runtime error: incompatible type for ", "Case");
					error = true;
					break;
				}
			}

			if(!finish && !error)
			{
				if(this->_default != NULL)
				{
					this->_default->evaluate();
					finish = true;
				}
			}
			break;
		}
		case VARIABLE:
		{
			VariableNode *v = (VariableNode *) this->_exp;
			std::list<ValueStmt*>::iterator stmtIter;

			for(stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
			{
				if(v->getType() == NUMBER)
				{
					if((*stmtIter)->getExp()->getType() == NUMBER)
					{
						if((*stmtIter)->getExp()->evaluateNumber() == v->evaluateNumber())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}else if(v->getType() == STRING)
				{
					if((*stmtIter)->getExp()->getType() == STRING)
					{
						if((*stmtIter)->getExp()->evaluateString() == v->evaluateString())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}else if(v->getType() == BOOL)
				{
					if((*stmtIter)->getExp()->getType() == BOOL)
					{
						if((*stmtIter)->getExp()->evaluateBool() == v->evaluateBool())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}
				else{
					warning("Runtime error: incompatible type for ", "Case");
					error = true;
					break;
				}

			}

			if(!finish && !error)
			{
				if(this->_default != NULL)
				{
					this->_default->evaluate();
					finish = true;
				}
			}
		}
		case CONSTANT:
		{
			ConstantNode *c = (ConstantNode *) this->_exp;
			std::list<ValueStmt*>::iterator stmtIter;

			for(stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++)
			{
				if(c->getType() == NUMBER)
				{
					if((*stmtIter)->getExp()->getType() == NUMBER)
					{
						if((*stmtIter)->getExp()->evaluateNumber() == c->evaluateNumber())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}else if(c->getType() == STRING)
				{
					if((*stmtIter)->getExp()->getType() == STRING)
					{
						if((*stmtIter)->getExp()->evaluateString() == c->evaluateString())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}else if(c->getType() == BOOL)
				{
					if((*stmtIter)->getExp()->getType() == BOOL)
					{
						if((*stmtIter)->getExp()->evaluateBool() == c->evaluateBool())
						{
							(*stmtIter)->evaluate();
							finish = true;
							break;
						}
					}
				}else
				{
					warning("Runtime error: incompatible type for ", "Case");
					error = true;
					break;
				}

			}

			if(!finish && !error)
			{
				if(this->_default != NULL)
				{
					this->_default->evaluate();
					finish = true;
				}
			}
		}
		default:
		{
			warning("Runtime error: incompatible type for ", "Case");
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::ClearStmt::printAST() 
{
	std::cout << "ClearStmt: "  << std::endl;
	std::cout << "\t";
}

void lp::ClearStmt::evaluate() 
{
  // Clear the screen
	std::cout << CLEAR_SCREEN;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::PlaceStmt::printAST() 
{
	std::cout << "PlaceStmt: "  << std::endl;
	std::cout << "\t";
	this->_exp1->printAST();
	std::cout << "\t";
	this->_exp2->printAST();
}

void lp::PlaceStmt::evaluate() 
{
  // Place the cursor in the position (x,y)
	int x, y;

	x = this->_exp1->evaluateNumber();
	y = this->_exp2->evaluateNumber();

	std::cout << PLACE(x, y);
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in Compiler

void lp::CommentStmt::printAST() 
{
	std::cout << "CommentStmt: "  << std::endl;
	std::cout << "\t";
	std::cout << this->_comment << std::endl;
}

void lp::CommentStmt::evaluate() 
{
  // Empty
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// NEW in example 17

void lp::BlockStmt::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  std::cout << "BlockStmt: "  << std::endl;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}


void lp::BlockStmt::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = this->_stmts->begin(); stmtIter != this->_stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void lp::AST::printAST() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
     (*stmtIter)->printAST();
  }
}



void lp::AST::evaluate() 
{
  std::list<Statement *>::iterator stmtIter;

  for (stmtIter = stmts->begin(); stmtIter != stmts->end(); stmtIter++) 
  {
    (*stmtIter)->evaluate();
  }
}



#include <iostream>

#include "stringConstant.hpp"

/*
 Definitions of the read and write functions of the StringConstant class 
*/

void lp::StringConstant::read()
{
  // Inherited attributes
   std::cout << "Name of the StringConstant: ";
   std::cin >> this->_name;

   std::cout << "Token of the StringConstant: ";
   std::cin >> this->_token;
   // The \n character is read 
   std::cin.ignore();

    std::cout << "Type of the StringConstant: ";
    std::cin >> this->_type;
    // The \n character is read
    std::cin.ignore();

    // Own attribute
    std::cout << "Value of the StringConstant: ";
    std::cin >> this->_value;
    // The \n character is read
    std::cin.ignore();
}


void lp::StringConstant::write() const
{
    // Inherited methods
    std::cout << "Name:" << this->getName() << std::endl;
    std::cout << "Token:" << this->getToken() << std::endl;
    std::cout << "Type:" << this->getType() << std::endl;

    // Own method
    std::cout << "Value:" << this->getValue() << std::endl;
}

lp::StringConstant &lp::StringConstant::operator=(const lp::StringConstant &n)
{
    // Check that is not the current object
    if (this != &n)
    {
        // Inherited methods
        this->setName(n.getName());

        this->setToken(n.getToken());

        this->setType(n.getType());

        // Own method
        this->setValue(n.getValue());
    }

    return *this;
}

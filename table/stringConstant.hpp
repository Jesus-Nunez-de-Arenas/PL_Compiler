#ifndef STRINGCONSTANT_HPP
#define STRINGCONSTANT_HPP

#include <string>
#include <iostream>

#include "constant.hpp"

/*!	
    \namespace lp
    \brief Name space for the subject Language Processors
*/
namespace lp{

/*!	
    \class StringConstant
    \brief Definition of atributes and methods of StringConstant class
    \note  StringConstant Class publicly inherits from Constant class
*/
class StringConstant:public lp::Constant
{
/*!
    \name Private atributes of StringConstant class
*/
    private:
        std::string      _value;   //!< \brief String value of the StringConstant

/*!
    \name Public methods of StringConstant class
*/
    public:

/*!
    \name Constructors
*/

/*!
    \brief Constructor with arguments with default values
    \note  Inline function that uses Constant's constructor as members initializer
    \param name: name of the StringConstant
    \param token: token of the StringConstant
    \param type: type of the StringConstant
    \param value: string value of the StringConstant
    \pre   None
    \post  A new StringConstant is created with the values of the parameters
    \sa   setName, setValue
*/
    inline StringConstant(std::string name="", int token = 0, int type = 0, std::string value=""): 
        Constant(name,token,type)
    {
        this->setValue(value);
    }   

/*!
    \brief Copy constructor
    \note  Inline function
    \param n: object of StringConstant class
    \pre   None
    \post  A new StringConstant is created with the values of the object n
    \sa    setName, setValue
*/
    inline StringConstant(const StringConstant &n)
    {
        this->setName(n.getName());

        this->setToken(n.getToken());

        this->setType(n.getType());

        this->setValue(n.getValue());
    }

/*!

    \brief Destructor of the class StringConstant
    \note  Inline function
    \pre   None
    \post  The StringConstant object is destroyed
*/
    inline ~StringConstant()
    {
    }

/*!
    \name Observers
*/


/*!
    \brief  Public method that returns the value of the StringConstant
    \note   Inline function
    \pre    None
    \post   None
    \return Value of the StringConstant
    \sa     getValue
*/
    inline std::string getValue() const
    {
        return this->_value;
    }

/*!
    \name Modifiers
*/

/*!
    \brief   This functions modifies the value of the StringConstant
    \note    Inline function
    \param   value: new value of the StringConstant
    \pre     None
    \post    The value of the StringConstant is equal to the parameter 
*/
    inline void setValue(std::string value)
    {
        this->_value = value;
    }

/*!
    \name I/O Functions
*/

/*!
    \brief   Public method that reads the attributes of the StringConstant
    \note    Virtual method
    \pre     None
    \post    The atributes of the StringConstant are modified with the inserted values
*/
    void read();

/*!
    \brief   Public method that writes the attributes of the StringConstant
    \note    Virtual method
    \pre     None
    \post    None
*/
    void write() const;

/*!
    \name Operator
*/

/*!
    \brief  Assignment Operator
    \note   Virtual method: can be redefined in the heir class
    \param  n: object of StringConstant class
    \pre    None
    \post   The atributes of this object are equal to the atributes of the parameter
    \return Reference to this object
*/
    StringConstant &operator=(const StringConstant &n);

};

}

#endif
#include <iostream>
#include "Token.hpp"

Token::Token( void ) : _value(""), _type(UNKNOWN)
{
}

Token::Token(Token const & src)
{
	*this = src;
}

Token::~Token( void )
{
}

Token &						Token::operator=(Token const & rhs)
{
	this->_value = rhs._value;
	this->_type = rhs._type;
	return *this;
}

std::string					Token::getValue( void ) const
{
	return this->_value;
}

tokenType					Token::getType( void ) const
{
	return this->_type;
}

void						Token::setValue(std::string const val)
{
	this->_value = val;
}

void						Token::setType(tokenType const tkn)
{
	this->_type = tkn;
}

std::ostream &				operator<<(std::ostream & o, Token const & rhs)
{
	o << rhs.getValue() << " | ";
	switch (rhs.getType())
	{
		case OPERATOR:
			o << "Operator";
			break;

		case TYPE:
			o << "Type";
			break;

		case OPENING_PAR:
			o << "Opening_Par";
			break;

		case CLOSING_PAR:
			o << "Closing_Par";
			break;

		case NATURAL_VAL:
			o << "Natural Value";
			break;

		case FLOATING_VAL:
			o << "Floating Value";
			break;

		case SEPARATOR:
			o << "Separator";
			break;

		default:
			o << "Unknown";
			break;
	}
	return o;
}

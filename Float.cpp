#include "Calculator.hpp"
#include "Float.hpp"

Float::Float( void ) : _value(0)
{
}

Float::Float(std::string const & value) : _value(value)
{
}

Float::Float(Float const & src)
{
	*this = src;
}

Float::~Float( void )
{
}

Float &				Float::operator=(Float const & rhs)
{
	this->_value = rhs._value;
	return *this;
}

int					Float::getPrecision( void ) const
{
	return 3;
}

eOperandType		Float::getType( void ) const
{
	return FLOAT;
}

IOperand const *	Float::operator+( IOperand const & rhs ) const
{
	return (Calculator::add(*this, rhs));
}

IOperand const *	Float::operator-( IOperand const & rhs ) const
{
	return (Calculator::sub(*this, rhs));
}

IOperand const *	Float::operator*( IOperand const & rhs ) const
{
	return (Calculator::mul(*this, rhs));
}

IOperand const *	Float::operator/( IOperand const & rhs ) const
{
	return (Calculator::div(*this, rhs));
}

IOperand const *	Float::operator%( IOperand const & rhs ) const
{
	return (Calculator::mod(*this, rhs));
}

std::string const & Float::toString( void ) const
{
	return this->_value;
}

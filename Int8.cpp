#include "Calculator.hpp"
#include "Int8.hpp"

Int8::Int8( void ) : _value(0)
{
}

Int8::Int8(std::string const & value) : _value(value)
{
}

Int8::Int8(Int8 const & src)
{
	*this = src;
}

Int8::~Int8( void )
{
}

Int8 &				Int8::operator=(Int8 const & rhs)
{
	this->_value = rhs._value;
	return *this;
}

int					Int8::getPrecision( void ) const
{
	return 0;
}

eOperandType		Int8::getType( void ) const
{
	return INT8;
}

IOperand const *	Int8::operator+( IOperand const & rhs ) const
{
	return (Calculator::add(*this, rhs));
}

IOperand const *	Int8::operator-( IOperand const & rhs ) const
{
	return (Calculator::sub(*this, rhs));
}

IOperand const *	Int8::operator*( IOperand const & rhs ) const
{
	return (Calculator::mul(*this, rhs));
}

IOperand const *	Int8::operator/( IOperand const & rhs ) const
{
	return (Calculator::div(*this, rhs));
}

IOperand const *	Int8::operator%( IOperand const & rhs ) const
{
	return (Calculator::mod(*this, rhs));
}

std::string const & Int8::toString( void ) const
{
	return this->_value;
}

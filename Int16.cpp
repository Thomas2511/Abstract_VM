#include "Calculator.hpp"
#include "Int16.hpp"

Int16::Int16( void ) : _value(0)
{
}

Int16::Int16(std::string const & value) : _value(value)
{
}

Int16::Int16(Int16 const & src)
{
	*this = src;
}

Int16::~Int16( void )
{
}

Int16 &				Int16::operator=(Int16 const & rhs)
{
	this->_value = rhs._value;
	return *this;
}

int					Int16::getPrecision( void ) const
{
	return 1;
}

eOperandType		Int16::getType( void ) const
{
	return INT16;
}

IOperand const *	Int16::operator+( IOperand const & rhs ) const
{
	return (Calculator::add(*this, rhs));
}

IOperand const *	Int16::operator-( IOperand const & rhs ) const
{
	return (Calculator::sub(*this, rhs));
}

IOperand const *	Int16::operator*( IOperand const & rhs ) const
{
	return (Calculator::mul(*this, rhs));
}

IOperand const *	Int16::operator/( IOperand const & rhs ) const
{
	return (Calculator::div(*this, rhs));
}

IOperand const *	Int16::operator%( IOperand const & rhs ) const
{
	return (Calculator::mod(*this, rhs));
}

std::string const & Int16::toString( void ) const
{
	return this->_value;
}

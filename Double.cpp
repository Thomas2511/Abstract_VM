#include "Calculator.hpp"
#include "Double.hpp"

Double::Double( void ) : _value(0)
{
}

Double::Double(std::string const & value) : _value(value)
{
}

Double::Double(Double const & src)
{
	*this = src;
}

Double::~Double( void )
{
}

Double &				Double::operator=(Double const & rhs)
{
	this->_value = rhs._value;
	return *this;
}

int					Double::getPrecision( void ) const
{
	return 4;
}

eOperandType		Double::getType( void ) const
{
	return DOUBLE;
}

IOperand const *	Double::operator+( IOperand const & rhs ) const
{
	return (Calculator::add(*this, rhs));
}

IOperand const *	Double::operator-( IOperand const & rhs ) const
{
	return (Calculator::sub(*this, rhs));
}

IOperand const *	Double::operator*( IOperand const & rhs ) const
{
	return (Calculator::mul(*this, rhs));
}

IOperand const *	Double::operator/( IOperand const & rhs ) const
{
	return (Calculator::div(*this, rhs));
}

IOperand const *	Double::operator%( IOperand const & rhs ) const
{
	return (Calculator::mod(*this, rhs));
}

std::string const & Double::toString( void ) const
{
	return this->_value;
}

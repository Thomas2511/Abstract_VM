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
	Calculator		calc;

	return (calc.add(*this, rhs));
}

IOperand const *	Int16::operator-( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.sub(*this, rhs));
}

IOperand const *	Int16::operator*( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mul(*this, rhs));
}

IOperand const *	Int16::operator/( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.div(*this, rhs));
}

IOperand const *	Int16::operator%( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mod(*this, rhs));
}

std::string const & Int16::toString( void ) const
{
	return this->_value;
}

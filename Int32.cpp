#include "Calculator.hpp"
#include "Int32.hpp"

Int32::Int32( void ) : _value(0)
{
}

Int32::Int32(std::string const & value) : _value(value)
{
}

Int32::Int32(Int32 const & src)
{
	*this = src;
}

Int32::~Int32( void )
{
}

Int32 &				Int32::operator=(Int32 const & rhs)
{
	this->_value = rhs._value;
	return *this;
}

int					Int32::getPrecision( void ) const
{
	return 2;
}

eOperandType		Int32::getType( void ) const
{
	return INT32;
}

IOperand const *	Int32::operator+( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.add(*this, rhs));
}

IOperand const *	Int32::operator-( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.sub(*this, rhs));
}

IOperand const *	Int32::operator*( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mul(*this, rhs));
}

IOperand const *	Int32::operator/( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.div(*this, rhs));
}

IOperand const *	Int32::operator%( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mod(*this, rhs));
}

std::string const & Int32::toString( void ) const
{
	return this->_value;
}

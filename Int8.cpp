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
	Calculator		calc;

	return (calc.add(*this, rhs));
}

IOperand const *	Int8::operator-( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.sub(*this, rhs));
}

IOperand const *	Int8::operator*( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mul(*this, rhs));
}

IOperand const *	Int8::operator/( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.div(*this, rhs));
}

IOperand const *	Int8::operator%( IOperand const & rhs ) const
{
	Calculator		calc;

	return (calc.mod(*this, rhs));
}

std::string const & Int8::toString( void ) const
{
	return this->_value;
}

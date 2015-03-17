#include "OperandFactory.hpp"

const char *	OperandFactory::OperandUnderflowException::what() const throw()
{
	return "Operand Underflow";
}

const char *	OperandFactory::OperandOverflowException::what() const throw()
{
	return "Operand Overflow";
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	f tab[] =
	{
		&OperandFactory::_createInt8,
		&OperandFactory::_createInt16,
		&OperandFactory::_createInt32,
		&OperandFactory::_createFloat,
		&OperandFactory::_createDouble
	};
	return ((this->*tab[type])(value));
}

IOperand const * OperandFactory::_createInt8( std::string const & value ) const
{
	double				dvalue = std::atof(value.c_str());
	int					ivalue;
	std::stringstream	ss;

	if (dvalue < std::numeric_limits<char>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<char>::max())
		throw OperandOverflowException();
	ivalue = static_cast<int>(dvalue);
	ss << ivalue;
	return (new Int8(ss.str()));
}

IOperand const * OperandFactory::_createInt16( std::string const & value ) const
{
	double				dvalue = std::atof(value.c_str());
	int					ivalue;
	std::stringstream	ss;

	if (dvalue < std::numeric_limits<short int>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<short int>::max())
		throw OperandOverflowException();
	ivalue = static_cast<int>(dvalue);
	ss << ivalue;
	return (new Int16(ss.str()));
}

IOperand const * OperandFactory::_createInt32( std::string const & value ) const
{
	double				dvalue = std::atof(value.c_str());
	int					ivalue;
	std::stringstream	ss;

	if (dvalue < std::numeric_limits<int>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<int>::max())
		throw OperandOverflowException();
	ivalue = static_cast<int>(dvalue);
	ss << ivalue;
	return (new Int32(ss.str()));
}

IOperand const * OperandFactory::_createFloat( std::string const & value ) const
{
	double			dvalue = std::atof(value.c_str());

	if (abs(dvalue) > 0.0 && abs(dvalue) < std::numeric_limits<float>::min())
		throw OperandUnderflowException();
	if (abs(dvalue) > std::numeric_limits<float>::max())
		throw OperandOverflowException();
	return (new Float(value));
}

IOperand const * OperandFactory::_createDouble( std::string const & value ) const
{
	double			dvalue = std::atof(value.c_str());

	if (abs(dvalue) > 0.0 && abs(dvalue) < std::numeric_limits<double>::min())
		throw OperandUnderflowException();
	if (abs(dvalue) > std::numeric_limits<double>::max())
		throw OperandOverflowException();
	return (new Double(value));
}

OperandFactory::OperandFactory( void )
{
	return ;
}

OperandFactory::~OperandFactory( void )
{
	return ;
}

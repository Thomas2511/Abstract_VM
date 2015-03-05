#include "OperandFactory.hpp"

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
	std::string		str = this->_trimFloat(value);
	double			dvalue = std::atof(str.c_str());

	if (dvalue < std::numeric_limits<char>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<char>::max())
		throw OperandOverflowException();
	return (new Int8(str));
}

IOperand const * OperandFactory::_createInt16( std::string const & value ) const
{
	std::string		str = this->_trimFloat(value);
	double			dvalue = std::atof(str.c_str());

	if (dvalue < std::numeric_limits<short int>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<short int>::max())
		throw OperandOverflowException();
	return (new Int16(str));
}

IOperand const * OperandFactory::_createInt32( std::string const & value ) const
{
	std::string		str = this->_trimFloat(value);
	double			dvalue = std::atof(str.c_str());

	if (dvalue < std::numeric_limits<int>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<int>::max())
		throw OperandOverflowException();
	return (new Int32(str));
}

IOperand const * OperandFactory::_createFloat( std::string const & value ) const
{
	double			dvalue = std::atof(value.c_str());

	if (dvalue < std::numeric_limits<float>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<float>::max())
		throw OperandOverflowException();
	return (new Float(value));
}

IOperand const * OperandFactory::_createDouble( std::string const & value ) const
{
	double			dvalue = std::atof(value.c_str());

	if (dvalue < std::numeric_limits<double>::min())
		throw OperandUnderflowException();
	if (dvalue > std::numeric_limits<double>::max())
		throw OperandOverflowException();
	return (new Double(value));
}

std::string		OperandFactory::_trimFloat( std::string const & value ) const
{
	size_t found = value.find_first_of(".", 0);
	if (found != std::string::npos)
		return (value.substr(0, found));
	return (value);
}

OperandFactory::OperandFactory( void )
{
	return ;
}

OperandFactory::~OperandFactory( void )
{
	return ;
}

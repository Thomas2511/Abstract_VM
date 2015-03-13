#include "Calculator.hpp"

const char *			Calculator::FloatingPointException::what() const throw()
{
	return "Floating Point";
}

IOperand const *		Calculator::add(IOperand const & lhs, IOperand const & rhs)
{
	double				lv;
	double				rv;
	eOperandType		type;
	OperandFactory		fact;
	std::stringstream	ss;

	lv = std::atof(lhs.toString().c_str());
	rv = std::atof(rhs.toString().c_str());
	type = lhs.getPrecision() < rhs.getPrecision() ? rhs.getType() : lhs.getType();
	lv = lv + rv;
	ss << lv;
	return (fact.createOperand(type, ss.str()));
}

IOperand const *		Calculator::sub(IOperand const & lhs, IOperand const & rhs)
{
	double				lv;
	double				rv;
	eOperandType		type;
	OperandFactory		fact;
	std::stringstream	ss;

	lv = std::atof(lhs.toString().c_str());
	rv = std::atof(rhs.toString().c_str());
	type = lhs.getPrecision() < rhs.getPrecision() ? rhs.getType() : lhs.getType();
	lv = lv - rv;
	ss << lv;
	return (fact.createOperand(type, ss.str()));
}

IOperand const *		Calculator::mul(IOperand const & lhs, IOperand const & rhs)
{
	double				lv;
	double				rv;
	eOperandType		type;
	OperandFactory		fact;
	std::stringstream	ss;

	lv = std::atof(lhs.toString().c_str());
	rv = std::atof(rhs.toString().c_str());
	type = lhs.getPrecision() < rhs.getPrecision() ? rhs.getType() : lhs.getType();
	lv = lv * rv;
	ss << lv;
	return (fact.createOperand(type, ss.str()));
}

IOperand const *		Calculator::div(IOperand const & lhs, IOperand const & rhs)
{
	double				lv;
	double				rv;
	eOperandType		type;
	OperandFactory		fact;
	std::stringstream	ss;

	lv = std::atof(lhs.toString().c_str());
	rv = std::atof(rhs.toString().c_str());
	type = lhs.getPrecision() < rhs.getPrecision() ? rhs.getType() : lhs.getType();
	if (rv == 0)
		throw Calculator::FloatingPointException();
	else
		lv = lv / rv;
	ss << lv;
	return (fact.createOperand(type, ss.str()));
}

IOperand const *		Calculator::mod(IOperand const & lhs, IOperand const & rhs)
{
	double				lv;
	double				rv;
	eOperandType		type;
	OperandFactory		fact;
	std::stringstream	ss;

	lv = std::atof(lhs.toString().c_str());
	rv = std::atof(rhs.toString().c_str());
	type = lhs.getPrecision() < rhs.getPrecision() ? rhs.getType() : lhs.getType();
	if (rv == 0)
		throw Calculator::FloatingPointException();
	else
		lv = fmod(lv, rv);
	ss << lv;
	return (fact.createOperand(type, ss.str()));
}

#include "Operator.hpp"

const char *			Operator::StackTooShortException::what() const throw()
{
	return "Stack contains less than two elements.";
}

const char *			Operator::EmptyStackException::what() const throw()
{
	return "Empty Stack";
}

const char *			Operator::AssertErrorException::what() const throw()
{
	return "Assert Error";
}

Operator::Operator(command cmd, int line) : _cmd(cmd), _line(line)
{
}

Operator::Operator(command cmd, eOperandType op, int line, std::string value) : _cmd(cmd), _operand(op), _line(line), _value(value)
{
}

Operator::Operator(Operator const & src)
{
	*this = src;
}

Operator::~Operator( void )
{
}

Operator &				Operator::operator=(Operator const & rhs)
{
	this->_cmd = rhs._cmd;
	this->_operand = rhs._operand;
	this->_line = rhs._line;
	return *this;
}

bool					Operator::callCommand(std::list<const IOperand *> & lst)
{
	bool				b;

	fun					f[] =
	{
		&Operator::_push,
		&Operator::_pop,
		&Operator::_dump,
		&Operator::_assert,
		&Operator::_add,
		&Operator::_sub,
		&Operator::_mul,
		&Operator::_div,
		&Operator::_mod,
		&Operator::_print,
		&Operator::_exit
	};
	try
	{
		b = (this->*f[this->getCommand()])(lst);
	}
	catch (OperatorException & e)
	{
		std::cerr << "Line " << this->_line << ": Error :";
		throw ;
	}
	return b;
}

command					Operator::getCommand( void )
{
	return this->_cmd;
}

eOperandType			Operator::getType( void )
{
	return this->_operand;
}

int						Operator::getLineNum( void )
{
	return this->_line;
}

std::string				Operator::getValue( void )
{
	return this->_value;
}

bool					Operator::_push(std::list<const IOperand *> & lst)
{
	OperandFactory		of;

	try
	{
		lst.push_front(of.createOperand(this->_operand, this->_value));
	}
	catch (OperandFactory::OperandOverflowException & e)
	{
		std::cerr << "Line " << this->_line << ": Error :";
		throw ;
	}
	catch (OperandFactory::OperandUnderflowException & e)
	{
		std::cerr << "Line " << this->_line << ": Error :";
		throw ;
	}
	return (false);
}

bool					Operator::_pop(std::list<const IOperand *> & lst)
{
	if (lst.empty())
		throw EmptyStackException();
	lst.pop_front();
	return (false);
}

bool					Operator::_dump(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		it;

	for (it = lst.begin(); it != lst.end(); ++it)
		std::cout << (*it)->toString() << std::endl;
	return (false);
}

bool					Operator::_assert(std::list<const IOperand *> & lst)
{
	if (lst.front()->toString().compare(this->_value))
		throw AssertErrorException();
	return (false);
}

bool					Operator::_add(std::list<const IOperand *> & lst)
{
	const IOperand *							lhs;
	const IOperand *							rhs;

	if (lst.size() < 2)
		throw StackTooShortException();
	rhs = (*lst.begin());
	lst.pop_front();
	lhs = (*lst.begin());
	lst.pop_front();
	lst.push_back(*lhs + *rhs);
	delete lhs;
	delete rhs;
	return (false);
}

bool					Operator::_sub(std::list<const IOperand *> & lst)
{
	const IOperand *							lhs;
	const IOperand *							rhs;

	if (lst.size() < 2)
		throw StackTooShortException();
	rhs = (*lst.begin());
	lst.pop_front();
	lhs = (*lst.begin());
	lst.pop_front();
	lst.push_back(*lhs - *rhs);
	delete lhs;
	delete rhs;
	return (false);
}

bool					Operator::_mul(std::list<const IOperand *> & lst)
{
	const IOperand *							lhs;
	const IOperand *							rhs;

	if (lst.size() < 2)
		throw StackTooShortException();
	rhs = (*lst.begin());
	lst.pop_front();
	lhs = (*lst.begin());
	lst.pop_front();
	lst.push_back(*lhs * *rhs);
	delete lhs;
	delete rhs;
	return (false);
}

bool					Operator::_div(std::list<const IOperand *> & lst)
{
	const IOperand *							lhs;
	const IOperand *							rhs;

	if (lst.size() < 2)
		throw StackTooShortException();
	rhs = (*lst.begin());
	lst.pop_front();
	lhs = (*lst.begin());
	lst.pop_front();
	try
	{
		lst.push_back(*lhs / *rhs);
	}
	catch (Calculator::FloatingPointException & e)
	{
		std::cerr << "Line " << this->_line << ": Error :";
	}
	delete lhs;
	delete rhs;
	return (false);
}

bool					Operator::_mod(std::list<const IOperand *> & lst)
{
	const IOperand *							lhs;
	const IOperand *							rhs;

	if (lst.size() < 2)
		throw StackTooShortException();
	rhs = (*lst.begin());
	lst.pop_front();
	lhs = (*lst.begin());
	lst.pop_front();
	try
	{
		lst.push_back(*lhs % *rhs);
	}
	catch (Calculator::FloatingPointException & e)
	{
		std::cerr << "Line " << this->_line << ": Error :";
	}
	delete lhs;
	delete rhs;
	return (false);
}

bool					Operator::_print(std::list<const IOperand *> & lst)
{
	if (lst.size() == 0)
		throw EmptyStackException();
	if (lst.front()->getType() != INT8)
		throw AssertErrorException();
	std::cout << static_cast<char>(atoi(lst.front()->toString().c_str())) << std::endl;;
	return (false);
}

bool					Operator::_exit(std::list<const IOperand *> & lst)
{
	static_cast<void>(lst);
	return (true);
}

#include "Operator.hpp"

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
	return (this->*f[this->getCommand()])(lst);
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

	lst.push_front(of.createOperand(this->_operand, this->_value));
	return (false);
}

bool					Operator::_pop(std::list<const IOperand *> & lst)
{
	if (lst.size() == 0)
		throw Operator::EmptyStackException::EmptyStackException();
	lst.pop_front();
	return (false);
}

bool					Operator::_dump(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		it;

	for (it = lst.begin(); it != lst.end(); ++it)
		std::cout << (*it)->toString();
	return (false);
}

bool					Operator::_assert(std::list<const IOperand *> & lst)
{
	if (lst.front()->toString().compare(this->_value))
		throw Operator::AssertErrorException::AssertErrorException();
	return (false);
}

bool					Operator::_add(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	lhs = lst.begin();
	++lhs;
	rhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) + *(*rhs));
	delete *lhs;
	delete *rhs;
	return (false);
}

bool					Operator::_sub(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	lhs = lst.begin();
	++lhs;
	rhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) - *(*rhs));
	delete *lhs;
	delete *rhs;
	return (false);
}

bool					Operator::_mul(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	lhs = lst.begin();
	++lhs;
	rhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) * *(*rhs));
	delete *lhs;
	delete *rhs;
	return (false);
}

bool					Operator::_div(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	lhs = lst.begin();
	++lhs;
	rhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) / *(*rhs));
	delete *lhs;
	delete *rhs;
	return (false);
}

bool					Operator::_mod(std::list<const IOperand *> & lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	lhs = lst.begin();
	++lhs;
	rhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) % *(*rhs));
	delete *lhs;
	delete *rhs;
	return (false);
}

bool					Operator::_print(std::list<const IOperand *> & lst)
{
	if (lst.size() == 0)
		throw Operator::EmptyStackException::EmptyStackException();
	if (lst.front()->getType() != INT8)
		throw Operator::AssertErrorException::AssertErrorException();
	std::cout << static_cast<char>(atoi(lst.front()->toString().c_str()));
	return (false);
}

bool					Operator::_exit(std::list<const IOperand *> & lst)
{
	static_cast<void>(lst);
	return (true);
}

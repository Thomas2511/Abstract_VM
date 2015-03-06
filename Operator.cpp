#include "Operator.hpp"

const char *			Operator::EmptyStackException::what() const throw()
{
	return "Empty Stack";
}

const char *			Operator::AssertErrorException::what() const throw()
{
	return "Assert Error";
}

Operator::Operator(Command cmd, int line) : _cmd(cmd), _line(line)
{
}

Operator::Operator(Command cmd, eOperandType op, int line, std::string value) : _cmd(cmd), _operand(op), _line(line), _value(value)
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

void					Operator::_push(std::list<const IOperand *> lst)
{
	OperandFactory		of;

	lst.push_front(of.createOperand(this->_operand, this->_value));
}

void					Operator::_pop(std::list<const IOperand *> lst)
{
	if (lst.size() == 0)
		throw Operator::EmptyStackException::EmptyStackException();
	lst.pop_front();
}

void					Operator::_dump(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		it;

	for (it = lst.begin(); it != lst.end(); --it)
		(*it)->toString();
}

void					Operator::_assert(std::list<const IOperand *> lst)
{
	if (lst.front()->toString().compare(this->_value))
		throw Operator::AssertErrorException::AssertErrorException();
}

void					Operator::_add(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	rhs = lst.begin();
	++rhs;
	lhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) + *(*rhs));
}

void					Operator::_sub(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	rhs = lst.begin();
	++rhs;
	lhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) - *(*rhs));
}

void					Operator::_mul(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	rhs = lst.begin();
	++rhs;
	lhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) * *(*rhs));
}

void					Operator::_div(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	rhs = lst.begin();
	++rhs;
	lhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) / *(*rhs));
}

void					Operator::_mod(std::list<const IOperand *> lst)
{
	std::list<const IOperand *>::iterator		lhs;
	std::list<const IOperand *>::iterator		rhs;

	rhs = lst.begin();
	++rhs;
	lhs = lst.begin();
	Operator::_pop(lst);
	Operator::_pop(lst);
	lst.push_back(*(*lhs) % *(*rhs));
}

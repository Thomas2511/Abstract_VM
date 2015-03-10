#include "Execution.hpp"

Execution::~Execution( void )
{
}

std::list<Operator *>			Execution::createExecutionList(std::list<Token> tkns)
{
	std::list<Operator *>		op;
	std::list<Token>::iterator	it;
	Token						tk;
	Token						tk2;

	for (it = tkns.begin(); it != tkns.end(); ++it)
	{
		if ((*it).getType() == OPERATOR_VAL)
		{
			tk = *it;
			it++;
			it++;
			tk2 = *it;
			op.push_back(new Operator(_checkCommand(tk), _checkOperand(tk2), (*it).getLineNum(), (*it).getValue()));
			it++;
		}
		if ((*it).getType() == OPERATOR)
			op.push_back(new Operator(_checkCommand(tk), (*it).getLineNum()));
	}
	return op;
}

Command							Execution::_checkCommand(Token tkn)
{
	std::string					tab[] =
	{
		"push",
		"pop",
		"dump",
		"assert",
		"add",
		"sub",
		"mul",
		"div",
		"mod",
		"print",
		"exit"
	};

	for (int i = 0; i < 11; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
			return (static_cast<Command>(i));
	}
	return static_cast<Command>(0);
}

eOperandType					Execution::_checkOperand(Token tkn)
{
	std::string					tab[] =
	{
		"Int8",
		"Int16",
		"Int32",
		"Float",
		"Double"
	};

	for (int i = 0; i < 5; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
			return (static_cast<eOperandType>(i));
	}
	return (static_cast<eOperandType>(0));
}

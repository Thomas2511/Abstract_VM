#include "Analyzer.hpp"

const char *		Analyzer::UnknownInstructionException::what() const throw()
{
	return "Unknown Instruction";
}

bool				Analyzer::analyzer(std::list<Token> * tkns)
{
	f				tab[] = {
		&Analyzer::isOperator,
		&Analyzer::isOperatorVal,
		&Analyzer::isPrecisionInt,
		&Analyzer::isPrecisionFloat,
		&Analyzer::isOpeningPar,
		&Analyzer::isClosingPar,
		&Analyzer::isNaturalVal,
		&Analyzer::isFloatingVal,
		&Analyzer::isSeparator
	};
	std::list<Token>::iterator		it;
	for (it = tkns->begin(); it != tkns->end(); ++it)
	{
		for (int i = 0; i < 9; i++)
		{
			if (tab[i](*it))
				break;
		}
		if ((*it).getType() == UNKNOWN)
			throw Analyzer::UnknownInstructionException::UnknownInstructionException();
	}
	int nb = tkns->back().getLineNum();
	tkns->push_back(Token(END_OF_FILE, nb));
	return true;
}

bool				Analyzer::isOperator(Token & tkn)
{
	std::string		tab[9] = {
		"pop",
		"dump",
		"add",
		"sub",
		"mul",
		"div",
		"mod",
		"print",
		"exit"
	};

	for (int i = 0; i < 9; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(OPERATOR);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::isOperatorVal(Token & tkn)
{
	std::string		tab[2] = {
		"push",
		"assert",
	};

	for (int i = 0; i < 2; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(OPERATOR_VAL);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::isPrecisionInt(Token & tkn)
{
	std::string		tab[3] = {
		"int8",
		"int16",
		"int32"
	};

	for (int i = 0; i < 3; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(PRECISION_INT);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::isPrecisionFloat(Token & tkn)
{
	std::string		tab[2] = {
		"float",
		"double"
	};

	for (int i = 0; i < 2; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(PRECISION_FLOAT);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::isOpeningPar(Token & tkn)
{
	if (tkn.getValue().compare("(") == 0)
	{
		tkn.setType(OPENING_PAR);
		return 1;
	}
	return 0;
}

bool				Analyzer::isClosingPar(Token & tkn)
{
	if (tkn.getValue().compare(")") == 0)
	{
		tkn.setType(CLOSING_PAR);
		return 1;
	}
	return 0;
}

bool				Analyzer::isNaturalVal(Token & tkn)
{
	std::string		value = tkn.getValue();
	unsigned int	i = 0;
	bool			num = 0;

	if (value[i] == '-')
		i++;
	while (i < (value.size() - 1))
	{
		if (!isdigit(value[i]))
			return 0;
		num = 1;
		i++;
	}
	if (!num)
		return 0;
	tkn.setType(NATURAL_VAL);
	return 1;
}

bool				Analyzer::isFloatingVal(Token & tkn)
{
	std::string		value = tkn.getValue();
	size_t			found = value.find_first_of(".");
	unsigned int	i = 0;

	if (value[i] == '-')
		i++;
	if (found == std::string::npos)
		return 0;
	while (i < (value.size() - 1))
	{
		if (!isdigit(value[i]) && i != found)
			return 0;
		i++;
	}
	tkn.setType(FLOATING_VAL);
	return 1;
}

bool				Analyzer::isSeparator(Token & tkn)
{
	if (tkn.getValue().compare("\n") == 0)
	{
		tkn.setType(SEPARATOR);
		return 1;
	}
	return 0;
}

#include "Analyzer.hpp"

void				Analyzer::analyzer(std::list<Token> * tkns)
{
	f				tab[] = {
		&Analyzer::isOperator,
		&Analyzer::isType,
		&Analyzer::isOpeningPar,
		&Analyzer::isClosingPar,
		&Analyzer::isNaturalVal,
		&Analyzer::isFloatingVal,
		&Analyzer::isSeparator
	};
	std::list<Token>::iterator		it;

	for (it = tkns->begin(); it != tkns->end(); ++it)
	{
		for (int i = 0; i < 7; i++)
		{
			if (tab[i](*it))
				break;
		}
		//throw new AnalyzerExcep::AnalyzerExcep(""); TODO AnalyzerExcep
	}
}

bool				Analyzer::isOperator(Token & tkn)
{
	std::string		tab[11] = {
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
		{
			tkn.setType(OPERATOR);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::isType(Token & tkn)
{
	std::string		tab[5] = {
		"int8",
		"int16",
		"int32",
		"float",
		"double"
	};

	for (int i = 0; i < 5; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(TYPE);
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
	size_t			found = value.find_first_of(".");
	unsigned int	i = 0;

	if (value[i] == '-')
		i++;
	if (found != std::string::npos)
		return 0;
	while (i < (value.size() - 1))
	{
		if (!isdigit(value[i]))
			return 0;
		i++;
	}
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

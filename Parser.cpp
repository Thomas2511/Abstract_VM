#include "Parser.hpp"

bool		Parser::parse(std::list<Token> * tokens)
{
	std::list<Token>::const_iterator	it = tokens->begin();

	try
	{
		if (!Parser::isInstr(&it))
			return false;
		while (it != tokens->end())
		{
			if (!Parser::isSeparator(&it) || !Parser::isInstr(&it))
				return false;
		}
	}
	catch (const Parser::ParserExcept & e)
	{
		std::cerr << e.what() << std::endl;
		// TODO : quitter le programme
	}
	catch ( ... )
	{
		std::cerr << "???" << std::endl;
		// TODO : panic
	}
}

bool		Parser::isInstr(std::list<Token>::const_iterator * ptr_it)
{
	if (Parser::isOperator(ptr_it))
	{
		++(*ptr_it);
		return true;
	}
	if (Parser::isOperatorVal(ptr_it))
	{
		++(*ptr_it);
		return (Parser::isValue(ptr_it));
	}
	// TODO : exception : instruction (push | pop | dump | assert | add | sub | mul | div | mod | print | exit) expected
	return false;
}


bool		Parser::isOperator(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPERATOR)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}


bool		Parser::isOperatorVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPERATOR_VAL)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::isValue(std::list<Token>::const_iterator * ptr_it)
{
	if (Parser::isPrecisionInt(ptr_it))
	{
		++(*ptr_it);
		return (Parser::isOpeningPar(ptr_it) || Parser::isNaturalVal(ptr_it) || Parser::isClosingPar(ptr_it));
	}
	if (Parser::isPrecisionFloat(ptr_it))
	{
		++(*ptr_it);
		return (Parser::isOpeningPar(ptr_it) || Parser::isFloatingVal(ptr_it) || Parser::isClosingPar(ptr_it));
	}
	// TODO : exception : precision (int8 | int16 | int32 | float | double) expected
	return false;
}

bool		Parser::isPrecisionInt(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == PRECISION_INT)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::isPrecisionFloat(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == PRECISION_FLOAT)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::isOpeningPar(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPENING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	// TODO : exception : left parenthesis expected
	return false;
}

bool		Parser::isClosingPar(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == CLOSING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	// TODO : exception : right parenthesis expected
	return false;
}

bool		Parser::isNaturalVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == NATURAL_VAL)
	{
		++(*ptr_it);
		return true;
	}
	// TODO : exception : natural value expected
	return false;
}

bool		Parser::isFloatingVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == FLOATING_VAL)
	{
		++(*ptr_it);
		return true;
	}
	// TODO : exception : floating value expected
	return false;
}

bool		Parser::isSeparator(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == SEPARATOR)
	{
		++(*ptr_it);
		return true;
	}
	// TODO : exception : separator expected
	return false;
}

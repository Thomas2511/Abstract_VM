#include "Parser.hpp"

const char *					Parser::InstructionException::what() const throw()
{
	return ("Instruction exception : instruction 'push | pop | dump | assert | add | sub | mul | div | print | exit' expected, got \"");
}

const char *					Parser::PrecisionException::what() const throw()
{
	return ("Precision exception : precision 'int8 | int16 | int32 | float | double' expected, got \"");
}

const char *					Parser::LeftParenthesisException::what() const throw()
{
	return ("Left Parenthesis exception : '(' expected, got \"");
}

const char *					Parser::RightParenthesisException::what() const throw()
{
	return ("Right Parenthesis exception : ')' expected, got \"");
}

const char *					Parser::NaturalValueException::what() const throw()
{
	return ("Natural Value exception : '[-]?[0..9]+' expected, got \"");
}

const char *					Parser::FloatingValueException::what() const throw()
{
	return ("Floating Value exception : '[-]?[0..9]+.[0..9]+' expected, got \"");
}

const char *					Parser::SeparatorException::what() const throw()
{
	return ("Separator exception : '\\n' expected, got \"");
}

bool		Parser::parse(std::list<Token> * tokens)
{
	std::list<Token>::const_iterator	it = tokens->begin();

	try
	{
		while ((*it).getType() == SEPARATOR)
			++it;
		if (!Parser::_isInstr(&it))
			return false;
		while ((*it).getType() != END_OF_FILE)
			if (!Parser::_isSeparator(&it) || !Parser::_isInstr(&it))
				return false;
	}
	catch (const ParserException & e)
	{
		std::cerr << "Line " << (*it).getLineNum() << " : Error : " << e.what() << (*it).getValue() << "\""<< std::endl;
		throw ;
	}
	return true;
}

bool		Parser::_isInstr(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == END_OF_FILE)
		return true;
	if (Parser::_isOperator(ptr_it))
		return true;
	if (Parser::_isOperatorVal(ptr_it))
		return (Parser::_isValue(ptr_it));
	throw InstructionException();
}


bool		Parser::_isOperator(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPERATOR)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}


bool		Parser::_isOperatorVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPERATOR_VAL)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::_isValue(std::list<Token>::const_iterator * ptr_it)
{
	if (Parser::_isPrecisionInt(ptr_it))
		return (Parser::_isLeftParenthesis(ptr_it) && Parser::_isNaturalVal(ptr_it) && Parser::_isRightParenthesis(ptr_it));
	if (Parser::_isPrecisionFloat(ptr_it))
		return (Parser::_isLeftParenthesis(ptr_it) && Parser::_isFloatingVal(ptr_it) && Parser::_isRightParenthesis(ptr_it));
	throw PrecisionException();
}

bool		Parser::_isPrecisionInt(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == PRECISION_INT)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::_isPrecisionFloat(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == PRECISION_FLOAT)
	{
		++(*ptr_it);
		return true;
	}
	return false;
}

bool		Parser::_isLeftParenthesis(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPENING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	throw LeftParenthesisException();
}

bool		Parser::_isRightParenthesis(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == CLOSING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	throw RightParenthesisException();
}

bool		Parser::_isNaturalVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == NATURAL_VAL)
	{
		++(*ptr_it);
		return true;
	}
	throw NaturalValueException();
}

bool		Parser::_isFloatingVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == FLOATING_VAL)
	{
		++(*ptr_it);
		return true;
	}
	throw FloatingValueException();
}

bool		Parser::_isSeparator(std::list<Token>::const_iterator * ptr_it)
{
	int		i = 0;

	while ((*(*ptr_it)).getType() == SEPARATOR)
	{
		++(*ptr_it);
		i++;
	}
	if (i > 0)
		return true;
	throw SeparatorException();
}

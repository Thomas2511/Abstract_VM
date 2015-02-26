#include "Parser.hpp"

Parser::ParserExcept::ParserExcept( void )
{
}

Parser::ParserExcept::ParserExcept(std::string error, size_t line) : _errorMessage(error), _lineNum(line)
{
}

Parser::ParserExcept::ParserExcept(Parser::ParserExcept const & src)
{
	*this = src;
}

Parser::ParserExcept::~ParserExcept( void ) throw()
{
}

Parser::ParserExcept &		Parser::ParserExcept::operator=(Parser::ParserExcept const & rhs)
{
	this->_errorMessage = rhs._errorMessage;
	this->_lineNum = rhs._lineNum;
	return *this;
}

const char *				Parser::ParserExcept::what() const throw()
{
	std::stringstream		ss;

	ss << "Line " << this->_lineNum << ": Error : " << this->_errorMessage;
	return ss.str().c_str();
}

bool		Parser::parse(std::list<Token> * tokens)
{
	std::list<Token>::const_iterator	it = tokens->begin();

	while ((*it).getType() == SEPARATOR)
		++it;
	if (!Parser::_isInstr(&it))
		return false;
	while ((*it).getType() != END_OF_FILE)
		if (!Parser::_isSeparator(&it) || !Parser::_isInstr(&it))
			return false;
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
	throw Parser::ParserExcept("Parser Exception : instruction (push | pop | dump | assert | add | sub | mul | div | mod | print | exit) expected.", (*(*ptr_it)).getLineNum());
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
		return (Parser::_isOpeningPar(ptr_it) && Parser::_isNaturalVal(ptr_it) && Parser::_isClosingPar(ptr_it));
	if (Parser::_isPrecisionFloat(ptr_it))
		return (Parser::_isOpeningPar(ptr_it) && Parser::_isFloatingVal(ptr_it) && Parser::_isClosingPar(ptr_it));
	throw Parser::ParserExcept("Parser Exception : precision (int8 | int16 | int32 | float | double) expected.", (*(*ptr_it)).getLineNum());
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

bool		Parser::_isOpeningPar(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == OPENING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	throw Parser::ParserExcept("Parser Exception : Opening Parenthesis expected.", (*(*ptr_it)).getLineNum());
}

bool		Parser::_isClosingPar(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == CLOSING_PAR)
	{
		++(*ptr_it);
		return true;
	}
	throw Parser::ParserExcept("Parser Exception : Closing Parenthesis expected.", (*(*ptr_it)).getLineNum());
}

bool		Parser::_isNaturalVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == NATURAL_VAL)
	{
		++(*ptr_it);
		return true;
	}
	throw Parser::ParserExcept("Parser Exception : Natural Value expected.", (*(*ptr_it)).getLineNum());
}

bool		Parser::_isFloatingVal(std::list<Token>::const_iterator * ptr_it)
{
	if ((*(*ptr_it)).getType() == FLOATING_VAL)
	{
		++(*ptr_it);
		return true;
	}
	throw Parser::ParserExcept("Parser Exception : Floating Value expected.", (*(*ptr_it)).getLineNum());
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
	throw Parser::ParserExcept("Parser Exception : Separator expected.", (*(*ptr_it)).getLineNum());
}

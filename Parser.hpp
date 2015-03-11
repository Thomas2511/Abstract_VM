#ifndef PARSER_HPP
# define PARSER_HPP

# include <list>
# include <iostream>
# include <sstream>
# include <exception>
# include "Token.hpp"

class Parser
{
	public:
		class ParserException : public std::exception
		{
		};
		class InstructionException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class PrecisionException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class LeftParenthesisException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class RightParenthesisException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class NaturalValueException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class FloatingValueException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		class SeparatorException : public ParserException
		{
			public:
				virtual const char *	what() const throw();
		};
		static bool			parse(std::list<Token> * tkns);

	private:
		Parser( void );
		Parser(Parser const & src);
		~Parser( void );
		Parser &			operator=(Parser const & rhs);

		static bool			_isInstr(std::list<Token>::const_iterator * it);
		static bool			_isOperator(std::list<Token>::const_iterator * it);
		static bool			_isOperatorVal(std::list<Token>::const_iterator * it);
		static bool			_isValue(std::list<Token>::const_iterator * it);
		static bool			_isPrecisionInt(std::list<Token>::const_iterator * it);
		static bool			_isPrecisionFloat(std::list<Token>::const_iterator * it);
		static bool			_isLeftParenthesis(std::list<Token>::const_iterator * it);
		static bool			_isRightParenthesis(std::list<Token>::const_iterator * it);
		static bool			_isNaturalVal(std::list<Token>::const_iterator * it);
		static bool			_isFloatingVal(std::list<Token>::const_iterator * it);
		static bool			_isSeparator(std::list<Token>::const_iterator * it);
};

#endif /* PARSER_HPP */

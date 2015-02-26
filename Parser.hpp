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
		class ParserExcept : public std::exception
		{
			public:
				ParserExcept( void );
				ParserExcept(std::string error, size_t line);
				ParserExcept(ParserExcept const & src);
				~ParserExcept( void ) throw();
				ParserExcept &			operator=(ParserExcept const & rhs);
				virtual const char *	what() const throw();

			private:
				std::string				_errorMessage;
				size_t					_lineNum;
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
		static bool			_isOpeningPar(std::list<Token>::const_iterator * it);
		static bool			_isClosingPar(std::list<Token>::const_iterator * it);
		static bool			_isNaturalVal(std::list<Token>::const_iterator * it);
		static bool			_isFloatingVal(std::list<Token>::const_iterator * it);
		static bool			_isSeparator(std::list<Token>::const_iterator * it);
};

#endif /* PARSER_HPP */

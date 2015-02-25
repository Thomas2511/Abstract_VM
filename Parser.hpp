#ifndef PARSER_HPP
# define PARSER_HPP

# include <list>
# include <iostream>
# include <exception>
# include "Token.hpp"

class Parser
{
	public:

		class ParserExcept : public std::exception
		{
			public:
				ParserExcept( void )
				{
				}
				ParserExcept(std::string error) : _errorMessage(error)
				{
				}
				ParserExcept(ParserExcept const & src)
				{
				}
				~ParserExcept( void ) throw()
				{
				}
				ParserExcept &			operator=(ParserExcept const & rhs)
				{
					this->_errorMessage = rhs._errorMessage;
					return *this;
				}
				virtual const char *	what() const throw()
				{
					return this->_errorMessage.c_str();
				}

			private:
				std::string				_errorMessage;
		};

		static bool			parse(std::list<Token> * tkns);
		static bool			isInstr(std::list<Token>::const_iterator * it);
		static bool			isOperator(std::list<Token>::const_iterator * it);
		static bool			isOperatorVal(std::list<Token>::const_iterator * it);
		static bool			isValue(std::list<Token>::const_iterator * it);
		static bool			isPrecisionInt(std::list<Token>::const_iterator * it);
		static bool			isPrecisionFloat(std::list<Token>::const_iterator * it);
		static bool			isOpeningPar(std::list<Token>::const_iterator * it);
		static bool			isClosingPar(std::list<Token>::const_iterator * it);
		static bool			isNaturalVal(std::list<Token>::const_iterator * it);
		static bool			isFloatingVal(std::list<Token>::const_iterator * it);
		static bool			isSeparator(std::list<Token>::const_iterator * it);

	private:
		Parser( void );
		Parser(Parser const & src);
		~Parser( void );
		Parser &	operator=(Parser const & rhs);
};

#endif /* PARSER_HPP */

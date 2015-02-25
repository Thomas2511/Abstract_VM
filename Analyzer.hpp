#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <list>
# include "Token.hpp"

class Analyzer
{
	public:
		static void				analyzer(std::list<Token> * tkns);
		static bool				isOperator(Token & tkn);
		static bool				isOperatorVal(Token & tkn);
		static bool				isPrecisionInt(Token & tkn);
		static bool				isPrecisionFloat(Token & tkn);
		static bool				isOpeningPar(Token & tkn);
		static bool				isClosingPar(Token & tkn);
		static bool				isNaturalVal(Token & tkn);
		static bool				isFloatingVal(Token & tkn);
		static bool				isSeparator(Token & tkn);

	private:
		Analyzer( void );
		Analyzer(Analyzer const & src);
		~Analyzer( void );
		Analyzer &				operator=(Analyzer const & rhs);
};

typedef bool					(*f)(Token & tkn);

#endif /* ANALYZER_HPP */

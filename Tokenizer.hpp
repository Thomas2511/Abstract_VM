#ifndef TOKENIZER_HPP
# define TOKENIZER_HPP

# include <list>
# include "Token.hpp"

class Tokenizer
{
	public:
		static std::list<Token>	*		tokenize(std::string const & content);

	private:
		Tokenizer( void );
		Tokenizer(Tokenizer const & src);
		~Tokenizer( void );
		Tokenizer &						operator=(Tokenizer const & rhs);
		static void						_checkForComments(std::string * value);
};

#endif /* TOKENIZER_HPP */

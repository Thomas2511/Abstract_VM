#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>

enum	tokenType {
	UNKNOWN = 0,
	OPERATOR,
	OPERATOR_VAL,
	PRECISION_INT,
	PRECISION_FLOAT,
	OPENING_PAR,
	CLOSING_PAR,
	NATURAL_VAL,
	FLOATING_VAL,
	SEPARATOR
};

class Token
{
	public:
		Token( void );
		Token(Token const & src);
		~Token( void );
		Token &					operator=(Token const & rhs);

		std::string				getValue( void ) const;
		tokenType				getType( void ) const;
		int						getLineNum( void ) const;
		void					setValue(std::string const val);
		void					setType(tokenType const tkn);
		void					setLineNum(int const nb);

	private:
		std::string				_value;
		tokenType				_type;
		int						_lineNum;

};

std::ostream &					operator<<(std::ostream & o, Token const & rhs);

#endif /* TOKEN_HPP */

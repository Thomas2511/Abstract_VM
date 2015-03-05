#ifndef INT8_HPP
# define INT8_HPP
# include <string>
# include "IOperand.hpp"

class Int8 : public IOperand
{
	public:
		Int8( void );
		Int8(std::string const & value);
		Int8(Int8 const & src);
		~Int8( void );
		Int8 &				operator=(Int8 const & rhs);

		int					getPrecision( void ) const;
		eOperandType		getType( void ) const;

		IOperand const *	operator+( IOperand const & rhs ) const;
		IOperand const *	operator-( IOperand const & rhs ) const;
		IOperand const *	operator*( IOperand const & rhs ) const;
		IOperand const *	operator/( IOperand const & rhs ) const;
		IOperand const *	operator%( IOperand const & rhs ) const;

		std::string const & toString( void ) const;

	private:
		std::string			_value;
};

#endif /* INT8_HPP */

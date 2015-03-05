#ifndef INT32_HPP
# define INT32_HPP
# include <string>
# include "IOperand.hpp"

class Int32 : public IOperand
{
	public:
		Int32( void );
		Int32(std::string const & value);
		Int32(Int32 const & src);
		~Int32( void );
		Int32 &				operator=(Int32 const & rhs);

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

#endif /* INT32_HPP */

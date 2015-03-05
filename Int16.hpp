#ifndef INT16_HPP
# define INT16_HPP
# include <string>
# include "IOperand.hpp"

class Int16 : public IOperand
{
	public:
		Int16( void );
		Int16(std::string const & value);
		Int16(Int16 const & src);
		~Int16( void );
		Int16 &				operator=(Int16 const & rhs);

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

#endif /* INT16_HPP */

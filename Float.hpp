#ifndef FLOAT_HPP
# define FLOAT_HPP
# include <string>
# include "IOperand.hpp"

class Float : public IOperand
{
	public:
		Float( void );
		Float(std::string const & value);
		Float(Float const & src);
		~Float( void );
		Float &				operator=(Float const & rhs);

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

#endif /* FLOAT_HPP */

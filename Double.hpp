#ifndef DOUBLE_HPP
# define DOUBLE_HPP
# include <string>
# include "IOperand.hpp"

class Double : public IOperand
{
	public:
		Double( void );
		Double(std::string const & value);
		Double(Double const & src);
		~Double( void );
		Double &				operator=(Double const & rhs);

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

#endif /* DOUBLE_HPP */

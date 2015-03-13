#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP

# include <cmath>
# include <sstream>
# include <cstdlib>
# include <exception>
# include "IOperand.hpp"
# include "OperandFactory.hpp"

class Calculator
{
	public:
		class FloatingPointException : public std::exception
		{
			public:
				virtual const char *			what() const throw();
		};
		Calculator( void );
		virtual ~Calculator( void );

		static IOperand const *		add(IOperand const & lhs, IOperand const & rhs);
		static IOperand const *		sub(IOperand const & lhs, IOperand const & rhs);
		static IOperand const *		mul(IOperand const & lhs, IOperand const & rhs);
		static IOperand const *		div(IOperand const & lhs, IOperand const & rhs);
		static IOperand const *		mod(IOperand const & lhs, IOperand const & rhs);
};

#endif /* CALCULATOR_HPP */

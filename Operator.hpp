#ifndef OPERATOR_HPP
# define OPERATOR_HPP

# include <list>
# include <exception>
# include "IOperand.hpp"
# include "Calculator.hpp"

enum	Command
{
	PUSH = 0,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT
};

class Operator
{
	public:
		class EmptyStackException : public std::exception //TODO change to prognameException
		{
			public:
				virtual const char * what() const throw();
		};
		class AssertErrorException : public std::exception //TODO change to prognameException
		{
			public:
				virtual const char * what() const throw();
		};
		Operator( void );
		Operator(Command cmd, int line);
		Operator(Command cmd, eOperandType op, int line, std::string value);
		Operator(Operator const & src);
		~Operator( void );
		Operator &				operator=(Operator const & rhs);

	private:
		Command					_cmd;
		eOperandType			_operand;
		int						_line;
		std::string				_value;
		void					_push(std::list<const IOperand *> lst);
		void					_pop(std::list<const IOperand *> lst);
		void					_dump(std::list<const IOperand *> lst);
		void					_assert(std::list<const IOperand *> lst);
		void					_add(std::list<const IOperand *> lst);
		void					_sub(std::list<const IOperand *> lst);
		void					_mul(std::list<const IOperand *> lst);
		void					_div(std::list<const IOperand *> lst);
		void					_mod(std::list<const IOperand *> lst);
		void					_print(std::list<const IOperand *> lst);
		void					_exit(std::list<const IOperand *> lst);
};
typedef void (Operator::*fun)(std::list<const IOperand *> lst);
#endif /* OPERATOR_HPP */

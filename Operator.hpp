#ifndef OPERATOR_HPP
# define OPERATOR_HPP

# include <list>
# include <exception>
# include "IOperand.hpp"
# include "Calculator.hpp"

enum	command
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
		Operator(command cmd, int line);
		Operator(command cmd, eOperandType op, int line, std::string value);
		Operator(Operator const & src);
		~Operator( void );
		Operator &				operator=(Operator const & rhs);
		bool					callCommand(std::list<const IOperand *> & lst);
		command					getCommand( void );
		eOperandType			getType( void );
		int						getLineNum( void );
		std::string				getValue( void );

		bool					_push(std::list<const IOperand *> & lst);
		bool					_pop(std::list<const IOperand *> & lst);
		bool					_dump(std::list<const IOperand *> & lst);
		bool					_assert(std::list<const IOperand *> & lst);
		bool					_add(std::list<const IOperand *> & lst);
		bool					_sub(std::list<const IOperand *> & lst);
		bool					_mul(std::list<const IOperand *> & lst);
		bool					_div(std::list<const IOperand *> & lst);
		bool					_mod(std::list<const IOperand *> & lst);
		bool					_print(std::list<const IOperand *> & lst);
		bool					_exit(std::list<const IOperand *> & lst);

	private:
		command					_cmd;
		eOperandType			_operand;
		int						_line;
		std::string				_value;
};
typedef bool (Operator::*fun)(std::list<const IOperand *> & lst);
#endif /* OPERATOR_HPP */

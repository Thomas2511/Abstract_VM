#ifndef EXECUTION_HPP
# define EXECUTION_HPP

# include "Token.hpp"
# include "Operator.hpp"

class Execution
{
	public:
		~Execution( void );
		std::list<Operator *>		createExecutionList(std::list<Token> tkns);

	private:
		Command						_checkCommand(Token tkn);
		eOperandType				_checkOperand(Token tkn);
};

#endif /* EXECUTION_HPP */

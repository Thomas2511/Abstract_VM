#ifndef EXECUTION_HPP
# define EXECUTION_HPP

# include "Token.hpp"
# include "Operator.hpp"

class Execution
{
	public:
		~Execution( void );
		static std::list<Operator *>		createExecutionList(std::list<Token> & tkns);

	private:
		static command						_checkCommand(Token tkn);
		static eOperandType					_checkOperand(Token tkn);
};

#endif /* EXECUTION_HPP */

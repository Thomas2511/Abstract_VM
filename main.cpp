#include		<iostream>
#include		<fstream>
#include		"Tokenizer.hpp"
#include		"Analyzer.hpp"
#include		"Parser.hpp"
#include		"Execution.hpp"
#include		"Operator.hpp"

int							main(int ac, char ** av)
{
	std::string				line;
	std::stringstream		ss;
	std::ifstream			file(av[1]);
	std::list<Token> *		tkns;

	if (ac == 1)
	{
		while (std::getline(std::cin, line) && line.compare(";;"))
			ss << line << std::endl;
	}
	else if (ac == 2)
	{
		if (file.is_open())
		{
			while(std::getline(file, line))
				ss << line << std::endl;
			file.close();
		}
		else
		{
			std::cerr << "Unable to open file" << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "Usage: ./avm [file]." << std::endl;
		return 1;
	}
	try
	{
		tkns = Tokenizer::tokenize(ss.str());
		Analyzer::analyzer(tkns);
		Parser::parse(tkns);

		std::list<Operator *>				exec;
		std::list<Operator *>::iterator		it;
		std::list<const IOperand *>			lst;
		std::list<const IOperand *>::iterator	it2;
		bool								exit = false;

		exec = Execution::createExecutionList(*tkns);
		for (it = exec.begin(); it != exec.end(); ++it)
			exit = ((*it)->callCommand(lst));
		if (!exit)
			std::cerr << "Exit command missing at end of program." << std::endl;
	}
	catch (const Analyzer::UnknownInstructionException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Calculator::FloatingPointException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const OperandFactory::OperandOverflowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const OperandFactory::OperandUnderflowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Operator::StackTooShortException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Operator::EmptyStackException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Operator::AssertErrorException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Parser::InstructionException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::PrecisionException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::LeftParenthesisException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::RightParenthesisException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::NaturalValueException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::FloatingValueException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	catch (const Parser::SeparatorException & e)
	{
		//In order to have the expected value by the parser, the exception is caught in the parse() function.
	}
	return 0;
}

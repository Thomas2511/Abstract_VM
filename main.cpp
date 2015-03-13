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
		while (std::getline(std::cin, line))
		{
			if (!line.compare(";;"))
			{
				ss << "exit" << std::endl;
				break ;
			}
			ss << line << std::endl;
		}
		std::cout << ss.str();
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
	/*	Analyzer::analyzer(tkns);
		Parser::parse(tkns);*/

		for(std::list<Token>::iterator tk = tkns->begin(); tk != tkns->end(); ++tk)
		{
			std::cout << (*tk).getValue() << std::endl;
		}

		std::list<Operator *>				exec;
		std::list<Operator *>::iterator		it;
		std::list<const IOperand *>			lst;
		std::list<const IOperand *>::iterator	it2;
		bool								exit = false;

		exec = Execution::createExecutionList(*tkns);
		for (it = exec.begin(); it != exec.end(); ++it)
		{
			std::cout << "-----------------------" << std::endl;
			std::cout << (*it)->getValue() << std::endl;
			exit = ((*it)->callCommand(lst));
			if (exit)
			{
				for (it2 = lst.begin(); it2 != lst.end(); ++it2)
				{
					std::cout << (*it2)->toString() << std::endl;
				}
				break ;
			}
		}
		if (!exit)
			std::cerr << "Exit command missing at end of program." << std::endl;
	}
	catch (const Analyzer::UnknownInstructionException & e)
	{
	}
	catch (const Parser::InstructionException & e)
	{
	}
	catch (const Parser::PrecisionException & e)
	{
	}
	catch (const Parser::LeftParenthesisException & e)
	{
	}
	catch (const Parser::RightParenthesisException & e)
	{
	}
	catch (const Parser::NaturalValueException & e)
	{
	}
	catch (const Parser::FloatingValueException & e)
	{
	}
	catch (const Parser::SeparatorException & e)
	{
	}
	catch (const Operator::EmptyStackException & e)
	{
	}
	catch (const Operator::AssertErrorException & e)
	{
	}
	return 0;
}

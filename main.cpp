#include		<iostream>
#include		<fstream>
#include		"Tokenizer.hpp"
#include		"Analyzer.hpp"
#include		"Parser.hpp"
#include		"Execution.hpp"
#include		"Operator.hpp"

int							main(int ac, char ** av)
{
	std::string				s("; ------------\n; exemple.avm -\n; ------------\n\npush int32(42)\npush int32(33)\n\nadd\n\npush float(44.55)\n\nmul\n\npush double(42.42)\npush int32(42)\n\ndump\n\npop\n\nassert double(42.42)\n\nexit");
	std::string				line;
	std::stringstream		ss;
	std::ifstream			file(av[1]);
	std::list<Token> *		tkns;

	if (ac == 1)
		tkns = Tokenizer::tokenize(s);
	else if (ac == 2)
	{
		if (file.is_open())
		{
			while(std::getline(file, line))
				ss << line << std::endl;
			file.close();
			tkns = Tokenizer::tokenize(ss.str());
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
		Analyzer::analyzer(tkns);
		Parser::parse(tkns);

		std::list<Operator *>				exec;
		std::list<Operator *>::iterator		it;
		std::list<const IOperand *>			lst;
		bool								exit = false;

		exec = Execution::createExecutionList(*tkns);
		for (it = exec.begin(); it != exec.end(); ++it)
		{
			exit = ((*it)->callCommand(lst));
			if (exit)
				break ;
		}
		if (!exit)
			std::cerr << "Exit command missing at end of program." << std::endl;
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
	for(std::list<Token>::const_iterator it = tkns->begin(); it != tkns->end(); ++it)
	{
		if ((*it).getValue().compare("\n") == 0)
			std::cout << "{\\n | Separator | " << (*it).getLineNum() << "}\n";
		else
			std::cout << "{" << *it << "}";
	}
	std::cout << std::endl;
	return 0;
}

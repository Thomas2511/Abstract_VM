#include		<iostream>
#include		<fstream>
#include		"Tokenizer.hpp"
#include		"Analyzer.hpp"
#include		"Parser.hpp"

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
	}
	catch (const Parser::ParserExcept & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
		// TODO : quitter le programme
	}
	catch (const Analyzer::AnalyzerExcept & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
		// TODO : quitter le programme
	}
	catch ( ... )
	{
		std::cerr << "???" << std::endl;
		return 1;
		// TODO : panic
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

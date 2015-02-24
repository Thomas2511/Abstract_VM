#include		<iostream>
#include		"Tokenizer.hpp"
#include		"Analyzer.hpp"

int				main()
{
	std::string			s("; ------------\n; exemple.avm -\n; ------------\n\npush int32(42)\npush int32(33)\n\nadd\n\npush float(44.55)\n\nmul\n\npush double(42.42)\npush int32(42)\n\ndump\n\npop\n\nassert double(42.42)\n\nexit");
	std::list<Token> *	tkns;

	tkns = Tokenizer::tokenize(s);
	Analyzer::analyzer(tkns);
	for(std::list<Token>::const_iterator it = tkns->begin(); it != tkns->end(); ++it)
	{
		if ((*it).getValue().compare("\n") == 0)
			std::cout << "{\\n | Separator}\n";
		else
			std::cout << "{" << *it << "}";
	}
	std::cout << std::endl;
	return 0;
}

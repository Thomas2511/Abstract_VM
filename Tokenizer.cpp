#include <sstream>
#include <cstring>
#include "Tokenizer.hpp"
#include <iostream>

std::list<Token> *				Tokenizer::tokenize(std::string const & content)
{
	std::list<Token> *			ret = new std::list<Token>;
	std::size_t					found = 0;
	std::string					value;
	std::stringstream			ss;
	Token						tkn;

	for (unsigned int i = 0; i < content.size(); i++)
	{
		found = content.find_first_of(" \n();", found);
		value = content.substr(i, found - i);
		if (value.compare("") != 0)
		{
			tkn.setValue(value);
			ret->push_back(tkn);
		}
		if (content[found] == '\n' || content[found] == '(' || content[found] == ')')
		{
			ss << content[found];
			tkn.setValue(ss.str());
			ret->push_back(tkn);
			ss.str(std::string());
		}
		if (found == std::string::npos)
			break;
		if (content[found] == ';')
			found = content.find_first_of("\n", found);
		i = found++;
	}

	return ret;
}

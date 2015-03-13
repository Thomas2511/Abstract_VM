#include <sstream>
#include <iostream>
#include <cstring>
#include "Tokenizer.hpp"

std::list<Token> *				Tokenizer::tokenize(std::string const & content)
{
	std::list<Token> *			ret = new std::list<Token>;
	std::size_t					found = 0;
	std::string					value;
	std::stringstream			ss;
	Token						tkn;
	int							lineNum = 0;

	for (unsigned int i = 0; i < content.size(); i++)
	{
		found = content.find_first_of(" \n();", found);
		if (content[found] == '\n')
			lineNum++;
		value = content.substr(i, found - i);
		if (value.compare("") != 0)
		{
			tkn.setValue(value);
			tkn.setLineNum(lineNum);
			ret->push_back(tkn);
		}
		if (content[found] == '\n' || content[found] == '(' || content[found] == ')')
		{
			ss << content[found];
			tkn.setValue(ss.str());
			tkn.setLineNum(lineNum);
			ret->push_back(tkn);
			ss.str(std::string());
		}
		if (content[found] == ';')
		{
			found = content.find_first_of("\n", found);
			if (content[found] == '\n')
				lineNum++;
		}
		if (found == std::string::npos)
			break;
		i = found++;
	}

		for(std::list<Token>::iterator tk = ret->begin(); tk != ret->end(); ++tk)
		{
			std::cout << (*tk).getValue();
		}

	return ret;
}

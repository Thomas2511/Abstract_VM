CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98 -pedantic-errors

SOURCES = Token.cpp \
		  Tokenizer.cpp \
		  Analyzer.cpp \
		  AnalyzerExcept.cpp \
		  main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

NAME = avm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all

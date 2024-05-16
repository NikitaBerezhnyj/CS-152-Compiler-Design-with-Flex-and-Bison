make:
	bison -d -o parser.cpp parser.y
	lex -o lexer.cpp lexer.lex
	g++ parser.cpp lexer.cpp
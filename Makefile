SCANNER := lex
SCANNER_PARAMS := lexica.l
PARSER := yacc
PARSER_PARAMS := -d sintatica_semantica.y

all: compile translate

compile:
		$(SCANNER) $(SCANNER_PARAMS)
		$(PARSER) $(PARSER_PARAMS)
		g++ -o glf y.tab.c -ll

run: 	glf
		clear
		compile
		translate

debug:	PARSER_PARAMS += -Wcounterexamples
debug: 	all

translate: glf
		./glf < teste.jsc

clear:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm glf
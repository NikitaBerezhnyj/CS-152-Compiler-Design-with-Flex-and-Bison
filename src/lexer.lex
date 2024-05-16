%option noyywrap

%{
#include <stdio.h>
#include "parser.hpp"

char *create_string(char *value, int length) {
  char *return_value = new char[length + 1];
  strcpy(return_value, value);
  return return_value;
}
%}

%%
"var"                           { return VAR; }
"print"                         { return PRINT; }
"input"                         { return INPUT; }
"while"                         { return WHILE; }
"for"                           { return FOR; }
"if"                            { return IF; }
"elif"                          { return ELIF; }
"else"                          { return ELSE; }
"func"                          { return FUNC; }
"return"                        { return RETURN; }
"="                             { return EQUAL; }
"+"                             { yylval.op_value = create_string(yytext, yyleng); return PLUS; }
"-"                             { yylval.op_value = create_string(yytext, yyleng); return MINUS; }
"*"                             { yylval.op_value = create_string(yytext, yyleng); return MULT; }
"/"                             { yylval.op_value = create_string(yytext, yyleng); return DIVISION; }
"%"                             { yylval.op_value = create_string(yytext, yyleng); return DIVISIONREM; }
"("                             { return LPAR; }
")"                             { return RPAR; }
"{"                             { return LCURLY; }
"}"                             { return RCURLY; }
"["                             { return LBRACK; }
"]"                             { return RBRACK; }
"<"                             { yylval.op_value = create_string(yytext, yyleng); return LESS; }
"<="                            { yylval.op_value = create_string(yytext, yyleng); return LESSEQUAL; }
"=="                            { yylval.op_value = create_string(yytext, yyleng); return EQUALEQUAL; }
"!="                            { yylval.op_value = create_string(yytext, yyleng); return NOTEQUAL; }
">="                            { yylval.op_value = create_string(yytext, yyleng); return MOREEQUAL; }
">"                             { yylval.op_value = create_string(yytext, yyleng); return MORE; }
"||"                            { yylval.op_value = create_string(yytext, yyleng); return OR; }
"&&"                            { yylval.op_value = create_string(yytext, yyleng); return AND; }
"!"                             { yylval.op_value = create_string(yytext, yyleng); return NOT; }
"++"                            { return INCREMENT; }
"--"                            { return DECREMENT; }
","                             { return COMA; }
";"                             { yylval.op_value = create_string(yytext, yyleng); return SEMICOLON; }
[0-9]+                          { yylval.op_value = create_string(yytext, yyleng); return NUMBER; }
[a-zA-Z]+                       { yylval.op_value = create_string(yytext, yyleng); return IDENT; }
\/\/[^\n]*\n                    {}
\/\*[^*]*\*+([^/*][^*]*\*+)*\/  {}
[ \t\n]                         {}
.                               { printf("Unknown token"); }
%%
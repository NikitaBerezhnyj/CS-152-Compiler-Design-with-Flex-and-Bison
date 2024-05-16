%{

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int yylex();
void yyerror(const char *s);

struct CodeNode {
    std::string code;
    std::string name;
};

struct Loop {
    int id;
    std::string begin_label;
    std::string end_label;
    std::string body_label;
};

std::vector<Loop> loops;

enum Type { Integer, Array };

struct Symbol {
    std::string name;
    Type type;
};

struct Function {
    std::string name;
    std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;

Function *get_function() {
    int last = symbol_table.size() - 1;
    if (last < 0) {
        printf("***Error. Attempt to call get_function with an empty symbol table\n");
        printf("Create a 'Function' object using 'add_function_to_symbol_table' before\n");
        printf("calling 'find' or 'add_variable_to_symbol_table'");
        exit(1);
    }
    return &symbol_table[last];
}

bool find(std::string &value) {
    Function *f = get_function();
    for (int i = 0; i < f->declarations.size(); i++) {
        Symbol *s = &f->declarations[i];
        if (s->name == value) {
            return true;
        }
    }
    return false;
}

void add_function_to_symbol_table(std::string &value) {
    Function f;
    f.name = value;
    symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string &value, Type t) {
    Symbol s;
    s.name = value;
    s.type = t;
    Function *f = get_function();
    f->declarations.push_back(s);
}

void print_symbol_table(void) {
    printf("symbol table:\n");
    printf("--------------------\n");
    for (int i = 0; i < symbol_table.size(); i++) {
        printf("function: %s\n", symbol_table[i].name.c_str());
        for (int j = 0; j < symbol_table[i].declarations.size(); j++) {
            printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
        }
    }
    printf("--------------------\n");
}

%}

%union {
    char *op_value;
    struct CodeNode *code_node;
}

%define parse.error verbose

%token FUNC
%token VAR
%token PRINT
%token INPUT
%token IF
%token ELIF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token LPAR
%token RPAR
%token LCURLY
%token RCURLY
%token LBRACK
%token RBRACK
%token EQUAL
%token INCREMENT
%token DECREMENT
%token <op_value> LESS
%token <op_value> LESSEQUAL
%token <op_value> EQUALEQUAL
%token <op_value> NOTEQUAL
%token <op_value> MOREEQUAL
%token <op_value> MORE
%token <op_value> IDENT
%token <op_value> NUMBER
%token <op_value> OR
%token <op_value> AND
%token <op_value> NOT
%token <op_value> PLUS
%token <op_value> MINUS
%token <op_value> MULT
%token <op_value> DIVISION
%token <op_value> DIVISIONREM
%token COMA
%token SEMICOLON

%start program

%type <op_value> variable
%type <op_value> operation_sign
%type <op_value> equal_sign
%type <op_value> condition_sign
%type <code_node> function
%type <code_node> functions
%type <op_value> function_header
%type <code_node> argument
%type <code_node> arguments
%type <code_node> param
%type <code_node> params
%type <code_node> statement
%type <code_node> statements
%type <code_node> elif_statement
%type <code_node> elif_statements
%type <code_node> condition
%type <code_node> conditions
%type <code_node> for_loop_action

%%

program: functions {
    struct CodeNode *functions = $1;
    printf("%s\n", functions->code.c_str());
}

functions: function functions {
    struct CodeNode *function = $1;
    struct CodeNode *functions = $2;
    struct CodeNode *node = new CodeNode;
    node->code = function->code + functions->code;
    $$ = node;
}
| %empty {
    struct CodeNode *node = new CodeNode;
    $$ = node;
}

function_header: FUNC IDENT {
    std::string function_name = $2;
    add_function_to_symbol_table(function_name);
    $$ = $2;
}

function: function_header LPAR params RPAR LCURLY statements RCURLY {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *params = $3;
    struct CodeNode *statements = $6;
    node->code = std::string("func ") + std::string($1) + std::string("\n");
    node->code += params->code;
    node->code += statements->code;
    node->code += std::string("endfunc\n\n");
    $$ = node;
}

params: param COMA params {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *param = $1;
    struct CodeNode *params = $3;
    node->code = param->code + params->code;
    $$ = node;
}
| param {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *param = $1;
    node->code = param->code;
    $$ = node;
}
| %empty {
    struct CodeNode *node = new CodeNode;
    $$ = node;
}

param: IDENT {
    struct CodeNode *node = new CodeNode;
    std::string param = $1;
    node->name = param;
    node->code = std::string(". ") + param + std::string("\n");
    int param_index = symbol_table.back().declarations.size();
    node->code += std::string("= ") + param + std::string(", $") + std::to_string(param_index) + std::string("\n");
    add_variable_to_symbol_table(param, Integer);
    $$ = node;
}

arguments: argument COMA arguments {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *argument = $1;
    struct CodeNode *arguments = $3;
    node->code = argument->code + arguments->code;
    $$ = node;
}
| argument {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *argument = $1;
    node->code = argument->code;
    $$ = node;
}
| %empty {
    struct CodeNode *node = new CodeNode;
    $$ = node;
}

argument: variable {
    struct CodeNode *node = new CodeNode;
    std::string argument = $1;
    node->code = std::string("param ") + argument + std::string("\n");
    $$ = node;
}

elif_statements: elif_statements elif_statement {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *elif_statements = $1;
    struct CodeNode *elif_statement = $2;
    node->code = elif_statements->code + elif_statement->code;
    $$ = node;
}
| %empty {
    struct CodeNode *node = new CodeNode;
    $$ = node;
}

elif_statement: ELIF conditions LCURLY statements RCURLY {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *conditions = $2;
    struct CodeNode *statements = $4;
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= endelse\n");
    $$ = node;
}

conditions: condition {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *condition = $1;
    node->code = condition->code;
    node->code += std::string("?:= condition_true, temp\n");
    node->code += std::string(":= condition_false\n");
    $$ = node;
}
| condition condition_sign conditions {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *condition1 = $1;
    std::string condition_sign = $2;
    struct CodeNode *conditions = $3;
    node->code = condition1->code + std::string(condition_sign) + std::string(" temp, temp, temp\n");
    node->code += conditions->code;
    node->code += std::string("?:= condition_true, temp\n");
    node->code += std::string(":= condition_false\n");
    $$ = node;
}

condition: variable equal_sign variable {
    struct CodeNode *node = new CodeNode;
    std::string var1 = $1;
    std::string equal_sign = $2;
    std::string var2 = $3;
    node->code += std::string(". temp\n");
    node->code += std::string(equal_sign) + std::string(" temp, ") + var1 + std::string(", ") + var2 + std::string("\n");
    $$ = node;
}
| NOT variable {
    struct CodeNode *node = new CodeNode;
    std::string var = $2;
    node->code = std::string(". temp\n");
    node->code += std::string("! temp, ") + var + std::string("\n");
    $$ = node;
}

for_loop_action: IDENT INCREMENT {
    struct CodeNode *node = new CodeNode;
    std::string var = $1;
    node->code += std::string("+ ") + std::string(var) + std::string(", ") + std::string(var) + std::string(", 1\n");
    $$ = node;
}
| IDENT DECREMENT {
    struct CodeNode *node = new CodeNode;
    std::string var = $1;
    node->code += std::string("- ") + std::string(var) + std::string(", ") + std::string(var) + std::string(", 1\n");
    $$ = node;
}
| IDENT EQUAL IDENT operation_sign variable {
    struct CodeNode *node = new CodeNode;
    std::string var = $1;
    std::string operation_sign = $4;
    std::string operation_value = $5;
    node->code += std::string(operation_sign) + std::string(" ") + std::string(var) + std::string(", ") + std::string(var) + std::string(",") + std::string(operation_value) + std::string("\n");
    $$ = node;
}

statements: statement statements {
    struct CodeNode *statement = $1;
    struct CodeNode *statements = $2;
    struct CodeNode *node = new CodeNode;
    node->code = statement->code + statements->code;
    $$ = node;
}
| %empty {
    struct CodeNode *node = new CodeNode;
    $$ = node;
}

statement: PRINT LPAR IDENT RPAR SEMICOLON {
    std::string variable_name = $3;
    if (!find(variable_name)) {
        yyerror("Undeclared variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".> ") + std::string($3) + std::string("\n");
    $$ = node;
}
| PRINT LPAR IDENT LBRACK NUMBER RBRACK RPAR SEMICOLON {
    std::string variable_name = $3;
    std::string item_index = $5;
    if (!find(variable_name)) {
        yyerror("Undeclared variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[]> ") + variable_name + std::string(", ") + item_index + std::string("\n");
    $$ = node;
}
| INPUT LPAR RPAR SEMICOLON {
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". temp\n");
    node->code += std::string(".< temp\n");
    $$ = node;
}
| IDENT EQUAL variable operation_sign variable SEMICOLON {
    struct CodeNode *node = new CodeNode;
    std::string operation_sign = $4;
    node->code = std::string(operation_sign) + std::string(" ") + std::string($1) + std::string(", ") + std::string($3) + std::string(", ") + std::string($5) + std::string("\n");
    $$ = node;
}
| IDENT EQUAL variable SEMICOLON {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("= ") + std::string($1) + std::string(", ") + std::string($3) + std::string("\n");
    $$ = node;
}
| IDENT INCREMENT SEMICOLON {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("+ ") + std::string($1) + std::string(", ") + std::string($1) + std::string(", 1\n");
    $$ = node;
}
| IDENT DECREMENT SEMICOLON {
    struct CodeNode *node = new CodeNode;
    node->code = std::string("- ") + std::string($1) + std::string(", ") + std::string($1) + std::string(", 1\n");
    $$ = node;
}
| IDENT LBRACK NUMBER RBRACK EQUAL INPUT LPAR RPAR SEMICOLON {
    std::string variable_name = $1;
    std::string item_index = $3;
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[]< ") + variable_name + std::string(", ") + item_index + "\n";
    $$ = node;
}
| VAR IDENT SEMICOLON {
    std::string variable_name = $2;
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + std::string("\n");
    $$ = node;
}
| VAR IDENT EQUAL variable SEMICOLON {
    std::string variable_name = $2;
    std::string variable_val = $4;
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + std::string("\n");
    node->code += std::string("= ") + variable_name + std::string(", ") + variable_val + std::string("\n");
    $$ = node;
}
| VAR IDENT EQUAL variable operation_sign variable SEMICOLON {
    std::string variable_name = $2;
    std::string operation_sign = $5;
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
node->code = std::string(". ") + variable_name + std::string("\n");
node->code += std::string(operation_sign) + std::string(" ") + variable_name + std::string(", ") + std::string($4) + std::string(", ") + std::string($6) + std::string("\n");
$$ = node;
}
| VAR IDENT EQUAL INPUT LPAR RPAR SEMICOLON {
    std::string variable_name = $2;
    if (find(variable_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(variable_name, Integer);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". ") + variable_name + "\n";
    node->code += std::string(".< ") + variable_name + "\n";
    $$ = node;
}
| VAR IDENT LBRACK RBRACK EQUAL NUMBER SEMICOLON {
    std::string array_name = $2;
    int array_size = atoi($6);
    if (find(array_name)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(array_name, Array);
    struct CodeNode *node = new CodeNode;
    node->code = std::string(".[] ") + array_name + std::string(", ") + std::to_string(array_size) + std::string("\n");
    $$ = node;
}
| IDENT EQUAL IDENT LBRACK variable RBRACK SEMICOLON {
    std::string dst = $1;
    std::string src = $3;
    int index = atoi($5);
    if (!find(dst) || !find(src)) {
        yyerror("Unknown variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string("=[] ") + dst + std::string(", ") + src + std::string(", ") + std::to_string(index) + std::string("\n");
    $$ = node;
}
| IDENT LBRACK NUMBER RBRACK EQUAL variable SEMICOLON {
    std::string dst = $1;
    int index = atoi($3);
    std::string src = $6;
    if (!find(dst)) {
        yyerror("Unknown variable.");
        return 1;
    }
    struct CodeNode *node = new CodeNode;
    node->code = std::string("[]= ") + dst + std::string(", ") + std::to_string(index) + std::string(", ") + src + std::string("\n");
    $$ = node;
}
| WHILE conditions LCURLY statements RCURLY {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *conditions = $2;
    struct CodeNode *statements = $4;
    int loop_id = loops.size();
    std::string begin_label = "beginloop" + std::to_string(loop_id);
    std::string end_label = "endloop" + std::to_string(loop_id);
    Loop loop = {loop_id, begin_label, end_label, ""};
    loops.push_back(loop);
    node->code += std::string(": ") + begin_label + "\n";
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= ") + begin_label + "\n";
    node->code += std::string(": condition_false\n");
    node->code += std::string(": ") + end_label + "\n";
    $$ = node;
}
| FOR VAR IDENT EQUAL variable SEMICOLON IDENT equal_sign variable SEMICOLON for_loop_action LCURLY statements RCURLY {
    struct CodeNode *node = new CodeNode;
    struct CodeNode *statements = $13;
    std::string var = $3;
    std::string start_val = $5;
    std::string equal_sign = $8;
    std::string current_val = $9;
    struct CodeNode *for_loop_action = $11;
    if (find(var)) {
        yyerror("Duplicate variable.");
        return 1;
    }
    add_variable_to_symbol_table(var, Integer);
    int loop_id = loops.size();
    std::string begin_label = "beginloop" + std::to_string(loop_id);
    std::string end_label = "endloop" + std::to_string(loop_id);
    std::string body_label = "loopbody" + std::to_string(loop_id);
    Loop loop = {loop_id, begin_label, end_label, body_label};
    loops.push_back(loop);
    node->code += std::string(". ") + var + std::string("\n");
    node->code += std::string("= ") + var + std::string(", ") + start_val + std::string("\n");
    node->code += std::string(": ") + begin_label + "\n";
    node->code += std::string(". temp\n");
    node->code += std::string(equal_sign) + std::string(" temp, ") + std::string(var) + std::string(", ") + std::string(current_val) + std::string("\n");
    node->code += std::string("?:= ") + body_label + std::string(", temp\n");
    node->code += std::string(":= ") + end_label + "\n";
    node->code += std::string(": ") + body_label + "\n";
    
    // Додаємо змінну циклу до таблиці символів перед виконанням тіла циклу
    add_variable_to_symbol_table(var, Integer);
    
    node->code += statements->code;
    
    // Видаляємо змінну циклу з таблиці символів після виконання тіла циклу
    Function *f = get_function();
    for (int i = 0; i < f->declarations.size(); i++) {
        if (f->declarations[i].name == var) {
            f->declarations.erase(f->declarations.begin() + i);
            break;
        }
    }
    
    node->code += for_loop_action->code;
    node->code += std::string(":= ") + begin_label + "\n";
    node->code += std::string(": ") + end_label + "\n";
    $$ = node;
}
| IF conditions LCURLY statements RCURLY {
    struct CodeNode *conditions = $2;
    struct CodeNode *statements = $4;
    struct CodeNode *node = new CodeNode;
    node->code += std::string(": condition_start\n");
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statements->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_false\n");
    node->code += std::string(": condition_end\n");
    $$ = node;
}
| IF conditions LCURLY statements RCURLY elif_statements ELSE LCURLY statements RCURLY {
    struct CodeNode *conditions = $2;
    struct CodeNode *statementsIF = $4;
    struct CodeNode *elif_statements = $6;
    struct CodeNode *statementsELSE = $9;
    struct CodeNode *node = new CodeNode;
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statementsIF->code;
    node->code += std::string(":= endelse\n");
    node->code += elif_statements->code;
    node->code += std::string(": condition_false\n");
    node->code += statementsELSE->code;
    node->code += std::string(":= endelse\n");
    node->code += std::string(": endelse\n");
    $$ = node;
}
| IF conditions LCURLY statements RCURLY ELSE LCURLY statements RCURLY {
    struct CodeNode *conditions = $2;
    struct CodeNode *statementsIF = $4;
    struct CodeNode *statementsELSE = $8;
    struct CodeNode *node = new CodeNode;
    node->code += std::string(": condition_start\n");
    node->code += conditions->code;
    node->code += std::string(": condition_true\n");
    node->code += statementsIF->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_false\n");
    node->code += statementsELSE->code;
    node->code += std::string(":= condition_end\n");
    node->code += std::string(": condition_end\n");
    $$ = node;
}
| IDENT EQUAL IDENT LPAR arguments RPAR SEMICOLON {
    std::string var = $1;
    std::string func = $3;
    struct CodeNode *arguments = $5;
    struct CodeNode *node = new CodeNode;
    node->code = arguments->code;
    node->code += std::string("call ") + func + std::string(", ") + var + std::string("\n");
    $$ = node;
}
| IDENT LPAR arguments RPAR SEMICOLON {
    std::string func = $1;
    struct CodeNode *arguments = $3;
    struct CodeNode *node = new CodeNode;
    node->code = std::string(". temp\n");
    node->code += arguments->code;
    node->code += std::string("call ") + func + std::string(", temp\n");
    $$ = node;
}
| RETURN variable SEMICOLON {
    std::string var = $2;
    struct CodeNode *node = new CodeNode;
    node->code = std::string("ret ") + var + std::string("\n");
    $$ = node;
}

variable:       IDENT           {$$ = $1;}
              | NUMBER          {$$ = $1;}

operation_sign: PLUS            {$$ = $1;}
              | MINUS           {$$ = $1;}
              | MULT            {$$ = $1;}
              | DIVISION        {$$ = $1;}
              | DIVISIONREM     {$$ = $1;}

equal_sign:     LESS            {$$ = $1;}
              | LESSEQUAL       {$$ = $1;} 
              | EQUALEQUAL      {$$ = $1;}
              | NOTEQUAL        {$$ = $1;}
              | MOREEQUAL       {$$ = $1;} 
              | MORE            {$$ = $1;}

condition_sign: OR              {$$ = $1;}
              | AND             {$$ = $1;}

%%

int main(void) {
    yyparse();
    print_symbol_table();
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
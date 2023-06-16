#include "../headers/Lexer.hpp"
#include "../Config.hpp"
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>
#include <utility>


#ifdef DEBUG_LEXER
#include <iostream>
#endif

Lexer::Lexer(std::string& expression)
{
    var_token = nullptr;
    source = expression; 
    words = {{"+",new Token("+", '+')},
             {"-",new Token("-", '-')},
             {"*",new Token("*", '*')},
             {"/",new Token("/", '/')},
             {"(",new Token("(", '(')},
             {")",new Token(")", ')')},
             {"sin",new UnaryFunc("sin", ELEM_UN_FN, std::sin)},
             {"cos",new UnaryFunc("cos", ELEM_UN_FN, std::cos)},
             {"tan",new UnaryFunc("tan", ELEM_UN_FN, std::tan)},
             {"atan",new UnaryFunc("atan", ELEM_UN_FN, std::atan)},
             {"sqrt",new UnaryFunc("sqrt", ELEM_UN_FN, std::sqrt)},
             {"ln",new UnaryFunc("ln", ELEM_UN_FN, std::log)},
             {"log2",new UnaryFunc("log2", ELEM_UN_FN, std::log2)},
             {"exp",new UnaryFunc("exp", ELEM_UN_FN, std::exp)},
             {"pow",new BinaryFunc("pow", ELEM_BIN_FN, std::pow)},
             {"x",new Number("x", X_VALUE, 0.0)}
            };
}

Lexer::~Lexer()
{
    for (auto elem : words)
        delete elem.second;    
}

void Lexer::analyse()
{
    Token* cur_tok = nullptr;
    auto iter = source.begin();
    do 
    {
        cur_tok = getToken(iter);
        token_list.push_back(cur_tok);
    }while (cur_tok->getTag() != END_OF_FILE);
    var_token = (Number*)words.find("x")->second;
}

Token* Lexer::getToken(std::string::iterator& pos)
{
    ignore:
    if (pos == source.end())
        return new Token("EOF",END_OF_FILE);
#ifdef DEBUG_LEXER
    std::cout << *pos << '\n';
#endif
    
    switch (*pos)
    {
        case '\t':    
        case ' ':
            pos++;
            goto ignore;
        case '*':
            pos++;
            return words.find("*")->second;
        case '-':
            pos++;
            return words.find("-")->second;
        case '+':
            pos++;
            return words.find("+")->second;
        case '/':
            pos++;
            return words.find("/")->second;
        case ')':
            pos++;
            return words.find(")")->second;
        case '(':
            pos++;
            return words.find("(")->second;
    }

    if (std::isdigit(*pos))
    {
        bool frac = false;
        std::string lex;
        lex.reserve(6);
        lex += *pos;
        pos++;
        while (std::isalnum(*pos) || (*pos == '.' && !frac))
        {
            lex += *pos;
            frac = frac || (*pos == '.');
            pos++;
        }

        auto tok = new Number(lex, CONST, std::stod(lex));
        words.insert(std::make_pair(lex, tok));
        return tok;
    }

    if (std::isalpha(*pos))
    {
        std::string lex;
        lex.reserve(4);
        lex += *pos;
        pos++;
        while (isalpha(*pos))
        {
            lex += *pos;
            pos++;   
        }

        auto elem = words.find(lex);
        assert(elem != words.end());
        return elem->second;
    }
    
    std::abort();
}

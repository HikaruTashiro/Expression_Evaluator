#include "../headers/Parser.hpp"
#include "../Config.hpp"
#include <cassert>
#include <memory>

#ifdef DEBUG_PARSER
#include <iostream>
#endif

Parser::Parser(Lexer& lex) : lexer(lex)
{
    lexer.analyse();     
#ifdef DEBUG_PARSER
    for (auto elem : lexer.token_list)
        std::cout << '\t' << *elem;
#endif
    iter = lexer.token_list.begin();
}

std::shared_ptr<Expr> Parser::gen()
{
    return expr();
}

void Parser::match(Tag tag)
{
#ifdef DEBUG_PARSER
    std::cout << "match -> " << **iter << '\n';
#endif
    assert(tag == (*iter)->getTag());
    iter++;
}

std::shared_ptr<Expr> Parser::expr()
{
#ifdef DEBUG_PARSER
    std::cout << "expr -> " << **iter << '\n';
#endif
    std::shared_ptr<Expr> expr1 = term();
    if((*iter)->getTag() == '+' || (*iter)->getTag() == '-')
    {
        Token* tok = *iter; move();
        expr1 = std::shared_ptr<Binary>(new Binary(expr1, tok, expr()));
    }
    return expr1;
}

std::shared_ptr<Expr> Parser::term()
{
#ifdef DEBUG_PARSER
    std::cout << "term -> " << **iter << '\n';
#endif
    auto expr1 = unary();
    if((*iter)->getTag() == '*' || (*iter)->getTag() == '/')
    {
        Token* tok = *iter; move();
        expr1 = std::shared_ptr<Binary>(new Binary(expr1, tok, unary()));
    }
    return expr1;
}

std::shared_ptr<Expr> Parser::unary()
{
#ifdef DEBUG_PARSER
    std::cout << "unary -> " << **iter << '\n';
#endif
    if((*iter)->getTag() == '-')
    {
        move();
        return std::shared_ptr<Unary>(new Unary(*iter, unary()));
    }
    return pow();
}

std::shared_ptr<Expr> Parser::pow()
{
#ifdef DEBUG_PARSER
    std::cout << "pow -> " << **iter << '\n';
#endif
    auto expr = factor(); 
    if((*iter)->getTag() == '^')
    {
        Token* tok = *iter; move();
        expr = std::shared_ptr<Binary>(new Binary(expr, tok, pow()));
    }
    return expr;
}

std::shared_ptr<Expr> Parser::factor()
{
#ifdef DEBUG_PARSER
    std::cout << "factor -> " << **iter << '\n';
#endif
    std::shared_ptr<Expr> expression{};
    switch ((*iter)->getTag())
    {
        case '(':
            move(); expression = expr(); match(')');
            return expression;
        case CONST:
            expression = std::shared_ptr<Const>(new Const((Number*)*iter));
            move();
            return expression;
        case X_VALUE:
            expression = std::shared_ptr<Var>(new Var((Number*)*iter));
            move();
            return expression;
        case ELEM_UN_FN:
            {
                Token* tok = *iter; move(); match('(');
                expression = std::shared_ptr<Func>(new Func(tok, expr(), nullptr));
                match(')');
            }
            return expression;
        case ELEM_BIN_FN:
            {
                Token* tok = *iter; move(); match('(');
                std::shared_ptr<Expr> expr1 = expr(); match(',');
                expression = std::shared_ptr<Func>(new Func(tok, expr1, expr()));
                match(')');
            }
            return expression;
        default:
            assert(false);
    }
}

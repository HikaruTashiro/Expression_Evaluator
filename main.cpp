#include "./headers/Parser.hpp"
#include "headers/Token.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
    //std::string pog("3.0 + 3 + x + sin ( cos (x) ) * tan(x) - exp(sqrt(x))");
    //Lexer nog(pog);
    ////nog.analyse();
    ////for (auto elem : nog.token_list)
    ////    std::cout << *elem; 

    //Parser based(nog);
    //std::cout << based.gen()->eval() << '\n';

    std::string user_expr;
    double x = 0.0;

    std::cout << "\nEscreva uma expressao:\n";
    std::cout << "f(x) = ";
    std::getline(std::cin, user_expr);
    std::endl(std::cout);

    Lexer lex(user_expr);
    Parser parser(lex);
    std::cout << "\nEscreva o valor de x = ";
    std::cin >> x;
    lex.var_token->value = x;

    std::shared_ptr<Expr> Ast = parser.gen();
    std::cout << "\nf(" << x << ") = " << Ast->eval() << '\n';

    return 0;
}

/*
 * x ^ 2 + ln(x) + e ^ x
 * x ^ 2 * [ 0.0 * ln(x) + 2.0 * 1.0 / x ] + 1.0 / x * 1.0 + e^x * [ 1.0 * ln(e) + x * 0.0 / e ]
 * |                                       |               | 
 *
 * */

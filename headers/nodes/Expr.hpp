#include "../Token.hpp"
#include <string>
#pragma once

class Expr
{
    public:
        Token* tok; 
        virtual double eval() = 0;
        virtual std::string get_expr() = 0;
        virtual std::string derivative() = 0;
};

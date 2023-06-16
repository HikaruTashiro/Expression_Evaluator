#include "../Token.hpp"
#pragma once

class Expr
{
    public:
        Token* tok; 
        virtual double eval() = 0;
};

#include "../../headers/nodes/Const.hpp"
#include "../../Config.hpp"
#ifdef DEBUG_NODE
#include <iostream>
#endif

Const::Const(Number* val)
{
    tok = val;
}

double Const::eval()
{
    auto var = ((Number*)tok)->value;
#ifdef DEBUG_NODE
    std::cout << "Const : " << var << '\n';
#endif
    return var;
}

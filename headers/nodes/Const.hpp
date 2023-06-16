#include "Expr.hpp"

class Const : public Expr
{
    public:
        explicit Const(Number* val);
        double eval() override;
};

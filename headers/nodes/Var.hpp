#include "Expr.hpp"

class Var : public Expr
{
    public:
        explicit Var(Number* val);
        double eval() override;
};

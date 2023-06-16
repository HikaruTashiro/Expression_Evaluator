#include <memory>
#include "Expr.hpp"

class Binary : public Expr
{
    public:
        std::shared_ptr<Expr> expression1, expression2;
        explicit Binary(std::shared_ptr<Expr> expr1, Token* op, std::shared_ptr<Expr> expr2);
        double eval() override;
};

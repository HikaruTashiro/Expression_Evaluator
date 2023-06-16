#include "Lexer.hpp"
#include "nodes/Expr.hpp"
#include "nodes/Unary.hpp"
#include "nodes/Binary.hpp"
#include "nodes/Var.hpp"
#include "nodes/Const.hpp"
#include "nodes/Func.hpp"
#include <list>
#include <memory>

class Parser
{
    private:
        Lexer& lexer;
        std::list<Token*>::iterator iter;
        void match(Tag tag);
        std::shared_ptr<Expr> expr();
        std::shared_ptr<Expr> term();
        std::shared_ptr<Expr> unary();
        std::shared_ptr<Expr> factor();
        inline void move() {iter++;}

    public:
        std::shared_ptr<Expr> gen();
        explicit Parser(Lexer& lex);
};

/*
 * // Since this is the initial production term needs to be expr on the program \\
 * <expr> -> <expr> + <term>
 *        |  <expr> - <term>
 *        |  <term>
 *
 * <term> -> <term> * <unary>
 *        |  <term> / <unary>
 *        |  <unary>
 *
 * <unary> -> '-' <unary>
 *          | <pow>
 *
 * <pow> -> <factor> '^' <up>
 *       |  <factor>
 *
 * <factor> ->  <const>
 *          |   <id>
 *          |   '(' <expr> ')'
 *          |   <sin> '(' <expr> ')' 
 *          |   <cos> '(' <expr> ')'
 *          |   <tan> '(' <expr> ')'
 *          |   <sqrt> '(' <expr> ')'
 *          |   <log2> '(' <expr> ')'
 *          |   <ln> '(' <expr> ')'
 *          |   <atan> '(' <expr> ')'
 *          |   <exp> '(' <expr> ')'
 *          |   <pow> '(' <expr> ')'
 * */

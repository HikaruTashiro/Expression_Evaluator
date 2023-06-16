#include <list>
#include <string>
#include <unordered_map>
#include "Token.hpp"

class Lexer
{
    private:
        std::string source;
        std::unordered_map<std::string, Token*> words;
        Token* getToken(std::string::iterator& pos);
    public:
        Number* var_token;
        std::list<Token*> token_list;
        void analyse();
        Lexer(std::string& expression);
        ~Lexer();
};

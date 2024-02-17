#include <string>
#include <vector>

class CCurrentPosition{
    public:
    std::string block;
    CCurrentPosition(std::string);
};

class CValidMoves{
    public:
    std::vector<std::string> moves;
    CValidMoves(std::vector<std::string> moves);  
};
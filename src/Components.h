#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class CCurrentPosition{
    public:
    std::string block;
    CCurrentPosition(std::string);
};

class CSprite{
    public:
    sf::Sprite figure;
    CSprite(sf::Texture &texture);
};

class CValidMoves{
    public:
    std::vector<std::string> moves;
    CValidMoves(std::vector<std::string> moves);  
};
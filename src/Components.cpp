#include "Components.h"

CCurrentPosition::CCurrentPosition(std::string block):block(block){}

CValidMoves::CValidMoves(std::vector<std::string> moves):moves(moves){}

CSprite::CSprite(sf::Texture &texture){
    figure.setTexture(texture);
    figure.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}
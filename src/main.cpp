#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <iostream>
#include <math.h>
#include "Game.h"

struct TOP_DOWN_CENTER
{
    float top_right_x;
    float bottom_left_y;
    float x_center;
    float y_center;
};

std::map<std::string, TOP_DOWN_CENTER> BOARD = {
    {"A8", {0, 125, 62.5, 62.5}},
    {"A7", {0, 250, 62.5, 187.5}},
    {"A6", {0, 375, 62.5, 312.5}},
    {"A5", {0, 500, 62.5, 437.5}},
    {"A4", {0, 625, 62.5, 562.5}},
    {"A3", {0, 750, 62.5, 687.5}},
    {"A2", {0, 875, 62.5, 812.5}},
    {"A1", {0, 1000, 62.5, 937.5}},

    {"B8", {125, 125, 187.5, 62.5}},
    {"B7", {125, 250, 187.5, 187.5}},
    {"B6", {125, 375, 187.5, 312.5}},
    {"B5", {125, 500, 187.5, 437.5}},
    {"B4", {125, 625, 187.5, 562.5}},
    {"B3", {125, 750, 187.5, 687.5}},
    {"B2", {125, 875, 187.5, 812.5}},
    {"B1", {125, 1000, 187.5, 937.5}},

    {"C8", {250, 125, 312.5, 62.5}},
    {"C7", {250, 250, 312.5, 187.5}},
    {"C6", {250, 375, 312.5, 312.5}},
    {"C5", {250, 500, 312.5, 437.5}},
    {"C4", {250, 625, 312.5, 562.5}},
    {"C3", {250, 750, 312.5, 687.5}},
    {"C2", {250, 875, 312.5, 812.5}},
    {"C1", {250, 1000, 312.5, 937.5}},

    {"D8", {375, 125, 437.5, 62.5}},
    {"D7", {375, 250, 437.5, 187.5}},
    {"D6", {375, 375, 437.5, 312.5}},
    {"D5", {375, 500, 437.5, 437.5}},
    {"D4", {375, 625, 437.5, 562.5}},
    {"D3", {375, 750, 437.5, 687.5}},
    {"D2", {375, 875, 437.5, 812.5}},
    {"D1", {375, 1000, 437.5, 937.5}},

    {"E8", {500, 125, 562.5, 62.5}},
    {"E7", {500, 250, 562.5, 187.5}},
    {"E6", {500, 375, 562.5, 312.5}},
    {"E5", {500, 500, 562.5, 437.5}},
    {"E4", {500, 625, 562.5, 562.5}},
    {"E3", {500, 750, 562.5, 687.5}},
    {"E2", {500, 875, 562.5, 812.5}},
    {"E1", {500, 1000, 562.5, 937.5}},

    {"F8", {625, 125, 687.5, 62.5}},
    {"F7", {625, 250, 687.5, 187.5}},
    {"F6", {625, 375, 687.5, 312.5}},
    {"F5", {625, 500, 687.5, 437.5}},
    {"F4", {625, 625, 687.5, 562.5}},
    {"F3", {625, 750, 687.5, 687.5}},
    {"F2", {625, 875, 687.5, 812.5}},
    {"F1", {625, 1000, 687.5, 937.5}},

    {"G8", {750, 125, 812.5, 62.5}},
    {"G7", {750, 250, 812.5, 187.5}},
    {"G6", {750, 375, 812.5, 312.5}},
    {"G5", {750, 500, 812.5, 437.5}},
    {"G4", {750, 625, 812.5, 562.5}},
    {"G3", {750, 750, 812.5, 687.5}},
    {"G2", {750, 875, 812.5, 812.5}},
    {"G1", {750, 1000, 812.5, 937.5}},

    {"H8", {875, 125, 937.5, 62.5}},
    {"H7", {875, 250, 937.5, 187.5}},
    {"H6", {875, 375, 937.5, 312.5}},
    {"H5", {875, 500, 937.5, 437.5}},
    {"H4", {875, 625, 937.5, 562.5}},
    {"H3", {875, 750, 937.5, 687.5}},
    {"H2", {875, 875, 937.5, 812.5}},
    {"H1", {875, 1000, 937.5, 937.5}},

};

int main()
{

     Game chess_game = Game();
     chess_game.run();
    // std::cout << BOARD["H1"].bottom_left_y << std::endl;

    // for (const auto &x : BOARD)
    // {
    //     std::cout << x.first << ":"
    //               << "TOP X:" << x.second.top_right_x << ", BOTTOM Y:" << x.second.bottom_left_y
    //               << "| CENTER X:" << x.second.x_center << ", CENTER Y:" << x.second.y_center << std::endl;
    // }

    // sf::RenderWindow window(sf::VideoMode(1000, 1000), "CHESS!");
    // window.setFramerateLimit(60);

    // sf::Texture board;
    // sf::Sprite board_sprite;
    // board.loadFromFile("assets/board.jpg");
    // board_sprite.setTexture(board);

    // sf::Texture pawn;
    // sf::Sprite pawn_sprite;
    // pawn.loadFromFile("assets/pawn.png");
    // pawn_sprite.setTexture(pawn);
    // pawn_sprite.setOrigin(pawn.getSize().x / 2, pawn.getSize().y / 2);
    // int x = 0;
    // int y = 0;
    // bool move_pawn = false;
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         if (event.type == sf::Event::KeyPressed)
    //         {
    //             if (event.key.code = sf::Keyboard::Q)
    //             {
    //                 window.close();
    //             }
    //         }
    //         if (event.type == sf::Event::MouseButtonPressed)
    //         {
    //             if (event.mouseButton.button == sf::Mouse::Left)
    //             {
    //                 move_pawn = true;
    //                 std::cout << event.mouseButton.x << ":" << event.mouseButton.y << std::endl;
    //             }
    //         }
    //         if (event.type == sf::Event::MouseButtonReleased)
    //         {
    //             if (event.mouseButton.button == sf::Mouse::Left)
    //             {
    //                 move_pawn = false;
    //                 for (auto const &x : BOARD)
    //                 {
    //                     if ((x.second.top_right_x < pawn_sprite.getPosition().x && x.second.top_right_x + 125 > pawn_sprite.getPosition().x) &&
    //                         (x.second.bottom_left_y - 125 < pawn_sprite.getPosition().y && x.second.bottom_left_y > pawn_sprite.getPosition().y))
    //                     {
    //                         std::cout << "Pawn is in " << x.first << " Block" << std::endl;
    //                         pawn_sprite.setPosition(x.second.x_center,x.second.y_center);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     window.clear();
    //     window.draw(board_sprite);
    //     window.draw(pawn_sprite);
    //     if (move_pawn &&
    //         ((pawn_sprite.getPosition().x - (pawn_sprite.getTexture()->getSize().x) / 2) < sf::Mouse::getPosition(window).x) &&
    //         ((pawn_sprite.getPosition().x + (pawn_sprite.getTexture()->getSize().x) / 2) > sf::Mouse::getPosition(window).x) &&
    //         ((pawn_sprite.getPosition().y + (pawn_sprite.getTexture()->getSize().y) / 2) > sf::Mouse::getPosition(window).y) &&
    //         ((pawn_sprite.getPosition().y - (pawn_sprite.getTexture()->getSize().y) / 2) < sf::Mouse::getPosition(window).y)

    //     )
    //         pawn_sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    //     window.display();
    // }

    return 0;
}

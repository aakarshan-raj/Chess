#include "Game.h"
#include <iostream>
Game::Game()
{
    init();
}

void Game::init()
{
    Game::running = true;
    number_of_entity = 0;

    initialiseChessboard();
    loadPieces();
    loadTexture();

    window.create(sf::VideoMode(1000, 1000), "Chess!");
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (running)
    {
        sRender();
        sUserInput();
    }
}

void Game::sRender()
{
    window.clear();
    window.draw(board_sprite);
    for (auto const &piece : entities)
    {
        std::cout<<"hi"<<std::endl;
        if (piece->tag == "pawn" && piece->is_black)
        {
            black_pawn_spite.setPosition(chessbaord[piece->CcurrentPosition->block].x_center,
                                         chessbaord[piece->CcurrentPosition->block].y_center);
             window.draw(black_pawn_spite);                            
        }
        if (piece->tag == "pawn" && !piece->is_black)
        {
            white_pawn_spite.setPosition(chessbaord[piece->CcurrentPosition->block].x_center,
                                         chessbaord[piece->CcurrentPosition->block].y_center);
            window.draw(white_pawn_spite);
        }
    }
    window.display();
}

void Game::sUserInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            running = false;
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Q)
            {
                window.close();
                running = false;
            }
        }
    }
}

void Game::loadPieces()
{

    for (char file = 'A'; file <= 'H'; ++file)
    {
        std::shared_ptr<Entity> x = std::make_shared<Entity>(number_of_entity, "pawn", false);
        number_of_entity++;
        entities.push_back(x);
        x->CcurrentPosition = std::make_shared<CCurrentPosition>(std::string(1, file) + "7");
    }

    for (char file = 'A'; file <= 'H'; ++file)
    {
        std::shared_ptr<Entity> x = std::make_shared<Entity>(number_of_entity, "pawn", true);
        number_of_entity++;
        entities.push_back(x);
        x->CcurrentPosition = std::make_shared<CCurrentPosition>(std::string(1, file) + "2");
    }
}

void Game::initialiseChessboard()
{
    chessbaord = {
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
}

void Game::loadTexture()
{
    board.loadFromFile("assets/board.jpg");
    board_sprite.setTexture(board);

    black_pawn.loadFromFile("assets/pieces/black-pawn.png");
    black_pawn_spite.setTexture(black_pawn);
    black_pawn_spite.setOrigin(black_pawn.getSize().x / 2, black_pawn.getSize().y/2);

    white_pawn.loadFromFile("assets/pieces/white-pawn.png");
    white_pawn_spite.setTexture(white_pawn);
    white_pawn_spite.setOrigin(white_pawn.getSize().x / 2, white_pawn.getSize().y/2);
}

// void Game::initialiseChessBoard()
// {
//     chessbaord[0][0] = {0, 125, 62.5, 62.5, "A8"};
//     chessbaord[1][0] = {125, 125, 187.5, 62.5, "B8"};
//     chessbaord[2][0] = {250, 125, 312.5, 62.5, "C8"};
//     chessbaord[3][0] = {375, 125, 437.5, 62.5, "D8"};
//     chessbaord[4][0] = {500, 125, 562.5, 62.5, "E8"};
//     chessbaord[5][0] = {625, 125, 687.5, 62.5, "F8"};
//     chessbaord[6][0] = {750, 125, 812.5, 62.5, "G8"};
//     chessbaord[7][0] = {875, 125, 937.5, 62.5, "H8"};

//     chessbaord[0][1] = {0, 250, 62.5, 187.5, "A7"};
//     chessbaord[1][1] = {125, 250, 187.5, 187.5, "B7"};
//     chessbaord[2][1] = {250, 250, 312.5, 187.5, "C7"};
//     chessbaord[3][1] = {375, 250, 437.5, 187.5, "D7"};
//     chessbaord[4][1] = {500, 250, 562.5, 187.5, "E7"};
//     chessbaord[5][1] = {625, 250, 687.5, 187.5, "F7"};
//     chessbaord[6][1] = {750, 250, 812.5, 187.5, "G7"};
//     chessbaord[7][1] = {875, 250, 937.5, 187.5, "H7"};

//     chessbaord[0][2] = {0, 375, 62.5, 312.5, "A6"};
//     chessbaord[1][2] = {125, 375, 187.5, 312.5, "B6"};
//     chessbaord[2][2] = {250, 375, 312.5, 312.5, "C6"};
//     chessbaord[3][2] = {375, 375, 437.5, 312.5, "D6"};
//     chessbaord[4][2] = {500, 375, 562.5, 312.5, "E6"};
//     chessbaord[5][2] = {625, 375, 687.5, 312.5, "F6"};
//     chessbaord[6][2] = {750, 375, 812.5, 312.5, "G6"};
//     chessbaord[7][2] = {875, 375, 937.5, 312.5, "H6"};

//     chessbaord[0][3] = {0, 500, 62.5, 437.5, "A5"};
//     chessbaord[1][3] = {125, 500, 187.5, 437.5, "B5"};
//     chessbaord[2][3] = {250, 500, 312.5, 437.5, "C5"};
//     chessbaord[3][3] = {375, 500, 437.5, 437.5, "D5"};
//     chessbaord[4][3] = {500, 500, 562.5, 437.5, "E5"};
//     chessbaord[5][3] = {625, 500, 687.5, 437.5, "F5"};
//     chessbaord[6][3] = {750, 500, 812.5, 437.5, "G5"};
//     chessbaord[7][3] = {875, 500, 937.5, 437.5, "H5"};

//     chessbaord[0][4] = {0, 625, 62.5, 562.5, "A4"};
//     chessbaord[1][4] = {125, 625, 187.5, 562.5, "B4"};
//     chessbaord[2][4] = {250, 625, 312.5, 562.5, "C4"};
//     chessbaord[3][4] = {375, 625, 437.5, 562.5, "D4"};
//     chessbaord[4][4] = {500, 625, 562.5, 562.5, "E4"};
//     chessbaord[5][4] = {625, 625, 687.5, 562.5, "F4"};
//     chessbaord[6][4] = {750, 625, 812.5, 562.5, "G4"};
//     chessbaord[7][4] = {875, 625, 937.5, 562.5, "H4"};

//     chessbaord[0][5] = {0, 750, 62.5, 687.5, "A3"};
//     chessbaord[1][5] = {125, 750, 187.5, 687.5, "B3"};
//     chessbaord[2][5] = {250, 750, 312.5, 687.5, "C3"};
//     chessbaord[3][5] = {375, 750, 437.5, 687.5, "D3"};
//     chessbaord[4][5] = {500, 750, 562.5, 687.5, "E3"};
//     chessbaord[5][5] = {625, 750, 687.5, 687.5, "F3"};
//     chessbaord[6][5] = {750, 750, 812.5, 687.5, "G3"};
//     chessbaord[7][5] = {875, 750, 937.5, 687.5, "H3"};

//     chessbaord[0][6] = {0, 875, 62.5, 812.5, "A2"};
//     chessbaord[1][6] = {125, 875, 187.5, 812.5, "B2"};
//     chessbaord[2][6] = {250, 875, 312.5, 812.5, "C2"};
//     chessbaord[3][6] = {375, 875, 437.5, 812.5, "D2"};
//     chessbaord[4][6] = {500, 875, 562.5, 812.5, "E2"};
//     chessbaord[5][6] = {625, 875, 687.5, 812.5, "F2"};
//     chessbaord[6][6] = {750, 875, 812.5, 812.5, "G2"};
//     chessbaord[7][6] = {875, 875, 937.5, 812.5, "H2"};

//     chessbaord[0][7] = {0, 1000, 62.5, 937.5, "A1"};
//     chessbaord[1][7] = {125, 1000, 187.5, 937.5, "B1"};
//     chessbaord[2][7] = {250, 1000, 312.5, 937.5, "C1"};
//     chessbaord[3][7] = {375, 1000, 437.5, 937.5, "D1"};
//     chessbaord[4][7] = {500, 1000, 562.5, 937.5, "E1"};
//     chessbaord[5][7] = {625, 1000, 687.5, 937.5, "F1"};
//     chessbaord[6][7] = {750, 1000, 812.5, 937.5, "G1"};
//     chessbaord[7][7] = {875, 1000, 937.5, 937.5, "H1"};
// }

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Entity.h"

class Game
{

public:
    sf::RenderWindow window;
    sf::Texture board;
    sf::Sprite board_sprite;

    sf::Texture black_pawn_texture;
    sf::Texture black_king_texture;
    sf::Texture black_queen_texture;
    sf::Texture black_bishop_texture;
    sf::Texture black_knight_texture;
    sf::Texture black_rook_texture;

    sf::Texture white_pawn_texture;
    sf::Texture white_king_texture;
    sf::Texture white_queen_texture;
    sf::Texture white_bishop_texture;
    sf::Texture white_knight_texture;
    sf::Texture white_rook_texture;

    std::vector<std::shared_ptr<Entity>> entities;
    struct top_down_center
    {
        float top_right_x;
        float bottom_left_y;
        float x_center;
        float y_center;
    };
    std::map<std::string, top_down_center> chessbaord;

    void sRender();    // handle all rendering
    void sUserInput(); // handle all userinputs

    void loadPieces(); // create all pieces and add it to eneities vector
    void initialiseChessboard();
    void loadTexture(); // load all the texture;

    bool running;
    int number_of_entity;

    void init();
    void run(); // Game Loop
    Game();
};
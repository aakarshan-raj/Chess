#include <string>
#include <memory>
#include "Components.h"

class Entity
{
public:
    int id;
    std::string tag; // use enum later
    bool is_black;
    std::shared_ptr<CCurrentPosition> CcurrentPosition;
    std::shared_ptr<CSprite> Csprite;

    Entity(int id, std::string tag, bool is_black);
};
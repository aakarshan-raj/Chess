#include <string>
#include <memory>
#include "Components.h"

class Entity{
    public:
    int id;
    std::string tag; // use enum later
    bool is_black;
    std::shared_ptr<CCurrentPosition> CcurrentPosition;
    Entity(int id,std::string tag,bool is_black);
};
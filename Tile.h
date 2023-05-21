#include "raylib.h"
#include <string>

class Tile
{   
    private:
        Vector2 coord{};
        bool isEmpty{};
    public:
        Tile(/*Vector2 coord*/);
        bool IsEmpty(){ return isEmpty;};
        bool SetTile(bool _isEmpty){isEmpty = _isEmpty;};
        std::string data = "Je suis la dans les ombre!";
};
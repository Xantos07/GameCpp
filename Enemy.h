#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy :  public BaseCharacter
{
public:

    Enemy(Vector2 pos, Texture2D tex);
    virtual void Tick(float deltaTime) override;
    virtual void DrawnCollision() override;
    void SetTarget(Character* character){target = character; }
    virtual Vector2 GetScreenPos() override;

private:
    Character* target;
};

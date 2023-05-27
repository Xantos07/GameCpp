#include "Grid.h"
#include "raymath.h"
#include <iostream>
#include <vector>


Grid::Grid(int winWidth, int winHeight,float scaleMap, int sizePixel) :
 windowWidth(winWidth),  windowHeight(winHeight), windowPixel(sizePixel), scale(scaleMap)
{  
    windowWidth = (windowWidth / windowPixel) * scale;
    windowHeight = (windowHeight / windowPixel) * scale;    
  
    int x = (windowWidth/64) * scale;
    int y = (windowHeight/64) * scale;

    tableau.resize(windowWidth);

    for (auto& x : tableau) 
    {
        x.resize(y, Tile());
    }
    // Peu causer une latence
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {            
            tableau[i][j] = Tile();            
            tableau[i][j].SetCoord(Vector2{i*64.f,j*64.f});
            tableau[i][j].SetWorldPos(Vector2{i*64.f + worldPos.x,j*64.f+ worldPos.y});
        }
    }
    
}

void Grid::Tick(float t)
{
    //DrawText(tableau[0][0].data.c_str(), 0, 0, 15, RED);

    /*
    std::string boolString = (tableau[0][0].IsEmpty()) ? "true" : "false";
    DrawText(boolString.c_str(), 0, 0, 15, RED);
    std::string boolString2 = (tableau[1][0].IsEmpty()) ? "true" : "false";
    DrawText(boolString2.c_str(), 0, 100, 15, RED);
    */  

    //tout les 64px pour les tiles donc le joueur aura une pose egalement 
    //et le convertir sa pos par rapport à 64 et en déduire le produit pour avoir la tuile dans le tableau
    //Vector2 posPlayer = {Vector2{target->GetScreenPos().x /64.f, target->GetScreenPos().y /64.f }};

    Vector2 test = Vector2Subtract(target -> GetWorldPos(), worldPos);
    DrawCircle(worldPos.x,worldPos.y, 5.f, GREEN); 
    DrawCircle(worldPos.x,worldPos.y, 5.f, GREEN); 

    DrawCircle(target->GetWorldPos().x,target->GetWorldPos().y, 10.f, YELLOW);
    DrawCircle(target->GetWorldPos().x,target->GetWorldPos().y, 10.f, YELLOW);

    int score = test.x / 64;
    int score2 = test.y / 64; 

    //DrawText(TextFormat("posPlayer: %08i", score), 0, 100, 15, RED);
    //DrawText(TextFormat("posPlayer2: %08i",  score2), 0, 0, 15, RED);

    DrawRectangle(target->GetScreenPos().x + 64,target->GetScreenPos().y, 64 , 64, BLACK);
    DrawRectangle(target->GetScreenPos().x ,target->GetScreenPos().y+ 64, 64 , 64, BLACK);
    DrawRectangle(target->GetScreenPos().x - 64,target->GetScreenPos().y, 64 , 64, BLACK);
    DrawRectangle(target->GetScreenPos().x,target->GetScreenPos().y- 64, 64 , 64, BLACK);

     tableau[score][score2].SetTile(false);
    int x = (windowWidth/64) * scale;
    int y = (windowHeight/64) * scale;

    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {       
            tableau[i][j].SetWorldPos(Vector2Scale(target->GetWorldPos(), -1.0f));
            tableau[i][j].Render(target->GetWorldPos(), Vector2{i*x*2,j*y*2});
        }
    }
}

void Grid::DrawGrid()
{
    for (int x = 0; x < windowWidth; x++)
    {
        DrawLine(worldPos.x + x * windowPixel * scale,
        worldPos.y + windowPixel * scale, 
        worldPos.x + x * windowPixel * scale, 
        worldPos.y + windowPixel * scale * windowHeight, PINK);

        DrawLine(worldPos.x + windowPixel * scale,
        worldPos.y + x * windowPixel * scale, 
        worldPos.x * windowPixel * scale * -windowWidth, 
        worldPos.y + x * windowPixel * scale, PINK);
    }

    //DrawRectangleLines(GetScreenPos().x + x * windowPixel * scale, GetScreenPos().y + y * windowPixel * scale, windowWidth, windowHeight, PINK);
}

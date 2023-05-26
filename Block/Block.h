//
// Created by xProsek on 24.05.2023.
//

#ifndef GANE_4_UNI_IML_BLOCK_H
#define GANE_4_UNI_IML_BLOCK_H


#include "../Player/Player.h"

class Block {

private:
    //2x wallSize
    int minPosX = 212;
    //Crashuje przy automatyzacji :(
    //windowSize - 2x wallSize
    int maxPosX = 1280 - 212;

    float lastPlayerY = 720;
    float maxSizeX = 1068;
    float minSizeX = 106;
    float sizeX;
    float sizeY = 32;

    sf::RenderWindow* windowPtr;
    sf::RectangleShape* playerPtr;

    Player* player;

    bool playerWentThrough = false;
public:

    sf::Vector2f position;
    sf::RectangleShape left;
    sf::RectangleShape middle;
    sf::RectangleShape right;
    Block(sf::RenderWindow* windowPtr, sf::RectangleShape* playerPtr, Player* player, sf::Vector2f position, float sizeX);
    ~Block();


    bool checkCollision(sf::RectangleShape* player);
    void update();
    void render();
    void createBlock();

    void worldMoving();

};


#endif //GANE_4_UNI_IML_BLOCK_H

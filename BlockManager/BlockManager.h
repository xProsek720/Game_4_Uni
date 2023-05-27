//
// Created by xProsek on 24.05.2023.
//

#ifndef GANE_4_UNI_IML_BLOCKMANAGER_H
#define GANE_4_UNI_IML_BLOCKMANAGER_H


#include "../Player/Player.h"
#include "../Block/Block.h"

class BlockManager
        {
private:
    int minBlockSize = 106;
    int maxBlockSize;
    int xMinPos;
    int xMaxPos;
    int numOfBlocksSpawned = 0;
    int numOfMaxBlocks;
    float lastPlayerY = 720;
    sf::RectangleShape* playerPtr;
    sf::RenderWindow* windowPtr;

    std::vector<Block> blocks;
    bool letsScroll = false;
    bool firstBlock = true;
    Player* player;


public:


    BlockManager(sf::RenderWindow* windowPtr, sf::RectangleShape* playerPtr, Player* player, int numOfMaxBlocks);
    ~BlockManager();

    void render();
    void update();

    friend Block;
    Block createBlock(int xMinPos, int xMaxPos, int minBlockSize, int maxBlockSize);

    sf::Vector2f randomizeBlockPos(int from, int to);
    float randomizeBlockSize(int minSize, int maxSize);
    void spawnBlock();
    void updateBlocks();
    void setPlayerPtr(sf::RectangleShape* playerPtr);
    void setPlayer(Player* player);
    void moveAllBlocks(float scrollSpeed, float scrollSpeed2);
    void superScroll();
    void worldMoving();

};


#endif //GANE_4_UNI_IML_BLOCKMANAGER_H

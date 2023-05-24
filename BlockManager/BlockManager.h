//
// Created by xProsek on 24.05.2023.
//

#ifndef GANE_4_UNI_IML_BLOCKMANAGER_H
#define GANE_4_UNI_IML_BLOCKMANAGER_H


class BlockManager
        {
private:
    int minBlockSize;
    int maxBlockSize;
    int xMinPos;
    int xMaxPos;
    int numOfBlocksSpawned = 0;
    int numOfMaxBlocks;
    sf::RectangleShape* playerPtr;
    sf::RenderWindow* windowPtr;
    std::vector<Block> blocks;

public:

    BlockManager(sf::RenderWindow* windowPtr, sf::RectangleShape* playerPtr, int numOfMaxBlocks);
    ~BlockManager();

    void render();
    void update();

    Block createBlock(int xMinPos, int xMaxPos, int minBlockSize, int maxBlockSize);

    sf::Vector2f randomizeBlockPos(int from, int to);
    float randomizeBlockSize(int minSize, int maxSize);
    void spawnBlock();
    void updateBlocks();
};


#endif //GANE_4_UNI_IML_BLOCKMANAGER_H

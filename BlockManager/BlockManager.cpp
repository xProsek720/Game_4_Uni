//
// Created by xProsek on 24.05.2023.
//
#include "../includes/imports.h"
#include "BlockManager.h"


//Jak dostane klase Player to zamienić tutaj playerPtr na klasa pointer

BlockManager::BlockManager(sf::RenderWindow* windowPtr, sf::RectangleShape* playerPtr, Player* player, int numOfMaxBlocks)
{
    this->windowPtr = windowPtr;
    this->playerPtr = playerPtr;
    this->numOfMaxBlocks = numOfMaxBlocks;
    this->player = player;


}

BlockManager::~BlockManager()
{

}

void BlockManager::render()
{
    for (int i = 0; i < this->blocks.size(); ++i )
    {
        this->blocks[i].render();
    }
}

void BlockManager::update()
{
    if (this->blocks.size() < this->numOfMaxBlocks)
    {
        spawnBlock();
    }

    int tCount = 0;
    int fCount = 0;
    for (int i = 0; i < this->blocks.size(); ++i)
    {
        if (blocks[i].checkCollision(this->playerPtr) && this->playerPtr->getPosition().y + 25 < blocks[i].position.y)
        {
            tCount +=1;
        }
        else
        {
            fCount +=1;
        }
    }
    if (tCount > 0)
    {
        this->player->colision = true;
    }
    else
    {
        this->player->colision = false;
    }

    updateBlocks();

}

sf::Vector2f BlockManager::randomizeBlockPos(int from, int to)
{
    int randomNum1 = (rand() % (to-from)) + from;
    int yPos = (720) - (120 * this->blocks.size());
    return sf::Vector2f(randomNum1, yPos);
}

float BlockManager::randomizeBlockSize(int minSize, int maxSize)
{
    int randomNum = (rand() % (maxSize-minSize)) + minSize;
    return randomNum;
}

Block BlockManager::createBlock(int xMinPos, int xMaxPos, int minBlockSize, int maxBlockSize)
{
    this->numOfBlocksSpawned += 1;
    if (this->numOfBlocksSpawned%10 == 0)
    {
        std::cout <<std::endl<< this->numOfBlocksSpawned;
        return Block(this->windowPtr, this->playerPtr, sf::Vector2f (212.f,(720) - (120 * this->blocks.size())), 1064);
    }
    else
    {
        if (this->numOfBlocksSpawned%2 == 0)
        {
            if ((this->minBlockSize > 115 || this->minBlockSize == NULL) && blocks.size() < this->numOfMaxBlocks)
            {
                this->minBlockSize = 600 - (numOfBlocksSpawned*2);
            }
            if ((this->maxBlockSize == NULL || this->maxBlockSize > 106) && blocks.size() < this->numOfMaxBlocks)
            {
                this->maxBlockSize = 865 - numOfBlocksSpawned*2;
            }
            float blockLen = 0;
            sf::Vector2f pos = sf::Vector2f(1.f, 1.f);
            float size = 0;
            while ((blockLen < this->minBlockSize || blockLen > this->maxBlockSize) &&pos.x + size <300 && blocks.size() < this->numOfMaxBlocks)
            {
                pos = randomizeBlockPos(xMinPos, xMaxPos);
                size = randomizeBlockSize(minBlockSize, maxBlockSize);
                blockLen = pos.x + size;
            }

            return Block(this->windowPtr, this->playerPtr, pos, size);
        }
        else
        {
            if ((this->minBlockSize > 115 || this->minBlockSize == NULL) && blocks.size() < this->numOfMaxBlocks)
            {
                this->minBlockSize = 600 - (numOfBlocksSpawned*2);
            }
            if ((this->maxBlockSize == NULL || this->maxBlockSize > 106) && blocks.size() < this->numOfMaxBlocks)
            {
                this->maxBlockSize = 865 - numOfBlocksSpawned*2;
            }
            float blockLen = 0;
            sf::Vector2f pos = sf::Vector2f(1.f, 1.f);
            float size = 0;
            while ((blockLen < this->minBlockSize || blockLen > this->maxBlockSize) &&pos.x + size <865 && blocks.size() < this->numOfMaxBlocks)
            {
                pos = randomizeBlockPos(xMinPos, xMaxPos);
                size = randomizeBlockSize(minBlockSize, maxBlockSize);
                blockLen = pos.x + size;
            }

            return Block(this->windowPtr, this->playerPtr, pos, size);
        }
    }
}

void BlockManager::spawnBlock()
{

    Block b = createBlock(212, 865-107, minBlockSize, 865);
    this->blocks.push_back(b);
}

void BlockManager::updateBlocks()
{
    for (int i = 0; i < this->blocks.size(); ++i )
    {
        this->blocks[i].update();

        //std::cout << std::endl << blocks[i].middle.getPosition().y;
        if(blocks[i].middle.getPosition().y > 920)
        {

            blocks.erase(this->blocks.begin() + i);
        }
    }
}

void BlockManager::setPlayerPtr(sf::RectangleShape* playerPtr)
{
    this->playerPtr = playerPtr;

}

void BlockManager::setPlayer(Player *player)
{
    this->player = player;

}

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
    int yPos = (720) - (120);
    int randomNum1 = (rand() % (to-from)) + from;
    if (this->blocks.size() > 0)
    {
        int blockNum = this->blocks.size();
        Block* lastB = this->blocks[blockNum-1].getPtr();
        yPos = (lastB->middle.getPosition().y) - (120);
    }
    else
    {
        yPos = 600;
    }

    return sf::Vector2f(randomNum1, yPos);
}

float BlockManager::randomizeBlockSize(int minSize, int maxSize)
{
    int randomNum = (rand() % (maxSize-minSize)) + minSize;
    return randomNum;
}

Block BlockManager::createBlock(int xMinPos, int xMaxPos, int minBlockSize, int maxBlockSize)
{
    
    this->minBlockSize = minBlockSize;
    int blockNum = this->blocks.size();
    Block* lastB = this->blocks[blockNum-1].getPtr();
    this->numOfBlocksSpawned += 1;
//    if(this->blocks.size() > 0)
//    std::cout << lastB->position.y << " " << this->blocks.size() << std::endl;
    if (this->numOfBlocksSpawned%10 == 0)
    {
        std::cout << this->numOfBlocksSpawned<< "\t\t\t\tw<=(IF%10)"<<std::endl;
        return Block(this->windowPtr, this->playerPtr, this->player, sf::Vector2f (212.f,(lastB->middle.getPosition().y) - 120), 1061);
    }
    else
    {
        if (this->numOfBlocksSpawned%3 == 0)
        {
            float blockLen = 0;
            sf::Vector2f pos = sf::Vector2f(1.f, 1.f);
            float size = 0;
            pos = randomizeBlockPos(xMinPos, xMaxPos);
            size = randomizeBlockSize(minBlockSize, maxBlockSize);
            if ((this->minBlockSize > 115 || this->minBlockSize == NULL) && this->blocks.size() <= this->numOfMaxBlocks)
            {
                this->minBlockSize = 300 - (numOfBlocksSpawned*2);
            }
            if ((this->maxBlockSize == NULL || this->maxBlockSize > 206) && this->blocks.size() <= this->numOfMaxBlocks)
            {
                this->maxBlockSize = 600 - numOfBlocksSpawned*2;
            }
            blockLen = size - pos.x;
            while ((blockLen < this->minBlockSize || blockLen > this->maxBlockSize) &&size - pos.x >600 && this->blocks.size() <= this->numOfMaxBlocks)
            {
                pos = randomizeBlockPos(xMinPos, xMaxPos);
                size = randomizeBlockSize(minBlockSize, maxBlockSize);
                blockLen = size - pos.x;
            }
            blockLen = size - pos.x;
            std::cout << this->numOfBlocksSpawned << ". " <<size << " " << pos.x <<" " <<pos.y<< " " << blockLen << "\t\t<=(ELSE, IF %3)" << std::endl;
            return Block(this->windowPtr, this->playerPtr, this->player, pos, size);
        }
        else
        {
            float blockLen = 0;
            sf::Vector2f pos = sf::Vector2f(1.f, 1.f);
            float size = 0;
            pos = randomizeBlockPos(xMinPos, xMaxPos);
            size = randomizeBlockSize(minBlockSize, maxBlockSize);
            if ((this->minBlockSize > 115 || this->minBlockSize == NULL) && this->blocks.size() <= this->numOfMaxBlocks)
            {
                this->minBlockSize = 150 - (numOfBlocksSpawned*2);
            }
            if ((this->maxBlockSize == NULL || this->maxBlockSize > 300) && this->blocks.size() <= this->numOfMaxBlocks)
            {
                this->maxBlockSize = 300 - numOfBlocksSpawned*2;
            }
            blockLen = size - pos.x;
            while ((blockLen < this->minBlockSize || blockLen > this->maxBlockSize) &&size - pos.x >300 && this->blocks.size() <= this->numOfMaxBlocks)
            {
                pos = randomizeBlockPos(xMinPos, xMaxPos);
                size = randomizeBlockSize(minBlockSize, maxBlockSize);
                blockLen = size - pos.x;
            }

            std::cout << this->numOfBlocksSpawned << ". " <<size << " " << pos.x <<" " <<pos.y<< " " << blockLen << "\t\t<=(ELSE, ELSE)"<<std::endl;
            return Block(this->windowPtr, this->playerPtr, this->player, pos, size);
        }
    }
}

void BlockManager::spawnBlock()
{

    Block b = createBlock(212, 865-107, this->minBlockSize, 865);
    b.render();
    this->blocks.push_back(b);
}

void BlockManager::updateBlocks()
{
    for (int i = 0; i < this->blocks.size(); ++i )
    {
        this->blocks[i].update();

        //std::cout << std::endl << blocks[i].middle.getPosition().y;
        if(blocks[i].middle.getPosition().y > 720)
        {

            blocks.erase(this->blocks.begin() + i);
        }
        superScroll();
        worldMoving();
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

void BlockManager::moveAllBlocks(float scrollSpeed, float scrollSpeedY)
{

    for (int i = 0; i < this->blocks.size(); ++i)
    {
        Block* managedBlock = (blocks[i].getPtr());
        managedBlock->left.setPosition(managedBlock->left.getPosition().x + scrollSpeed, managedBlock->left.getPosition().y + scrollSpeedY);
        managedBlock->middle.setPosition(managedBlock->middle.getPosition().x + scrollSpeed, managedBlock->middle.getPosition().y + scrollSpeedY);
        managedBlock->right.setPosition(managedBlock->right.getPosition().x + scrollSpeed, managedBlock->right.getPosition().y + scrollSpeedY);

        this->blocks[i].update();

        //std::cout << std::endl << blocks[i].middle.getPosition().y;
        if (blocks[i].middle.getPosition().y > 720) {

            blocks.erase(this->blocks.begin() + i);
        }
    }
}

void BlockManager::superScroll()
{
    float scrollSpeed = 1.f;
    if (this->playerPtr->getPosition().y < 16)
    {
        this->letsScroll = true;
    }
    while (this->playerPtr->getPosition().y < 320 && letsScroll)
    {
        this->playerPtr->setPosition(this->playerPtr->getPosition().x, this->playerPtr->getPosition().y + scrollSpeed);
        this->moveAllBlocks(0, scrollSpeed);


    }

    this->letsScroll = false;

}

void BlockManager::worldMoving()
{
    if (this->playerPtr->getPosition().y < this->lastPlayerY)
    {
        //std::cout << "LOL1" <<std::endl;

        //1.2f zamienić na player speed ale jest zbyt późno


        this->moveAllBlocks(0, this->player->movementSpeed);
//            this->blocks[i].left.setPosition(this->blocks[i].left.getPosition().x, this->blocks[i].left.getPosition().y + this->player->movementSpeed);
//            this->blocks[i].middle.setPosition(this->blocks[i].middle.getPosition().x, this->blocks[i].middle.getPosition().y + this->player->movementSpeed);
//            this->blocks[i].right.setPosition(this->blocks[i].right.getPosition().x, this->blocks[i].right.getPosition().y + this->player->movementSpeed);
        }
        //this->position.y -= playerPtr->getPosition().y - lastPlayerY;
        this->lastPlayerY = this->playerPtr->getPosition().y;


    if (this->playerPtr->getPosition().y > this->lastPlayerY)
    {
//        //std::cout << "LOL2" <<std::endl;
//
//        this->left.setPosition(this->left.getPosition().x, this->left.getPosition().y - 1.2f);
//        this->middle.setPosition(this->middle.getPosition().x, this->middle.getPosition().y - 1.2f);
//        this->right.setPosition(this->right.getPosition().x, this->right.getPosition().y - 1.2f);
//
//        //this->position.y += playerPtr->getPosition().y - lastPlayerY;
        this->lastPlayerY = this->playerPtr->getPosition().y;
    }

}

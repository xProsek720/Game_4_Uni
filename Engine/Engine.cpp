//
// Created by xProsek on 23.05.2023.
//
#include "../includes/imports.h"
#include "Engine.h"



Engine::Engine(int windowWidth, int windowHeight, int bitsPerPixel, std::string title)
{
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
    this->bitsPerPixel = bitsPerPixel;
    this->title = title;


    gameLoop();
}

Engine::~Engine()
{
    std::cout << "ELO!";
}

sf::RenderWindow* Engine::getWindow()
{
    return this->windowPtr;
}

void Engine::loadClasses()
{
    Background bg(getWindow());
    this->bg = bg;
    Walls walls(getWindow());
    this->walls = walls;
    BlockManager bm(getWindow(), nullptr, 20);
    this->bm = bm;
    Player player(getWindow());
    this->player = player;
}

void Engine::gameLoop()
{
    sf::RenderWindow MainWindow(sf::VideoMode(windowWidth, windowHeight, bitsPerPixel), title);
    this->windowPtr = &MainWindow;
    gameStart();
    sf::Clock clock;
    while (MainWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        sf::Event event;

        while (MainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                MainWindow.close();
            }
            //std::cout << event.type << std::endl;



        }
        //Tu miejsce na aktualizacje klatek
        update();

        //Tu miejsce na render klatek
        render();
        MainWindow.display();
    }
}



void Engine::update()
{
    bg.update();
    walls.update();
    bm.update();
    player.update();
}

void Engine::render()
{
    bg.render();
    walls.render();
    bm.render();
    player.render();
}

void Engine::gameStart()
{
    loadClasses();
    walls.defaultVars();
    this->windowPtr->setFramerateLimit(60);
}

Engine *Engine::getPtr() {
    return this;
}

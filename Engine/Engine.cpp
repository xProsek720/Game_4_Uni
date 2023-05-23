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
void Engine::createWindow()
{

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
}

void Engine::gameLoop()
{
    sf::RenderWindow MainWindow(sf::VideoMode(windowWidth, windowHeight, bitsPerPixel), title);
    this->windowPtr = &MainWindow;
    loadClasses();

    walls.defaultVars();
    while (MainWindow.isOpen())
    {

        sf::Event event;

        while (MainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                MainWindow.close();
            }

            sf::Clock Clock;
            while (Clock.getElapsedTime().asMilliseconds() < 5.f)
            {
                //std::cout << Clock.getElapsedTime().asSeconds() << std::endl;
            }

            //Tu miejsce na aktualizacje klatek
            update();

            //Tu miejsce na render klatek
            render();
            MainWindow.display();

        }
    }
}



void Engine::update()
{
    bg.update();
    walls.update();
}

void Engine::render()
{
    bg.render();
    walls.render();

}

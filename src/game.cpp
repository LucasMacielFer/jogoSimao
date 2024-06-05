#include "game.h"

namespace GameMain
{
    Game::Game()
    {
        int size[2] = {360, 360};
        int pos1[2] = {300, 300};
        int pos2[2] = {700, 300};

        level = new GameParts::Level();
        player1 = new Entities::Player(pos1, size, "textures/player1.jpg");
        player2 = new Entities::Player(pos2, size, "textures/player2.jpg");
        level->addPlayer(player1);
        level->addPlayer(player2);
    }

    Game::~Game()
    {
        delete level;
        delete player1;
        delete player2;
    }

    void Game::run()
    {
        while(level->getWindow()->isOpen())
        {
            level->update();
            level->render();
        }
    }
}
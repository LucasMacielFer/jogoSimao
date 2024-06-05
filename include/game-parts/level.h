#pragma once
#include "../elements/entities/player.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameParts
{
    class Level
    {
    private:
        static int const MAX_PLAYERS = 2;
        const int nPlayers;
        std::vector<Entities::Player*> players;
        std::vector<sf::RectangleShape*> pRects;
        sf::RenderWindow* window;

    public:
        Level();
        ~Level();
        void addPlayer(Entities::Player* player);
        sf::Event getEvents();
        sf::RenderWindow* getWindow();
        void executeEvent(sf::Event e);
        void update();
        void render();
    };
}
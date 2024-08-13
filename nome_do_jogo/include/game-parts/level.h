#pragma once
#include "../elements/entities/player.h"
#include <SFML/Graphics.hpp>
#include <vector>

// Dá para usar um set ou list de players
// Usar map para texturas

namespace GameParts
{
    class Level
    {
    private:
        static int const MAX_PLAYERS = 2;
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
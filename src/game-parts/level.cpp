#include "../../include/game-parts/level.h"

namespace GameParts{
    Level::Level():
    nPlayers(0)
    {
        window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Game");
    }

    Level::~Level()
    {
        delete window;
    }

    void Level::addPlayer(Entities::Player* player)
    {
        if(players.size() < MAX_PLAYERS)
        {
            sf::Vector2f sz(player->getWidth(), player->getHeight());
            sf::RectangleShape* p = new sf::RectangleShape(sz);
            sf::Texture pTexture;
            pTexture.loadFromFile(player->getTexturePath());
            p->setTexture(&pTexture);
            players.push_back(player);
            p->setOrigin(sz.x / 2, sz.y / 2);
            p->setPosition(player->getPosition()->getX(), player->getPosition()->getY());
        }
    }

    sf::Event Level::getEvents()
    {
        sf::Event e;
        window->pollEvent(e);
        return e;
    }

    sf::RenderWindow* Level::getWindow()
    {
        return window;
    }

    void Level::executeEvent(sf::Event e)
    {
        if(e.type == sf::Event::Closed)
        {
            window->close();
        }
        else if(e.type == sf::Event::KeyPressed)
        {
            switch(e.key.code)
            {
                case sf::Keyboard::Key::A:
                    players[0]->move(-1);
                    break;
                case sf::Keyboard::Key::D:
                    players[0]->move(1);
                    break;
                case sf::Keyboard::Key::W:
                    players[0]->move(2);
                    break;
                case sf::Keyboard::Key::S:
                    players[0]->move(-2);
                    break;
            }
            if(players.size() == 2)
            {
                switch(e.key.code)
                {
                    case sf::Keyboard::Key::Left:
                        players[1]->move(-1);
                        break;
                    case sf::Keyboard::Key::Right:
                        players[1]->move(1);
                        break;
                    case sf::Keyboard::Key::Up:
                        players[1]->move(-2);
                        break;
                    case sf::Keyboard::Key::Down:
                        players[1]->move(2);
                        break;
                }
            }
        }
    }

    void Level::update()
    {
        for(int i = 0; i < players.size(); i++)
        {
            sf::RectangleShape* p = pRects[i];
            Entities::Player* player = players[i];
            p->setPosition(player->getPosition()->getX(), player->getPosition()->getY());
        }
    }

    void Level::render()
    {
        window->clear();
        for(int i = 0; i < players.size(); i++)
        {
            window->draw(*pRects[i]);
        }
    }
}
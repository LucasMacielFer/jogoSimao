#include "../../include/gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    Gerenciador_Eventos* Gerenciador_Eventos::pInstancia(NULL);

    Gerenciador_Eventos::Gerenciador_Eventos():
    pGGrafico(Gerenciador_Grafico::getInstancia()),
    jogador1(NULL),
    jogador2(NULL)
    {
    }

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        pGGrafico = NULL;
    }

    sf::Event Gerenciador_Eventos::recebeEvento()
    {
        sf::Event e;
        pGGrafico->getJanela().pollEvent(e);
        return e;
    }

    void Gerenciador_Eventos::processaEvento(sf::Event e)
    {
        if (e.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
        if (e.type == sf::Event::KeyReleased)
        {
            switch (e.key.code)
            {
                case sf::Keyboard::Key::A:
                case sf::Keyboard::Key::D:
                    if(jogador1)
                        jogador1->movimentaX(0);
                    break;
                case sf::Keyboard::Key::W:
                //case sf::Keyboard::Key::S:
                    if(jogador1)
                        jogador1->movimentaX(0);
                    break;
                case sf::Keyboard::Key::S:
                    if(jogador1)
                        jogador1->atacar();
                    break;
                case sf::Keyboard::Key::Left:
                case sf::Keyboard::Key::Right:
                    if (jogador2)
                        jogador2->movimentaX(0);
                    break;
                case sf::Keyboard::Key::Up:
                //case sf::Keyboard::Key::Down:
                    if (jogador2)
                        jogador2->movimentaX(0);
                    break;
                case sf::Keyboard::Key::Down:
                    if (jogador2)
                        jogador2->atacar();
                    break;
                default:
                    break;
            }
        }
        if(jogador1)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                jogador1->movimentaX(-1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                jogador1->movimentaX(1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                jogador1->pular();
            }
        }
        if(jogador2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                jogador2->movimentaX(-1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                jogador2->movimentaX(1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                jogador2->pular();
            }
        }
    }

    void Gerenciador_Eventos::executar()
    {
        sf::Event e;
        e = recebeEvento();
        processaEvento(e);
    }

    void Gerenciador_Eventos::setJogador1(Entidades::Personagens::Jogador* pJ)
    {
        jogador1 = pJ;
    }

    void Gerenciador_Eventos::setJogador2(Entidades::Personagens::Jogador* pJ)
    {
        jogador2 = pJ;        
    }

    // Execução efetiva do padrão de projeto singleton
    Gerenciador_Eventos* Gerenciador_Eventos::getInstancia()
    {
        if(!pInstancia)
        {
            pInstancia = new Gerenciador_Eventos();
        }
        return pInstancia;
    }
}
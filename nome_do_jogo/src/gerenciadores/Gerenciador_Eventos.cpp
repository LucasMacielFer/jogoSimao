#include "../../include/gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    Gerenciador_Eventos* Gerenciador_Eventos::pInstancia(NULL);

    Gerenciador_Eventos::Gerenciador_Eventos():
    pGGrafico(Gerenciador_Grafico::getInstancia()),
    personagem1(NULL),
    personagem2(NULL)
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
        if(e.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            personagem1->mover(-1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            personagem1->mover(1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            personagem1->mover(2);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            personagem1->mover(-2);
        }
        if(personagem2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                personagem2->mover(-1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                personagem2->mover(1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                personagem2->mover(2);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                personagem2->mover(-2);
            }
        }
    }

    void Gerenciador_Eventos::executar()
    {
        sf::Event e;
        e = recebeEvento();
        processaEvento(e);
    }

    void Gerenciador_Eventos::setPersonagem1(Entidades::Personagens::Personagem* pP)
    {
        personagem1 = pP;
    }

    void Gerenciador_Eventos::setPersonagem2(Entidades::Personagens::Personagem* pP)
    {
        personagem2 = pP;        
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
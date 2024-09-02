#include "../../include/gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    Gerenciador_Eventos* Gerenciador_Eventos::pInstancia(NULL);

    Gerenciador_Eventos::Gerenciador_Eventos():
    pGGrafico(Gerenciador_Grafico::getInstancia()),
    listaObs(),
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
        std::list<Observadores::Observador*>::iterator itr;

        if(e.type == sf::Event::Closed)
        {
            pGGrafico->fecharJanela();
        }

        else if(e.type == sf::Event::KeyReleased)
        {
            for(itr = listaObs.begin(); itr != listaObs.end(); itr++)
            {
                (*itr)->teclaSolta(e.key.code);
            }
        }

        for(itr = listaObs.begin(); itr != listaObs.end(); itr++)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::A);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::D);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::W);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::S);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Left);  
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Right);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Up);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Down);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Enter);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                (*itr)->teclaPressionada(sf::Keyboard::Key::Escape);
            }
        }
    }

    void Gerenciador_Eventos::executar()
    {
        sf::Event e;
        e = recebeEvento();
        processaEvento(e);
    }

    void Gerenciador_Eventos::adicionarObservador(Observadores::Observador* pObs)
    {
        if(pObs)
        {
            listaObs.push_back(pObs);
        }
    }

    void Gerenciador_Eventos::removerObservador(Observadores::Observador* pObs)
    {
        std::list<Observadores::Observador*>::iterator itr;
        itr = std::find(listaObs.begin(), listaObs.end(), pObs);

        if(itr != listaObs.end())
        {
            listaObs.erase(itr);
        }
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
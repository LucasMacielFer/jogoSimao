#include "../../include/gerenciadores/GerenciadorEventos.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    GerenciadorEventos* GerenciadorEventos::pInstancia(NULL);

    GerenciadorEventos::GerenciadorEventos():
    pGGrafico(GerenciadorGrafico::getInstancia()),
    listaObs(),
    jogador1(NULL),
    jogador2(NULL)
    {
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
        pGGrafico = NULL;
    }

    sf::Event GerenciadorEventos::recebeEvento()
    {
        sf::Event e;
        pGGrafico->getJanela().pollEvent(e);
        return e;
    }

    void GerenciadorEventos::processaEvento(sf::Event e)
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
                if((*itr)->getAtivar())
                    (*itr)->teclaSolta(e.key.code);
            }
        }

        for(itr = listaObs.begin(); itr != listaObs.end(); itr++)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::A);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::D);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::W);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::S);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Left);  
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Right);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Up);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Down);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Enter);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                if((*itr)->getAtivar())
                    (*itr)->teclaPressionada(sf::Keyboard::Key::Escape);
            }
        }
    }

    void GerenciadorEventos::executar()
    {
        sf::Event e;
        e = recebeEvento();
        processaEvento(e);
    }

    void GerenciadorEventos::adicionarObservador(Observadores::Observador* pObs)
    {
        if(pObs)
        {
            listaObs.push_back(pObs);
        }
    }

    void GerenciadorEventos::removerObservador(Observadores::Observador* pObs)
    {
        std::list<Observadores::Observador*>::iterator itr;
        itr = std::find(listaObs.begin(), listaObs.end(), pObs);

        if(itr != listaObs.end())
        {
            listaObs.erase(itr);
        }
    }

    void GerenciadorEventos::setJogador1(Entidades::Personagens::Jogador* pJ)
    {
        jogador1 = pJ;
    }

    void GerenciadorEventos::setJogador2(Entidades::Personagens::Jogador* pJ)
    {
        jogador2 = pJ;        
    }

    // Execução efetiva do padrão de projeto singleton
    GerenciadorEventos* GerenciadorEventos::getInstancia()
    {
        if(!pInstancia)
        {
            pInstancia = new GerenciadorEventos();
        }
        return pInstancia;
    }
}
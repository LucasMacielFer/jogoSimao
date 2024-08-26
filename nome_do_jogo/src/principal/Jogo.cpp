#include "../../include/principal/Jogo.h"
#include "SFML/Graphics/Color.hpp"
#include "entidades/personagens/Esqueleto.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    p1(new Entidades::Personagens::Jogador("assets/textures/jogador.png", 50, 100)),
    p2(new Entidades::Personagens::Jogador("assets/textures/jogador.png", 50, 100)),
    inim(new Entidades::Personagens::Esqueleto("assets/textures/esqueleto.png", 500, 100)),
    fase1(new Fases::Fase("assets/maps/teste.json", 0, 0, 0, 0, 0, 0)),
    relogio(),
    tempo(0.0f)
    {
        time_t t;
        srand((unsigned)time(&t));
        gEventos->setJogador1(p1);
        gEventos->setJogador2(p2);
        gColisoes->setJog1(p1);
        gColisoes->setJog2(p2);
        gColisoes->incluirInimigo(inim);
        fase1->setJogador1(p1);
        fase1->setJogador2(p2);
        inim->setJogador1(p1);
        inim->setJogador2(p2);
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
        delete p1;
        delete p2;
        delete inim;
    }

    void Jogo::executar()
    {
        bool inicio = true;
        while(gGrafico->janelaAberta())
        {
            gGrafico->limparJanela();
            gEventos->executar();
            gColisoes->executar();

            tempo = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            fase1->executar(tempo);
            inim->executar(tempo);
            
            //gGrafico->getJanela().draw(retangulo);
            gGrafico->desenhaEnte(static_cast<Ente*>(fase1));
            gGrafico->desenhaEnte(static_cast<Ente*>(inim));
            if(inim->getFlecha())
            {
                if(inicio)
                {
                    gColisoes->incluirInimigo(inim->getFlecha());
                    inicio = false;
                }
                
                gGrafico->desenhaEnte(static_cast<Ente*> (inim->getFlecha()));

                if(!((inim->getFlecha())->getAtivo()))
                {
                    gColisoes->removerInimigo();
                    inicio = true;
                }
            }
            gGrafico->mostrarJanela();
        }
    }
}
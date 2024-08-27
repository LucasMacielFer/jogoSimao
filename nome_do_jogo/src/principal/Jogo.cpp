#include "../../include/principal/Jogo.h"
//#include "SFML/Graphics/Color.hpp"
//#include "entidades/personagens/Esqueleto.h"
//#include "entidades/personagens/Mago.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    p1(new Entidades::Personagens::Jogador("assets/textures/jogador1.png", 43, 60)),
    //p1(NULL),
    //p2(NULL),
    p2(new Entidades::Personagens::Jogador("assets/textures/jogador2.png", 43, 60)),
    //inim(new Entidades::Personagens::Esqueleto("assets/textures/esqueleto.png", 500, 100)),
    //inim(new Entidades::Personagens::Mago("assets/textures/esqueleto.png", 500, 100)),
    fase1(new Fases::FasePrimeira()),
    relogio(),
    tempo(0.0f)
    {
        time_t t;
        srand((unsigned)time(&t));
        gEventos->setJogador1(p1);
        gEventos->setJogador2(p2);
        gColisoes->setJog1(p1);
        gColisoes->setJog2(p2);
        //gColisoes->incluirInimigo(inim);
        fase1->setJogador1(p1);
        fase1->setJogador2(p2);
        //inim->setJogador1(p1);
        //inim->setJogador2(p2);
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
        delete p1;
        delete p2;
        //delete inim;
    }

    void Jogo::executar()
    {
        //bool inicio = true;
        while(gGrafico->janelaAberta())
        {
            if(p1)
            {
                if(!p1->getVivo())
                {
                    fase1->setJogador1(NULL);
                    gEventos->setJogador1(NULL);
                    gColisoes->setJog1(NULL);
                    //inim->setJogador1(NULL);
                    delete p1;
                    p1 = NULL;
                }
            }

            if(p2)
            {
                if(!p2->getVivo())
                {
                    fase1->setJogador2(NULL);
                    gEventos->setJogador2(NULL);
                    gColisoes->setJog2(NULL);
                    //inim->setJogador2(NULL);
                    delete p2;
                    p2 = NULL;
                }
            }

            if(!p1 && !p2)
            {
                std::cout<<"GAME OVER!!!" << std::endl;
                exit(1);
            }
            gGrafico->limparJanela();
            gEventos->executar();
            gColisoes->executar();

            tempo = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            fase1->executar(tempo);
            //inim->executar(tempo);
            
            //gGrafico->getJanela().draw(retangulo);
            gGrafico->desenhaEnte(static_cast<Ente*>(fase1));
            /*
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
            */
            
            /*gGrafico->desenhaEnte(static_cast<Ente*>(inim));
            if(inim->getFogo())
            {
                if(inicio)
                {
                    gColisoes->incluirInimigo(inim->getFogo());
                    inicio = false;
                }
                
                gGrafico->desenhaEnte(static_cast<Ente*> (inim->getFogo()));

                if(!((inim->getFogo())->getAtivo()))
                {
                    gColisoes->removerInimigo();
                    inicio = true;
                }
            }*/
            
            gGrafico->mostrarJanela();
        }
    }
}
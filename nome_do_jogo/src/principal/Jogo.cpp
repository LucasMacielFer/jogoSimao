#include "../../include/principal/Jogo.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    p1(new Entidades::Personagens::Jogador()),
    p2(new Entidades::Personagens::Jogador()),
    plat(new Entidades::Obstaculos::Plataforma("", 1000, 100, 500, 750)),
    relogio(),
    tempo(0.0f)
    {
        gEventos->setJogador1(p1);
        gEventos->setJogador2(p2);
        gColisoes->setJog1(p1);
        gColisoes->setJog2(p2);
        gColisoes->incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(plat));
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
        delete p1;
        delete p2;  
        delete plat;
    }

    void Jogo::executar()
    {
        while(gGrafico->janelaAberta())
        {
            gGrafico->limparJanela();
            gEventos->executar();
            gColisoes->executar();

            tempo = relogio.getElapsedTime().asSeconds();
            relogio.restart();

            plat->executar(tempo);
            p1->executar(tempo);
            p2->executar(tempo);
            
            //gGrafico->getJanela().draw(retangulo);
            gGrafico->desenhaEnte(static_cast<Ente*>(p1));
            gGrafico->desenhaEnte(static_cast<Ente*>(p2));
            gGrafico->desenhaEnte(static_cast<Ente*>(plat));
            gGrafico->mostrarJanela();
        }
    }
}
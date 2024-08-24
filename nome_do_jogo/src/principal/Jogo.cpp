#include "../../include/principal/Jogo.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    p1(new Entidades::Personagens::Jogador(sf::Color::Blue, 50, 700)),
    p2(new Entidades::Personagens::Jogador(sf::Color::Cyan, 50, 100)),
    fase1(new Fases::Fase("../assets/maps/teste.json", 0, 0, 0, 0, 0, 0)),
    relogio(),
    tempo(0.0f)
    {
        time_t t;
        srand((unsigned)time(&t));
        gEventos->setJogador1(p1);
        gEventos->setJogador2(p2);
        gColisoes->setJog1(p1);
        gColisoes->setJog2(p2);
        fase1->setJogador1(p1);
        fase1->setJogador2(p2);
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
        delete p1;
        delete p2;  
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
            fase1->executar(tempo);
            
            //gGrafico->getJanela().draw(retangulo);
            gGrafico->desenhaEnte(static_cast<Ente*>(fase1));
            gGrafico->mostrarJanela();
        }
    }
}
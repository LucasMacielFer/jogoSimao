#include "../../include/principal/Jogo.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    fase1(new Estados::Fases::FasePrimeira(2)),
    relogio(),
    tempo(0.0f)
    {
        time_t t;
        srand((unsigned)time(&t));
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
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
            gGrafico->desenhaEnte(static_cast<Ente*>(fase1));
            gGrafico->mostrarJanela();
        }
    }
}
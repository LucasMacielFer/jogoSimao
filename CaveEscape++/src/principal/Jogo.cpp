#include "../../include/principal/Jogo.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::GerenciadorEventos::getInstancia()),
    gGrafico(Gerenciadores::GerenciadorGrafico::getInstancia()),
    gEstados(Estados::GerenciadorEstados::getInstancia()),
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
        delete gEstados;
    }

    void Jogo::executar()
    {
        bool inicio = true;
        while(gGrafico->janelaAberta())
        {
            gGrafico->limparJanela();
            gEventos->executar();
            tempo = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            gEstados->executar(tempo);
            gGrafico->desenhaEnte(static_cast<Ente*>(gEstados->getEnteAtual()));
            gGrafico->mostrarJanela();
        }
    }
}
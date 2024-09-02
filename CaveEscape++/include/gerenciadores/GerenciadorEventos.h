#pragma once

#include <list>
#include "GerenciadorGrafico.h"
#include "../entidades/personagens/Jogador.h"
#include "../observadores/Observador.h"

namespace Gerenciadores
{
    class GerenciadorEventos
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static GerenciadorEventos* pInstancia;
        GerenciadorGrafico* pGGrafico;
        std::list<Observadores::Observador*> listaObs;
        Entidades::Personagens::Jogador* jogador1;
        Entidades::Personagens::Jogador* jogador2;
    
    private:
        // Construtora privada, em conformidade com o padrão de projeto Singleton
        GerenciadorEventos();
        sf::Event recebeEvento();
        void processaEvento(sf::Event e);

    public:
        ~GerenciadorEventos();
        void adicionarObservador(Observadores::Observador* pObs);
        void removerObservador(Observadores::Observador* pObs);
        void executar();
        void setJogador1(Entidades::Personagens::Jogador* pJ);
        void setJogador2(Entidades::Personagens::Jogador* pJ);
        static GerenciadorEventos* getInstancia();
    };
}
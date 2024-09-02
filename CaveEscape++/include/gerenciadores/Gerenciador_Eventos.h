#pragma once

#include <list>
#include "Gerenciador_Grafico.h"
#include "../entidades/personagens/Jogador.h"
#include "../observadores/Observador.h"

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static Gerenciador_Eventos* pInstancia;
        Gerenciador_Grafico* pGGrafico;
        std::list<Observadores::Observador*> listaObs;
        Entidades::Personagens::Jogador* jogador1;
        Entidades::Personagens::Jogador* jogador2;
    
    private:
        // Construtora privada, em conformidade com o padrão de projeto Singleton
        Gerenciador_Eventos();
        sf::Event recebeEvento();
        void processaEvento(sf::Event e);

    public:
        ~Gerenciador_Eventos();
        void adicionarObservador(Observadores::Observador* pObs);
        void removerObservador(Observadores::Observador* pObs);
        void executar();
        void setJogador1(Entidades::Personagens::Jogador* pJ);
        void setJogador2(Entidades::Personagens::Jogador* pJ);
        static Gerenciador_Eventos* getInstancia();
    };
}
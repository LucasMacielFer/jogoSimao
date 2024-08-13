#pragma once

#include "Gerenciador_Grafico.h"
#include "../entidades/personagens/Personagem.h"

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static Gerenciador_Eventos* pInstancia;
        Gerenciador_Grafico* pGGrafico;
        Entidades::Personagens::Personagem* personagem1;
        Entidades::Personagens::Personagem* personagem2;
    
    private:
        // Construtora privada, em conformidade com o padrão de projeto Singleton
        Gerenciador_Eventos();
        sf::Event recebeEvento();
        void processaEvento(sf::Event e);

    public:
        ~Gerenciador_Eventos();
        void executar();
        void setPersonagem1(Entidades::Personagens::Personagem* pP);
        void setPersonagem2(Entidades::Personagens::Personagem* pP);
        static Gerenciador_Eventos* getInstancia();
    };
}
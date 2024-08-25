#pragma once

#include "../gerenciadores/Gerenciador_Eventos.h"
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../fases/Fase.h"
#include "entidades/personagens/Esqueleto.h"


#define TICKRATE 0.017

namespace Principal
{
    class Jogo
    {
        private:
            Gerenciadores::Gerenciador_Eventos* gEventos;
            Gerenciadores::Gerenciador_Colisoes* gColisoes;
            Gerenciadores::Gerenciador_Grafico* gGrafico;

            // Aqui estará a lista de entidades!
            Entidades::Personagens::Jogador* p1;
            Entidades::Personagens::Jogador* p2;
            Entidades::Personagens::Esqueleto* inim;
            Fases::Fase* fase1;

            // Todo o gerenciamento de tempo foi feito baseado no jogo Desert++, do monitor Matheus Burda
            // Disponível em: https://github.com/MatheusBurda/Desert/tree/4d1ec28610a4675cfa3defc2a1aac12f28ffad2b
            sf::Clock relogio;
            float tempo;
            
        public:
            Jogo();
            ~Jogo();
            void executar();
    };
}
#pragma once

#include "../gerenciadores/GerenciadorEventos.h"
#include "../gerenciadores/GerenciadorColisoes.h"
#include "../estados/GerenciadorEstados.h"

#define TICKRATE 0.017

namespace Principal
{
    class Jogo
    {
        private:
            Gerenciadores::GerenciadorEventos* gEventos;
            Gerenciadores::GerenciadorGrafico* gGrafico;
            Estados::GerenciadorEstados* gEstados;

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
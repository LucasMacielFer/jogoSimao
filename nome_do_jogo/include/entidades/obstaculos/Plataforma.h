#pragma once
#include "Obstaculo.h"

#define TAM_PLAT_X 64.0
#define TAM_PLAT_Y 32.0

namespace Entidades
{ 
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
            const bool chao;
            
        public:            
            Plataforma(const float xx, const float yy, const bool ehChao);
            Plataforma(const char* c, const float xx, const float yy, const bool ehChao);
            Plataforma();
            ~Plataforma();
            void salvar();
            void executar(float dt);
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void obstacular(Personagens::Personagem* p);
        };
    }
}
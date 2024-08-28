#pragma once
#include "Obstaculo.h"

#define TAM_PLAT_X 64.0
#define TAM_PLAT_Y 32.0
#define SUSTMAX 999999.0
#define SUSTENTACAO 30.0

namespace Entidades
{ 
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
            const bool chao;
            float sustentacao;
            
        public:            
            Plataforma(const char* txt, const float xx, const float yy, const bool ehChao);
            Plataforma();
            ~Plataforma();
            void salvar();
            void executar(float dt);
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void obstacular(Personagens::Personagem* p);
        };
    }
}
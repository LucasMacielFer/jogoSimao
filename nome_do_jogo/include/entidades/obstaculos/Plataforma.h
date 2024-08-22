#pragma once
#include "Obstaculo.h"

namespace Entidades
{ 
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        public:            
            Plataforma(const float tamXX, const float tamYY, const float xx, const float yy);
            Plataforma(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy);
            Plataforma();
            ~Plataforma();
            void salvar();
            void executar(float dt);
            void obstacular(Personagens::Jogador* p);
        };
    }
}
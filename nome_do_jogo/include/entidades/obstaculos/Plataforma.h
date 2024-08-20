#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
            float forcaSustentacao;

        public:            
            Plataforma(std::string txt="", const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
            ~Plataforma();
            void salvar();
            void executar();
            void obstacular(Personagens::Jogador* p);
        };
    }
}
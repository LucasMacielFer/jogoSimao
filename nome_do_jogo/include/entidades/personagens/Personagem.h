#pragma once

#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem : public Entidade
        {
        protected:
            int vidas;
            int velocidade;
            bool ataque;

        public:
            Personagem(const float vd = 10.0f, const float vel = 10.0f, const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
            virtual ~Personagem();
            void mover(int dir);
            const int getVidas() const;
            void setVidas(const int v);
            void operator++();
            void operator--();

            // Devem ser virtuais puras
            virtual void executar();
            virtual void salvar();
        };
    }
}
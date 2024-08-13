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

        public:
            Personagem(const int vd = 10, const int vel = 10, const int tamXX=10, const int tamYY=10, const int xx=0, const int yy=0);
            virtual ~Personagem();
            void mover(int dir);
            const int getVidas() const;
            void setVidas(const int v);
            void operator++();
            void operator--();

            // Devem ser virtuais puras
            void executar();
            void salvar();
        };
    }
}
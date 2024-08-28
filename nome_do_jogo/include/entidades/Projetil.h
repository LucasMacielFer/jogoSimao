#pragma once

#include "Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo;
    }

    class Projetil : public Entidade
    {
        private:
            static const int idClasse;
            Personagens::Inimigo* atirador;
            bool ativo;
            int dano;

        public:
            Projetil(Personagens::Inimigo* at, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel);
            Projetil();
            ~Projetil();
            const bool getAtivo() const;
            Personagens::Inimigo* getAtirador() const;
            void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void executar(float dt);
            void salvar();
            void sumir();
    };
}
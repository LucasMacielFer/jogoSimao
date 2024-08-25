#pragma once

#include "Inimigo.h"
#include "../Projetil.h"
#include "entidades/personagens/Personagem.h"
#include <cmath>

#define TAM_X_ESQUELETO 30
#define TAM_Y_ESQUELETO 100
#define VIDAS_ESQUELETO 30
#define VEL_MAX_ESQUELETO 3.0f
#define FORCA_ESQUELETO 10
#define DURACAO_ATAQUE_ESQUELETO 1.0f
#define DURACAO_ESPERA_ESQUELETO 2.0f
#define ALCANCE_ESQUELETO 200.0f
//#define TAMANHO_FLECHA_X
//#define TAMANHO_FLECHA_Y
//#define VELOCIDADE_FLECHA


namespace Entidades
{
    namespace Personagens
    {
        class Esqueleto : public Inimigo
        {
            private:

            Projetil* flecha;

            public:

            Esqueleto(sf::Color c, const float xx, const float yy);
            Esqueleto();
            ~Esqueleto();
            void salvar();
            void atacarCorpo(Personagem* pPersonagem);
            void atacarDist(float posJogador);
            void habilidadeInimiga();

        };
    }
}
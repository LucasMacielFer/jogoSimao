#pragma once

#include "Inimigo.h"
#include "../Projetil.h"
#include <cmath>

#define TAM_X_MAGO 100
#define TAM_Y_MAGO 100
#define VIDAS_MAGO 30
#define VEL_MAX_MAGO 4.0f
#define FORCA_MAGO 10
#define DURACAO_ATAQUE_MAGO 1.0f
#define DURACAO_ESPERA_MAGO 2.0f
#define ESPERA_TELEPORTE_MAGO 5.0f
#define ALCANCE_MAGO 200.0f
#define TAMANHO_FOGO_X 25
#define TAMANHO_FOGO_Y 25
#define VELOCIDADE_FOGO 20.0f

namespace Entidades
{
    namespace Personagens
    {
        class Mago : public Inimigo
        {
            private:

            Projetil* fogo;
            float esperaTeleporte;
            bool bolaDeFogoTratada;

            public:

            //Mago(const char* txt, const float xx, const float yy);
            Mago();
            ~Mago();
            //Projetil* getFogo();
            //const bool getBFTratada() const;
            //void setBFTratada(const bool bf);
            //void salvar();
            //void atacarCorpo(Personagem* pPersonagem);
            //void atacarDist(float posJogador);
            //void habilidadeInimiga(float dt);
        };
    }
}
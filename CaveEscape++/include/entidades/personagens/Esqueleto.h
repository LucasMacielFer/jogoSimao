#pragma once

#include "Inimigo.h"
#include "../Projetil.h"
#include "entidades/personagens/Personagem.h"
#include <cmath>

#define TAM_X_ESQUELETO 43
#define TAM_Y_ESQUELETO 60
#define VIDAS_ESQUELETO 30
#define VEL_MAX_ESQUELETO 3.0f
#define FORCA_ESQUELETO 1
#define DURACAO_ATAQUE_ESQUELETO 1.0f
#define DURACAO_ESPERA_ESQUELETO 2.0f
#define ALCANCE_ESQUELETO 200.0f
#define TAMANHO_FLECHA_X 30
#define TAMANHO_FLECHA_Y 3
#define CAMINHO_FLECHA "assets/textures/flecha.png"
#define VELOCIDADE_FLECHA 10.0f

namespace Fases
{
    class Fase;
}

namespace Entidades
{
    namespace Personagens
    {
        class Esqueleto : public Inimigo
        {
            private:
            Fases::Fase* faseAgregado;
            Projetil* flecha;

            public:

            Esqueleto(const char* txt, const float xx, const float yy);
            Esqueleto();
            ~Esqueleto();
            Projetil* getFlecha();
            void setFlecha(Projetil* p);
            void setFase(Fases::Fase* f);
            void salvar();
            void danificar(Jogador* pJogador);
            void atacarDist(float posJogador);
            void habilidadeInimiga(float dt);
        };
    }
}
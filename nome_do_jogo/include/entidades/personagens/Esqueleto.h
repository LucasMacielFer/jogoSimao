#pragma once

#include "Inimigo.h"

#define TAM_X_ESQUELETO 30
#define TAM_Y_ESQUELETO 100
#define VIDAS_ESQUELETO 30
#define VEL_MAX_ESQUELETO 3.0f
#define FORCA_ESQUELETO 10
#define DURACAO_ATAQUE_ESQUELETO 1.0f
#define DURACAO_ESPERA_ESQUELETO 2.0f

namespace Entidades
{
    namespace Personagens
    {
        class Esqueleto : public Inimigo
        {

        };
    }
}
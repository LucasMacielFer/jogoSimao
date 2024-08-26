#include "../../include/fases/FasePrimeira.h"

namespace Fases
{
    void FasePrimeira::aleatorizaOcorrencias()
    {
        int i;
        for(i=0; i< NUM_PLATAFORMAS_F1; i++)
        {
            plataformas[i] = rand()%2 == 1 ? true : false;
        }

        // Garantindo que as plataformas que podem conter espinhos sejam sempre geradas
        plataformas[1] = true;
        plataformas[2] = true;
        plataformas[3] = true;
        plataformas[5] = true;

        for(i=0; i< NUM_GOSMAS_F1; i++)
        {
            gosmas[i] = rand()%2 == 1 ? true : false;
        }

        // Garantindo que ao menos duas gosmas sejam geradas
        gosmas[0] = true;
        gosmas[NUM_GOSMAS_F1-1] = true;
        
        for(i=0; i< NUM_ESPINHOS_F1; i++)
        {
            espinhos[i] = rand()%2 == 1 ? true : false;
        }

        // Garantindo que ao menos dois espinhos sejam gerados
        espinhos[0] = true;
        espinhos[NUM_ESPINHOS_F1-1] = true;

        for(i=0; i< NUM_LOBISOMENS_F1; i++)
        {
            lobisomens[i] = rand()%2 == 1 ? true : false;
        }

        // Garantindo que ao menos dois lobisomens sejam gerados
        lobisomens[0] = true;
        lobisomens[NUM_LOBISOMENS_F1-1] = true;

        for(i=0; i< NUM_ESQUELETOS_F1; i++)
        {
            esqueletos[i] = rand()%2 == 1 ? true : false;
        }

        // Garantindo que ao menos dois esqueletos sejam gerados
        esqueletos[0] = true;
        esqueletos[NUM_ESQUELETOS_F1-1] = true;
    }

    FasePrimeira::FasePrimeira():
    Fase(TILEMAP_F1)
    {
        aleatorizaOcorrencias();
        criarMapa();
        inicializaColisoes();
    }

    FasePrimeira::~FasePrimeira()
    {
    }

    void FasePrimeira::criarMapa()
    {
        CriadorMapas* gerador = new CriadorMapas(caminhoTilemap);
        if(gerador)
        {
            tamMapa = gerador->criarMapa(&lEntidades, plataformas, gosmas, espinhos, lobisomens, esqueletos);
            delete gerador;
            gerador = NULL;
        }
    }
}
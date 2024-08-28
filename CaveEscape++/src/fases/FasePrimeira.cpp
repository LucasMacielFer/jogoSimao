#include "../../include/fases/FasePrimeira.h"

namespace Fases
{
    FasePrimeira::FasePrimeira():
    Fase(TILEMAP_F1)
    {
        criarMapa();
        inicializaColisoes();
    }

    FasePrimeira::~FasePrimeira()
    {
    }

    void FasePrimeira::criarLobisomens(bool* lobs, const int max)
    {
        aleatorizaOcorrencias(lobs, max);
        criadorDeMapas->criarTipo(&lEntidades, CODIGO_LOBISOMEM, lobs, max);
    }

    void FasePrimeira::criarGosmas(bool* gosmas, const int max)
    {
        aleatorizaOcorrencias(gosmas, max);
        criadorDeMapas->criarTipoGrande(&lEntidades, CODIGO_GOSMA, gosmas, max);
    }

    void FasePrimeira::criarMapa()
    {
        criarChao();
        criarGosmas(gosmas, NUM_GOSMAS_F1);
        criarPlataformas(plataformas, NUM_PLATAFORMAS_F1);
        criarEsqueletos(esqueletos, NUM_ESQUELETOS_F1);
        criarLobisomens(lobisomens, NUM_LOBISOMENS_F1);
        tamMapa = criadorDeMapas->getTamMapa();
    }

    void FasePrimeira::salvar()
    {
    }
}
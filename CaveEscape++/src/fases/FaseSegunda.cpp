#include "../../include/fases/FaseSegunda.h"

namespace Fases
{
    FaseSegunda::FaseSegunda():
    Fase(TILEMAP_F2)
    {
        criarMapa();
        inicializaColisoes();
    }

    FaseSegunda::~FaseSegunda()
    {
    }

    void FaseSegunda::criarMagos(bool* magos, const int max)
    {
        aleatorizaOcorrencias(magos, max);
        criadorDeMapas->criarTipo(&lEntidades, CODIGO_MAGO, magos, max);
    }

    void FaseSegunda::criarEspinhos(bool* espinhos, const int max)
    {
        aleatorizaOcorrencias(espinhos, max);
        criadorDeMapas->criarTipo(&lEntidades, CODIGO_ESPINHO, espinhos, max);
    }

    void FaseSegunda::criarMapa()
    {
        criarChao();
        criarEspinhos(espinhos, NUM_ESPINHOS_F2);
        criarPlataformas(plataformas, NUM_PLATAFORMAS_F2);
        criarEsqueletos(esqueletos, NUM_ESQUELETOS_F2);
        criarMagos(magos, NUM_MAGOS_F2);
        tamMapa = criadorDeMapas->getTamMapa();
    }

    void FaseSegunda::salvar()
    {
    }
}
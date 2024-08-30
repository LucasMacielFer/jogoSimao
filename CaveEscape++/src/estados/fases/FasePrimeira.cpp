#include "../../../include/estados/fases/FasePrimeira.h"

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(const int numJogs):
        Fase(TILEMAP_F1, idEstados::Jogando1, numJogs)
        {
            criarMapa();
            inicializaColisoes();
            criarJogadores(numJogs);
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

        void FasePrimeira::vencer()
        {
            pGColisoes->limparListas();
            modificarEstado(idEstados::Jogando2);
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

        void FasePrimeira::salvarJogada(const char* caminhoSalvamento)
        {
            std::ofstream gravador(caminhoSalvamento, std::ios::out);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar primeira fase"<<std::endl;
            }
            else
            {
                gravador << "1" << std::endl;
            }
            gravador.close();

            Fase::salvarJogada(caminhoSalvamento);
        }
    }
}
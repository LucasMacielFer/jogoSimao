#include "../../../include/estados/fases/FaseSegunda.h"
#include "../../../include/estados/menus/MenuPausa.h"

namespace Estados
{
    namespace Fases
    {
        FaseSegunda::FaseSegunda(const int numJogs):
        Fase(TILEMAP_F2, idEstados::Jogando2, numJogs)
        {
            criarMapa();
            inicializaColisoes();
            criarJogadores(numJogs);

            if(numJogs >= 1)
                jog1->operator=(pontJ1);
            if(numJogs == 2)
                jog2->operator=(pontJ2);
        }

        FaseSegunda::~FaseSegunda()
        {
        }

        void FaseSegunda::criarPlataformas(bool* plats, const int max)
        {
            aleatorizaOcorrencias(plats, max);
            // Plataformas que podem receber espinhos são sempre criadas!
            plats[3] = true;
            plats[6] = true;
            plats[7] = true;
            criadorDeMapas->criarTipoGrande(&lEntidades, CODIGO_PLATAFORMA, plats, max);
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

        void FaseSegunda::vencer()
        {
            pGGrafico->moveCamera(pGGrafico->getTamJanela().x/2.0f);
            modificarEstado(idEstados::Vitoria);
        }

        void FaseSegunda::criarMapa()
        {
            criarEspinhos(espinhos, NUM_ESPINHOS_F2);
            criarChao();
            criarPlataformas(plataformas, NUM_PLATAFORMAS_F2);
            criarEsqueletos(esqueletos, NUM_ESQUELETOS_F2);
            criarMagos(magos, NUM_MAGOS_F2);
            tamMapa = criadorDeMapas->getTamMapa();
        }

        void FaseSegunda::salvarJogada(const char* caminhoSalvamento)
        {
            std::ofstream gravador(caminhoSalvamento, std::ios::out);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar segunda fase"<<std::endl;
            }
            else
            {
                gravador << "2" << std::endl;
            }
            gravador.close();

            Fase::salvarJogada(caminhoSalvamento);
        }

        void FaseSegunda::pausar()
        {
            Menus::MenuPausa::setFase(idEstados::Jogando2);
            Fase::pausar();
        }
    }
}
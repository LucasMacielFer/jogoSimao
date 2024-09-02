#include "Fase.h"

#define NUM_PLATAFORMAS_F2 8
#define NUM_ESPINHOS_F2 19
#define NUM_MAGOS_F2 5
#define NUM_ESQUELETOS_F2 5
#define TILEMAP_F2 "assets/maps/FaseSegunda.json"

namespace Estados
{
    namespace Fases
    {
        class FaseSegunda : public Fase
        {
            private:
                bool plataformas[NUM_PLATAFORMAS_F2];
                bool espinhos[NUM_ESPINHOS_F2];
                bool magos[NUM_MAGOS_F2];
                bool esqueletos[NUM_ESQUELETOS_F2];
            
            private:
                void criarPlataformas(bool* plats, const int max);
                void criarMagos(bool* magos, const int max);
                void criarEspinhos(bool* espinhos, const int max);
                void vencer();

            public:
                FaseSegunda(const int numJogs);
                ~FaseSegunda();
                void criarMapa();
                void salvarJogada(const char* caminhoSalvamento);
                void pausar();
        };
    }
}
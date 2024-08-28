#include "Fase.h"

#define NUM_PLATAFORMAS_F2 10
#define NUM_ESPINHOS_F2 7
#define NUM_MAGOS_F2 4
#define NUM_ESQUELETOS_F2 6
#define TILEMAP_F2 "assets/maps/faseSegunda.json"

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
            void criarMagos(bool* magos, const int max);
            void criarEspinhos(bool* espinhos, const int max);

        public:
            FaseSegunda();
            ~FaseSegunda();
            void criarMapa();
            void salvar();
    };
}
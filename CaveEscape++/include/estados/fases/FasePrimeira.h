#include "Fase.h"

#define NUM_PLATAFORMAS_F1 7
#define NUM_GOSMAS_F1 5
#define NUM_LOBISOMENS_F1 4
#define NUM_ESQUELETOS_F1 6
#define TILEMAP_F1 "assets/maps/FasePrimeira.json"

namespace Estados
{
    namespace Fases
    {
        class FasePrimeira : public Fase
        {
            private:
                bool plataformas[NUM_PLATAFORMAS_F1];
                bool gosmas[NUM_GOSMAS_F1];
                bool lobisomens[NUM_LOBISOMENS_F1];
                bool esqueletos[NUM_ESQUELETOS_F1];
            
            private:
                void criarLobisomens(bool* lobs, const int max);
                void criarGosmas(bool* gosmas, const int max);

            public:
                FasePrimeira(const int numJogs);
                ~FasePrimeira();
                void criarMapa();
                void salvar();
        };
    }
}
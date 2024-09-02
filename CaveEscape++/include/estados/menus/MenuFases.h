#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuFases : public Menu
        {   
            private:
                int numJogs;

            public:
                MenuFases();
                ~MenuFases();
                void selecionar();
                void criarBotoes();
        };
    }
}
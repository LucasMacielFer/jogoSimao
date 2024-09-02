#include "Menu.h"
#include <string>

namespace Estados
{
    namespace Menus
    {
        class MenuDerrota : public Menu
        {
            private:
                Texto::ElementoTexto* pontuacaoDerrota;

            public:
                MenuDerrota();
                ~MenuDerrota();
                void selecionar();
                void criarBotoes();
                virtual void desenhar(sf::RenderWindow& janela);
        };
    }
}
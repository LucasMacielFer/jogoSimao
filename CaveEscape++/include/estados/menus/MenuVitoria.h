#include "Menu.h"
#include <string>

namespace Estados
{
    namespace Menus
    {
        class MenuVitoria : public Menu
        {
            private:
                Texto::ElementoTexto* pontuacaoVitoria;

            public:
                MenuVitoria();
                ~MenuVitoria();
                void selecionar();
                void criarBotoes();
                virtual void desenhar(sf::RenderWindow& janela);
        };
    }
}
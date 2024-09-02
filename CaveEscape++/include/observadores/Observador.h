#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace Estados
{
    class GerenciadorEstados;
}

namespace Gerenciadores
{
    class Gerenciador_Eventos;
}

namespace Observadores
{
    // Classe baseada no código do monitor Giovane. GitHub: https://github.com/Giovanenero/JogoPlataforma2D-Jungle.git. Acesso em: 30/08/2024.
    class Observador
    {
        protected:
            static Gerenciadores::Gerenciador_Eventos* pGEventos;
            static Estados::GerenciadorEstados* pGEstados;
            std::map<sf::Keyboard::Key, char> teclado;
            std::map<sf::Keyboard::Key, std::string> tecladoEspecial;

        private:
            bool ativar;

        private:
            void inicializarTeclado();
        
        public:
            Observador(Gerenciadores::Gerenciador_Eventos* pGEv);
            virtual ~Observador();
            const bool getAtivar() const;
            void setAtivo(const bool at);
            void removerObservador();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
    };
}
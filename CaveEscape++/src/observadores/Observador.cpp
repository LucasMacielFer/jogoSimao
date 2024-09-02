#include "../../include/observadores/Observador.h"
#include "../../include/gerenciadores/GerenciadorEventos.h"
#include "../../include/estados/GerenciadorEstados.h"

namespace Observadores
{
    Gerenciadores::GerenciadorEventos* Observador::pGEventos(Gerenciadores::GerenciadorEventos::getInstancia());
    Estados::GerenciadorEstados* Observador::pGEstados(Estados::GerenciadorEstados::getInstancia());

    void Observador::inicializarTeclado()
    {
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num0, '0'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num1, '1'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num2, '2'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num3, '3'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num4, '4'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num5, '5'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num6, '6'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num7, '7'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num8, '8'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num9, '9'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::A, 'a'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::B, 'b'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::C, 'c'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::D, 'd'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::E, 'e'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::F, 'f'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::G, 'g'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::H, 'h'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::I, 'i'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::J, 'j'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::K, 'k'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::L, 'l'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::M, 'm'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::N, 'n'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::O, 'o'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::P, 'p'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Q, 'q'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::R, 'r'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::S, 's'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::T, 't'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::U, 'u'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::V, 'v'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::X, 'x'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::W, 'w'));
        teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Z, 'z'));

        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Enter, "Enter"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::BackSpace, "BackSpace"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Escape, "Escape"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Delete, "Delete"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Left, "Left"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Right, "Right"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Down, "Down"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Up, "Up"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LShift, "LShift"));
    }

    Observador::Observador(Gerenciadores::GerenciadorEventos* pGEv):
    ativar(false),
    teclado(),
    tecladoEspecial()
    {
        pGEventos = pGEv;
        inicializarTeclado();
        pGEventos->adicionarObservador(this);
    }

    Observador::~Observador()
    {
        ativar = false;
        removerObservador();
    }

    const bool Observador::getAtivar() const
    {
        return ativar;
    }

    void Observador::setAtivo(const bool at)
    {
        ativar = at;
    }

    void Observador::removerObservador()
    {
        pGEventos->removerObservador(this);
    }
}
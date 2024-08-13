#include "../include/gerenciadores/Gerenciador_Eventos.h"


int main()
{
    Gerenciadores::Gerenciador_Eventos* gEventos = Gerenciadores::Gerenciador_Eventos::getInstancia();
    Gerenciadores::Gerenciador_Grafico* gGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    Entidades::Personagens::Personagem* p1 = new Entidades::Personagens::Personagem();
    Entidades::Personagens::Personagem* p2 = new Entidades::Personagens::Personagem();

    gEventos->setPersonagem1(p1);
    gEventos->setPersonagem2(p2);

    //Para testes
    //sf::RectangleShape retangulo(sf::Vector2f(100, 100));
    //retangulo.setPosition(200, 200);
    //retangulo.setFillColor(sf::Color::White);

    while(gGrafico->getJanela().isOpen())
    {
        gEventos->executar();
        gGrafico->limparJanela();
        
        //gGrafico->getJanela().draw(retangulo);
        gGrafico->desenhaEnte(static_cast<Ente*>(p1));
        gGrafico->desenhaEnte(static_cast<Ente*>(p2));
        gGrafico->mostrarJanela();
    }
}
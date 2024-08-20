#include "../include/gerenciadores/Gerenciador_Eventos.h"


int main()
{
    Gerenciadores::Gerenciador_Eventos* gEventos = Gerenciadores::Gerenciador_Eventos::getInstancia();
    Gerenciadores::Gerenciador_Grafico* gGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    Entidades::Personagens::Jogador* p1 = new Entidades::Personagens::Jogador();
    Entidades::Personagens::Jogador* p2 = new Entidades::Personagens::Jogador();

    gEventos->setJogador1(p1);
    gEventos->setJogador2(p2);

    //Para testes
    //sf::RectangleShape retangulo(sf::Vector2f(100, 100));
    //retangulo.setPosition(200, 200);
    //retangulo.setFillColor(sf::Color::White);

    while(gGrafico->getJanela().isOpen())
    {
        gEventos->executar();
        gGrafico->limparJanela();

        p1->executar();
        p2->executar();
        
        //gGrafico->getJanela().draw(retangulo);
        gGrafico->desenhaEnte(static_cast<Ente*>(p1));
        gGrafico->desenhaEnte(static_cast<Ente*>(p2));
        gGrafico->mostrarJanela();
    }
}
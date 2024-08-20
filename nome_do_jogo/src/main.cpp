#include "../include/gerenciadores/Gerenciador_Eventos.h"
#include "../include/gerenciadores/Gerenciador_Colisoes.h"
#include "../include/entidades/obstaculos/Plataforma.h"

int main()
{
    Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma("", 1000, 100, 500, 750);
    Gerenciadores::Gerenciador_Eventos* gEventos = Gerenciadores::Gerenciador_Eventos::getInstancia();
    Gerenciadores::Gerenciador_Grafico* gGrafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    Gerenciadores::Gerenciador_Colisoes* gColisoes = new Gerenciadores::Gerenciador_Colisoes();
    Entidades::Personagens::Jogador* p1 = new Entidades::Personagens::Jogador();
    Entidades::Personagens::Jogador* p2 = new Entidades::Personagens::Jogador();

    gEventos->setJogador1(p1);
    gEventos->setJogador2(p2);
    gColisoes->setJog1(p1);
    gColisoes->setJog2(p2);
    gColisoes->incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(plat));

    //Para testes
    //sf::RectangleShape retangulo(sf::Vector2f(100, 100));
    //retangulo.setPosition(200, 200);
    //retangulo.setFillColor(sf::Color::White);

    while(gGrafico->getJanela().isOpen())
    {
        gGrafico->limparJanela();
        gEventos->executar();
        gColisoes->executar();

        plat->executar();
        p1->executar();
        p2->executar();
        
        //gGrafico->getJanela().draw(retangulo);
        gGrafico->desenhaEnte(static_cast<Ente*>(p1));
        gGrafico->desenhaEnte(static_cast<Ente*>(p2));
        gGrafico->desenhaEnte(static_cast<Ente*>(plat));
        gGrafico->mostrarJanela();
    }

    //delete plat;
    delete p1;
    delete p2;  
    delete gGrafico;
    delete gEventos;

    return 0;
}
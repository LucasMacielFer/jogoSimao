#include "../../include/principal/Jogo.h"

namespace Principal
{
    Jogo::Jogo():
    gEventos(Gerenciadores::Gerenciador_Eventos::getInstancia()),
    gColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
    gGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
    p1(new Entidades::Personagens::Jogador(sf::Color::Blue, 50, 700)),
    p2(new Entidades::Personagens::Jogador(sf::Color::Cyan, 50, 100)),
    inim(new Entidades::Personagens::Lobisomem(sf::Color::Red, 100, 100)),
    plat(new Entidades::Obstaculos::Plataforma(1024, 100, 512, 750)),
    gosma(new Entidades::Obstaculos::Gosma(sf::Color::Yellow, 0.2, 900, 690)),
    esp(new Entidades::Obstaculos::Espinho(sf::Color::Magenta, 10, 800 ,675)),
    relogio(),
    tempo(0.0f)
    {
        time_t t;
        srand((unsigned)time(&t));
        gEventos->setJogador1(p1);
        gEventos->setJogador2(p2);
        gColisoes->setJog1(p1);
        gColisoes->setJog2(p2);
        gColisoes->incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(plat));
        gColisoes->incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(gosma));
        gColisoes->incluirObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(esp));
        gColisoes->incluirInimigo(static_cast<Entidades::Personagens::Inimigo*>(inim));
    }

    Jogo::~Jogo()
    {
        delete gGrafico;
        delete gEventos;
        delete gColisoes;
        delete p1;
        delete p2;  
        delete plat;
    }

    void Jogo::executar()
    {
        while(gGrafico->janelaAberta())
        {
            gGrafico->limparJanela();
            gEventos->executar();
            gColisoes->executar();

            tempo = relogio.getElapsedTime().asSeconds();
            relogio.restart();

            inim->setJogador1(p1);
            inim->setJogador2(p2);

            plat->executar(tempo);
            gosma->executar(tempo);
            esp->executar(tempo);
            inim->executar(tempo);
            p1->executar(tempo);
            p2->executar(tempo);
            
            //gGrafico->getJanela().draw(retangulo);
            gGrafico->desenhaEnte(static_cast<Ente*>(p1));
            gGrafico->desenhaEnte(static_cast<Ente*>(p2));
            gGrafico->desenhaEnte(static_cast<Ente*>(plat));
            gGrafico->desenhaEnte(static_cast<Ente*>(inim));
            gGrafico->desenhaEnte(static_cast<Ente*>(gosma));
            gGrafico->desenhaEnte(static_cast<Ente*>(esp));
            gGrafico->mostrarJanela();
        }
    }
}
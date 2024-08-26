#include "../../include/fases/Fase.h"

namespace Fases
{
    const int Fase::idClasse(4);
    Gerenciadores::Gerenciador_Colisoes* Fase::pGColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia());

    void Fase::gerenciarColisoes()
    {
        pGColisoes->setJog1(jog1);
        pGColisoes->setJog2(jog2);
        pGColisoes->executar();
    }

    void Fase::inicializaColisoes()
    {
        Entidades::Entidade* pAux = NULL;
        lEntidades.irAoPrimeiro();
        while(!lEntidades.fim())
        {
            pAux = lEntidades.passoPercorrer();
            if(pAux->getId() == 2)
            {
                pGColisoes->incluirInimigo(pAux);
            }
            else if(pAux->getId() == 3)
            {
                pGColisoes->incluirObstaculo(pAux);
            }
        }
    }

    void Fase::executarEntidades(float dt)
    {
        if(jog1)
            jog1->executar(dt);
        if(jog2)
            jog2->executar(dt);
        lEntidades.percorreExecutando(dt);
    }

    const float Fase::calculaCentroCamera()
    {
        float xMedio = 0.0f;
        float divisor = 0.0f;
        if(jog1)
        {
            xMedio += jog1->getPosicao().x;
            divisor += 1.0;
        }
        if(jog2)
        {
            xMedio += jog2->getPosicao().x;
            divisor += 1.0;
        }
        
        xMedio /= divisor;
        
        if(xMedio < (pGGrafico->getTamJanela().x/2.0f)+64)
        {
            return pGGrafico->getTamJanela().x/2.0f;
        }
        else if(xMedio > (tamMapa - (pGGrafico->getTamJanela().x/2.0f)))
        {
            return tamMapa - (pGGrafico->getTamJanela().x/2.0f);
        }
        return xMedio;
    }


    Fase::Fase(std::string tilemap):
    Ente(idClasse),
    lEntidades(),
    caminhoTilemap(tilemap),
    jog1(NULL),
    jog2(NULL),
    tamMapa(0)
    {
    }

    Fase::Fase():
    Ente(-1),
    lEntidades(),
    caminhoTilemap(""),
    jog1(NULL),
    jog2(NULL),
    tamMapa(0)
    {
    }

    Fase::~Fase()
    {
        // Salvar?
        lEntidades.limpaLista();
    }

    // Será chamada pelo gerenciador grafico!
    void Fase::desenhar(sf::RenderWindow& janela)
    {
        if(jog1)
            jog1->desenhar(janela);
        if(jog2)
            jog2->desenhar(janela);
        lEntidades.irAoPrimeiro();
        while(!lEntidades.fim())
        {
            (lEntidades.passoPercorrer())->desenhar(janela);
        }
    }

    void Fase::setJogador1(Entidades::Personagens::Jogador* jog)
    {
        jog1 = jog;
    }

    void Fase::setJogador2(Entidades::Personagens::Jogador* jog)
    {
        jog2 = jog;
    }

    void Fase::executar(float dt)
    {
        gerenciarColisoes();
        executarEntidades(dt);
        pGGrafico->moveCamera(calculaCentroCamera());
    }

    void Fase::salvar()
    {
        // Logica de salvamento
    }
}
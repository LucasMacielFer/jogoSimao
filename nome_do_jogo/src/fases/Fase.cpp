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

    void Fase::criarMapa()
    {
        CriadorMapas* gerador = new CriadorMapas(caminhoTilemap);
        if(gerador)
        {
            gerador->criarMapa(&lEntidades, nOFaceis, nOMedios, nODificeis, nIFaceis, nIDificeis, nIChefoes);
            delete gerador;
            gerador = NULL;
        }
    }

    const float Fase::calculaCentroCamera()
    {
        float x = 0.0f;
        if(jog1)
        {
            x += jog1->getPosicao().x;
        }
        if(jog2)
        {
            x += jog2->getPosicao().x;
        }
        
        return x/2.0f;
    }


    Fase::Fase(std::string tilemap, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC):
    Ente(idClasse),
    lEntidades(),
    caminhoTilemap(tilemap),
    jog1(NULL),
    jog2(NULL),
    nOFaceis(nOF),
    nOMedios(nOM),
    nODificeis(nOD),
    nIFaceis(nIF),
    nIDificeis(nID),
    nIChefoes(nIC)
    {
        criarMapa();
        inicializaColisoes();
    }

    Fase::Fase():
    Ente(-1),
    lEntidades(),
    caminhoTilemap(""),
    jog1(NULL),
    jog2(NULL),
    nOFaceis(0),
    nOMedios(0),
    nODificeis(0),
    nIFaceis(0),
    nIDificeis(0),
    nIChefoes(0)
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
        jog1->desenhar(janela);
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
        pGGrafico->moveCamera(calculaCentroCamera());
        gerenciarColisoes();
        executarEntidades(dt);
    }

    void Fase::salvar()
    {
        // Logica de salvamento
    }
}
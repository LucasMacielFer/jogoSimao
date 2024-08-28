#include "../../include/fases/Fase.h"

namespace Fases
{
    const int Fase::idClasse(4);
    Gerenciadores::Gerenciador_Colisoes* Fase::pGColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia());

    void Fase::gerenciarProjeteis()
    {
        Entidades::Entidade* pAux = NULL;
        Entidades::Personagens::Esqueleto* pEsq = NULL;
        Entidades::Personagens::Mago* pMago = NULL;
        Entidades::Personagens::Inimigo* pInim = NULL;
        Entidades::Projetil* pProj = NULL;
        lEntidades.irAoPrimeiro();
        while(!lEntidades.fim())
        {
            pAux = lEntidades.passoPercorrer();
            if(pAux->getId() == 2)
            {
                pInim = dynamic_cast<Entidades::Personagens::Inimigo*>(pAux);
                if(pInim->getTipo() == 2)
                {
                    pEsq = dynamic_cast<Entidades::Personagens::Esqueleto*>(pInim);
                    if(pEsq->getFlecha() && !pEsq->getFTratada())
                    {
                        std::cout<<"\n\n\nADICIONEI\n\n\n"<<std::endl;
                        lEntidades.acrescentarEntidade(static_cast<Entidades::Entidade*>(pEsq->getFlecha()));
                        pGColisoes->incluirInimigo(static_cast<Entidades::Entidade*>(pEsq->getFlecha()));
                        pEsq->setFTratada(true);
                    }
                }
                
                else if(pInim->getTipo() == 3)
                {
                    pMago = dynamic_cast<Entidades::Personagens::Mago*>(pInim);
                    if(pMago->getFogo() && !pMago->getBFTratada())
                    {
                        lEntidades.acrescentarEntidade(static_cast<Entidades::Entidade*>(pMago->getFogo()));
                        pGColisoes->incluirInimigo(static_cast<Entidades::Entidade*>(pMago->getFogo()));
                        pMago->setBFTratada(true);
                    }
                }
            }
            
            else if(pAux->getId() == 4)
            {
                pProj = dynamic_cast<Entidades::Projetil*>(pAux);
                if(!pProj->getAtivo())
                { 
                    std::cout<<"\n\n\nREMOVI\n\n\n"<<std::endl;
                    pGColisoes->removerInimigo(static_cast<Entidades::Entidade*>(pProj));
                    lEntidades.removerEntidade(static_cast<Entidades::Entidade*>(pProj));
                    delete pProj;
                    pProj = NULL;
                }
            }
        }
    }

    void Fase::criarChao()
    {
        criadorDeMapas->criarChao(&lEntidades);
    }

    void Fase::criarPlataformas(bool* plats, const int max)
    {
        aleatorizaOcorrencias(plats, max);
        criadorDeMapas->criarTipo(&lEntidades, CODIGO_PLATAFORMA, plats, max);
    }

    void Fase::criarEsqueletos(bool* esqs, const int max)
    {
        aleatorizaOcorrencias(esqs, max);
        criadorDeMapas->criarTipo(&lEntidades, CODIGO_ESQUELETO, esqs, max);
    }
    
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
            return pGGrafico->getTamJanela().x/2.0f + 64;
        }
        else if(xMedio > (tamMapa - (pGGrafico->getTamJanela().x/2.0f)))
        {
            return tamMapa - (pGGrafico->getTamJanela().x/2.0f);
        }
        return xMedio;
    }


    Fase::Fase(std::string tilemap):
    Ente(idClasse),
    criadorDeMapas(new CriadorMapas(tilemap)),
    lEntidades(),
    caminhoTilemap(tilemap),
    jog1(NULL),
    jog2(NULL),
    tamMapa(0)
    {
        time_t t;
        srand((unsigned)time(&t));
        //Entidades::Personagens::Mago* pMag = new Entidades::Personagens::Mago("assets/textures/esqueleto.png", 500, 100);
        //lEntidades.acrescentarEntidade(static_cast<Entidades::Personagens::Mago*>(pMag));
    }

    Fase::Fase():
    Ente(-1),
    criadorDeMapas(NULL),
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
        lEntidades.percorreDesenhando(janela);
    }

    void Fase::setJogador1(Entidades::Personagens::Jogador* jog)
    {
        Entidades::Entidade* pAux = NULL;
        Entidades::Personagens::Inimigo* pInim = NULL;
        lEntidades.irAoPrimeiro();
        while(!lEntidades.fim())
        {
            pAux = lEntidades.passoPercorrer();
            if(pAux->getId() == 2)
            {
                pInim = dynamic_cast<Entidades::Personagens::Inimigo*>(pAux);
                pInim->setJogador1(jog);
            }
        }
        jog1 = jog;
    }

    void Fase::setJogador2(Entidades::Personagens::Jogador* jog)
    {
        Entidades::Entidade* pAux = NULL;
        Entidades::Personagens::Inimigo* pInim = NULL;
        lEntidades.irAoPrimeiro();
        while(!lEntidades.fim())
        {
            pAux = lEntidades.passoPercorrer();
            if(pAux->getId() == 2)
            {
                pInim = dynamic_cast<Entidades::Personagens::Inimigo*>(pAux);
                pInim->setJogador2(jog);
            }
        }
        jog2 = jog;
    }

    void Fase::executar(float dt)
    {
        gerenciarColisoes();
        gerenciarProjeteis();
        executarEntidades(dt);
        pGGrafico->moveCamera(calculaCentroCamera());
    }

    void Fase::aleatorizaOcorrencias(bool* ocorrencias, const int max)
    {
        int i;
        int cont = 0;
        for(i=0; i<max; i++)
        {
            ocorrencias[i] = rand()%2 == 1 ? true : false;
            if(ocorrencias[i]) {cont++;}
        }

        i = 0;
        while(cont < 3)
        {
            if(!ocorrencias[i])
            {
                ocorrencias[i] = true;
                cont++;
            }
            i++;
        }
    }

    void Fase::salvar()
    {
        // Logica de salvamento
    }
}
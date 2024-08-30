#include "../../../include/estados/fases/Fase.h"

namespace Estados
{
    namespace Fases
    {
        Gerenciadores::Gerenciador_Colisoes* Fase::pGColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia());
        Gerenciadores::Gerenciador_Eventos* Fase::pGEventos(Gerenciadores::Gerenciador_Eventos::getInstancia());    

        void Fase::constroiHud()
        {
            float meio = calculaCentroCamera();
            if(jog1)
            {
                vidasJ1->setString("Vidas J1: " + std::to_string(jog1->getVidas()));
                pontosJ1->setString("Pontos J1: " + std::to_string(jog1->getPontuacao()));
            }
            vidasJ1->setX(meio-496);
            pontosJ1->setX(meio+284);
            if(jog2)
            {
                vidasJ2->setString("Vidas J2: " + std::to_string(jog2->getVidas()));
                pontosJ2->setString("Pontos J2: " + std::to_string(jog2->getPontuacao()));
            }
            vidasJ2->setX(meio-496);
            pontosJ2->setX(meio+284);
        }

        void Fase::verificaJogsVivos()
        {
            if(jog1 && !jog1->getVivo())
            {   
                vidasJ1->setString("Vidas J1: 0");
                vidasJ1->setCor(sf::Color::Red);
                pontosJ1->setCor(sf::Color::Red);
                pGColisoes->setJog1(NULL);
                pGEventos->setJogador1(NULL);
                delete jog1;
                setJogador1(NULL);
            }
            if(jog2 && !jog2->getVivo())
            {
                vidasJ2->setString("Vidas J2: 0");
                vidasJ2->setCor(sf::Color::Red);
                pontosJ2->setCor(sf::Color::Red);
                pGColisoes->setJog2(NULL);
                pGEventos->setJogador2(NULL);
                delete jog2;
                setJogador2(NULL);
            }
            if(!jog1 && !jog2)
            {
                std::cout<<"Skill issue"<<std::endl;
                exit(1);
            }
        }

        void Fase::verificaVitoria()
        {
            int cont = 0;
            int posX = 0;

            if(jog1)
            {
                posX += jog1->getPosicao().x;
                cont++;
            }
            if(jog2)
            {
                posX += jog2->getPosicao().x;
                cont++;
            }
            if(cont != 0)
            {
                if(posX/cont >= tamMapa-100)
                {
                    vencer();
                }
            }
        }

        void Fase::gerenciarProjeteis()
        {
            Entidades::Entidade** vetRemocao = (Entidades::Entidade**) malloc(sizeof(Entidades::Entidade*)*100);
            int index = 0;

            Entidades::Entidade* pAux = NULL;
            Entidades::Personagens::Esqueleto* pEsq = NULL;
            Entidades::Personagens::Mago* pMago = NULL;
            Entidades::Personagens::Inimigo* pInim = NULL;
            Entidades::Projetil* pProj = NULL;
            lEntidades.irAoPrimeiro();
            while(!lEntidades.fim())
            {
                pAux = lEntidades.passoPercorrer();
                if(pAux && pAux->getId() == idEntes::Projetil)
                {
                    pProj = dynamic_cast<Entidades::Projetil*>(pAux);
                    if(!pProj->getAtivo())
                    { 
                        pGColisoes->removerInimigo(pAux);;
                        if(pProj->getAtirador()->getTipo() == Entidades::Personagens::tipoInimigo::Esque)
                        {
                            dynamic_cast<Entidades::Personagens::Esqueleto*>(pProj->getAtirador())->setFlecha(NULL);
                        }
                        if(pProj->getAtirador()->getTipo() == Entidades::Personagens::tipoInimigo::Mag)
                        {
                            dynamic_cast<Entidades::Personagens::Mago*>(pProj->getAtirador())->setBolaFogo(NULL);
                        }
                        vetRemocao[index] = pAux;
                        index++;

                        pProj = NULL;
                        pAux = NULL;
                    }
                }
            }
            for(int i=0; i<index; i++)
            {
                lEntidades.removerEntidade(vetRemocao[i]);
            }
        }

        void Fase::criarChao()
        {
            criadorDeMapas->criarChao(&lEntidades);
        }

        void Fase::criarJogadores(const int numJogs)
        {
            if(numJogs >= 1)
            {
                setJogador1(new Entidades::Personagens::Jogador("assets/textures/jogador1.png", "assets/textures/jogador1ataca.png", 100, 0));
                pGColisoes->setJog1(jog1);
                pGEventos->setJogador1(jog1);
            }
            if(numJogs == 2)
            {
                setJogador2(new Entidades::Personagens::Jogador("assets/textures/jogador2.png", "assets/textures/jogador2ataca.png", 100, 0));
                pGColisoes->setJog2(jog2);
                pGEventos->setJogador2(jog2);
            }
        }

        void Fase::criarPlataformas(bool* plats, const int max)
        {
            aleatorizaOcorrencias(plats, max);
            criadorDeMapas->criarTipoGrande(&lEntidades, CODIGO_PLATAFORMA, plats, max);
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
                if(pAux && pAux->getId() == idEntes::Inimigo)
                {
                    pGColisoes->incluirInimigo(pAux);
                    // TEMPORARIO - VAI PRA CRIAÇÃO DE MAPA
                    if(dynamic_cast<Entidades::Personagens::Inimigo*>(pAux)->getTipo() == Entidades::Personagens::tipoInimigo::Esque)
                    {
                        dynamic_cast<Entidades::Personagens::Esqueleto*>(pAux)->setFase(this);
                    }
                    if(dynamic_cast<Entidades::Personagens::Inimigo*>(pAux)->getTipo() == Entidades::Personagens::tipoInimigo::Mag)
                    {
                        dynamic_cast<Entidades::Personagens::Mago*>(pAux)->setFase(this);
                    }
                }
                else if(pAux && pAux->getId() == idEntes::Obstaculo)
                {
                    pGColisoes->incluirObstaculo(pAux);
                }
                pAux = NULL;
            }
        }

        void Fase::executarEntidades(float dt)
        {
            if(jog1)
                jog1->executar(dt);
            if(jog2)
                jog2->executar(dt);

            lEntidades.percorreExecutando(dt);

            Entidades::Entidade** vetRemocao = (Entidades::Entidade**) malloc(sizeof(Entidades::Entidade*)*100);
            int index = 0;

            Entidades::Entidade* pAux = NULL;
            lEntidades.irAoPrimeiro();
            while(!lEntidades.fim())
            {
                pAux = lEntidades.passoPercorrer();

                if(pAux && pAux->getId() == idEntes::Inimigo)
                {
                    Entidades::Personagens::Inimigo* inim = dynamic_cast<Entidades::Personagens::Inimigo*>(pAux);
                    if(!inim->getVivo())
                    {
                        pGColisoes->removerInimigo(pAux);
                        vetRemocao[index] = pAux;
                        index++;
                        pAux = NULL;
                    }
                }
            }
            for(int i=0; i<index; i++)
            {
                lEntidades.removerEntidade(vetRemocao[i]);
            }
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


        Fase::Fase(std::string tilemap, idEstados id, const int numJogs):
        Estado(id),
        Ente(idEntes::Fase),
        criadorDeMapas(new CriadorMapas(tilemap)),
        lEntidades(),
        caminhoTilemap(tilemap),
        jog1(NULL),
        jog2(NULL),
        tamMapa(0),
        pontosJ1(new Texto::ElementoTexto(40, 796, 5,sf::Color::White, "assets/fonts/StepalangeShort.ttf")),
        pontosJ2(new Texto::ElementoTexto(40, 796, 35,sf::Color::White, "assets/fonts/StepalangeShort.ttf")),
        vidasJ1(new Texto::ElementoTexto(40, 80, 5,sf::Color::White, "assets/fonts/StepalangeShort.ttf")),
        vidasJ2(new Texto::ElementoTexto(40, 80, 35,sf::Color::White, "assets/fonts/StepalangeShort.ttf"))
        {
            pGColisoes = Gerenciadores::Gerenciador_Colisoes::getInstancia();
            pGEventos = Gerenciadores::Gerenciador_Eventos::getInstancia();
            time_t t;
            srand((unsigned)time(&t));
        }

        Fase::Fase():
        Estado(idEstados::Indefinido),
        Ente(idEntes::Indefinido),
        criadorDeMapas(NULL),
        lEntidades(),
        caminhoTilemap(""),
        jog1(NULL),
        jog2(NULL),
        tamMapa(0),
        pontosJ1(),
        pontosJ2(),
        vidasJ1(),
        vidasJ2()
        {
        }

        Fase::~Fase()
        {
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
            pontosJ1->desenhar(janela);
            pontosJ2->desenhar(janela);
            vidasJ1->desenhar(janela);
            vidasJ2->desenhar(janela);
        }

        void Fase::setJogador1(Entidades::Personagens::Jogador* jog)
        {
            Entidades::Entidade* pAux = NULL;
            Entidades::Personagens::Inimigo* pInim = NULL;
            lEntidades.irAoPrimeiro();
            while(!lEntidades.fim())
            {
                pAux = lEntidades.passoPercorrer();
                if(pAux->getId() == idEntes::Inimigo)
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
                if(pAux->getId() == idEntes::Inimigo)
                {
                    pInim = dynamic_cast<Entidades::Personagens::Inimigo*>(pAux);
                    pInim->setJogador2(jog);
                }
            }
            jog2 = jog;
        }

        void Fase::criarProjetil(Entidades::Personagens::Inimigo* inim, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel)
        {
            Entidades::Projetil* pProj = new Entidades::Projetil(inim, txt, tamXX, tamYY, xx, yy, sentMovX, vel);
            if(inim->getTipo() == Entidades::Personagens::tipoInimigo::Esque)
            {
                Entidades::Personagens::Esqueleto* pEsq = dynamic_cast<Entidades::Personagens::Esqueleto*>(inim);
                pEsq->setFlecha(pProj);
            }
            if(inim->getTipo() == Entidades::Personagens::tipoInimigo::Mag)
            {
                Entidades::Personagens::Mago* pMag = dynamic_cast<Entidades::Personagens::Mago*>(inim);
                pMag->setBolaFogo(pProj);
            }
            pGColisoes->incluirInimigo(static_cast<Entidades::Entidade*>(pProj));
            lEntidades.acrescentarEntidade(static_cast<Entidades::Entidade*>(pProj));
        }


        void Fase::executar(float dt)
        {
            gerenciarColisoes();
            gerenciarProjeteis();
            executarEntidades(dt);
            pGGrafico->moveCamera(calculaCentroCamera());
            verificaVitoria();
            verificaJogsVivos();
            constroiHud();
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

        void Fase::salvarJogada(const char* caminhoSalvamento)
        {
            if(jog1)
                jog1->salvar(caminhoSalvamento);
            if(jog2)
                jog2->salvar(caminhoSalvamento);

            Entidades::Entidade* pAux = NULL;
            lEntidades.irAoPrimeiro();
            while(!lEntidades.fim())
            {
                pAux = lEntidades.passoPercorrer();
                if(pAux)
                    pAux->salvar(caminhoSalvamento);
            }
        }
    }
}
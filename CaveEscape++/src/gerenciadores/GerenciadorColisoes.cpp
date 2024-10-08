#include "gerenciadores/GerenciadorColisoes.h"
#include "entidades/Entidade.h"
//#include "auxiliares/ListaEntidades.h"

namespace Gerenciadores
{
    GerenciadorColisoes* GerenciadorColisoes::pInstancia(NULL);

    GerenciadorColisoes::GerenciadorColisoes():
    pJogador1(NULL),
    pJogador2(NULL),
    LObstaculos(),
    LInimigos()
    {
        LObstaculos.clear();
        LInimigos.clear();
    }

    GerenciadorColisoes::~GerenciadorColisoes()
    {
        std::vector<Entidades::Entidade*>::iterator itrInim;
        std::list<Entidades::Entidade*>::iterator itrObs;

        pJogador1 = NULL;
        pJogador2 = NULL;
        
        for(itrInim=LInimigos.begin(); itrInim!=LInimigos.end(); itrInim++)
        {
            (*itrInim) = NULL;
        }
        LInimigos.clear();
        for(itrObs=LObstaculos.begin(); itrObs!=LObstaculos.end(); itrObs++)
        {
            (*itrObs) = NULL;
        }
        LObstaculos.clear();
    }

    const sf::Vector2f GerenciadorColisoes::calculaColisoes(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        if(e1 && e2)
        {
            sf::Vector2f posicao1 = e1->getPosicao();
            sf::Vector2f posicao2 = e2->getPosicao();

            sf::Vector2f tamanho1 = e1->getTamanho();
            sf::Vector2f tamanho2 = e2->getTamanho();

            //Calculo da distância relativa entre os centros de cada entidade.
            float dist_centro_em_x = fabs((posicao1.x) - (posicao2.x));
            float dist_centro_em_y = fabs((posicao1.y) - (posicao2.y));

            //Um vetor que indica que ocorre colisão se os dois parâmetros são negativos.
            return sf::Vector2f(dist_centro_em_x - ((tamanho1.x/2.0f) + (tamanho2.x/2.0f)), dist_centro_em_y - ((tamanho1.y/2.0f) + (tamanho2.y/2.0f)) );
        }
        else
        {
            std::cout << "Ponteiros nulos comparados na calculadora" << std::endl;
            exit(1);
        }
    }

    void GerenciadorColisoes::tratarColisoesJogsObstacs()
    {
        std::list<Entidades::Entidade*>::iterator itrObs;
        Entidades::Entidade* obst = NULL;
        for(itrObs=LObstaculos.begin(); itrObs!=LObstaculos.end(); itrObs++)
        {
            obst = (*itrObs);
            if(pJogador1)
            {
                sf::Vector2f distancia_colisao = calculaColisoes(static_cast<Entidades::Entidade*>(pJogador1), obst);

                if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                {
                    pJogador1->colidir(obst, distancia_colisao);
                    obst->colidir(pJogador1, distancia_colisao); // metodo ainda precisa ser definido na classe entidade
                }
            }
            if(pJogador2)
            {
                sf::Vector2f distancia_colisao = calculaColisoes(static_cast<Entidades::Entidade*>(pJogador2), obst);

                if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                {
                    pJogador2->colidir(obst, distancia_colisao);
                    obst->colidir(pJogador2, distancia_colisao); // metodo ainda precisa ser definido na classe entidade
                }
            }
        }
    }

    void GerenciadorColisoes::tratarColisoesJogsInimgs()
    {
        std::vector<Entidades::Entidade*>::iterator itrInim;
        Entidades::Entidade* inim = NULL;
        for(itrInim=LInimigos.begin(); itrInim!=LInimigos.end(); itrInim++)
        {
            inim = (*itrInim);
            if(pJogador1)
            {
                sf::Vector2f distancia_colisao = calculaColisoes(static_cast<Entidades::Entidade*>(pJogador1), inim);

                if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                {
                    pJogador1->colidir(inim, distancia_colisao);
                    inim->colidir(pJogador1, distancia_colisao);
                }
            }
            if(pJogador2)
            {
                sf::Vector2f distancia_colisao = calculaColisoes(static_cast<Entidades::Entidade*>(pJogador2), inim);

                if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                {
                    pJogador2->colidir(inim, distancia_colisao);
                    inim->colidir(pJogador2, distancia_colisao);
                }
            }
        }
    }

    void GerenciadorColisoes::tratarColisoesInimgsObstacs() {
        std::list<Entidades::Entidade*>::iterator itrObs;

        for (int i=0; i<LInimigos.size(); i++) {
            Entidades::Entidade* inimigo = LInimigos[i];
            for (itrObs = LObstaculos.begin(); itrObs != LObstaculos.end(); itrObs++) {
                Entidades::Entidade* obstaculo = *itrObs;
                sf::Vector2f distancia_colisao = calculaColisoes(inimigo, obstaculo);

                if (distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f) {
                    inimigo->colidir(obstaculo, distancia_colisao); // Método ainda precisa ser definido na classe Entidade
                    obstaculo->colidir(inimigo, distancia_colisao); // Método ainda precisa ser definido na classe Entidade
                }
            }
        }
    }

    void GerenciadorColisoes::tratarColisoesImimgs() {
        for (int i=0; i<LInimigos.size(); i++) {
            Entidades::Entidade* inimigo1 =LInimigos[i];
            for (int j=i; j<LInimigos.size(); j++) {
                Entidades::Entidade* inimigo2 = LInimigos[j];
                sf::Vector2f distancia_colisao = calculaColisoes(inimigo1, inimigo2);

                if (distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f) {
                    // inimigo1->colidir(inimigo2, distancia_colisao); // Método ainda precisa ser definido na classe Entidade
                    // inimigo2->colidir(inimigo1, distancia_colisao); // Método ainda precisa ser definido na classe Entidade
                }
            }
        }
    }

    void GerenciadorColisoes::incluirObstaculo(Entidades::Entidade* pO) {
        if (pO) {
            LObstaculos.push_back(pO);
        }
    }

    void GerenciadorColisoes::incluirInimigo(Entidades::Entidade* pI) {
        if (pI) {
            LInimigos.push_back(pI);
        }
    }

    void GerenciadorColisoes::removerObstaculo(Entidades::Entidade* pO)
    {
        std::list<Entidades::Entidade*>::iterator itr;
        itr = std::find(LObstaculos.begin(), LObstaculos.end(), pO);
        if(itr != LObstaculos.end())
            LObstaculos.erase(itr);
    }

    void GerenciadorColisoes::removerInimigo(Entidades::Entidade* pI)
    {
        std::vector<Entidades::Entidade*>::iterator itr;
        itr = std::find(LInimigos.begin(), LInimigos.end(), pI);
        if(itr != LInimigos.end())
            LInimigos.erase(itr);
    }

    void GerenciadorColisoes::limparListas()
    {
        LInimigos.clear();
        LObstaculos.clear();
        setJog1(NULL);
        setJog2(NULL);
    }

    void GerenciadorColisoes::setJog1(Entidades::Personagens::Jogador* pJog1) {
        pJogador1 = pJog1;
    }

    void GerenciadorColisoes::setJog2(Entidades::Personagens::Jogador* pJog2) {
        pJogador2 = pJog2;
    }

    void GerenciadorColisoes::executar() {
        tratarColisoesJogsObstacs();
        tratarColisoesJogsInimgs();
        tratarColisoesInimgsObstacs();
        tratarColisoesImimgs();
        // Adicione outras funções de tratamento de colisão conforme necessário
    }

    // Execução efetiva do padrão de projeto singleton
    GerenciadorColisoes* GerenciadorColisoes::getInstancia()
    {
        if(!pInstancia)
        {
            pInstancia = new GerenciadorColisoes();
        }
        return pInstancia;
    }

} // namespace Gerenciadores
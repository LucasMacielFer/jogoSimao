#include "../../../include/entidades/obstaculos/Gosma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Gosma::Gosma(const char* txt, const float d, const float xx, const float yy):
        Obstaculo(txt, TAM_X_GOSMA, TAM_Y_GOSMA, xx, yy, idObstaculos::gosm, false),
        decrementoVelocidade(d)
        {
        }

        Gosma::Gosma():
        Obstaculo(),
        decrementoVelocidade(1)
        {
        }

        Gosma::~Gosma()
        {
        }

        void Gosma::obstacular(Personagens::Personagem* p)
        {
            if(p->getId() == idEntes::Jogador) // Jogador
            {
                p->setVelocidade(p->getVelMax()*decrementoVelocidade);
                p->setPulo(false);
            }
            else    // Inimigo
            {
                p->setVelocidade(p->getVelMax()*decrementoVelocidade);
            }
        }

        void Gosma::salvar(const char* caminhoSalvamento)
        {
            Obstaculo::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(decrementoVelocidade);


            std::ofstream gravador(caminhoSalvamento, std::ios::app);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar gosma"<<std::endl;
            }
            else
            {
                gravador << salvamento << std::endl;
            }
            gravador.close();
        }

        void Gosma::executar(float dt)
        {
        }
    }
}
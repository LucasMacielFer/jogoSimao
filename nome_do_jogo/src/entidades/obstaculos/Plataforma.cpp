#include "../../../include/entidades/obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(std::string txt, const float tamXX, const float tamYY, const float xx, const float yy):
        Obstaculo(false, txt, tamXX, tamYY, xx, yy),
        forcaSustentacao(10) //Aqui vai vir a gravidade!
        {
        }

        Plataforma::~Plataforma()
        {
        }

        void Plataforma::salvar()
        {
        }

        void Plataforma::executar(float dt)
        {
        }

        void Plataforma::obstacular(Personagens::Jogador* p)
        {
            //Plataforma não obstacula!
        }
    }
}
#include "../../include/estados/GerenciadorEstados.h"
#include "../../include/Ente.h"
#include "../../include/estados/fases/FasePrimeira.h"
#include "../../include/estados/fases/FaseSegunda.h"

namespace Estados
{
    GerenciadorEstados* GerenciadorEstados::pInstancia(NULL);

    GerenciadorEstados::GerenciadorEstados():
    pilhaEstados()
    {
        empilharEstado(idEstados::Jogando1);
    }

    GerenciadorEstados::~GerenciadorEstados()
    {
        Estado* pAux;

        while(!pilhaEstados.empty())
        {
            pAux = pilhaEstados.top();
            pilhaEstados.pop();

            if(pAux)
                delete pAux;
            pAux = NULL;
        }
    }

    void GerenciadorEstados::empilharEstado(idEstados id)
    {
        if(id == idEstados::Jogando1)
        {
            Fases::FasePrimeira* f1 = new Fases::FasePrimeira(2);
            pilhaEstados.push(static_cast<Estado*>(f1));
        }
        
        else if(id == idEstados::Jogando2)
        {
            Fases::FaseSegunda* f2 = new Fases::FaseSegunda(2);
            pilhaEstados.push(static_cast<Estado*>(f2));
        }
    }

    void GerenciadorEstados::desempilharEstado()
    {
        Estado* pAux;

        if(!pilhaEstados.empty())
        {
            pAux = pilhaEstados.top();
            pilhaEstados.pop();
            delete pAux;
            pAux = NULL;
        }
    }

    Estado* GerenciadorEstados::getEstadoAtual()
    {
        if(!pilhaEstados.empty())
            return pilhaEstados.top();
        else
        {
            std::cout<<"A pilha de estados esta vazia"<<std::endl;
            return NULL;
        }
    }

    Ente* GerenciadorEstados::getEnteAtual()
    {
        switch(getEstadoAtual()->getIdentificador())
        {
            case idEstados::Jogando1:
                return static_cast<Ente*>(dynamic_cast<Fases::FasePrimeira*>(getEstadoAtual()));
                break;
            case idEstados::Jogando2:
                return static_cast<Ente*>(dynamic_cast<Fases::FaseSegunda*>(getEstadoAtual()));
                break;
            default:
                return NULL;
                break;
        }
    }

    void GerenciadorEstados::executar(float dt)
    {
        if(getEstadoAtual()->getAtivo())
            getEstadoAtual()->executar(dt);
    }

    GerenciadorEstados* GerenciadorEstados::getInstancia()
    {
        if(!pInstancia)
            pInstancia = new GerenciadorEstados();
        return pInstancia;
    }
}
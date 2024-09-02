#include "../../include/estados/GerenciadorEstados.h"
#include "../../include/Ente.h"
#include "../../include/estados/fases/FasePrimeira.h"
#include "../../include/estados/fases/FaseSegunda.h"
#include "../../include/estados/menus/MenuPrincipal.h"
#include "../../include/estados/menus/MenuFases.h"

namespace Estados
{
    GerenciadorEstados* GerenciadorEstados::pInstancia(NULL);

    GerenciadorEstados::GerenciadorEstados():
    mapaEstados()
    {
        mudarEstado(idEstados::Principal);
    }

    GerenciadorEstados::~GerenciadorEstados()
    {
        std::map<idEstados, Estado*>::iterator it;
        
        for(it = mapaEstados.begin(); it != mapaEstados.end(); it++)
        {
            delete (*it).second;
            mapaEstados.erase(it);
        }
    }

    void GerenciadorEstados::mudarEstado(idEstados id)
    {
        std::map<idEstados, Estado*>::iterator it;
        estadoAtual = id;
        it = mapaEstados.find(id);

        if(it == mapaEstados.end())
        {
            if(estadoAtual == idEstados::Jogando1)
            {
                Fases::FasePrimeira* f1 = new Fases::FasePrimeira(numJogs);
                mapaEstados.insert(std::make_pair(idEstados::Jogando1, static_cast<Estado*>(f1)));
            }
            else if(estadoAtual == idEstados::Jogando2)
            {
                Fases::FaseSegunda* f2 = new Fases::FaseSegunda(numJogs);
                mapaEstados.insert(std::make_pair(idEstados::Jogando2, static_cast<Estado*>(f2)));
            }
            else if(estadoAtual == idEstados::Principal)
            {
                Menus::MenuPrincipal* mp = new Menus::MenuPrincipal();
                mapaEstados.insert(std::make_pair(idEstados::Principal, static_cast<Estado*>(mp)));
            }
            else if(estadoAtual == idEstados::SelecaoFase)
            {
                Menus::MenuFases* mf = new Menus::MenuFases();
                mapaEstados.insert(std::make_pair(idEstados::SelecaoFase, static_cast<Estado*>(mf)));
            }
        }

        mapaEstados[estadoAtual]->setAtivo(true);

        if(estadoAtual == idEstados::Jogando2)
            excluirEstado(idEstados::Jogando1);
        else if(estadoAtual == idEstados::Jogando1)
            excluirEstado(idEstados::Jogando2);
        else if(estadoAtual == idEstados::Principal)
        {
            excluirEstado(idEstados::Jogando2);
            excluirEstado(idEstados::Jogando2);
        }
    }

    void GerenciadorEstados::setNumJogs(const unsigned int i)
    {
        numJogs = i;
    }

    void GerenciadorEstados::excluirEstado(idEstados id)
    {
        std::map<idEstados, Estado*>::iterator it;
        it = mapaEstados.find(id);
        if(it != mapaEstados.end())
        {
            delete (*it).second;
            mapaEstados.erase(it);
        }
    }

    Estado* GerenciadorEstados::getEstadoAtual()
    {
        return mapaEstados[estadoAtual];
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
            case idEstados::Principal:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuPrincipal*>(getEstadoAtual()));
                break;
            case idEstados::SelecaoFase:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuFases*>(getEstadoAtual()));
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
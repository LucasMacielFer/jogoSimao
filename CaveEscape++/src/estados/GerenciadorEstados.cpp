#include "../../include/estados/GerenciadorEstados.h"
#include "../../include/Ente.h"
#include "../../include/estados/fases/FasePrimeira.h"
#include "../../include/estados/fases/FaseSegunda.h"
#include "../../include/estados/menus/MenuPrincipal.h"
#include "../../include/estados/menus/MenuFases.h"
#include "../../include/estados/menus/MenuVitoria.h"
#include "../../include/estados/menus/MenuDerrota.h"
#include "../../include/estados/menus/MenuPausa.h"
#include "../../include/estados/menus/MenuSalvar.h"
#include "../../include/estados/menus/MenuLideres.h"


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
        estadoAtual = id;

        if(estadoAtual == idEstados::Jogando2)
            excluirEstado(idEstados::Jogando1);
        else if(estadoAtual == idEstados::Jogando1)
            excluirEstado(idEstados::Jogando2);
        else if(estadoAtual == idEstados::Principal || estadoAtual == idEstados::Vitoria || estadoAtual == idEstados::Derrota)
        {
            excluirEstado(idEstados::Jogando1);
            excluirEstado(idEstados::Jogando2);
        }
        
        if(mapaEstados.count(id) == 0)
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
            else if(estadoAtual == idEstados::Derrota)
            {
                Menus::MenuDerrota* md = new Menus::MenuDerrota();
                mapaEstados.insert(std::make_pair(idEstados::Derrota, static_cast<Estado*>(md)));
            }
            else if(estadoAtual == idEstados::Vitoria)
            {
                Menus::MenuVitoria* mv = new Menus::MenuVitoria();
                mapaEstados.insert(std::make_pair(idEstados::Vitoria, static_cast<Estado*>(mv)));
            }
            else if(estadoAtual == idEstados::Pause)
            {
                Menus::MenuPausa* mpausa = new Menus::MenuPausa();
                mapaEstados.insert(std::make_pair(idEstados::Pause, static_cast<Estado*>(mpausa)));
            }
            else if(estadoAtual == idEstados::SalvarNome)
            {
                Menus::MenuSalvar* ms = new Menus::MenuSalvar();
                mapaEstados.insert(std::make_pair(idEstados::SalvarNome, static_cast<Estado*>(ms)));
            }
            else if(estadoAtual == idEstados::TabelaLideres)
            {
                Menus::MenuLideres* ml = new Menus::MenuLideres();
                mapaEstados.insert(std::make_pair(idEstados::TabelaLideres, static_cast<Estado*>(ml)));
            }
        }

        mapaEstados[estadoAtual]->setAtivo(true);
    }

    void GerenciadorEstados::setNumJogs(const unsigned int i)
    {
        numJogs = i;
    }

    void GerenciadorEstados::excluirEstado(idEstados id)
    {
        if(mapaEstados.count(id) != 0)
        {
            delete mapaEstados[id];
            mapaEstados.erase(id);
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
            case idEstados::Vitoria:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuVitoria*>(getEstadoAtual()));
                break;
            case idEstados::Derrota:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuDerrota*>(getEstadoAtual()));
                break;
            case idEstados::Pause:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuPausa*>(getEstadoAtual()));
                break;
            case idEstados::SalvarNome:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuSalvar*>(getEstadoAtual()));
                break;
            case idEstados::TabelaLideres:
                return static_cast<Ente*>(dynamic_cast<Menus::MenuLideres*>(getEstadoAtual()));
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
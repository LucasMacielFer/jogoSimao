#include "../../include/estados/Estado.h"
#include "../../include/estados/GerenciadorEstados.h"

namespace Estados
{
    GerenciadorEstados* Estado::pGEstados(GerenciadorEstados::getInstancia());

    Estado::Estado(idEstados id):
    identificador(id),
    ativo(false)
    {
    }

    Estado::Estado():
    identificador(idEstados::Indefinido),
    ativo(false)
    {
    }

    Estado::~Estado()
    {
        identificador = idEstados::Indefinido;
        ativo = false;
    }

    const bool Estado::getAtivo() const
    {
        return ativo;
    }

    const idEstados Estado::getIdentificador() const
    {
        return identificador;
    }

    void Estado::modificarEstado(idEstados id)
    {
        if(id != identificador && id != idEstados::Indefinido)
        {
            pGEstados->mudarEstado(id);
            ativo = false;
        }
    }
}
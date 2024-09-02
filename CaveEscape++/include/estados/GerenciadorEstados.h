#pragma once

#include <map>
#include "Estado.h"
#include <iostream>

class Ente;

namespace Estados
{
    class GerenciadorEstados
    {
        private:
            // Padrão de projeto singleton
            static GerenciadorEstados* pInstancia;
            std::map<idEstados, Estado*> mapaEstados;
            idEstados estadoAtual;
            int numJogs;

        private:
            GerenciadorEstados();

        public:
            ~GerenciadorEstados();
            void mudarEstado(idEstados id);
            void setNumJogs(const unsigned int i);
            void excluirEstado(idEstados id);
            Estado* getEstadoAtual();
            Ente* getEnteAtual();
            void executar(float dt);
            static GerenciadorEstados* getInstancia();
    };
}
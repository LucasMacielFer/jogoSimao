#pragma once

#include <stack>
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
            std::stack<Estado*> pilhaEstados;

        private:
            GerenciadorEstados();

        public:
            ~GerenciadorEstados();
            void empilharEstado(idEstados id);
            void desempilharEstado();
            Estado* getEstadoAtual();
            Ente* getEnteAtual();
            void executar(float dt);
            static GerenciadorEstados* getInstancia();
    };
}
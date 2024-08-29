#pragma once

namespace Estados
{
    enum idEstados
    {
        Indefinido = -1,
        Principal = 0,
        Jogando1,
        Jogando2,
        Pause,
        TabelaLideres
    };

    class GerenciadorEstados;

    class Estado
    {
        private:
            static GerenciadorEstados* pGEstados;
            idEstados identificador;
            bool ativo;
        
        public:
            Estado(idEstados id);
            Estado();
            virtual ~Estado();
            void setAtivo(const bool at);
            const bool getAtivo() const;
            const idEstados getIdentificador() const;
            void modificarEstado(idEstados id);
            void voltarAnterior();
            virtual void executar(float dt) = 0;
    };
}
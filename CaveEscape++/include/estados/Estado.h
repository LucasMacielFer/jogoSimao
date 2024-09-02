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
        SelecaoFase,
        TabelaLideres,
        SalvarNome,
        Derrota,
        Vitoria
    };

    class GerenciadorEstados;

    class Estado
    {
        protected:
            static GerenciadorEstados* pGEstados;
            idEstados identificador;
            bool ativo;
            static int pontJ1;
            static int pontJ2;
        
        public:
            Estado(idEstados id);
            Estado();
            virtual ~Estado();
            const bool getAtivo() const;
            const idEstados getIdentificador() const;
            void modificarEstado(idEstados id);
            virtual void setAtivo(const bool at) = 0;
            virtual void executar(float dt) = 0;
    };
}
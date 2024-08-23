#pragma once

#include <fstream>
#include "nlohmann/json.hpp"
#include "listas/ListaEntidades.h"

// O carregamento de mapas através de tilemaps no formato JSON foi implementado
// Baseado nos códigos da equipe do PETECO. Disponível em: 

class CriadorMapas
{
    private:
        nlohmann::json mapa;

    public:
        CriadorMapas(std::string tilemap);
        ~CriadorMapas();
        void carregarMapa(std::string tilemap);
        void criarMapa(Listas::ListaEntidades* lista, int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC);
        Entidades::Entidade* criarEntidade();
};
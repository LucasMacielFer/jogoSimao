#include "../include/CriadorMapas.h"

CriadorMapas::CriadorMapas(std::string tilemap)
{
    mapa.clear();
    carregarMapa(tilemap);
}

CriadorMapas::~CriadorMapas()
{
    mapa.clear();
}

void CriadorMapas::carregarMapa(std::string tilemap)
{
    std::ifstream arquivo(tilemap);
    
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}

void CriadorMapas::criarMapa(Listas::ListaEntidades* lista, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC)
{
}

Entidades::Entidade* CriadorMapas::criarEntidade()
{
    return NULL;
}
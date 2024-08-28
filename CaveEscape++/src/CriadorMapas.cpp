#include "../include/CriadorMapas.h"

CriadorMapas::CriadorMapas(std::string tilemap):
tamMapa(-1)
{
    carregarMapa(tilemap);
}

CriadorMapas::~CriadorMapas()
{
    tamMapa = -1;
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

void CriadorMapas::criarChao(Listas::ListaEntidades* lista)
{
// Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int heightTiled = mapa["tileheight"];
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    int posX = 0;
    int posY = 0;
    int indice = 0;
    int contOcorrencias = 0;
    int contTamanho = 0;

    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId == CODIGO_CHAO)
            {
                posX = x * sizeTiled;
                posY = y * heightTiled;
                lista->acrescentarEntidade(static_cast<Entidades::Entidade*>(criarEntidade(posX, posY, tileId)));
            }
        }
    }
    tamMapa = (width-1)*sizeTiled;
}

void CriadorMapas::criarTipoGrande(Listas::ListaEntidades* lista, const int idMapa, const bool* ocorrencias, const int max)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int heightTiled = mapa["tileheight"];
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    int posX = 0;
    int posY = 0;
    int indice = 0;
    int contOcorrencias = 0;
    int contTamanho = 0;

    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId == idMapa && contOcorrencias < max)
            {
                posX = x * sizeTiled;
                posY = y * heightTiled;

                if(ocorrencias[contOcorrencias])
                {
                    lista->acrescentarEntidade(static_cast<Entidades::Entidade*>(criarEntidade(posX, posY, tileId)));
                }
                else
                {
                    if(tileId == CODIGO_GOSMA)
                        lista->acrescentarEntidade(static_cast<Entidades::Entidade*>(criarEntidade(posX, posY, CODIGO_CHAO)));
                }
                if(contTamanho++ >= 3)
                {
                    contTamanho = 0;
                    contOcorrencias++;
                }
            }
        }
    }
}

void CriadorMapas::criarTipo(Listas::ListaEntidades* lista, const int idMapa, const bool* ocorrencias, const int max)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int heightTiled = mapa["tileheight"];
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    int posX = 0;
    int posY = 0;
    int indice = 0;
    int contOcorrencias = 0;

    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId == idMapa && contOcorrencias < max)
            {
                posX = x * sizeTiled;
                posY = y * heightTiled;
                

                if(ocorrencias[contOcorrencias])
                {
                    lista->acrescentarEntidade(static_cast<Entidades::Entidade*>(criarEntidade(posX, posY, tileId)));
                }
                contOcorrencias++;
            }
        }
    }
}

const int CriadorMapas::getTamMapa() const
{
    return tamMapa;
}

Entidades::Entidade* CriadorMapas::criarEntidade(const int posX, const int posY, const int tipo)
{
    switch(tipo)
    {
        case CODIGO_CHAO:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, true);
            break;

        case CODIGO_PLATAFORMA:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, false);
            break;

        case CODIGO_GOSMA:
            return new Entidades::Obstaculos::Gosma("assets/textures/gosma.png", 0.3, posX, posY);
            break;

        case CODIGO_ESPINHO:
            return new Entidades::Obstaculos::Espinho("assets/textures/espinho.png", 10, posX, posY);
            break;

        case CODIGO_LOBISOMEM:
            return new Entidades::Personagens::Lobisomem("assets/textures/lobisomem.png", posX, posY);
            break;

        case CODIGO_ESQUELETO:
            return new Entidades::Personagens::Esqueleto("assets/textures/esqueleto.png", posX, posY);
            break;

        case CODIGO_MAGO:
            return new Entidades::Personagens::Mago("assets/textures/mago.png", posX, posY);
            
        default:
            return NULL;
            break;
    }
}
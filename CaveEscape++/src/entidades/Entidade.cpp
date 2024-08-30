#include "../../include/entidades/Entidade.h"

namespace Entidades
{
    void Entidade::atualizaTextura()
    {
        retangulo.setTexture(textura);
    }

    Entidade::Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const float vel):
    Ente(i, txt),
    tamX(tamXX),
    tamY(tamYY),
    x(xx + tamX/2.0f),
    y(yy + tamY/2.0f),
    maxVelocidade(vel),
    velocidade(vel),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(1),
    caminhoTextura(txt),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setTexture(textura);
    } 

    Entidade::Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy):
    Ente(i, txt),
    tamX(tamXX),
    tamY(tamYY),
    x(xx + tamX/2.0f),
    y(yy + tamY/2.0f),
    maxVelocidade(0.0f),
    velocidade(0.0f),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(0),
    caminhoTextura(txt),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setTexture(textura);
    } 

    // Sobrecarga para o projetil
    Entidade::Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel):
    Ente(i, txt),
    tamX(tamXX),
    tamY(tamYY),
    x(xx + tamX/2.0f),
    y(yy + tamY/2.0f),
    maxVelocidade(vel),
    velocidade(vel),
    velocidadeX(vel),
    velocidadeY(0.0f),
    sentidoMovX(sentMovX),
    caminhoTextura(txt),
    retangulo(sf::Vector2f(tamXX, tamYY))
    {
        retangulo.setOrigin(tamX / 2.0f, tamY / 2.0f);
        retangulo.setPosition(x, y);
        retangulo.setTexture(textura);
    }

    Entidade::Entidade():
    Ente(idEntes::Indefinido),
    tamX(0),
    tamY(0),
    x(0),
    y(0),
    maxVelocidade(0.0f),
    velocidade(0.0f),
    velocidadeX(0.0f),
    velocidadeY(0.0f),
    sentidoMovX(0),
    caminhoTextura(),
    retangulo()
    {
    }

    Entidade::~Entidade()
    {
        x = -1;
        y = -1;
    }

    void Entidade::setTamanho(const float xx, const float yy)
    {
        tamX = xx;
        tamY = yy;
    }

    //Mudar para sf::Vector2f v = {tamX, tamY};
    const sf::Vector2f Entidade::getTamanho() const
    {
        sf::Vector2f v = {tamX, tamY};
        return v;
    }

    void Entidade::setPosicao(const float xx, const float yy)
    {
        x = xx;
        y = yy;
    }

    const sf::Vector2f Entidade::getPosicao() const 
    {
        sf::Vector2f v = {x, y};
        return v;
    }

    void Entidade::setVelocidade(const float vel)
    {
        if(vel > 0)
            velocidade = vel;
        else
            velocidade = 0;
    }

    const float Entidade::getVelMax() const
    {
        return maxVelocidade;
    }

    void Entidade::movimentaX(const float s)
    {
        sentidoMovX = s;
        if(s <= 1 && s >= -1) {velocidadeX = s*velocidade;}
    }

    // Implementação da gravidade baseada no jogo Desert++, do monitor Matheus Burda
    // Disponível em: https://github.com/MatheusBurda/Desert/tree/4d1ec28610a4675cfa3defc2a1aac12f28ffad2b
    void Entidade::aplicaGravidade(float dt)
    {
        velocidadeY += GRAVIDADE*dt;
    }

    void Entidade::aplicaGravidade(float dt, float sustentacao)
    {
        if(GRAVIDADE > sustentacao)
        {
            velocidadeY += (GRAVIDADE - sustentacao);
        }
    }

    void Entidade::desenhar(sf::RenderWindow& janela)
    {
        janela.draw(retangulo);
    }

    void Entidade::mover()
    {
        x += velocidadeX;
        y += velocidadeY;
        atualizaEntidade();
    }

    void Entidade::atualizaEntidade()
    {
        retangulo.setPosition(x, y);
    }

    std::string Entidade::getSalvamento() const
    {
        return salvamento;
    }

    void Entidade::salvar(const char* caminhoSalvamento)
    {
        salvamento += " ";
        salvamento += std::to_string(getId());
        salvamento += " ";
        salvamento += caminhoTextura;
        salvamento += " ";
        salvamento += std::to_string(tamX);
        salvamento += " ";
        salvamento += std::to_string(tamY);
        salvamento += " ";
        salvamento += std::to_string(x);
        salvamento += " ";
        salvamento += std::to_string(y);
        salvamento += " ";
        salvamento += std::to_string(velocidade);
        salvamento += " ";
        salvamento += std::to_string(maxVelocidade);
        salvamento += " ";
        salvamento += std::to_string(velocidadeX);
        salvamento += " ";
        salvamento += std::to_string(velocidadeY);
        salvamento += " ";
        salvamento += std::to_string(sentidoMovX);
    }
}
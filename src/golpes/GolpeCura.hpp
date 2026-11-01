#ifndef GOLPECURA_HPP
#define GOLPECURA_HPP
#include"Golpe.hpp" //aqui inclui diretamente o arquivo pois herda atributos e metodos da classe Golpe

class GolpeCura : public Golpe {
    private:
    int poder;
    int quantidade; //qnt de cura

    public:
    GolpeCura (std::string nome , int poder , int quantidade );
    virtual ~GolpeCura();
    std::string aplicar ( Pokemon &atacante , Pokemon &alvo ) override;


};





#endif
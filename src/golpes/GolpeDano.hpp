#ifndef GOLPEDANO_HPP
#define GOLPEDANO_HPP
#include"Golpe.hpp" //aqui inclui diretamente o arquivo pois herda atributos e metodos da classe Golpe

class GolpeDano : public Golpe {
private:
    int poder;

public:

    //construtor
    GolpeDano (std::string nome, int poder );
    
    virtual ~GolpeDano();
    
    //aplica o dano
    std::string aplicar(Pokemon &atacante , Pokemon &alvo ) override; //sobrescreve o metodo da classe abstrata

};
#endif
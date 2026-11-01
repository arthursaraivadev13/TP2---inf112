#ifndef GOLPEREDUCAOATAQUE_HPP
#define GOLPEREDUCAOATAQUE_HPP
#include"Golpe.hpp" //aqui inclui diretamente o arquivo pois herda atributos e metodos da classe Golpe

class GolpeReducaoAtaque : public Golpe {
private:

int poder;

public:
GolpeReducaoAtaque (std::string nome , int poder) ;
virtual ~GolpeReducaoAtaque();
std::string aplicar ( Pokemon &atacante , Pokemon &alvo ) override ;

};

#endif
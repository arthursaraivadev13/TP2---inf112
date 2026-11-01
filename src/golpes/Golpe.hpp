#ifndef GOLPE_HPP
#define GOLPE_HPP
#include<string>
class Pokemon; //apenas informa que a classe existe

class Golpe {
protected:
//classes derivadas herdarão e poderão acessar esses metódos e variáveis

std::string nome; //nome que será herdado

// Metodo protegido :
int calcularDano ( Pokemon & atacante , Pokemon & alvo , int poder);



public:
//construtor
Golpe (std::string nome ) ;
//destrutor
virtual ~Golpe ();

std::string getNome() ;
virtual std::string aplicar(Pokemon &atacante , Pokemon &alvo ) = 0; //metodo abstrato -> sera sobrescrito pelas classes derivadas


};





#endif
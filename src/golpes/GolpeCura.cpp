#include"GolpeCura.hpp" 
#include"Pokemon.hpp"

GolpeCura::GolpeCura(std::string nome, int poder, int quantidade)
:Golpe(nome), poder(poder), quantidade(quantidade){} //usa o construtor da classe Golpe + atributos especificos de GolpeCura

GolpeCura::~GolpeCura(){}

std::string GolpeCura::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoFinal = calcularDano(atacante, alvo, this->poder);
    int danoEfetivo = alvo.perderVida(danoFinal);
    int curaEfetiva = atacante.curar(this->quantidade); //Aplica a cura com base na quantidade fornecida

    return atacante.getNome() + " usou " + getNome() + " e causou " +  std::to_string(danoEfetivo) + " de dano e recuperou " + std::to_string(curaEfetiva) + " de vida!";
}


           
           
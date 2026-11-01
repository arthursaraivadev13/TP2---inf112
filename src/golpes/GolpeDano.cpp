#include"GolpeDano.hpp"
#include"Pokemon.hpp"

GolpeDano::GolpeDano(std::string nome, int poder)
:Golpe(nome), poder(poder){} //usa o construtor de golpe abstrato + o poder do golpe de dano

GolpeDano::~GolpeDano(){}

std::string GolpeDano::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoFinal = calcularDano(atacante, alvo, this->poder);
    int danoEfetivo = alvo.perderVida(danoFinal);

    return atacante.getNome() + " usou " + getNome() + " e causou " + std::to_string(danoEfetivo) + " de dano!";
}




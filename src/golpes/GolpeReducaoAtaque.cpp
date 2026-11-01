#include "GolpeReducaoAtaque.hpp"
#include "Pokemon.hpp"

GolpeReducaoAtaque::GolpeReducaoAtaque(std::string nome, int poder) 
    : Golpe(nome), poder(poder) {}

GolpeReducaoAtaque::~GolpeReducaoAtaque() {}

std::string GolpeReducaoAtaque::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoFinal = calcularDano(atacante, alvo, this->poder);
    int danoEfetivo = alvo.perderVida(danoFinal);

    std::string msg = atacante.getNome() + " usou " + getNome() + " e causou " + std::to_string(danoEfetivo) + " de dano!";

    //Se o alvo ainda estiver vivo, reduz o ataque dele em 8
    if (!alvo.derrotado()) {
        alvo.reduzirAtaque(8);
        msg += " O ataque de " + alvo.getNome() + " foi reduzido!";
    }

    return msg;
}




#include "PokemonEletrico.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    // Principal (dano: poder 12) | Secundário (redução: poder 6)
    definirGolpe(0, new GolpeDano("Choque do Trovão", 12));
    definirGolpe(1, new GolpeReducaoAtaque("Onda de Choque", 6));
}

PokemonEletrico::~PokemonEletrico() {}

int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") mult = 1.0;
    else if (tipoAtacante == "agua") mult = 0.5;
    else if (tipoAtacante == "eletrico") mult = 1.0;
    else if (tipoAtacante == "planta") mult = 1.0;

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}


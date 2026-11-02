#include "PokemonFogo.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    // Principal (dano: poder 12) | Secundário (redução: poder 6)
    definirGolpe(0, new GolpeDano("Lança-Chamas", 12));
    definirGolpe(1, new GolpeReducaoAtaque("Rugido", 6));
}

PokemonFogo::~PokemonFogo() {}

int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") mult = 1.0;
    else if (tipoAtacante == "agua") mult = 2.0;
    else if (tipoAtacante == "eletrico") mult = 1.0;
    else if (tipoAtacante == "planta") mult = 0.5;

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}

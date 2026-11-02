#include "PokemonPlanta.hpp"
#include "GolpeDano.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    // Principal (dano: poder 12) | Secundário (cura: poder 6, cura 5)
    definirGolpe(0, new GolpeDano("Chicote de Vinha", 12));
    definirGolpe(1, new GolpeCura("Sintese", 6, 5));
}

PokemonPlanta::~PokemonPlanta() {}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") mult = 2.0;
    else if (tipoAtacante == "agua") mult = 0.5;
    else if (tipoAtacante == "eletrico") mult = 1.0;
    else if (tipoAtacante == "planta") mult = 1.0;

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}


#ifndef POKEMON_AGUA_HPP
#define POKEMON_AGUA_HPP

#include "Pokemon.hpp"

class PokemonAgua : public Pokemon {
public:
    PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonAgua();

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif


#ifndef POKEMON_FOGO_HPP
#define POKEMON_FOGO_HPP

#include "Pokemon.hpp"

class PokemonFogo : public Pokemon {
public:
    PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonFogo();

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif


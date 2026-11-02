#ifndef POKEMON_PLANTA_HPP
#define POKEMON_PLANTA_HPP

#include "Pokemon.hpp"

class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonPlanta();

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif


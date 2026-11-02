#ifndef POKEMON_ELETRICO_HPP
#define POKEMON_ELETRICO_HPP

#include "Pokemon.hpp"

class PokemonEletrico : public Pokemon {
public:
    PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonEletrico();

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif


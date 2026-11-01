#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <string>

class Pokemon;
class Item;

class Treinador {
private:
    std::string nome;
    Pokemon* equipe[3];
    Item* itens[2];
    int ativo;

public:
    Treinador(std::string nome, int pokemons[3]);
    virtual ~Treinador();

    std::string getNome() const;
    Pokemon* getPokemon(int indice) const;
    Pokemon* getAtivo() const;
    Item* getItem(int indice) const;
    int getIndiceAtivo() const;

    bool trocar(int indice);
    bool perdeu() const;
    bool usarItem(int item, int alvo);
};

#endif
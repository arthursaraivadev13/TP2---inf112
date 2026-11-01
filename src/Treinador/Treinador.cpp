#include "Treinador.hpp"
#include "Pokemon.hpp"
#include "PokemonFogo.hpp"
#include "PokemonAgua.hpp"
#include "PokemonPlanta.hpp"
#include "PokemonEletrico.hpp"
#include "Item.hpp"
#include "Cura.hpp"
#include "Fortificante.hpp"

#include <fstream>
#include <iostream>

Treinador::Treinador(std::string nome, int pokemons[3])
    : nome(nome), ativo(0) {
    std::cout << "[DEBUG] Criando treinador: " << nome << std::endl;

    for (int i = 0; i < 3; i++) {
        this->equipe[i] = nullptr;
    }

    this->itens[0] = new Cura();
    this->itens[1] = new Fortificante();

    // Tenta abrir o pokemons.txt no diretorio atual e no relativo
    std::ifstream arquivo("pokemons.txt");
    if (!arquivo.is_open()) arquivo.open("lib/pokemons.txt");
    if (!arquivo.is_open()) arquivo.open("../pokemons.txt");

    if (!arquivo.is_open()) {
        std::cerr << "[ERRO CRITICO] Nao foi possivel abrir pokemons.txt!" << std::endl;
        return;
    }

    int id, vida, ataque, defesa;
    std::string tipo, nomePoke;

    while (arquivo >> id >> tipo >> nomePoke >> vida >> ataque >> defesa) {
        for (int i = 0; i < 3; i++) {
            if (pokemons[i] == id) {
                if (tipo == "fogo") {
                    this->equipe[i] = new PokemonFogo(nomePoke, id, vida, ataque, defesa);
                } else if (tipo == "agua") {
                    this->equipe[i] = new PokemonAgua(nomePoke, id, vida, ataque, defesa);
                } else if (tipo == "planta") {
                    this->equipe[i] = new PokemonPlanta(nomePoke, id, vida, ataque, defesa);
                } else if (tipo == "eletrico") {
                    this->equipe[i] = new PokemonEletrico(nomePoke, id, vida, ataque, defesa);
                }

                if (this->equipe[i] != nullptr) {
                    std::cout << "  -> Carregado Posicao " << i << ": " << nomePoke << " (ID " << id << ")" << std::endl;
                }
            }
        }
    }
    arquivo.close();
}

Treinador::~Treinador() {
    for (int i = 0; i < 3; i++) {
        if (this->equipe[i] != nullptr) {
            delete this->equipe[i];
            this->equipe[i] = nullptr;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (this->itens[i] != nullptr) {
            delete this->itens[i];
            this->itens[i] = nullptr;
        }
    }
}

std::string Treinador::getNome() const {
    return this->nome;
}

Pokemon* Treinador::getPokemon(int indice) const {
    if (indice >= 0 && indice < 3) {
        return this->equipe[indice];
    }
    return nullptr;
}

Pokemon* Treinador::getAtivo() const {
    if (this->ativo >= 0 && this->ativo < 3) {
        return this->equipe[this->ativo];
    }
    return nullptr;
}

Item* Treinador::getItem(int indice) const {
    if (indice >= 0 && indice < 2) {
        return this->itens[indice];
    }
    return nullptr;
}

int Treinador::getIndiceAtivo() const {
    return this->ativo;
}

bool Treinador::trocar(int indice) {
    if (indice < 0 || indice >= 3) return false;
    if (indice == this->ativo) return false;
    if (this->equipe[indice] == nullptr || this->equipe[indice]->derrotado()) return false;

    this->ativo = indice;
    return true;
}

bool Treinador::perdeu() const {
    for (int i = 0; i < 3; i++) {
        if (this->equipe[i] != nullptr && !this->equipe[i]->derrotado()) {
            return false;
        }
    }
    return true;
}

bool Treinador::usarItem(int item, int alvo) {
    if (item < 0 || item >= 2 || alvo < 0 || alvo >= 3) {
        return false;
    }

    Item* it = this->itens[item];
    Pokemon* p = this->equipe[alvo];

    if (it == nullptr || p == nullptr) {
        return false;
    }

    if (it->usar(*p)) {
        delete this->itens[item];
        this->itens[item] = nullptr;
        return true;
    }

    return false;
}
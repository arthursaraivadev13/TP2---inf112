#include "Pokemon.hpp"
#include "Golpe.hpp"

//Construtor
// Construtor: inicializa os atributos na mesma ordem em que foram declarados no .hpp
Pokemon::Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo)
    : nome(nome),
      tipo(tipo),               
      idPokemon(idPokemon),
      vida(vida),
      vidaMaxima(vida),         // vida máxima começa igual à vida inicial
      ataque(ataque),
      defesa(defesa),
      reducaoProximoAtaque(0),  // nenhum efeito temporário ativo
      fortalecido(false) {
    // Golpes começam vazios; as subclasses chamam definirGolpe() para preenchê-los
    this->golpes[0] = nullptr;
    this->golpes[1] = nullptr;
}

//Destrutor
Pokemon::~Pokemon() {
    if (this->golpes[0] != nullptr) {
        delete this->golpes[0];
        this->golpes[0] = nullptr;
    }
    if (this->golpes[1] != nullptr) {
        delete this->golpes[1];
        this->golpes[1] = nullptr;
    }
}

std::string Pokemon::getNome() {
    return this->nome;
}

int Pokemon::getIdPokemon() {
    return this->idPokemon;
}

int Pokemon::getVida() {
    return this->vida;
}

int Pokemon::getVidaMaxima() {
    return this->vidaMaxima;
}

int Pokemon::getAtaque() {
    return this->ataque;
}

int Pokemon::getDefesa() {
    return this->defesa;
}

std::string Pokemon::getTipo() {
    return this->tipo;
}

bool Pokemon::derrotado() {
    return this->vida == 0;
}

Golpe* Pokemon::getGolpe(int indice) { //indica qual golpe é o principal e qual é o secundario
    if (indice == 0 || indice == 1) {
        return this->golpes[indice];
    }
    return nullptr;
}

void Pokemon::definirGolpe(int indice, Golpe* golpe) {
    if (indice == 0 || indice == 1) {
        if (this->golpes[indice] != nullptr) {
            delete this->golpes[indice];
        }
        this->golpes[indice] = golpe;
    } else {
        // Se o índice for inválido, libera o golpe recebido sem alterar os existentes
        if (golpe != nullptr) {
            delete golpe;
        }
    }
}

int Pokemon::perderVida(int quantidade) {
    if (quantidade <= 0) return 0;

    int vidaAnterior = this->vida;
    this->vida -= quantidade;

    if (this->vida < 0) {
        this->vida = 0;
    }

    return vidaAnterior - this->vida; //Quantidade efetivamente perdida
}

int Pokemon::curar(int quantidade) {
    // Pokémon sem vida ou quantidade inválida não pode ser curado
    if (derrotado() || quantidade <= 0) {
        return 0;
    }

    int vidaAnterior = this->vida;
    this->vida += quantidade;

    if (this->vida > this->vidaMaxima) { //impede curar alem da vida maxima
        this->vida = this->vidaMaxima;
    }

    return this->vida - vidaAnterior; // Quantidade efetivamente recuperada
}

void Pokemon::reduzirAtaque(int quantidade) {
    if (quantidade > 0) {
        this->reducaoProximoAtaque = quantidade;
    }
}

int Pokemon::consumirReducaoAtaque() {
    int reducao = this->reducaoProximoAtaque;
    this->reducaoProximoAtaque = 0;
    return reducao;
}

bool Pokemon::fortalecer() {
    if (derrotado() || this->fortalecido) {
        return false;
    }
    this->fortalecido = true;
    return true;
}

double Pokemon::consumirFortalecimento() {
    if (this->fortalecido) {
        this->fortalecido = false;
        return 1.1;
    }
    return 1.0;
}
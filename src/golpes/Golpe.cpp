#include "Golpe.hpp"
#include "../pokemon/Pokemon.hpp"
#include <cmath> 
#include<algorithm>

//construtor
Golpe::Golpe(std::string nome)
: nome(nome){}

//destrutor
Golpe::~Golpe(){}

std::string Golpe::getNome(){
    return this->nome;
}

//não implementa o aplicar pelo fato de Golpe ser uma classe abstrata e apenas define o metodo virtual que sera realmente aplicado pelas classes derivadas

int Golpe::calcularDano ( Pokemon &atacante , Pokemon &alvo , int poder){
    int danoBase = std::max(1, poder + atacante.getAtaque() - alvo.getDefesa());

    // Caso o atacante esteja sob efeito de redução de ataque, diminui em 8 (até o mínimo de 0)
    int reducao = atacante.consumirReducaoAtaque();
    danoBase = std::max(0, danoBase - reducao);

    //Calcula o multiplicador com base no tipo usando a função da classe pokemon
    int danoTipo = alvo.calcularDanoRecebido(danoBase, atacante.getTipo());

    //Aplica fortalecimento
    double fortalecimento = atacante.consumirFortalecimento(); // 1.1 ou 1.0
    int danoFinal = std::max(1, static_cast<int>(std::round(danoTipo * fortalecimento)));

    return danoFinal;
}


#include"Fortificante.hpp"
#include"Pokemon.hpp"

Fortificante::Fortificante()
:Item("Fortificante"){} //utiliza o construtor da classe abstrata e atribui o nome do item

Fortificante::~Fortificante(){}

bool Fortificante::usar(Pokemon &alvo){
    return alvo.fortalecer(); //chama a função de fortalecer da classe pokemon
}
#include"Item.hpp"

Item::Item(std::string nome)
: nome(nome){}

Item::~Item(){

}

std::string Item:: getNome(){
    return this->nome;
}

//nao implementa metodo usar pois é uma classe abstrata que só define o metodo
#include"Cura.hpp"
#include"Pokemon.hpp"


Cura::Cura() : 
Item("Cura"){} //utiliza o construtor Item() da classe abstrata e inicializa ele com o nome do item de cura

Cura::~Cura(){}

bool Cura:: usar(Pokemon &alvo){
    if(alvo.getVida()>=alvo.getVidaMaxima()){ //impede que cure alem da vida maxima
        return false; 
    }
    if (alvo.derrotado())  //olha se o pokemon ja foi derrotado
        return false;

    alvo.curar(20); //cura 20 de vida chamando a funcao de cura
    return true;

}





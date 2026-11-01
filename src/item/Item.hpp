#ifndef ITEM_HPP
#define ITEM_HPP
#include<string>

class Pokemon; //apenas informa que a classe existe

class Item {
private:

std::string nome;

public:
//construtor
Item (std::string nome); 
//destrutor
virtual ~Item ();
std::string getNome () ;
virtual bool usar (Pokemon &alvo ) = 0;
};



#endif
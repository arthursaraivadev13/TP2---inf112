#ifndef CURA_HPP
#define CURA_HPP
#include"Item.hpp"

class Cura : public Item {
private:


public:

Cura(); //não recebe nada porque ja herda o construtor de item que recebe o nome do item
virtual ~Cura();
bool usar (Pokemon &alvo )override;

};


#endif
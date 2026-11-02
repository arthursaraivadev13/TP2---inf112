#ifndef FORTIFICANTE_HPP
#define FORTIFICANTE_HPP
#include"Item.hpp"

class Fortificante:public Item{
    private:

    public:
    Fortificante();
    virtual ~Fortificante();
    bool usar (Pokemon &alvo) override ;
};



#endif
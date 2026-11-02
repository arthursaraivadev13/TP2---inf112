#ifndef POKEMON_HPP
#define POKEMON_HPP

#include<string>
class Golpe;  //apenas informa que a classe exist
class Pokemon {

private:

std::string nome;
std::string tipo;
int idPokemon;
int vida;
int vidaMaxima;
int ataque;
int defesa;
int reducaoProximoAtaque;
bool fortalecido;
Golpe* golpes[2]; //Golpe é outra classe, portanto serve como objeto da classe pokemon, cada pokemon tem dois golpes



public:

Pokemon ( std::string nome , int idPokemon , int vida , int ataque , int defesa , std::string tipo ) ;
virtual ~Pokemon () ;

std::string getNome () ;
int getIdPokemon () ;
int getVida () ;
int getVidaMaxima () ;
int getAtaque () ;
int getDefesa () ;
std::string getTipo () ;
bool derrotado () ;

Golpe * getGolpe (int indice ) ;
void definirGolpe ( int indice , Golpe * golpe ) ;

int perderVida (int quantidade ) ;
int curar (int quantidade ) ;
void reduzirAtaque ( int quantidade ) ;
int consumirReducaoAtaque () ;

bool fortalecer () ;
double consumirFortalecimento () ;

virtual int calcularDanoRecebido ( int dano , std::string tipoAtacante ) = 0;

};

#endif
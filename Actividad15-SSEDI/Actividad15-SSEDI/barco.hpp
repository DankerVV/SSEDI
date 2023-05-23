//  barco.hpp
//  Actividad15-SSEDI
//  Created by Carlos Salcido on 29/11/21.
#ifndef barco_hpp
#define barco_hpp
#include "guerrero.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

class Barco{
public:
    Barco(){};
    Barco(const string &ID, float combustible, float velocidad, float armadura, int num_guerreros):
    ID(ID), combustible(combustible), velocidad(velocidad), armadura(armadura), num_guerreros(num_guerreros){}
    
    void setID(const string &ID);
    string getID() const;
    
    void setCombustible(float combustible);
    float getCombustible();
    
    void setVelocidad(float velocidad);
    float getVelocidad();
    
    void setArmadura(float armadura);
    float getArmadura();
    
    void setNum_Guerreros(int num_guerreros);
    int getNum_Guerreros() const;
    
    
    ///////////////////////////////////GUERRERO/////////////////////////////////////////////
    void agregarGuerrero(const Guerrero &g);
    void eliminarGuerrero();
    void topeGuerrro();
    void mostrarGuerreros();
    void aumentarGuerreros();
    void decrementarGuerreros();
    
    
    friend ostream& operator <<(ostream &out, const Barco &b)
    {
        out << left;
        out << setw(14) << b.ID;
        out << setw(14) << b.combustible;
        out << setw(14) << b.velocidad;
        out << setw(14) << b.armadura;
        out << setw(14) << b.num_guerreros;
        
        return out;
    }
    
private:
    string ID;
    float combustible;
    float velocidad;
    float armadura;
    int num_guerreros;
    stack<Guerrero> guerreros;
};


#endif /* barco_hpp */

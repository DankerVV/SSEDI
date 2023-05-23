//  guerrero.hpp
//  Actividad15-SSEDI
//  Created by Carlos Salcido on 29/11/21.
#ifndef guerrero_hpp
#define guerrero_hpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace  std;

class Guerrero{
public:
    Guerrero(){};
    Guerrero(const string &ID, int salud, float fuerza, float escudo, const string &tipo):
    ID(ID), salud(salud), fuerza(fuerza), escudo(escudo), tipo(tipo){}
    
    void setID(const string &ID);
    string getID() const;
    
    void setSalud(int salud);
    int getSalud() const;
    
    void setFuerza(float fuerza);
    float getFuerza() const;
    
    void setEscudo(float escudo);
    float getEscudo() const;
    
    void setTipo(const string &tipo);
    string getTipo() const;
    
    
    friend ostream& operator <<(ostream &out, const Guerrero &g)
    {
        out << left;
        out << setw(10) << g.ID;
        out << setw(10) << g.salud;
        out << setw(10) << g.fuerza;
        out << setw(10) << g.escudo;
        out << setw(10) << g.tipo;
        
        return out;
    }
    
private:
    string ID;
    int salud;
    float fuerza;
    float escudo;
    string tipo;
};


#endif /* guerrero_hpp */

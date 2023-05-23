//  aldeano.hpp
//  Actividad13-SSEDI
//  Created by Carlos Salcido on 17/11/21.
#ifndef aldeano_hpp
#define aldeano_hpp
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
public:
    Aldeano() {}
    Aldeano(const string &nombre, int edad, const string &genero, int salud):
    nombre(nombre), edad(edad), genero(genero), salud(salud){}
    
    void setNombre(const string &nombre);
    string getNombre() const;
    
    void setEdad(int edad);
    int getEdad() const;
    
    void setGenero(const string &genero);
    string getGenero();
    
    void setSalud(int salud);
    int getSalud() const;
    
    friend ostream& operator <<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(12) << a.nombre;
        out << setw(6) << a.edad;
        out << setw(12) << a.genero;
        out << setw(6) << a.salud;
        
        return out;
    }
    
    bool operator<(const Aldeano &a) const
    {
        return nombre < a.nombre;
    }
    
private:
    string nombre;
    int edad;
    string genero;
    int salud;
};


#endif /* aldeano_hpp */

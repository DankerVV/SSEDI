//  barco.cpp
//  Actividad15-SSEDI
//  Created by Carlos Salcido on 29/11/21.
#include "barco.hpp"
using namespace std;

void Barco::setID(const string &ID)
{
    this -> ID = ID;
}

string Barco::getID() const
{
    return ID;
}


void Barco::setCombustible(float combustible)
{
    this -> combustible = combustible;
}

float Barco::getCombustible()
{
    return combustible;
}


void Barco::setVelocidad(float velocidad)
{
    this -> velocidad = velocidad;
}

float Barco::getVelocidad()
{
    return velocidad;
}


void Barco::setArmadura(float armadura)
{
    this -> armadura = armadura;
}

float Barco::getArmadura()
{
    return armadura;
}

void Barco::setNum_Guerreros(int num_guerreros)
{
    this-> num_guerreros = num_guerreros;
}

int Barco::getNum_Guerreros() const
{
    return num_guerreros;
}


///////////////////////////////////GUERRERO/////////////////////////////////////////////
void Barco::agregarGuerrero(const Guerrero &g)//agregar Guerrero al barco
{
    guerreros.push(g);
}

void Barco::eliminarGuerrero()//Eliminar un Guerrero
{
    if(guerreros.size()>0){
        guerreros.pop();
    }
}

void Barco::topeGuerrro()//Mostrar el Tope de la pila de Guerreros
{
    cout << left;
    cout << setw(10) << "ID";
    cout << setw(10) << "Salud";
    cout << setw(10) << "Fuerza";
    cout << setw(10) << "Escudo";
    cout << setw(10) << "Tipo";
    cout << endl;
    cout << guerreros.top() << endl;
}

void Barco::mostrarGuerreros()
{
    stack<Guerrero> copia(guerreros);
    cout << left;
    cout << setw(10) << "ID";
    cout << setw(10) << "Salud";
    cout << setw(10) << "Fuerza";
    cout << setw(10) << "Escudo";
    cout << setw(10) << "Tipo";
    cout << endl;
    while (!copia.empty()) {
        auto const &e = copia.top();
        cout<< e << endl;
        copia.pop();
    }
}

void Barco::aumentarGuerreros()
{
    num_guerreros = num_guerreros + 1;
}

void Barco::decrementarGuerreros()
{
    if(num_guerreros > 0){
        num_guerreros = num_guerreros -1;
    }
}

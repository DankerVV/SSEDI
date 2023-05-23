//  guerrero.cpp
//  Actividad15-SSEDI
//  Created by Carlos Salcido on 29/11/21.
#include "guerrero.hpp"

void Guerrero::setID(const string &ID)
{
    this -> ID = ID;
}

string Guerrero::getID() const
{
    return ID;
}


void Guerrero::setSalud(int salud)
{
    this -> salud = salud;
}

int Guerrero::getSalud() const
{
    return salud;
}


void Guerrero::setFuerza(float fuerza)
{
    this -> fuerza = fuerza;
}

float Guerrero::getFuerza() const
{
    return fuerza;
}


void Guerrero::setEscudo(float escudo)
{
    this -> escudo = escudo;
}

float Guerrero::getEscudo() const
{
    return escudo;
}


void Guerrero::setTipo(const string &tipo)
{
    this -> tipo = tipo;
}

string Guerrero::getTipo() const
{
    return tipo;
}

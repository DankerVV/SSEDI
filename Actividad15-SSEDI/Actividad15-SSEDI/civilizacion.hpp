//  civilizacion.hpp
//  Actividad12-SSEDI
//  Created by Carlos Salcido on 05/11/21.
#ifndef civilizacion_hpp
#define civilizacion_hpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "aldeano.hpp"
#include <list>
#include "barco.hpp"

using namespace std;

class Civilizacion
{
    string nombre;
    int ubi_x;
    int ubi_y;
    int puntuacion;
    list<Aldeano> aldeanos;
    list<Barco*> puerto;
    
public:
    Civilizacion();
    Civilizacion(const string &nombre,
                int ubi_x,
                int ubi_y,
                int puntuacion);
    void setNombre(const string &vg);
    string getNombre();
    void setUbi_x(int vg);
    int getUbi_x();
    void setUbi_y(int vg);
    int getUbi_y();
    void setPuntuacion(int vg);
    int getPuntuacion();
    
    ///////////////////////////////////ALDEANOS/////////////////////////////////////////////
    //agregar y print
    void agregarInicio(const Aldeano &a);
    void agregarFinal(const Aldeano &a);
    void agregarPuntos();
    void print();
    
    //eliminar
    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(int salud);
    
    //ordenar
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    
    //buscar
    void buscar_ald(const string &nombre);
    
    //modificar
    void modificar_ald(const string &nombre);
    
    //respaldar y recuperar
    void respaldar_aldeanos();
    void recuperar_aldeanos();
    
    
    ///////////////////////////////////PUERTO/////////////////////////////////////////////
    void agregarBarco(Barco *b);
    void mostrarBarcos();
    Barco* buscarBarco(const string &ID);
    void eliminarBarcoID(const string &ID);
    void eliminarBarcoCombustible(float combustible);
    
    
    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(14) << c.nombre;
        out << setw(8) << c.ubi_x;
        out << setw(8) << c.ubi_y;
        out << setw(12) << c.puntuacion;
        out << endl;
        return out;
    }
    
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        //getline (cin, c.nombre); //Esto lo tiene Orlando y no se porqué
        cout << "Nombre: ";
        getline(cin, c.nombre);
        
        cout << "Ubicación en X: ";
        cin >> c.ubi_x;
        
        cout << "Ubicación en Y: ";
        cin >> c.ubi_y;
        
        cout << "Puntuación: ";
        cin >> c.puntuacion;
        return in;
    }
    
    bool operator == (const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    
    bool operator == (const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }
    
    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }
    
    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
};




///////////////////////////////////USUARIO////////////////////////////////////////////
class Usuario
{
    string nombre_usuario;
public:
    Usuario();
    Usuario(const string &nombre_usuario);
    void setNombre_usuario(const string &vg);
    string getNombre_usuario();
    
    friend ostream& operator<<(ostream &out, const Usuario &u)
    {
        out << left;
        out << setw(16) << u.nombre_usuario;
        out << endl;
        return out;
    }
    
    friend istream& operator>>(istream &in, Usuario &u)
    {
        cout << "Nombre de Usuario: ";
        getline(cin, u.nombre_usuario);
        
        return in;
    }
};
#endif /* civilizacion_hpp */


//  civilizacion.cpp
//  Actividad12-SSEDI
//  Created by Carlos Salcido on 05/11/21.
#include "civilizacion.hpp"
#include <fstream>
#include <vector>

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre,
                         int ubi_x,
                         int ubi_y,
                         int puntuacion)
{
    this -> nombre = nombre;
    this -> ubi_x = ubi_x;
    this -> ubi_y = ubi_y;
    this -> puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &vg){
    nombre = vg;
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setUbi_x(int vg){
    ubi_x = vg;
}

int Civilizacion::getUbi_x(){
    return ubi_x;
}

void Civilizacion::setUbi_y(int vg){
    ubi_y = vg;
}
int Civilizacion::getUbi_y(){
    return ubi_y;
}

void Civilizacion::setPuntuacion(int vg){
    puntuacion = vg;
}
int Civilizacion::getPuntuacion(){
    return puntuacion;
}


///////////////////////////////////ALDEANOS/////////////////////////////////////////////
void Civilizacion::agregarInicio(const Aldeano &a)//Agregar aldeano al inicio
{
    //cout<<puntuacion<<endl;
    aldeanos.push_front(a);
    //puntuacion = puntuacion + 100;
    //cout<<puntuacion<<endl;
}

void Civilizacion::agregarFinal(const Aldeano &a)//Agregar aldeano al final
{
    aldeanos.push_back(a);
    //puntuacion = puntuacion + 100;
}

void Civilizacion::agregarPuntos()
{
    puntuacion = puntuacion + 100;
}

void Civilizacion::print()//Imprimir aldeanos
{
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(6) << "Edad";
    cout << setw(12) << "Género";
    cout << setw(6) << "Salud";
    cout << endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)//Eliminar aldeano por nombre
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)//Comparador para poder eliminar aldeano por edad
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()//Eliminar aldeano por edad
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarSalud(int salud)//Eliminar aldeano por salud
{
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

void Civilizacion::ordenarNombre()//Ordenar aldeanos por nombre
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()//Ordenar aldeanos por edad
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud()//Ordenar aldeanos por salud
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::buscar_ald(const string &nombre)//Buscar aldeano por nombre
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            cout << left;
            cout << setw(12) << "Nombre";
            cout << setw(6) << "Edad";
            cout << setw(12) << "Género";
            cout << setw(6) << "Salud";
            cout << endl;
            cout<<*it<<endl;
            break;
        }
    }
}

void Civilizacion::modificar_ald(const string &nombre)//Modificar aldeano por nombre
{
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            cout << "\nAldeano encontrado, ingresa los nuevos datos:\n";
            Aldeano a;
            string nombre;
            int edad;
            string genero;
            int salud;
            
            cout << "Nombre: ";
            getline(cin, nombre);
            a.setNombre(nombre);

            cout << "Edad: ";
            cin >> edad; cin.ignore();
            a.setEdad(edad);
            
            cout << "Género: ";
            getline(cin, genero); // cin.ignore();
            a.setGenero(genero);
            
            cout << "Salud: ";
            cin >> salud; cin.ignore();
            a.setSalud(salud);
            
            *it = a;
            
            break;
        }
    }
}

void Civilizacion::respaldar_aldeanos()//Respaldar aldeanos en archivos.txt
{
    ofstream archivo2("/Users/carlossalcidoa/Desktop/" + getNombre() + ".txt", ios::out);
    for (auto it2 = aldeanos.begin(); it2 != aldeanos.end(); ++it2) {
        Aldeano &aldeano = *it2;
        archivo2 << aldeano.getNombre() << endl;
        archivo2 << aldeano.getEdad()   << endl;
        archivo2 << aldeano.getGenero() << endl;
        archivo2 << aldeano.getSalud()  << endl;
        }
    archivo2.close();
}

void Civilizacion::recuperar_aldeanos()//Recuperar aldeanos de los archivos.txt
{
    ifstream archivo2("/Users/carlossalcidoa/Desktop/" + getNombre() + ".txt", ios::out);
    if(archivo2.is_open()){
        string temp;
        int edad;
        int salud;
        Aldeano a;
        puntuacion = 0;
        while(true){
            getline(archivo2, temp);
            if (archivo2.eof()){
                break;
            }
            a.setNombre(temp);
            
            getline(archivo2, temp);
            edad = stoi(temp);
            a.setEdad(edad);
            
            getline(archivo2, temp);
            a.setGenero(temp);
            
            getline(archivo2, temp);
            salud = stoi(temp);
            a.setSalud(salud);
            
            agregarFinal(a);
            agregarPuntos();
        }
        archivo2.close();
    }
}


///////////////////////////////////PUERTO/////////////////////////////////////////////
void Civilizacion::agregarBarco(Barco *b)
{
    puerto.push_back(b);
}

void Civilizacion::mostrarBarcos()
{
    cout << left;
    cout << setw(14) << "ID";
    cout << setw(14) << "Combustible";
    cout << setw(14) << "Velocidad";
    cout << setw(14) << "Armadura";
    cout << setw(14) << "Guerreros";
    cout << endl;
    for(auto it = puerto.begin(); it!= puerto.end(); it++){
        auto &e = *it;
        cout<< *e << endl;
    }
}

Barco* Civilizacion::buscarBarco(const string &ID)
{
    for(auto it = puerto.begin(); it!= puerto.end(); it++){
        Barco *b = *it;
        if(ID == b->getID()){
            return (*it);
            break;
        }
    }
    return nullptr;
}

void Civilizacion::eliminarBarcoID(const string &ID)
{
    int aux=0;
    for(auto it = puerto.begin(); it!= puerto.end(); it++){
        Barco *b = *it;
        if(ID == b->getID()){
            aux++;
            cout<<"Barco eliminado\n";
            puerto.erase(it);
            break;
        }
    }
    if(aux==0){
        cout<<"No se encontró un barco con ese ID\n";
    }
}

void Civilizacion::eliminarBarcoCombustible(float combustible)
{
    puerto.remove_if([combustible](Barco *b){return b->getCombustible() < combustible;});
    cout<<"Se han eliminado los barcos con combustible menor a "<<combustible<<"\n";
}


///////////////////////////////////USUARIO////////////////////////////////////////////
Usuario::Usuario(){}

Usuario::Usuario(const string &nombre_usuario)
{
    this -> nombre_usuario = nombre_usuario;
}

void Usuario::setNombre_usuario(const string &vg){
    nombre_usuario = vg;
}

string Usuario::getNombre_usuario(){
    return nombre_usuario;
}

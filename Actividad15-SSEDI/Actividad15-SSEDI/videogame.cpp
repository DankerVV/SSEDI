//  videogame.cpp
//  Actividad12-SSEDI
//  Created by Carlos Salcido on 05/11/21.
#include "videogame.hpp"
#include "civilizacion.hpp"
#include "aldeano.hpp"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame(){}

void VideoGame::agregarCivilizacion(const Civilizacion &c)//Agregar civilizacion
{
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)//Insertar civilizacion en una posicion
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n)//Inicializar n civilizaciones
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::primera_civ()//Imprimir la primera civilizacion
{
    cout << left;
    cout << setw(14) << "Civilización";
    cout << setw(8) << "Eje X";
    cout << setw(8) << "Eje Y";
    cout << setw(12) << "Puntuación";
    cout << endl;
    
    Civilizacion &c = civilizaciones.front();
    cout << c;
}

void VideoGame::ultima_civ()//Imprimir la ultima civilizacion
{
    cout << left;
    cout << setw(14) << "Civilización";
    cout << setw(8) << "Eje X";
    cout << setw(8) << "Eje Y";
    cout << setw(12) << "Puntuación";
    cout << endl;
    
    Civilizacion &c = civilizaciones.back();
    cout << c;
}

void VideoGame::ordenar_nombre()//Ordenar civilizaciones por nombre
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

void VideoGame::ordenar_x()//Ordenar civilizaciones por eje x
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getUbi_x() < c2.getUbi_x();});
}

void VideoGame::ordenar_y()//Ordenar civilizaciones por eje y
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getUbi_y() < c2.getUbi_y();});
}

void VideoGame::ordenar_punt()//Ordenar civilizaciones por puntuacion
{
    sort(civilizaciones.begin(), civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminar(const Civilizacion &c)//Eliminar una civilizacion por nombre
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    
    if (it == civilizaciones.end()){
        cout<<"No se encontró";
    }
    else{
        civilizaciones.erase(it);
        cout<<endl;
    }
}

size_t VideoGame::size()//Tamaño del vector civilizaciones
{
    return civilizaciones.size();
}

void VideoGame::mostrar()//Imprimir civilizaciones en forma de tabla
{
    cout << left;
    cout << setw(14) << "Civilización";
    cout << setw(8) << "Eje X";
    cout << setw(8) << "Eje Y";
    cout << setw(12) << "Puntuación";
    cout << endl;
    
    
   // int &j = i;
    for(size_t i=0; i<civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
    //for(auto it = civilizaciones.begin(); it != civilizaciones.end(); it++){
        //cout << *it << endl;}
}


Civilizacion* VideoGame::buscar(const Civilizacion &c)//Buscar civilizaciones por nombre
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    
    if (it == civilizaciones.end()){
        return nullptr;
    }
    else{
        cout << endl;
        return &(*it);
    }
}

void VideoGame::modificar(const Civilizacion &c)//Modificar civilizaciones por nombre
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    
    if (it == civilizaciones.end()){
        cout<<"No se encontró";
    }
    else{
        Civilizacion c;
        cin>>c; cin.ignore();
        
        *it = c;
    }
}

void VideoGame::respaldar_civilizacion()//Respaldar las civilizaciones y llamar la función para respaldar aldeanos en archivo .txt
{
    ofstream archivo("/Users/carlossalcidoa/Desktop/civilizaciones.txt");
    for(auto it = civilizaciones.begin(); it != civilizaciones.end(); ++it){
        Civilizacion &civilizacion = *it;
        archivo << civilizacion.getNombre() << endl;
        archivo << civilizacion.getUbi_x() << endl;
        archivo << civilizacion.getUbi_y() << endl;
        archivo << civilizacion.getPuntuacion() << endl;
        
        civilizacion.respaldar_aldeanos();
    }
    archivo.close();
}

void VideoGame::recuperar_civilizacion()//Recuperar los datos de las civilizaciones en sus archivos .txt
{
    civilizaciones.erase(civilizaciones.begin(), civilizaciones.end());
    ifstream archivo("/Users/carlossalcidoa/Desktop/civilizaciones.txt");
    string temp;
    int x;
    int y;
    int puntos;
    Civilizacion c;
    while(true){
        getline(archivo, temp);
        if (archivo.eof()){
            break;
        }
        c.setNombre(temp);
        
        getline(archivo, temp);
        x = stoi(temp);
        c.setUbi_x(x);
        
        getline(archivo,temp);
        y = stoi(temp);
        c.setUbi_y(y);
        
        getline(archivo, temp);
        puntos = stoi(temp);
        c.setPuntuacion(puntos);
        
        agregarCivilizacion(c);
    }
    for(auto it = civilizaciones.begin(); it != civilizaciones.end(); ++it){
        Civilizacion &civilizacion = *it;
        civilizacion.recuperar_aldeanos();
    }
    archivo.close();
}

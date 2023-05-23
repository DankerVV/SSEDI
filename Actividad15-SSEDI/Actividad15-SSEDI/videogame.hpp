//  videogame.hpp
//  Actividad12-SSEDI
//  Created by Carlos Salcido on 05/11/21.
#ifndef videogame_hpp
#define videogame_hpp
#include <stdio.h>
#include <vector>
#include "civilizacion.hpp"
class VideoGame
{
    vector <Civilizacion> civilizaciones;
    vector <Usuario> usuarios;
    
public:
    VideoGame();
    void agregarCivilizacion(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void inicializar(const Civilizacion &c, size_t n);
    void primera_civ();
    void ultima_civ();
    void ordenar_nombre();
    void ordenar_x();
    void ordenar_y();
    void ordenar_punt();
    void eliminar(const Civilizacion &c);
    Civilizacion* buscar(const Civilizacion &c);
    void modificar(const Civilizacion &c);
    void mostrar();
    size_t size();//tamaño
    void respaldar_civilizacion();
    void recuperar_civilizacion();
        
    friend VideoGame& operator<<(VideoGame &vg, const Civilizacion &c)
    {
        vg.agregarCivilizacion(c);
        return vg;
    }
};
#endif /* videogame_hpp */

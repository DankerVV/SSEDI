//  main.cpp
//  Actividad12-SSEDI
//  Created by Carlos Salcido on 05/11/21.
#include <iostream>
#include "civilizacion.hpp"
#include "videogame.hpp"
#include "aldeano.hpp"
#include <vector>
#include "submenu.hpp"

int main() {
    VideoGame vg;
    //Civilizacion cv;
    vector <Civilizacion> civilizaciones;

    int opc, opc2;
    do{
        cout<<"Selecciona una opción: \n";
        cout<<"1)Nombre de Usuario\n";
        cout<<"2)Agregar Civilización\n";
        cout<<"3)Insertar Civilización\n";
        cout<<"4)Inicializar Civilizaciones\n";
        cout<<"5)Primera Civilización\n";
        cout<<"6)Última Civilización\n";
        cout<<"7)Ordenar\n";
        cout<<"8)Eliminar Civilización\n";
        cout<<"9)Buscar\n";
        cout<<"10)Modificar\n";
        cout<<"11)Resumen\n";
        cout<<"12)Respaldar\n";
        cout<<"13)Recuperar\n";
        cout<<"14)Acceder al Puerto\n";
        
        cout<<"0)Salir\n";
        cin>>opc;
        cin.ignore();//Es necesario cuando después de un int se lee un string, sino se genera un "bug"
        switch(opc){
            case 1:{ //Nombre de Usuario
                Usuario u;
                cin>>u;
                cout<<endl;
                break;}
                
            case 2:{//Agregar al inicio
                Civilizacion c;
                cin>>c;
                vg.agregarCivilizacion(c);
                cin.ignore();
                cout<<endl;
                break;
            }
                
            case 3:{//Insertar en cualquier punto
                Civilizacion c;
                cin>>c;
                
                size_t pos;
                cout << "Posición: ";
                cin>>pos; cin.ignore();
                
                if(pos >= vg.size()){
                    cout <<"Posición inválida\n";
                }
                else{
                    vg.insertar(c, pos);
                    cout<<endl;
                }
                    
                break;}
                
            case 4:{ //inicializar varias civilizaciones
                Civilizacion c;
                cin>>c;
                
                size_t n;
                cout << "Cantidad de veces: ";
                cin>>n; cin.ignore();
                
                vg.inicializar(c, n);
                cout<<endl;
                break;}
                
            case 5:{vg.primera_civ();//mostrar primera civilizacion
                cout<<endl;
                break;
            }
                
            case 6:{vg.ultima_civ();//mostrar ultima civilizacion
                cout<<endl;
                break;}
                
            case 7:{//ordenar de varias formas
                cout << "\t1)Ordenar por nombre\n";
                cout << "\t2)Ordenar por eje X\n";
                cout << "\t3)Ordenar por eje Y\n";
                cout << "\t4)Ordenar por Puntuación\n";
                cout << "\t0)Cancelar\n";
                cin>>opc2; cin.ignore();
                switch(opc2){
                    case 1:{vg.ordenar_nombre();
                        vg.mostrar();
                        cout<<endl;
                        break;
                    }
                        
                    case 2:{
                        vg.ordenar_x();
                        vg.mostrar();
                        cout<<endl;
                        break;
                    }
                        
                    case 3:{
                        vg.ordenar_y();
                        vg.mostrar();
                        cout<<endl;
                        break;
                    }
                        
                    case 4:{
                        vg.ordenar_punt();
                        vg.mostrar();
                        cout<<endl;
                        break;
                    }
                }
                break;
            }
                
            case 8:{//eliminar una civilizacion por su nombre
                cout<<"\nTeclea la civilización que quieres eliminar\n";
                Civilizacion c;
                cin>>c; cin.ignore();
                
                Civilizacion *ptr =vg.buscar(c);
            
                if(ptr == nullptr){
                    cout << "No se encontró esa civilización\n\n";
                    
                }
                else{
                    vg.eliminar(c);
                }
                break;
            }
                
                
                
            case 9:{//buscar una civilizacion por su nombre
                cout<<"\nTeclea la civilización que estás buscando\n";
                Civilizacion c;
                cin>>c; cin.ignore();
                
                Civilizacion *ptr = vg.buscar(c);
                
                if(ptr == nullptr){
                    cout << "No se encontró esa civilización\n\n";
                }
                else{
                    cout << left;
                    cout << setw(14) << "Civilización";
                    cout << setw(8) << "Eje X";
                    cout << setw(8) << "Eje Y";
                    cout << setw(12) << "Puntuación";
                    cout << endl;
                    cout << *ptr << endl;
                    
                    cout << "¿Quieres acceder a los aldeanos?\n1)Si\t2)No";//Acceder a los aldeanos
                    cin >> opc2;
                    cout<<endl;
                    if(opc2 == 1){
                        //Civilizacion &civilizacion = c;
                        submenu(*ptr);
                    }
                }
                
                break;
            }
                
                
                
            case 10:{//Modificar una civilización por su nombre
                cout<<"\nTeclea la civilización que quieres modificar\n";
                Civilizacion c;
                cin>>c; cin.ignore();
                
                Civilizacion *ptr = vg.buscar(c);
            
                if(ptr == nullptr){
                    cout << "No se encontró esa civilización\n\n";
                }
                else{
                    cout<<"Ingresa los datos nuevos: \n";
                    vg.modificar(c);
                    cout<<endl;
                }
                break;}
                
            case 11:{//mostrar todas las civilizaciones en forma de tabla
                cout<<endl;
                vg.mostrar();
                cout<<endl;
                break;}
                
            case 12:{//respaldar civilizaciones
                cout<<endl;
                vg.respaldar_civilizacion();
                break;}
                
            case 13:{//recuperar civilizaciones
                cout<<endl;
                vg.recuperar_civilizacion();
                break;}
                
                
            case 14:{//Acceder al puerto
                cout<<"\nTeclea la civilización a la que quieres acceder a su Puerto\n";
                Civilizacion c;
                cin>>c; cin.ignore();
                
                Civilizacion *ptr = vg.buscar(c);
                
                if(ptr == nullptr){
                    cout << "No se encontró esa civilización\n\n";
                }
                else{
                    cout << left;
                    cout << setw(14) << "Civilización";
                    cout << setw(8) << "Eje X";
                    cout << setw(8) << "Eje Y";
                    cout << setw(12) << "Puntuación";
                    cout << endl;
                    cout << *ptr << endl;
                    
                    submenu_puerto(*ptr);
                }
                
                break;

            }
        }
    }while(opc!=0);
    return 0;
}

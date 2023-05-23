//  submenu.hpp
//  Actividad13-SSEDI
//  Created by Carlos Salcido on 17/11/21.
#ifndef submenu_hpp
#define submenu_hpp
#include <stdio.h>
#include "civilizacion.hpp"


///////////////////////////////////ALDEANOS/////////////////////////////////////////////
Aldeano capturar()
{
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
    
    return a;
}



void submenu(Civilizacion &c)
{
    int opc3, opc4;
    do{
        cout<<"1)Agregar Aldeano\n";
        cout<<"2)Eliminar Aldeano\n";
        cout<<"3)Clasificar Aldeanos\n";
        cout<<"4)Buscar Aldeano\n";
        cout<<"5)Modificar Aldeano\n";
        cout<<"6)Mostrar Aldeanos\n";
        cout<<"0)Salir\n";
        cin>>opc3;
        switch(opc3)
        {
            case 1:{//agregar aldeano
                cout << "\t1)Agregar al inicio\n";
                cout << "\t2)Agregar al final\n";
                cout << "\t0)Cancelar\n";
                cin>>opc4; cin.ignore();
                        switch(opc4){
                            case 1:{//agregar aldeano al inicio
                                c.agregarInicio(capturar());
                                //cout<<c.getPuntuacion()<<endl;
                                //int x;
                                //x = c.getPuntuacion();
                                //cout<<x<<endl;
                                //x=x+100;
                                //cout<<x<<endl;
                                //c.setPuntuacion(x);
                                //cout<<c.getPuntuacion();
                                c.agregarPuntos();
                                cout<<endl;
                                break;}
                                            
                            case 2:{//agregar aldeano al final
                                c.agregarFinal(capturar());
                                c.agregarPuntos();
                                //sumar 100 puntos
                                cout<<endl;
                                break;}
                        }
                        break;}
                
            case 2:{//eliminar aldeano
                cout << "\t1)Eliminar por nombre\n";
                cout << "\t2)Eliminar por salud\n";
                cout << "\t3)Eliminar por edad (con 60 años o más)\n";
                cout << "\t0)Cancelar\n";
                cin>>opc4; cin.ignore();
                switch(opc4){
                    case 1:{//eliminar aldeano por nombre
                        string nombre;
                        cout<<"Nombre: ";
                        getline(cin, nombre);
                        c.eliminarNombre(nombre);
                        cout<<endl;
                        break;}
                        
                    case 2:{//eliminar aldeano por salud
                        int salud;
                        cout<<"Salud mínima: ";
                        cin>>salud; cin.ignore();
                        c.eliminarSalud(salud);
                        cout<<endl;
                        break;}
                                    
                    case 3:{//eliminar aldeano por edad
                        c.eliminarEdad();
                        cout<<endl;
                        break;}
                            }
                break;}

            case 3:{//clasificar aldeano
                cout << "\t1)Ordenar por nombre\n";
                cout << "\t2)Ordenar por salud\n";
                cout << "\t3)Ordenar por edad\n";
                cout << "\t0)Cancelar\n";
                cin>>opc4; cin.ignore();
                switch(opc4){
                    case 1:{
                        c.ordenarNombre();//ordenar aldeano por nombre
                        cout<<endl;
                        break;}
                                
                    case 2:{
                        c.ordenarSalud();//ordenar aldeano por salud
                        cout<<endl;
                        break;}
                                    
                    case 3:{
                        c.ordenarEdad();//ordenar aldeano por edad
                        cout<<endl;
                        break;}
                }
                break;}
                
                
            case 4:{//buscar aldeano
                string nombre;
                cout<<"Nombre: ";
                cin.ignore(); getline(cin, nombre);
                c.buscar_ald(nombre);
                cout<<endl;
                break;}
                        
            case 5:{//modificar aldeano
                string nombre;
                cout<<"Nombre del aldeano a modificar: ";
                cin.ignore(); getline(cin, nombre);
                c.modificar_ald(nombre);
                cout<<endl;
                break;}
                            
            case 6:{//mostrar aldeanos
                c.print();
                cout<<endl;
                 break;}
        }
    }while(opc3 != 0);
    cout<<endl;
}


///////////////////////////////////GUERRERO/////////////////////////////////////////////
//Guerrero
void capturarGuerrero(Barco &b)
{
    int opc;
    
    string ID;
    int salud;
    float fuerza;
    float escudo;
    string tipo;
    Guerrero g;
    
    cout<<"ID: ";
    getline(cin, ID);
    g.setID(ID);
    
    cout<<"Salud: ";
    cin>>salud;
    g.setSalud(salud);
    cin.ignore();
    
    cout<<"Fuerza: ";
    cin>>fuerza;
    g.setFuerza(fuerza);
    cin.ignore();
    
    cout<<"Escudo: ";
    cin>>escudo;
    g.setEscudo(escudo);
    cin.ignore();
    
    cout<<"Elige un tipo\n";
    cout<<"1)Espadachín\t2)Arquero\t3)Hechicero\t4)Fantasma";
    cin>>opc;
    cin.ignore();
    switch(opc){
        case 1:{//Guardar Espadachín
            tipo = "Espadachín";
            g.setTipo(tipo);
            break;
        }
            
        case 2:{//Guardar Arquero
            tipo = "Arquero";
            g.setTipo(tipo);
            break;
        }
            
        case 3:{//Guardar Hechicero
            tipo = "Hechicero";
            g.setTipo(tipo);
            break;
        }

        case 4:{//Guardar Fantasma
            tipo = "Fantasma";
            g.setTipo(tipo);
            break;
        }
    }
    b.agregarGuerrero(g);
}



///////////////////////////////////PUERTO/////////////////////////////////////////////
void capturarBarco(Civilizacion &c)
{
    string ID;
    float velocidad = 0.0;
    float armadura = 100.0;
    float combustible;
    int num_guerreros = 0;
    Barco *b = new Barco();
    
    cout<<"ID: ";
    getline(cin, ID);
    b->setID(ID);
    //cin.ignore();
    
    b->setVelocidad(velocidad);
    
    b->setArmadura(armadura);
        
    cout<<"Combustible: ";
    cin>>combustible;
    b->setCombustible(combustible);
    cin.ignore();
    
    b->setNum_Guerreros(num_guerreros);
    
    c.agregarBarco(b);
}


void submenu_puerto(Civilizacion &c)
{
    int opc3, opc4, opc5;
    do{
        cout<<"1)Agregar Barco\n";
        cout<<"2)Mostrar Barcos\n";
        cout<<"3)Buscar Barco\n";
        cout<<"4)Eliminar Barco\n";
        cout<<"0)Salir\n";
        cin>>opc3;
        cin.ignore();
        switch(opc3){
            case 1:{//Agregar un Barco al puerto
                capturarBarco(c);
                cout<<endl;
                break;
            }
                
                
            case 2:{//Mostrar todos los Barcos
                c.mostrarBarcos();
                cout<<endl;
                break;
            }
                
                
            case 3:{//Buscar un Barco por ID
                string ID;
                cout<<"Ingresa el ID del Barco que buscas: ";
                getline(cin, ID);
                Barco *ptr = c.buscarBarco(ID);
                if(ptr == nullptr){//Barco no encontrado
                    cout<<"No se encontró un barco con ese ID";
                    cout<<endl<<endl;
                }
                else{//Barco sí encontrado, acceso al menu de guerreros
                    cout << left;
                    cout << setw(14) << "ID";
                    cout << setw(14) << "Combustible";
                    cout << setw(14) << "Velocidad";
                    cout << setw(14) << "Armadura";
                    cout << setw(14) << "Guerreros";
                    cout << endl;
                    cout<<*ptr;
                    cout<<endl<<endl;
                    
                    cout<<"¿Acceder a los Guerreros?\n";
                    cout<<"1)Si\t2)No\n";
                    cin>>opc4;
                    if(opc4==1){
                        
                        do{//Menu de Guerreros                            
                            cout<<"1)Agregar Guerrero\n";
                            cout<<"2)Eliminar Guerrero\n";
                            cout<<"3)Mostrar Último Guerrero\n";
                            cout<<"4)Mostrar todos los Guerreros\n";
                            cout<<"0)Cancelar\n";
                            cin>>opc5;
                            cin.ignore();
                            switch(opc5){
                                case 1:{//Agregar un Guerrero al Barco
                                    capturarGuerrero(*ptr);
                                    ptr->aumentarGuerreros();
                                    cout<<endl;
                                    break;}
                                    
                                case 2:{//Eliminar al último Guerrero del Barco
                                    ptr->eliminarGuerrero();
                                    ptr->decrementarGuerreros();
                                    cout<<endl;
                                    break;
                                }
                                    
                                case 3:{//Imprimir al último Guerrero del Barco
                                    ptr->topeGuerrro();
                                    cout<<endl;
                                    break;
                                }
                                    
                                case 4:{//Mostrar todos los Guerreros del Barco
                                    ptr->mostrarGuerreros();
                                    cout<<endl;
                                    break;
                                }

                            }
                        }while(opc5!=0);
                        
                    }
                }
                
                break;
            }
                
                
            case 4:{//Eliminar un Barco por ID
                do{
                    cout<<"1)Eliminar por ID\n";
                    cout<<"2)Eliminar por Combustible\n";
                    cout<<"0)Salir";
                    cout<<endl;
                    cin>>opc4;
                    cin.ignore();
                    switch(opc4){
                        case 1:{//Eliminar un barco por ID
                            string ID;
                            cout<<endl<<"Escribe el ID del Barco que quieres eliminar: ";
                            getline(cin, ID);
                            c.eliminarBarcoID(ID);
                            cout<<endl;
                            break;
                        }
                            
                        case 2:{//Eliminar un barco por combustible mínimo
                            float combustible;
                            cout<<"Escribe el combustible mínimo: ";
                            cin>>combustible;
                            c.eliminarBarcoCombustible(combustible);
                            cout<<endl;
                            break;
                        }
                    }
                }while(opc4!=0);
                break;
            }
        }
        
        
    }while(opc3!=0);
}





#endif /* submenu_hpp */

#include <iostream>

using namespace std;

int menu(){
    int opcion;
    string nombre, nombre1, nombre2;

    while (true){

    system("CLS");

    cout << "Menu Principal"<<endl<<endl;
    cout <<"1.Juego Nuevo para un jugador"<<endl;
    cout <<"2.Juego Nuevo para dos jugadores"<<endl;
    cout <<"3.Puntuacion mas alta"<<endl;
    cout <<"4.Salir"<<endl<<endl;

    cout <<"opcion: ";

    cin >>opcion;


    switch(opcion){

        case 1:
            system ("CLS");
            cout<<"Ingrese el nombre del jugador"<<endl;
            cin >> nombre;
            system ("pause");
            break;
        case 2:
            system ("CLS");
            cout<<"Ingrese el nombre del jugador 1"<<endl;
            cin>> nombre1;
            cout<<"Ingrese el nombre del jugador 2"<<endl;
            cin>>nombre2;
            system ("pause");
            break;
        case 3:
            system ("CLS");
            cout<<"Puntuacion mas alta"<<endl;
            system ("pause");
            break;
        case 4:
            system ("CLS");
            cout<<"FIN DEL JUEGO"<<endl;
                 return 0;
            break;

        default:
            system ("CLS");
            cout<<"Opcion no valida"<<endl;
            system ("pause");
            break;
        }
    }

    return 0;
}

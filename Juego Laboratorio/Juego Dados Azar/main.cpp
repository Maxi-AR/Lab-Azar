#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>
#include "funciones.h"
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
#include <conio.h>
using namespace std;
using namespace rlutil;

int main(){
char vNombre[30];
srand(time(NULL));


     int a;

     tapaPrincipal();

     do{
         setlocale(LC_ALL, "spanish"); //Para los acentos.
         system("cls");

          cout<<endl;
          PresentacionMenu();
          gotoxy (50,10);cout<< "        GREED          "<<endl;
          gotoxy (50,11);cout<< "-----------------------"<<endl;
          gotoxy (50,12);cout<< "1 - MODO UN JUGADOR    "<<endl;
          gotoxy (50,13);cout<< "2 - MODO DOS JUGADORES "<<endl;
          gotoxy (50,14);cout<< "3 - ESTADÍSTICAS       "<<endl;
          gotoxy (50,15);cout<< "4 - CRÉDITOS           "<<endl;
          gotoxy (50,16);cout<< "-----------------------"<<endl;
          gotoxy (50,17);cout<< "0 - SALIR              "<<endl;
          gotoxy (50,18);cin>>a;
          cout<<endl;
          setlocale(LC_ALL, "C"); //Para el codigo ASCII
          switch(a){
             case 1:
              system("cls");

              opcion1();
              break;
             case 2:
             opcion2();
             break;
             case 3:
              system("cls");
              recuadroganador();
              mostrarMaximo();
              system("pause");
             break;
             case 4:
             system("cls");
             estadisticas();
             system("pause");
             break;

          }

       }while(a!=0);

     return 0;
    }

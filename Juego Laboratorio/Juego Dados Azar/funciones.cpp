#include "funciones.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "rlutil.h"
#include <conio.h>
#include <string.h>
using namespace std;
using namespace rlutil;
#include <ctype.h>


int totalMaximo =0 ;
char vNombreMax[30] = {};

int randomDados(){   //Funcion para girar los dados randon
int i,n,color;
for(i=1;i<100;i++){
       n=(rand()%6)+1;
    return n;
}
}

void cargarNombre(char *vNombre){ //Funcion para cargar el nombre del jugador
Presentaciondeljuego();
gotoxy (50,14);cout<<"Cargar Nombre: ";

cin.getline(vNombre, 30);

}


void tiradasJugador(int *vTirada,int dado1, int dado2){ //funcion para tirar los 5 dados del jugador
int i, x=25;
for(i=0;i<5;i++){
    if(vTirada[i]>=1){
    vTirada[i]=randomDados();
}
}
//for(i=0;i<5;i++){
//cout<<vTirada[i];}

for(i=0;i<5;i++){
msleep(500);
   if((vTirada[i]==dado1) || (vTirada[i]==dado2)){
     setColor(RED);
}
else setColor(WHITE);
dadosForma(vTirada[i],x, 18);
x+=14;
}}

int acumuladorPuntos(int dado1, int dado2, int *vTirada){ //Funcion para acumular los puntos del jugador Linea 11
int i,acu=0, cont=0,sum=0;
for(i=0;i<5;i++){
      if((vTirada[i]==dado1) || (vTirada[i]==dado2)){
         vTirada[i]=0;
         cont++;
          }
          else {acu+=vTirada[i];}
}

    for(i=0;i<5;i++){
   //  msleep(500);

     if(vTirada[i]>0){
         sum++;
        }
    setColor(rand () % 15 + 1);
//    cout<<vTirada[i]<<" "; //Linea 11
     setColor(WHITE);
}
//       cout<<" << Dados Sin Bloquear "<<sum;
       return acu;
}

int contarbloqueados(int *vTirada){ //Cuenta los dados bloqueados.
int i, cont=0;
for(i=0;i<5;i++){
      if(vTirada[i]==0){
         cont++;
          }
}
       return cont;
}

void mostrarRonda(int *vRonda){ //Funcion Para contar por ronda los puntos y los puntos totales.
setColor(WHITE);
int i, acum=0;
for(i=0;i<3;i++){
acum += vRonda[i];
}

}

void opcion1(){ //Funcion que tiene todas las funciones para 1 jugador

setColor(WHITE);
system("cls");
int vJugador1[3]={}, i,acu1=0,acu2=0, vJugador2[3]={};
char vNombre1[30]={};

cin.ignore();
    gotoxy (40,14);cargarNombre(vNombre1);


    for(i=0;i<3;i++){
     setBackgroundColor(CYAN);
   int acuPuntos=0,cont = 0,  acuronda=0;


   jugador(vJugador1,vNombre1,i, vJugador2, "MENU OPCION 2");

   }
   for(i=0;i<3;i++){
      acu1+=vJugador1[i];
   }
    system("cls");
   portada_final(acu1,vNombre1);
   //gotoxy (50,14);cout<<"El Ganador es: "<<vNombre1<<endl;
   //gotoxy (50,15);cout<<"Puntaje Total: "<<acu1<<endl;
    buscarMaximo(acu1, vNombre1);
      system("pause");
   }

void Presentaciondeljuego(){
for (int i=2 ; i <120 ; i++){

setColor(YELLOW); // color del texto.
msleep (10);// tiempo de espera.

// mueve horizontal segunda linea.
   gotoxy (i, 8);
    cout << "*";
//mueve vertical lineas de los costados.
    if (i < 26){

    gotoxy (2, i);
    cout << "*";
    gotoxy (120, i);
    cout << "*";
    }
//mueve vertical medio.
    //if (i>8 && i <26){
    //gotoxy (44 , i);
    //cout<< "=";
    //}
 // mueve horizontal pricipales.
    gotoxy (60, 4);// pos. nombre
    cout << "G R E E D";
    gotoxy (i, 2);
    cout << "*";
    gotoxy (i, 25);
cout << "*";
   }

setColor(WHITE);
for(int i=0;i<70;i++){
    gotoxy(30+i,16);cout <<(char)205;
}

for(int i=0;i<70;i++){
setColor(WHITE);
gotoxy (30+i, 13);cout <<(char)205;
}
gotoxy(40,29);cout<<"Push You Luck v1.1, (C) Copyright 1990, Bob Lancaster"<<endl;
}


void PresentacionMenu(){
for (int i=2 ; i <120 ; i++){
gotoxy (30, 3);// pos. nombre
 cout <<" ----------- ----------- ----------- ----------- -----------";
    gotoxy (30, 4);
    cout<< "| o          |         o |           |  o      o | o      o |";
    gotoxy (30, 5);
    cout<< "|     o      |           |     o     |           | o      o |";
     gotoxy (30, 6);
    cout<< "|         o  |   o       |           |  o      o | o      o |";
    gotoxy (30, 7);
    cout<< " ----------- ----------- ----------- ----------- ----------- ";


setColor(WHITE); // color del texto.
// tiempo de espera.

// mueve horizontal segunda linea.
   gotoxy (i, 8);
    cout << "*";
//mueve vertical lineas de los costados.
    //if (i < 26){

    //gotoxy (2, i);
    //cout << "=";
    //gotoxy (120, i);
    //cout << "=";

//mueve vertical medio.
    //if (i>8 && i <26){
    //gotoxy (44 , i);
    //cout<< "=";
    //}
 // mueve horizontal pricipales.


    gotoxy (i, 2);
    cout << "*";
    gotoxy (i, 25);

cout << "*";
   }
   gotoxy(40,29);cout<<"Push You Luck v1.1, (C) Copyright 1990, Bob Lancaster"<<endl;
   }

void dadosForma(int valor, int x, int y){  //Los 6 dados formados

   switch (valor){
    case 1:
    setBackgroundColor(BLACK);
    gotoxy(x, y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "|            | ";
    gotoxy (x,y+2);
    cout<< "|     o      | ";
     gotoxy (x, y+3);
    cout<< "|            | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

    case 2:
    gotoxy(x,y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "| o          | ";
    gotoxy (x, y+2);
    cout<< "|            | ";
     gotoxy (x, y+3);
    cout<< "|         o  | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

    case 3:
    gotoxy(x,y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "| o          | ";
    gotoxy (x, y+2);
    cout<< "|     o      | ";
     gotoxy (x, y+3);
    cout<< "|         o  | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

    case 4:
    gotoxy( x,y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "| o       o  | ";
    gotoxy (x, y+2);
    cout<< "|            | ";
     gotoxy (x, y+3);
    cout<< "| o       o  | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

    case 5:
    gotoxy(x,y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "| o       o  | ";
    gotoxy (x, y+2);
    cout<< "|     o      | ";
     gotoxy (x, y+3);
    cout<< "| o       o  | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

    case 6:
    gotoxy(x,y);
    cout <<" -----------   ";
    gotoxy (x, y+1);
    cout<< "| o       o  | ";
    gotoxy (x, y+2);
    cout<< "| o       o  | ";
     gotoxy (x, y+3);
    cout<< "| o       o  | ";
    gotoxy (x, y+4);
    cout<< " -----------   ";
    break;

   }
    }


void displayRonda(int *vRonda, int *vRonda1){
gotoxy (17,7);cout<<"Ronda 1: "<<vRonda[0]<<endl;
gotoxy (17,8);cout<<"Ronda 2: "<<vRonda[1]<<endl;
gotoxy (17,9);cout<<"Ronda 3: "<<vRonda[2]<<endl;
gotoxy (17,10);cout<<"______________"<<endl;
gotoxy (17,11);cout<<"Puntos totales: "<<vRonda[0]+vRonda[1]+vRonda[2]<<endl;

gotoxy (93,7);cout<<"Ronda 1: "<<vRonda1[0]<<endl;
gotoxy (93,8);cout<<"Ronda 2: "<<vRonda1[1]<<endl;
gotoxy (93,9);cout<<"Ronda 3: "<<vRonda1[2]<<endl;
gotoxy (93,10);cout<<"______________"<<endl;
gotoxy (93,11);cout<<"Puntos totales: "<<vRonda1[0]+vRonda1[1]+vRonda1[2]<<endl;

}


void jugador(int *vRonda, char *vNombre, int i,int *vRonda1, char *vNombre2){ //Funcion que controla la jugada por jugador. WHILE


   int acuPuntos=0,cont = 0, acuronda=0,  vTirada[5]={1,1,1,1,1}, dado1,dado2,acu=0;
int opc;
    dado1=randomDados();
    dado2=randomDados();


 while(cont<5){

system("cls");
recuadro_jugada();
setColor(WHITE);

displayRonda(vRonda, vRonda1);
    gotoxy (17,4);cout<<"Nombre: ";
    setColor(BLACK);
    gotoxy (17,5);cout<<vNombre;
    setColor(WHITE);
    msleep(500);

    gotoxy (93,4);cout<<"Nombre: ";
    setColor(BLACK);
    gotoxy (93,5);cout<<vNombre2;
    setColor(WHITE);
    msleep(500);

    setBackgroundColor(BLACK);

    gotoxy (46,8);dadosForma(dado1,46,8);
    msleep(500);
    gotoxy (46,9);dadosForma(dado2,60,8);


    gotoxy (50,9); tiradasJugador(vTirada,dado1,dado2); //Linea 9 codeblocks
    gotoxy (50,10); acuPuntos = acumuladorPuntos(dado1,dado2,vTirada);

     cont = contarbloqueados(vTirada);

    //gotoxy (50,12); cout<<"Contador de Dados Bloqueados: "<<cont;





     if(cont<5){
    vRonda[i]+=acuPuntos;

    setBackgroundColor(CYAN);
displayRonda(vRonda, vRonda1);
    gotoxy (43,25); cout<<(char)168<<"Desea seguir jugando? 1 Si - 2 No"<<endl;
    gotoxy (43,26); cout<<"                 ";cin>>opc;

///////////////VALIDACIONES

    while((opc!=1) && (opc!=2)){
        cout<<"incorrecto"<<endl;
        cin>>opc;
    }

    if(opc==2){
        cont=6;
    }
     }

    else vRonda[i]=0;
   setBackgroundColor(CYAN);
    }

    }


void opcion2(){ //Funcion para 2 Jugadores

setColor(WHITE);
 system("cls");
int vJugador1[3]={},vJugador2[3]={}, i,acu1=0,acu2=0;
char vNombre1[30]={}, vNombre2[30]={};

cin.ignore();
    gotoxy (40,14);cargarNombre(vNombre1);
    system("cls");
    gotoxy (40,14);cargarNombre(vNombre2);




    for(i=0;i<3;i++){
    setBackgroundColor(CYAN);
   int acuPuntos=0,cont = 0,  acuronda=0;


   jugador(vJugador1,vNombre1,i, vJugador2,vNombre2);

   jugador(vJugador2, vNombre2,i, vJugador1,vNombre1);
   }
   for(i=0;i<3;i++){
      acu1+=vJugador1[i];
     acu2+=vJugador2[i];
   }
   system("cls");
   if(acu1>acu2){
     portada_final(acu1,vNombre1);

      buscarMaximo(acu1, vNombre1);
     system("pause");
   }
   else {portada_final(acu2,vNombre2);

         buscarMaximo(acu2, vNombre2);
      system("pause");}
   }



void tapaPrincipal (){ //Inicio del Juego

system ("color 37");


gotoxy(45, 20);cout << "QUE LA FUERZA DE LOS DADOS TE ACOMPAÑE";
for (int color=15 ; color >=8 ; color--){

setColor (color);


       gotoxy(40, 10);
       cout<< (  "######   ########  ######## ######## ########   ")<<endl;
       gotoxy(40, 11);
        cout<< ( "##    ##  ##     ## ##       ##       ##     ## ")<<endl;
        gotoxy(40, 12);
       cout<< (  "##        ##     ## ##       ##       ##     ## ")<<endl;
       gotoxy(40, 13);
        cout<< ( "##   #### ########  ######   ######   ##     ## ")<<endl;
 setColor (color+3);
        gotoxy(40, 14);
        cout<< ( "##    ##  ##   ##   ##       ##       ##     ## ")<<endl;
        gotoxy(40, 15);
        cout<< ( "##    ##  ##    ##  ##       ##       ##     ## ")<<endl;
        gotoxy(40, 16);
        cout<< ( "######   ##     ## ######## ######## ########   ")<<endl;



setColor (color+1);
                gotoxy(56, 22);
               cout<<("     _______          ")<<endl;
               gotoxy(56, 23);
               cout<<( "    /   ()  \\         ")<<endl;
               gotoxy(56, 24);
               cout<<( "  __|_______|__       ")<<endl;
               gotoxy(56, 25);
               cout<<( " |  |       |  |      ")<<endl;
               gotoxy(56, 26);
               cout<<( " |__|       |__|      ")<<endl;
               gotoxy(56, 27);
               cout<<( "  | |       | |       ")<<endl;
               gotoxy(56, 28);
               cout<<( "  | |       | |       ")<<endl;
               gotoxy(56, 29);
               cout<<( " |~  \\______/ ~|      ")<<endl;
               gotoxy(56, 30);
               cout<< " /=\\   /=\\   /=\\ " << endl;
               gotoxy(56, 31);
               cout<<("_[_]___[_]___[_]____   ")<<endl;

msleep(300);


}

   }


void recuadro_jugada(){ //Plantilla de la parte jugable
int num;
setColor(WHITE);
//cls();

for (int i=2; i <120 ; i++){

   // Linea vertical superior.
   gotoxy(i,2);
   cout <<(char)205;
   // Linea vertical Inferior
    gotoxy (i, 28);
    cout <<(char)205;
    //Linea horizontal izquierda.
    if (i>2 && i<28){
    gotoxy (1, i);
    cout <<(char)186;
    }
    //Linea horizontal derecha.
    if (i>2 && i<28){
    gotoxy (120, i);
    cout <<(char)186;
    }

    //segunda linea horizontal (geed).
    if (i >= 46 && i <=74){
        gotoxy (i, 5);
        cout <<(char)205;

    }

    //ultima  linea horizontal (geed).


        gotoxy (i, 14);
        cout <<(char)205;




}

// esquinas las puse separadas para que el ciclo no las imprima muchas veces.

 gotoxy (1, 28);
printf("%c",200);
 gotoxy (1, 2);
printf("%c",201);
 gotoxy (120, 2);
printf("%c",187);
 gotoxy (120, 28);
printf("%c",188);

 // esquinas cuadro de (greed)
 gotoxy (45, 5);
 cout <<(char)204;
 gotoxy (75, 5);
 cout <<(char)185;
// texto GREDD
gotoxy (58 , 3);
cout << "GREED";
gotoxy (51 , 6);
cout << "DADOS BLOQUEADORES";
gotoxy (2 , 3);
cout << "JUGADOR ACTIVO";
gotoxy (76 , 3);
cout << "JUGADOR EN ESPERA...";


// esquinas cuadro de (greed) uiltimas
gotoxy (45, 14);
 cout <<(char)202;
 gotoxy (75, 14);
 cout <<(char)202;




// Cuadro medio superiror (geed)

 gotoxy (45, 2);
 cout <<(char)203;
 gotoxy (45, 3);
 cout <<(char)186;
gotoxy (45, 4);
 cout <<(char)186;
  gotoxy (45, 6);
 cout <<(char)186;
gotoxy (45, 7);
 cout <<(char)186;
  gotoxy (45, 8);
 cout <<(char)186;
gotoxy (45, 9);
 cout <<(char)186;
 gotoxy (45, 10);
 cout <<(char)186;
gotoxy (45, 11);
 cout <<(char)186;
gotoxy (45, 12);
 cout <<(char)186;
gotoxy (45, 13);
 cout <<(char)186;


//linea lado izquierdo
  gotoxy (75, 2);
 cout <<(char)203;
 gotoxy (75, 3);
 cout <<(char)186;
gotoxy (75, 4);
 cout <<(char)186;
gotoxy (75, 6);
 cout <<(char)186;
gotoxy (75, 7);
 cout <<(char)186;
gotoxy (75, 8);
 cout <<(char)186;
gotoxy (75, 9);
 cout <<(char)186;
gotoxy (75, 10);
 cout <<(char)186;
gotoxy (75, 11);
 cout <<(char)186;
gotoxy (75, 12);
 cout <<(char)186;
gotoxy (75, 13);
 cout <<(char)186;
gotoxy(40,29);cout<<"Push You Luck v1.1, (C) Copyright 1990, Bob Lancaster"<<endl;
//cin >> num; // para que puedas ver el cuadro
}

void buscarMaximo(int acu, char *vNombre){  //Maximo opcion 3

if(acu>totalMaximo){

    totalMaximo = acu;

    strcpy(vNombreMax,vNombre);
}

}

void mostrarMaximo(){
setColor(BLACK);
if(totalMaximo==0){
    gotoxy(50,14);cout<<"Todavia no hay un puntaje Maximo"<<endl<<endl<<endl<<endl<<endl;
}

else {gotoxy(50,14);cout<<"El Maximo Puntaje es de: "<<vNombreMax;
     gotoxy(50,15);cout<<"Con un total de: "<<totalMaximo<<endl<<endl<<endl<<endl<<endl;;}

}


void cuadro(int Vi, int Vf, int Hi, int Hf){ //Cuadro para crear nuevo dado
int i;
for(i=Vi; i<=Vf; i++)
{
gotoxy(i,Hi); printf("%c",205);//horizontal
gotoxy(i,Hf); printf("%c",205);//
}
for(i=Hi; i<=Hf; i++)
{

gotoxy(Vi,i);printf("%c",186);//vertical
gotoxy(Vf,i);printf("%c",186);//
}

gotoxy(Vi,Hi); printf("%c",201);//esquinero izq sup
gotoxy(Vf,Hi); printf("%c",187);//esquinero der sup
gotoxy(Vi,Hf); printf("%c",200);//esquinero izq inf
gotoxy(Vf,Hf); printf("%c",188);//esquinero der sup
}


void portada_final(int acu1, char *vNombre){ //Tapa para el ganador


system ("color 37");

   gotoxy (50,14);cout<<"El Ganador es: "<<vNombre<<endl;
   gotoxy (50,15);cout<<"Puntaje Total: "<<acu1<<endl;

for (int x=0; x<=3; x++){

for (int color=15 ; color >3 ; color--){

setColor (color);


gotoxy(7, 3);
cout<< ( "           _                              ")<<endl;
gotoxy(7, 4);
cout<< ( "          (_)                             ")<<endl;
gotoxy(7, 5);
cout<< ( "  __      ___ _ __  _ __   ___ _ __       ")<<endl;
gotoxy(7, 6);
cout<< ( "  \\ \\ /\\ / / | '_ \\| '_ \\ / _ \\ '__|")<<endl;
setColor (color+5);
gotoxy(7, 7);
cout<< ( "   \\ V  V /| | | | | | | |  __/ |        ")<<endl;
gotoxy(7, 8);
cout<< ( "    \\_/\\_/ |_|_| |_|_| |_|\\___|_|       ")<<endl;

setColor (color);

gotoxy(90, 21);
cout<< ( " __   __        __       ")<<endl;
gotoxy(90, 22);
cout<< ( "/  ` |__)  /\\  /  ` |__/ ")<<endl;
setColor (color+4);
gotoxy(90, 23);
cout<< ( "\\__, |  \\ /~~\\ \\__, |  \\ ")<<endl;

setColor (color+3);
gotoxy(6, 19);
cout<< ( "  _ __  _   _ _ __ __ _   ___  __ _ _ __   __ _ _ __ ___  ")<<endl;
gotoxy(6, 20);
cout<< ( " | '_ \\| | | | '__/ _` | / __|/ _` | '_ \\ / _` | '__/ _ \\ ")<<endl;
gotoxy(6, 21);
cout<< ( " | |_) | |_| | | | (_| | \\__ \\ (_| | | | | (_| | | |  __/ ")<<endl;
setColor (color+1);
gotoxy(6, 22);
cout<< ( " | .__/ \\__,_|_|  \\__,_| |___/\\__,_|_| |_|\\__, |_|  \\___| ")<<endl;
gotoxy(6, 23);
cout<< ( " | |                                       __/ |          ")<<endl;
gotoxy(6, 24);
cout<< ( " |_|                                      |___/           ")<<endl;

setColor (color+3);
gotoxy(65, 4);
cout<< ( "  _ __   _____   _____ _ __   _ __   ___  _ __  _   _  ")<<endl;
gotoxy(65, 5);
cout<< ( " | '_ \\ / _ \\ \\ / / _ \\ '__| | '_ \\ / _ \\| '_ \\| | | | ")<<endl;
gotoxy(65, 6);
cout<< ( " | | | |  __/\\ V /  __/ |    | |_) | (_) | | | | |_| | ")<<endl;
setColor (color+1);
gotoxy(65, 7);
cout<< ( " |_| |_|\\___| \\_/ \\___|_|    | .__/ \\___/|_| |_|\\__, | ")<<endl;
gotoxy(65, 8);
cout<< ( "                             | |                 __/ | ")<<endl;
gotoxy(65, 9);
cout<< ( "                             |_|                |___/  ")<<endl;

msleep(50);
}
}

}

void estadisticas(){ //CREDITOS

for (int color=15 ; color >=8 ; color--){

setColor (color);


       gotoxy(40, 3);
       cout<< (  "######   ########  ######## ######## ########   ")<<endl;
       gotoxy(40, 4);
        cout<< ( "##    ##  ##     ## ##       ##       ##     ## ")<<endl;
        gotoxy(40, 5);
       cout<< (  "##        ##     ## ##       ##       ##     ## ")<<endl;
       gotoxy(40, 6);
        cout<< ( "##   #### ########  ######   ######   ##     ## ")<<endl;
 setColor (color+3);
        gotoxy(40, 7);
        cout<< ( "##    ##  ##   ##   ##       ##       ##     ## ")<<endl;
        gotoxy(40, 8);
        cout<< ( "##    ##  ##    ##  ##       ##       ##     ## ")<<endl;
        gotoxy(40, 9);
        cout<< ( "######   ##     ## ######## ######## ########   ")<<endl;

msleep(300);

}
 setlocale(LC_ALL, "spanish");
setColor(WHITE);
gotoxy(50,12);cout<<"      CRÉDITOS";
gotoxy(50,13);cout<<"      --------";
gotoxy(50,15);cout<<"CREACIÓN Y DIRECCIÓN:";
gotoxy(50,16);cout<<"---------------------";
gotoxy(50,17);cout<<"Equipo CortoCircuito";
gotoxy(50,18);cout<<"21729 - Chozza, Maximiliano";
gotoxy(50,19);cout<<"24208 - Hoffman, Nicolas";
gotoxy(40,23);cout<<"FRGP - TUP - Profesores - Angel Simon/ Brian Lara"<<endl;
setlocale(LC_ALL, "C");
   }

void recuadroganador(){
       setColor(BLACK);
       gotoxy(40, 3);
       cout<< (  "######   ########  ######## ######## ########   ")<<endl;
       gotoxy(40, 4);
        cout<< ( "##    ##  ##     ## ##       ##       ##     ## ")<<endl;
        gotoxy(40, 5);
       cout<< (  "##        ##     ## ##       ##       ##     ## ")<<endl;
       gotoxy(40, 6);
        cout<< ( "##   #### ########  ######   ######   ##     ## ")<<endl;
        gotoxy(40, 7);
        cout<< ( "##    ##  ##   ##   ##       ##       ##     ## ")<<endl;
        gotoxy(40, 8);
        cout<< ( "##    ##  ##    ##  ##       ##       ##     ## ")<<endl;
        gotoxy(40, 9);
        cout<< ( "######   ##     ## ######## ######## ########   ")<<endl;

setColor(GREEN);
for(int i=0;i<70;i++){
    gotoxy(30+i,16);cout <<(char)205;
}

for(int i=0;i<70;i++){
setColor(GREEN);
gotoxy (30+i, 13);cout <<(char)205;
}


}

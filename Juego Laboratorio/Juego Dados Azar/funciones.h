#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Declaracion de la funcion Prototipos

int randomDados();
void cargarNombre(char *vNombre);
void tiradasJugador(int *vTirada, int dado1, int dado2);
int acumuladorPuntos(int dado1, int dado2, int *vTirada);
int contarbloqueados(int *vTirada);
void opcion1();
int main();
void Presentaciondeljuego();
void PresentacionMenu();
void dadosForma(int valor, int x, int y);
void jugador(int *vRonda, char *vNombre, int i, int *vRonda1, char *vNombre2);
void opcion2();
void tapaPrincipal();
void recuadro_jugada();
void buscarMaximo(int acu, char *vnombre);
void mostrarMaximo();
void portada_final(int acu1, char *vNombre);
void estadisticas();
void recuadroganador();
void displayRonda(int *vRonda, int *vRonda1);
#endif // FUNCIONES_H_INCLUDED


#ifndef CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#include "Control_grafico.h"
#include <iostream>
using namespace std;

class JUGADOR: public PERSONAJE{
    protected:
        int movimiento;
        int direccion;

        int sprite_personaje;

    public:

        ///---------------------Propio del padre---------------------
        ///Gets:

        int gets_posicion_x_guia();
        int gets_posicion_y_guia();
        int gets_posicion_x_juego();
        int gets_posicion_y_juego();

        ///Sets:

        void sets_posicion_completa(int x_guia, int y_guia, int x_juego, int y_juego);
        void sets_posicion_x_guia(int x_guia);
        void sets_posicion_y_guia(int y_guia);
        void sets_posicion_x_juego(int x_juego);
        void sets_posicion_y_juego(int y_juego);

        ///---------------------Propio del hijo---------------------
        JUGADOR(MAPA &mapa);
        void mover_en_mapa_guia();
        void mover_jugador(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);
        void rutina_de_accion(MAPA &mapa, int anterior_direccion, int x, int y, int x_ext, int y_ext);
        void eliminar_muro(MAPA &mapa, int anterior_direccion, int x, int y, int x_ext, int y_ext);

};

JUGADOR::JUGADOR(MAPA &mapa){

    sprite_personaje = AVATAR;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

void JUGADOR::rutina_de_accion(MAPA &mapa, int anterior_direccion, int x, int y, int x_ext, int y_ext){ ///SEGUN ULTIMO BOTON APRETADO DE DIRECCION

///hasta aca las cosas sucedieron como correspondian.


if (key[KEY_SPACE]){
/// se detecta la key
       eliminar_muro(mapa, anterior_direccion, x, y, x_ext, y_ext);
    }
  /*  else if(key[KEY_Q]){
        estocada(mapa, anterior_direccion, x, y);
        }
        else if(key[KEY_W]){
            eludir(mapa, anterior_direccion, x, y);
            }
            else if(key[KEY_E]){
                interactuar(mapa, anterior_direccion, x, y);
                }*/
    }

///*/

///Rutina de movimiento del jugador:
void JUGADOR::rutina_de_movimiento(MAPA &mapa){

    direccion = 0;

    if(key[KEY_RIGHT]&&key[KEY_UP]){                                               ///DERECHA ARRIBA
            direccion = 5;

        }else if(key[KEY_RIGHT]&&key[KEY_DOWN]){                                   ///DERECHA ABAJO
                    direccion = 6;

                }else if(key[KEY_LEFT]&&key[KEY_UP]){                              ///IZQUIERDA ARRIBA
                            direccion = 7;

                        }else if(key[KEY_LEFT]&&key[KEY_DOWN]){                    ///IZQUIERDA ABAJO
                                    direccion = 8;

                                }else if(key[KEY_RIGHT]){                          ///DERECHA
                                            direccion = 1;

                                        }else if(key[KEY_LEFT]){                   ///IZQUIERDA
                                                    direccion = 2;

                                                }else if(key[KEY_UP]){             ///ARRIBA
                                                        direccion = 3;

                                                        }else if(key[KEY_DOWN]){   ///ABAJO
                                                                direccion = 4;
                                                                }
            mover_jugador(mapa);
}



void JUGADOR::eliminar_muro(MAPA &mapa, int anterior_direccion, int x, int y, int x_ext, int y_ext){

 cout<<"\n-----INGRESO A LA FUNCION ELIMINAR MURO----- ";
cout<<"\nANTERIOR DIRECCION: "<<anterior_direccion;
cout<<"\nVALOR DE LA VARIABLE X: "<<x;
cout<<"\nVALOR DE LA VARIABLE Y: "<<y;
cout<<endl<<endl;


 switch(anterior_direccion){

        case 5: x++; break;        ///ABAJO:
        case 8: x--; break;        ///ARRIBA:
        case 4: y--; break;        ///IZQUIERDA:
        case 6: y++; break;        ///DERECHA:
}
           if(mapa.gets_mapa_juego(x_ext, y_ext, x, y)== MURO_ROMPIBLE){
            mapa.sets_mapa_general(x_ext, y_ext, x, y, PISO);
           }

}
///-----------------------------------------Aun sin terminar---------------------------------------------

void JUGADOR::mover_jugador(MAPA &mapa){

int x=0, y=0;   ///variables auxiliares para el uso de las posiciones.

    mapa.sets_mapa_general(gets_posicion_x_guia(), gets_posicion_y_guia(), gets_posicion_x_juego(), gets_posicion_y_juego(), PISO); ///ACTIUALIZA EL CARACTER DE PISO EN LA POSICION ANTERIOR

    switch(direccion){

        case 1: y++; break; ///Derecha;
        case 2: y--; break; ///Izquierda;
        case 3: x--; break; ///Arriba;
        case 4: x++; break; ///Abajo;
        case 5: x--; y++; break; ///DERECHA ARRIBA;
        case 6: x++; y++; break; ///DERECHA ABAJO;
        case 7: x--; y--; break; ///IZQUIERDA ARRIBA;
        case 8: x++; y--; break; ///IZQUIERDA ABAJO;

  }
            if(mapa.gets_mapa_juego(gets_posicion_x_guia(), gets_posicion_y_guia(), gets_posicion_x_juego() + x, gets_posicion_y_juego() +y) == PUERTA){
                mover_en_mapa_guia();
            }
            else{
                if(mapa.gets_mapa_juego(gets_posicion_x_guia(), gets_posicion_y_guia(), gets_posicion_x_juego() + x, gets_posicion_y_juego() +y) == PISO){
                    sets_posicion_x_juego(gets_posicion_x_juego() + x);
                    sets_posicion_y_juego(gets_posicion_y_juego() + y);
                }
            }

    mapa.sets_mapa_general(gets_posicion_x_guia(), gets_posicion_y_guia(), gets_posicion_x_juego(), gets_posicion_y_juego(), sprite_personaje); ///ACTUALIZA LA UBICACION DEL OBJETO
}

void JUGADOR::mover_en_mapa_guia(){

    switch(direccion){
        case 1: ///Derecha:
                sets_posicion_completa(gets_posicion_x_guia(), gets_posicion_y_guia() + 1, gets_posicion_x_juego(), 1);

        break;

        case 2:///Izquierda:
            sets_posicion_completa(gets_posicion_x_guia(), gets_posicion_y_guia() - 1, gets_posicion_x_juego(), MAX_COLUMNAS_JUEGO-2);

        break;

        case 3:///Arriba:
            sets_posicion_completa(gets_posicion_x_guia() - 1, gets_posicion_y_guia(), MAX_FILAS_JUEGO-2, gets_posicion_y_juego());

        break;

        case 4:///Abajo:
            sets_posicion_completa(gets_posicion_x_guia() + 1, gets_posicion_y_guia(), 1, gets_posicion_y_juego());

        break;

    }

}

///---------------------Propio del padre---------------------

///Gets

int JUGADOR::gets_posicion_x_guia(){
    return PERSONAJE::gets_posicion_x_guia();
}

int JUGADOR::gets_posicion_y_guia(){
    return PERSONAJE::gets_posicion_y_guia();
}

int JUGADOR::gets_posicion_x_juego(){
    return PERSONAJE::gets_posicion_x_juego();
}

int JUGADOR::gets_posicion_y_juego(){
    return PERSONAJE::gets_posicion_y_juego();
}

///Sets:

void JUGADOR::sets_posicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_posicion_x_guia(x_guia);
    PERSONAJE::sets_posicion_y_guia(y_guia);
    PERSONAJE::sets_posicion_x_juego(x_juego);
    PERSONAJE::sets_posicion_y_juego(y_juego);

}

void JUGADOR::sets_posicion_x_guia(int x_guia){
    PERSONAJE::sets_posicion_x_guia(x_guia);
}

void JUGADOR::sets_posicion_y_guia(int y_guia){
    PERSONAJE::sets_posicion_y_guia(y_guia);
}

void JUGADOR::sets_posicion_x_juego(int x_juego){
    PERSONAJE::sets_posicion_x_juego(x_juego);
}

void JUGADOR::sets_posicion_y_juego(int y_juego){
    PERSONAJE::sets_posicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_JUGADOR_H_INCLUDED

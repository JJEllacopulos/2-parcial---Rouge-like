#ifndef CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#include "Control_grafico.h"
#include "Funciones_auxiliares.h"
#include <iostream>
using namespace std;



class ENEMIGO: public PERSONAJE{
    protected:

        int vida;
        int vision;
        int movimiento;
        int direccion;
        int velocidad;

        int sprite_personaje;

    public:

        ///---------------------Propio del padre---------------------
        ///Gets

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
        ENEMIGO(MAPA &mapa);

        ///GETTERS
        int gets_velocidad(){return velocidad;}
        int gets_sprite(){return sprite_personaje;}
        int gets_vision(){return vision;}

        ///SETTERS
        void set_sprite( char c){sprite_personaje=c;}

        ///METODOS
        int asechar(MAPA &mapa);

        void mover_enemigo(MAPA &mapa, int x_guia, int y_guia, int x_mapa, int y_mapa);
        void rutina_de_movimiento_aleatorio(MAPA &mapa);
        void iddle(MAPA &mapa);
};


ENEMIGO::ENEMIGO(MAPA &mapa){


    sprite_personaje = COFRE;
    velocidad=25;
    vida=50;
    vision=6;


    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///FUNCION DE MOVIMIENTO
void ENEMIGO::rutina_de_movimiento_aleatorio(MAPA &mapa){

                                            /// POSICION ACTUAL DEL OBJETO
    int x_guia=PERSONAJE::gets_posicion_x_guia();
    int y_guia=PERSONAJE::gets_posicion_y_guia();
    int x_mapa=PERSONAJE::gets_posicion_x_juego();
    int y_mapa=PERSONAJE::gets_posicion_y_juego();

    int cuadrante=0;
    int dir = 0;

    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO

    dir = ((rand()) % gets_velocidad()); ///RANGO DE VELOCIDAD INVERSO (CUANTO MAS ALTO, MAS LENTO)

    cuadrante=asechar(mapa);             ///AL TENER UN CUADRANTE MARCADO COMO OBJETIVO ENTONCES BUSCA.

    if(cuadrante!=0){

        dir=cuadrante;
    }

    switch(dir){                     /// SI Y SOLO SI HAY ESPACIO PARA MOVERSE, SE MOVERA EN DIRECCION DEL SWITCH


    case 1: x_mapa--;         ///ARRIBA:
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa++;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;

    case 2: x_mapa++;         ///ABAJO:
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa--;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite()); ///SI NO HAY ESPACIO PARA MOVERSE ENTONCES REIMPRIME EL SPRITE EN PANTALLA
        }break;


    case 3: y_mapa--;         ///IZQUIERDA:
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { y_mapa++;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;


    case 4: y_mapa++;         ///DERECHA:
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { y_mapa--;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;

     case 9: x_mapa--; y_mapa--;       ///IZQUIERDA ARRIBA
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa++; y_mapa++;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;

    case 6:  x_mapa++; y_mapa--;       ///IZQUIERDA ABAJO
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa--; y_mapa++;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;

        case 8:  x_mapa++; y_mapa++;       ///DERECHA ABAJO
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa--; y_mapa--;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;

        case 7:  x_mapa--; y_mapa++;       ///DERECHA ARRIBA
    if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa, y_mapa)== PISO){
        mover_enemigo(mapa, x_guia, y_guia, x_mapa, y_mapa);
    }else { x_mapa++; y_mapa--;
        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }break;



    default: mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite()); break; /// EN ESTE CASO DEBERIA HABER UN IDDLE DE ANIMACION PASIVA


    // iddle(mapa); break;        ///AÑADIR ANIMACION PASIVA
    }



}

///RUTINA DE MOVIMIENTO DEL ENEMIGO
void ENEMIGO::mover_enemigo(MAPA &mapa,  int x_guia, int y_guia, int x_mapa, int y_mapa){

    PERSONAJE::sets_posicion_completa(x_guia, y_guia, x_mapa, y_mapa);        ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL OBJETO
    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, sprite_personaje);  ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL MAPA


}

int ENEMIGO::asechar(MAPA &mapa){

  int contador=0;

                int x=PERSONAJE::gets_posicion_x_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                int y=PERSONAJE::gets_posicion_y_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                int v= gets_vision();
                int i=x-v; int I=x+v;
                int j=x-v; int J=y+v;


                int cuadrante=0;                ///CUADRANTE INICIAL

                for(i; i<=I; i++ ){

                for(j=y-v; j<=J; j++ ){ ///INICIO DEL FOR EN Y

    if(mapa.gets_mapa_juego(PERSONAJE::gets_posicion_x_guia(), PERSONAJE::gets_posicion_y_guia(),i,j)==AVATAR){

                     cout<<"\nENCONTRO AL AVATAR EN X: "<<i;
                     cout<<"\nENCONTRO AL AVATAR EN Y: "<<j;

                    cuadrante=buscar_cuadrante(x, y, i, j);

                    return cuadrante; ///Se corta el for una vez encontrado lo buscado.

                        }
                 }
            }
            return cuadrante;

}
#endif // CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

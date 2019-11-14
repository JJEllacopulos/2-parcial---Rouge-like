#include <ctime>
#include <allegro.h>
#include <iostream>

#include "Imagenes.h"
//#include "Pistas_de_audio.h"
#include "Clase_mapa.h"
#include "Clase_personaje.h"
#include "Clase_personaje_jugador.h"
#include "Clase_personaje_Enemigo.h"
#include "Control_grafico.h"
//#include "Control_audio.h"


using namespace std;
int main(){

    int tempo;
    int anterior_direccion=0;              ///AUXILIAR QUE GUARDAN LA ULTIMA TECLA DE MOVIMIENTO APRETADA
    int x=0, y=0;                          ///VARIABLES AUXILIARES QUE GUARDAN LA ULTIMA POSICION DEL JUGADOR
    int x_ext=0, y_ext=0;

    ///Inicia allegro.
    allegro_init();
    install_keyboard();

    ///Establecer los parametros de la pantalla.
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, TAMANO_X_BUFFER, TAMANO_Y_BUFFER, 0, 0);

    ///Establecer los parametros del audio.
   /* if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }*/

    ///Ajustes de audio:
    //set_volume(70, 70);

    ///Carga las imagenes en los distintos bitmaps.
    asignar_sprites();

    ///Carga las pistas de audio.
   // asignar_audio();

    ///Semailla del random:
    srand(time(0));

    ///Inicia y arma el mapa.
    MAPA mapa(1);

    ///Inicia y arma el personaje.
    JUGADOR per_jug(mapa);
    ENEMIGO mimic(mapa);

    x=per_jug.gets_posicion_x_juego(); y=per_jug.gets_posicion_y_guia(); ///POSICION INICAL DEL JUGADOR CARGADO EN AUXILIARES

   // per_jug.iniciar_personaje(mapa);

    mapa.sets_mapa_general(1,0,15,15, mimic.gets_sprite());


    ///Reproducion en bucle del tema de fondo:
    //play_midi(Fondo, 1);

    ///Bucle del juego (game loop).
    while(!key[KEY_ESC]){


        rest(7);
        if((key[KEY_UP]||key[KEY_DOWN])||(key[KEY_LEFT]||key[KEY_RIGHT])){
        per_jug.rutina_de_movimiento(mapa);
        }


        ///Limpia el mapa de bits.
        clear(buffer);

        ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
        Graficar_mapa_base(mapa, per_jug.gets_posicion_x_guia(), per_jug.gets_posicion_y_guia());
        ///Carga en el buffer los elementos restantes(PJ, NPC, puertas, etc).
        Graficar_mapa_objetos(mapa, per_jug.gets_posicion_x_guia(), per_jug.gets_posicion_y_guia());

        if(key[KEY_SPACE]){

        per_jug.rutina_de_accion(mapa, anterior_direccion, x, y, x_ext, y_ext);///PASAJE DE COORDENADAS AUXILIARES PARA LA MODIFICACION
        }
        ///TEMPO

        tempo++;
        if (tempo==3){

        mimic.rutina_de_movimiento_aleatorio(mapa);
        tempo=0;
        }



        ///Imprime en la ventana lo que se cargo en el buffer.
        pantallaso();

        ///Retraso de actividades en nanosegundos.
        rest(115);


        /// CARGA DE LOS AUXILIARES DE MOVIMIENTO
        if(key[KEY_UP]){anterior_direccion=8;}
        else if(key[KEY_DOWN]){anterior_direccion=5;}
        else if(key[KEY_LEFT]){anterior_direccion=4;}
        else if(key[KEY_RIGHT]){anterior_direccion=6;}

        x=per_jug.gets_posicion_x_juego(); y=per_jug.gets_posicion_y_juego(); ///COORDENADAS PARA ESTABLECER ULTIMA POSICION EN EL MAPA*/
        x_ext=per_jug.gets_posicion_x_guia(); y_ext=per_jug.gets_posicion_y_guia();///COORDENADAS DE LA GUIA

    }

    //free(Fondo);

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

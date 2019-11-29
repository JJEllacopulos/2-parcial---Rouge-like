#include <ctime>
#include <allegro.h>

#include<string.h>
#include <iostream>
using namespace std;

///Control de tiempo:
#include "Cronometro.h"

///Configuracion del mapa:
#include "Clase_mapa.h"

///Cofiguracion del los elemoentos de audio y graficos:
#include "Imagenes.h";
#include "Pistas_de_audio.h";
#include "Control_grafico.h"
#include "Control_audio.h"

///Clase personaje:
#include "Clase_personaje/Clase_personaje.h"
#include "Clase_personaje/Clase_personaje_jugador.h"
#include "Clase_personaje/Clase_personaje_MOBs.h"



int main(){

    ///Inicia allegro.
    allegro_init();
    install_keyboard();
    cout<< "Allegro iniciado."<< endl;

    ///Establecer los parametros de la pantalla.
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, TAMANO_X_BUFFER, TAMANO_Y_BUFFER, 0, 0);
    cout<< "Parametros del buffer iniciados."<< endl;

    ///Establecer los parametros del audio.
    if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }
    cout<< "Parametros de audio iniciados."<< endl;

    ///Ajustes de audio:
    set_volume(70, 70);
    cout<< "Parametos de volumen de audio iniciados."<< endl;

    ///Carga las imagenes en los distintos bitmaps.
    asignar_sprites();

    ///Carga las imagenes en los distintos bitmaps(Decorados).
    asignar_sprites_decorado();

    ///Carga las pistas de audio.
    asignar_audio();

    ///Semailla del random:
    srand(time(0));

    ///Inicia y arma el mapa.
    MAPA mapa;
    cout<< "Mapa iniciado."<< endl;

    ///Inicia y arma el personaje.
    JUGADOR per_jug(mapa);
    cout<< "Personaje jugador iniciado."<< endl;

    ///Iniciar MOVs:
    int cantidad_de_MOBs = 15;
    int ciclo_MOBs;
    MOB esqueleto[cantidad_de_MOBs](mapa);

    ///Inicicar conometro:
    CRONO cronometro;
    cronometro.sets_tiempo(4);

    ///Reproducion en bucle del tema de fondo:
    play_midi(Fondo, 1);

    ///Bucle del juego (game loop).
    while(!key[KEY_ESC]){

        ///Mover personaje jugador:
        per_jug.rutina_de_movimiento(mapa);

        ///Mover MOVs:
        for(ciclo_MOBs = 0; ciclo_MOBs < cantidad_de_MOBs; ciclo_MOBs++){
            esqueleto[ciclo_MOBs].rutina_de_movimiento(mapa);
        }
        ///Limpia el mapa de bits.
        clear(buffer);

        ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
        Graficar_mapa_base(mapa, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia());

        ///Carga en el buffer los elementos restantes(manchas, efectos, etc).
        Graficar_mapa_de_efectos(mapa, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia(), cronometro.control_int()+1);

        ///Carga en el buffer los elementos restantes(PJ, NPC, puertas, etc).
        Graficar_mapa_objetos(mapa, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia());

        ///Carga en el buffer el sprite del jugador.
        per_jug.graficar_jugador();

        ///Imprime en la ventana lo que se cargo en el buffer.
        pantallaso();

        ///Retraso de actividades en nanosegundos.
        rest(40);
    }

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

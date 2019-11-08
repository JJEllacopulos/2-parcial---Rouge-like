#include <ctime>
#include <allegro.h>

#include "Imagenes.h";
#include "Pistas_de_audio.h";
#include "Clase_mapa.h"
#include "Clase_personaje.h"
#include "Clase_personaje_jugador.h"
#include "Control_grafico.h"
#include "Control_audio.h"


int main(){

    ///Inicia allegro.
    allegro_init();
    install_keyboard();

    ///Establecer los parametros de la pantalla.
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, TAMANO_X_BUFFER, TAMANO_Y_BUFFER, 0, 0);

    ///Establecer los parametros del audio.
    if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }

    ///Ajustes de audio:
    set_volume(70, 70);

    ///Carga las imagenes en los distintos bitmaps.
    asignar_sprites();

    ///Carga las pistas de audio.
    asignar_audio();

    ///Semailla del random:
    srand(time(0));

    ///Inicia y arma el mapa.
    MAPA mapa(1);

    ///Inicia y arma el personaje.
    PERSONAJE pj;
    pj.iniciar_personaje(mapa);

    ///Reproducion en bucle del tema de fondo:
    play_midi(Fondo, 1);

    ///Bucle del juego (game loop).
    while(!key[KEY_ESC]){

        ///Limpia el mapa de bits.
        clear(buffer);

        ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
        Graficar_mapa_base(mapa, pj.gets_pocicion_x_guia(), pj.gets_pocicion_y_guia());
        ///Carga en el buffer los elementos restantes(PJ, NPC, puertas, etc).
        Graficar_mapa_objetos(mapa, pj.gets_pocicion_x_guia(), pj.gets_pocicion_y_guia());

        ///Imprime en la ventana lo que se cargo en el buffer.
        pantallaso();

        ///Retraso de actividades en nanosegundos.
        rest(150);
    }

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

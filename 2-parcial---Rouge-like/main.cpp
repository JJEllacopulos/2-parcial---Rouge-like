#include <ctime>
#include <allegro.h>

#include "Imagenes.h";
#include "Clase_mapa.h"
#include "Control_grafico.h"


int main(){

    ///Inicia allegro.
    allegro_init();
    install_keyboard();

    ///Establecer los parametros de la pantalla.
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, TAMANO_X_BUFFER, TAMANO_Y_BUFFER, 0, 0);

    ///Carga las imagenes en los distintos bitmaps.
    asignar_sprites();

    ///Inicia y arma el mapa.
    MAPA mapa(1);

    ///Bucle del juego (game loop).
    while(!key[KEY_ESC]){

        ///Limpia el mapa de bits.
        clear(buffer);

        ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
        Graficar_mapa_base(mapa);
        ///Carga en el buffer los elementos restantes(PJ, NPC, puertas, etc).
        Graficar_mapa_objetos(mapa);

        ///Imprime en la ventana lo que se cargo en el buffer.
        pantallaso();

        ///Retraso de actividades en nanosegundos.
        rest(150);
    }

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

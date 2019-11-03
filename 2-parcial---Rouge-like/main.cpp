#include <ctime>
#include <allegro.h>

#include "Imagenes.h";
#include "Clase_mapa.h"
#include "Control_grafico.h"


int main(){

    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 740, 740, 0, 0);

    asignar_sprites();

    MAPA mapa();

    while(!key[KEY_ESC]){


        clear(buffer);

        Graficar_mapa_base(mapa);
        Graficar_mapa_objetos(mapa);

        pantallaso();


        rest(150);
    }

}

END_OF_MAIN();

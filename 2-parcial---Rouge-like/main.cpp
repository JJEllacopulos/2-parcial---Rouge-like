#include <ctime>
#include <allegro.h>

#include<string.h>
#include <iostream>
#include <cstdio>
using namespace std;

///---Control de tiempo:
#include "Cronometro.h"

///---Configuracion del mapa:
#include "Clase_mapa.h"
#include "Clase_mapa_grafico.h"

///---Cofiguracion del los elemoentos de audio y graficos:
#include "Controles_de_archivos/Imagenes.h";
#include "Controles_de_archivos/Pistas_de_audio.h";
#include "Controles_de_archivos/Control_grafico.h"
#include "Controles_de_archivos/Control_audio.h"


///---Clase personaje:
#include "Clase_personaje/Clase_personaje.h"

///Otros
#include "Clase_personaje/Otros/Clase_personaje_proyectil.h"
#include "Clase_personaje/Otros/Proyectil_flecha.h"

///Jugador:
#include "Clase_personaje/Clase_personaje_jugador.h"
#include "Clase_personaje/Clase_personaje_jugador_graficos.h"
#include "Clase_personaje/Clase_personaje_jugador_combate.h"
///Enemigos:
#include "Clase_personaje/Clase_personaje_enemigo_1.h"
#include "Clase_personaje/Clase_personaje_enemigo_1_graficos.h"
#include "Clase_personaje/Clase_personaje_enemigo_1_combate.h"

#include "Clase_personaje/Clase_personaje_enemigo_2.h"
#include "Clase_personaje/Clase_personaje_enemigo_2_graficos.h"
#include "Clase_personaje/Clase_personaje_enemigo_2_combate.h"


///interacciones
//#include "Clase_personaje/Otros/Interacciones_entre_objetos.h"
///Vectores dinamicos de enemigos:
#include "Clase_personaje/Pila_de_enemigos.h"



///---Guardado de progreso.
#include "Controles_de_archivos/Control_partida.h"

///---Game loop:
#include "Game_loop.h"

///---Menu
#include "Menu.h"

int main(){

    ///Inicia allegro.
    allegro_init();
    install_keyboard();
    cout<< "Allegro iniciado."<< endl;

    ///Establecer los parametros de la pantalla.
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN , TAMANO_X_BUFFER, TAMANO_Y_BUFFER, 0, 0);
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

    ///Semailla del random:
    srand(time(0));

    ///Inicia y arma el mapa.
    MAPA mapa;
    MAPA_GRAFICO mapa_grafico;
    ///MAPA_GRAFICO mapa_grafico(mapa);
    int zona = 0;///((rand()) % 9);
    cout<< "Mapa iniciado."<< endl;

    ///Inicia y arma el personaje.
    JUGADOR per_jug;
    cout<< "Personaje jugador iniciado."<< endl;

    ///Iniciar MOVs:
    PILA_ENEMIGOS pila_enemigos;

    ///Archivo de guardado:
    ARCHIVO_PARTIDA archivo_guardado;

    Menu_control( per_jug, pila_enemigos, mapa, mapa_grafico, zona, archivo_guardado);

    ///Game_loop( per_jug, pila_enemigos, mapa, mapa_grafico, zona);

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

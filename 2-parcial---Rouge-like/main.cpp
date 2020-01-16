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

///Jugador:
#include "Clase_personaje/Clase_personaje_jugador.h"
#include "Clase_personaje/Clase_personaje_jugador_graficos.h"
///Enemigos:
#include "Clase_personaje/Clase_personaje_enemigo_1.h"
#include "Clase_personaje/Clase_personaje_enemigo_1_graficos.h"

///Otros
#include "Clase_personaje/Otros/Clase_personaje_proyectil.h"
///interacciones
//#include "Clase_personaje/Otros/Interacciones_entre_objetos.h"
///Vectores dinamicos de enemigos:
#include "Clase_personaje/Pila_de_enemigos.h"



///---Guardado de progreso.
#include "Controles_de_archivos/Control_partida.h"



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
    ///JUGADOR per_jug(mapa);
    cout<< "Personaje jugador iniciado."<< endl;

    ///Iniciar MOVs:
    /*
    int cantidad_de_MOBs = 15;
    int ciclo_MOBs;
    ENEMIGO_1 esqueleto[CANTIDAD_MODS];
    */
    PILA_ENEMIGOS pila_enemigos;

    ///MOB esqueleto[CANTIDAD_MODS](mapa);

    ///Inicicar conometro:
    CRONO cronometro;
    CRONO cronometro_int;
    cronometro.sets_tiempo(2);
    cronometro_int.sets_tiempo(0);

    ///Archivo de guardado:
    ARCHIVO_PARTIDA archivo_guardado;

    while(zona != 9){

        ///Iniciar y reiniciar el mapa.
        mapa.Reiniciar_mapa();
        mapa_grafico.Reiniciar_mapa_grefico(mapa);
        per_jug.Reiniciar_jugador(mapa);
        /*for(ciclo_MOBs = 0; ciclo_MOBs < CANTIDAD_MODS; ciclo_MOBs++){
            esqueleto[ciclo_MOBs].Reiniciar_MOBs(mapa);
        }*/

        pila_enemigos.Iniciar_vectores(zona, mapa);

        ///Guardar partida.
        //archivo_guardado.Guardar_partida(zona, mapa, mapa_grafico, per_jug);

        ///Carga las pistas de audio.
        asignar_audio(zona);

        ///Reproducion en bucle del tema de fondo:
        play_midi(Fondo, 1);

        ///Bucle del juego (game loop).
        while(!key[KEY_ESC]){

            ///Mover personaje jugador:
            per_jug.rutinas_de_acciones(mapa/*, esqueleto*/);
            pila_enemigos.Jugador_ataca(per_jug);

            ///Mover MOVs:
            /*for(ciclo_MOBs = 0; ciclo_MOBs < CANTIDAD_MODS; ciclo_MOBs++){
                esqueleto[ciclo_MOBs].rutina_de_movimiento(mapa);
            }*/
            pila_enemigos.Rutina_de_enemigos(mapa);

            ///Atacar personaje jugador:
            //per_jug.realizar_ataque(esqueleto);

            ///Limpia el mapa de bits.
            clear(buffer);

            ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
            Graficar_fondo(mapa_grafico, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia(), zona);

            ///Carga en el buffer los elementos de la superpocicion 1(decorados, efectos, animaciones, etc).

            if(cronometro_int.control_bool()){
                cronometro.control_int();
            }

            Graficar_superpocicion_1(mapa_grafico, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia(), cronometro.gets_cont(), zona);

            ///Carga en el buffer el sprite del jugador.
            per_jug.graficar_jugador();

            ///Graficar MOVs:
            /*for(ciclo_MOBs = 0; ciclo_MOBs < CANTIDAD_MODS; ciclo_MOBs++){
                esqueleto[ciclo_MOBs].graficar_MOBs(per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia());
            }*/
            pila_enemigos.Graficar_enemigos(per_jug);

            ///Imprime en la ventana lo que se cargo en el buffer.
            pantallaso();

            ///Retraso de actividades en nanosegundos.
            rest(60);
        }

        while(key[KEY_ESC]){}

        zona++;

        pila_enemigos.Cerrar_vectores();

        ///Cargar partida.
        //archivo_guardado.Cargar_partida(zona, mapa, mapa_grafico, per_jug);

    }

}
///Equivalente a el return 0 para el main.
END_OF_MAIN();

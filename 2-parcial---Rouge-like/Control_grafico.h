#ifndef CONTROL_GRAFICO_H_INCLUDED
#define CONTROL_GRAFICO_H_INCLUDED

///Tamaño de la pantalla.
#define TAMANO_X_BUFFER 1300 ///Tamaño del los buffer en el eje x.
#define TAMANO_Y_BUFFER 700 ///Tamaño del los buffer en el eje y.

#define TAMANO_X_SPRITE 30 ///Tamaño del los sprites en el eje x.
#define TAMANO_Y_SPRITE 30 ///Tamaño del los sprites en el eje y.

///Carga las imagenes en los difenentes mapas de bits.
void asignar_sprites(){

    ///Inicia los valores del buffer.
    buffer = create_bitmap(TAMANO_X_BUFFER, TAMANO_Y_BUFFER);

    ///Carga las imagenes en los mapas de bits.

    ///Recuendan como se le mandaba una direccion parcial de un archivo? Porque yo no.

    MURO_IRROMPIBLE_spr = load_bitmap("Imagenes/Piedra_2.bmp", NULL);
    MURO_ROMPIBLE_spr = load_bitmap("Imagenes/Piedra_3.bmp", NULL);
    COFRE_spr = load_bitmap("Imagenes/Cofre_1.bmp", NULL);
    ENEMIGO_spr = load_bitmap("Imagenes/Enemigo_1.bmp", NULL);
    AVATAR_spr = load_bitmap("Imagenes/Viajero_1.bmp", NULL);
    PUERTA_spr = load_bitmap("Imagenes/Puerta_1.bmp", NULL);
    PISO_spr = load_bitmap("Imagenes/Mosaico_2.bmp", NULL);

}

///Carga en el buffer los elementos de entorno (Piso, muros, etc).
void Graficar_mapa_base( MAPA &mapa, int x_externo = 1, int y_externo = 1){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
        for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

            switch(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno)){
                case MURO_IRROMPIBLE:

                    draw_sprite(buffer, MURO_IRROMPIBLE_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case MURO_ROMPIBLE:

                    draw_sprite(buffer, MURO_ROMPIBLE_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                ///Cualquier valor que no sean de los anteriores seran asignados como piso.
                default:

                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

            }

        }
    }

}

///Carga en el buffer los elementos restantes(PJ, NPC, puertas, etc).
void Graficar_mapa_objetos(MAPA &mapa, int x_externo = 1, int y_externo = 1){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
        for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

            switch(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno)){

                case COFRE:

                    draw_sprite(buffer, COFRE_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case AVATAR:

                    draw_sprite(buffer, AVATAR_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case ENEMIGO:

                    draw_sprite(buffer, ENEMIGO_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case PUERTA:

                    draw_sprite(buffer, PUERTA_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

            }

        }
    }

}

///Imprime en la ventana lo que se cargo en el buffer.
void pantallaso(){

    blit(buffer, screen, 0, 0, 0, 0, TAMANO_X_BUFFER, TAMANO_Y_BUFFER);

}

#endif // CONTROL_GRAFICO_H_INCLUDED

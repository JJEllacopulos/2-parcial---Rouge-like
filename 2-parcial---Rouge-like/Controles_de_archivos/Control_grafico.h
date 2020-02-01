#ifndef CONTROL_GRAFICO_H_INCLUDED
#define CONTROL_GRAFICO_H_INCLUDED

///Tamaño de la pantalla.
///1300 x 700
#define TAMANO_X_BUFFER 640 ///Tamaño del los buffer en el eje x.
#define TAMANO_Y_BUFFER 480 ///Tamaño del los buffer en el eje y.


///---Propios de todo sprite:
#define TAMANO_X_SPRITE 32 ///Tamaño del los sprites en el eje x.
#define TAMANO_Y_SPRITE 32 ///Tamaño del los sprites en el eje y.

#define DESPLAZAR_X_PIXEL 33 ///Tamaño de pixels en el eje x que se debe desplazar para cortar la imagen.
#define DESPLAZAR_Y_PIXEL 33 ///Tamaño de pixels en el eje y que se debe desplazar para cortar la imagen.

///Espacio para los bordes:
#define ESPACIO_SUPERIOR_Y 16 ///Espacio marcos.
#define ESPACIO_SUPERIOR_X 64 ///Espacio superior.


///---Propios de los personajes:

#define TAMANO_X_SPRITE_INT 10 ///Intervalo de la animacion.
#define TAMANO_Y_SPRITE_INT 10 ///Intervalo de la animacion.

///Ataque:
#define TAMANO_X_SPRITE_ATTACK 64 ///Tamaño del los sprites de attack en el eje x.
#define TAMANO_Y_SPRITE_ATTACK 64 ///Tamaño del los sprites de attack en el eje y.

#define DESPLAZAR_X_SPRITE_ATTACK 66 ///Tamaño del los sprites de attack en el eje x que se debe desplazar para cortar la imagen.
#define DESPLAZAR_Y_SPRITE_ATTACK 66 ///Tamaño del los sprites de attack en el eje y que se debe desplazar para cortar la imagen.

#define CENTRAR_X_SPRITE_ATTACK 16 ///Tamaño del los sprites de attack en el eje x que se debe desplazar para centrar la imagen.
#define CENTRAR_Y_SPRITE_ATTACK 16 ///Tamaño del los sprites de attack en el eje y que se debe desplazar para centrar la imagen.

///Propios de los jugador:
#define TAMANO_X_BARRA 32 ///Tamaño de las barras en el eje x.
#define TAMANO_Y_BARRA 16 ///Tamaño de las barras en el eje y.

#define ANIMACION_ATAQUE_1 265 ///Pocicion inicial de la animacion del ataque 1.
#define ANIMACION_ATAQUE_2 529 ///Pocicion inicial de la animacion del ataque 2.
#define ANIMACION_ESCUDO 792 ///Pocicion inicial de la animacion del ataque 2.
#define ANIMACION_ATAQUE_ESP_1 925 ///Pocicion inicial de la animacion del ataque 2.

///Propios de los enemigos:
#define TAMANO_X_CORAZON 8 ///Tamaño de las barras en el eje x.
#define TAMANO_Y_CORAZON 8 ///Tamaño de las barras en el eje y.


///Carga las imagenes en los difenentes mapas de bits.
void asignar_sprites(){

    ///Inicia los valores del buffer.
    buffer = create_bitmap(TAMANO_X_BUFFER, TAMANO_Y_BUFFER);

    ///Carga las imagenes en los mapas de bits.

    JUGADOR_spr = load_bitmap("Imagenes/Jugador.bmp", NULL);
    JUGADOR_mov_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    JUGADOR_attack_spr = create_bitmap(TAMANO_X_SPRITE_ATTACK, TAMANO_Y_SPRITE_ATTACK);

    ENEMIGO_1_spr = load_bitmap("Imagenes/Enemigo_1.bmp", NULL);
    ENEMIGO_1_mov_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ENEMIGO_2_spr = load_bitmap("Imagenes/Enemigo_2.bmp", NULL);
    ENEMIGO_2_mov_spr = create_bitmap(TAMANO_X_SPRITE_ATTACK, TAMANO_Y_SPRITE_ATTACK);

    PROYECTILES_spr = load_bitmap("Imagenes/Proyectiles.bmp", NULL);
    PROYECTIL_mov_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///------------------------------------------

    FONDOS_spr = load_bitmap("Imagenes/Fondos.bmp", NULL);
    MURO_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    PARED_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    PISO_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///------------------------------------------

    ELEMENTOS_spr = load_bitmap("Imagenes/Elementos.bmp", NULL);
    ALTAR_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    PUERTA_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    DECORADO_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///------------------------------------------
    ANIMACIONES_spr = load_bitmap("Imagenes/Animaciones.bmp", NULL);
    ANIMACION_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///------------------------------------------
    BARRAS_spr = load_bitmap("Imagenes/Barras.bmp", NULL);
    BARRAS_ACT_spr = create_bitmap(TAMANO_Y_BARRA, TAMANO_X_BARRA);
    CORAZON_spr = create_bitmap(TAMANO_Y_CORAZON, TAMANO_X_CORAZON);

}

///Carga en el buffer los elementos de entorno (Piso, muros, etc).
void Graficar_fondo( MAPA_GRAFICO &mapa, int x_externo, int y_externo, int zona){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
        for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

            switch(mapa.gets_mapa_grafico_fondo(x_externo, y_externo, x_interno, y_interno)){

                case MURO_1:
                    blit(FONDOS_spr, MURO_spr, 0 * DESPLAZAR_Y_PIXEL, (132 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case MURO_2:
                    blit(FONDOS_spr, MURO_spr, 1 * DESPLAZAR_Y_PIXEL, (132 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case MURO_3:
                    blit(FONDOS_spr, MURO_spr, 2 * DESPLAZAR_Y_PIXEL, (132 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case MURO_4:
                    blit(FONDOS_spr, MURO_spr, 3 * DESPLAZAR_Y_PIXEL, (132 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_1:
                    blit(FONDOS_spr, PARED_spr, 0 * DESPLAZAR_Y_PIXEL, (132 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PARED_2:
                    blit(FONDOS_spr, PARED_spr, 1 * DESPLAZAR_Y_PIXEL, (132 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PARED_3:
                    blit(FONDOS_spr, PARED_spr, 2 * DESPLAZAR_Y_PIXEL, (132 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PARED_4:
                    blit(FONDOS_spr, PARED_spr, 3 * DESPLAZAR_Y_PIXEL, (132 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PISO_1:
                    blit(FONDOS_spr, PISO_spr, 0 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_2:
                    blit(FONDOS_spr, PISO_spr, 1 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_3:
                    blit(FONDOS_spr, PISO_spr, 2 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_4:
                    blit(FONDOS_spr, PISO_spr, 3 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_5:
                    blit(FONDOS_spr, PISO_spr, 4 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_6:
                    blit(FONDOS_spr, PISO_spr, 5 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_7:
                    blit(FONDOS_spr, PISO_spr, 6 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PISO_8:
                    blit(FONDOS_spr, PISO_spr, 7 * DESPLAZAR_Y_PIXEL, (132 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_1:
                    blit(FONDOS_spr, PISO_spr, 0 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_2:
                    blit(FONDOS_spr, PISO_spr, 1 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_3:
                    blit(FONDOS_spr, PISO_spr, 2 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_4:
                    blit(FONDOS_spr, PISO_spr, 3 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_5:
                    blit(FONDOS_spr, PISO_spr, 4 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_6:
                    blit(FONDOS_spr, PISO_spr, 5 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_7:
                    blit(FONDOS_spr, PISO_spr, 6 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_8:
                    blit(FONDOS_spr, PISO_spr, 7 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;

                case PARED_ESQUINA_9:
                    blit(FONDOS_spr, PISO_spr, 8 * DESPLAZAR_Y_PIXEL, (132 * zona) + 3 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;


            }

        }
    }

}


///Carga en el buffer los elementos que decoran el fondo(sangre, pilares, oro, etc).
void Graficar_superpocicion_1(MAPA_GRAFICO &mapa, int x_externo, int y_externo, int num, int zona){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
        for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

            switch(mapa.gets_mapa_grafico_1_sup(x_externo, y_externo, x_interno, y_interno)){

                case ELEMENTO_1:
                    blit(ELEMENTOS_spr, DECORADO_spr, 3 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case ELEMENTO_2:
                    blit(ELEMENTOS_spr, DECORADO_spr, 4 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case ELEMENTO_3:
                    blit(ELEMENTOS_spr, DECORADO_spr, 5 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case ELEMENTO_4:
                    blit(ELEMENTOS_spr, DECORADO_spr, 6 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;


                case PUERTA_1:
                    blit(ELEMENTOS_spr, PUERTA_spr, 1 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PUERTA_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case PUERTA_2:
                    blit(ELEMENTOS_spr, PUERTA_spr, 2 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PUERTA_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;


                case ANIMACION_1:
                    blit(ANIMACIONES_spr, ANIMACION_spr, num * DESPLAZAR_Y_PIXEL, (66 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, ANIMACION_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
                break;
                case ANIMACION_2:
                    blit(ANIMACIONES_spr, ANIMACION_spr, num * DESPLAZAR_Y_PIXEL, (66 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, ANIMACION_spr, y_interno * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, x_interno * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
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

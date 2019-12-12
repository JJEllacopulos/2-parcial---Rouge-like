#ifndef CONTROL_GRAFICO_H_INCLUDED
#define CONTROL_GRAFICO_H_INCLUDED

///Tamaño de la pantalla.
#define TAMANO_X_BUFFER 1300 ///Tamaño del los buffer en el eje x.
#define TAMANO_Y_BUFFER 700 ///Tamaño del los buffer en el eje y.

#define TAMANO_X_SPRITE 32 ///Tamaño del los sprites en el eje x.
#define TAMANO_Y_SPRITE 32 ///Tamaño del los sprites en el eje y.

#define DESPLAZAR_X_PIXEL 33 ///Tamaño de pixels en el eje x que se debe desplazar para cortar la imagen.
#define DESPLAZAR_Y_PIXEL 33 ///Tamaño de pixels en el eje y que se debe desplazar para cortar la imagen.

#define TAMANO_X_SPRITE_INT 8 ///Intervalo de la animacion.
#define TAMANO_Y_SPRITE_INT 8 ///Intervalo de la animacion.

///Carga las imagenes en los difenentes mapas de bits.
void asignar_sprites(){

    ///Inicia los valores del buffer.
    buffer = create_bitmap(TAMANO_X_BUFFER, TAMANO_Y_BUFFER);

    ///Carga las imagenes en los mapas de bits.

    JUGADOR_spr = load_bitmap("Imagenes/Animacion_movimiento.bmp", NULL);
    JUGADOR_mov_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ENEMIGO_spr = load_bitmap("Imagenes/Enemigo_1.bmp", NULL);

    FONDO_spr = load_bitmap("Imagenes/Fondo.bmp", NULL);
    PUERTA_spr = load_bitmap("Imagenes/Puertas.bmp", NULL);
    DECORADO_spr = load_bitmap("Imagenes/Decorado.bmp", NULL);
    ANIMACION_spr = load_bitmap("Imagenes/Animaciones.bmp", NULL);

    ///MURO_IRROMPIBLE_spr = load_bitmap("Imagenes/Piedra_2.bmp", NULL);
    ///MURO_ROMPIBLE_spr = load_bitmap("Imagenes/Piedra_3.bmp", NULL);
    ///COFRE_spr = load_bitmap("Imagenes/Cofre_1.bmp", NULL);
    ///AVATAR_spr = load_bitmap("Imagenes/Viajero_1.bmp", NULL);
    ///PUERTA_spr = load_bitmap("Imagenes/Puerta_1.bmp", NULL);
    ///PISO_spr = load_bitmap("Imagenes/Mosaico_2.bmp", NULL);


    MURO_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    PARED_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    PISO_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///--------------
    PUERTA_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    DECORADO_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);
    ANIMACION_1_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///SANGRE_spr = load_bitmap("Imagenes/Efectos/Sangre.bmp", NULL);
    ///SANGRE_efect_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

    ///ANTORCHA_spr = load_bitmap("Imagenes/Efectos/Antorcha.bmp", NULL);
    ///ANTORCHA_efect_spr = create_bitmap(TAMANO_X_SPRITE, TAMANO_Y_SPRITE);

}

///Carga en el buffer los elementos de entorno (Piso, muros, etc).
void Graficar_fondo( MAPA_GRAFICO &mapa, int x_externo = 1, int y_externo = 1, int zona = 0){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
        for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

            switch(mapa.gets_mapa_grafico_fondo(x_externo, y_externo, x_interno, y_interno)){

                case MURO_1:
                    blit(FONDO_spr, MURO_1_spr, 0 * DESPLAZAR_Y_PIXEL, (99 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case MURO_2:
                    blit(FONDO_spr, MURO_1_spr, 1 * DESPLAZAR_Y_PIXEL, (99 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case MURO_3:
                    blit(FONDO_spr, MURO_1_spr, 2 * DESPLAZAR_Y_PIXEL, (99 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case MURO_4:
                    blit(FONDO_spr, MURO_1_spr, 3 * DESPLAZAR_Y_PIXEL, (99 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, MURO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case PARED_1:
                    blit(FONDO_spr, PARED_1_spr, 0 * DESPLAZAR_Y_PIXEL, (99 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PARED_2:
                    blit(FONDO_spr, PARED_1_spr, 1 * DESPLAZAR_Y_PIXEL, (99 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PARED_3:
                    blit(FONDO_spr, PARED_1_spr, 2 * DESPLAZAR_Y_PIXEL, (99 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PARED_4:
                    blit(FONDO_spr, PARED_1_spr, 3 * DESPLAZAR_Y_PIXEL, (99 * zona) + 1 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PARED_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case PISO_1:
                    blit(FONDO_spr, PISO_1_spr, 0 * DESPLAZAR_Y_PIXEL, (99 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PISO_2:
                    blit(FONDO_spr, PISO_1_spr, 1 * DESPLAZAR_Y_PIXEL, (99 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PISO_3:
                    blit(FONDO_spr, PISO_1_spr, 2 * DESPLAZAR_Y_PIXEL, (99 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case PISO_4:
                    blit(FONDO_spr, PISO_1_spr, 3 * DESPLAZAR_Y_PIXEL, (99 * zona) + 2 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PISO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
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
                    blit(DECORADO_spr, DECORADO_1_spr, 0 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case ELEMENTO_2:
                    blit(DECORADO_spr, DECORADO_1_spr, 1 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;
                case ELEMENTO_3:
                    blit(DECORADO_spr, DECORADO_1_spr, 2 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, DECORADO_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;

                case PUERTA_1:
                    blit(PUERTA_spr, PUERTA_1_spr, 0 * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, PUERTA_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
                break;


                case ANIMACION_1:
                    blit(ANIMACION_spr, ANIMACION_1_spr, num * DESPLAZAR_Y_PIXEL, (33 * zona) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                    draw_sprite(buffer, ANIMACION_1_spr, y_interno * TAMANO_Y_SPRITE, x_interno * TAMANO_X_SPRITE);
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

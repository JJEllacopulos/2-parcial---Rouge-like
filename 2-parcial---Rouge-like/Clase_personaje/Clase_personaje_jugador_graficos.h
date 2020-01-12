#ifndef CLASE_PERSONAJE_JUGADOR_GRAFICOS_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_GRAFICOS_H_INCLUDED

///-----------------------------------------Graficar jugador---------------------------------------------

void JUGADOR::graficar_jugador(){

    if(direccion == 0){

        graficar_jugador_pocicion_estatica();

    }
    else{

        graficar_jugador_caminar();

    }

    graficar_jugador_barras();

}

///Pocicion estatica.
void JUGADOR::graficar_jugador_pocicion_estatica(){

    switch(frente){
        case 0:
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 1:
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 2:
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 3:
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

    }

}

///Animacion de movimiento al caminar.
void JUGADOR::graficar_jugador_caminar(){

    animacion.control_int();
    frame_estatico.control_int_invertido();
    switch(direcion_anima){

        case 0: ///Estatico.
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Derecha;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Izquierda;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Arriba;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 4: ///Abajo;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 5: ///DERECHA ARRIBA;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 6: ///DERECHA ABAJO;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 7: ///IZQUIERDA ARRIBA;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 8: ///IZQUIERDA ABAJO;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;
    }

        ///return;

}

///Amimacion de las barras:
void JUGADOR::graficar_jugador_barras(){

    int x;

    for(x = 1 ; x <= MAXIMA_VIDA ; x++){

        switch(x){

            case 1:
                blit(BARRAS_spr, BARRAS_ACT_spr, 2 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);

                if(vida_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 2 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);
                }

            break;
            case MAXIMA_VIDA:
                blit(BARRAS_spr, BARRAS_ACT_spr, 2 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite_h_flip(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);

                if(vida_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 2 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite_h_flip(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);
                }

            break;
            default:
                blit(BARRAS_spr, BARRAS_ACT_spr, 3 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);

                if(vida_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 3 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, 0);
                }

            break;

        }

    }

    for(x = 1 ; x <= MAXIMA_RUNA ; x++){

        switch(x){

            case 1:
                blit(BARRAS_spr, BARRAS_ACT_spr, 0 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);

                if(runa_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 0 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                }

            break;
            case MAXIMA_VIDA:
                blit(BARRAS_spr, BARRAS_ACT_spr, 0 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite_h_flip(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);

                if(runa_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 0 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite_h_flip(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                }

            break;
            default:
                blit(BARRAS_spr, BARRAS_ACT_spr, 1 * (TAMANO_Y_BARRA + 1), 0 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);

                if(runa_actual >= x){
                    blit(BARRAS_spr, BARRAS_ACT_spr, 1 * (TAMANO_Y_BARRA + 1), 1 * (TAMANO_X_BARRA + 1), 0, 0,  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                    draw_sprite(buffer, BARRAS_ACT_spr, x *  TAMANO_Y_BARRA, TAMANO_X_BARRA);
                }

            break;

        }

    }
}

#endif // CLASE_PERSONAJE_JUGADOR_GRAFICOS_H_INCLUDED

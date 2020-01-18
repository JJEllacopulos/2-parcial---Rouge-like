#ifndef CLASE_PERSONAJE_JUGADOR_GRAFICOS_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_GRAFICOS_H_INCLUDED

///-----------------------------------------Graficar jugador---------------------------------------------

void JUGADOR::graficar_jugador(){

    graficar_jugador_barras();

    Graficar_flechas();

    if(frames_animacion_ataque_1.gets_cont_bool() != 0){
        graficar_jugador_ataque_1();
        return;
    }

    if(frames_animacion_ataque_2.gets_cont_bool() != 0){
        graficar_jugador_ataque_2();
        return;

    }

    if(direccion == 0){

        //inavilitar_acciones.sets_tiempo(1);
        graficar_jugador_pocicion_estatica();
        return;

    }
    else{

        //inavilitar_acciones.sets_tiempo(3);
        graficar_jugador_caminar();
        return;

    }

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

    frames_animacion_caminar.control_int();
    inavilitar_acciones.control_int_invertido();
    switch(direccion){

        case 0: ///Estatico.
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Derecha;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Izquierda;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Arriba;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 4: ///Abajo;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 5: ///DERECHA ARRIBA;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 6: ///DERECHA ABAJO;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 7: ///IZQUIERDA ARRIBA;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 8: ///IZQUIERDA ABAJO;
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + inavilitar_acciones.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - inavilitar_acciones.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;
    }

        ///return;

}

///Animacion de ataque 1:
void JUGADOR::graficar_jugador_ataque_1(){

    frames_animacion_ataque_1.control_int();
    inavilitar_acciones.control_int_invertido();
    switch(frente){

        case 0: ///Abajo;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (0 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Izquierda;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite_h_flip(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Arriba;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (2 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Derecha;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

    }

}

///Animacion de ataque 2:
void JUGADOR::graficar_jugador_ataque_2(){

    frames_animacion_ataque_2.control_int();
    inavilitar_acciones.control_int_invertido();
    switch(frente){

        case 0: ///Abajo;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_2.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (0 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_2, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Izquierda;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_2.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_2, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite_h_flip(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Arriba;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_2.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (2 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_2, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Derecha;
            blit(JUGADOR_spr, JUGADOR_attack_spr, (frames_animacion_ataque_2.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_2, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

    }

}

///Amimacion de las barras:
void JUGADOR::Graficar_flechas(){

    int x;

    for(x=0 ; x<3 ; x++){

        if(carcaj[x].gets_activo()){

            if(gets_pocicion_x_guia() == carcaj[x].gets_pocicion_x_guia() && gets_pocicion_y_guia() == carcaj[x].gets_pocicion_y_guia()){
                carcaj[x].Animar_flecha();
            }

        }

    }

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

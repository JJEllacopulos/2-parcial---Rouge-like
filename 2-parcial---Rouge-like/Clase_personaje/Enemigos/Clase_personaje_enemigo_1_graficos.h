#ifndef CLASE_PERSONAJE_MOBS_GRAFICOS_H_INCLUDED
#define CLASE_PERSONAJE_MOBS_GRAFICOS_H_INCLUDED

void ENEMIGO_1::graficar_MOBs(int x_externo, int y_externo){

    if(estado_vivo){
        if(x_externo == gets_pocicion_x_guia()){
            if(y_externo == gets_pocicion_y_guia()){
                Graficar_accion_MOBs();
            }
        }
    }

}

void ENEMIGO_1::Graficar_accion_MOBs(){

    Graficar_accion_MOBs_estado();


    if(frames_animacion_ataque.gets_cont_bool() != 0){
        graficar_jugador_ataque();
        return;
    }
    if(!inavilitar_acciones.gets_cont_bool()){
        if(direccion == 0){

            Graficar_accion_MOBs_pocicion_estatica();
            return;

        }
        else{

            Graficar_accion_MOBs_caminar();
            return;
        }

    }else{
        Graficar_accion_MOBs_pocicion_estatica();
        return;
    }



}


void ENEMIGO_1::Graficar_accion_MOBs_pocicion_estatica(){

    ///Pocicion estatica.
    switch(frente){
        case 0:
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 1:
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 2:
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;
        case 3:
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

    }

}

void ENEMIGO_1::Graficar_accion_MOBs_caminar(){

    ///Animacion de movimiento.

    if(animacion_int.control_bool()){
        animacion_caminar.control_int();
    }

    frame_estatico.control_int_invertido();
    switch(direcion_anima){

        case 0: ///Estatico.
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Derecha;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Izquierda;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Arriba;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 4: ///Abajo;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 5: ///DERECHA ARRIBA;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 6: ///DERECHA ABAJO;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 7: ///IZQUIERDA ARRIBA;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;

        case 8: ///IZQUIERDA ABAJO;
            blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_X);
        break;
    }

    return;

}

///Animacion de ataque:
void ENEMIGO_1::graficar_jugador_ataque(){


    //inavilitar_acciones.control_int_invertido();
    frames_animacion_ataque.control_int();

    switch(frente){

        case 0: ///Abajo;
            blit(ENEMIGO_1_spr, JUGADOR_attack_spr, (frames_animacion_ataque.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (0 * DESPLAZAR_X_SPRITE_ATTACK) + 133, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Izquierda;
            blit(ENEMIGO_1_spr, JUGADOR_attack_spr, (frames_animacion_ataque.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + 133, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite_h_flip(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Arriba;
            blit(ENEMIGO_1_spr, JUGADOR_attack_spr, (frames_animacion_ataque.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (2 * DESPLAZAR_X_SPRITE_ATTACK) + 133, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Derecha;
            blit(ENEMIGO_1_spr, JUGADOR_attack_spr, (frames_animacion_ataque.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + 133, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
            draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);
        break;

    }


}

void ENEMIGO_1::Graficar_accion_MOBs_estado(){

    int x;
    int sprite_corazon;
    int descontar;

    if(vida_actual <= 4){
        sprite_corazon = 0;
        descontar = 0;
    }else{
        if(vida_actual <= 8){
            sprite_corazon = 1;
            descontar = 4;
        }else{
            if(vida_actual <= 12){
                sprite_corazon = 2;
                descontar = 8;
            }
        }
    }



    for(x=0 ; x<4 ; x++){
        if(vida_actual - descontar > x){
            blit(BARRAS_spr, CORAZON_spr, sprite_corazon * 9, 67, 0, 0,  TAMANO_Y_CORAZON, TAMANO_X_CORAZON);
            draw_sprite(buffer, CORAZON_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) + (TAMANO_Y_CORAZON * x) + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - TAMANO_X_CORAZON + ESPACIO_SUPERIOR_X);
        }
    }

}

#endif // CLASE_PERSONAJE_MOBS_GRAFICOS_H_INCLUDED

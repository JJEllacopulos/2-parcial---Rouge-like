#ifndef CLASE_PERSONAJE_ENEMIGO_4_GRAFICOS_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_4_GRAFICOS_H_INCLUDED

void ENEMIGO_4::Graficar_MOBs(int x_externo, int y_externo){

    if(estado_vivo){
        if(x_externo == gets_pocicion_x_guia()){
            if(y_externo == gets_pocicion_y_guia()){
                Graficar_accion_MOBs();
            }
        }
    }

}

void ENEMIGO_4::Graficar_accion_MOBs(){

    Graficar_accion_MOBs_estado();

    Graficar_accion_MOBs_pocicion_estatica();

    Graficar_ataque_rayo();

    /*if(frames_animacion_ataque.gets_cont_bool() != 0){
        Graficar_enemigo_ataque();
        return;
    }*/

}


void ENEMIGO_4::Graficar_accion_MOBs_pocicion_estatica(){

    frames_animacion.control_int();

    ///Pocicion estatica.
    blit(ENEMIGO_4_spr, ENEMIGO_4_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  32, 49);
    draw_sprite(buffer, ENEMIGO_4_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X - 17);

    blit(ENEMIGO_4_spr, ENEMIGO_4_cristal_spr, frames_animacion.gets_cont() * 13, 51, 0, 0,  12, 15);
    draw_sprite(buffer, ENEMIGO_4_cristal_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y + 11, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X - 17);

}

///Animacion de ataque:
void ENEMIGO_4::Graficar_enemigo_ataque(){

    frames_animacion_ataque.control_int();

    blit(ENEMIGO_1_spr, JUGADOR_attack_spr, (frames_animacion_ataque.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (0 * DESPLAZAR_X_SPRITE_ATTACK) + 133, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
    draw_sprite(buffer, JUGADOR_attack_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) - CENTRAR_Y_SPRITE_ATTACK + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - CENTRAR_X_SPRITE_ATTACK + ESPACIO_SUPERIOR_X);

}

///Amimacion del rayo:
void ENEMIGO_4::Graficar_ataque_rayo(){

    int x;

    for(x=0 ; x<RAYOS_ENEMIGO_4 ; x++){

        if(rayo[x].gets_activo()){

            if(gets_pocicion_x_guia() == rayo[x].gets_pocicion_x_guia() && gets_pocicion_y_guia() == rayo[x].gets_pocicion_y_guia()){
                rayo[x].Animar_rayo();
            }

        }

    }

}

void ENEMIGO_4::Graficar_accion_MOBs_estado(){

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
            draw_sprite(buffer, CORAZON_spr, (gets_pocicion_y_juego() * TAMANO_Y_SPRITE) + (TAMANO_Y_CORAZON * x) + ESPACIO_SUPERIOR_Y, (gets_pocicion_x_juego() * TAMANO_X_SPRITE) - TAMANO_X_CORAZON + ESPACIO_SUPERIOR_X - 17);
        }
    }

}

#endif // CLASE_PERSONAJE_ENEMIGO_4_GRAFICOS_H_INCLUDED

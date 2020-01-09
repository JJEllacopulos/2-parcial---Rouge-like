#ifndef CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_H_INCLUDED

class JUGADOR: public PERSONAJE{
    protected:
        int direccion;
        int sprite_personaje;

        BITMAP *personaje_spr;

        CRONO retraso_movimiento;
        CRONO animacion;
        CRONO frame_estatico;
        int direcion_anima;

        int frente;
        CRONO frames_ataque;

    public:

        ///---------------------Propio del padre---------------------
        ///Gets

        int gets_pocicion_x_guia();
        int gets_pocicion_y_guia();
        int gets_pocicion_x_juego();
        int gets_pocicion_y_juego();

        ///Sets:

        void sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego);
        void sets_pocicion_x_guia(int x_guia);
        void sets_pocicion_y_guia(int y_guia);
        void sets_pocicion_x_juego(int x_juego);
        void sets_pocicion_y_juego(int y_juego);

        ///---------------------Propio del hijo---------------------
        JUGADOR(MAPA &mapa);
        void mover_en_mapa_guia();
        void mover_jugador(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

        void graficar_jugador();

        void realizar_ataque(MOB esqueleto[]);
        void atacar(int x_guia, int y_guia, int x_juego, int y_juego, MOB esqueleto[]);

        ///Reiniciar;
        void Reiniciar_jugador(MAPA &mapa);
};

JUGADOR::JUGADOR(MAPA &mapa){

    sprite_personaje = AVATAR;

    retraso_movimiento.sets_tiempo(5);
    animacion.sets_tiempo(9);
    frame_estatico.sets_tiempo(3);
    frames_ataque.sets_tiempo(5);

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    frente = 0;

}

///Reiniciar JUGADOR:
void JUGADOR::Reiniciar_jugador(MAPA &mapa){

    frente = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de movimiento del jugador:
void JUGADOR::rutina_de_movimiento(MAPA &mapa){

    if(!frame_estatico.gets_cont_bool()){

        direccion = 0;

        if(key[KEY_RIGHT]&&key[KEY_UP]){                                               ///DERECHA ARRIBA
                direccion = 5;
                frente = 2;

            }else if(key[KEY_RIGHT]&&key[KEY_DOWN]){                                   ///DERECHA ABAJO
                        direccion = 6;
                        frente = 0;

                    }else if(key[KEY_LEFT]&&key[KEY_UP]){                              ///IZQUIERDA ARRIBA
                                direccion = 7;
                                frente = 2;

                            }else if(key[KEY_LEFT]&&key[KEY_DOWN]){                    ///IZQUIERDA ABAJO
                                        direccion = 8;
                                        frente = 0;

                                    }else if(key[KEY_RIGHT]){                          ///DERECHA
                                                direccion = 1;
                                                frente = 3;

                                            }else if(key[KEY_LEFT]){                   ///IZQUIERDA
                                                        direccion = 2;
                                                        frente = 1;

                                                    }else if(key[KEY_UP]){             ///ARRIBA
                                                            direccion = 3;
                                                            frente = 2;

                                                            }else if(key[KEY_DOWN]){   ///ABAJO
                                                                    direccion = 4;
                                                                    frente = 0;
                                                                    }
                mover_jugador(mapa);
    }
}

///Mover al jugador.
void JUGADOR::mover_jugador(MAPA &mapa){

   int x=0, y=0;   ///variables auxiliares para el uso de las posiciones.

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), PISO); ///ACTIUALIZA EL CARACTER DE PISO EN LA POSICION ANTERIOR

    switch(direccion){

        case 1: ///Derecha;
            y++;
        break;
        case 2: ///Izquierda;
            y--;
        break;
        case 3: ///Arriba;
            x--;
        break;
        case 4: ///Abajo;
            x++;
        break;
        case 5: ///DERECHA ARRIBA;
            x--;
            y++;
        break;
        case 6: ///DERECHA ABAJO;
            x++;
            y++;
        break;
        case 7: ///IZQUIERDA ARRIBA;
            x--;
            y--;
        break;
        case 8: ///IZQUIERDA ABAJO;
            x++;
            y--;
        break;

    }
    if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + x, gets_pocicion_y_juego() +y) == PUERTA){
        mover_en_mapa_guia();
    }
    else{
        if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + x, gets_pocicion_y_juego() +y) == PISO){
            sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
            sets_pocicion_y_juego(gets_pocicion_y_juego() + y);
            direcion_anima = direccion;
        }
        else{
            direccion = 0;
            direcion_anima = 0;
        }
    }

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), sprite_personaje); ///ACTUALIZA LA UBICACION DEL OBJETO
}

void JUGADOR::mover_en_mapa_guia(){

    switch(direccion){
        case 1: ///Derecha:
            sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() + 1, gets_pocicion_x_juego(), 1);

        break;

        case 2:///Izquierda:
            sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() - 1, gets_pocicion_x_juego(), MAX_COLUMNAS_JUEGO-2);

        break;

        case 3:///Arriba:
            sets_pocicion_completa(gets_pocicion_x_guia() - 1, gets_pocicion_y_guia(), MAX_FILAS_JUEGO-2, gets_pocicion_y_juego());

        break;

        case 4:///Abajo:
            sets_pocicion_completa(gets_pocicion_x_guia() + 1, gets_pocicion_y_guia(), 1, gets_pocicion_y_juego());

        break;

    }

}

///-----------------------------------------Graficar jugador---------------------------------------------

void JUGADOR::graficar_jugador(){

    if(direccion == 0){

        ///Pocicion estatica.
        switch(frente){
            case 0:
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 1:
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 2:
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 3:
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

        }
    }
    else{ ///Animacion de movimiento.
        animacion.control_int();
        frame_estatico.control_int_invertido();
        switch(direcion_anima){

            case 0: ///Estatico.
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 1: ///Derecha;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 2: ///Izquierda;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 3: ///Arriba;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 4: ///Abajo;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 5: ///DERECHA ARRIBA;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 6: ///DERECHA ABAJO;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 7: ///IZQUIERDA ARRIBA;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 8: ///IZQUIERDA ABAJO;
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;
        }

        return;
    }
    ///draw_sprite(buffer, AVATAR_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE);
}

void JUGADOR::realizar_ataque(MOB esqueleto[]){

    if(!frames_ataque.control_bool()){
        if(key[KEY_SPACE]){
            if(frente == 0){
                atacar(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()+1, gets_pocicion_y_juego(), esqueleto);
            }
            else if(frente == 1){
                atacar(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-1, esqueleto);
            }
            else if(frente == 2){
                atacar(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-1, gets_pocicion_y_juego(), esqueleto);
            }
            else if(frente == 3){
                atacar(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+1, esqueleto);
            }
        }
    }

}

void JUGADOR::atacar(int x_guia, int y_guia, int x_juego, int y_juego, MOB esqueleto[]){

    int x;

    for(x=0 ; x<CANTIDAD_MODS ; x++){

        if(esqueleto[x].gets_pocicion_x_guia() == x_guia){
            if(esqueleto[x].gets_pocicion_y_guia() == y_guia){
                if(esqueleto[x].gets_pocicion_x_juego() == x_juego){
                    if(esqueleto[x].gets_pocicion_y_juego() == y_juego){

                        esqueleto[x].restar_vida();

                    }
                }
            }
        }

    }

}

///---------------------Propio del padre---------------------

///Gets

int JUGADOR::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int JUGADOR::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int JUGADOR::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int JUGADOR::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void JUGADOR::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void JUGADOR::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void JUGADOR::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void JUGADOR::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void JUGADOR::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_JUGADOR_H_INCLUDED

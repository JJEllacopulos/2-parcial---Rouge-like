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
};

JUGADOR::JUGADOR(MAPA &mapa){

    sprite_personaje = AVATAR;

    retraso_movimiento.sets_tiempo(5);
    animacion.sets_tiempo(9);
    frame_estatico.sets_tiempo(3);

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de movimiento del jugador:
void JUGADOR::rutina_de_movimiento(MAPA &mapa){

    if(!frame_estatico.gets_cont_bool()){

        direccion = 0;

        if(key[KEY_RIGHT]&&key[KEY_UP]){                                               ///DERECHA ARRIBA
                direccion = 5;

            }else if(key[KEY_RIGHT]&&key[KEY_DOWN]){                                   ///DERECHA ABAJO
                        direccion = 6;

                    }else if(key[KEY_LEFT]&&key[KEY_UP]){                              ///IZQUIERDA ARRIBA
                                direccion = 7;

                            }else if(key[KEY_LEFT]&&key[KEY_DOWN]){                    ///IZQUIERDA ABAJO
                                        direccion = 8;

                                    }else if(key[KEY_RIGHT]){                          ///DERECHA
                                                direccion = 1;

                                            }else if(key[KEY_LEFT]){                   ///IZQUIERDA
                                                        direccion = 2;

                                                    }else if(key[KEY_UP]){             ///ARRIBA
                                                            direccion = 3;

                                                            }else if(key[KEY_DOWN]){   ///ABAJO
                                                                    direccion = 4;
                                                                    }
                mover_jugador(mapa);
    }
}

///-----------------------------------------Aun sin terminar---------------------------------------------

void JUGADOR::mover_jugador(MAPA &mapa){

   int x=0, y=0;   ///variables auxiliares para el uso de las posiciones.

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), PISO); ///ACTIUALIZA EL CARACTER DE PISO EN LA POSICION ANTERIOR

    switch(direccion){

        case 1: y++; break; ///Derecha;
        case 2: y--; break; ///Izquierda;
        case 3: x--; break; ///Arriba;
        case 4: x++; break; ///Abajo;
        case 5: x--; y++; break; ///DERECHA ARRIBA;
        case 6: x++; y++; break; ///DERECHA ABAJO;
        case 7: x--; y--; break; ///IZQUIERDA ARRIBA;
        case 8: x++; y--; break; ///IZQUIERDA ABAJO;

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

        blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * TAMANO_Y_SPRITE, 0 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE);
    }
    else{
        animacion.control_int();
        frame_estatico.control_int_invertido();
        switch(direcion_anima){
            case 0:
                blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * TAMANO_Y_SPRITE, 0 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE);
            break;
            case 1:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 7 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE);
            break;
            case 2:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 5 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE);
            break;
            case 3:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 6 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
            case 4:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 4 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
            case 5:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 6 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
            case 6:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 4 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
            case 7:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 6 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
            case 8:
                blit(JUGADOR_spr, JUGADOR_mov_spr, animacion.gets_cont() * TAMANO_Y_SPRITE, 4 * TAMANO_X_SPRITE, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT);
            break;
        }

        return;
    }
    ///draw_sprite(buffer, AVATAR_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE);
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

#ifndef CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

#define RETRAZO_MOVIMIENTO_MOB 3 ///Intrevalo entre movimientos de los MOBs
#define CANTIDAD_MODS 15

/// IDENTIFICACION DE CUADRANTES
    int buscar_cuadrante(int x, int y, int i, int j){   ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


    if(y<j&&x<i){       /// PRIMER * derecha abajo
        return 8;
    }else if(y==j&&x<i){///SEGUNDO * abajo
        return 2;
    }else if(y>j&&x<i){ /// TERCER * iizquierda abajo
        return 6;
    }else if(y<j&&x==i){/// CUARTO * derecha
        return 4;                               /// * QUINTO ES LA pocicion DEL OBJETO ENEMIGO
    }else if(y>j&&x==i){///  SEXTO * izquierda
        return 3;
    }else if(y<j&&x>i){/// SEPTIMO * derecha arriba
        return 7;
    }else if(y==j&&x>i){/// OCTAVO * arriba
        return 1;
    }else if(y>j&&x>i){///  NOVENO * izquierda arriba
        return 9;
    }
}


class MOB: public PERSONAJE{
    protected:
        int direccion;

        int sprite_personaje;

        int vision;
        int movimiento;
        int velocidad;

        int vida;
        bool vivo;



        CRONO retraso_movimiento;

        CRONO animacion;
        CRONO animacion_int;

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
        ///Gets
        int gets_velocidad(){return velocidad;}
        int gets_sprite(){return sprite_personaje;}
        int gets_vision(){return vision;}
        int gets_vida(){return vida;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}
        void sets_vida(int aux){vida = aux;}
        void restar_vida();
        void muerte();



        MOB(/*MAPA &mapa*/);

        int asechar(MAPA &mapa);
        void realisar_movimiento(MAPA &mapa, int x_guia, int y_guia, int x_mapa, int y_mapa);
        void mover_MOB(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

        void Graficar_movimiento_MOBs();
        void graficar_MOBs(int x_externo, int y_externo);

        ///Reiniciar MOBs:
        void Reiniciar_MOBs(MAPA &mapa);

};

MOB::MOB(/*MAPA &mapa*/){

    sprite_personaje = ENEMIGO;
    retraso_movimiento.sets_tiempo(10);

    velocidad=25;
    vision=5;

    retraso_movimiento.sets_tiempo(5);

    animacion.sets_tiempo(2);
    animacion_int.sets_tiempo(1);

    frame_estatico.sets_tiempo(3);
    frames_ataque.sets_tiempo(5);

    ///PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    vida = 3;
    vivo = true;
    frente = 0;

}

///Reiniciar MOBs:
void MOB::Reiniciar_MOBs(MAPA &mapa){

    vida = 3;
    vivo = true;
    frente = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de MOBimiento del jugador:
void MOB::rutina_de_movimiento(MAPA &mapa){

    if(!frame_estatico.gets_cont_bool()){

        direccion = 0;

        if(!retraso_movimiento.control_bool_invertido()){

            /// pocicion ACTUAL DEL OBJETO
            int x_guia=PERSONAJE::gets_pocicion_x_guia();
            int y_guia=PERSONAJE::gets_pocicion_y_guia();
            int x_mapa=PERSONAJE::gets_pocicion_x_juego();
            int y_mapa=PERSONAJE::gets_pocicion_y_juego();
                                                    /// VARIABLES AUXILIARES
            int x=0, y=0;
            int cuadrante=0;
            int dir = 0;

            mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO

            dir = ((rand()) % gets_velocidad());                          ///RANGO DE VELOCIDAD INVERSO (CUANTO MAS ALTO, MAS LENTO)

            cuadrante=asechar(mapa);                                     ///SI ENCUENTRA AL CARACTER PERSONAJE ENTONCES SEÑALA EL CUADRANTE

            if(cuadrante!=0){

                dir=cuadrante;
            }

            switch(dir){                     /// SI Y SOLO SI HAY ESPACIO PARA MOVERSE, SE MOVERA EN DIRECCION DEL SWITCH

                case 1: ///ARRIBA:
                    direccion = 3;
                    frente = 2;
                    x--;
                break;

                case 2: ///ABAJO:
                    direccion = 4;
                    frente = 0;
                    x++;
                break;

                case 3: ///IZQUIERDA:
                    direccion = 2;
                    frente = 1;
                    y--;
                break;

                case 4: ///DERECHA:
                    direccion = 1;
                    frente = 3;
                    y++;
                break;

                case 9: ///IZQUIERDA ARRIBA
                    direccion = 7;
                    frente = 2;
                    x--;
                    y--;
                break;

                case 6: ///IZQUIERDA ABAJO
                    direccion = 8;
                    frente = 0;
                    x++;
                    y--;
                break;

                case 8: ///DERECHA ABAJO
                    direccion = 6;
                    frente = 0;
                    x++;
                    y++;
                break;

                case 7: ///DERECHA ARRIBA
                    direccion = 5;
                    frente = 2;
                    x--;
                    y++;
                break;

                default: /// EN ESTE CASO DEBERIA HABER UN IDDLE DE ANIMACION PASIVA
                    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                break;
                // iddle(mapa); break;        ///AÑADIR ANIMACION PASIVA

            }

            if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa + x, y_mapa + y)== PISO){
                realisar_movimiento(mapa, x_guia, y_guia, x_mapa + x, y_mapa + y);
                direcion_anima = direccion;
            }else {
                mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                direcion_anima = 0;
                direccion = 0;
            }

        }
    }
}

void MOB::realisar_movimiento(MAPA &mapa,  int x_guia, int y_guia, int x_mapa, int y_mapa){

    PERSONAJE::sets_pocicion_completa(x_guia, y_guia, x_mapa, y_mapa);        ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL OBJETO
    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, sprite_personaje);  ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL MAPA

}

int MOB::asechar(MAPA &mapa){

    int contador=0;

    int x=PERSONAJE::gets_pocicion_x_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
    int y=PERSONAJE::gets_pocicion_y_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
    int v= gets_vision();
    int i=x-v; int I=x+v;
    int j=x-v; int J=y+v;


    int cuadrante=0;                ///CUADRANTE INICIAL

    for(i; i<=I; i++ ){

        for(j=y-v; j<=J; j++ ){ ///INICIO DEL FOR EN Y

            if(mapa.gets_mapa_juego(PERSONAJE::gets_pocicion_x_guia(), PERSONAJE::gets_pocicion_y_guia(),i,j)==AVATAR){

                 ///cout<<"\nENCONTRO AL AVATAR EN X: "<<i;
                 ///cout<<"\nENCONTRO AL AVATAR EN Y: "<<j;

                cuadrante=buscar_cuadrante(x, y, i, j);

                return cuadrante; ///Se corta el for una vez encontrado lo buscado.

            }
         }
    }

    return cuadrante;
}

void MOB::mover_MOB(MAPA &mapa){

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), PISO);

    switch(direccion){
        case 0: ///Derecha:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego() + 1) == PISO){
                sets_pocicion_y_juego(gets_pocicion_y_juego() + 1);
            }

        break;

        case 1:///Izquierda:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego() - 1) == PISO){
                sets_pocicion_y_juego(gets_pocicion_y_juego() - 1);
            }

        break;

        case 2:///Arriba:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() - 1, gets_pocicion_y_juego()) == PISO){
                sets_pocicion_x_juego(gets_pocicion_x_juego() - 1);
            }

        break;

        case 3:///Abajo:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + 1, gets_pocicion_y_juego()) == PISO){
                sets_pocicion_x_juego(gets_pocicion_x_juego() + 1);
            }

        break;

    }

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), sprite_personaje);
}

void MOB::graficar_MOBs(int x_externo, int y_externo){

    if(vivo){
        if(x_externo == gets_pocicion_x_guia()){
            if(y_externo == gets_pocicion_y_guia()){
                Graficar_movimiento_MOBs();
            }
        }
    }

}

void MOB::Graficar_movimiento_MOBs(){

    if(direccion == 0){

        ///Pocicion estatica.
        switch(frente){
            case 0:
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 1:
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite_h_flip(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 2:
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;
            case 3:
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_X_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

        }
    }
    else{ ///Animacion de movimiento.

        if(animacion_int.control_bool()){
            animacion.control_int();
        }

        frame_estatico.control_int_invertido();
        switch(direcion_anima){

            case 0: ///Estatico.
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 1: ///Derecha;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 2: ///Izquierda;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite_h_flip(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_Y);
            break;

            case 3: ///Arriba;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 4: ///Abajo;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 5: ///DERECHA ARRIBA;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 6: ///DERECHA ABAJO;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 7: ///IZQUIERDA ARRIBA;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE + frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;

            case 8: ///IZQUIERDA ABAJO;
                blit(ENEMIGO_1_spr, ENEMIGO_1_mov_spr, animacion.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
                draw_sprite(buffer, ENEMIGO_1_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + frame_estatico.gets_cont() * TAMANO_Y_SPRITE_INT, gets_pocicion_x_juego() * TAMANO_X_SPRITE - frame_estatico.gets_cont() * TAMANO_X_SPRITE_INT + ESPACIO_SUPERIOR_Y);
            break;
        }

        return;
    }
    ///draw_sprite(buffer, AVATAR_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE, gets_pocicion_x_juego() * TAMANO_X_SPRITE);
}

void MOB::restar_vida(){
    if(vida > 0){
        vida--;
    }
    else{
        muerte();
    }
}

void MOB::muerte(){
    vivo = false;
    sprite_personaje = PISO;
}

///---------------------Propio del padre---------------------

///Gets

int MOB::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int MOB::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int MOB::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int MOB::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void MOB::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void MOB::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void MOB::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void MOB::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void MOB::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

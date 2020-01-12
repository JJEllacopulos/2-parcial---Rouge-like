#ifndef CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_H_INCLUDED

#define MAXIMA_VIDA 30
#define MAXIMA_RUNA 30

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

        ///Estadisticas del jugador:
        int vida_actual;
        int vida_maxima;
        int runa_actual;
        int runa_maxima;

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
        JUGADOR(/*MAPA &mapa*/);
        void mover_en_mapa_guia();
        void mover_jugador(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

        void realizar_ataque(MOB esqueleto[]);
        void atacar(int x_guia, int y_guia, int x_juego, int y_juego, MOB esqueleto[]);

        ///Animaciones:
        void graficar_jugador();
        void graficar_jugador_pocicion_estatica();
        void graficar_jugador_caminar();
        void graficar_jugador_barras();

        ///Iniciar y reiniciar las estadisticas;
        void Reiniciar_jugador(MAPA &mapa);
};

JUGADOR::JUGADOR(/*MAPA &mapa*/){

    sprite_personaje = AVATAR;

    retraso_movimiento.sets_tiempo(5);
    animacion.sets_tiempo(9);
    frame_estatico.sets_tiempo(3);
    frames_ataque.sets_tiempo(5);

    ///PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    frente = 0;

}

///Reiniciar JUGADOR:
void JUGADOR::Reiniciar_jugador(MAPA &mapa){

    frente = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    vida_actual = 30;
    vida_maxima = MAXIMA_VIDA;
    runa_actual = 30;
    runa_maxima = MAXIMA_RUNA;
}

///-------------------------------------------Rutina de movimiento del jugador:
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
        sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
        sets_pocicion_y_juego(gets_pocicion_y_juego() + y);
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

///Mover entre sub-mapas:
void JUGADOR::mover_en_mapa_guia(){

    if(gets_pocicion_y_juego() ==  MAX_COLUMNAS_JUEGO-1){ ///Derecha:
        sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() + 1, gets_pocicion_x_juego(), 1);
    }///else
    if(gets_pocicion_y_juego() ==  0){ ///Izquierda:
        sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() - 1, gets_pocicion_x_juego(), MAX_COLUMNAS_JUEGO-2);
    }else
    if(gets_pocicion_x_juego() == 0){ ///Arriba:
        sets_pocicion_completa(gets_pocicion_x_guia() - 1, gets_pocicion_y_guia(), MAX_FILAS_JUEGO-2, gets_pocicion_y_juego());
    }else
    if(gets_pocicion_x_juego() == MAX_FILAS_JUEGO-1){ ///Abajo:
        sets_pocicion_completa(gets_pocicion_x_guia() + 1, gets_pocicion_y_guia(), 1, gets_pocicion_y_juego());
    }

}

///-------------------------------------------Rutina de ataque

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

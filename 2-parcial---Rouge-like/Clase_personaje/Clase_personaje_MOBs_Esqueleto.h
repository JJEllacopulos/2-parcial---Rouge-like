#ifndef CLASE_PERSONAJE_MOBS_ESQUELETO_H_INCLUDED
#define CLASE_PERSONAJE_MOBS_ESQUELETO_H_INCLUDED

/// Aun le falta modificarlo:

class ESQUELETO: public PERSONAJE{
    protected:
        int direccion;

        int retrazo;

        int sprite_personaje;

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
        MOB(MAPA &mapa);

        void MOBer_MOB(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

};

ESQUELETO::ESQUELETO(MAPA &mapa){

    sprite_personaje = ENEMIGO;
    retrazo = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de MOBimiento del jugador:
void ESQUELETO::rutina_de_movimiento(MAPA &mapa){

    if(retrazo == RETRAZO_MOVIMIENTO_MOB){
        direccion = direccion = ((rand()) % 4);
        MOBer_MOB(mapa);
        retrazo = 0;
    }
    else{
        retrazo++;
    }

}

void ESQUELETO::MOBer_MOB(MAPA &mapa){

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

///---------------------Propio del padre---------------------

///Gets

int ESQUELETO::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int ESQUELETO::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int ESQUELETO::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int ESQUELETO::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void ESQUELETO::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void ESQUELETO::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void ESQUELETO::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void ESQUELETO::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void ESQUELETO::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_MOBS_ESQUELETO_H_INCLUDED

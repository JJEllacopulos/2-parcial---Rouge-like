#ifndef CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

#define RETRAZO_MOVIMIENTO_MOB 5 ///Intrevalo entre movimientos de los MOBs

class MOB: public PERSONAJE{
    protected:
        int direccion;

        int retrazo;

        int sprite_personaje;


        int vision;
        int movimiento;
        int velocidad;

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

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}



        MOB(MAPA &mapa);

        void mover_MOB(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

};

MOB::MOB(MAPA &mapa){

    sprite_personaje = ENEMIGO;
    retrazo = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de MOBimiento del jugador:
void MOB::rutina_de_movimiento(MAPA &mapa){

    if(retrazo == RETRAZO_MOVIMIENTO_MOB){
        direccion = direccion = ((rand()) % 4);
        mover_MOB(mapa);
        retrazo = 0;
    }
    else{
        retrazo++;
    }
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

#ifndef CLASE_PERSONAJE_JUGADOR_SKJALDMO_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_SKJALDMO_H_INCLUDED

class SKJALDOM: public JUGADOR{
    protected:
        int vida_maxima;
        int vida_actual;

        int daño;

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
        SKJALDOM(MAPA &mapa);
        void mover_skjaldom(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

};

SKJALDOM::SKJALDOM(MAPA &mapa){

    sprite_personaje = AVATAR;

    SKJALDOM::iniciar_personaje(mapa, sprite_personaje);

    /*
    PERSONAJE::cargar_sprite("Imagenes/Viajero_1.bmp");
    PERSONAJE::graficar_personaje();
    */
}

///Rutina de movimiento del jugador:
void SKJALDOM::rutina_de_movimiento(MAPA &mapa){



}

///---------------------Propio del padre---------------------

///Gets

int SKJALDOM::gets_pocicion_x_guia(){
    return JUGADOR::gets_pocicion_x_guia();
}

int SKJALDOM::gets_pocicion_y_guia(){
    return JUGADOR::gets_pocicion_y_guia();
}

int SKJALDOM::gets_pocicion_x_juego(){
    return JUGADOR::gets_pocicion_x_juego();
}

int SKJALDOM::gets_pocicion_y_juego(){
    return JUGADOR::gets_pocicion_y_juego();
}

///Sets:

void SKJALDOM::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    JUGADOR::sets_pocicion_x_guia(x_guia);
    JUGADOR::sets_pocicion_y_guia(y_guia);
    JUGADOR::sets_pocicion_x_juego(x_juego);
    JUGADOR::sets_pocicion_y_juego(y_juego);

}

void SKJALDOM::sets_pocicion_x_guia(int x_guia){
    JUGADOR::sets_pocicion_x_guia(x_guia);
}

void SKJALDOM::sets_pocicion_y_guia(int y_guia){
    JUGADOR::sets_pocicion_y_guia(y_guia);
}

void SKJALDOM::sets_pocicion_x_juego(int x_juego){
    JUGADOR::sets_pocicion_x_juego(x_juego);
}

void SKJALDOM::sets_pocicion_y_juego(int y_juego){
    JUGADOR::sets_pocicion_y_juego(y_juego);
}


#endif // CLASE_PERSONAJE_JUGADOR_SKJALDMO_H_INCLUDED

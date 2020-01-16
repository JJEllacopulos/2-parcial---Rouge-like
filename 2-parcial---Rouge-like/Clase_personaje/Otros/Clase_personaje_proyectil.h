#ifndef CLASE_PERSONAJE_PROYECTIL_H_INCLUDED
#define CLASE_PERSONAJE_PROYECTIL_H_INCLUDED

class PROYECTIL: public PERSONAJE{
    protected:

    //Indica si el proyectil esta activo.
    //bool activo;

    //Indica quien lanzo el proyectil y quien puede recivirlo.
    //bool lanzador;

    ///Indica en que direccion fue lanzado;
    int direccion_movimiento;
    //Indica su recorrido maximo antes de desactivarce.
    //int duracion;

    ///Animaciones:
    int tipo_proyectil;
    //CRONO desplazamineto;
    //CRONO frames_animacion_movimiento;

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

        ///---Constructor:
        PROYECTIL();

        ///---Iniciar proyectil;
        void Iniciar_proyectil(int direccion, int tipo, int x_guia, int y_guia, int x_juego, int y_juego);
        void Mover_proyectil();
        void Animar_proyectil(int espacio, int desplazar, int animacion);

};

///---------------------Propio del hijo------------------

PROYECTIL::PROYECTIL(){
    //inavilitar_acciones.sets_tiempo(3);
    //frames_animacion_movimiento.sets_tiempo(3);
}

///---Iniciar proyectil:
void PROYECTIL::Iniciar_proyectil(int direccion, int tipo, int x_guia, int y_guia, int x_juego, int y_juego){

    sets_pocicion_completa(x_guia, y_guia, x_juego, y_juego);
    //desplazamineto.sets_tiempo(tiempo);
    direccion_movimiento = direccion;
    tipo_proyectil = tipo;

}

///---Mover proyectil:
void PROYECTIL::Mover_proyectil(){

    int x = 0, y = 0;

    switch(direccion_movimiento){
        case 1: ///Derecha;
            x ++;
        break;

        case 2: ///Izquierda;
            x--;
        break;

        case 3: ///Arriba;
            y++;
        break;

        case 4: ///Abajo;
            y--;
        break;
    }

    sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
    sets_pocicion_y_juego(gets_pocicion_y_juego() + y);

}

///---Graficar proyectil:
void PROYECTIL::Animar_proyectil(int espacio, int desplazar, int animacion){


    switch(direccion_movimiento){
        case 1: ///Derecha;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion * DESPLAZAR_Y_PIXEL, 2 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - desplazar * espacio + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Izquierda;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + desplazar * espacio + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Arriba;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + desplazar * espacio + ESPACIO_SUPERIOR_X);
        break;

        case 4: ///Abajo;
            blit(JUGADOR_spr, JUGADOR_mov_spr, animacion * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - desplazar * espacio + ESPACIO_SUPERIOR_X);
        break;
    }
}

///---------------------Propio del padre---------------------

///Gets

int PROYECTIL::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int PROYECTIL::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int PROYECTIL::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int PROYECTIL::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void PROYECTIL::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void PROYECTIL::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void PROYECTIL::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void PROYECTIL::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void PROYECTIL::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_PROYECTIL_H_INCLUDED

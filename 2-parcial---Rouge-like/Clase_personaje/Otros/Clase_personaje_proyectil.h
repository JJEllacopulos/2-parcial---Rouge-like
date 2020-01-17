#ifndef CLASE_PERSONAJE_PROYECTIL_H_INCLUDED
#define CLASE_PERSONAJE_PROYECTIL_H_INCLUDED

class PROYECTIL: public PERSONAJE{
    protected:

    ///Indica en que direccion fue lanzado;
    int frente;

    ///Animaciones:
    int sprite;

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

        ///---Rutinas de proyectil:
        bool Mover_proyectil(MAPA &mapa);
        void Animar_proyectil(int espacio, int desplazar);

        ///---Gets:

        int gets_frente();
        int gets_sprite();

        ///---Sets:

        void sets_frente(int x);
        void sets_sprite(int x);

};

///---------------------Propio del hijo------------------

PROYECTIL::PROYECTIL(){}

///---Iniciar proyectil:
void PROYECTIL::Iniciar_proyectil(int direccion, int tipo, int x_guia, int y_guia, int x_juego, int y_juego){

    sets_pocicion_completa(x_guia, y_guia, x_juego, y_juego);
    frente = direccion;
    sprite = tipo;

}

///---Mover proyectil:
bool PROYECTIL::Mover_proyectil(MAPA &mapa){

    int x = 0, y = 0;

    switch(frente){
        case 0: ///ABAJO
            x ++;
        break;

        case 1: ///IZQUIERDA
            y--;
        break;

        case 2: ///ARRIBA
            x--;
        break;

        case 3: ///DERECHA
            y++;
        break;

    }

    if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + x, gets_pocicion_y_juego() +y) == PISO){
        sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
        sets_pocicion_y_juego(gets_pocicion_y_juego() + y);

        return true;
    }

    return false;
}

///---Graficar proyectil:
void PROYECTIL::Animar_proyectil(int espacio, int desplazar){


    switch(frente){

        case 0: ///Abajo;
            blit(PROYECTILES_spr, PROYECTIL_mov_spr, 0 * DESPLAZAR_Y_PIXEL, sprite * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_v_flip(buffer, PROYECTIL_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE - desplazar * espacio + ESPACIO_SUPERIOR_X);
        break;

        case 1: ///Izquierda;
            blit(PROYECTILES_spr, PROYECTIL_mov_spr,  1 * DESPLAZAR_Y_PIXEL, sprite * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite_h_flip(buffer, PROYECTIL_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + desplazar * espacio + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

        case 2: ///Arriba;
            blit(PROYECTILES_spr, PROYECTIL_mov_spr,  0 * DESPLAZAR_Y_PIXEL, sprite * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, PROYECTIL_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + desplazar * espacio + ESPACIO_SUPERIOR_X);
        break;

        case 3: ///Derecha;
            blit(PROYECTILES_spr, PROYECTIL_mov_spr,  1 * DESPLAZAR_Y_PIXEL, sprite * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, PROYECTIL_mov_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE - desplazar * espacio + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);
        break;

    }
}


///---Gets:

int PROYECTIL::gets_frente(){
    return frente;
}

int PROYECTIL::gets_sprite(){
    return sprite;
}

///---Sets:

void PROYECTIL::sets_frente(int x){
    frente = x;
}

void PROYECTIL::sets_sprite(int x){
    sprite = x;
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

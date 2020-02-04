#ifndef CLASE_PERSONAJE_PILAR_H_INCLUDED
#define CLASE_PERSONAJE_PILAR_H_INCLUDED

class RAYO: public PERSONAJE{
    protected:

    bool activo;
    bool ataque_activo;

    int dano_rayo;

    CRONO animacion;


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
        RAYO();

        ///---Iniciar proyectil;
        void Iniciar_rayo(int dano_ing, int x_guia, int y_guia, int x_juego, int y_juego);
        void Desactivar_rayo();

        ///---Rutinas de proyectil:
        void Animar_rayo();

        ///Ataque:
        int Realizar_ataque_rayo(int x_guia, int y_guia, int x_juego, int y_juego, bool escudo);
        bool verificar_inpacto(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo);

        ///---Gets:
        bool gets_activo();

        bool gets_ataque_activo();

        ///---Sets:

        void sets_activo(bool x);

        void sets_ataque_activo(bool x);

};

///---------------------Propio del hijo------------------

RAYO::RAYO(){

    animacion.sets_tiempo(6);

}

void RAYO::Desactivar_rayo(){
    activo = false;
    ataque_activo = false;
}

///---Iniciar proyectil:
void RAYO::Iniciar_rayo(int dano_ing, int x_guia, int y_guia, int x_juego, int y_juego){

    activo = true;
    ataque_activo = true;
    dano_rayo = dano_ing;

    animacion.sets_cont(1);

    sets_pocicion_completa(x_guia, y_guia, x_juego, y_juego);

}

///---Graficar proyectil:
void RAYO::Animar_rayo(){

    blit(PILARES_spr, RAYO_spr, (animacion.gets_cont() - 1) * 17, 66, 0, 0,  TAMANO_X_SPRITE_RAYO, TAMANO_Y_SPRITE_RAYO);
    draw_sprite_v_flip(buffer, RAYO_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y + 8, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X - 16);

    animacion.control_int();

    if(animacion.gets_cont_bool()){
        return;
    }

    activo = false;
    ataque_activo = false;
}

int RAYO::Realizar_ataque_rayo(int x_guia, int y_guia, int x_juego, int y_juego, bool escudo){
    int dano = 0;


        if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){
            if(verificar_inpacto(gets_pocicion_x_juego(), gets_pocicion_y_juego(), x_juego, y_juego)){
                if(!escudo){
                    dano += dano_rayo;
                }
                ataque_activo = false;
            }
        }


    return dano;
}

bool RAYO::verificar_inpacto(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        return true;
    }

    return false;

}


///---Gets:

bool RAYO::gets_activo(){
    return activo;
}

bool RAYO::gets_ataque_activo(){
    return ataque_activo;
}

///---Sets:

void RAYO::sets_activo(bool x){
    activo = x;
}

void RAYO::sets_ataque_activo(bool x){
    ataque_activo = x;
}


///---------------------Propio del padre---------------------

///Gets

int RAYO::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int RAYO::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int RAYO::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int RAYO::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void RAYO::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void RAYO::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void RAYO::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void RAYO::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void RAYO::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_PILAR_H_INCLUDED

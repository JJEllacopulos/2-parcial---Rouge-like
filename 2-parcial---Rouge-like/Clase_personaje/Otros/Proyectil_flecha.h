#ifndef PROYECTIL_FLECHA_H_INCLUDED
#define PROYECTIL_FLECHA_H_INCLUDED

class FLECHA: public PROYECTIL{
    protected:
        ///Indica si la flecha esta en el aire:
        bool activo;

        ///Indica el daño de la flecha;
        int dano_flecha;

        ///Indica si la flecha a inpactado con algo.
        //bool impacto_flecha;

        ///Relojes:
        CRONO inavilitar_acciones;
        //CRONO frames_animacion_desplasamiento;

    public:
        ///---------------------Propio del padre---------------------
        ///Gets

        int gets_pocicion_x_guia();
        int gets_pocicion_y_guia();
        int gets_pocicion_x_juego();
        int gets_pocicion_y_juego();

        int gets_frente();
        int gets_sprite();

        ///Sets:

        void sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego);
        void sets_pocicion_x_guia(int x_guia);
        void sets_pocicion_y_guia(int y_guia);
        void sets_pocicion_x_juego(int x_juego);
        void sets_pocicion_y_juego(int y_juego);

        void sets_frente(int x);
        void sets_sprite(int x);

        ///---------------------Propio del hijo---------------------

        ///---Constructor:
        FLECHA();

        ///---Iniciar, reiniciar y desactivar la flecha:
        void Iniciar_flecha(int direccion, int tipo, int dano, int x_guia, int y_guia, int x_juego, int y_juego);
        void Desactivar_flecha();


        ///---Mover flecha:
        void Rutinas_flecha(MAPA &mapa);
        void Mover_flecha(MAPA &mapa);
        bool verificar_inpacto(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo);
        int Realizar_ataque_flecha(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo, int escudo);

        ///---Animacion:
        void Animar_flecha();

        ///Gets

        bool gets_activo();

        int gets_dano_flecha();

        ///Sets:

        void sets_activo(bool x);

        void sets_dano_flecha(int x);

};

///---------------------Propio del hijo---------------------

///---Constructor:
FLECHA::FLECHA(){
    activo = false;
    inavilitar_acciones.sets_tiempo(2);
    //impacto_flecha = false;
}

///---Iniciar, reiniciar y desactivar la flecha:
void FLECHA::Iniciar_flecha(int direccion, int tipo, int dano, int x_guia, int y_guia, int x_juego, int y_juego){

    activo = true;
    PROYECTIL::Iniciar_proyectil(direccion, tipo, x_guia, y_guia, x_juego, y_juego);
    dano_flecha = dano;
    inavilitar_acciones.sets_cont(0);

}

void FLECHA::Desactivar_flecha(){
    activo = false;
}


///---Mover flecha:
void FLECHA::Rutinas_flecha(MAPA &mapa){

    if(activo){
        Mover_flecha(mapa);
    }
}

void FLECHA::Mover_flecha(MAPA &mapa){

    if(!inavilitar_acciones.gets_cont_bool()){
        activo = PROYECTIL::Mover_proyectil(mapa);
    }
}

int FLECHA::Realizar_ataque_flecha(int x_guia, int y_guia, int x_juego, int y_juego, int escudo){
    int dano = 0;

    if(!inavilitar_acciones.gets_cont_bool()){
        if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){
            if(frente == 0){
                if(verificar_inpacto(gets_pocicion_x_juego()+1, gets_pocicion_y_juego(), x_juego, y_juego)){
                    if(frente != escudo){
                        dano += dano_flecha;
                    }
                    activo = false;
                    //Desactivar_flecha();
                }
            }
            else if(frente == 1){
                if(verificar_inpacto(gets_pocicion_x_juego(), gets_pocicion_y_juego()-1, x_juego, y_juego)){
                    if(frente != escudo){
                        dano += dano_flecha;
                    }
                    activo = false;
                    //Desactivar_flecha();
                }
            }
            else if(frente == 2){
                if(verificar_inpacto(gets_pocicion_x_juego()-1, gets_pocicion_y_juego(),x_juego, y_juego)){
                    if(frente != escudo){
                        dano += dano_flecha;
                    }
                    activo = false;
                    //Desactivar_flecha();
                }
            }
            else if(frente == 3){
                if(verificar_inpacto(gets_pocicion_x_juego(), gets_pocicion_y_juego()+1, x_juego, y_juego)){
                    if(frente != escudo){
                        dano += dano_flecha;
                    }
                    activo = false;
                    //Desactivar_flecha();
                }
            }
        }
    }
    return dano;
}

bool FLECHA::verificar_inpacto(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        return true;
    }

    return false;

}

///---Animacion:
void FLECHA::Animar_flecha(){

    PROYECTIL::Animar_proyectil(8,inavilitar_acciones.control_int_invertido());
}

///Gets

bool FLECHA::gets_activo(){
    return activo;
}

int FLECHA::gets_dano_flecha(){
    return dano_flecha;
}

///Sets:

void FLECHA::sets_activo(bool x){
    activo = x;
}

void FLECHA::sets_dano_flecha(int x){
    dano_flecha = x;
}

///---------------------Propio del padre---------------------

///Gets

int FLECHA::gets_pocicion_x_guia(){
    return PROYECTIL::gets_pocicion_x_guia();
}

int FLECHA::gets_pocicion_y_guia(){
    return PROYECTIL::gets_pocicion_y_guia();
}

int FLECHA::gets_pocicion_x_juego(){
    return PROYECTIL::gets_pocicion_x_juego();
}

int FLECHA::gets_pocicion_y_juego(){
    return PROYECTIL::gets_pocicion_y_juego();
}


int FLECHA::gets_frente(){
    return PROYECTIL::gets_frente();
}

int FLECHA::gets_sprite(){
    return PROYECTIL::gets_sprite();
}


///Sets:

void FLECHA::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PROYECTIL::sets_pocicion_x_guia(x_guia);
    PROYECTIL::sets_pocicion_y_guia(y_guia);
    PROYECTIL::sets_pocicion_x_juego(x_juego);
    PROYECTIL::sets_pocicion_y_juego(y_juego);

}

void FLECHA::sets_pocicion_x_guia(int x_guia){
    PROYECTIL::sets_pocicion_x_guia(x_guia);
}

void FLECHA::sets_pocicion_y_guia(int y_guia){
    PROYECTIL::sets_pocicion_y_guia(y_guia);
}

void FLECHA::sets_pocicion_x_juego(int x_juego){
    PROYECTIL::sets_pocicion_x_juego(x_juego);
}

void FLECHA::sets_pocicion_y_juego(int y_juego){
    PROYECTIL::sets_pocicion_y_juego(y_juego);
}


void FLECHA::sets_frente(int x){
    PROYECTIL::sets_frente(x);
}

void FLECHA::sets_sprite(int x){
    PROYECTIL::sets_sprite(x);
}

#endif // PROYECTIL_FLECHA_H_INCLUDED

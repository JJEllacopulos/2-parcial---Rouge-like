#ifndef CLASE_PERSONAJE_ENEMIGO_4_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_4_H_INCLUDED

#define RAYOS_ENEMIGO_4 4

class ENEMIGO_4: public PERSONAJE{
    protected:
        int sprite_personaje;

        ///Estadisticas del MOB:
        int vida_actual;
        int vida_maxima;
        bool estado_vivo;

        CRONO retraso_movimiento;
        CRONO frames_animacion;
        CRONO frame_estatico;

        CRONO frames_animacion_ataque;
        CRONO inavilitar_acciones;

        ///Ataque:
        bool ataque_rayo;
        RAYO rayo[RAYOS_ENEMIGO_4];

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
        int gets_sprite(){return sprite_personaje;}
        int gets_vida(){return vida_actual;}
        bool gets_estado_vivo(){return estado_vivo;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}
        void sets_vida(int aux){vida_actual = aux;}
        void restar_vida(int dano);
        void muerte();


        ///Constructor.
        ENEMIGO_4(/*MAPA &mapa*/);

        ///--- Rutinas del enemigo 1:
        void Rutinas(MAPA &mapa);

        ///Rutina de ataque:
        int realizar_ataque(MAPA &mapa ,int x_guia, int y_guia, int x_juego, int y_juego);
        bool verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo);

        ///Graficar MOB:
        void Graficar_MOBs(int x_externo, int y_externo);
        void Graficar_accion_MOBs();
        void Graficar_accion_MOBs_pocicion_estatica();
        void Graficar_enemigo_ataque();
        void Graficar_ataque_rayo();
        void Graficar_accion_MOBs_estado();

        ///Iniciar y reiniciar las estadisticas del MOBs:
        void Reiniciar_MOBs(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);
        void iniciar_pocicion_enemigo(MAPA &mapa, int sprite_personaje, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

};

ENEMIGO_4::ENEMIGO_4(/*MAPA &mapa*/){

    sprite_personaje = ENEMIGO;

    retraso_movimiento.sets_tiempo(5);
    frames_animacion.sets_tiempo(14);
    frames_animacion_ataque.sets_tiempo(2);
    frame_estatico.sets_tiempo(3);
    inavilitar_acciones.sets_tiempo(3);

}

///Reiniciar MOBs:
void ENEMIGO_4::Reiniciar_MOBs(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    vida_maxima = 6;
    vida_actual = vida_maxima;
    estado_vivo = true;
    sprite_personaje = ENEMIGO;

    int x;

    for(x=0 ; x<RAYOS_ENEMIGO_4 ; x++){

        if(rayo[x].gets_activo()){
            rayo[x].Desactivar_rayo();
        }

    }

    iniciar_pocicion_enemigo(mapa, sprite_personaje, pocicion_x_no_aseptable, pocicion_y_no_aseptable);

}

void ENEMIGO_4::iniciar_pocicion_enemigo(MAPA &mapa, int sprite_personaje, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x_externo;
    int y_externo;
    int x_interno;
    int y_interno;

    int moneda;

    while(true){

        for(x_externo=0;x_externo<MAX_FILAS_GUIA;x_externo++){
            for(y_externo=0;y_externo<MAX_COLUMNAS_GUIA;y_externo++){
                for(x_interno=1;x_interno<MAX_FILAS_JUEGO-1;x_interno++){
                    for(y_interno=1;y_interno<MAX_COLUMNAS_JUEGO-1;y_interno++){

                        moneda = ((rand()) % 10000);

                        if(!(x_externo == pocicion_x_no_aseptable && y_externo == pocicion_y_no_aseptable)){

                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno) == PISO){
                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno+1, y_interno) == PISO){
                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno-1, y_interno) == PISO){
                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno+1) == PISO){
                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno-1) == PISO){

                                if(moneda == 0){

                                    sets_pocicion_completa(x_externo, y_externo, x_interno, y_interno);

                                    mapa.sets_mapa_general(x_externo, y_externo, x_interno, y_interno, sprite_personaje);

                                    return;

                                }

                            }
                            }
                            }
                            }
                            }

                        }

                    }
                }
            }
        }

    }

}

///--- Rutinas del enemigo 1:
void ENEMIGO_4::Rutinas(MAPA &mapa){

    inavilitar_acciones.control_int_invertido();

}

///Resibir daño.
void ENEMIGO_4::restar_vida(int dano){
    if((vida_actual - dano) > 0){
        vida_actual-= dano;
    }
    else{
        muerte();
    }
}

void ENEMIGO_4::muerte(){
    estado_vivo = false;
    sprite_personaje = PISO;
}

///---------------------Propio del padre---------------------

///Gets

int ENEMIGO_4::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int ENEMIGO_4::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int ENEMIGO_4::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int ENEMIGO_4::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void ENEMIGO_4::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void ENEMIGO_4::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void ENEMIGO_4::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void ENEMIGO_4::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void ENEMIGO_4::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_ENEMIGO_4_H_INCLUDED

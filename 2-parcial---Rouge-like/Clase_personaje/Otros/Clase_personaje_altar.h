#ifndef CLASE_PERSONAJE_ALTAR_H_INCLUDED
#define CLASE_PERSONAJE_ALTAR_H_INCLUDED

class ALTAR: public PERSONAJE{
    protected:
        int sprite_personaje;
        CRONO cargar_altar;

        int vida_recuperada;
        int costo_runa;

        int tipo;

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
        int gets_vida_recuperada(){return vida_recuperada;}
        int gets_costo_runa(){return costo_runa;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}


        ///Constructor.
        ALTAR();

        ///Graficar MOB:
        void graficar_altar(int x_externo, int y_externo);
        void graficar_altar_actual();

        ///Iniciar y reiniciar las estadisticas del MOBs:
        void Reiniciar_altar(MAPA &mapa, int zona);
        void iniciar_pocicion_altar(MAPA &mapa, int sprite_personaje);

        ///Interaccion:
        bool Altar_cargado(){return cargar_altar.gets_cont_bool();}

};

ALTAR::ALTAR(){

    vida_recuperada = 1;
    costo_runa = 1;
    cargar_altar.sets_tiempo(6);


}

///Reiniciar altar:
void ALTAR::Reiniciar_altar(MAPA &mapa, int zona){

    sprite_personaje = ENEMIGO;
    tipo = zona;
    cargar_altar.sets_cont(1);

    iniciar_pocicion_altar(mapa, sprite_personaje);

}

void ALTAR::iniciar_pocicion_altar(MAPA &mapa, int sprite_personaje){

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

///Graficar altar:
void ALTAR::graficar_altar(int x_externo, int y_externo){

    if(cargar_altar.gets_cont_bool()){
        cargar_altar.control_int();
    }

    if(x_externo == gets_pocicion_x_guia()){
        if(y_externo == gets_pocicion_y_guia()){
            graficar_altar_actual();
        }
    }

}

void ALTAR::graficar_altar_actual(){

    blit(ELEMENTOS_spr, ALTAR_spr, 0 * DESPLAZAR_Y_PIXEL, tipo * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
    draw_sprite(buffer, ALTAR_spr, gets_pocicion_y_juego() * TAMANO_Y_SPRITE + ESPACIO_SUPERIOR_Y, gets_pocicion_x_juego() * TAMANO_X_SPRITE + ESPACIO_SUPERIOR_X);

}

///---------------------Propio del padre---------------------

///Gets

int ALTAR::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int ALTAR::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int ALTAR::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int ALTAR::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void ALTAR::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void ALTAR::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void ALTAR::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void ALTAR::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void ALTAR::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_ALTAR_H_INCLUDED

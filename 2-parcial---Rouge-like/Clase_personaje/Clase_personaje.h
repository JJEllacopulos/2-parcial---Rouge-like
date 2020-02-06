#ifndef CLASE_PERSONAJE_H_INCLUDED
#define CLASE_PERSONAJE_H_INCLUDED

class PERSONAJE{
    protected:
        int pocicion_x_guia;
        int pocicion_y_guia;
        int pocicion_x_juego;
        int pocicion_y_juego;

        ///BITMAP *personaje_spr;

    public:

        ///Estabece la poccicion inicial del los personajes.
        void pocicion_inicial(MAPA &mapa, int clave, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);
        void iniciar_personaje(MAPA &mapa, int clave, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);


        ///void cargar_sprite(const char *direccion);

        ///void graficar_personaje(BITMAP *personaje);


        ///Gets

        int gets_pocicion_x_guia();
        int gets_pocicion_y_guia();
        int gets_pocicion_x_juego();
        int gets_pocicion_y_juego();


        ///BITMAP gets_personaje_spr();

        ///Sets:

        void sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego);
        void sets_pocicion_x_guia(int x_guia);
        void sets_pocicion_y_guia(int y_guia);
        void sets_pocicion_x_juego(int x_juego);
        void sets_pocicion_y_juego(int y_juego);


        ///Operadores:



};

void PERSONAJE::iniciar_personaje(MAPA &mapa, int clave, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    pocicion_inicial(mapa, clave, pocicion_x_no_aseptable, pocicion_y_no_aseptable);

}

void PERSONAJE::pocicion_inicial(MAPA &mapa, int clave, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x_externo;
    int y_externo;
    int x_interno;
    int y_interno;

    int moneda;

    while(true){

        for(x_externo=0;x_externo<MAX_FILAS_GUIA;x_externo++){
            for(y_externo=0;y_externo<MAX_COLUMNAS_GUIA;y_externo++){
                for(x_interno=0;x_interno<MAX_FILAS_JUEGO;x_interno++){
                    for(y_interno=0;y_interno<MAX_COLUMNAS_JUEGO;y_interno++){

                        if(!(x_externo == pocicion_x_no_aseptable && y_externo == pocicion_y_no_aseptable)){

                            moneda = ((rand()) % 10000);

                            if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno) == PISO){

                                if(moneda == 0){

                                    pocicion_x_guia = x_externo;
                                    pocicion_y_guia = y_externo;
                                    pocicion_x_juego = x_interno;
                                    pocicion_y_juego = y_interno;

                                    mapa.sets_mapa_general(x_externo, y_externo, x_interno, y_interno, clave);

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


///Gets

int PERSONAJE::gets_pocicion_x_guia(){
    return pocicion_x_guia;
}

int PERSONAJE::gets_pocicion_y_guia(){
    return pocicion_y_guia;
}

int PERSONAJE::gets_pocicion_x_juego(){
    return pocicion_x_juego;
}

int PERSONAJE::gets_pocicion_y_juego(){
    return pocicion_y_juego;
}


///Sets:

void PERSONAJE::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){
    pocicion_x_guia = x_guia;
    pocicion_y_guia = y_guia;
    pocicion_x_juego = x_juego;
    pocicion_y_juego = y_juego;
}

void PERSONAJE::sets_pocicion_x_guia(int x_guia){
    pocicion_x_guia = x_guia;
}

void PERSONAJE::sets_pocicion_y_guia(int y_guia){
    pocicion_y_guia = y_guia;
}

void PERSONAJE::sets_pocicion_x_juego(int x_juego){
    pocicion_x_juego = x_juego;
}

void PERSONAJE::sets_pocicion_y_juego(int y_juego){
    pocicion_y_juego = y_juego;
}



#endif // CLASE_PERSONAJE_H_INCLUDED

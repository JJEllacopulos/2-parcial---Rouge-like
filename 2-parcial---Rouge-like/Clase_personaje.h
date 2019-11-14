#ifndef CLASE_PERSONAJE_H_INCLUDED
#define CLASE_PERSONAJE_H_INCLUDED

class PERSONAJE{
    protected:
        int posicion_x_guia;
        int posicion_y_guia;
        int posicion_x_juego;
        int posicion_y_juego;

    public:
        void posicion_inicial(MAPA &mapa, int clave); /// UBICA AL PERSONAJE SEGUN UNA CLAVE DE INICIO EN UNA COORDENADA
        void iniciar_personaje(MAPA &mapa, int clave);/// ESTA DERIVA DEL AZAR

        ///void mover_personaje(int direcion);

        ///Gets

        int gets_posicion_x_guia();
        int gets_posicion_y_guia();
        int gets_posicion_x_juego();
        int gets_posicion_y_juego();

        ///Sets:

        void sets_posicion_completa(int x_guia, int y_guia, int x_juego, int y_juego);
        void sets_posicion_x_guia(int x_guia);
        void sets_posicion_y_guia(int y_guia);
        void sets_posicion_x_juego(int x_juego);
        void sets_posicion_y_juego(int y_juego);

        ///Operadores:



};

void PERSONAJE::iniciar_personaje(MAPA &mapa, int clave){

    posicion_inicial(mapa, clave);

}

void PERSONAJE::posicion_inicial(MAPA &mapa, int clave){

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

                        moneda = ((rand()) % 50);

                        if(mapa.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno) == PISO){

                            if(moneda == 0){

                                posicion_x_guia = x_externo;
                                posicion_y_guia = y_externo;
                                posicion_x_juego = x_interno;
                                posicion_y_juego = y_interno;

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


///Gets

int PERSONAJE::gets_posicion_x_guia(){
    return posicion_x_guia;
}

int PERSONAJE::gets_posicion_y_guia(){
    return posicion_y_guia;
}

int PERSONAJE::gets_posicion_x_juego(){
    return posicion_x_juego;
}

int PERSONAJE::gets_posicion_y_juego(){
    return posicion_y_juego;
}

///Sets:

void PERSONAJE::sets_posicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){
    posicion_x_guia = x_guia;
    posicion_y_guia = y_guia;
    posicion_x_juego = x_juego;
    posicion_y_juego = y_juego;
}

void PERSONAJE::sets_posicion_x_guia(int x_guia){
    posicion_x_guia = x_guia;
}

void PERSONAJE::sets_posicion_y_guia(int y_guia){
    posicion_y_guia = y_guia;
}

void PERSONAJE::sets_posicion_x_juego(int x_juego){
    posicion_x_juego = x_juego;
}

void PERSONAJE::sets_posicion_y_juego(int y_juego){
    posicion_y_juego = y_juego;
}


#endif // CLASE_PERSONAJE_H_INCLUDED

///Clace mapa:
///Aqui se encuentra tanto la clase mapa como sus propiedades y metodos del mismo.

///Propiedades:
///     Mapa guia: Matriz de 5 x 5.
///     Mapa juego: Matriz de 30 x 30
///     Bioma: char (Cada letra se la ocupa como clabe para cargar los diferentes juegos de sprites).

#ifndef CLASE_MAPA_H_INCLUDED
#define CLASE_MAPA_H_INCLUDED

///Definiciones:
    ///Matrices:
#define MAX_FILAS_GUIA 5
#define MAX_COLUMNAS_GUIA 5
#define MAX_FILAS_JUEGO 31
#define MAX_COLUMNAS_JUEGO 31

    ///Contenido de matriz de juego:
#define MURO_INRROMPIBLE 88 ///X
#define MURO_ROMPIBLE 77 ///M
#define COFRE 67 ///C
#define AVATAR 65 ///A
#define PUERTA 80 ///P
#define PISO 112 ///p

    ///Contenido de matriz guia:
#define BLOQUE_ABILITADO 43 ///+
#define BLOQUE_INABILITADO 45 ///-

    ///Biomas:
        ///Proximamente...


class MAPA {
    private:
        int mapa_guia[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA];
        int mapa_juego[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];
        int bioma;

        int movimiento;

    public:
        ///Constructor:
            void armar_mapa_guia();
            void iniciar_mapas();
            void armar_mapa_general_marco(int x_externo, int y_externo);
            void armar_mapa_general_puertas(int x_externo, int y_externo);
            void armar_mapa_general_caminos(int x_externo, int y_externo, int x_interno ,int y_interno);
            void armar_mapa_general();
            MAPA(int bio);
        ///Gets:
            char gets_mapa_guia(int posicion_en_x, int posicion_en_y);
            char gets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
        ///Sets:
            ///Ingresa un valor char a la pocicion de la matriz guia señalada.
            void sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar);
            ///Ingresa un valor char a la pocicion de la matriz juego señalada.
            void sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, char auxiliar);
};

MAPA::MAPA(int bio){

    bioma = bio;
    iniciar_mapas();
    armar_mapa_guia();
    armar_mapa_general();

}

void MAPA::iniciar_mapas(){

    int w,x,y,z;

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){

            mapa_guia[w][x] = BLOQUE_INABILITADO;

        }
    }

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){
            for(y=0 ; y < MAX_FILAS_JUEGO ; y++){
                for(z=0 ; z < MAX_COLUMNAS_JUEGO ; z++){

                    mapa_juego[w][x][y][z] = MURO_ROMPIBLE;

                }
            }
        }
    }


}

void MAPA::armar_mapa_guia(){

    int x = 2;
    int y = 2;

    int movimiento;
    int direccion;

    bool key = true;

    srand(time(0));

    for(movimiento=0; movimiento<6; movimiento++){

        while(key){

            direccion = ((rand() + x + y) % 4);

            switch(direccion){
                case 0: ///Arriba
                    if((x - 1) > 0){
                        if(mapa_guia[x-1][y] == BLOQUE_INABILITADO){
                            key = false;
                            mapa_guia[x-1][y] = BLOQUE_ABILITADO;
                        }
                        x--;
                    }
                break;
                case 1: ///Abajo
                    if((x + 1) < MAX_FILAS_GUIA-1){
                        if(mapa_guia[x+1][y] == BLOQUE_INABILITADO){
                            key = false;
                            mapa_guia[x+1][y] = BLOQUE_ABILITADO;
                        }
                        x++;
                    }
                break;
                case 2: ///Izquierda
                    if((y - 1) > 0){
                        if(mapa_guia[y-1][y] == BLOQUE_INABILITADO){
                            key = false;
                            mapa_guia[y-1][y] = BLOQUE_ABILITADO;
                        }
                        y--;
                    }
                break;
                case 3: ///Derecha
                    if((y + 1) < MAX_COLUMNAS_GUIA-1){
                        if(mapa_guia[y+1][y] == BLOQUE_INABILITADO){
                            key = false;
                            mapa_guia[y+1][y] = BLOQUE_ABILITADO;
                        }
                        y++;
                    }
                break;
            }

        }

        key = true;
    }
}


void MAPA::armar_mapa_general(){

    int x, y;

    for(x=0;x<MAX_FILAS_GUIA;x++){
        for(y=0;y<MAX_COLUMNAS_GUIA;y++){
            if(mapa_guia[x][y] == BLOQUE_ABILITADO){
                armar_mapa_general_marco(x,y);
                armar_mapa_general_puertas(x,y);
            }
        }
    }

}


void MAPA::armar_mapa_general_marco(int x_externo, int y_externo){

    int x_interno;
    int y_interno;

    for(x_interno=0 ; x_interno<MAX_FILAS_JUEGO ; x_interno++){
        for(y_interno=0 ; y_interno<MAX_COLUMNAS_JUEGO ; y_interno++){

            if(x_interno == 0 || x_interno == (MAX_COLUMNAS_JUEGO - 1)){
                mapa_juego[x_externo][y_externo][x_interno][x_interno] = MURO_INRROMPIBLE;
            }
            if(x_interno == 0 || x_interno == (MAX_COLUMNAS_JUEGO - 1)){
                mapa_juego[x_externo][y_externo][x_interno][x_interno] = MURO_INRROMPIBLE;
            }

        }
    }
}


void MAPA::armar_mapa_general_puertas(int x_externo, int y_externo){

    if(x_externo != 0){
        if(mapa_guia[x_externo+1][y_externo] == BLOQUE_ABILITADO){
            mapa_juego[x_externo][y_externo][0][15] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, 0, 15);
        }
    }
    if(x_externo != MAX_FILAS_GUIA-1){
        if(mapa_guia[x_externo-1][y_externo] == BLOQUE_ABILITADO){
            mapa_juego[x_externo][y_externo][MAX_FILAS_JUEGO][15] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, MAX_FILAS_JUEGO, 15);
        }
    }
    if(y_externo != 0){
        if(mapa_guia[x_externo][y_externo+1] == BLOQUE_ABILITADO){
            mapa_juego[x_externo][y_externo][15][0] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, 15, 0);
        }
    }
    if(y_externo != MAX_COLUMNAS_GUIA-1){
        if(mapa_guia[x_externo][y_externo-1] == BLOQUE_ABILITADO){
            mapa_juego[x_externo][y_externo][15][MAX_COLUMNAS_JUEGO] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, 15, MAX_COLUMNAS_JUEGO);
        }
    }


}


void MAPA::armar_mapa_general_caminos(int x_externo, int y_externo, int x_interno ,int y_interno){

    int movimiento;
    int direccion;

    bool key2 = false;
    bool key = true;

    srand(time(0));

    for(movimiento=0; movimiento<20; movimiento++){

        while(key){

            direccion = ((rand() + x_externo + y_externo + x_interno + y_interno) % 4);

            switch(direccion){
                case 0: ///Arriba
                    if((x_interno - 1) > 0){
                        if(mapa_juego[x_externo][y_externo][x_interno-1][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno-1][y_interno] = PISO;
                        }
                        x_externo--;
                    }
                break;
                case 1: ///Abajo
                    if((x_interno + 1) < MAX_FILAS_GUIA){
                        if(mapa_juego[x_externo][y_externo][x_interno+1][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno+1][y_interno] = PISO;
                        }
                        x_externo++;
                    }
                break;
                case 2: ///Izquierda
                    if((y_interno - 1) > 0){
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno-1] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno-1] = PISO;
                        }
                        y_externo--;
                    }
                break;
                case 3: ///Derecha
                    if((y_interno + 1) < MAX_COLUMNAS_GUIA){
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno+1] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno+1] = PISO;
                        }
                        y_externo++;
                    }
                break;
            }

        }

        key = true;
    }

}


///Gets:
char MAPA::gets_mapa_guia(int posicion_en_x, int posicion_en_y){
    return mapa_guia[posicion_en_x][posicion_en_y];
}


char MAPA::gets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_juego[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}


///Sets:
///Ingresa un valor char a la pocicion de la matriz guia señalada.
void MAPA::sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar){
    mapa_guia[posicion_en_x][posicion_en_y] = auxiliar;
}


///Ingresa un valor char a la pocicion de la matriz juego señalada.
void MAPA::sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, char auxiliar){
    mapa_juego[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}




#endif // CLASE_MAPA_H_INCLUDED

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
#define MAX_FILAS_GUIA 3
#define MAX_COLUMNAS_GUIA 3
#define MAX_FILAS_JUEGO 30
#define MAX_COLUMNAS_JUEGO 20
#define POSICION_PUERTA_X 11
#define POSICION_PUERTA_Y 11

    ///Contenido de matriz de juego:
#define MURO_IRROMPIBLE 88 ///X
#define MURO_ROMPIBLE 77 ///M
#define COFRE 67 ///C
#define AVATAR 65 ///A
#define PUERTA 80 ///P
#define PISO 112 ///p

    ///Contenido de matriz guia:
#define BLOQUE_HABILITADO 43 ///+
#define BLOQUE_INHABILITADO 45 ///-

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
            char gets_mapa_juego(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
        ///Sets:
            ///Ingresa un valor char a la pocicion de la matriz guia señalada.
            void sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar);
            ///Ingresa un valor char a la pocicion de la matriz juego señalada.
            void sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, char auxiliar);
};

///Constructor:
MAPA::MAPA(int bio){

    bioma = bio;
    iniciar_mapas();
    armar_mapa_guia();
    armar_mapa_general();

}

///Otorga los valores iniciales a las matrices.
void MAPA::iniciar_mapas(){

    int w,x,y,z;

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){

            mapa_guia[w][x] = BLOQUE_INHABILITADO;

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

///Arma el mapa que servira para armar el mapa del juego.
void MAPA::armar_mapa_guia(){

    int x = 1;
    int y = 1;

    int movimiento;
    int direccion;

    bool key = true;


    mapa_guia[x][y] = BLOQUE_HABILITADO;

    for(movimiento=0; movimiento<4; movimiento++){

        while(key){

            direccion = ((rand()) % 4);

            switch(direccion){
                case 0: ///Arriba
                    if((x - 1) >= 0){
                        if(mapa_guia[x-1][y] == BLOQUE_INHABILITADO){
                            key = false;
                            mapa_guia[x-1][y] = BLOQUE_HABILITADO;
                        }
                        x--;
                    }
                break;
                case 1: ///Abajo
                    if((x + 1) <= MAX_FILAS_GUIA-1){
                        if(mapa_guia[x+1][y] == BLOQUE_INHABILITADO){
                            key = false;
                            mapa_guia[x+1][y] = BLOQUE_HABILITADO;
                        }
                        x++;
                    }
                break;
                case 2: ///Izquierda
                    if((y - 1) >= 0){
                        if(mapa_guia[x][y-1] == BLOQUE_INHABILITADO){
                            key = false;
                            mapa_guia[x][y-1] = BLOQUE_HABILITADO;
                        }
                        y--;
                    }
                break;
                case 3: ///Derecha
                    if((y + 1) <= MAX_COLUMNAS_GUIA-1){
                        if(mapa_guia[x][y+1] == BLOQUE_INHABILITADO){
                            key = false;
                            mapa_guia[x][y+1] = BLOQUE_HABILITADO;
                        }
                        y++;
                    }
                break;
            }

        }

        key = true;
    }

}

///Arma el mapa el mapa del juego.
void MAPA::armar_mapa_general(){

    int x, y;

    for(x=0;x<MAX_FILAS_GUIA;x++){
        for(y=0;y<MAX_COLUMNAS_GUIA;y++){
            if(mapa_guia[x][y] == BLOQUE_HABILITADO){
                armar_mapa_general_marco(x,y);
                armar_mapa_general_puertas(x,y);
            }
        }
    }


}

///Arma los marcos en las secciones habilitadas para los mapas.
void MAPA::armar_mapa_general_marco(int x_externo, int y_externo){

    int x_interno;
    int y_interno;


    for(x_interno=0 ; x_interno<MAX_FILAS_JUEGO ; x_interno++){
        for(y_interno=0 ; y_interno<MAX_COLUMNAS_JUEGO ; y_interno++){

            if(x_interno == 0 || x_interno == (MAX_FILAS_JUEGO - 1)){
                mapa_juego[x_externo][y_externo][x_interno][y_interno] = MURO_IRROMPIBLE;
            }
            if(y_interno == 0 || y_interno == (MAX_COLUMNAS_JUEGO - 1)){
                mapa_juego[x_externo][y_externo][x_interno][y_interno] = MURO_IRROMPIBLE;
            }

        }
    }


}

///Asigna las puertas.
void MAPA::armar_mapa_general_puertas(int x_externo, int y_externo){


    ///Puerta arriba
    if(x_externo != 0){

        if(mapa_guia[x_externo-1][y_externo] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][0][POSICION_PUERTA_Y] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, 0, POSICION_PUERTA_Y);
            mapa_juego[x_externo][y_externo][1][POSICION_PUERTA_Y] = PISO;
        }
    }

    ///Puerta abajo
    if(x_externo != MAX_FILAS_GUIA-1){

        if(mapa_guia[x_externo+1][y_externo] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][MAX_FILAS_JUEGO-1][POSICION_PUERTA_Y] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, MAX_FILAS_JUEGO-1, POSICION_PUERTA_Y);
            mapa_juego[x_externo][y_externo][MAX_FILAS_JUEGO-2][POSICION_PUERTA_Y] = PISO;
        }
    }

    ///Puerta izquierda
    if(y_externo != 0){

        if(mapa_guia[x_externo][y_externo-1] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][0] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, POSICION_PUERTA_X, 0);
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][1] = PISO;
        }
    }

    ///Puerta deracha
    if(y_externo != MAX_COLUMNAS_GUIA-1){

        if(mapa_guia[x_externo][y_externo+1] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][MAX_COLUMNAS_JUEGO-1] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, POSICION_PUERTA_X, MAX_COLUMNAS_JUEGO-1);
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][MAX_COLUMNAS_JUEGO-2] = PISO;
        }
    }

}

///Arma los caminos en los mapas comensando desde las puertas.
void MAPA::armar_mapa_general_caminos(int x_externo, int y_externo, int x_interno ,int y_interno){

    int movimiento;
    int direccion;

    bool key2 = false;
    bool key = true;


    for(movimiento=0; movimiento<70; movimiento++){

        while(key){

            direccion = ((rand()) % 4);

            switch(direccion){
                case 0: ///Arriba
                    if((x_interno - 1) > 0){

                        x_interno--;
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno] = PISO;
                        }

                    }
                break;
                case 1: ///Abajo
                    if((x_interno + 1) < MAX_FILAS_JUEGO){

                        x_interno++;
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno] = PISO;
                        }

                    }
                break;
                case 2: ///Izquierda
                    if((y_interno - 1) > 0){

                        y_interno--;
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno] = PISO;
                        }

                    }
                break;
                case 3: ///Derecha
                    if((y_interno + 1) < MAX_COLUMNAS_JUEGO){

                        y_interno++;
                        if(mapa_juego[x_externo][y_externo][x_interno][y_interno] == MURO_ROMPIBLE){
                            key = false;
                            mapa_juego[x_externo][y_externo][x_interno][y_interno] = PISO;
                        }

                    }
                break;
            }

        }

        key = true;
    }

}


///Gets:

///Devuelve el valor que contiene las pociciones indicadas en la matriz guia.
char MAPA::gets_mapa_guia(int posicion_en_x, int posicion_en_y){
    return mapa_guia[posicion_en_x][posicion_en_y];
}

///Devuelve el valor que contiene las pociciones indicadas en la matriz del juego.
char MAPA::gets_mapa_juego(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
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

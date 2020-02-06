#ifndef CLASE_MAPA_H_INCLUDED
#define CLASE_MAPA_H_INCLUDED

///Definiciones:
    ///Matrices:
#define MAX_FILAS_GUIA 5
#define MAX_COLUMNAS_GUIA 5

#define MAX_FILAS_JUEGO 13
#define MAX_COLUMNAS_JUEGO 19

#define POSICION_PUERTA_X 6
#define POSICION_PUERTA_Y 9

    ///Cantidades en el armado de los mapas
#define BLOQUES_GUIA_HABILITADOS 3 ///Candidad de minimapas habilitados.
#define BLOQUES_JUEGOS_PISO 43 ///Cantidad de bloques que se dispondran como piso.

///Contenido de matriz de juego:
#define MURO_IRROMPIBLE 88 ///X
#define MURO_ROMPIBLE 77 ///M
#define PISO 112 ///p

#define PUERTA 80 ///P

#define ENEMIGO 69 ///E
#define AVATAR 65 ///A



    ///Contenido de matriz guia:
#define BLOQUE_HABILITADO 43 ///+
#define BLOQUE_INHABILITADO 45 ///-



class MAPA {
    private:
        int mapa_guia[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA];
        int mapa_juego[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];
        ///int mapa_de_efectos[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];

        int movimiento;

        int habitaciones;

    public:
        ///Constructor:
            void armar_mapa_guia();
            void iniciar_mapas();
            void armar_mapa_general_marco(int x_externo, int y_externo);
            void armar_mapa_general_puertas(int x_externo, int y_externo);
            void armar_mapa_general_caminos(int x_externo, int y_externo, int x_interno ,int y_interno);
            void armar_mapa_general();
            MAPA();

        ///Reiniciar mapa:
            void asignar_abitaciones(int zona);
            void Reiniciar_mapa(int zona);

        ///Gets:
            int gets_mapa_guia(int posicion_en_x, int posicion_en_y);
            int gets_mapa_juego(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
            ///int gets_mapa_de_efectos(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
        ///Sets:
            ///Ingresa un valor char a la pocicion de la matriz guia señalada.
            void sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar);
            ///Ingresa un valor char a la pocicion de la matriz juego señalada.
            void sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar);
            ///Ingresa un valor char a la pocicion de la matriz de efectos señalada.
            ///void sets_mapa_de_efectos(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar);

};

///Constructor:
MAPA::MAPA(){

    ///iniciar_mapas();
    ///armar_mapa_guia();
    ///armar_mapa_general();

}

///Reiniciar mapa:
void MAPA::Reiniciar_mapa(int zona){

    asignar_abitaciones(zona);

    iniciar_mapas();
    armar_mapa_guia();
    armar_mapa_general();

}

void MAPA::asignar_abitaciones(int zona){

    habitaciones = 1;

    switch(zona){
        case 0:
            habitaciones = 1;
        break;

        case 1:
            habitaciones = 2;
        break;

        case 2:
            habitaciones = 3;
        break;

        case 3:
            habitaciones = 4;
        break;

        case 4:
            habitaciones = 5;
        break;

        case 5:
            habitaciones = 6;
        break;

        case 6:
            habitaciones = 7;
        break;

        case 7:
            habitaciones = 8;
        break;

        case 8:
            habitaciones = 9;
        break;

        case 9:
            habitaciones = 10;
        break;

        default:
            habitaciones = 2;
        break;

    }

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

    /*for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){
            for(y=0 ; y < MAX_FILAS_JUEGO ; y++){
                for(z=0 ; z < MAX_COLUMNAS_JUEGO ; z++){

                    mapa_de_efectos[w][x][y][z] = VACIO;

                }
            }
        }
    }*/


}

///Arma el mapa que servira para armar el mapa del juego.
void MAPA::armar_mapa_guia(){

    int x = 1;
    int y = 1;

    int movimiento;
    int direccion;

    bool key = true;


    mapa_guia[x][y] = BLOQUE_HABILITADO;

    for(movimiento=0; movimiento<habitaciones; movimiento++){

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

    int x = 0;

    ///Puerta arriba
    if(x_externo != 0){

        if(mapa_guia[x_externo-1][y_externo] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][0][POSICION_PUERTA_Y] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, 1, POSICION_PUERTA_Y);

            while(x + 1 != POSICION_PUERTA_X){
                mapa_juego[x_externo][y_externo][1 + x][POSICION_PUERTA_Y] = PISO;
                x++;
            }

            x = 0;
        }
    }

    ///Puerta abajo
    if(x_externo != MAX_FILAS_GUIA-1){

        if(mapa_guia[x_externo+1][y_externo] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][MAX_FILAS_JUEGO-1][POSICION_PUERTA_Y] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, MAX_FILAS_JUEGO-2, POSICION_PUERTA_Y);

            while(x + MAX_FILAS_JUEGO-1 != POSICION_PUERTA_X){
                mapa_juego[x_externo][y_externo][MAX_FILAS_JUEGO-2 + x][POSICION_PUERTA_Y] = PISO;
                x--;
            }

            x = 0;

        }
    }


    ///Puerta izquierda
    if(y_externo != 0){

        if(mapa_guia[x_externo][y_externo-1] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][0] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, POSICION_PUERTA_X, 1);

            while(x + 1 != POSICION_PUERTA_Y){
                mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][1 + x] = PISO;
                x++;
            }

            x = 0;


        }
    }


    ///Puerta deracha
    if(y_externo != MAX_COLUMNAS_GUIA-1){

        if(mapa_guia[x_externo][y_externo+1] == BLOQUE_HABILITADO){
            mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][MAX_COLUMNAS_JUEGO-1] = PUERTA;
            armar_mapa_general_caminos(x_externo, y_externo, POSICION_PUERTA_X, MAX_COLUMNAS_JUEGO-2);

            while(x + MAX_COLUMNAS_JUEGO-1 != POSICION_PUERTA_Y){
                mapa_juego[x_externo][y_externo][POSICION_PUERTA_X][MAX_COLUMNAS_JUEGO-2 + x] = PISO;
                x--;
            }

            x = 0;


        }
    }

}

///Arma los caminos en los mapas comensando desde las puertas.
void MAPA::armar_mapa_general_caminos(int x_externo, int y_externo, int x_interno ,int y_interno){

    int movimiento;
    int direccion;

    bool key = true;


    for(movimiento=0; movimiento<BLOQUES_JUEGOS_PISO; movimiento++){

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
                    if((x_interno + 1) < MAX_FILAS_JUEGO-1){

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
                    if((y_interno + 1) < MAX_COLUMNAS_JUEGO-1){

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
int MAPA::gets_mapa_guia(int posicion_en_x, int posicion_en_y){
    return mapa_guia[posicion_en_x][posicion_en_y];
}

///Devuelve el valor que contiene las pociciones indicadas en la matriz del juego.
int MAPA::gets_mapa_juego(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_juego[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}

///Devuelve el valor que contiene las pociciones indicadas en la matriz de efectos.
/*int MAPA::gets_mapa_de_efectos(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_de_efectos[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}*/


///Sets:
///Ingresa un valor char a la pocicion de la matriz guia señalada.
void MAPA::sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar){
    mapa_guia[posicion_en_x][posicion_en_y] = auxiliar;
}

///Ingresa un valor char a la pocicion de la matriz juego señalada.
void MAPA::sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar){
    mapa_juego[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}

///Ingresa un valor char a la pocicion de la matriz de efectos señalada.
/*void MAPA::sets_mapa_de_efectos(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar){
    mapa_de_efectos[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}*/


#endif // CLASE_MAPA_H_INCLUDED

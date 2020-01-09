#ifndef CLASE_MAPA_GRAFICO_H_INCLUDED
#define CLASE_MAPA_GRAFICO_H_INCLUDED

///Contenido de matriz de efectos:
#define VACIO 0 ///Un espacio vacio, sin graficos.

///Contenido de fondo:
#define MURO_1 10
#define MURO_2 11
#define MURO_3 12
#define MURO_4 13

#define PARED_1 20
#define PARED_2 21
#define PARED_3 22
#define PARED_4 23

#define PISO_1 30
#define PISO_2 31
#define PISO_3 32
#define PISO_4 33
#define PISO_5 34
#define PISO_6 35
#define PISO_7 36
#define PISO_8 37

///Contenido de la 1° superpocicion:
#define ELEMENTO_1 10
#define ELEMENTO_2 11
#define ELEMENTO_3 12
#define ELEMENTO_4 13

#define ANIMACION_1 20
#define ANIMACION_2 21

#define PUERTA_1 30
#define PUERTA_2 31


class MAPA_GRAFICO{
    private:
        int mapa_grafico_fondo[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];
        int mapa_grafico_1_sup[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];
        ///int mapa_grafico_2_sup[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA][MAX_FILAS_JUEGO][MAX_COLUMNAS_JUEGO];

        int movimiento;

    public:
        ///Constructor:
            void armar_mapa_grafico_fondo(MAPA &mapa);
            void armar_mapa_grafico_1_sup(MAPA &mapa);
            ///void armar_mapa_grafico_2_sup(MAPA &mapa);
            void iniciar_mapas();
            MAPA_GRAFICO(MAPA &mapa);

        ///Gets:
            int gets_mapa_grafico_fondo(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
            int gets_mapa_grafico_1_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);
            ///int gets_mapa_grafico_2_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor);

        ///Sets:
            void sets_mapa_grafico_fondo(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar);
            void sets_mapa_grafico_1_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar);
            ///void sets_mapa_grafico_2_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar);

};

///Constructor:
MAPA_GRAFICO::MAPA_GRAFICO(MAPA &mapa){

    iniciar_mapas();
    armar_mapa_grafico_fondo(mapa);
    armar_mapa_grafico_1_sup(mapa);
    ///armar_mapa_grafico_2_sup(mapa);

}

///Otorga los valores iniciales a las matrices.
void MAPA_GRAFICO::iniciar_mapas(){

    int w,x,y,z;

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){
            for(y=0 ; y < MAX_FILAS_JUEGO ; y++){
                for(z=0 ; z < MAX_COLUMNAS_JUEGO ; z++){

                    mapa_grafico_fondo[w][x][y][z] = VACIO;
                    mapa_grafico_1_sup[w][x][y][z] = VACIO;
                    ///mapa_grafico_2_sup[w][x][y][z] = VACIO;

                }
            }
        }
    }

}

void MAPA_GRAFICO::armar_mapa_grafico_fondo(MAPA &mapa){

    int w,x,y,z, num;

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){
            for(y=0 ; y < MAX_FILAS_JUEGO ; y++){
                for(z=0 ; z < MAX_COLUMNAS_JUEGO ; z++){

                    switch(mapa.gets_mapa_juego(w, x, y, z)){
                        case MURO_IRROMPIBLE:
                            mapa_grafico_fondo[w][x][y][z] = ((rand()) % 4) + 10;
                        break;

                        case PUERTA:
                            mapa_grafico_fondo[w][x][y][z] = ((rand()) % 4) + 10;
                        break;

                        case MURO_ROMPIBLE:
                            mapa_grafico_fondo[w][x][y][z] = ((rand()) % 4) + 20;
                        break;

                        case PISO:
                            mapa_grafico_fondo[w][x][y][z] = ((rand()) % 8) + 30;
                        break;

                    }

                    ///mapa_grafico_fondo[w][x][y][z] = num;

                }
            }
        }
    }

}

void MAPA_GRAFICO::armar_mapa_grafico_1_sup(MAPA &mapa){

    int w,x,y,z, num;

    for(w=0 ; w < MAX_FILAS_GUIA ; w++){
        for(x=0 ; x < MAX_COLUMNAS_GUIA ; x++){
            for(y=0 ; y < MAX_FILAS_JUEGO ; y++){
                for(z=0 ; z < MAX_COLUMNAS_JUEGO ; z++){

                    num = ((rand()) % 5);

                    if(num == 0){
                        if(mapa.gets_mapa_juego(w, x, y, z) == MURO_ROMPIBLE){
                            if(mapa.gets_mapa_juego(w, x, y+1, z) == PISO){

                                if(mapa.gets_mapa_juego(w, x, y, z+1) == MURO_ROMPIBLE && mapa.gets_mapa_juego(w, x, y, z-1) == MURO_ROMPIBLE){

                                        mapa_grafico_1_sup[w][x][y][z] = ((rand()) % 2) + 20;

                                }
                                else{

                                    mapa_grafico_1_sup[w][x][y][z] = ((rand()) % 4) + 10;

                                }

                            }
                        }

                    }
                    if(mapa.gets_mapa_juego(w, x, y, z) == PUERTA){

                        if(y == 0 || y == (MAX_FILAS_JUEGO - 1)){
                            mapa_grafico_1_sup[w][x][y][z] = PUERTA_1;
                        }
                        if(z == 0 || z == (MAX_COLUMNAS_JUEGO - 1)){
                            mapa_grafico_1_sup[w][x][y][z] = PUERTA_2;
                        }

                    }

                }
            }
        }
    }

}

///void MAPA_GRAFICO::armar_mapa_grafico_2_sup(MAPA &mapa){}

///Gets:

int MAPA_GRAFICO::gets_mapa_grafico_fondo(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_grafico_fondo[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}

int MAPA_GRAFICO::gets_mapa_grafico_1_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_grafico_1_sup[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}

/*
int MAPA_GRAFICO::gets_mapa_grafico_2_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor){
    return mapa_grafico_2_sup[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor];
}
*/


///Sets:
void MAPA_GRAFICO::sets_mapa_grafico_fondo(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar){
    mapa_grafico_fondo[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}

void MAPA_GRAFICO::sets_mapa_grafico_1_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar){
    mapa_grafico_1_sup[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}

/*
void MAPA_GRAFICO::sets_mapa_grafico_2_sup(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, int auxiliar){
    mapa_grafico_2_sup[posicion_x_mayor][posicion_y_mayor][posicion_x_menor][posicion_y_menor] = auxiliar;
}
*/

#endif // CLASE_MAPA_GRAFICO_H_INCLUDED

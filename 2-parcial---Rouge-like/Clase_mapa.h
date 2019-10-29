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
#define MAX_FILAS_GENERAL 30
#define MAX_COLUMNAS_GENERAL 30

    ///Contenido de matriz de juego:
#define MURO_INRROMPIBLE 88 ///X
#define MURO 77 ///M
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
        char mapa_guia[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA] = {BLOQUE_INABILITADO};
        char mapa_juego[MAX_FILAS_GENERAL][MAX_COLUMNAS_GENERAL] = {MURO};
        int bioma;
    public:
        ///Constructor:
            void armar_mapa_guia();
            void armar_mapa_general();
        MAPA(int bio);
        ///Gets:
            char gets_mapa_guia();
            char gets_mapa_general();
        ///Sets:
            ///Ingresa un valor char a la pocicion de la matriz guia señalada.
            void sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar);
            ///Ingresa un valor char a la pocicion de la matriz juego señalada.
            void sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, char auxiliar);
};

MAPA::MAPA(int bio){

    bioma = bio;
    armar_mapa_guia();
    armar_mapa_general();

}

void MAPA::armar_mapa_guia(){

    int x = 2;
    int y = 2;

    int mov;
    int direccion;

    bool key = true;

    srand(time(0));

    for(mov=0; mov<20; mov++){

        while(key){

            direccion = ((rand() ) % 4);

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
                    if((x + 1) < MAX_COLUMNAS_GUIA){
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
                    if((y + 1) < MAX_FILAS_GUIA){
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
                armar_mapa_general_marco();
                armar_mapa_general_puertas();
                armar_mapa_general_caminos();
            }
        }
    }

}



void MAPA::armar_mapa_general_marco(){



}

void MAPA::armar_mapa_general_puertas(){



}

void MAPA::armar_mapa_general_caminos(){



}

///Gets:
char MAPA::gets_mapa_guia(){
    return mapa_guia[posicion_en_x][posicion_en_y];
}

char MAPA::gets_mapa_general(){
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

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

    ///Contenido de matriz:
#define MURO 77 ///M
#define COFRE 67 ///C
#define AVATAR 65 ///A
#define PUERTA 80 ///P
#define PISO 112 ///p

    ///Biomas:
        ///Proximamente...


class MAPA {
    private:
        char mapa_guia[MAX_FILAS_GUIA][MAX_COLUMNAS_GUIA];
        char mapa_juego[MAX_FILAS_GENERAL][MAX_COLUMNAS_GENERAL];
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



}

void MAPA::armar_mapa_general();

///Gets:
char MAPA::gets_mapa_guia();
char MAPA::gets_mapa_general();
///Sets:
///Ingresa un valor char a la pocicion de la matriz guia señalada.
void MAPA::sets_mapa_guia(int posicion_en_x, int posicion_en_y, char auxiliar);
///Ingresa un valor char a la pocicion de la matriz juego señalada.
void MAPA::sets_mapa_general(int posicion_x_mayor, int posicion_y_mayor, int posicion_x_menor, int posicion_y_menor, char auxiliar);




#endif // CLASE_MAPA_H_INCLUDED

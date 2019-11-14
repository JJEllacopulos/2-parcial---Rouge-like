#ifndef FUNCIONES_AUXILIARES_H_INCLUDED
#define FUNCIONES_AUXILIARES_H_INCLUDED



    /// IDENTIFICACION DE CUADRANTES
    int buscar_cuadrante(int x, int y, int i, int j){   ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


    if(y<j&&x<i){       /// PRIMER * derecha abajo
        return 8;
    }else if(y==j&&x<i){///SEGUNDO * abajo
        return 2;
    }else if(y>j&&x<i){ /// TERCER * iizquierda abajo
        return 6;
    }else if(y<j&&x==i){/// CUARTO * derecha
        return 4;                               /// * QUINTO ES LA POSICION DEL OBJETO ENEMIGO
    }else if(y>j&&x==i){///  SEXTO * izquierda
        return 3;
    }else if(y<j&&x>i){/// SEPTIMO * derecha arriba
        return 7;
    }else if(y==j&&x>i){/// OCTAVO * arriba
        return 1;
    }else if(y>j&&x>i){///  NOVENO * izquierda arriba
        return 9;
    }
}


#endif // FUNCIONES_AUXILIARES_H_INCLUDED

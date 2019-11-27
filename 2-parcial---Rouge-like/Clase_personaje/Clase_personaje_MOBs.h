#ifndef CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

#define RETRAZO_MOVIMIENTO_MOB 3 ///Intrevalo entre movimientos de los MOBs

/// IDENTIFICACION DE CUADRANTES
    int buscar_cuadrante(int x, int y, int i, int j){   ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


    if(y<j&&x<i){       /// PRIMER * derecha abajo
        return 8;
    }else if(y==j&&x<i){///SEGUNDO * abajo
        return 2;
    }else if(y>j&&x<i){ /// TERCER * iizquierda abajo
        return 6;
    }else if(y<j&&x==i){/// CUARTO * derecha
        return 4;                               /// * QUINTO ES LA pocicion DEL OBJETO ENEMIGO
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


class MOB: public PERSONAJE{
    protected:
        int direccion;

        int retrazo;

        int sprite_personaje;


        int vision;
        int movimiento;
        int velocidad;

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
        int gets_velocidad(){return velocidad;}
        int gets_sprite(){return sprite_personaje;}
        int gets_vision(){return vision;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}



        MOB(MAPA &mapa);

        int asechar(MAPA &mapa);
        void realisar_movimiento(MAPA &mapa, int x_guia, int y_guia, int x_mapa, int y_mapa);
        void mover_MOB(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);


};

MOB::MOB(MAPA &mapa){

    sprite_personaje = ENEMIGO;
    retrazo = 0;

    velocidad=25;
    vision=6;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de MOBimiento del jugador:
void MOB::rutina_de_movimiento(MAPA &mapa){

    if(retrazo == RETRAZO_MOVIMIENTO_MOB){

        retrazo = 0;

        /// pocicion ACTUAL DEL OBJETO
        int x_guia=PERSONAJE::gets_pocicion_x_guia();
        int y_guia=PERSONAJE::gets_pocicion_y_guia();
        int x_mapa=PERSONAJE::gets_pocicion_x_juego();
        int y_mapa=PERSONAJE::gets_pocicion_y_juego();
                                                /// VARIABLES AUXILIARES
        int x=0, y=0;
        int cuadrante=0;
        int dir = 0;

        mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO

        dir = ((rand()) % gets_velocidad());                          ///RANGO DE VELOCIDAD INVERSO (CUANTO MAS ALTO, MAS LENTO)

        cuadrante=asechar(mapa);                                     ///SI ENCUENTRA AL CARACTER PERSONAJE ENTONCES SEÑALA EL CUADRANTE

        if(cuadrante!=0){

            dir=cuadrante;
        }

        switch(dir){                     /// SI Y SOLO SI HAY ESPACIO PARA MOVERSE, SE MOVERA EN DIRECCION DEL SWITCH


        case 1: x--;      break;  ///ARRIBA:
        case 2: x++;      break;  ///ABAJO:
        case 3: y--;      break;  ///IZQUIERDA:
        case 4: y++;      break;  ///DERECHA:
        case 9: x--; y--; break;  ///IZQUIERDA ARRIBA
        case 6: x++; y--; break;  ///IZQUIERDA ABAJO
        case 8: x++; y++; break;  ///DERECHA ABAJO
        case 7: x--; y++; break;  ///DERECHA ARRIBA

        default: mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite()); break; /// EN ESTE CASO DEBERIA HABER UN IDDLE DE ANIMACION PASIVA
        // iddle(mapa); break;        ///AÑADIR ANIMACION PASIVA
        }

        if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa + x, y_mapa + y)== PISO){
            realisar_movimiento(mapa, x_guia, y_guia, x_mapa + x, y_mapa + y);
        }else {
            mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
        }


        /*
        direccion = direccion = ((rand()) % 4);
        mover_MOB(mapa);
        retrazo = 0;
        */
    }
    else{
        retrazo++;
    }
}

void MOB::realisar_movimiento(MAPA &mapa,  int x_guia, int y_guia, int x_mapa, int y_mapa){

    PERSONAJE::sets_pocicion_completa(x_guia, y_guia, x_mapa, y_mapa);        ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL OBJETO
    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, sprite_personaje);  ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL MAPA


}

int MOB::asechar(MAPA &mapa){

  int contador=0;

                int x=PERSONAJE::gets_pocicion_x_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                int y=PERSONAJE::gets_pocicion_y_juego(); ///EL VALOR DE X ES RELATIVO A LAS COORDENADAS DEL OBJETO
                int v= gets_vision();
                int i=x-v; int I=x+v;
                int j=x-v; int J=y+v;


                int cuadrante=0;                ///CUADRANTE INICIAL

                for(i; i<=I; i++ ){

                for(j=y-v; j<=J; j++ ){ ///INICIO DEL FOR EN Y

    if(mapa.gets_mapa_juego(PERSONAJE::gets_pocicion_x_guia(), PERSONAJE::gets_pocicion_y_guia(),i,j)==AVATAR){

                     ///cout<<"\nENCONTRO AL AVATAR EN X: "<<i;
                     ///cout<<"\nENCONTRO AL AVATAR EN Y: "<<j;

                    cuadrante=buscar_cuadrante(x, y, i, j);

                    return cuadrante; ///Se corta el for una vez encontrado lo buscado.

                        }
                 }
            }
            return cuadrante;

}

void MOB::mover_MOB(MAPA &mapa){

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), PISO);

    switch(direccion){
        case 0: ///Derecha:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego() + 1) == PISO){
                sets_pocicion_y_juego(gets_pocicion_y_juego() + 1);
            }

        break;

        case 1:///Izquierda:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego() - 1) == PISO){
                sets_pocicion_y_juego(gets_pocicion_y_juego() - 1);
            }

        break;

        case 2:///Arriba:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() - 1, gets_pocicion_y_juego()) == PISO){
                sets_pocicion_x_juego(gets_pocicion_x_juego() - 1);
            }

        break;

        case 3:///Abajo:

            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + 1, gets_pocicion_y_juego()) == PISO){
                sets_pocicion_x_juego(gets_pocicion_x_juego() + 1);
            }

        break;

    }

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), sprite_personaje);
}

///---------------------Propio del padre---------------------

///Gets

int MOB::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int MOB::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int MOB::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int MOB::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void MOB::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void MOB::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void MOB::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void MOB::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void MOB::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

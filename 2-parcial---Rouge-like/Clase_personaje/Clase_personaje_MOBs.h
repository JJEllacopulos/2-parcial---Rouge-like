#ifndef CLASE_PERSONAJE_ENEMIGO_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_H_INCLUDED

///#define RETRAZO_MOVIMIENTO_MOB 3 ///Intrevalo entre movimientos de los MOBs
#define CANTIDAD_MODS 15


class MOB: public PERSONAJE{
    protected:
        int direccion;

        int sprite_personaje;

        int vision;
        int movimiento;
        int velocidad;

        ///Estadisticas del MOB:
        int vida_actual;
        int vida_maxima;
        bool estado_vivo;



        CRONO retraso_movimiento;

        CRONO animacion;
        CRONO animacion_int;

        CRONO frame_estatico;
        int direcion_anima;

        int frente;
        CRONO frames_ataque;

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
        int gets_vida(){return vida_actual;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}
        void sets_vida(int aux){vida_actual = aux;}
        void restar_vida();
        void muerte();


        ///Constructor.
        MOB(/*MAPA &mapa*/);

        ///Rutina de movimiento.
        void rutina_de_movimiento(MAPA &mapa);

        void mover_MOB(MAPA &mapa);
        void realisar_movimiento(MAPA &mapa, int x_guia, int y_guia, int x_mapa, int y_mapa);
        int asechar(MAPA &mapa);
        int buscar_cuadrante(int x, int y, int i, int j);

        ///Graficar MOB:
        void graficar_MOBs(int x_externo, int y_externo);
        void Graficar_accion_MOBs();
        void Graficar_accion_MOBs_pocicion_estatica();
        void Graficar_accion_MOBs_caminar();
        void Graficar_accion_MOBs_estado();

        ///Iniciar y reiniciar las estadisticas del MOBs:
        void Reiniciar_MOBs(MAPA &mapa);

};

MOB::MOB(/*MAPA &mapa*/){

    sprite_personaje = ENEMIGO;
    retraso_movimiento.sets_tiempo(10);

    velocidad=25;
    vision=5;

    retraso_movimiento.sets_tiempo(5);

    animacion.sets_tiempo(2);
    animacion_int.sets_tiempo(1);

    frame_estatico.sets_tiempo(3);
    frames_ataque.sets_tiempo(5);

    ///PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    //vida = 3;
    //vivo = true;
    //frente = 0;

}

///Reiniciar MOBs:
void MOB::Reiniciar_MOBs(MAPA &mapa){

    vida_actual = 3;
    vida_maxima = 3;
    estado_vivo = true;
    frente = 0;
    sprite_personaje = ENEMIGO;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

}

///Rutina de MOBimiento del jugador:
void MOB::rutina_de_movimiento(MAPA &mapa){

    if(estado_vivo){

    if(!frame_estatico.gets_cont_bool()){

        direccion = 0;

        if(!retraso_movimiento.control_bool_invertido()){

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

            cuadrante=asechar(mapa);                                     ///SI ENCUENTRA AL CARACTER PERSONAJE ENTONCES SE�ALA EL CUADRANTE

            if(cuadrante!=0){

                dir=cuadrante;
            }

            switch(dir){                     /// SI Y SOLO SI HAY ESPACIO PARA MOVERSE, SE MOVERA EN DIRECCION DEL SWITCH

                case 1: ///ARRIBA:
                    direccion = 3;
                    frente = 2;
                    x--;
                break;

                case 2: ///ABAJO:
                    direccion = 4;
                    frente = 0;
                    x++;
                break;

                case 3: ///IZQUIERDA:
                    direccion = 2;
                    frente = 1;
                    y--;
                break;

                case 4: ///DERECHA:
                    direccion = 1;
                    frente = 3;
                    y++;
                break;

                case 9: ///IZQUIERDA ARRIBA
                    direccion = 7;
                    frente = 2;
                    x--;
                    y--;
                break;

                case 6: ///IZQUIERDA ABAJO
                    direccion = 8;
                    frente = 0;
                    x++;
                    y--;
                break;

                case 8: ///DERECHA ABAJO
                    direccion = 6;
                    frente = 0;
                    x++;
                    y++;
                break;

                case 7: ///DERECHA ARRIBA
                    direccion = 5;
                    frente = 2;
                    x--;
                    y++;
                break;

                default: /// EN ESTE CASO DEBERIA HABER UN IDDLE DE ANIMACION PASIVA
                    mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                break;
                // iddle(mapa); break;        ///A�ADIR ANIMACION PASIVA

            }

            if(mapa.gets_mapa_juego(x_guia, y_guia, x_mapa + x, y_mapa + y)== PISO){
                realisar_movimiento(mapa, x_guia, y_guia, x_mapa + x, y_mapa + y);
                direcion_anima = direccion;
            }else {
                mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                direcion_anima = 0;
                direccion = 0;
            }

        }
    }

    }
    else{
        mapa.sets_mapa_general(PERSONAJE::gets_pocicion_x_guia(), PERSONAJE::gets_pocicion_y_guia(), PERSONAJE::gets_pocicion_x_juego(), PERSONAJE::gets_pocicion_y_juego(), PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO
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

/// IDENTIFICACION DE CUADRANTES
int MOB:: buscar_cuadrante(int x, int y, int i, int j){   ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


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

///Resibir da�o.
void MOB::restar_vida(){
    if(vida_actual > 1){
        vida_actual--;
    }
    else{
        muerte();
    }
}

void MOB::muerte(){
    estado_vivo = false;
    sprite_personaje = PISO;
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

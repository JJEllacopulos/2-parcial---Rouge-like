#ifndef CLASE_PERSONAJE_ENEMIGO_3_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_3_H_INCLUDED

class ENEMIGO_3: public PERSONAJE{
    protected:
        int direccion;
        int direccion_anterion;
        bool rebote;

        int sprite_personaje;

        int vision;
        int movimiento;
        int velocidad;

        ///Estadisticas del MOB:
        int vida_actual;
        int vida_maxima;
        bool estado_vivo;



        CRONO retraso_movimiento;

        CRONO animacion_caminar;
        CRONO animacion_int;
        CRONO frame_estatico;

        CRONO frames_animacion_ataque;

        int direcion_anima;

        int frente;
        CRONO frames_ataque;
        CRONO inavilitar_acciones;

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
        bool gets_estado_vivo(){return estado_vivo;}

        ///Sets:
        void set_sprite( char c){sprite_personaje=c;}
        void sets_vida(int aux){vida_actual = aux;}
        void restar_vida(int dano);
        void muerte();


        ///Constructor.
        ENEMIGO_3(/*MAPA &mapa*/);

        ///--- Rutinas del enemigo 1:
        void Rutinas(MAPA &mapa);

        ///Rutina de movimiento.
        void rutina_de_movimiento(MAPA &mapa);

        void mover_MOB(MAPA &mapa);
        void realisar_movimiento(MAPA &mapa, int x_guia, int y_guia, int x_mapa, int y_mapa);

        int buscar_cuadrante(int x, int y, int i, int j);

        ///Rutina de ataque:
        int realizar_ataque(int x_guia, int y_guia, int x_juego, int y_juego, int escudo);
        bool verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo, int escudo);

        ///Graficar MOB:
        void graficar_MOBs(int x_externo, int y_externo);
        void Graficar_accion_MOBs();
        void Graficar_accion_MOBs_pocicion_estatica();
        void Graficar_accion_MOBs_caminar();
        void graficar_jugador_ataque();
        void Graficar_accion_MOBs_estado();

        ///Iniciar y reiniciar las estadisticas del MOBs:
        void Reiniciar_MOBs(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

};

ENEMIGO_3::ENEMIGO_3(/*MAPA &mapa*/){

    sprite_personaje = PISO;
    //retraso_movimiento.sets_tiempo(10);

    velocidad=25;
    vision=5;

    retraso_movimiento.sets_tiempo(5);

    animacion_caminar.sets_tiempo(2);
    animacion_int.sets_tiempo(1);
    frames_animacion_ataque.sets_tiempo(2);

    frame_estatico.sets_tiempo(3);
    frames_ataque.sets_tiempo(5);
    inavilitar_acciones.sets_tiempo(1);

}

///Reiniciar MOBs:
void ENEMIGO_3::Reiniciar_MOBs(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    vida_actual = 2;
    vida_maxima = 2;
    estado_vivo = true;
    frente = 0;
    sprite_personaje = PISO;

    direccion_anterion = 0;
    rebote = true;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje, pocicion_x_no_aseptable, pocicion_y_no_aseptable);

}

///--- Rutinas del enemigo 1:
void ENEMIGO_3::Rutinas(MAPA &mapa){

    if(!inavilitar_acciones.gets_cont_bool()){
        rutina_de_movimiento(mapa);
        inavilitar_acciones.sets_tiempo(3);
    }
    else{
        inavilitar_acciones.control_int_invertido();
    }
}


///Rutina de MOBimiento del enemigo:
void ENEMIGO_3::rutina_de_movimiento(MAPA &mapa){

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

            dir = direccion_anterion;

            //mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO

            //dir = ((rand()) % gets_velocidad());                          ///RANGO DE VELOCIDAD INVERSO (CUANTO MAS ALTO, MAS LENTO)

            if(rebote){
            dir = ((rand()) % 4);                          ///RANGO DE VELOCIDAD INVERSO (CUANTO MAS ALTO, MAS LENTO)
            }
            /*cuadrante=asechar(mapa);                                     ///SI ENCUENTRA AL CARACTER PERSONAJE ENTONCES SEÑALA EL CUADRANTE

            if(cuadrante!=0){

                dir=cuadrante;
            }*/

            switch(dir){                     /// SI Y SOLO SI HAY ESPACIO PARA MOVERSE, SE MOVERA EN DIRECCION DEL SWITCH

                /*case 1: ///ARRIBA:
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
                break;*/

                case 0: ///IZQUIERDA ARRIBA
                    direccion = 7;
                    frente = 2;
                    x--;
                    y--;
                break;

                case 1: ///IZQUIERDA ABAJO
                    direccion = 8;
                    frente = 0;
                    x++;
                    y--;
                break;

                case 2: ///DERECHA ABAJO
                    direccion = 6;
                    frente = 0;
                    x++;
                    y++;
                break;

                case 3: ///DERECHA ARRIBA
                    direccion = 5;
                    frente = 2;
                    x--;
                    y++;
                break;

                default: /// EN ESTE CASO DEBERIA HABER UN IDDLE DE ANIMACION PASIVA
                    //mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                break;
                // iddle(mapa); break;        ///AÑADIR ANIMACION PASIVA

            }

            if((x_mapa + x) > 0 && (x_mapa + x) < MAX_FILAS_JUEGO - 1 && (y_mapa + y) > 0 && (y_mapa + y) < MAX_COLUMNAS_JUEGO -1 ){
                realisar_movimiento(mapa, x_guia, y_guia, x_mapa + x, y_mapa + y);
                direcion_anima = direccion;
                direccion_anterion = dir;
                rebote = false;
            }else {
                //mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, gets_sprite());
                direcion_anima = 0;
                direccion = 0;
                rebote = true;
            }


        }
    }

    }
    else{
        mapa.sets_mapa_general(PERSONAJE::gets_pocicion_x_guia(), PERSONAJE::gets_pocicion_y_guia(), PERSONAJE::gets_pocicion_x_juego(), PERSONAJE::gets_pocicion_y_juego(), PISO); ///BORRA LA UBICACION ANTERIOR DEL ENEMIGO
    }

}

void ENEMIGO_3::realisar_movimiento(MAPA &mapa,  int x_guia, int y_guia, int x_mapa, int y_mapa){

    PERSONAJE::sets_pocicion_completa(x_guia, y_guia, x_mapa, y_mapa);        ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL OBJETO
    //mapa.sets_mapa_general(x_guia, y_guia, x_mapa, y_mapa, sprite_personaje);  ///ACTUALIZA LA UBICACION DEL ENEMIGO EN EL MAPA

}

void ENEMIGO_3::mover_MOB(MAPA &mapa){

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
int ENEMIGO_3:: buscar_cuadrante(int x, int y, int i, int j){   ///"*" SIGNIFICA QUE ESTA CHEQUEADA LA LOGICA


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

///Resibir daño.
void ENEMIGO_3::restar_vida(int dano){
    if((vida_actual - dano) > 0){
        vida_actual-= dano;
    }
    else{
        muerte();
    }
}

void ENEMIGO_3::muerte(){
    estado_vivo = false;
    sprite_personaje = PISO;
}

///---------------------Propio del padre---------------------

///Gets

int ENEMIGO_3::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int ENEMIGO_3::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int ENEMIGO_3::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int ENEMIGO_3::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void ENEMIGO_3::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void ENEMIGO_3::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void ENEMIGO_3::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void ENEMIGO_3::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void ENEMIGO_3::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_ENEMIGO_3_H_INCLUDED

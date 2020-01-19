#ifndef CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_H_INCLUDED

#define MAXIMA_VIDA 30
#define MAXIMA_RUNA 30

#define MAXIMA_FLECHAS 3
#define MAXIMA_ESPECIAL_1 1

class JUGADOR: public PERSONAJE{
    protected:
        int direccion;
        int sprite_personaje;

        BITMAP *personaje_spr;

        int frente;
        CRONO frames_ataque;


        ///Animaciones:
        CRONO inavilitar_acciones;
        CRONO frames_animacion_ataque_1;
        CRONO frames_animacion_ataque_2;
        CRONO frames_animacion_ataque_esp_1;
        CRONO frames_animacion_desplasamiento;
        CRONO frames_animacion_caminar;

        ///Estadisticas del jugador:
        bool estado_vivo;
        int vida_actual;
        int vida_maxima;
        int runa_actual;
        int runa_maxima;

        ///Ataque 1:
        bool ataque_1;


        ///Ataque 2:
        bool ataque_2;
        FLECHA carcaj[MAXIMA_FLECHAS];

        ///Ataque especial 1;
        bool ataque_esp_1;
        FLECHA especial_1[MAXIMA_ESPECIAL_1];

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
        JUGADOR();

        ///---Acciones:
        void rutinas_de_acciones(MAPA &mapa);

        ///Moviniento
        void mover_en_mapa_guia();
        void mover_jugador(MAPA &mapa);
        void rutina_de_movimiento(MAPA &mapa);

        ///---Ataques:
        int verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo);

        ///Ataque 1 (Z);
        bool gets_ataque_1(){return ataque_1;}
        int realizar_ataque_1(int x_guia, int y_guia, int x_juego, int y_juego);

        ///Ataque 2 (X):
        bool Lanzar_flecha();
        void Mover_flechas(MAPA &mapa);
        int realizar_ataque_2(int x_guia, int y_guia, int x_juego, int y_juego);

        ///Ataque especial 1 (A):
        bool Lanzar_ataque_esp_1();
        void Mover_ataque_esp_1(MAPA &mapa);
        int realizar_ataque_esp_1(int x_guia, int y_guia, int x_juego, int y_juego);

        ///---Restar vida y runa;
        bool Restar_runa(int gasto);
        bool verificar_runa(int gasto);
        void restar_vida(int dano);
        void muerte();

        ///---Animaciones:
        void graficar_jugador();
        void graficar_jugador_pocicion_estatica();
        void graficar_jugador_caminar();

        void graficar_jugador_ataque_1();

        void graficar_jugador_ataque_2();
        void Graficar_flechas();

        void graficar_jugador_ataque_esp_1();
        void Graficar_ataque_esp_1();

        void graficar_jugador_barras();


        ///Iniciar y reiniciar las estadisticas;
        void Reiniciar_jugador(MAPA &mapa);
};

JUGADOR::JUGADOR(){

    sprite_personaje = AVATAR;

    inavilitar_acciones.sets_tiempo(1);
    frames_animacion_desplasamiento.sets_tiempo(3);
    frames_animacion_caminar.sets_tiempo(9);
    frames_animacion_ataque_1.sets_tiempo(7);
    frames_animacion_ataque_2.sets_tiempo(8);
    frames_animacion_ataque_esp_1.sets_tiempo(9);

}

///Reiniciar JUGADOR:
void JUGADOR::Reiniciar_jugador(MAPA &mapa){

    int x;

    frente = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje);

    vida_actual = 30;
    vida_maxima = MAXIMA_VIDA;
    runa_actual = 30;
    runa_maxima = MAXIMA_RUNA;

    for(x=0 ; x<MAXIMA_FLECHAS ; x++){

        if(carcaj[x].gets_activo()){
            carcaj[x].Desactivar_flecha();
        }

    }

    for(x=0 ; x<MAXIMA_ESPECIAL_1 ; x++){

        if(especial_1[x].gets_activo()){
            especial_1[x].Desactivar_flecha();
        }

    }

}

///-------------------------------------------Rutinas de acciones:
void JUGADOR::rutinas_de_acciones(MAPA &mapa){

    Mover_flechas(mapa);
    Mover_ataque_esp_1(mapa);

    ataque_1 = false;

    if(!inavilitar_acciones.gets_cont_bool()){

        direccion = 0;

        ///Mobimiento:
        if(key[KEY_RIGHT] ||key[KEY_LEFT] || key[KEY_DOWN] || key[KEY_UP]){

            inavilitar_acciones.sets_tiempo(3);
            rutina_de_movimiento(mapa);

            return;
        }

        ///Ataque 1:
        if(key[KEY_Z]){

            if(!frames_animacion_ataque_1.gets_cont_bool()){

                frames_animacion_ataque_1.sets_cont(1);
                inavilitar_acciones.sets_tiempo(7);
                ataque_1 = true;

            }
            return;
        }

        ///Ataque 2:
        if(key[KEY_X]){

            if(!frames_animacion_ataque_2.gets_cont_bool()){

                if(Lanzar_flecha()){
                    frames_animacion_ataque_2.sets_cont(1);
                    inavilitar_acciones.sets_tiempo(8);
                }

            }
            return;
        }

        if(key[KEY_A]){

            if(!frames_animacion_ataque_esp_1.gets_cont_bool()){
                if(verificar_runa(1)){

                    if(Lanzar_ataque_esp_1()){
                        Restar_runa(1);
                        frames_animacion_ataque_esp_1.sets_cont(1);
                        inavilitar_acciones.sets_tiempo(9);
                    }

                }
            }
            return;
        }


    }

}


///---Rutina de movimiento del jugador:
void JUGADOR::rutina_de_movimiento(MAPA &mapa){

    if(key[KEY_RIGHT]&&key[KEY_UP]){  ///DERECHA ARRIBA
        direccion = 5;
        frente = 2;

    }else if(key[KEY_RIGHT]&&key[KEY_DOWN]){  ///DERECHA ABAJO
        direccion = 6;
        frente = 0;

    }else if(key[KEY_LEFT]&&key[KEY_UP]){   ///IZQUIERDA ARRIBA
        direccion = 7;
        frente = 2;

    }else if(key[KEY_LEFT]&&key[KEY_DOWN]){  ///IZQUIERDA ABAJO
        direccion = 8;
        frente = 0;

    }else if(key[KEY_RIGHT]){ ///DERECHA
        direccion = 1;
        frente = 3;

    }else if(key[KEY_LEFT]){ ///IZQUIERDA
        direccion = 2;
        frente = 1;

    }else if(key[KEY_UP]){  ///ARRIBA
        direccion = 3;
        frente = 2;

    }else if(key[KEY_DOWN]){  ///ABAJO
        direccion = 4;
        frente = 0;
    }

    mover_jugador(mapa);

}

///Mover al jugador.
void JUGADOR::mover_jugador(MAPA &mapa){

   int x=0, y=0;   ///variables auxiliares para el uso de las posiciones.

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), PISO); ///ACTIUALIZA EL CARACTER DE PISO EN LA POSICION ANTERIOR

    switch(direccion){

        case 1: ///Derecha;
            y++;
        break;
        case 2: ///Izquierda;
            y--;
        break;
        case 3: ///Arriba;
            x--;
        break;
        case 4: ///Abajo;
            x++;
        break;
        case 5: ///DERECHA ARRIBA;
            x--;
            y++;
        break;
        case 6: ///DERECHA ABAJO;
            x++;
            y++;
        break;
        case 7: ///IZQUIERDA ARRIBA;
            x--;
            y--;
        break;
        case 8: ///IZQUIERDA ABAJO;
            x++;
            y--;
        break;

    }
    if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + x, gets_pocicion_y_juego() +y) == PUERTA){
        sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
        sets_pocicion_y_juego(gets_pocicion_y_juego() + y);
        mover_en_mapa_guia();
    }
    else{
        if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego() + x, gets_pocicion_y_juego() +y) == PISO){
            sets_pocicion_x_juego(gets_pocicion_x_juego() + x);
            sets_pocicion_y_juego(gets_pocicion_y_juego() + y);
        }
        else{
            direccion = 0;

        }
    }

    mapa.sets_mapa_general(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego(), sprite_personaje); ///ACTUALIZA LA UBICACION DEL OBJETO
}

///Mover entre sub-mapas:
void JUGADOR::mover_en_mapa_guia(){

    if(gets_pocicion_y_juego() ==  MAX_COLUMNAS_JUEGO-1){ ///Derecha:
        sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() + 1, gets_pocicion_x_juego(), 1);
    }///else
    if(gets_pocicion_y_juego() ==  0){ ///Izquierda:
        sets_pocicion_completa(gets_pocicion_x_guia(), gets_pocicion_y_guia() - 1, gets_pocicion_x_juego(), MAX_COLUMNAS_JUEGO-2);
    }else
    if(gets_pocicion_x_juego() == 0){ ///Arriba:
        sets_pocicion_completa(gets_pocicion_x_guia() - 1, gets_pocicion_y_guia(), MAX_FILAS_JUEGO-2, gets_pocicion_y_juego());
    }else
    if(gets_pocicion_x_juego() == MAX_FILAS_JUEGO-1){ ///Abajo:
        sets_pocicion_completa(gets_pocicion_x_guia() + 1, gets_pocicion_y_guia(), 1, gets_pocicion_y_juego());
    }

}


///---Restar vida y runa;
bool JUGADOR::verificar_runa(int gasto){

    if((runa_actual - gasto) >= 0){
        ///runa_actual-= gasto;
        return true;
    }
    else{
        return false;
    }

}

bool JUGADOR::Restar_runa(int gasto){

    runa_actual-= gasto;

}

void JUGADOR::restar_vida(int dano){
    if((vida_actual - dano) > 0){
        vida_actual-= dano;
    }
    else{
        muerte();
    }
}

void JUGADOR::muerte(){
    estado_vivo = false;
}


///---------------------Propio del padre---------------------

///Gets

int JUGADOR::gets_pocicion_x_guia(){
    return PERSONAJE::gets_pocicion_x_guia();
}

int JUGADOR::gets_pocicion_y_guia(){
    return PERSONAJE::gets_pocicion_y_guia();
}

int JUGADOR::gets_pocicion_x_juego(){
    return PERSONAJE::gets_pocicion_x_juego();
}

int JUGADOR::gets_pocicion_y_juego(){
    return PERSONAJE::gets_pocicion_y_juego();
}

///Sets:

void JUGADOR::sets_pocicion_completa(int x_guia, int y_guia, int x_juego, int y_juego){

    PERSONAJE::sets_pocicion_x_guia(x_guia);
    PERSONAJE::sets_pocicion_y_guia(y_guia);
    PERSONAJE::sets_pocicion_x_juego(x_juego);
    PERSONAJE::sets_pocicion_y_juego(y_juego);

}

void JUGADOR::sets_pocicion_x_guia(int x_guia){
    PERSONAJE::sets_pocicion_x_guia(x_guia);
}

void JUGADOR::sets_pocicion_y_guia(int y_guia){
    PERSONAJE::sets_pocicion_y_guia(y_guia);
}

void JUGADOR::sets_pocicion_x_juego(int x_juego){
    PERSONAJE::sets_pocicion_x_juego(x_juego);
}

void JUGADOR::sets_pocicion_y_juego(int y_juego){
    PERSONAJE::sets_pocicion_y_juego(y_juego);
}

#endif // CLASE_PERSONAJE_JUGADOR_H_INCLUDED

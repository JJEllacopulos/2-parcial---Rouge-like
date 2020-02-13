#ifndef CLASE_PERSONAJE_JUGADOR_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_H_INCLUDED

#define MAXIMA_VIDA 38
#define MAXIMA_RUNA 38

#define MAXIMA_FLECHAS 3
#define MAXIMA_ESPECIAL_1 1
#define MAXIMA_ESPECIAL_2 3

class JUGADOR: public PERSONAJE{
    protected:
        int direccion;
        int sprite_personaje;

        ///BITMAP *personaje_spr;

        int frente;
        CRONO frames_ataque;


        ///Animaciones:
        CRONO inavilitar_acciones;
        CRONO frames_animacion_ataque_1;
        CRONO frames_animacion_ataque_2;
        CRONO frames_animacion_escudo;
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

        ///Escudo:
        bool escudo;
        int frente_escudo;

        ///Rezar:
        bool rezar;

        ///Ataque especial 1;
        bool ataque_esp_1;
        FLECHA especial_1[MAXIMA_ESPECIAL_1];

        ///Ataque especial 2;
        bool ataque_esp_2;
        RAYO especial_2[MAXIMA_ESPECIAL_2];

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

        ///Escudo (C):
        void Levantar_escudo();
        void graficar_jugador_levantar_escudo();
        void graficar_jugador_escudo_estatico();
        int gets_frente_escudo(){return frente_escudo;}

        ///Rezar (V):
        bool gets_rezar(){return rezar;}
        void realizar_rezo(int x_guia, int y_guia, int x_juego, int y_juego, int costo_runa, int recuperacion);

        ///Ataque especial 1 (A):
        bool Lanzar_ataque_esp_1();
        void Mover_ataque_esp_1(MAPA &mapa);
        int realizar_ataque_esp_1(int x_guia, int y_guia, int x_juego, int y_juego);

        ///Ataque especial 2 (S):
        bool Lanzar_ataque_esp_2(MAPA &mapa);
        int realizar_ataque_esp_2(int x_guia, int y_guia, int x_juego, int y_juego);

        ///---Restar vida y runa;
        bool Restar_runa(int gasto);
        bool verificar_runa(int gasto);
        void Restaurar_runa(int recuperacion);
        bool verificar_vida(int recuperacion);
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

        void Graficar_ataque_esp_2();

        void graficar_jugador_barras();


        ///Iniciar y reiniciar las estadisticas;
        void Reiniciar_jugador_total(MAPA &mapa);
        void Reiniciar_jugador_parcial(MAPA &mapa);

        bool gets_estado_vivo(){return estado_vivo;}
        void sets_estado_vivo(bool x){estado_vivo = x;}
};

JUGADOR::JUGADOR(){

    sprite_personaje = AVATAR;

    inavilitar_acciones.sets_tiempo(1);
    frames_animacion_desplasamiento.sets_tiempo(3);
    frames_animacion_caminar.sets_tiempo(9);
    frames_animacion_ataque_1.sets_tiempo(7);
    frames_animacion_ataque_2.sets_tiempo(8);
    frames_animacion_escudo.sets_tiempo(4);
    frames_animacion_ataque_esp_1.sets_tiempo(9);

    vida_maxima = MAXIMA_VIDA;
    runa_maxima = MAXIMA_RUNA;

    estado_vivo = true;

}

///Reiniciar JUGADOR:
void JUGADOR::Reiniciar_jugador_total(MAPA &mapa){

    int x;

    frente = 0;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje, -1, -1);

    vida_actual = MAXIMA_VIDA;
    runa_actual = MAXIMA_RUNA;

    estado_vivo = true;

    escudo = false;

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

    for(x=0 ; x<MAXIMA_ESPECIAL_2 ; x++){

        if(especial_2[x].gets_activo()){
            especial_2[x].Desactivar_rayo();
        }

    }


    inavilitar_acciones.sets_cont(0);
    frames_animacion_desplasamiento.sets_cont(0);
    frames_animacion_caminar.sets_cont(0);
    frames_animacion_ataque_1.sets_cont(0);
    frames_animacion_ataque_2.sets_cont(0);
    frames_animacion_escudo.sets_cont(0);
    frames_animacion_ataque_esp_1.sets_cont(0);

}

void JUGADOR::Reiniciar_jugador_parcial(MAPA &mapa){

    int x;

    frente = 0;

    escudo = false;

    PERSONAJE::iniciar_personaje(mapa, sprite_personaje, -1, -1);

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

    for(x=0 ; x<MAXIMA_ESPECIAL_2 ; x++){

        if(especial_2[x].gets_activo()){
            especial_2[x].Desactivar_rayo();
        }

    }


    inavilitar_acciones.sets_cont(0);
    frames_animacion_desplasamiento.sets_cont(0);
    frames_animacion_caminar.sets_cont(0);
    frames_animacion_ataque_1.sets_cont(0);
    frames_animacion_ataque_2.sets_cont(0);
    frames_animacion_escudo.sets_cont(0);
    frames_animacion_ataque_esp_1.sets_cont(0);

}

///-------------------------------------------Rutinas de acciones:
void JUGADOR::rutinas_de_acciones(MAPA &mapa){

    Mover_flechas(mapa);
    Mover_ataque_esp_1(mapa);

    ataque_1 = false;
    rezar = false;

    if(!inavilitar_acciones.gets_cont_bool()){

        direccion = 0;

        ///Escudo
        if(key[KEY_C]){

            if(!frames_animacion_escudo.gets_cont_bool()){
                if(!escudo){
                    Levantar_escudo();
                    frames_animacion_escudo.sets_cont(1);
                    inavilitar_acciones.sets_tiempo(4);
                }

            }
            return;
        }else{
            escudo = false;
            frente_escudo = -1;
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

        ///Rezar:
        if(key[KEY_V]){

            rezar = true;
            inavilitar_acciones.sets_tiempo(3);

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

        if(key[KEY_S]){

            if(!frames_animacion_ataque_esp_1.gets_cont_bool()){
                if(verificar_runa(2)){

                    if(Lanzar_ataque_esp_2(mapa)){
                        Restar_runa(2);
                        frames_animacion_ataque_esp_1.sets_cont(1);
                        inavilitar_acciones.sets_tiempo(9);
                    }

                }
            }
            return;
        }

        ///Mobimiento:
        if(key[KEY_RIGHT] ||key[KEY_LEFT] || key[KEY_DOWN] || key[KEY_UP]){

            inavilitar_acciones.sets_tiempo(3);
            rutina_de_movimiento(mapa);

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
        if(frente == 3){
            direccion = 1;
        }

        frente = 3;

    }else if(key[KEY_LEFT]){ ///IZQUIERDA
        if(frente == 1){
            direccion = 2;
        }
        frente = 1;

    }else if(key[KEY_UP]){  ///ARRIBA
        if(frente == 2){
            direccion = 3;
        }
        frente = 2;

    }else if(key[KEY_DOWN]){  ///ABAJO
        if(frente == 0){
            direccion = 4;
        }
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

bool JUGADOR::verificar_vida(int recuperacion){

    if((vida_actual + recuperacion) <= MAXIMA_VIDA){
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

void JUGADOR::Restaurar_runa(int recuperacion){

    if((runa_actual + recuperacion) <= MAXIMA_RUNA){
        runa_actual+= recuperacion;
    }

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

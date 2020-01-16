#ifndef PILA_DE_ENEMIGOS_H_INCLUDED
#define PILA_DE_ENEMIGOS_H_INCLUDED

class PILA_ENEMIGOS{
    private:

        ENEMIGO_1 *enemigo_1;

        int tam_enemigo_1;


    public:

        ///---Iniciar, reiniciar y finalizar vectores:

        ///Iniciar vectores:
        void Iniciar_vectores(int zona, MAPA &mapa);

        ///Asignar tamaños:
        void Asignar_tamanos(int zona);

        ///Cerrar vectores:
        void Cerrar_vectores();

        ///Enemigo 1:
        void Enemigo_1_asignacion_dinamica();
        void Iniciar_enemigo_1(MAPA &mapa);

        ///---Interacciones jugador a enemigo:
        void Jugador_ataca(JUGADOR jugador);

        ///-------Pendiente:

        ///---Rutinas de los enemigos;
        void Rutina_de_enemigos(MAPA &mapa);

        ///---Graficar a los enemigos;
        void Graficar_enemigos(JUGADOR jugador);

        ///---Destructor:
        ~PILA_ENEMIGOS(){
            Cerrar_vectores();
        }

};

///--------------------------Iniciar, reiniciar y finalizar vectores:

void PILA_ENEMIGOS::Iniciar_vectores(int zona, MAPA &mapa){

    Asignar_tamanos(zona);

    if(tam_enemigo_1 != 0){
        Enemigo_1_asignacion_dinamica();
        Iniciar_enemigo_1(mapa);
    }

}

void PILA_ENEMIGOS::Asignar_tamanos(int zona){

    switch(zona){
        case 0:
            tam_enemigo_1 = 1;
        break;

        case 1:
            tam_enemigo_1 = 2;
        break;

        case 2:
            tam_enemigo_1 = 3;
        break;

        case 3:
            tam_enemigo_1 = 4;
        break;

        case 4:
            tam_enemigo_1 = 5;
        break;

        case 5:
            tam_enemigo_1 = 6;
        break;

        case 6:
            tam_enemigo_1 = 7;
        break;

        case 7:
            tam_enemigo_1 = 8;
        break;

        case 8:
            tam_enemigo_1 = 9;
        break;

        default:
            tam_enemigo_1 = 0;
        break;

    }

}

void PILA_ENEMIGOS::Enemigo_1_asignacion_dinamica(){

    enemigo_1 = new ENEMIGO_1[tam_enemigo_1];
    if(enemigo_1 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_1(MAPA &mapa){

    int x;

    if(tam_enemigo_1 != 0){

        for(x = 0 ; x < tam_enemigo_1 ; x++){
            enemigo_1[x].Reiniciar_MOBs(mapa);
        }

    }

}

void PILA_ENEMIGOS::Cerrar_vectores(){

    if(tam_enemigo_1 != 0){
        delete enemigo_1;
    }

}


///-----------------------Rutinas:

///---Interacciones jugador a enemigo:
void PILA_ENEMIGOS::Jugador_ataca(JUGADOR jugador){

    int x;

    if(jugador.gets_ataque_1()){
        for(x = 0 ; x < tam_enemigo_1 ; x++){

            enemigo_1[x].restar_vida(jugador.realizar_ataque_1(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego()));

        }
    }

}

///---Rutinas de los enemigos;
void PILA_ENEMIGOS::Rutina_de_enemigos(MAPA &mapa){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){

        enemigo_1[x].rutina_de_movimiento(mapa);

    }

}

///---Graficar a los enemigos;
void PILA_ENEMIGOS::Graficar_enemigos(JUGADOR jugador){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){

        enemigo_1[x].graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }

}

#endif // PILA_DE_ENEMIGOS_H_INCLUDED

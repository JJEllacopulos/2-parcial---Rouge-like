#ifndef PILA_DE_ENEMIGOS_H_INCLUDED
#define PILA_DE_ENEMIGOS_H_INCLUDED

class PILA_ENEMIGOS{
    private:

        ENEMIGO_1 *enemigo_1;
        ENEMIGO_2 *enemigo_2;
        ENEMIGO_3 *enemigo_3;
        ENEMIGO_4 *enemigo_4;
        ENEMIGO_5 *enemigo_5;

        ALTAR *altar;

        int tam_enemigo_1;
        int tam_enemigo_2;
        int tam_enemigo_3;
        int tam_enemigo_4;
        int tam_enemigo_5;

        int tam_altar;


    public:

        ///---Iniciar, reiniciar y finalizar vectores:

        ///Iniciar vectores:
        void Iniciar_vectores(int zona, MAPA &mapa, JUGADOR &jugador);

        ///Asignar tamaños:
        void Asignar_tamanos(int zona);

        ///Cerrar vectores:
        void Cerrar_vectores();

        ///Enemigo 1:
        void Enemigo_1_asignacion_dinamica();
        void Iniciar_enemigo_1(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

        ///Enemigo 2:
        void Enemigo_2_asignacion_dinamica();
        void Iniciar_enemigo_2(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

        ///Enemigo 3:
        void Enemigo_3_asignacion_dinamica();
        void Iniciar_enemigo_3(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

        ///Enemigo 4:
        void Enemigo_4_asignacion_dinamica();
        void Iniciar_enemigo_4(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

        ///Enemigo 5:
        void Enemigo_5_asignacion_dinamica();
        void Iniciar_enemigo_5(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable);

        ///Altar:
        void altar_asignacion_dinamica();
        void Iniciar_altar(MAPA &mapa, int zona);


        ///---Interacciones jugador a enemigo:
        void Jugador_ataca(JUGADOR &jugador, MAPA &mapa);

        ///---Rutinas de los enemigos;
        void Rutina_de_enemigos(MAPA &mapa, JUGADOR &jugador);
        void Enemigo_ataca(JUGADOR &jugador, MAPA &mapa);

        ///---Graficar a los enemigos;
        void Graficar_enemigos(JUGADOR &jugador);

        ///---Verificar si hay enemigos vivos:
        bool Enemigos_vivos();

        ///---Destructor:
        ~PILA_ENEMIGOS(){
            Cerrar_vectores();
        }

};

///--------------------------Iniciar, reiniciar y finalizar vectores:

void PILA_ENEMIGOS::Iniciar_vectores(int zona, MAPA &mapa, JUGADOR &jugador){

    Asignar_tamanos(zona);

    if(tam_enemigo_1 != 0){
        Enemigo_1_asignacion_dinamica();
        Iniciar_enemigo_1(mapa, jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());
    }
    if(tam_enemigo_2 != 0){
        Enemigo_2_asignacion_dinamica();
        Iniciar_enemigo_2(mapa, jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());
    }
    if(tam_enemigo_3 != 0){
        Enemigo_3_asignacion_dinamica();
        Iniciar_enemigo_3(mapa, jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());
    }
    if(tam_enemigo_4 != 0){
        Enemigo_4_asignacion_dinamica();
        Iniciar_enemigo_4(mapa, jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());
    }
    if(tam_enemigo_5 != 0){
        Enemigo_5_asignacion_dinamica();
        Iniciar_enemigo_5(mapa, jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());
    }
    if(tam_altar != 0){
        altar_asignacion_dinamica();
        Iniciar_altar(mapa, zona);
    }

}

void PILA_ENEMIGOS::Asignar_tamanos(int zona){

    tam_enemigo_1 = 0;
    tam_enemigo_2 = 0;
    tam_enemigo_3 = 0;
    tam_enemigo_4 = 0;
    tam_enemigo_5 = 0;
    tam_altar = 0;

    switch(zona){
        case 0:
            tam_enemigo_1 = 2;
            tam_enemigo_2 = 0;
            tam_enemigo_3 = 0;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 0;
        break;

        case 1:
            tam_enemigo_1 = 3;
            tam_enemigo_2 = 1;
            tam_enemigo_3 = 0;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 0;
        break;

        case 2:
            tam_enemigo_1 = 3;
            tam_enemigo_2 = 3;
            tam_enemigo_3 = 0;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 1;
        break;

        case 3:
            tam_enemigo_1 = 5;
            tam_enemigo_2 = 5;
            tam_enemigo_3 = 2;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 1;
        break;

        case 4:
            tam_enemigo_1 = 5;
            tam_enemigo_2 = 5;
            tam_enemigo_3 = 5;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 1;
        break;

        case 5:
            tam_enemigo_1 = 6;
            tam_enemigo_2 = 6;
            tam_enemigo_3 = 6;
            tam_enemigo_4 = 1;
            tam_enemigo_5 = 0;
            tam_altar = 1;
        break;

        case 6:
            tam_enemigo_1 = 7;
            tam_enemigo_2 = 7;
            tam_enemigo_3 = 6;
            tam_enemigo_4 = 3;
            tam_enemigo_5 = 0;
            tam_altar = 1;
        break;

        case 7:
            tam_enemigo_1 = 6;
            tam_enemigo_2 = 8;
            tam_enemigo_3 = 8;
            tam_enemigo_4 = 4;
            tam_enemigo_5 = 2;
            tam_altar = 1;
        break;

        case 8:
            tam_enemigo_1 = 9;
            tam_enemigo_2 = 9;
            tam_enemigo_3 = 8;
            tam_enemigo_4 = 5;
            tam_enemigo_5 = 3;
            tam_altar = 2;
        break;

        default:
            tam_enemigo_1 = 0;
            tam_enemigo_2 = 0;
            tam_enemigo_3 = 0;
            tam_enemigo_4 = 0;
            tam_enemigo_5 = 0;
            tam_altar = 0;
        break;

    }

}

void PILA_ENEMIGOS::Enemigo_1_asignacion_dinamica(){

    enemigo_1 = new ENEMIGO_1[tam_enemigo_1];
    if(enemigo_1 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_1(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x;

    if(tam_enemigo_1 != 0){

        for(x = 0 ; x < tam_enemigo_1 ; x++){
            enemigo_1[x].Reiniciar_MOBs(mapa, pocicion_x_no_aseptable, pocicion_y_no_aseptable);
        }

    }

}

void PILA_ENEMIGOS::Enemigo_2_asignacion_dinamica(){

    enemigo_2 = new ENEMIGO_2[tam_enemigo_2];
    if(enemigo_2 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_2(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x;

    if(tam_enemigo_2 != 0){

        for(x = 0 ; x < tam_enemigo_2 ; x++){
            enemigo_2[x].Reiniciar_MOBs(mapa, pocicion_x_no_aseptable, pocicion_y_no_aseptable);
        }

    }

}

void PILA_ENEMIGOS::Enemigo_3_asignacion_dinamica(){

    enemigo_3 = new ENEMIGO_3[tam_enemigo_3];
    if(enemigo_3 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_3(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x;

    if(tam_enemigo_3 != 0){

        for(x = 0 ; x < tam_enemigo_3 ; x++){
            enemigo_3[x].Reiniciar_MOBs(mapa, pocicion_x_no_aseptable, pocicion_y_no_aseptable);
        }

    }

}

void PILA_ENEMIGOS::Enemigo_4_asignacion_dinamica(){

    enemigo_4 = new ENEMIGO_4[tam_enemigo_4];
    if(enemigo_4 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_4(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x;

    if(tam_enemigo_4 != 0){

        for(x = 0 ; x < tam_enemigo_4 ; x++){
            enemigo_4[x].Reiniciar_MOBs(mapa, pocicion_x_no_aseptable, pocicion_y_no_aseptable);
        }

    }

}

void PILA_ENEMIGOS::Enemigo_5_asignacion_dinamica(){

    enemigo_5 = new ENEMIGO_5[tam_enemigo_5];
    if(enemigo_5 == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_enemigo_5(MAPA &mapa, int pocicion_x_no_aseptable, int pocicion_y_no_aseptable){

    int x;

    if(tam_enemigo_5 != 0){

        for(x = 0 ; x < tam_enemigo_5 ; x++){
            enemigo_5[x].Reiniciar_MOBs(mapa, pocicion_x_no_aseptable, pocicion_y_no_aseptable);
        }

    }

}

void PILA_ENEMIGOS::altar_asignacion_dinamica(){

    altar = new ALTAR[tam_altar];
    if(altar == NULL){
        exit(1);
    }

}

void PILA_ENEMIGOS::Iniciar_altar(MAPA &mapa, int zona){

    int x;

    if(tam_altar != 0){

        for(x = 0 ; x < tam_altar ; x++){
            altar[x].Reiniciar_altar(mapa, zona);
        }

    }

}

void PILA_ENEMIGOS::Cerrar_vectores(){

    if(tam_enemigo_1 != 0){
        delete enemigo_1;
    }
    if(tam_enemigo_2 != 0){
        delete enemigo_2;
    }
    if(tam_enemigo_3 != 0){
        delete enemigo_3;
    }
    if(tam_enemigo_4 != 0){
        delete enemigo_4;
    }
    if(tam_enemigo_5 != 0){
        delete enemigo_5;
    }
    if(tam_altar != 0){
        delete altar;
    }

    tam_enemigo_1=0;
    tam_enemigo_2=0;
    tam_enemigo_3 = 0;
    tam_enemigo_4 = 0;
    tam_enemigo_5 = 0;
    tam_altar=0;

}


///-----------------------Rutinas:

///---Interacciones jugador a enemigo:
void PILA_ENEMIGOS::Jugador_ataca(JUGADOR &jugador, MAPA &mapa){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){
        if(enemigo_1[x].gets_estado_vivo()){
            enemigo_1[x].restar_vida(jugador.realizar_ataque_1(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego()));
            enemigo_1[x].restar_vida(jugador.realizar_ataque_2(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego()));
            enemigo_1[x].restar_vida(jugador.realizar_ataque_esp_1(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego()));
            enemigo_1[x].restar_vida(jugador.realizar_ataque_esp_2(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego()));

            if(!enemigo_1[x].gets_estado_vivo()){
                jugador.Restaurar_runa(1);
                mapa.sets_mapa_general(enemigo_1[x].gets_pocicion_x_guia(), enemigo_1[x].gets_pocicion_y_guia(), enemigo_1[x].gets_pocicion_x_juego(), enemigo_1[x].gets_pocicion_y_juego(),PISO);
            }

        }
    }

    for(x = 0 ; x < tam_enemigo_2 ; x++){
        if(enemigo_2[x].gets_estado_vivo()){
            enemigo_2[x].restar_vida(jugador.realizar_ataque_1(enemigo_2[x].gets_pocicion_x_guia(), enemigo_2[x].gets_pocicion_y_guia(), enemigo_2[x].gets_pocicion_x_juego(), enemigo_2[x].gets_pocicion_y_juego()));
            enemigo_2[x].restar_vida(jugador.realizar_ataque_2(enemigo_2[x].gets_pocicion_x_guia(), enemigo_2[x].gets_pocicion_y_guia(), enemigo_2[x].gets_pocicion_x_juego(), enemigo_2[x].gets_pocicion_y_juego()));
            enemigo_2[x].restar_vida(jugador.realizar_ataque_esp_1(enemigo_2[x].gets_pocicion_x_guia(), enemigo_2[x].gets_pocicion_y_guia(), enemigo_2[x].gets_pocicion_x_juego(), enemigo_2[x].gets_pocicion_y_juego()));
            enemigo_2[x].restar_vida(jugador.realizar_ataque_esp_2(enemigo_2[x].gets_pocicion_x_guia(), enemigo_2[x].gets_pocicion_y_guia(), enemigo_2[x].gets_pocicion_x_juego(), enemigo_2[x].gets_pocicion_y_juego()));

            if(!enemigo_2[x].gets_estado_vivo()){
                jugador.Restaurar_runa(1);
                mapa.sets_mapa_general(enemigo_2[x].gets_pocicion_x_guia(), enemigo_2[x].gets_pocicion_y_guia(), enemigo_2[x].gets_pocicion_x_juego(), enemigo_2[x].gets_pocicion_y_juego(),PISO);
            }

        }
    }

    for(x = 0 ; x < tam_enemigo_3 ; x++){
        if(enemigo_3[x].gets_estado_vivo()){
            enemigo_3[x].restar_vida(jugador.realizar_ataque_1(enemigo_3[x].gets_pocicion_x_guia(), enemigo_3[x].gets_pocicion_y_guia(), enemigo_3[x].gets_pocicion_x_juego(), enemigo_3[x].gets_pocicion_y_juego()));
            enemigo_3[x].restar_vida(jugador.realizar_ataque_2(enemigo_3[x].gets_pocicion_x_guia(), enemigo_3[x].gets_pocicion_y_guia(), enemigo_3[x].gets_pocicion_x_juego(), enemigo_3[x].gets_pocicion_y_juego()));
            enemigo_3[x].restar_vida(jugador.realizar_ataque_esp_1(enemigo_3[x].gets_pocicion_x_guia(), enemigo_3[x].gets_pocicion_y_guia(), enemigo_3[x].gets_pocicion_x_juego(), enemigo_3[x].gets_pocicion_y_juego()));
            enemigo_3[x].restar_vida(jugador.realizar_ataque_esp_2(enemigo_3[x].gets_pocicion_x_guia(), enemigo_3[x].gets_pocicion_y_guia(), enemigo_3[x].gets_pocicion_x_juego(), enemigo_3[x].gets_pocicion_y_juego()));

            if(!enemigo_3[x].gets_estado_vivo()){
                jugador.Restaurar_runa(1);
                ///mapa.sets_mapa_general(enemigo_3[x].gets_pocicion_x_guia(), enemigo_3[x].gets_pocicion_y_guia(), enemigo_3[x].gets_pocicion_x_juego(), enemigo_3[x].gets_pocicion_y_juego(),PISO);
            }

        }
    }

    for(x = 0 ; x < tam_enemigo_4 ; x++){
        if(enemigo_4[x].gets_estado_vivo()){
            enemigo_4[x].restar_vida(jugador.realizar_ataque_1(enemigo_4[x].gets_pocicion_x_guia(), enemigo_4[x].gets_pocicion_y_guia(), enemigo_4[x].gets_pocicion_x_juego(), enemigo_4[x].gets_pocicion_y_juego()));
            enemigo_4[x].restar_vida(jugador.realizar_ataque_2(enemigo_4[x].gets_pocicion_x_guia(), enemigo_4[x].gets_pocicion_y_guia(), enemigo_4[x].gets_pocicion_x_juego(), enemigo_4[x].gets_pocicion_y_juego()));
            enemigo_4[x].restar_vida(jugador.realizar_ataque_esp_1(enemigo_4[x].gets_pocicion_x_guia(), enemigo_4[x].gets_pocicion_y_guia(), enemigo_4[x].gets_pocicion_x_juego(), enemigo_4[x].gets_pocicion_y_juego()));
            enemigo_4[x].restar_vida(jugador.realizar_ataque_esp_2(enemigo_4[x].gets_pocicion_x_guia(), enemigo_4[x].gets_pocicion_y_guia(), enemigo_4[x].gets_pocicion_x_juego(), enemigo_4[x].gets_pocicion_y_juego()));

            if(!enemigo_4[x].gets_estado_vivo()){
                jugador.Restaurar_runa(2);
                mapa.sets_mapa_general(enemigo_4[x].gets_pocicion_x_guia(), enemigo_4[x].gets_pocicion_y_guia(), enemigo_4[x].gets_pocicion_x_juego(), enemigo_4[x].gets_pocicion_y_juego(),PISO);
            }

        }
    }

    for(x = 0 ; x < tam_enemigo_5 ; x++){
        if(enemigo_5[x].gets_estado_vivo()){
            enemigo_5[x].restar_vida(jugador.realizar_ataque_1(enemigo_5[x].gets_pocicion_x_guia(), enemigo_5[x].gets_pocicion_y_guia(), enemigo_5[x].gets_pocicion_x_juego(), enemigo_5[x].gets_pocicion_y_juego()));
            enemigo_5[x].restar_vida(jugador.realizar_ataque_2(enemigo_5[x].gets_pocicion_x_guia(), enemigo_5[x].gets_pocicion_y_guia(), enemigo_5[x].gets_pocicion_x_juego(), enemigo_5[x].gets_pocicion_y_juego()));
            enemigo_5[x].restar_vida(jugador.realizar_ataque_esp_1(enemigo_5[x].gets_pocicion_x_guia(), enemigo_5[x].gets_pocicion_y_guia(), enemigo_5[x].gets_pocicion_x_juego(), enemigo_5[x].gets_pocicion_y_juego()));
            enemigo_5[x].restar_vida(jugador.realizar_ataque_esp_2(enemigo_5[x].gets_pocicion_x_guia(), enemigo_5[x].gets_pocicion_y_guia(), enemigo_5[x].gets_pocicion_x_juego(), enemigo_5[x].gets_pocicion_y_juego()));

            if(!enemigo_5[x].gets_estado_vivo()){
                jugador.Restaurar_runa(2);
                mapa.sets_mapa_general(enemigo_5[x].gets_pocicion_x_guia(), enemigo_5[x].gets_pocicion_y_guia(), enemigo_5[x].gets_pocicion_x_juego(), enemigo_5[x].gets_pocicion_y_juego(),PISO);
            }

        }
    }


}

///---Interacciones enemigo a jugador:
void PILA_ENEMIGOS::Enemigo_ataca(JUGADOR &jugador, MAPA &mapa){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){
        if(enemigo_1[x].gets_estado_vivo()){
            jugador.restar_vida(enemigo_1[x].realizar_ataque(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego(), jugador.gets_frente_escudo()));
        }
    }

    for(x = 0 ; x < tam_enemigo_2 ; x++){
        if(enemigo_2[x].gets_estado_vivo()){
            jugador.restar_vida(enemigo_2[x].realizar_ataque(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego(), jugador.gets_frente_escudo()));
        }
    }

    for(x = 0 ; x < tam_enemigo_3 ; x++){
        if(enemigo_3[x].gets_estado_vivo()){
            jugador.restar_vida(enemigo_3[x].realizar_ataque(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego(), jugador.gets_frente_escudo()));
        }
    }

    for(x = 0 ; x < tam_enemigo_4 ; x++){
        if(enemigo_4[x].gets_estado_vivo()){
            jugador.restar_vida(enemigo_4[x].realizar_ataque(mapa ,jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego()));
        }
    }

    for(x = 0 ; x < tam_enemigo_5 ; x++){
        if(enemigo_5[x].gets_estado_vivo()){
            jugador.restar_vida(enemigo_5[x].realizar_ataque(mapa ,jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego(), jugador.gets_frente_escudo()));
        }
    }

    if(jugador.gets_rezar()){
        for(x = 0 ; x < tam_altar ; x++){

            if(jugador.verificar_runa(altar[x].gets_costo_runa())){
                if(jugador.verificar_vida(altar[x].gets_vida_recuperada())){
                    if(!altar[x].Altar_cargado()){

                    jugador.realizar_rezo( altar[x].gets_pocicion_x_guia(), altar[x].gets_pocicion_y_guia(), altar[x].gets_pocicion_x_juego(), altar[x].gets_pocicion_y_juego(),altar[x].gets_costo_runa(), altar[x].gets_vida_recuperada());

                    }
                    //jugador.restar_vida(altar[x].realizar_ataque(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia(), jugador.gets_pocicion_x_juego(), jugador.gets_pocicion_y_juego(), jugador.gets_frente_escudo()));
                }
            }

        }
    }

}

///---Rutinas de los enemigos;
void PILA_ENEMIGOS::Rutina_de_enemigos(MAPA &mapa, JUGADOR &jugador){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){

        enemigo_1[x].Rutinas(mapa);

    }
    for(x = 0 ; x < tam_enemigo_2 ; x++){

        enemigo_2[x].Rutinas(mapa);

    }
    for(x = 0 ; x < tam_enemigo_3 ; x++){

        enemigo_3[x].Rutinas(mapa);

    }
    for(x = 0 ; x < tam_enemigo_4 ; x++){

        enemigo_4[x].Rutinas(mapa);

    }
    for(x = 0 ; x < tam_enemigo_5 ; x++){

        enemigo_5[x].Rutinas(mapa);

    }

    Enemigo_ataca(jugador, mapa);

}

///---Verificar si hay enemigos vivos:
bool PILA_ENEMIGOS::Enemigos_vivos(){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){

        if(enemigo_1[x].gets_estado_vivo()){
            return true;
        }

    }
    for(x = 0 ; x < tam_enemigo_2 ; x++){

        if(enemigo_2[x].gets_estado_vivo()){
            return true;
        }

    }
    for(x = 0 ; x < tam_enemigo_3 ; x++){

        if(enemigo_3[x].gets_estado_vivo()){
            return true;
        }

    }
    for(x = 0 ; x < tam_enemigo_4 ; x++){

        if(enemigo_4[x].gets_estado_vivo()){
            return true;
        }

    }
    for(x = 0 ; x < tam_enemigo_5 ; x++){

        if(enemigo_5[x].gets_estado_vivo()){
            return true;
        }

    }

    return false;

}

///---Graficar a los enemigos;
void PILA_ENEMIGOS::Graficar_enemigos(JUGADOR &jugador){

    int x;

    for(x = 0 ; x < tam_enemigo_1 ; x++){

        enemigo_1[x].graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }
    for(x = 0 ; x < tam_enemigo_2 ; x++){

        enemigo_2[x].graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }
    for(x = 0 ; x < tam_enemigo_3 ; x++){

        enemigo_3[x].graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }
    for(x = 0 ; x < tam_enemigo_4 ; x++){

        enemigo_4[x].Graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }
    for(x = 0 ; x < tam_enemigo_5 ; x++){

        enemigo_5[x].graficar_MOBs(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }
    for(x = 0 ; x < tam_altar ; x++){

        altar[x].graficar_altar(jugador.gets_pocicion_x_guia(), jugador.gets_pocicion_y_guia());

    }

}

#endif // PILA_DE_ENEMIGOS_H_INCLUDED

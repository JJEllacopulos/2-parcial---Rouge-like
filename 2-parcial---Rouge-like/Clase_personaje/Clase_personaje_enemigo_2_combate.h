#ifndef CLASE_PERSONAJE_ENEMIGO_2_COMBATE_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_2_COMBATE_H_INCLUDED

///---Realizar ataque;

int ENEMIGO_2::realizar_ataque(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;

    Lanzar_flechas(x_guia, y_guia, x_juego, y_juego);

    dano += realizar_ataque_flecha(x_guia, y_guia, x_juego, y_juego);

    return dano;
}

void ENEMIGO_2::Lanzar_flechas(int x_guia, int y_guia, int x_juego, int y_juego){

    if(direccion == 0){
        if(!inavilitar_acciones.gets_cont_bool()){

            if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){

                if(frente == 0){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego(), x_juego, y_juego)){
                        if(Lanzar_flecha()){
                            //dano += 1;
                            inavilitar_acciones.sets_tiempo(16);
                            inavilitar_acciones.sets_cont(16);
                            frames_animacion_ataque.sets_cont(1);
                        }
                    }

                }
                else if(frente == 1){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego(), x_juego, y_juego)){
                        if(Lanzar_flecha()){
                            //dano += 1;
                            inavilitar_acciones.sets_tiempo(16);
                            inavilitar_acciones.sets_cont(16);
                            frames_animacion_ataque.sets_cont(1);
                        }
                    }

                }
                else if(frente == 2){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego(),x_juego, y_juego)){
                        if(Lanzar_flecha()){
                            //dano += 1;
                            inavilitar_acciones.sets_tiempo(16);
                            inavilitar_acciones.sets_cont(16);
                            frames_animacion_ataque.sets_cont(1);
                        }
                    }

                }
                else if(frente == 3){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego(), x_juego, y_juego)){
                        if(Lanzar_flecha()){
                            //dano += 1;
                            inavilitar_acciones.sets_tiempo(16);
                            inavilitar_acciones.sets_cont(16);
                            frames_animacion_ataque.sets_cont(1);
                        }
                    }

                }

            }
        }
    }

}

bool ENEMIGO_2::Lanzar_flecha(){

    int x;

    for(x=0 ; x<2 ; x++){

        if(!carcaj[x].gets_activo()){
            carcaj[x].Iniciar_flecha(frente, 0, 1, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego());
            return true;
        }

    }

    return false;
}

void ENEMIGO_2::Mover_flechas(MAPA &mapa){

    int x;

    for(x=0 ; x<2 ; x++){

        if(carcaj[x].gets_activo()){
            carcaj[x].Mover_flecha(mapa);
        }

    }

}

int ENEMIGO_2::realizar_ataque_flecha(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;
    int x;

    for(x=0 ; x<2 ; x++){

        if(carcaj[x].gets_activo()){
            dano += carcaj[x].Realizar_ataque_flecha(x_guia, y_guia, x_juego, y_juego);
        }

    }

    return dano;
}


///---Confirmar ataque:

bool ENEMIGO_2::verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo){

    int x = 0, y = 0;

    while((x_jugador + x) != 0 && (x_jugador + x) !=  MAX_FILAS_JUEGO - 1 && (y_jugador + y) != 0 && (y_jugador + y) !=  MAX_COLUMNAS_JUEGO-1 ){

        switch(frente){
            case 0: ///Abajo;
                x++;
            break;

            case 1: ///Izquierda;
                y--;
            break;

            case 2: ///Arriba;
                x--;
            break;

            case 3: ///Derecha;
                y++;
            break;
        }

        if((x_jugador + x) == x_enemigo && (y_jugador + y) == y_enemigo){
            return true;
        }

    }

    return false;
}

#endif // CLASE_PERSONAJE_ENEMIGO_2_COMBATE_H_INCLUDED

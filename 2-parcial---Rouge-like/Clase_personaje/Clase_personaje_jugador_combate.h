#ifndef CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED

///---Rutina de ataque 1

int JUGADOR::realizar_ataque_1(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;

    if(ataque_1){

        if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){
            if(frente == 0){
                dano += verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego(), x_juego, y_juego) * 2;
                dano += verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego()+1, x_juego, y_juego);
                dano += verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego()-1, x_juego, y_juego);
            }
            else if(frente == 1){
                dano += verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()-1, x_juego, y_juego) * 2;
                dano += verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego()-1, x_juego, y_juego);
                dano += verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego()-1, x_juego, y_juego);
            }
            else if(frente == 2){
                dano += verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego(),x_juego, y_juego) * 2;
                dano += verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego()+1,x_juego, y_juego);
                dano += verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego()-1,x_juego, y_juego);
            }
            else if(frente == 3){
                dano += verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()+1, x_juego, y_juego) * 2;
                dano += verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego()+1, x_juego, y_juego);
                dano += verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego()+1, x_juego, y_juego);
            }
        }
    }

    return dano;
}

///---Rutina de ataque 2:

bool JUGADOR::Lanzar_flecha(){

    int x;

    for(x=0 ; x<MAXIMA_FLECHAS ; x++){

        if(!carcaj[x].gets_activo()){
            carcaj[x].Iniciar_flecha(frente, 0, 1, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego());
            return true;
        }

    }

    return false;
}

void JUGADOR::Mover_flechas(MAPA &mapa){

    int x;

    for(x=0 ; x<MAXIMA_FLECHAS ; x++){

        if(carcaj[x].gets_activo()){
            carcaj[x].Mover_flecha(mapa);
        }

    }

}

int JUGADOR::realizar_ataque_2(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;
    int x;

    for(x=0 ; x<MAXIMA_FLECHAS ; x++){

        if(carcaj[x].gets_activo()){
            dano += carcaj[x].Realizar_ataque_flecha(x_guia, y_guia, x_juego, y_juego, -1);
        }

    }

    return dano;
}

///Escudo:
void JUGADOR::Levantar_escudo(){

    switch(frente){
        case 0:
            frente_escudo = 2;
        break;
        case 2:
            frente_escudo = 0;
        break;
        case 3:
            frente_escudo = 1;
        break;
        case 1:
            frente_escudo = 3;
        break;
    }

    escudo = true;
}

///Rezar:

void JUGADOR::realizar_rezo(int x_guia, int y_guia, int x_juego, int y_juego, int costo_runa, int recuperacion){

    //if(rezar){

        if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){
            if(frente == 0){
                if(verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego(), x_juego, y_juego)){
                    vida_actual += recuperacion;
                    runa_actual -= costo_runa;
                }

            }
            else if(frente == 1){

                if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()-1, x_juego, y_juego)){
                    vida_actual += recuperacion;
                    runa_actual -= costo_runa;
                }

            }
            else if(frente == 2){

                if(verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego(),x_juego, y_juego)){
                    vida_actual += recuperacion;
                    runa_actual -= costo_runa;
                }

            }
            else if(frente == 3){

                if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()+1, x_juego, y_juego)){
                    vida_actual += recuperacion;
                    runa_actual -= costo_runa;
                }

            }
        }
    //}

}


///---Rutina de ataque especial 1:

bool JUGADOR::Lanzar_ataque_esp_1(){

    int x;

    for(x=0 ; x<MAXIMA_ESPECIAL_1 ; x++){

        if(!especial_1[x].gets_activo()){
            especial_1[x].Iniciar_flecha(frente, 5, 3, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego());
            return true;
        }

    }

    return false;

}

void JUGADOR::Mover_ataque_esp_1(MAPA &mapa){

    int x;

    for(x=0 ; x<MAXIMA_ESPECIAL_1 ; x++){

        if(especial_1[x].gets_activo()){
            especial_1[x].Mover_flecha(mapa);
        }

    }

}



int JUGADOR::realizar_ataque_esp_1(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;
    int x;

    for(x=0 ; x<MAXIMA_ESPECIAL_1 ; x++){

        if(especial_1[x].gets_activo()){
            dano += especial_1[x].Realizar_ataque_flecha(x_guia, y_guia, x_juego, y_juego, -1);
        }

    }

    return dano;
}

///---Rutina de ataque especial 2:

bool JUGADOR::Lanzar_ataque_esp_2(MAPA &mapa){

    int x = 0;
    int y = 0;
    bool key = false;

    while(x<MAXIMA_ESPECIAL_2){

        if(!especial_2[x].gets_activo()){

            switch(frente){
                case 0:

                    y = 1;

                    while(y<4){

                        if((gets_pocicion_x_juego()+y) <= 0 || (gets_pocicion_x_juego()+y) >= MAX_FILAS_JUEGO - 1 || gets_pocicion_y_juego() <= 0 || gets_pocicion_y_juego() >= MAX_COLUMNAS_JUEGO -1 || !(x < MAXIMA_ESPECIAL_2)){
                                return key;
                        }
                        else{

                            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()+y, gets_pocicion_y_juego()) == PISO){
                                especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()+y, gets_pocicion_y_juego());
                                key = true;
                                x++;
                            }else{
                                if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()+y, gets_pocicion_y_juego()) == ENEMIGO){
                                    especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()+y, gets_pocicion_y_juego());
                                    key = true;
                                    x++;
                                }
                            }
                        }
                        y++;

                    }

                break;

                case 1:

                    y = 1;

                    while(y<4){

                        if((gets_pocicion_x_juego()) <= 0 || (gets_pocicion_x_juego()) >= MAX_FILAS_JUEGO - 1 || (gets_pocicion_y_juego()-y) <= 0 || (gets_pocicion_y_juego()-y) >= MAX_COLUMNAS_JUEGO -1 || !(x < MAXIMA_ESPECIAL_2)){
                                return key;
                        }
                        else{

                            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-y) == PISO){
                                especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-y);
                                key = true;
                                x++;
                            }else{
                                if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-y) == ENEMIGO){
                                    especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-y);
                                    key = true;
                                    x++;
                                }
                            }
                        }
                        y++;

                    }

                    //especial_2[x].Iniciar_rayo( 2, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()-1);
                    //key = true;
                break;

                case 2:
                    y = 1;

                    while(y<4){

                        if((gets_pocicion_x_juego()-y) <= 0 || (gets_pocicion_x_juego()-y) >= MAX_FILAS_JUEGO - 1 || gets_pocicion_y_juego() <= 0 || gets_pocicion_y_juego() >= MAX_COLUMNAS_JUEGO -1 || !(x < MAXIMA_ESPECIAL_2)){
                                return key;
                        }
                        else{

                            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-y, gets_pocicion_y_juego()) == PISO){
                                especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-y, gets_pocicion_y_juego());
                                key = true;
                                x++;
                            }else{
                                if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-y, gets_pocicion_y_juego()) == ENEMIGO){
                                    especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-y, gets_pocicion_y_juego());
                                    key = true;
                                    x++;
                                }
                            }
                        }
                        y++;

                    }

                    ///especial_2[x].Iniciar_rayo( 2, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego()-1, gets_pocicion_y_juego());
                    ///key = true;
                break;

                case 3:
                    y = 1;

                    while(y<4){

                        if((gets_pocicion_x_juego()) <= 0 || (gets_pocicion_x_juego()) >= MAX_FILAS_JUEGO - 1 || (gets_pocicion_y_juego()+y) <= 0 || (gets_pocicion_y_juego()+y) >= MAX_COLUMNAS_JUEGO -1 || !(x < MAXIMA_ESPECIAL_2)){
                                return key;
                        }
                        else{

                            if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+y) == PISO){
                                especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+y);
                                key = true;
                                x++;
                            }else{
                                if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+y) == ENEMIGO){
                                    especial_2[x].Iniciar_rayo( 3, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+y);
                                    key = true;
                                    x++;
                                }
                            }
                        }
                        y++;

                    }

                    ///especial_2[x].Iniciar_rayo( 2, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego()+1);
                    ///key = true;
                break;
            }

        }

        x++;

    }

    if(key){
        return true;
    }

    return false;

}


int JUGADOR::realizar_ataque_esp_2(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;
    int x;

    for(x=0 ; x<MAXIMA_ESPECIAL_2 ; x++){

        if(especial_2[x].gets_ataque_activo()){
            dano += especial_2[x].Realizar_ataque_rayo(x_guia, y_guia, x_juego, y_juego, false);
        }

    }

    return dano;
}

///---Confirmar ataque:

int JUGADOR::verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo/*, ENEMIGO_1 esqueleto[]*/){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        return 1;
    }

    return 0;
}

#endif // CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED

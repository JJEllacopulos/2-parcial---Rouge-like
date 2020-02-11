#ifndef CLASE_PERSONAJE_ENEMIGO_4_COMBATE_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_4_COMBATE_H_INCLUDED

///---Realizar ataque;

int ENEMIGO_4::realizar_ataque(MAPA &mapa ,int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;

    int w;

    int x = 0;
    int y = 0;

    if(!inavilitar_acciones.gets_cont_bool()){

        if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){

            for(w=0 ;w<RAYOS_ENEMIGO_4; w++){

                if(!rayo[w].gets_activo()){

                    x = ((rand()) % MAX_COLUMNAS_JUEGO);
                    y = ((rand()) % MAX_FILAS_JUEGO);

                    if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), y, x) == PISO){
                        rayo[w].Iniciar_rayo( 1, 1, gets_pocicion_x_guia(), gets_pocicion_y_guia(), y, x);

                    }else{
                        if(mapa.gets_mapa_juego(gets_pocicion_x_guia(), gets_pocicion_y_guia(), y, x) == AVATAR){
                            rayo[w].Iniciar_rayo( 1, 1, gets_pocicion_x_guia(), gets_pocicion_y_guia(), y, x);

                        }
                    }


                }


            }

        }
    }

    for(w=0 ; w<RAYOS_ENEMIGO_4 ; w++){

        if(rayo[w].gets_ataque_activo()){
            dano += rayo[w].Realizar_ataque_rayo(x_guia, y_guia, x_juego, y_juego, false);
        }

    }

    return dano;
}

///---Confirmar ataque:

bool ENEMIGO_4::verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        //if(frente != escudo){
            return true;
        //}
    }

    return false;
}

#endif // CLASE_PERSONAJE_ENEMIGO_4_COMBATE_H_INCLUDED

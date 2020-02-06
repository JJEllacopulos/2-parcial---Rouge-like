#ifndef CLASE_PERSONAJE_ENEMIGO_1_COMBATE_H_INCLUDED
#define CLASE_PERSONAJE_ENEMIGO_1_COMBATE_H_INCLUDED

///---Realizar ataque;

int ENEMIGO_1::realizar_ataque(int x_guia, int y_guia, int x_juego, int y_juego, int escudo){

    int dano = 0;

    if(direccion == 0){
        if(!inavilitar_acciones.gets_cont_bool()){

            if(gets_pocicion_x_guia() == x_guia && gets_pocicion_y_guia() == y_guia ){

                if(frente == 0){
                    if(verificar_ataque(gets_pocicion_x_juego()+1, gets_pocicion_y_juego(), x_juego, y_juego, escudo)){
                        if(frente != escudo){
                            dano += 1;
                        }
                        inavilitar_acciones.sets_tiempo(12);
                        inavilitar_acciones.sets_cont(12);
                        frames_animacion_ataque.sets_cont(1);
                    }

                }
                else if(frente == 1){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()-1, x_juego, y_juego, escudo)){
                        if(frente != escudo){
                            dano += 1;
                        }
                        inavilitar_acciones.sets_tiempo(12);
                        inavilitar_acciones.sets_cont(12);
                        frames_animacion_ataque.sets_cont(1);
                    }

                }
                else if(frente == 2){
                    if(verificar_ataque(gets_pocicion_x_juego()-1, gets_pocicion_y_juego(),x_juego, y_juego, escudo)){
                        if(frente != escudo){
                            dano += 1;
                        }
                        inavilitar_acciones.sets_tiempo(12);
                        inavilitar_acciones.sets_cont(12);
                        frames_animacion_ataque.sets_cont(1);
                    }

                }
                else if(frente == 3){
                    if(verificar_ataque(gets_pocicion_x_juego(), gets_pocicion_y_juego()+1, x_juego, y_juego, escudo)){
                        if(frente != escudo){
                            dano += 1;
                        }
                        inavilitar_acciones.sets_tiempo(12);
                        inavilitar_acciones.sets_cont(12);
                        frames_animacion_ataque.sets_cont(1);
                    }

                }

            }
        }
    }

    return dano;
}

///---Confirmar ataque:

bool ENEMIGO_1::verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo, int escudo){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        //if(frente != escudo){
            return true;
        //}
    }

    return false;
}

#endif // CLASE_PERSONAJE_ENEMIGO_1_COMBATE_H_INCLUDED

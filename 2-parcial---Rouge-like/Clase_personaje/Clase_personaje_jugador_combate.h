#ifndef CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED
#define CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED

///---Rutina de ataque 1

int JUGADOR::realizar_ataque_1(int x_guia, int y_guia, int x_juego, int y_juego){

    int dano = 0;

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
        //}
    //}
    return dano;
}

///---Rutina de ataque 2:

bool JUGADOR::Lanzar_flecha(){

    int x;

    for(x=0 ; x<3 ; x++){

        if(!carcaj[x].gets_activo()){
            carcaj[x].Iniciar_flecha(frente, 0, 0, gets_pocicion_x_guia(), gets_pocicion_y_guia(), gets_pocicion_x_juego(), gets_pocicion_y_juego());
            return true;
        }

    }

    return false;
}

void JUGADOR::Mover_flechas(MAPA &mapa){

    int x;

    for(x=0 ; x<3 ; x++){

        if(carcaj[x].gets_activo()){
            carcaj[x].Mover_flecha(mapa);
        }

    }

}

///---Confirmar ataque:

int JUGADOR::verificar_ataque(int x_jugador, int y_jugador, int x_enemigo, int y_enemigo/*, ENEMIGO_1 esqueleto[]*/){

    if(x_jugador == x_enemigo && y_jugador == y_enemigo){
        return 1;
    }

    return 0;
}

#endif // CLASE_PERSONAJE_JUGADOR_COMBATE_H_INCLUDED

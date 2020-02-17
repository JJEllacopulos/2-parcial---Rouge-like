#ifndef GAME_LOOP_H_INCLUDED
#define GAME_LOOP_H_INCLUDED

void Pantalla_de_trancicion(int zona){

    CRONO frames_trancicion;
    frames_trancicion.sets_tiempo(10);
    frames_trancicion.sets_cont(1);

    CRONO frames_animacion_caminar;
    frames_animacion_caminar.sets_tiempo(4);

    CRONO frames_animacion_movimineto;
    frames_animacion_movimineto.sets_tiempo(4);

    int x;
    ///int a = 0 , b = 0 , c = 0;

    while(frames_trancicion.gets_cont_bool() != 0){

        //cout << frames_trancicion.gets_cont()<< "---" << frames_animacion_movimineto.gets_cont()<< endl;

        frames_trancicion.control_int();
        frames_animacion_caminar.control_int_sin_reinicio();
        frames_animacion_movimineto.control_int_sin_reinicio();

        for(x=0;x<9;x++){
            blit(ELEMENTOS_spr, PUERTA_spr, 2 * DESPLAZAR_Y_PIXEL, (33 * x) + 0 * DESPLAZAR_X_PIXEL, 0, 0, TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, PUERTA_spr, 10 * TAMANO_Y_SPRITE, x * 43 + 50);
        }

        if(frames_animacion_caminar.gets_cont() != 5){
            blit(JUGADOR_spr, JUGADOR_mov_spr, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, 280, 13 + (frames_animacion_movimineto.gets_cont() * 8) + (zona * 43));
        }
        else{
            blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
            draw_sprite(buffer, JUGADOR_mov_spr, 280, 13 + ((frames_animacion_movimineto.gets_cont() * 8)) + (zona * 43));
        }


        ///Imprime en la ventana lo que se cargo en el buffer.
        pantallaso();
        ///Limpia el mapa de bits.
        clear(buffer);
        ///Retraso de actividades en nanosegundos.
        rest(100);

    }
}

void Pantalla_final(bool flag){

    CRONO frames_trancicion;
    frames_trancicion.sets_tiempo(40);
    frames_trancicion.sets_cont(1);

    if(flag){
        while(!key[KEY_ESC]){

            blit(MENU_spr, MENSAJE_2, 0, 387, 0, 0, 202, 31);
            draw_sprite(buffer, MENSAJE_2, 215, 70);
            blit(MENU_spr, MENSAJE_3, 0, 424, 0, 0, 267, 335);
            draw_sprite(buffer, MENSAJE_3, 180, 105);

            ///Imprime en la ventana lo que se cargo en el buffer.
            pantallaso();
            ///Limpia el mapa de bits.
            clear(buffer);
            ///Retraso de actividades en nanosegundos.
            rest(100);
        }
        while(key[KEY_ESC]){}
    }else{
        while(frames_trancicion.gets_cont_bool() != 0){

            frames_trancicion.control_int();

            blit(MENU_spr, MENSAJE_1, 0, 326, 0, 0, 225, 58);
            draw_sprite(buffer, MENSAJE_1, 205, 175);

            ///Imprime en la ventana lo que se cargo en el buffer.
            pantallaso();
            ///Limpia el mapa de bits.
            clear(buffer);
            ///Retraso de actividades en nanosegundos.
            rest(100);
        }
    }

}

void Game_loop(JUGADOR &per_jug, PILA_ENEMIGOS &pila_enemigos, MAPA &mapa, MAPA_GRAFICO &mapa_grafico, int &zona, ARCHIVO_PARTIDA &archivo_guardado){

    ///Inicicar conometro:
    CRONO cronometro;
    CRONO cronometro_int;
    cronometro.sets_tiempo(2);
    cronometro_int.sets_tiempo(0);

    ///Iniciar y reiniciar el mapa.
    /*
    mapa.Reiniciar_mapa();
    mapa_grafico.Reiniciar_mapa_grefico(mapa);
    per_jug.Reiniciar_jugador(mapa);
    pila_enemigos.Iniciar_vectores(zona, mapa);
    */

    while(/*!key[KEY_ESC] &&*/ zona != 9 && per_jug.gets_estado_vivo()){

        /*
        ///Iniciar y reiniciar el mapa.
        mapa.Reiniciar_mapa();
        mapa_grafico.Reiniciar_mapa_grefico(mapa);
        per_jug.Reiniciar_jugador(mapa);
        pila_enemigos.Iniciar_vectores(zona, mapa);
        */

        ///Guardar partida.
        archivo_guardado.Guardar_partida(zona, mapa, mapa_grafico, per_jug);

        pila_enemigos.Iniciar_vectores(zona, mapa, per_jug);

        ///Carga las pistas de audio.
        asignar_audio(zona);

        ///Reproducion en bucle del tema de fondo:
        play_midi(Fondo, 1);

        ///Pantalla de trancicion:
        Pantalla_de_trancicion(zona);

        ///Bucle del juego (game loop).
        while(/*!key[KEY_ESC] &&*/ per_jug.gets_estado_vivo() && pila_enemigos.Enemigos_vivos()){

            ///Rutinas de enemigos:
            pila_enemigos.Rutina_de_enemigos(mapa, per_jug);

            ///Rutinas del jugador:
            per_jug.rutinas_de_acciones(mapa);
            pila_enemigos.Jugador_ataca(per_jug, mapa);

            ///Carga en el buffer los elementos de entorno (Piso, muros, etc).
            Graficar_fondo(mapa_grafico, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia(), zona);

            ///Carga en el buffer los elementos de la superpocicion 1(decorados, efectos, animaciones, etc).
            if(cronometro_int.control_bool()){
                cronometro.control_int();
            }

            Graficar_superpocicion_1(mapa_grafico, per_jug.gets_pocicion_x_guia(), per_jug.gets_pocicion_y_guia(), cronometro.gets_cont(), zona);

            ///Carga en el buffer el sprite del jugador.
            per_jug.graficar_jugador();

            ///Carga en el buffer los sprites de los enemigos.
            pila_enemigos.Graficar_enemigos(per_jug);

            ///Imprime en la ventana lo que se cargo en el buffer.
            pantallaso();

            ///Limpia el mapa de bits.
            clear(buffer);

            ///Retraso de actividades en nanosegundos.
            rest(60);

            while(key[KEY_ESC]){
                while(key[KEY_ESC]){}
                pila_enemigos.Cerrar_vectores();
                return;
            }
        }

        //while(key[KEY_ESC]){}

        zona++;

        pila_enemigos.Cerrar_vectores();



        ///Iniciar y reiniciar el mapa.
        mapa.Reiniciar_mapa(zona);
        mapa_grafico.Reiniciar_mapa_grefico(mapa);
        per_jug.Reiniciar_jugador_parcial(mapa);
        ///pila_enemigos.Iniciar_vectores(zona, mapa);

    }

    Pantalla_final(per_jug.gets_estado_vivo());

    while(key[KEY_ESC]){}



    zona = 9;
    ///Carga las pistas de audio.
    asignar_audio(zona);
    ///Reproducion en bucle del tema de fondo:
    play_midi(Fondo, 1);

}

#endif // GAME_LOOP_H_INCLUDED

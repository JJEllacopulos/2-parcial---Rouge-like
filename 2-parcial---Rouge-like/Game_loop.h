#ifndef GAME_LOOP_H_INCLUDED
#define GAME_LOOP_H_INCLUDED

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

    while(zona != 9){

        /*
        ///Iniciar y reiniciar el mapa.
        mapa.Reiniciar_mapa();
        mapa_grafico.Reiniciar_mapa_grefico(mapa);
        per_jug.Reiniciar_jugador(mapa);
        pila_enemigos.Iniciar_vectores(zona, mapa);
        */

        ///Guardar partida.
        archivo_guardado.Guardar_partida(zona, mapa, mapa_grafico, per_jug);

        pila_enemigos.Iniciar_vectores(zona, mapa);

        ///Carga las pistas de audio.
        asignar_audio(zona);

        ///Reproducion en bucle del tema de fondo:
        play_midi(Fondo, 1);

        ///Bucle del juego (game loop).
        while(!key[KEY_ESC]){

            ///Rutinas de enemigos:
            pila_enemigos.Rutina_de_enemigos(mapa, per_jug);

            ///Rutinas del jugador:
            per_jug.rutinas_de_acciones(mapa);
            pila_enemigos.Jugador_ataca(per_jug);

            ///Limpia el mapa de bits.
            clear(buffer);

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

            ///Retraso de actividades en nanosegundos.
            rest(60);
        }

        while(key[KEY_ESC]){}

        zona++;

        pila_enemigos.Cerrar_vectores();



        ///Iniciar y reiniciar el mapa.
        mapa.Reiniciar_mapa();
        mapa_grafico.Reiniciar_mapa_grefico(mapa);
        per_jug.Reiniciar_jugador(mapa);
        ///pila_enemigos.Iniciar_vectores(zona, mapa);

    }

    zona = 9;
    ///Carga las pistas de audio.
    asignar_audio(zona);
    ///Reproducion en bucle del tema de fondo:
    play_midi(Fondo, 1);

}

#endif // GAME_LOOP_H_INCLUDED

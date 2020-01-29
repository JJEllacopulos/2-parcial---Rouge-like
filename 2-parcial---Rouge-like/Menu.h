#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///Menu:
BITMAP *MENU_spr;
BITMAP *TITULO_spr;
BITMAP *SUB_TITULO_spr;
BITMAP *FONDO_spr;
BITMAP *CADENA_spr;
BITMAP *TACHAS_spr;
BITMAP *CHAR_1_spr;
BITMAP *CHAR_2_spr;
BITMAP *CHAR_3_spr;
BITMAP *CHAR_4_spr;
BITMAP *SELECCION_spr;

///Instrucciones de controles:

BITMAP *BOTON_ENTER;
BITMAP *BOTON_FLECHA;
BITMAP *BOTON_LETRA;

BITMAP *EJE_MOVIMIENTO;
BITMAP *EJE_ATAQUE_1;
BITMAP *EJE_ATAQUE_2;
BITMAP *EJE_ATAQUE_ESP_1;


///640x480

void Instrucciones_controles(){

    while(!key[KEY_ESC]){

        blit(MENU_spr, EJE_MOVIMIENTO, 428, 403, 0, 0, 32, 32);
        draw_sprite(buffer, EJE_MOVIMIENTO, 170, 80);
        blit(MENU_spr, EJE_ATAQUE_1, 428, 438, 0, 0, 46, 40);
        draw_sprite(buffer, EJE_ATAQUE_1, 170, 130);
        blit(MENU_spr, EJE_ATAQUE_2, 428, 481, 0, 0, 32, 30);
        draw_sprite(buffer, EJE_ATAQUE_2, 170, 180);
        blit(MENU_spr, EJE_ATAQUE_ESP_1, 428, 514, 0, 0, 44, 31);
        draw_sprite(buffer, EJE_ATAQUE_ESP_1, 170, 230);

        blit(MENU_spr, BOTON_FLECHA, 291, 402, 0, 0, 112, 78);
        draw_sprite(buffer, BOTON_FLECHA, 290, 50);
        blit(MENU_spr, BOTON_LETRA, 294, 573, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 130);
        blit(MENU_spr, BOTON_LETRA, 337, 573, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 180);
        blit(MENU_spr, BOTON_LETRA, 294, 618, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 230);

        pantallaso();
        clear(buffer);

    }

    while(key[KEY_ESC]){}

}

void menu_grafico(int opcion){

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 140, 0);

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 303, 0);

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 484, 0);

    blit(MENU_spr, FONDO_spr, 271, 0, 0, 0, 370, 390);
    draw_sprite(buffer, FONDO_spr, 140, 55);


    blit(MENU_spr, TACHAS_spr, 192, 140, 0, 0, 50, 50);
    draw_sprite_v_flip(buffer, TACHAS_spr, 140, 55);

    blit(MENU_spr, TACHAS_spr, 192, 140, 0, 0, 50, 50);
    draw_sprite(buffer, TACHAS_spr, 140, 395);

    blit(MENU_spr, TACHAS_spr, 192, 140, 0, 0, 50, 50);
    draw_sprite_vh_flip(buffer, TACHAS_spr, 460, 55);

    blit(MENU_spr, TACHAS_spr, 192, 140, 0, 0, 50, 50);
    draw_sprite_h_flip(buffer, TACHAS_spr, 460, 395);


    blit(MENU_spr, TITULO_spr, 0, 0, 0, 0, 267, 127);
    draw_sprite(buffer, TITULO_spr, 185, 75);

    blit(MENU_spr, SUB_TITULO_spr, 0, 142, 0, 0, 125, 39);
    draw_sprite(buffer, SUB_TITULO_spr, 225, 195);

    blit(MENU_spr, CHAR_1_spr, 6, 231, 0, 0, 97, 18);
    draw_sprite(buffer, CHAR_1_spr, 260, 265);

    blit(MENU_spr, CHAR_2_spr, 7, 260, 0, 0, 67, 14);
    draw_sprite(buffer, CHAR_2_spr, 260, 315);

    blit(MENU_spr, CHAR_3_spr, 7, 282, 0, 0, 67, 13);
    draw_sprite(buffer, CHAR_3_spr, 260, 365);

    blit(MENU_spr, CHAR_4_spr, 8, 303, 0, 0, 38, 13);
    draw_sprite(buffer, CHAR_4_spr, 260, 415);

    switch(opcion){
        case 0:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 260);
        break;

        case 1:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 310);
        break;

        case 2:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 360);
        break;

        case 3:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 410);
        break;

    }

    pantallaso();
    clear(buffer);

}

void Menu_control(JUGADOR &per_jug, PILA_ENEMIGOS &pila_enemigos, MAPA &mapa, MAPA_GRAFICO &mapa_grafico, int &zona, ARCHIVO_PARTIDA &archivo_guardado){

    int opcion = 0;

    MENU_spr = load_bitmap("Imagenes/Menu.bmp", NULL);
    CADENA_spr = create_bitmap(21, 58);
    TACHAS_spr = create_bitmap(50, 50);
    FONDO_spr = create_bitmap(370, 390);
    TITULO_spr = create_bitmap(267, 127);
    SUB_TITULO_spr = create_bitmap(125, 39);

    CHAR_1_spr = create_bitmap(97, 18);
    CHAR_2_spr = create_bitmap(67, 14);
    CHAR_3_spr = create_bitmap(67, 13);
    CHAR_4_spr = create_bitmap(38, 13);
    SELECCION_spr = create_bitmap(142, 32);

    ///Ejemplo de controles:

    BOTON_FLECHA = create_bitmap(112, 78);
    BOTON_ENTER = create_bitmap(64, 78);
    BOTON_LETRA = create_bitmap(41, 44);

    EJE_MOVIMIENTO = create_bitmap(32, 32);
    EJE_ATAQUE_1 = create_bitmap(46, 40);
    EJE_ATAQUE_2 = create_bitmap(32, 30);
    EJE_ATAQUE_ESP_1 = create_bitmap(44, 31);

    zona = 9;
    ///Carga las pistas de audio.
    asignar_audio(zona);
    ///Reproducion en bucle del tema de fondo:
    play_midi(Fondo, 1);

    while(!key[KEY_ESC]){

        if(key[KEY_UP]){ ///ARRIBA

            if(opcion > 0){
                opcion --;
                while(key[KEY_UP]){}
            }

        }
        else if(key[KEY_DOWN]){  ///ABAJO

            if(opcion < 3){
                opcion ++;
                while(key[KEY_DOWN]){}
            }

        }
        menu_grafico(opcion);

        if(key[KEY_ENTER]){

            switch(opcion){
                case 0:
                    mapa.Reiniciar_mapa();
                    mapa_grafico.Reiniciar_mapa_grefico(mapa);
                    per_jug.Reiniciar_jugador_total(mapa);
                    //per_jug.sets_estado_vivo(true);
                    zona = 0;

                    Game_loop( per_jug, pila_enemigos, mapa, mapa_grafico, zona, archivo_guardado);
                break;

                case 1:
                    ///Cargar partida.
                    archivo_guardado.Cargar_partida(zona, mapa, mapa_grafico, per_jug);

                    Game_loop( per_jug, pila_enemigos, mapa, mapa_grafico, zona, archivo_guardado);
                break;

                case 2:
                    clear(buffer);
                    Instrucciones_controles();
                break;

                case 3:
                    return;
                break;
            }

        }

    }

}

#endif // MENU_H_INCLUDED

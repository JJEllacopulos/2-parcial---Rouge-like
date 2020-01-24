#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

BITMAP *MENU_spr;
BITMAP *TITULO_spr;
BITMAP *SUB_TITULO_spr;
BITMAP *FONDO_spr;
BITMAP *CADENA_spr;
BITMAP *CHAR_1_spr;
BITMAP *CHAR_2_spr;
BITMAP *CHAR_3_spr;
BITMAP *SELECCION_spr;

///640x480

void menu_grafico(int opcion){

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 140, 0);

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 303, 0);

    blit(MENU_spr, CADENA_spr, 163, 140, 0, 0, 21, 58);
    draw_sprite(buffer, CADENA_spr, 484, 0);

    blit(MENU_spr, FONDO_spr, 271, 0, 0, 0, 370, 390);
    draw_sprite(buffer, FONDO_spr, 140, 55);

    blit(MENU_spr, TITULO_spr, 0, 0, 0, 0, 267, 127);
    draw_sprite(buffer, TITULO_spr, 185, 75);

    blit(MENU_spr, SUB_TITULO_spr, 0, 142, 0, 0, 125, 39);
    draw_sprite(buffer, SUB_TITULO_spr, 225, 195);

    blit(MENU_spr, CHAR_1_spr, 6, 231, 0, 0, 97, 18);
    draw_sprite(buffer, CHAR_1_spr, 260, 275);

    blit(MENU_spr, CHAR_2_spr, 7, 260, 0, 0, 67, 14);
    draw_sprite(buffer, CHAR_2_spr, 260, 325);

    blit(MENU_spr, CHAR_3_spr, 8, 285, 0, 0, 38, 13);
    draw_sprite(buffer, CHAR_3_spr, 260, 375);

    switch(opcion){
        case 0:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 270);
        break;

        case 1:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 320);
        break;

        case 2:
            blit(MENU_spr, SELECCION_spr, 0, 187, 0, 0, 142, 32);
            draw_sprite(buffer, SELECCION_spr, 255, 370);
        break;

    }

    pantallaso();
    clear(buffer);

}

void Menu_control(JUGADOR &per_jug, PILA_ENEMIGOS &pila_enemigos, MAPA &mapa, MAPA_GRAFICO &mapa_grafico, int &zona, ARCHIVO_PARTIDA &archivo_guardado){

    int opcion = 0;

    MENU_spr = load_bitmap("Imagenes/Menu.bmp", NULL);
    CADENA_spr = create_bitmap(21, 58);
    FONDO_spr = create_bitmap(370, 390);
    TITULO_spr = create_bitmap(267, 127);
    SUB_TITULO_spr = create_bitmap(125, 39);

    CHAR_1_spr = create_bitmap(97, 18);
    CHAR_2_spr = create_bitmap(67, 14);
    CHAR_3_spr = create_bitmap(38, 13);
    SELECCION_spr = create_bitmap(142, 32);

    while(!key[KEY_ESC]){

        if(key[KEY_UP]){ ///ARRIBA

            if(opcion > 0){
                opcion --;
                while(key[KEY_UP]){}
            }

        }
        else if(key[KEY_DOWN]){  ///ABAJO

            if(opcion < 2){
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
                    per_jug.Reiniciar_jugador(mapa);


                    Game_loop( per_jug, pila_enemigos, mapa, mapa_grafico, zona, archivo_guardado);
                break;

                case 1:
                    ///Cargar partida.
                    archivo_guardado.Cargar_partida(zona, mapa, mapa_grafico, per_jug);

                    Game_loop( per_jug, pila_enemigos, mapa, mapa_grafico, zona, archivo_guardado);
                break;

                case 2:
                    return;
                break;
            }

        }

    }

}

#endif // MENU_H_INCLUDED

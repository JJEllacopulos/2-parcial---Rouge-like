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
BITMAP *EJE_ESCUDO;
BITMAP *EJE_RESAR;
BITMAP *EJE_ATAQUE_ESP_1;
BITMAP *EJE_ATAQUE_ESP_2;


///640x480

void Instrucciones_controles(){

    int x;

    CRONO frames_animacion_caminar;
    CRONO frames_animacion_ataque_1;
    CRONO frames_animacion_ataque_proyectil;
    CRONO frames_animacion_ataque_2;
    CRONO frames_animacion_escudo;
    CRONO frames_animacion_ataque_esp_1;
    CRONO frames_animacion_rayo;

    frames_animacion_caminar.sets_tiempo(9);
    frames_animacion_ataque_1.sets_tiempo(7);
    frames_animacion_ataque_proyectil.sets_tiempo(8);
    frames_animacion_ataque_2.sets_tiempo(8);
    frames_animacion_escudo.sets_tiempo(4);
    frames_animacion_ataque_esp_1.sets_tiempo(9);
    frames_animacion_rayo.sets_tiempo(6);


    while(!key[KEY_ESC]){

        frames_animacion_caminar.control_int();
        frames_animacion_ataque_1.control_int();
        frames_animacion_ataque_proyectil.control_int_invertido();
        frames_animacion_ataque_2.control_int();
        frames_animacion_escudo.control_int();
        frames_animacion_ataque_esp_1.control_int();
        frames_animacion_rayo.control_int();

        ///Ejemplo caminar:

        blit(JUGADOR_spr, EJE_MOVIMIENTO, frames_animacion_caminar.gets_cont() * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, EJE_MOVIMIENTO, 170, 30);

        ///Ejemplo ataque 1:

        blit(JUGADOR_spr, EJE_ATAQUE_1, (frames_animacion_ataque_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
        draw_sprite(buffer, EJE_ATAQUE_1, 155, 85);

        ///Ejemplo ataque 2:

        blit(PROYECTILES_spr, PROYECTIL_mov_spr,  1 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, PROYECTIL_mov_spr, 233 - 8 * frames_animacion_ataque_proyectil.gets_cont() , 160);

        blit(JUGADOR_spr, EJE_ATAQUE_2, (frames_animacion_ataque_2.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_2, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
        draw_sprite(buffer, EJE_ATAQUE_2, 155, 140);

        ///Ejemplo escudo:

        blit(JUGADOR_spr, EJE_ESCUDO, (frames_animacion_escudo.gets_cont() - 1) * DESPLAZAR_X_PIXEL, (1 * DESPLAZAR_X_PIXEL) + ANIMACION_ESCUDO, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, EJE_ESCUDO, 170, 205);

        ///Ejemplo altar:

        blit(BARRAS_spr, CORAZON_spr, 0, 67, 0, 0,  TAMANO_Y_CORAZON, TAMANO_X_CORAZON);
        draw_sprite(buffer, CORAZON_spr, 180, 245);

        blit(MENU_spr, CORAZON_spr, 429, 553, 0, 0,  TAMANO_Y_CORAZON, TAMANO_X_CORAZON);
        draw_sprite(buffer, CORAZON_spr, 187, 245);

        blit(JUGADOR_spr, JUGADOR_mov_spr, 0 * DESPLAZAR_Y_PIXEL, 1 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, JUGADOR_mov_spr, 170, 255);

        blit(ELEMENTOS_spr, ALTAR_spr, 0 * DESPLAZAR_Y_PIXEL, 0 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, ALTAR_spr, 200, 255);

        ///Ejemplo ataque especial 1:

        blit(PROYECTILES_spr, PROYECTIL_mov_spr,  1 * DESPLAZAR_Y_PIXEL, 5 * DESPLAZAR_X_PIXEL, 0, 0,  TAMANO_Y_SPRITE, TAMANO_X_SPRITE);
        draw_sprite(buffer, PROYECTIL_mov_spr, 238 - 8 * frames_animacion_ataque_proyectil.gets_cont() , 300);

        blit(JUGADOR_spr, EJE_ATAQUE_ESP_1, (frames_animacion_ataque_esp_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_ESP_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
        draw_sprite(buffer, EJE_ATAQUE_ESP_1, 155, 280);

        ///Ejemplo ataque especial 2:

        for(x=0 ; x<3 ; x++){
            blit(PILARES_spr, RAYO_spr, frames_animacion_rayo.gets_cont() * 17, 66, 0, 0,  TAMANO_X_SPRITE_RAYO, TAMANO_Y_SPRITE_RAYO);
            draw_sprite_v_flip(buffer, RAYO_spr, 215 + (32 * x), 330);
        }

        blit(JUGADOR_spr, EJE_ATAQUE_ESP_1, (frames_animacion_ataque_esp_1.gets_cont() - 1) * DESPLAZAR_Y_SPRITE_ATTACK, (1 * DESPLAZAR_X_SPRITE_ATTACK) + ANIMACION_ATAQUE_ESP_1, 0, 0,  TAMANO_Y_SPRITE_ATTACK, TAMANO_X_SPRITE_ATTACK);
        draw_sprite(buffer, EJE_ATAQUE_ESP_1, 155, 330);


        blit(MENU_spr, BOTON_FLECHA, 291, 402, 0, 0, 112, 78);
        draw_sprite(buffer, BOTON_FLECHA, 290, 10);

        blit(MENU_spr, BOTON_LETRA, 294, 573, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 90);
        blit(MENU_spr, BOTON_LETRA, 337, 573, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 140);
        blit(MENU_spr, BOTON_LETRA, 337, 618, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 190);
        blit(MENU_spr, BOTON_LETRA, 294, 663, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 240);
        blit(MENU_spr, BOTON_LETRA, 294, 618, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 290);
        blit(MENU_spr, BOTON_LETRA, 337, 663, 0, 0, 41, 44);
        draw_sprite(buffer, BOTON_LETRA, 325, 340);


        pantallaso();
        clear(buffer);

        ///Retraso de actividades en nanosegundos.
        rest(70);

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

    EJE_ATAQUE_1 = create_bitmap(64, 64);
    EJE_ATAQUE_2 = create_bitmap(64, 64);
    EJE_ESCUDO = create_bitmap(32, 32);
    EJE_RESAR = create_bitmap(32, 32);

    EJE_ATAQUE_ESP_1 = create_bitmap(64, 64);
    EJE_ATAQUE_ESP_2 = create_bitmap(64, 64);

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

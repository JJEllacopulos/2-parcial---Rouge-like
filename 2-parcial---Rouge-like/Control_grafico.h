#ifndef CONTROL_GRAFICO_H_INCLUDED
#define CONTROL_GRAFICO_H_INCLUDED

#define TAMAÑO_X_SPRITE 30 ///Tamaño del los sprites en el eje x.
#define TAMAÑO_Y_SPRITE 30 ///Tamaño del los sprites en el eje y.

void leer_mapa(MAPA mapa_juego, int x_externo, int y_externo){

    int x_interno;
    int y_interno;

    for(x_interno=0;x_interno<filas;x_interno++){
        for(y_interno=0;y_interno<columnas;y_interno++){

            switch(mapa_juego.gets_mapa_juego(x_externo, y_externo, x_interno, y_interno)){
                case MURO_INRROMPIBLE:

                    draw_sprite(buffer, MURO_INRROMPIBLE_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

                case MURO_ROMPIBLE:

                    draw_sprite(buffer, MURO_ROMPIBLE_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

                case COFRE:

                    draw_sprite(buffer, COFRE_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

                case AVATAR:

                    draw_sprite(buffer, AVATAR_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

                case PUERTA:

                    draw_sprite(buffer, PUERTA_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

                case PISO:

                    draw_sprite(buffer, PISO_spr, x_interno * TAMAÑO_X_SPRITE, y_interno * TAMAÑO_Y_SPRITE);
                break;

            }

        }
    }

}

#endif // CONTROL_GRAFICO_H_INCLUDED

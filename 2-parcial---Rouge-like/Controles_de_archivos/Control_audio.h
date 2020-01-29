#ifndef CONTROL_SONIDO_H_INCLUDED
#define CONTROL_SONIDO_H_INCLUDED

void asignar_audio(int zona){

    ///Carga de las pistas de audio:
    switch(zona){
        case 0:
            Fondo = load_midi("Musica/1  -(Touhou) - gosth_lead.mid");
        break;

        case 1:
            Fondo = load_midi("Musica/2 - (Touhou) - let_s_live_in_a_lovely_cemetery.mid");
        break;

        case 2:
            Fondo = load_midi("Musica/3 - (Touhou) - old_yuanxian.mid");
        break;

        case 3:
            Fondo = load_midi("Musica/4 - (Touhou) - dream_palace_of_the_great_mausol.mid");
        break;

        case 4:
            Fondo = load_midi("Musica/5 - (Touhou) - everlasting_red_spider_lily_ido_.mid");
        break;

        case 5:
            Fondo = load_midi("Musica/6 - (Touhou) - Beloved_Tomboyish_Daughter.mid");
        break;

        case 6:
            Fondo = load_midi("Musica/7 - (Touhou) - night_sakura_of_death_spirits.mid");
        break;

        case 7:
            Fondo = load_midi("Musica/8 - (Touhou) - the_spirit_of_avarice.mid");
        break;

        case 8:
            Fondo = load_midi("Musica/9 - (Touhou) - septette_for_the_dead_princess.mid");
        break;

        case 9:
            Fondo = load_midi("Musica/Menu - (Berserk) - Guts Theme.mid");
        break;

        default:
        break;

    }


}

#endif // CONTROL_SONIDO_H_INCLUDED

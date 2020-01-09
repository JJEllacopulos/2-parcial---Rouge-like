#ifndef CONTROL_SONIDO_H_INCLUDED
#define CONTROL_SONIDO_H_INCLUDED

void asignar_audio(int zona){

    switch(zona){
        case 0:
            ///Carga de las pistas de audio:
            Fondo = load_midi("Musica/Castlevania 2_ Simon's Quest - Bloody Tears.mid");
        break;

        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 7:
        break;

        case 9:
        break;

        default:
        break;

    }


}

#endif // CONTROL_SONIDO_H_INCLUDED

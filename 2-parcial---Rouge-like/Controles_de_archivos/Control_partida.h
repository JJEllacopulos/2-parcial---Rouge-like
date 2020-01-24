#ifndef CONTROL_PARTIDAS_H_INCLUDED
#define CONTROL_PARTIDAS_H_INCLUDED

class ARCHIVO_PARTIDA{
    private:

        int zona;
        MAPA mapa;
        MAPA_GRAFICO mapa_grafico;
        JUGADOR per_jug;

    public:

        ARCHIVO_PARTIDA();

        void Guardar_partida(int &zona_g, MAPA &mapa_g, MAPA_GRAFICO &mapa_grafico_g, JUGADOR &per_jug_g);
        void Cargar_partida(int &zona_c, MAPA &mapa_c, MAPA_GRAFICO &mapa_grafico_c, JUGADOR &per_jug_c);

        void Guardar_archivo();
        void Cargar_archivo();

};

ARCHIVO_PARTIDA::ARCHIVO_PARTIDA(){}

void ARCHIVO_PARTIDA::Guardar_partida(int &zona_g, MAPA &mapa_g, MAPA_GRAFICO &mapa_grafico_g, JUGADOR &per_jug_g){

    zona = zona_g;
    mapa = mapa_g;
    mapa_grafico = mapa_grafico_g;
    per_jug = per_jug_g;

    Guardar_archivo();

}

void ARCHIVO_PARTIDA::Cargar_partida(int &zona_c, MAPA &mapa_c, MAPA_GRAFICO &mapa_grafico_c, JUGADOR &per_jug_c){

    Cargar_archivo();

    zona_c = zona;
    mapa_c = mapa;
    mapa_grafico_c = mapa_grafico;
    per_jug_c = per_jug;

}

void ARCHIVO_PARTIDA::Guardar_archivo(){

    FILE *apertur;
    apertur = fopen("Archivo_de_guardado/Partida_1.dat", "wb");
    if(apertur == NULL){
        cout<< "Error al guardar la partida."<< endl;
        exit(1);
    }

    fwrite(this, sizeof this, 1, apertur);
    fclose(apertur);

}

void ARCHIVO_PARTIDA::Cargar_archivo(){

    FILE *apertur;
    bool flag;
    apertur = fopen("Archivo_de_guardado/Partida_1.dat", "rb");
    if(apertur == NULL){
        cout<< "Error al cargar la partida."<< endl;
        exit(1);
    }

    flag = fwrite(this, sizeof this, 1, apertur);
    fclose(apertur);
    //return flag;

}

#endif // CONTROL_PARTIDAS_H_INCLUDED

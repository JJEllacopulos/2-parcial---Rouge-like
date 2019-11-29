#ifndef CRONOMETRO_H_INCLUDED
#define CRONOMETRO_H_INCLUDED

class CRONO{
    private:
        int tiempo;
        int cont;
    public:
        CRONO();

        int gets_tiempo();
        void sets_tiempo(int aux);

        int gets_cont();
        bool gets_cont_bool();
        void sets_cont(int aux);

        bool control_bool();
        int control_int();

        bool control_bool_invertido();
        int control_int_invertido();
};

CRONO::CRONO(){
    tiempo = 0;
    cont = 0;
}

int CRONO::gets_tiempo(){
    return tiempo;
}

void CRONO::sets_tiempo(int aux){
    tiempo = aux;
}

int CRONO::gets_cont(){
    return cont;
}

bool CRONO::gets_cont_bool(){
    return cont;
}

void CRONO::sets_cont(int aux){
    cont = aux;
}

bool CRONO::control_bool(){
    if(cont <= tiempo){
        cont++;
        return true;
    }
    else{
        cont = 0;
        return false;
    }
}

int CRONO:: control_int(){
    if(cont <= tiempo){
        cont++;
        return cont;
    }
    else{
        cont = 0;
        return cont;
    }
}

bool CRONO::control_bool_invertido(){
    if(cont != 0){
        cont--;
        return true;
    }
    else{
        cont = tiempo;
        return false;
    }
}

int CRONO:: control_int_invertido(){
    if(cont != 0){
        cont--;
        return cont;
    }
    else{
        cont = tiempo;
        return cont;
    }
}

#endif // CRONOMETRO_H_INCLUDED

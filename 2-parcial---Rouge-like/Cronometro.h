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

        ///Con reinicio:
        bool control_bool();
        int control_int();

        bool control_bool_invertido();
        int control_int_invertido();

        ///Sin reincio:
        bool control_bool_sin_reinicio();
        int control_int_sin_reinicio();

        bool control_bool_invertido_sin_reinicio();
        int control_int_invertido_sin_reinicio();
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

///---Con reinicio:
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

///---Sin reinicio:

bool CRONO::control_bool_sin_reinicio(){
    if(cont <= tiempo){
        cont++;
        return true;
    }
    return false;
}

int CRONO:: control_int_sin_reinicio(){
    if(cont <= tiempo){
        cont++;
        return cont;
    }
    return cont;
}

bool CRONO::control_bool_invertido_sin_reinicio(){
    if(cont != 0){
        cont--;
        return true;
    }
    return false;
}

int CRONO:: control_int_invertido_sin_reinicio(){
    if(cont != 0){
        cont--;
        return cont;
    }
    return cont;
}

#endif // CRONOMETRO_H_INCLUDED

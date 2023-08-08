#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

 void vectorcero(int v[],int t){
    for(int i=0;i<t;i++){
        v[i]=0;
    }
 }

//PETICION DE NOMBRE PARA UN JUGADOR

void nombrejugador(char *n){
    char nomb[20];
    std::cout<<"NOMBRE DE JUGADOR: ";
    std::cin.getline(nomb,19);
    strcpy(n,nomb);
}
//FUNCION PARA ENCONTRAR EL NOMBRE DE LA COMBINACION GANADORA
void encontrarFraseGanadora(int dados[],char *_frase) {
    char f[19];
    int puntosMaximos = 0;
    int frecuencia[7] = {0}; // Contador de frecuencia de cada número de dado (del 1 al 6)

    for (int i = 0; i <= 6; i++) {
        frecuencia[dados[i]]++;
    }

    for (int i = 1; i <= 6; i++) {
        int puntos = 0;
        int count = frecuencia[i];

        if(i==2){
            if(count >=3){
                puntos+=i*100;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 2         ");
                }
            }
        }
        if(i==3){
            if(count >=3){
                puntos+=i*100;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 3         ");
                }
            }
        }
        if( i==4){
            if(count >=3){
                puntos+=i*100;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 4         ");
                }
            }
        }
        if(i==6){
            if(count >=3){
                puntos+=i*100;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 6         ");
                }
            }
        }
        puntosMaximos = std::max(puntosMaximos, puntos);
    }

    for (int i = 6; i >= 1; i--) {
        int puntos = 0;
        int count = frecuencia[i];

        if (i == 1) {
            if(count==3){
                puntos+=1000;
                if(puntos>puntosMaximos){
                    puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 1         ");
                }
            }else{
                if(count<=2 && count!=0){
                    puntos+=(count*100);
                if(puntos>puntosMaximos){
                    puntosMaximos=puntos;
                    strcpy(f,"JUEGO DE 1    ");
                }
                }
            }
        }
         if (i == 5) {
            if(count<=2 && count!=0){
                puntos += count * 50;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"JUEGO DE 5     ");
                }
            }else{
                if (count >= 3) {
                    puntos += i * 100;
                if(puntos>puntosMaximos){
                        puntosMaximos=puntos;
                    strcpy(f,"TRIO DE 5   ");
                }
                }
            }
        }
        puntosMaximos = std::max(puntosMaximos, puntos);
    }

    //escalera
    bool escalera = true;
    for (int i = 1; i <= 5; i++) {
        if (frecuencia[i] != 1) {
            escalera = false;
            break;
        }
    }
    if (frecuencia[6] != 1) {
        escalera = false;
    }
    if (escalera) {
            puntosMaximos=1500;
        strcpy(f,"ESCALERA        ");
    }
    //trio de 1 ampliado
        if(frecuencia[1]==4 || frecuencia[1]==5){
            puntosMaximos=2000;
            strcpy(f,"TRIO DE 1 AMPLIADO");
    }
    // todos los dados con valor 1
    if (frecuencia[1] == 6) {
        puntosMaximos=-1;
        strcpy(f,"SEXTETO!        ");
    }


    strcpy(_frase,f);
}

//FUNCION PARA ENCONTAR LA COMBINACION GANADORA
int encontrarCombiGanadora(int dados[]) {
    int puntosMaximos = 0;
    int pts=0;
    int frecuencia[7] = {0}; // Contador de frecuencia de cada número de dado (del 1 al 6)

    for (int i = 0; i <= 6; i++) {
        frecuencia[dados[i]]++;
    }

    for (int i = 1; i <= 6; i++) {
        int puntos = 0;
        int count = frecuencia[i];

        if(i==2){
            if(count >=3){
                puntos+=i*100;
            }
        }
        if(i==3){
            if(count >=3){
                puntos+=i*100;
            }
        }
        if( i==4){
            if(count >=3){
                puntos+=i*100;
            }
        }
        if(i==6){
            if(count >=3){
                puntos+=i*100;
            }
        }
        puntosMaximos = std::max(puntosMaximos, puntos);
    }

    for (int i = 6; i >= 1; i--) {
        int puntos = 0;
        int count = frecuencia[i];

        if (i == 1) {
            if(count==3){
                puntos+=1000;
            }else{
                if(count==1 || count ==2){
                    puntos+=(count*100);
                    puntosMaximos = std::max(puntosMaximos, puntos);
                }
            }
        }
         if (i == 5) {
            if(count<=2 && count!=0){
                puntos += count * 50;
                puntosMaximos = std::max(puntosMaximos, puntos);
            }else{
                if (count >= 3) {
                    puntos += i * 100;
                    puntosMaximos = std::max(puntosMaximos, puntos);
                }
            }
        }
        puntosMaximos = std::max(puntosMaximos, puntos);
    }

    //escalera
    bool escalera = true;
    for (int i = 1; i <= 5; i++) {
        if (frecuencia[i] != 1) {
            escalera = false;
            break;
        }
    }
    if (frecuencia[6] != 1) {
        escalera = false;
    }
    if (escalera) {
        pts=1500;
        puntosMaximos = std::max(puntosMaximos, pts);
    }
    //trio de 1 ampliado
        if(frecuencia[1]==4 || frecuencia[1]==5){
            pts=2000;
            puntosMaximos = std::max(puntosMaximos, pts);
    }
    // todos los dados con valor 1
    if (frecuencia[1] == 6) {
        return -1;
    }


    return puntosMaximos;
}

//FUNCION PARA MOSTRAR FRASE
void mostrarFrase(const char* frase) {
    for (int i = 0; frase[i] != '\0'; i++) {
        std::cout << frase[i];
    }
}

//FUNCION PARA DESPUES DE LOS LANZAMIENTOS
void pantallapostlanzamiento(){
    system("cls");
    rlutil::locate(30,13);
    std::cout<<"TIRANDO DADOS.";
    rlutil::msleep(250);
    std::cout<<".";
    rlutil::msleep(250);
    std::cout<<".";
    rlutil::msleep(250);
    system("cls");
}

//FUNCION DE LOS LANZAMIENTOS Y LAS RONDAS
void tiradas(){
    int vec[6],ptstotales=0,rondas=1;
    char frase[19];
    char nombre[20];
    bool vueltas=true,loop=true;
    nombrejugador(nombre);
    system("cls");
    while(loop){
        vueltas=true;
        int puntos=0,lanzamiento=0;
        while(vueltas){
            int c=0;
            std::cout<<"TURNO DE: "<<nombre<<std::endl;
            std::cout<<"------------------------------------------------------------------"<<std::endl;
            rlutil::locate(47,1);
            std::cout<<"|PUNTOS TOTALES: "<<ptstotales<<std::endl;
            rlutil::locate(22,1);
            std::cout<<"|RONDA NRO: "<<rondas<<std::endl;
            vectorcero(vec,6);
            srand((unsigned)time(0));
            for(int i=1;i<=6;i++){
                    vec[i]=(rand()%6)+1;
                dibujardado(i*10,5,vec[i]);
            }
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::setColor(rlutil::COLOR::WHITE);
            encontrarFraseGanadora(vec,frase);
            puntos+=encontrarCombiGanadora(vec);
            c=encontrarCombiGanadora(vec);
            if(c!=0){
                if(puntos>10000){
                    puntos=puntos-c;
                }
                lanzamiento++;
                rlutil::locate(1,12);
                std::cout<<"-------------------------------------------------------"<<std::endl;
                std::cout<<"LANZAMIENTO NRO: "<<lanzamiento<<std::endl;
                std::cout<<"-------------------------------------------------------"<<std::endl;
                if(c==-1){
                    rlutil::locate(2,11);
                    std::cout<<"CONSEGUISTE UN SEXTETO!"<<std::endl;
                }else{
                    rlutil::locate(25,13);
                    std::cout<<"|PUNTOS DE LA RONDA: "<<puntos<<std::endl;
                    rlutil::locate(2,11);
                    std::cout<<"+"<<c<<std::endl;
                    rlutil::locate(2,10);
                    mostrarFrase(frase);
                }
                if(c==-1 || puntos==10000){
                    rlutil::locate(20,15);
                    std::cout<<"ENHORABUENA!!"<<std::endl;
                    rlutil::locate(20,16);
                    std::cout<<"----------------"<<std::endl;
                    rlutil::locate(20,17);
                    std::cout<<"GANASTE EL JUEGO"<<std::endl;
                    vueltas=false;
                    rlutil::getkey();
                }else{
                    rlutil::locate(1,16);
                    std::cout<<"--------------------------------------------------"<<std::endl;
                    std::cout<<"|PARA SEGUIR LANZANDO: PULSE CUALQUIER TECLA     |"<<std::endl;
                    std::cout<<"|------------------------------------------------|"<<std::endl;
                    std::cout<<"|SI NO QUIERE LANZAN MAS EN ESTA RONDA: PULSE 'N'|"<<std::endl;
                    std::cout<<"--------------------------------------------------"<<std::endl;
                    switch(rlutil::getkey()){
                    case 78:
                        vueltas=false;
                        break;
                    case 110:
                        vueltas=false;
                        break;
                    default:
                        pantallapostlanzamiento();
                        break;
                    }
                }
            }else{
                rlutil::locate(1,14);
                std::cout<<"|PUNTOS DE LA RONDA: "<<puntos<<std::endl;
                rlutil::locate(1,15);
                std::cout<<"----------------------------------"<<std::endl;
                std::cout<<"PUNTOS OBTENIDOS EN ESTA TIRADA: "<<c<<std::endl;
                std::cout<<"----------------------------------"<<std::endl;
                rlutil::locate(25,18);
                std::cout<<"NO HUBO NINGUNA COMBINACION GANADORA  :("<<std::endl;
                rlutil::locate(25,19);
                std::cout<<"SE VAN A PERDER LOS PUNTOS DE ESTA RONDA"<<std::endl;
                rlutil::getkey();
                puntos=0;
                vueltas=false;
            }
        }//aquí terminan los lanzamientos
        ptstotales=puntos+ptstotales;
        if(ptstotales>10000){
            ptstotales=ptstotales-puntos;
        }
        rondas++;
        if(ptstotales==10000){
            rlutil::locate(20,10);
            std::cout<<"ENHORABUENA!!"<<std::endl;
            rlutil::locate(20,11);
            std::cout<<"----------------"<<std::endl;
            rlutil::locate(20,12);
            std::cout<<"GANASTE EL JUEGO"<<std::endl;
            rlutil::locate(20,15);
            std::cout<<"GANADOR: "<<nombre<<std::endl;
            rlutil::locate(20,16);
            std::cout<<"PUNTOS: "<<10000<<std::endl;
            rlutil::locate(20,17);
            std::cout<<"RONDAS: "<<rondas-1<<std::endl;
            rlutil::getkey();
            system("cls");
            rlutil::locate(20,10);
            std::cout<<"MUCHAS GRACIAS POR JUGAR! :)"<<std::endl;
            loop=false;
        }else{
            rlutil::locate(20,10);
            std::cout<<"SI QUIERE PASAR A LA SIGUIENTE RONDA PULSE CUALQUIER TECLA"<<std::endl;
            rlutil::locate(20,11);
            std::cout<<"SI 'NO' QUIERE PASAR A LA SIGUIENTE RONDA PULSE 'N'"<<std::endl;
            switch(rlutil::getkey()){
            case 78:
                system("cls");
                loop=false;
                rlutil::locate(20,10);
                std::cout<<"MUCHAS GRACIAS POR JUGAR! :)"<<std::endl;
                break;
            case 110:
                loop=false;
                system("cls");
                rlutil::locate(20,10);
                std::cout<<"MUCHAS GRACIAS POR JUGAR! :)"<<std::endl;
                break;
            default:
                pantallapostlanzamiento();
                break;
            }
        }
    }//aquí terminan las rondas
}

//FUNCION PARA ILUMINAR LO SELECCIONADO
void seleccionado(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    }else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx,posy);
    std::cout<< text <<std::endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

//FUNCION MENU
void menu(){
    int op=1,y=10;
    rlutil::hidecursor();
    do{
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            rlutil::locate(55,9);
            std::cout<<"       DIEZ MIL    ";
            seleccionado("     UN JUGADOR     ", 55, 10, y==10);
            //seleccionado("    DOS JUGADORES   ", 55, 11, y==11);
            //seleccionado(" GUARDAR PUNTUACION ", 55, 12, y==12);
            seleccionado("        SALIR       ", 55, 11, y==11);
            //flecha de seleccion: ">"
            /*
            rlutil::locate(53,y);
            std::cout<< (char)62<<std::endl;
            */

            switch(rlutil::getkey()){
        case 14:
            rlutil::locate(53,y);
            std::cout<<" "<<std::endl;
            y--;
            if(y<10){
                y=10;
            }
            break;
        case 15:
            rlutil::locate(53,y);
            std::cout<<" "<<std::endl;
            y++;
            if(y>11){
                y=11;
            }
            break;
        case 1:
            switch(y){
        case 10:
            system("cls");
            rlutil::locate(45,10);
            std::cout<<"JUEGO PARA UN JUGADOR"<<std::endl;
            rlutil::locate(43,12);
            std::cout<<"presione cualquier tecla...";
            rlutil::getkey();
            system("cls");
            tiradas();
        case 13:
            op=0;
            break;
        default:
            break;
            }
            break;
            }
    }while(op!=0);
}

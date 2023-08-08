#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "dados.h"
#include "funciones.h"

int main (){
    rlutil::hidecursor();

    menu();

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::BLACK);

    return 0;
}


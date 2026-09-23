#include "IngresoBuilder.h"
#include "Controladora.h"
#include"DeduccionBuilder.h"
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {

    Controladora* app = Controladora::getInstance();
    app->ejecutar();

	delete Controladora::getInstance(); 

    return 0;

}
   
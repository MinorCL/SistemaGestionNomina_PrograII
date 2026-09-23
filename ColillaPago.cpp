//#include "ColillaPago.h"
//#include <sstream>
//#include <iomanip>
//
//ColillaPago::ColillaPago(int salarioBruto, int totalDeducciones)
//    : salarioBruto(salarioBruto),
//    totalDeducciones(totalDeducciones),
//    salarioNeto(salarioBruto - totalDeducciones),
//    fechaGeneracion(obtenerFechaActual()) {
//}
//
//string ColillaPago::obtenerFechaActual() {
//    auto now = chrono::system_clock::now();
//    time_t tiempoActual = chrono::system_clock::to_time_t(now);
//    tm* tiempoLocal = localtime(&tiempoActual);
//
//    ostringstream oss;
//    oss << put_time(tiempoLocal, "%d/%m/%Y %H:%M:%S");
//    return oss.str();
//}
//
//string ColillaPago::getFechaGeneracion() const {
//    return fechaGeneracion;
//}
//
//int ColillaPago::getSalarioBruto() const {
//    return salarioBruto;
//}
//
//int ColillaPago::getTotalDeducciones() const {
//    return totalDeducciones;
//}
//
//int ColillaPago::getSalarioNeto() const {
//    return salarioNeto;
//}

#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor
{
private:

    std::string nombreCompleto;
    std::string codigoProfesor;

public:

    Profesor();

    Profesor(
        std::string nombreCompleto,
        std::string codigoProfesor
    );

    std::string getNombreCompleto();
    std::string getCodigoProfesor();

    void setNombreCompleto(std::string nombreCompleto);
    void setCodigoProfesor(std::string codigoProfesor);
};

#endif
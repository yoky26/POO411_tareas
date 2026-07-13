#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante
{
private:

    std::string nombreCompleto;
    std::string matricula;
    std::string sesion;

public:

    Estudiante();

    Estudiante(
        std::string nombreCompleto,
        std::string matricula,
        std::string sesion
    );

    std::string getNombreCompleto();
    std::string getMatricula();
    std::string getSesion();

    void setNombreCompleto(std::string nombreCompleto);
    void setMatricula(std::string matricula);
    void setSesion(std::string sesion);
};

#endif
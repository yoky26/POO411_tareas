#include "Estudiante.h"

Estudiante::Estudiante()
{
}

Estudiante::Estudiante(
    std::string nombreCompleto,
    std::string matricula,
    std::string sesion
)
{
    this->nombreCompleto = nombreCompleto;
    this->matricula = matricula;
    this->sesion = sesion;
}

std::string Estudiante::getNombreCompleto()
{
    return nombreCompleto;
}

std::string Estudiante::getMatricula()
{
    return matricula;
}

std::string Estudiante::getSesion()
{
    return sesion;
}

void Estudiante::setNombreCompleto(std::string nombreCompleto)
{
    this->nombreCompleto = nombreCompleto;
}

void Estudiante::setMatricula(std::string matricula)
{
    this->matricula = matricula;
}

void Estudiante::setSesion(std::string sesion)
{
    this->sesion = sesion;
}
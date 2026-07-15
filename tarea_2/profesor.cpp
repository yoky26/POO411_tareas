#include "Profesor.h"

Profesor::Profesor()
{
}

Profesor::Profesor(
    std::string nombreCompleto,
    std::string codigoProfesor
)
{
    this->nombreCompleto = nombreCompleto;
    this->codigoProfesor = codigoProfesor;
}

std::string Profesor::getNombreCompleto()
{
    return nombreCompleto;
}

std::string Profesor::getCodigoProfesor()
{
    return codigoProfesor;
}

void Profesor::setNombreCompleto(std::string nombreCompleto)
{
    this->nombreCompleto = nombreCompleto;
}

void Profesor::setCodigoProfesor(std::string codigoProfesor)
{
    this->codigoProfesor = codigoProfesor;
}
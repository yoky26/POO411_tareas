#include "Materia.h"

Materia::Materia()
{
}

Materia::Materia(
    std::string nombreMateria,
    std::string codigoMateria,
    int cantidadCreditos
)
{
    this->nombreMateria = nombreMateria;
    this->codigoMateria = codigoMateria;
    this->cantidadCreditos = cantidadCreditos;
}

std::string Materia::getNombreMateria()
{
    return nombreMateria;
}

std::string Materia::getCodigoMateria()
{
    return codigoMateria;
}

int Materia::getCantidadCreditos()
{
    return cantidadCreditos;
}

void Materia::setNombreMateria(std::string nombreMateria)
{
    this->nombreMateria = nombreMateria;
}

void Materia::setCodigoMateria(std::string codigoMateria)
{
    this->codigoMateria = codigoMateria;
}

void Materia::setCantidadCreditos(int cantidadCreditos)
{
    this->cantidadCreditos = cantidadCreditos;
}
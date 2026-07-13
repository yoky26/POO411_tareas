#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia
{
private:

    std::string nombreMateria;
    std::string codigoMateria;
    int cantidadCreditos;

public:

    Materia();

    Materia(
        std::string nombreMateria,
        std::string codigoMateria,
        int cantidadCreditos
    );

    std::string getNombreMateria();
    std::string getCodigoMateria();
    int getCantidadCreditos();

    void setNombreMateria(std::string nombreMateria);
    void setCodigoMateria(std::string codigoMateria);
    void setCantidadCreditos(int cantidadCreditos);
};

#endif
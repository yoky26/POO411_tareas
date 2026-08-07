#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class Prestamo {
private:
    std::string codUsuario;
    std::string codMaterial;

public:
    Prestamo(std::string u, std::string m);
    std::string getCodUsuario() const;
    std::string getCodMaterial() const;
};

#endif
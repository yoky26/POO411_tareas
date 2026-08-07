#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string codigo;
    std::string nombre;
    static int contador;

public:
    Usuario(std::string n);
    std::string getCodigo() const;
    std::string getNombre() const;
};

#endif
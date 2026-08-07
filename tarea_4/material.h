#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material {
private:
    std::string codigo;
    std::string titulo;
    bool disponible;
    static int contador;

public:
    Material(std::string t);
    virtual ~Material() {}

    virtual std::string getTipo() const = 0;
    virtual std::string getDato() const = 0;

    std::string getCodigo() const;
    std::string getTitulo() const;
    bool estaDisponible() const;
    void cambiarEstado(bool e);
};

#endif
#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <memory>
#include "material.h"
#include "libro.h"
#include "revista.h"
#include "usuario.h"
#include "prestamo.h"

class Sistema {
private:
    std::vector<std::unique_ptr<Material>> listaMateriales;
    std::vector<Usuario> listaUsuarios;
    std::vector<Prestamo> listaPrestamos;

    bool existeUsuario(std::string codigo);
    int cantidadPrestamos(std::string codigo);

public:
    void registrarLibro();
    void registrarRevista();
    void registrarUsuario();
    void realizarPrestamo();
    void realizarDevolucion();
    void mostrarMateriales();
    void iniciarMenu();
};

#endif
#include "sistema.h"
#include <iostream>
#include <limits>

bool Sistema::existeUsuario(std::string codigo) {
    for (int i = 0; i < listaUsuarios.size(); i++) {
        if (listaUsuarios[i].getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

int Sistema::cantidadPrestamos(std::string codigo) {
    int cont = 0;
    for (int i = 0; i < listaPrestamos.size(); i++) {
        if (listaPrestamos[i].getCodUsuario() == codigo) {
            cont = cont + 1;
        }
    }
    return cont;
}

void Sistema::registrarLibro() {
    std::string titulo, autor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Ingrese autor: ";
    std::getline(std::cin, autor);
    listaMateriales.push_back(std::make_unique<Libro>(titulo, autor));
    std::cout << "Libro registrado. Codigo: " << listaMateriales.back()->getCodigo() << std::endl;
}

void Sistema::registrarRevista() {
    std::string titulo, editorial;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese titulo: ";
    std::getline(std::cin, titulo);
    std::cout << "Ingrese editorial: ";
    std::getline(std::cin, editorial);
    listaMateriales.push_back(std::make_unique<Revista>(titulo, editorial));
    std::cout << "Revista registrada. Codigo: " << listaMateriales.back()->getCodigo() << std::endl;
}

void Sistema::registrarUsuario() {
    std::string nombre;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese nombre del usuario: ";
    std::getline(std::cin, nombre);
    listaUsuarios.emplace_back(nombre);
    std::cout << "Usuario registrado. Codigo: " << listaUsuarios.back().getCodigo() << std::endl;
}

void Sistema::realizarPrestamo() {
    std::string codU, codM;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Codigo del usuario: ";
    std::getline(std::cin, codU);
    std::cout << "Codigo del material: ";
    std::getline(std::cin, codM);

    if (existeUsuario(codU) == false) {
        std::cout << "El usuario no esta registrado." << std::endl;
        return;
    }
    if (cantidadPrestamos(codU) >= 3) {
        std::cout << "El usuario ya tiene 3 prestamos." << std::endl;
        return;
    }

    for (int i = 0; i < listaMateriales.size(); i++) {
        if (listaMateriales[i]->getCodigo() == codM) {
            if (listaMateriales[i]->estaDisponible() == false) {
                std::cout << "El material no esta disponible." << std::endl;
                return;
            }
            listaMateriales[i]->cambiarEstado(false);
            listaPrestamos.emplace_back(codU, codM);
            std::cout << "Prestamo realizado con exito." << std::endl;
            return;
        }
    }
    std::cout << "No existe ese codigo de material." << std::endl;
}

void Sistema::realizarDevolucion() {
    std::string codM;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Codigo del material a devolver: ";
    std::getline(std::cin, codM);

    for (int i = 0; i < listaPrestamos.size(); i++) {
        if (listaPrestamos[i].getCodMaterial() == codM) {
            for (int j = 0; j < listaMateriales.size(); j++) {
                if (listaMateriales[j]->getCodigo() == codM) {
                    listaMateriales[j]->cambiarEstado(true);
                }
            }
            listaPrestamos.erase(listaPrestamos.begin() + i);
            std::cout << "Devolucion realizada." << std::endl;
            return;
        }
    }
    std::cout << "No se encontro ese prestamo." << std::endl;
}

void Sistema::mostrarMateriales() {
    if (listaMateriales.size() == 0) {
        std::cout << "No hay materiales registrados." << std::endl;
        return;
    }
    std::cout << std::endl << "--- Lista de Materiales ---" << std::endl;
    for (int i = 0; i < listaMateriales.size(); i++) {
        std::cout << listaMateriales[i]->getTipo() << " | ";
        std::cout << listaMateriales[i]->getCodigo() << " | ";
        std::cout << listaMateriales[i]->getTitulo() << " | ";
        std::cout << listaMateriales[i]->getDato() << " | ";
        if (listaMateriales[i]->estaDisponible() == true) {
            std::cout << "Disponible";
        } else {
            std::cout << "Prestado";
        }
        std::cout << std::endl;
    }
}

void Sistema::iniciarMenu() {
    int opcion;
    do {
        std::cout << std::endl << "===== SISTEMA DE BIBLIOTECA =====" << std::endl;
        std::cout << "1. Registrar Libro" << std::endl;
        std::cout << "2. Registrar Revista" << std::endl;
        std::cout << "3. Registrar Usuario" << std::endl;
        std::cout << "4. Realizar Prestamo" << std::endl;
        std::cout << "5. Realizar Devolucion" << std::endl;
        std::cout << "6. Mostrar todos los Materiales" << std::endl;
        std::cout << "0. Salir del Sistema" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) registrarLibro();
        else if (opcion == 2) registrarRevista();
        else if (opcion == 3) registrarUsuario();
        else if (opcion == 4) realizarPrestamo();
        else if (opcion == 5) realizarDevolucion();
        else if (opcion == 6) mostrarMateriales();
        else if (opcion == 0) std::cout << "Saliendo del sistema..." << std::endl;
        else std::cout << "Opcion invalida. Intente nuevamente." << std::endl;

    } while (opcion != 0);
}
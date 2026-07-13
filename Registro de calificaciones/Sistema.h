#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <memory>

#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Calificacion.h"

class Sistema
{
private:

    std::vector<std::unique_ptr<Estudiante>> estudiantes;
    std::vector<std::unique_ptr<Profesor>> profesores;
    std::vector<std::unique_ptr<Materia>> materias;
    std::vector<std::unique_ptr<Calificacion>> calificaciones;

    void guardarEstudiantes();
    void guardarProfesores();
    void guardarMaterias();
    void guardarCalificaciones();

    void cargarEstudiantes();
    void cargarProfesores();
    void cargarMaterias();
    void cargarCalificaciones();

public:

    Sistema();

    void menu();

    void registrarEstudiante();
    void registrarProfesor();
    void registrarMateria();
    void registrarCalificacion();

    void verEstudiantes();
    void verProfesores();
    void verMaterias();
    void verCalificaciones();
};

#endif
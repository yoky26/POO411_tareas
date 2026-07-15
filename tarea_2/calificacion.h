#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"

class Calificacion
{
private:

    Estudiante* estudiante;
    Profesor* profesor;
    Materia* materia;
    double nota;

public:

    Calificacion();

    Calificacion(
        Estudiante* estudiante,
        Profesor* profesor,
        Materia* materia,
        double nota
    );

    Estudiante* getEstudiante();
    Profesor* getProfesor();
    Materia* getMateria();
    double getNota();

    void setEstudiante(Estudiante* estudiante);
    void setProfesor(Profesor* profesor);
    void setMateria(Materia* materia);
    void setNota(double nota);
};

#endif
#include "Calificacion.h"

Calificacion::Calificacion()
{
    estudiante = nullptr;
    profesor = nullptr;
    materia = nullptr;
    nota = 0;
}

Calificacion::Calificacion(
    Estudiante* estudiante,
    Profesor* profesor,
    Materia* materia,
    double nota
)
{
    this->estudiante = estudiante;
    this->profesor = profesor;
    this->materia = materia;
    this->nota = nota;
}

Estudiante* Calificacion::getEstudiante()
{
    return estudiante;
}

Profesor* Calificacion::getProfesor()
{
    return profesor;
}

Materia* Calificacion::getMateria()
{
    return materia;
}

double Calificacion::getNota()
{
    return nota;
}

void Calificacion::setEstudiante(Estudiante* estudiante)
{
    this->estudiante = estudiante;
}

void Calificacion::setProfesor(Profesor* profesor)
{
    this->profesor = profesor;
}

void Calificacion::setMateria(Materia* materia)
{
    this->materia = materia;
}

void Calificacion::setNota(double nota)
{
    this->nota = nota;
}
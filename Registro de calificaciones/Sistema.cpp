#include "Sistema.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


Sistema::Sistema()
{
    cargarEstudiantes();
    cargarProfesores();
    cargarMaterias();
    cargarCalificaciones();
}


void Sistema::menu()
{
    int opcion;

    do
    {
        std::cout << "\n===== SISTEMA DE REGISTRO DE CALIFICACIONES =====\n";
        std::cout << "1. Registrar estudiante\n";
        std::cout << "2. Registrar profesor\n";
        std::cout << "3. Registrar materia\n";
        std::cout << "4. Registrar calificacion\n";
        std::cout << "5. Ver estudiantes\n";
        std::cout << "6. Ver profesores\n";
        std::cout << "7. Ver materias\n";
        std::cout << "8. Ver calificaciones\n";
        std::cout << "9. Salir\n";

        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;


        switch(opcion)
        {
        case 1:
            registrarEstudiante();
            break;

        case 2:
            registrarProfesor();
            break;

        case 3:
            registrarMateria();
            break;

        case 4:
            registrarCalificacion();
            break;

        case 5:
            verEstudiantes();
            break;

        case 6:
            verProfesores();
            break;

        case 7:
            verMaterias();
            break;

        case 8:
            verCalificaciones();
            break;

        case 9:

            guardarEstudiantes();
            guardarProfesores();
            guardarMaterias();
            guardarCalificaciones();

            std::cout << "Datos guardados. Hasta luego.\n";
            break;


        default:
            std::cout << "Opcion invalida.\n";
        }


    } while(opcion != 9);
}



void Sistema::registrarEstudiante()
{
    std::string nombre;
    std::string matricula;
    std::string sesion;


    std::cin.ignore();


    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);


    std::cout << "Matricula: ";
    std::getline(std::cin, matricula);


    std::cout << "Sesion: ";
    std::getline(std::cin, sesion);



    estudiantes.push_back(
        std::make_unique<Estudiante>(
            nombre,
            matricula,
            sesion
        )
    );


    std::cout << "Estudiante registrado.\n";
}



void Sistema::registrarProfesor()
{
    std::string nombre;
    std::string codigo;


    std::cin.ignore();


    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);


    std::cout << "Codigo profesor: ";
    std::getline(std::cin, codigo);



    profesores.push_back(
        std::make_unique<Profesor>(
            nombre,
            codigo
        )
    );


    std::cout << "Profesor registrado.\n";
}



void Sistema::registrarMateria()
{
    std::string nombre;
    std::string codigo;
    int creditos;


    std::cin.ignore();


    std::cout << "Nombre materia: ";
    std::getline(std::cin, nombre);


    std::cout << "Codigo materia: ";
    std::getline(std::cin, codigo);


    std::cout << "Cantidad de creditos: ";
    std::cin >> creditos;



    materias.push_back(
        std::make_unique<Materia>(
            nombre,
            codigo,
            creditos
        )
    );


    std::cout << "Materia registrada.\n";
}

void Sistema::registrarCalificacion()
{
    if(estudiantes.empty() || profesores.empty() || materias.empty())
    {
        std::cout << "Debe registrar estudiantes, profesores y materias primero.\n";
        return;
    }


    std::cout << "\n===== ESTUDIANTES =====\n";

    for(size_t i = 0; i < estudiantes.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << estudiantes[i]->getNombreCompleto()
                  << std::endl;
    }


    int estudianteSeleccionado;

    std::cout << "Seleccione estudiante: ";
    std::cin >> estudianteSeleccionado;



    std::cout << "\n===== PROFESORES =====\n";

    for(size_t i = 0; i < profesores.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << profesores[i]->getNombreCompleto()
                  << std::endl;
    }


    int profesorSeleccionado;

    std::cout << "Seleccione profesor: ";
    std::cin >> profesorSeleccionado;



    std::cout << "\n===== MATERIAS =====\n";

    for(size_t i = 0; i < materias.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << materias[i]->getNombreMateria()
                  << std::endl;
    }


    int materiaSeleccionada;

    std::cout << "Seleccione materia: ";
    std::cin >> materiaSeleccionada;



    double nota;

    std::cout << "Ingrese nota: ";
    std::cin >> nota;



    calificaciones.push_back(
        std::make_unique<Calificacion>(
            estudiantes[estudianteSeleccionado - 1].get(),
            profesores[profesorSeleccionado - 1].get(),
            materias[materiaSeleccionada - 1].get(),
            nota
        )
    );


    std::cout << "Calificacion registrada.\n";
}




void Sistema::verEstudiantes()
{
    std::cout << "\n===== ESTUDIANTES =====\n";


    for(const auto& estudiante : estudiantes)
    {
        std::cout << estudiante->getNombreCompleto()
                  << " | "
                  << estudiante->getMatricula()
                  << " | "
                  << estudiante->getSesion()
                  << std::endl;
    }
}



void Sistema::verProfesores()
{
    std::cout << "\n===== PROFESORES =====\n";


    for(const auto& profesor : profesores)
    {
        std::cout << profesor->getNombreCompleto()
                  << " | "
                  << profesor->getCodigoProfesor()
                  << std::endl;
    }
}




void Sistema::verMaterias()
{
    std::cout << "\n===== MATERIAS =====\n";


    for(const auto& materia : materias)
    {
        std::cout << materia->getNombreMateria()
                  << " | "
                  << materia->getCodigoMateria()
                  << " | "
                  << materia->getCantidadCreditos()
                  << std::endl;
    }
}





void Sistema::verCalificaciones()
{
    std::cout << "\n===== CALIFICACIONES =====\n";


    for(const auto& calificacion : calificaciones)
    {
        std::cout << "Estudiante: "
                  << calificacion->getEstudiante()->getNombreCompleto()
                  << std::endl;


        std::cout << "Profesor: "
                  << calificacion->getProfesor()->getNombreCompleto()
                  << std::endl;


        std::cout << "Materia: "
                  << calificacion->getMateria()->getNombreMateria()
                  << std::endl;


        std::cout << "Nota: "
                  << calificacion->getNota()
                  << std::endl;


        std::cout << "---------------------\n";
    }
}

void Sistema::guardarEstudiantes()
{
    std::ofstream archivo("estudiantes.txt");

    for(const auto& estudiante : estudiantes)
    {
        archivo << estudiante->getNombreCompleto()
                << ";"
                << estudiante->getMatricula()
                << ";"
                << estudiante->getSesion()
                << std::endl;
    }

    archivo.close();
}



void Sistema::guardarProfesores()
{
    std::ofstream archivo("profesores.txt");

    for(const auto& profesor : profesores)
    {
        archivo << profesor->getNombreCompleto()
                << ";"
                << profesor->getCodigoProfesor()
                << std::endl;
    }

    archivo.close();
}



void Sistema::guardarMaterias()
{
    std::ofstream archivo("materias.txt");

    for(const auto& materia : materias)
    {
        archivo << materia->getNombreMateria()
                << ";"
                << materia->getCodigoMateria()
                << ";"
                << materia->getCantidadCreditos()
                << std::endl;
    }

    archivo.close();
}



void Sistema::guardarCalificaciones()
{
    std::ofstream archivo("calificaciones.txt");

    for(const auto& calificacion : calificaciones)
    {
        archivo << calificacion->getEstudiante()->getMatricula()
                << ";"
                << calificacion->getProfesor()->getCodigoProfesor()
                << ";"
                << calificacion->getMateria()->getCodigoMateria()
                << ";"
                << calificacion->getNota()
                << std::endl;
    }

    archivo.close();
}

void Sistema::cargarEstudiantes()
{
    std::ifstream archivo("estudiantes.txt");

    std::string nombre;
    std::string matricula;
    std::string sesion;


    while(std::getline(archivo, nombre, ';'))
    {
        std::getline(archivo, matricula, ';');
        std::getline(archivo, sesion);


        estudiantes.push_back(
            std::make_unique<Estudiante>(
                nombre,
                matricula,
                sesion
            )
        );
    }


    archivo.close();
}



void Sistema::cargarProfesores()
{
    std::ifstream archivo("profesores.txt");

    std::string nombre;
    std::string codigo;


    while(std::getline(archivo, nombre, ';'))
    {
        std::getline(archivo, codigo);


        profesores.push_back(
            std::make_unique<Profesor>(
                nombre,
                codigo
            )
        );
    }


    archivo.close();
}



void Sistema::cargarMaterias()
{
    std::ifstream archivo("materias.txt");

    std::string nombre;
    std::string codigo;
    int creditos;


    while(std::getline(archivo, nombre, ';'))
    {
        std::getline(archivo, codigo, ';');

        archivo >> creditos;
        archivo.ignore();


        materias.push_back(
            std::make_unique<Materia>(
                nombre,
                codigo,
                creditos
            )
        );
    }


    archivo.close();
}

void Sistema::cargarCalificaciones()
{
    std::ifstream archivo("calificaciones.txt");

    std::string matricula;
    std::string codigoProfesor;
    std::string codigoMateria;
    double nota;


    while(std::getline(archivo, matricula, ';'))
    {
        std::getline(archivo, codigoProfesor, ';');
        std::getline(archivo, codigoMateria, ';');

        archivo >> nota;
        archivo.ignore();


        Estudiante* estudianteEncontrado = nullptr;
        Profesor* profesorEncontrado = nullptr;
        Materia* materiaEncontrada = nullptr;


        for(auto& estudiante : estudiantes)
        {
            if(estudiante->getMatricula() == matricula)
            {
                estudianteEncontrado = estudiante.get();
                break;
            }
        }


        for(auto& profesor : profesores)
        {
            if(profesor->getCodigoProfesor() == codigoProfesor)
            {
                profesorEncontrado = profesor.get();
                break;
            }
        }


        for(auto& materia : materias)
        {
            if(materia->getCodigoMateria() == codigoMateria)
            {
                materiaEncontrada = materia.get();
                break;
            }
        }


        if(estudianteEncontrado != nullptr &&
           profesorEncontrado != nullptr &&
           materiaEncontrada != nullptr)
        {
            calificaciones.push_back(
                std::make_unique<Calificacion>(
                    estudianteEncontrado,
                    profesorEncontrado,
                    materiaEncontrada,
                    nota
                )
            );
        }
    }


    archivo.close();
}
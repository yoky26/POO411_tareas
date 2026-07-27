#include <iostream>
#include <string>

using namespace std;


class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};


class Profesor : public Persona {
private:
    string materia;

public:
    Profesor(string n, int e, string m) : Persona(n, e) {
        materia = m;
    }

    void mostrarProfesor() {
        mostrar();
        cout << "Materia: " << materia << endl;
    }
};


class Estudiante : public Persona {
private:
    string matricula;

public:
    Estudiante(string n, int e, string mat) : Persona(n, e) {
        matricula = mat;
    }

    void mostrarEstudiante() {
        mostrar();
        cout << "Matricula: " << matricula << endl;
    }
};


class Almacenamiento {
private:
    string archivo;

public:
    Almacenamiento(string a) {
        archivo = a;
    }

    void guardarArchivo() {
        cout << "Archivo guardado correctamente." << endl;
        cout << "Nombre del archivo: " << archivo << endl;
    }
};

int main() {

    Profesor profesor("Yoel Andeyci Pilier Martínez", 45, "Programacion Orientada a Objetos");
    Estudiante estudiante("Yocaira Mercedes", 29, "25-MISN-2-007");
    Almacenamiento almacenamiento("almacenamiento.cpp");

    cout << " PROFESOR " << endl;
    profesor.mostrarProfesor();

    cout << endl;

    cout << "ESTUDIANTE " << endl;
    estudiante.mostrarEstudiante();

    cout << endl;

    cout << " ALMACENAMIENTO " << endl;
    almacenamiento.guardarArchivo();

    return 0;
}
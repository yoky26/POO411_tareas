#include <iostream>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <vector>

// Se evitan problemas de includePath declarando las clases mínimas aquí
class Audio {
public:
    virtual void mostrar() = 0;
    virtual ~Audio() {}
};

class Cancion : public Audio {
    std::string titulo;
    std::string artista;
public:
    Cancion(const std::string& t, const std::string& a) : titulo(t), artista(a) {}
    void mostrar() override {
        std::cout << "Cancion - Titulo: " << titulo << ", Artista: " << artista << "\n";
    }
};

class Podcast : public Audio {
    std::string titulo;
    std::string presentador;
public:
    Podcast(const std::string& t, const std::string& p) : titulo(t), presentador(p) {}
    void mostrar() override {
        std::cout << "Podcast - Titulo: " << titulo << ", Presentador: " << presentador << "\n";
    }
};

int main()
{
    std::vector<Audio*> lista;
    int opcion;

    do
    {
        std::cout << "\n=== Registro de audios ===\n";
        std::cout << "1. Registrar cancion\n";
        std::cout << "2. Registrar podcast\n";
        std::cout << "3. Mostrar audios\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";

        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1)
        {
            std::string titulo;
            std::string artista;

            std::cout << "Titulo de la cancion: ";
            std::getline(std::cin, titulo);

            std::cout << "Artista: ";
            std::getline(std::cin, artista);

            lista.push_back(new Cancion(titulo, artista));

            std::cout << "Cancion registrada.\n";
        }
        else if (opcion == 2)
        {
            std::string titulo;
            std::string presentador;

            std::cout << "Titulo del podcast: ";
            std::getline(std::cin, titulo);

            std::cout << "Presentador: ";
            std::getline(std::cin, presentador);

            lista.push_back(new Podcast(titulo, presentador));

            std::cout << "Podcast registrado.\n";
        }
        else if (opcion == 3)
        {
            if (lista.empty())
            {
                std::cout << "No hay audios registrados.\n";
            }
            else
            {
                std::cout << "\n--- Lista de audios ---\n";

                for (int i = 0; i < static_cast<int>(lista.size()); i++)
                {
                    lista[i]->mostrar();
                }
            }
        }
        else if (opcion != 0)
        {
            std::cout << "Opcion no valida.\n";
        }

    } while (opcion != 0);

    for (int i = 0; i < static_cast<int>(lista.size()); i++)
    {
        delete lista[i];
    }

    return 0;
}
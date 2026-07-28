#include "Cancion.h"

Cancion::Cancion(std::string titulo, std::string autor)
    : Audio(titulo, autor)
{
}

void Cancion::mostrar()
{
    std::cout << "Cancion: " << titulo
              << " - Artista: " << autor << std::endl;
}
#include <iostream>
#include "podscat.h"

Podcast::Podcast(std::string titulo, std::string autor)
    : Audio(titulo, autor)
{
}

void Podcast::mostrar()
{
    std::cout << "Podcast: " << titulo
              << " - Presentador: " << autor << std::endl;
}
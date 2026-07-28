#include "Audio.h"

Audio::Audio(std::string titulo, std::string autor)
{
    this->titulo = titulo;
    this->autor = autor;
}

void Audio::mostrar()
{
    std::cout << titulo << " - " << autor << std::endl;
}

Audio::~Audio()
{
}
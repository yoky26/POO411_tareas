#ifndef CANCION_H
#define CANCION_H

#include "Audio.h"

class Cancion : public Audio
{
public:
    Cancion(std::string titulo, std::string autor);

    virtual void mostrar();
};

#endif
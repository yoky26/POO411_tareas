#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <string>

class Audio
{
protected:
    std::string titulo;
    std::string autor;

public:
    Audio(std::string titulo, std::string autor);

    virtual void mostrar();

    virtual ~Audio();
};

#endif
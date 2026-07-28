#ifndef PODCAST_H
#define PODCAST_H

#include "Audio.h"

class Podcast : public Audio
{
public:
    Podcast(std::string titulo, std::string autor);

    virtual void mostrar();
};

#endif
#ifndef REVISTA_H
#define REVISTA_H

#include "material.h"

class Revista : public Material {
private:
    std::string editorial;

public:
    Revista(std::string t, std::string e);
    std::string getTipo() const;
    std::string getDato() const;
};

#endif
#ifndef TP2DISEÑO_PARTE_H
#define TP2DISEÑO_PARTE_H

#include <map>
using namespace std;

class Parte{
public:
    bool* dameEstado(Parte p);

    void agregarSubpartes(Parte p, subpartes s);

    void eliminarParte(Parte p);


private:
    std::map(Parte, subparte) _porParte;
    bool* _estado;
};

#endif //TP2DISEÑO_PARTE_H

#ifndef TP2DISEÑO_TRANSACCION_H
#define TP2DISEÑO_TRANSACCION_H

#include <vector>
#include <string>
#include "Parte.h"
using namespace std;

class Transaccion{
public:
    //constructor
    Transaccion();

    ~Transaccion();

    /*pre: parte p no tenia estado, tenia estado en NULL, es parte atomica*/
    /*post: le adjudica un estado a la parte p*/
    void registrarEstado(parte p, bool estado);

    /*pre: p se encuentra en estado defectuoso, es parte atomica*/
    /*post: al llamar a esta funcion p va tener un estado correcto */
    void reparar(parte p);

    /*pre: esta parte no esta siendo utilizada por nadie, esta suelta, no es atomica */
    /*post: nos da las subpartes de una parte p, // pensar : p deja de aparecer en el sistema*/
    void desarmar(parte p, vector<parte> subparte);

    /*pre: p no esta siendo utilizada por otro empleado*/
    /*post: le asigna un id a cada subparte de p y cada una de ella quedan afectadas por esta trans*/
    void registrarSubpartes(parte p, vector<parte> subparte);

    bool confirmarTransaccion() const;

    bool cancelarTransaccion() const;



private:
diccPartes(Parte, std::tuple<itCatalogo, stock>) _partePorTrans;


};

#endif //TP2DISEÑO_TRANSACCION_H



#ifndef TP2DISEÑO_SISTEMA_H
#define TP2DISEÑO_SISTEMA_H

#include "Transaccion.h"

class Sistema{
public:
    //crea un sistema vacia de stock, solo con los empleados en un pricipio
    /*pre: true*/
    /*post: crea un sistema con los empleados*/
    Sistema();


    //destructor del sistema
    /*pre: toma un sistema valido*/
    /*post: te deja un sitema sin stock*/
    ~Sistema();

    /*pre: p no pertenece al sistema*/
    /*post: agrega una nueva parte al sistema, especificamente al stock.
     * Se la considera parte suelta al entrar al sistema*/
    void comprar(const parte p);

    /*pre: p pertence al sistema, ya figuraba en el stock, es una parte suelta*/
    /*post: saca una parte del sistema y no se puede modificar mas porque
     * ya no figura en el sistema*/
    void vender(const parte p);

    /*pre: true*/
    /*post: decide si la parte p pertence al sistema*/
    bool pertenece(const parte p)const;


    /*pre: true*/
    /*post: nos devuelve el catalogo no modificable del sistema*/
    const stock catalogo()const ;


private:
//PENSAR

};



#endif //TP2DISEÑO_SISTEMA_H

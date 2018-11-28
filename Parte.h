#ifndef TP2DISEÑO_PARTE_H
#define TP2DISEÑO_PARTE_H
#include <list>
typedef ID string;
typedef Estado bool*;

using namespace std;


class Parte{
public:

    /*pre: true*/
    /*post: asigna un identificador por unica vez a parte*/
    Parte(ID id) : ID(id) {};

    ~Parte();

    /*pre:true*/
    /*post: se asigna un valor para identificar si una parte es atómica*/
    bool esAtomica()const;

    /*pre: p es atómica */
    /*post: devolvemos el estado en el que se encuentra p*/
    bool* dameEstado()const;


    /*pre: si p es atomica s es vacia*/
    /*post: cada elemento de s cuenta con un identificador, s pasa a ser _subparte de p*/
    void agregarSubparte(list<ID> s);


private:
   ID id;
   std::list<ID> _subparte;
   Estado _estado;
   bool _atomica;

   /*INVARIANTE DE REPRESENTACION*/
   /**
    * Los ID elementos de _subparte son distinguibles entre si y ninguno coincide con el ID principal.
    * Si una parte es atómica entoces puede tener _estado true o false.
    * Si una parte es atómica _subparte es vacia.
    * Si una parte no es atómica _estado es NULL.
    * **/


   //--------------------------explicación de la estructura---------------------------//
    /*ID: usamos un tipo T para el identificador que va tener parte, en particular va ser string, asi la usamos
     * como clave dentro de stringMap*/

    /*_subparte: está montada en una lista enlazada que va almacenar las subpartes de parte, elegimos esta
     * estructura asi es menos costoso el borrado y agregar que es lo unico que necesitamos*/

    /*Estado: es un puntero a bool, si una parte no es atómica solamente seteamos NULL para diferenciar,
     * en caso de ser atómica se va ir modificando a lo largo de las transacciones*/

    /*_atomica: es un booleano que usamos para reflejar si una parte es atómica o no*/

};

#endif //TP2DISEÑO_PARTE_H

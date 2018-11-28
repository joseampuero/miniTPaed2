#ifndef TP2DISEÑO_STOCK_H
#define TP2DISEÑO_STOCK_H

#include "Parte.h"
#include <set>
typedef IdStock string;

using namespace std;

template <class T>
class Stock{
public:

    Stock();

    ~Stock();

    /*pre: true*/
    /*post: crea una nueva linea con todos los parametros*/
    void agregarLinea(ID p, list<_ID> s, Estado e);

    Linea verLinea(IdStock i);

    /*pre: p se encuentra en el stk*/
    /*post: la linea donde p es _ID es borrada*/
    void eliminarLinea(ID p);

private:
    struct Linea{
    IdStock _idStock;
    std::list<IdStock> _subparteStock;
    bool* _estadoStock;

    Linea(): _idStock(new T), _subparteStock(new T), _estadoStock(NULL){};
    };

    std::set<Linea*> _stk;

    /*INVARIANTE DE REPRESENTACION*/
    /**
     * Cada _idStock de una linea es diferenciable.
     * Si _idStock tiene estado true/false entonces _subparteStock es vacia
     * **/

    //------------------explicación de la estructura-----------------------//
    /*_stk: elegimos un conjunto lineal de Lineas ya que solo necesitamos listar cada parte con la que contamos
     * dentro del sistema o con la que estamos trabajando y asumimos que cada parte es unica(no hay _ids repetidos)
     * y como std:set tiene la propiedad de que cada elemento del contenedor es único nos parecio una estructura que
     * reflejaba lo que queriamos.
     * Tambien se podia representar con un std::list y pediamos en el IREP que cada elemento sea único.
     * Como solo necesitamos las funciones de insertar y borrar ambas eran buenas opciones.
     * */

    /*Linea: representa un renglon con informacion(id, subpartes, estado) acerca de una parte determinada
     *      IdStock: es el nombre de la parte con la que se identifica en el sistema o transaccion.
     *      _subparteStock: nos da a saber las subpartes de una parte no atómica.
     *      _estadoStock: contamos con esta información para saber en que condiciones se encuentra una parte atómica.
     * */
};

#endif //TP2DISEÑO_STOCK_H

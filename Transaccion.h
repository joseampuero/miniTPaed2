#ifndef TP2DISEÑO_TRANSACCION_H
#define TP2DISEÑO_TRANSACCION_H

#include <tuple>
#include <string>
#include "Stock.h"
#include "StringMap.h"

using namespace std;

class Transaccion{
public:
    ~Transaccion();

    /*pre: parte no esta siendo usada por otro empleado*/
    /*post: buscamos parte en el _catalogo dejamos un puntero a esa linea para reflejar que esta siendo usada,
     * parte pasa a ser clave de _partePorTransaccion,
     * se crea un _areaDeTrabajo para poder realizar las transacciones,
     * al crearse el areaDeTrabajo, parte pasa a ser el _idStock,
     * y los otros espacios (_subparte, _estado) permanecen igual si no han sido modificadas hasta el momento,
     * si no, se copia la informacion donde corresponde*/
    Transaccion(itCatalogo, _ID parte);

    /*pre:parte es atomica y
     * si la condicion anterior es NULL entonces estado puede ser true o false(se encuentra en buenas condiciones o en
     * malas condiciones, respectivamente),
     * si la condicion anterior es false entonces estado puede ser true o false(parte fue reparada o no pudo serlo),
     * si la condicion anterior es true entonces estado tiene que seguir siendo true(no puedo estropiar
     * una parte que ya se encuentra en buenas condiciones)*/
    /*post: le adjudica un estado a parte y  estado pasa a ser el _estadoStock en el _areaDeTrabajo de parte y
     * _estado en Parte*/
    void registrarEstado(_ID parte, bool estado);

    /*pre: si parte es atomica s es vacia*/
    /*post: le asigna un id a cada subparte de parte y cada una de ellas quedan afectadas por esta transaccion
     * agregamos s a _subparteStock de Linea _areaDeTrabajo y tambien a _subparte de Parte */
    void registrarSubpartes(_ID parte, list<_ID> s);

    /*pre: parte no es atomica, _subparte no es vacia y fueron registradas previamente */
    /*post: devolvemos las subpartes de parte: parte deja de tener entidad (ya no puedo
     * realizar transacciones con parte),
     * parte es eliminada de _partePorTransaccion junto a su significado(para cumplir el invariante de stringMap)
     * y cada _ID de _subparte pasan a ser clave de _partePorTransaccion y son nuevas Parte-s, ahora el empleado pasara
     * a tener un nuevo _areaDeTrabajo , o mas, dependiendo la longitud de _subparte, donde podra realizar nuevas
     * transacciones con cada una de ellas si lo desea*/
    void desarmar(_ID parte);

    /*pre:true*/
    /*post:si _confirmar es true entonces:
     * _areaDeTrabajo se copia al catalogo con todas las modificaciones realizadas a la parte con la que estaba
     * trabajando el empleado, en caso de que se haya usado la funcion desarmar la parte con la que estaba trabajando
     * deja de tener entidad en el sistema(la linea donde parte es _ID se borra del catalogo, para eso contamos
     * con el itCatalgo) y se agregan todas las modificaciones realizadas a _catalogo.
     * Si _confirmar es false se sigue trabajando con la parte que corresponda*/


    /*y con mi puntero al map empleadoPorTransaccion una vez que se confirmo borro el nodo dentro de map que contiene
     * la transaccion con la que estoy trabajando*/


    void confirmarTransaccion() const;

    /*pre: true*/
    /*post: si _cancelar es true:
     * todas las modificaciones realizadas a parte que estan en el _areaDeTrabajo no se veran reflejadas en _catalogo
     * si _cancelar es false es porque se sigue trabajando con la parte que corresponda*/


    /*y con mi puntero al map empleadoPorTransaccion una vez que se cancela la transaccion borro el nodo dentro de map
     * que contiene la transaccion con la que estoy trabajando*/

    void cancelarTransaccion() const;

    friend class Stock; // lo uso para tener acceso a la parte privada de Stock y poder modificar
    friend class Parte; // lo uso para tener acceso a la parte privada de Parte y poder modificar

private:

    StringMap(ID clave, std::tuple<Stock* itCatalogo, Stock _areaDeTrabajo>, map*<empleado, Transaccion> itEmpTra>) _partePorTransaccion;


    /*INVARIANTE DE REPRESENTACION*/
    /**
     * No se puede setear en true _confirmar y _cancelar en una misma  funcion de transacción.
     * Cada clave de _partePorTransaccion es unica.
     * Dentro del significado, itCatalogo solo puede apuntar a una única linea del catalogo.
     * No puedo tener dos _areasDeTrabajo iguales
     * **/

    //------------------------explicación de la estructura-----------------------//

    /*_partePorTransaccion: está montado sobre un stringMap asi podremos insertar la clave con la que estamos
     * trabajando durante una transaccion, en un principio podria haber sido cualquier tipo de
     * diccionario(std::map, etc) que se banque strings como clave(esto porque decidimos que _id sea string), ya
     * que al principio un empleado solo trabaja con una parte a la vez, recien al aplicar la funcion desarmar se
     * van agregando nuevas claves al diccionario.
     * Entonces por lo que vimos necesario esta estructura fue por un tema de diseño.
     *      clave: es el identificador de la parte.
     *      itCatalogo: apunta a una única linea del catalogo, esto quiere decir que un empleado esta trabajando con
     * esta parte.
     *      _areaDeTrabajo: en este Stock vamos a ir almacenando todos los cambios que vamos a ir reailizando a
     * lo largo de la transaccion, esto no es visible para el sistema*/

    /*_confrmar: si se setea en true, implica que un empleado ya finalizo su trabajo y su _areaDeTrabajo es pasado
     * por copia al catalago con todas las modificaciones realizadas y se destruye el _areaDeTrabajo y el diccionario
     * _partePorTransaccion*/

    /*_cancelar: si se setea en true, implica que todas las modificaciones a parte que fuimos realizando a
     * lo largo de la transaccion no se veran reflejadas en el catalogo del sistema y se destruye el _areaDeTrabajo
     * y el diccionario _partePorTransaccion */

};

#endif //TP2DISEÑO_TRANSACCION_H

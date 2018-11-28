#ifndef TP2DISEÑO_SISTEMA_H
#define TP2DISEÑO_SISTEMA_H

#include <map>
#include "Transaccion.h"

typedef empleado int;

using namespace std;
class Sistema{
public:
    //crea un sistema vacio de stock, solo con los empleados en un pricipio
    /*pre: true*/
    /*post: crea un sistema con los empleados*/
    Sistema(set<empleado> e);

    //destructor del sistema
    /*pre: toma un sistema valido*/
    /*post: te deja un sitema sin stock*/
    ~Sistema();

    /*pre: p no pertenece al sistema*/
    /*post: agrega una nueva parte al sistema, especificamente al stock,
     * al ingresar no se registra ningun detalle sobre p, solo el _ID
     * Se la considera suelta al entrar al sistema*/
    void comprar(Parte p, ID parte);

    /*pre: parte pertence al sistema, figura en el stock, es suelta y ningun empleado la apunta*/
    /*post: saca una parte del sistema y no se puede modificar mas porque
     * ya no aperece en el sistema, o sea se borra parte del catalogo*/
    void vender(IdStock parte);

    /*pre: true*/
    /*post: decide si parte pertence al sistema, es decir si figura en el catalogo*/
    bool pertenece(IdStock parte)const;

    /*pre: true*/
    /*post: nos devuelve el catalogo no modificable del sistema*/
    const Stock catalogo()const;


    void iniciarTransaccion(empleado e, Parte p, Stock s);

    /*pre: true*/
    /*post: si el empleado que me pasan por parametro aparece en el diccionario _empleadoPorTransaccion
     * retornaremos true
     * ///////////y la linea(en particular el ID) con la que esta trabajando,
     * si no, <false, null> el empleado no esta realizando ninguna transaccion*/
    bool estaOcupado(empleado e)const;


    /*pre: estaOcuapado(e) = True*/
    /*post: me deuvelve la parte con la que está ocupado el empleado e*/

    ID ocupadoCon(empleado e)const;

private:
    std::map<empleado, Transaccion> _empleadoPorTransaccion;
    Stock _catalogo;
    std::set<empleado> _empleados;
    /*INVARIANTE DE REPRESENTACION*/
    /**
     * Cada _idStock de cada linea dentro de _catalogo es unico.
     * Los empleados son distinguibles entre si.
     * No es posible vender una parte que esta siendo afectada por una transaccion, es decir si esta siendo
     * apuntada por itCatalogo.
     * Un empleado puede apuntar con itCatalogo a una unica linea de _catalogo.
     * **/

    //------------------------explicación de la estructura-----------------------//

    /*_empleadoPorTransaccion: esta montado en un diccionario linal que representa la transaccion que está realizando
     * un empleado.
     * Si un empleado aparece en este diccionario siginifica que esta ocupado.
     * Cada funcion de Transaccion está explicado en Transaccion.h .
     * Elegimos un diccionario lineal ya que cuenta con las caracteristicas de clave-valor y cada clave es unica,
     * como empleado.
     * Podriamos haber elegido un diccAVl(aprovechando que las claves son enteros) o
     * un diccTrie(tomando como longitud de la clave log(empleado) ) pero como no teniamos ninguna restricción
     * respecto a la complejidad que debia cumplir que un empleado inicie o termine o verifique si está ocupado con
     * alguna una transaccion elegimos std::map.
     * */

    /*_catalogo: representa el catalogo del sistema, lista todas las partes con las que contamos para ser modificadas
     * u ofrecidas a la venta, tambien brinda informacion acerca de las subpartes de cada parte y en caso de ser
     * parte atómica, su estado. Si una parte está siendo afectada por una transaccion no podra ser vendida.
     * */

    /*empleado: se representa con int, el cual representa su número de legajo
     * */

};



#endif //TP2DISEÑO_SISTEMA_H

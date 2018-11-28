#ifndef TP2DISEÑO_STRINGMAP_H
#define TP2DISEÑO_STRINGMAP_H

#include <string>
#include <vector>

using namespace std;

template<typename T>
class StringMap {
public:
    /*
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();


    /*
    DESTRUCTOR
    **/
    ~string_map();

    /*
    operator[]
    * Acceso o definición de pares clave/valor
    **/

    T &operator[](const string &key);

    /*
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string &key) const;

    /*
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    **/
    const T& at(const string& key) const;

    /*
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    */
    void erase(const string& key);

    /*
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /*
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

private:

    struct Nodo {
        vector<Nodo*> siguientes;
        T* definicion;
        Nodo():siguientes(256, NULL), definicion(NULL){}
    };

    Nodo* raiz;
    int _size;

};

#endif //TP2DISEÑO_STRINGMAP_H

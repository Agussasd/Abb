#include "pila.h"
#include <stdlib.h>
#include <stdbool.h>

/* Definición del struct pila proporcionado por la cátedra*/
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if (pila == NULL) {
        return NULL;
    }
    pila->datos = malloc( 2 * sizeof(void*)); //Pila->datos comienza con una capacidad para 2 elementos
    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }
    pila->cantidad = 0 ;
    pila->capacidad = 2 ;
    return pila;
}

void pila_destruir(pila_t* pila){
	free(pila->datos);
	free(pila);
}

bool redimensionar(pila_t* pila, void* valor){
	if (pila->capacidad == pila->cantidad){ //Si la pila esta llena y quiero apilar, redimensiono
		void** datos_nuevos = realloc(pila->datos, pila->capacidad *2 * sizeof(void*) );
		if (datos_nuevos == NULL){
			return false;
			}
		pila->datos = datos_nuevos;
		pila->capacidad = pila->capacidad * 2;
	}	
	if(pila->capacidad/4 >= pila->cantidad && pila->cantidad >= 2){ //Si desapile y la pila me quedo muy vacia
		void** datos_nuevos = realloc(pila->datos, (pila->capacidad*sizeof(void*))/2);
		if (datos_nuevos == NULL){
			return false;
			}	
		pila->capacidad = pila->capacidad / 2;
		pila->datos = datos_nuevos;
		} 	
	return true; //Salio todo bien, se redimensiono bien o no se tuvo que redimesionar
	}	
bool pila_apilar(pila_t* pila, void* valor){
	if(redimensionar(pila,valor)){; //Hago la tarea de redimensionar si hace falta
		pila->datos[pila->cantidad] = valor; //Apilo el valor en la posicion correspondiente
		pila->cantidad++ ; 
		return true;
	}
	return false;
}

void* pila_desapilar(pila_t* pila){
	if (pila_esta_vacia(pila)){
		return NULL;
	}
	pila->cantidad--  ; //Aca es donde desapilo
	redimensionar(pila, NULL); //Redimensiono la pila si hace falta
	return pila->datos[pila->cantidad];
}

void* pila_ver_tope(const pila_t *pila){
	if (pila_esta_vacia(pila)){
		return NULL;
		}
	return pila->datos[pila->cantidad - 1];
		 
}

bool pila_esta_vacia(const pila_t *pila){
	return pila->cantidad == 0;
}		


	



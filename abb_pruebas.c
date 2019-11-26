#include "testing.h"
#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void abb_vacio_crear_e_iterar(){
	printf("\n PRUEBAS ABB CREAR ARBOL VACIO E ITERARLO\n");
	abb_t* abb = abb_crear(NULL, NULL);
	print_test("Creo arbol vacio", abb);
	print_test("La cantidad de elementos es 0", abb_cantidad(abb) == 0);
	print_test("Obtener clave es NULL", abb_obtener(abb, "ABC") == NULL);
	print_test("Clave pertenece es NULL", abb_pertenece(abb, "ABC") == NULL);
	print_test("Borrar clave devuelve NULL", abb_borrar(abb, "ABC") == NULL);
	abb_iter_t* iter = abb_iter_in_crear(abb);
	print_test("Iterador esta al final", abb_iter_in_al_final(iter) == true);
	print_test("Iterador avanzar es falso", abb_iter_in_avanzar(iter) == false);
	print_test("Iter ver actual es NULL", abb_iter_in_ver_actual(iter) == NULL);
	abb_iter_in_destruir(iter);
	abb_destruir(abb); 
}

void abb_clave_vacia() {
	printf("\n PRUEBAS ABB CLAVE VACÍA \n");
	abb_t* abb = abb_crear(strcmp,NULL);
	char* clave = "";
	char* valor = "";
	print_test("Insertar clave vacia", abb_guardar(abb, clave, valor));
	print_test("La cantidad de elementos es 1", abb_cantidad(abb) == 1);
	print_test("Obtener clave vacia es el valor correcto", abb_obtener(abb, clave) == valor);
	print_test("Abb pertenece clave vacia es true", abb_pertenece(abb, clave));
	print_test("Abb borrar clave vacia es valor correcto", abb_borrar(abb, clave) == valor);
	print_test("La cantidad de elementos es 0", abb_cantidad(abb) == 0);
	abb_destruir(abb);
}

void abb_insertar(){
	printf("\n PRUEBAS ABB INSERTAR ELEMENTOS \n");
	abb_t* abb = abb_crear(strcmp, NULL);
	char* clave = "hola";
	char* valor = "chau";
	char* clave2 = "sol";
	char* valor2 = "luna";
	char* clave3 = "oro";
	char* valor3 = "gold";
	print_test("Inserto la primera clave", abb_guardar(abb, clave, valor));
	print_test("La cantidad de elementos es 1", abb_cantidad(abb) == 1);
	print_test("Obtener clave es el valor correcto", abb_obtener(abb, clave) == valor);
	print_test("Clave pertenece es truue", abb_pertenece(abb, clave));
	print_test("Abb borrar clave, devuelve valor correcto", abb_borrar(abb, clave) == valor);
	print_test("La cantidad de elementos es 0", abb_cantidad(abb) == 0);
	print_test("Inserto la primera clave nuevamente", abb_guardar(abb, clave, valor));
	print_test("Inserto la segunda clave", abb_guardar(abb, clave2, valor2));
	print_test("Inserto la tercera clave", abb_guardar(abb, clave3, valor3));
	print_test("La cantidad de elementos es 3", abb_cantidad(abb) == 3);
	abb_destruir(abb);
}

void abb_reemplazar(){
	printf("\n PRUEBAS ABB REEMPLAZAR \n");
	abb_t* abb = abb_crear(strcmp, NULL);
	int uno = 1, dos = 2, tres = 3;
	char* clave = "clave", clave2 = "clave2";
	print_test("Guardo clave con valor 1" , abb_guardar(arbol, clave, &uno));
	print_test("Guardo clave con valor 2", abb_guardar(arbol, clave2, &dos));
	print_test("Obtener clave debe ser 2", abb_obtener(arbol,clave2) == &dos);
	print_test("Clave pertenece es true",abb_pertenece(arbol,clave) == true);
	print_test("Clave2 pertenece es true",abb_pertenece(arbol, clave2) == true);
	abb_destruir(abb);
}

void abb_iterador_externo(){
	printf("\n PRUEBAS DE ITERADOR EXTERNO \n");
	abb_t* arbol = abb_crear(strcmp,NULL);
	abb_iter_t* iter = abb_iter_in_crear(arbol);
	print_test("Creo iterador", iter != NULL);
	char* clave = "a";
	char* clave2 = "b";
	char* clave3 = "c";
	char* clave4 = "d"; 
	char* clave5 = "e";
	char* dato = "asd";
	print_test("Guardo clave", abb_guardar(arbol, clave, dato));	
	print_test("Guardo clave2", abb_guardar(arbol, clave2, dato));	
	print_test("Guardo clave3", abb_guardar(arbol, clave3, dato));	
	print_test("Guardo clave4", abb_guardar(arbol, clave4, dato));	
	print_test("Guardo clave5", abb_guardar(arbol, clave5, dato));	

	print_test("Ver actual es a", strcmp("a", abb_iter_in_ver_actual(iter)) == 0);
	print_test("Avanzar es true", abb_iter_in_avanzar(iter) == true);
	print_test("Iter esta al final es false ", abb_iter_in_al_final(iter) == false);
	print_test("Ver actual es b: ",strcmp("b", abb_iter_in_ver_actual(iter)) == 0);
	print_test("Avanzar es true", abb_iter_in_avanzar(iter) == true);
	print_test("Ver actual es c: ",strcmp("c", abb_iter_in_ver_actual(iter)) == 0);
	print_test("Avanzar es true", abb_iter_in_avanzar(iter) == true);
	print_test("Ver actual es d",strcmp("d", abb_iter_in_ver_actual(iter)) == 0);
	print_test("Avanzar es true", abb_iter_in_avanzar(iter) == true);
	print_test("Ver actual es e",strcmp("e", abb_iter_in_ver_actual(iter)) == 0);
	print_test("Avanzar es true", abb_iter_in_avanzar(iter) == true);
	print_test("Iter esta al final es true", abb_iter_in_al_final(iter) == true);
	print_test("Avanzar otra vez es falso", abb_iter_in_avanzar(iter) ==f alse);
	abb_iter_in_destruir(iter);
	abb_destruir(arbol);
}

void pruebas_abb_alumno(){
	abb_vacio_crear_e_iterar();
	abb_insertar();
	abb_clave_vacia();
	abb_reemplazar();
	abb_iterador_externo();
}

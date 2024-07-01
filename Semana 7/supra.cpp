#include <iostream>
using namespace std;

int comandos=0;
int accion=0;
//Creamos la estructura de los elementos
struct elementos{
    int dato;
    elementos *siguiente;

    elementos(){
        dato = 0;
        siguiente = NULL;
    }
};
//Creamos la estructura de la lista
struct lista{
    elementos *inicio;

    lista(){
        inicio = NULL;
    }
    //Funcion para insertar al primero
    void insertar_primero(int dato){
        elementos *nuevo_elemento = new elementos();
        nuevo_elemento->dato = dato;
        if(inicio == NULL){
            inicio = nuevo_elemento;
        }
        else{
            nuevo_elemento->siguiente=inicio;
            inicio= nuevo_elemento;
           
        }
    }
    //Funcion para mostrar el primer elemento
    void mostrar_primero(){
        if(inicio == NULL){
            cout << "Empty!" << "\n" ;
        }
        else{
            cout << inicio->dato << "\n" ;
        }
    }
    //Funcion para eliminar el primer elemento
    void eliminar_primero(){
        if(inicio == NULL){
            return;
        }
        else{
            elementos *aux = inicio;
            inicio = inicio->siguiente;
            delete aux;
        }
    }
};


int main(){
    //Optimizacion de cin y cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    lista l;
    cin >> comandos;
    //Ciclo para leer los comandos
    for(int i=0; i<comandos; i++){
        cin >> accion;
        if(accion == 1){
            int dato;
            cin >> dato;
            l.insertar_primero(dato);
        }
        else if(accion == 2){
            l.eliminar_primero();
        }
        else if(accion == 3){
            l.mostrar_primero();
        }
    }
}
#include <iostream>
using namespace std;

//Estructura de cada uno de los nodos del arbol. 
struct nodo{
    int dato;
    int color;
    int posicion;
    nodo *padre;
    nodo *izquierdo;
    nodo *derecho;
    
    nodo(){
        dato=-1;
        //El color se escoje de forma binaria. Rojo=0, Negro=1
        color=1;
        posicion=-1;
        padre=NULL;
        izquierdo=NULL;
        derecho=NULL;
    }
};

//Estructura del arbol Rojo Negro. Basada en la implemetación del Introducction to Algorithms(El Cormen)
//Su caracteriztica principal es usar un unico nodo "nulo" como sustituto de un apuntador vacio
//
struct arbol
{
    nodo *raiz;
    nodo *nulo;
    arbol(){
        nulo=new nodo;
        raiz=nulo;
    }
    //Funcion que realiza la rotación a la izquierda
    void rotacion_izquierda(nodo *x){
        nodo *y= x->derecho;
        x->derecho=y->izquierdo;
        if(y->izquierdo!=nulo){
            y->izquierdo->padre=x;
        }
        y->padre=x->padre;
        if(x->padre==nulo){
            raiz=y;
        }
        else if (x==x->padre->izquierdo)
        {
            x->padre->izquierdo=y;
        }
        else{
            x->padre->derecho=y;
        }
        y->izquierdo=x;
        x->padre=y;

    }
    //Función que realiza la rotación a la derecha
    void rotacion_derecha(nodo*x){
        nodo*y=x->izquierdo;
        x->izquierdo=y->derecho;
        if(y->derecho!=nulo){
            y->derecho->padre=x;
        }
        y->padre=x->padre;
        if (x->padre==nulo)
        {
            raiz=y;
        }
        else if (x->padre->derecho==x)
        {
            x->padre->derecho=y;
        }
        else{
            x->padre->izquierdo=y;
        }
        y->derecho=x;
        x->padre=y;
        
    }
    //Funcion que se encarga de mantener el arbol rojo negro con las propiedades obligatorias
    void mantener_propiedad(nodo*z){
        while(z->padre->color==0){
            if (z->padre==z->padre->padre->izquierdo){
                nodo* y=z->padre->padre->derecho;
                if(y->color==0){
                    z->padre->color=1;
                    y->color=1;
                    z->padre->padre->color=0;
                    z=z->padre->padre;
                }
                else{
                    if(z==z->padre->derecho){
                        z=z->padre;
                        rotacion_izquierda(z);
                    }
                    z->padre->color=1;
                    z->padre->padre->color=0;
                    rotacion_derecha(z->padre->padre);
                }
            }
            else{
                nodo* y=z->padre->padre->izquierdo;
                if(y->color==0){
                    z->padre->color=1;
                    y->color=1;
                    z->padre->padre->color=0;
                    z=z->padre->padre;
                }
                else{
                    if(z==z->padre->izquierdo){
                        z=z->padre;
                        rotacion_derecha(z);
                    }
                    z->padre->color=1;
                    z->padre->padre->color=0;
                    rotacion_izquierda(z->padre->padre);
                }
            }
        }
        raiz->color=1;
    }

    //Función que inserta elementos en el arbol
    void insertar_elemento(int u,int v){
        nodo*z=new nodo;
        z->dato=u;
        z->posicion=v;
        
        nodo*x=raiz;
        nodo*y=nulo;
        
        while(x!=nulo){
            y=x;
            if(z->dato < x->dato){
                x=x->izquierdo;
            }
            else{
                x=x->derecho;
            }
        }
        z->padre=y;
        if (y==nulo)
        {
            raiz=z;
        }
        else if (z->dato < y->dato)
        {
            y->izquierdo=z;
        }
        else{
            y->derecho=z;
        }
        z->derecho=nulo;
        z->izquierdo=nulo;
        z->color=0;
        mantener_propiedad(z);
    }

    //Función que se desplaza por el arbol para encontrar un elemento buscado
    void buscar_elemento(int k){
        nodo*temporal=raiz;
        while(temporal!=nulo){
            if(k<temporal->dato){
                temporal=temporal->izquierdo;
            }
            else if(k>temporal->dato){
                temporal=temporal->derecho;
            }
            else{
                cout << temporal->posicion<<"\n";
                return;               
            }
        }
        cout << -1<<"\n";

    }

    
};

int main(){
    //Optimizaciones necesarias
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Declaración de variables
    arbol a;
    int N;
    int Q;
    int comandos;
    int queries;
    int anterior_comando=1000000001;
    cin >>N;
    cin >>Q;
    //Se escoje no insertar los elementos repetidos para evitar complicaciones en el arbol
    for (int i=0; i<N; i++){
        cin >> comandos;
        if(comandos!=anterior_comando){
            a.insertar_elemento(comandos, i);
            anterior_comando=comandos;
        }
    }
    for (int i=0; i<Q; i++){
        cin >>queries;
        a.buscar_elemento(queries);
    }
    
}
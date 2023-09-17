
#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo*izquierda;
    Nodo*derecha;
};

Nodo*arbol=NULL;

//Prototipos
Nodo*crearNodo(int);
void insertarNodo(Nodo*&,int);
void Menu();

int main()
{
    Menu();
    return 0;
};

//Funcion para crear un noto
Nodo*crearNodo(int n){
    Nodo * new_nodo = new Nodo();
    
    new_nodo->dato=n;
    new_nodo->izquierda=NULL;
    new_nodo->derecha=NULL; 

    return new_nodo; //Devolver el nodo con los valores
};

void insertarNodo(Nodo*&arbol,int n){
    if(arbol==NULL){
        Nodo*new_nodo=crearNodo(n);
        arbol=new_nodo;
    }
    else{
        int Raiz=arbol->dato;//insertar la raiz del arbol
        if(n<Raiz){
            insertarNodo(arbol->izquierda,n);//insertar valores menores
        }
        else{
            insertarNodo(arbol->derecha,n);//insertar valores mayores
        }
    }
}

void Menu(){
    int opcion;
    do{
        std::cout << "MENU" << std::endl;
        std::cout << "1)insertar" << std::endl;
        std::cout << "2)Salir" << std::endl;
        cin>>opcion;
        
        if(opcion==1){
            std::cout << "Ingrese el Nodo que desea ingresar: " << std::endl;
            int dato;
            cin>>dato;
            insertarNodo(arbol,dato);
        }
        
    }while(opcion!=2);
}
 
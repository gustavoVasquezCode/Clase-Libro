#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>

using namespace std;

class Libro{
    private:
        string titulo;
        string autor;
        int cantidad;
        int prestados;
    public:
        Libro();
        void ingresarDatos();
        void prestarLibro();
        void mostrarLibro();
        void mostrarLibroActual();
        void setTitulo(string);
        void setAutor(string);
        void setCantidad(int);
        void setPrestados(int);
        string getTitulo();
        string getAutor();
        int getCantidad();
        int getPrestados();
};

Libro::Libro(){
    titulo = " ";
    autor = " ";
    cantidad = 0;
}

void Libro::ingresarDatos(){
    fflush(stdin);
    cout << "\nIngrese el titulo: ";
    getline(cin, titulo);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese la cantidad disponibles: ";
    cin >> cantidad;
}

void Libro::prestarLibro(){
    cout << "\nIngrese la cantidad a prestar: ";
    cin >> prestados;
    if(cantidad > 0)
        cantidad = cantidad - prestados;
    else
        cout << "\nEl libro seleccionado esta agotado" << endl;
}

void Libro::mostrarLibro(){
    cout << "\nTitulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Cantidad: " << cantidad << endl;
}

void Libro::mostrarLibroActual(){
    cout << "\nTitulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Cantidad actual: " << cantidad << endl;
    cout << "Prestados: " << prestados << endl;
}

void Libro::setTitulo(string _titulo){
    titulo = _titulo;
}

void Libro::setAutor(string _autor){
    autor = _autor;
}

void Libro::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

void Libro::setPrestados(int _prestados){
    prestados = _prestados;
}

string Libro::getTitulo(){ return titulo; }

string Libro::getAutor(){ return autor; }

int Libro::getCantidad(){ return cantidad; }

int Libro::getPrestados(){ return prestados; }

int main(){
    int i, pocision=0, opc=0;
    bool bandera = true;

    Libro *libros = new Libro[5];
    
    cout << "********** Ingresar datos de libros **********" << endl;
    for(i=0; i<5; i++){
        libros[i].ingresarDatos();
    }

    cout << "\n********** Prestamo **********" << endl;
    while(bandera){
        cout << "\nSeleccione una opcion: \n1.Mostrar informacion \n2.Prestar libro \n3.Mostrar Actualizacion \n4.Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;

        if(opc == 1){
            for(i=0; i<5; ++i){
                cout << "\n********** Libro " << i << " **********" << endl;
                libros[i].mostrarLibro();
            }
        }
        else if(opc == 2){
            cout << "\nIngrese el numero del libro a prestar: ";
            cin >> pocision;
            for(i=0; i<5; i++){
                if(pocision == i){
                    libros[i].prestarLibro();
                }
            }
        }
        else if(opc == 3){
            for(i=0; i<5; i++){
                    libros[i].mostrarLibroActual();
            }
        }
        else if(opc == 4)
            bandera = false;
        else
            cout << "\nError, la opcion no existe" << endl;
    }

    system("pause");
    return 0;
}

// Programa que se detiene cuando se ingresa el número 42. Si no, imprime el número ingresado
#include <iostream>
using namespace std;

int main() {
    int x =0;
    while(true){
        cin >> x;
        if(x == 42){
            break;
        }
        cout << x << endl;
    }
    return 0;
}
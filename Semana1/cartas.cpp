#include <iostream>
#include <vector>
using namespace std;

int main() {
    int contador=0;
    int casos=0;
    int n=0;
    int k=0;
    bool repetido=false;
    vector<int> cartas;
    cin >> casos;
    for (int i=0; i<casos; i++){
        cin >> n;
        cin >> k;
        cartas.resize(n);
        for(int i=0; i<n; i++){
            cin >> cartas[i];
        }
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if(cartas[i]==cartas[j]){
                    contador++;
                }
            }
            if(contador==k || contador > k){
                cout << k-1 << endl;
                contador=0;
                repetido=true;
                break;          
            }
            contador=0;
        }
        if(repetido==false){
            cout << n << endl;
        }
        repetido=false;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

//Variables
int casos=0;
int n=0;
vector <int> arreglo;

int main(){
    //Llenamos el arreglo con el input
    cin >> casos;
    for(int i=0; i<casos;i++){
        cin >>n;
        arreglo.resize(n);
        for(int j=0; j<n;j++){
            cin>>arreglo[j];            
        }
    //Aplicamos Bubble Sort
    for(int k=0; k<n-1;k++){
        for(int l=0; l<n-k-1;l++){
            if(arreglo[l]>arreglo[l+1]){
                swap(arreglo[l],arreglo[l+1]);
            }
        }
    }
    //Calculamos la "belleza" del arreglo
    int belleza=arreglo[n-1]-arreglo[0];
    cout << belleza << " ";
    }
}

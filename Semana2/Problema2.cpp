#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Variables
int cont=0;
int c=0;
int n=0;
int tmp=0;
vector <int> arreglo;
vector <pair<int,int>> VectorR;
//Respuesta
int main(){
        //Llenamos el arreglo con el input
        cin >> n;
        cin >> c;
        arreglo.resize(n);
        for(int i=0; i<n;i++){
            cin>>arreglo[i];            
        }

        //Llenamos otro arreglo con información de los números repetidos
        for (int k=0; k<n;k++){
            tmp=arreglo[k];
            for(int l=k; l<n;l++){
                if(tmp==-1){
                    cont=0;
                    break;
                }
                if(tmp==arreglo[l]){
                    cont++;
                    arreglo[l]=-1;
                }
            }
            if(tmp!=-1){
                VectorR.push_back({tmp,cont});
                cont=0;
            }        
        }
        //Aplicamos Bubble Sort en el nuevo arreglo
        for(int m=0; m<VectorR.size()-1;m++){
            for(int n=0; n<VectorR.size()-m-1;n++){
                if(VectorR[n].second<VectorR[n+1].second){
                    swap(VectorR[n],VectorR[n+1]);
                }
            }
        }
        //Imprimos los resultados
        for(int o=0; o<VectorR.size();o++){
            for (int p=0; p<VectorR[o].second;p++){
                cout << VectorR[o].first<< " ";
            }
        }
}
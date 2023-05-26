#include <bits/stdc++.h>
using namespace std;

void prinvetor(vector<int>v, int ini, int tam){
    cout<<" [";
    for(int i=ini; i<tam; i++){
        cout<< v[i];
        if(i != tam-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void troca(vector<int>& v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

vector<int> countingSort(vector<int>& v, int tamV){
    //passo 1: descobrir maior e menor
    int menor = v[0];
    int maior = v[0];
    for(int i=0; i<tamV; i++){
        if(v[i]<menor){
            menor = v[i];
        }
        if(v[i]>maior){
            maior = v[i];
        }
    }
    //passo 2: criar vetor de contagem
    vector<int> contagem(maior - menor + 1, 0);
    //passo 3: contar ocorrencias de cada elemento em v
    for(int i=0; i<tamV; i++){
        contagem[v[i]-menor]++;
    }
    //passo 4: realizar soma cumulativa
    for(int i=1; i<contagem.size();i++){
        contagem[i]+=contagem[i-1];
    }
    //passo 5: criar novo vetor para armazenar os valores ordenados
    vector<int> ordenado(tamV);
    //passo 6: mapear os elementos do vetor desordenado p/ ordenado utilizando o vetor de contagem
    vector<bool> ocupado(tamV, false);
    for(int i=0; i<tamV; i++){
        //[10,8,3]
        //----------0 1 2 3 4 5 6 7
        //contagem [1,0,0,0,0,1,0,1]
        //contagem [1,1,1,1,1,2,2,3] soma cumulativa
        // ordenado[contagem[v[i]-menor]-1] = v[i];
        //----------0 1 2
        //ordenado [3,8,10]
        int indiceOrdenado = contagem[v[i]-menor]-1;
        while(ocupado[indiceOrdenado]){
            indiceOrdenado--;
        }
        ordenado[indiceOrdenado] = v[i];
        ocupado[indiceOrdenado] = true;
    }

    return ordenado;
}


int main() {
    
    // vector <int> vetor {0,5,1,4,3,9,8};
    vector <int> vetor {0,5,1,4,3,9,8,1,1};
    // vector <int> vetor {1,2,3,4,5,6,7};
    // vector <int> vetor {6,5,4,3,2,1,0};
    cout<<"array desordenado:";
    prinvetor(vetor, 0, vetor.size());
    vector <int> vetor_ordenado(vetor.size());
    vetor_ordenado = countingSort(vetor, vetor.size());
    cout<<"array ordenado:";
    prinvetor(vetor_ordenado, 0, vetor_ordenado.size());

	return 0;
}
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

int particiona(vector<int>& v, int ini, int fim){
    int indexPivo = ini;


    //pivô sem randomização ----------------------
    // int pivo = v[fim];
    //--------------------------------------------

    // pivô com ramdomização----------------------
    //TODO
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(ini, fim);
    int random = distribution(generator);
    troca(v, random, fim);
    prinvetor(v, 0, 7);
    int pivo = v[fim];
    //--------------------------------------------

    for(int i=ini; i<fim;i++){
        if(v[i] <= pivo){
            troca(v, i, indexPivo);
            indexPivo++;
        }
    }
    prinvetor(v, 0, 7);
    return indexPivo;
}

void quickSort(vector<int>& v, int ini, int fim){
    if(fim > ini){ //condição de continuidade
        int indexPivo = particiona(v, ini, fim);
        cout<<"indexPivo "<< indexPivo<<endl;
        quickSort(v, ini, indexPivo-1); //lado esquerdo do pivo
        quickSort(v, indexPivo+1, fim); //lado direito do pivo
    }
}


int main() {
    
    // vector <int> vetor {0,5,1,4,3,9,8};
    vector <int> vetor {1,2,3,4,5,6,7};
    // vector <int> vetor {6,5,4,3,2,1,0};
    cout<<"array desordenado:";
    prinvetor(vetor, 0, vetor.size());
    quickSort(vetor, 0, vetor.size()-1);
    cout<<"array ordenado:";
    prinvetor(vetor, 0, vetor.size());

	return 0;
}
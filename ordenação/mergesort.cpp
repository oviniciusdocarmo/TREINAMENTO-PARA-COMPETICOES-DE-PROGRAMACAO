#include <bits/stdc++.h>
using namespace std;

void prinvetor(vector<int>v, int tam){
    cout<<" [";
    for(int i=0; i<v.size(); i++){
        cout<< v[i];
        if(i != v.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void Merge(vector<int>& v, int tamV, vector<int>& e, int tamE, vector<int>& d, int tamD){
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;
    //comparando os index dos vetores 'e' e 'd'
    while(indexE<tamE && indexD<tamD){
        if(e[indexE]<=d[indexD]){
            v[indexV] = e[indexE];
            indexE++;
        }else{
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    //copiando os elementos restantes do vetor 'e' caso tenha sobrado elementos
    while(indexE<tamE){
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    //copiando os elementos restantes do vetor 'd' caso tenha sobrado elementos
    while(indexD<tamD){
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void MergeSort(vector<int>& v, int tamV){
    if(tamV>1){
        int meio = tamV/2;
        //copiando valores de v para v1
        int tamV1 = meio;
        vector<int> v1(tamV1);
        for(int i=0; i<tamV1; i++){
            v1[i] = v[i];
        }
        //copiando valores de v para v2
        int tamV2 = tamV - meio;
        vector<int> v2(tamV2);
        for(int i=meio; i<tamV; i++){
            v2[i-meio] = v[i]; // i-meio pois iremos adicionar começando da peimeira posição de v2
        }
        //repetindo o processo para os subvetores
        MergeSort(v1, tamV1);
        MergeSort(v2, tamV2);
        Merge(v, tamV, v1, tamV1, v2, tamV2);

    }
}


int main() {

    vector <int> vetor {0,5,1,4,3,9,8};
    cout<<"array desordenado:";
    prinvetor(vetor, vetor.size());
    MergeSort(vetor, vetor.size());
    cout<<"array ordenado:";
    prinvetor(vetor, vetor.size());

	return 0;
}
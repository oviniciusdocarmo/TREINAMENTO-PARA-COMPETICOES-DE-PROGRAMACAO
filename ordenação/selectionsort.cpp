#include <bits/stdc++.h>
using namespace std;

vector<int> SelectionSortOP(vector<int>& v, int tamanho){
    vector <int> ordenado(tamanho);
    for(int i=0; i<tamanho; i++){
        int iMenor = 0;
        for(int j=0; j<tamanho; j++){
            if(v[j] < v[iMenor]){
                iMenor = j;
            }
        }
        ordenado[i] = v[iMenor];
        v[iMenor] = INT_MAX;
    }
    return ordenado;
}
void SelectionSortIP(vector<int>& v, int tamanho){
    for(int i=0;i<(tamanho-1); i++){
        int iMenor = i;
        for(int j=i+1; j<tamanho; j++){
            if(v[j] < v[iMenor]){
                iMenor = j;
            }
        }
        int aux = v[i];
        v[i] = v[iMenor];
        v[iMenor] = aux;
    }
}

int main() {
    vector <int> vetor {0,5,1,4,3,9,8};
    vector <int> vetor_ordenado(7);
    
    
    cout<<"---------Out-of-Place----------"<<endl;
    cout<<"array desordenado: [";
    for(int i=0; i<vetor.size(); i++){
        cout<< vetor[i];
        if(i != vetor.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    vetor_ordenado = SelectionSortOP(vetor, vetor.size());
    cout<<"array ordenado: [";
    for(int i=0; i<vetor_ordenado.size(); i++){
        cout<< vetor_ordenado[i];
        if(i != vetor_ordenado.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    cout<<"---------In-Place-------------"<<endl;
    vector <int> vetor_ip {0,5,1,4,3,9,8};
    cout<<"array desordenado: [";
    for(int i=0; i<vetor_ip.size(); i++){
        cout<< vetor_ip[i];
        if(i != vetor_ip.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    SelectionSortIP(vetor_ip, vetor_ip.size());
    cout<<"array ordenado: [";
    for(int i=0; i<vetor_ip.size(); i++){
        cout<< vetor_ip[i];
        if(i != vetor_ip.size()-1){
            cout<<", ";
        }
    }
    cout<<"]";
	return 0;
}
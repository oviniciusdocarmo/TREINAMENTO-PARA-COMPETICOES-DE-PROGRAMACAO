#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>& v, int tamanho){
    for(int varredura=0;varredura<(tamanho-1); varredura++){
        bool trocou = false;
        for(int i=0; i<(tamanho-varredura-1); i++){
            if(v[i] > v[i+1]){
                int temp=v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = true;
            }
        }
        if(trocou == false){
            return;
        }
    }
}

int main() {

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
    BubbleSort(vetor_ip, vetor_ip.size());
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
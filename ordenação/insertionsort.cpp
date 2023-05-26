#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>& v, int tamanho){
    for(int i=1;i<tamanho; i++){
        for(int j=i; j>0 && v[j-1] > v[j]; j--){
            int temp = v[j-1];
            v[j-1] = v[j];
            v[j] = temp;
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
    InsertionSort(vetor_ip, vetor_ip.size());
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
#include <bits/stdc++.h>

using namespace std;

//OBSERVAÇÃO: todas as questões devem ser resolvidas com recursão, sem utilizar nenhum for/while

//retorna a soma dos elementos entre os índices a e b do vetor v
//por exemplo, sendo v = {4, 5, 2, 1, 3}, somaElementos(v, 0, 2) deve retornar 11
int somaElementos(vector<int> v, int a, int b) {
	if(a == b){
		return v[b];
	}else{
		return v[a] + somaElementos(v, a+1, b);
	}
}


//retorna se a substring s entre os índices a e b é um palíndromo
//por exemplo, ehPalindromo("fbabg", 1, 3) deve retornar true pois a substring "bab" é um palíndromo
bool ehPalindromo(string s, int a, int b) {
	if(a == b || a+1 == b){
		return true;
	}else{
		if(s[a]==s[b]){
			return ehPalindromo(s, a+1, b-1);
		}else{
			return false;
		}
	}
}

//retorna a quantidade de elementos gerados a partir de n seguindo as regras do problema 3n+1
//por exemplo, qtdElementos3n1(5) deve retornar 6, pois a sequência gerada (5 16 8 4 2 1) possui 6 elementos
int qtdElementos3n1(int n) {
	if(n == 1){
		return 1;
	}else{
		if(n%2==0){
			return 1 + qtdElementos3n1(n/2);
		}else{
			return 1 + qtdElementos3n1(3*n + 1);
		}
	}
}

//retorna a soma dos dígitos de um número n. O número pode ser negativo.
int somaDigitos(int n) {
  if (n < 0) {
    n = -n; // Transforma n em positivo
  }
  if (n < 10) {
    return n; // Caso base, retorna o próprio n se ele tiver apenas um dígito
  }
  return somaDigitos(n/10) + n%10; // Chama a função recursivamente para o número sem o último dígito e soma com o último dígito
}

//retorna a string palindromo k(k-1)(k-2)...a...(k-2)(k-1)k, onde k é um caractere, k-1 é o caractere anterior, etc
//por exemplo, gerarPalindromo('d') deve retornar dcbabcd
//gerarPalindromo('e') deve retornar edcbabcde
//lembre-se de que você pode concatenar strings com o operador +
string gerarPalindromo(char k) {
	char a = 'a';
	if(k == a){
		return "a";
	}else{
		if(k<='z'){
			return  k + gerarPalindromo(k-1) + k;
		}
	}
}

//retorna o resultado da exponenciação base^expoente
//considere que o expoente é sempre positivo
//por exemplo, potencia(2, 3) deve retornar 8
int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else {
        return base * potencia(base, expoente - 1);
    }
}

//retorna se é possível compor (sem resto) n reais com x notas de a reais e y notas de b reais
//por exemplo, saquePossivel(10, 1, 5, 1, 10) retorna true, pois dá para compor 10 reais com 1 nota de 10 reais
//saquePossivel(13, 4, 1, 3, 5) retorna true, pois dá para compor 13 reais com 3 notas de 1 real e 2 notas de 5 reais
//saquePossivel(13, 2, 1, 3, 5) retorna false, pois não dá para compor 13 reais tendo 2 notas disponíveis de 1 e 3 notas disponíveis de 5
bool saquePossivel(int n, int x, int a, int y, int b) {
  // Caso base: se n chegou a zero, é possível compor o saque
  if (n == 0) {
    return true;
  }

  // Caso base: se as notas acabaram e n ainda não chegou a zero, não é possível compor o saque
  if (x == 0 && y == 0) {
    return false;
  }

  // Caso geral: verifica se é possível compor o saque com a nota a ou b
  if (x > 0 && n >= a && saquePossivel(n-a, x-1, a, y, b)) {
    return true;
  }
  if (y > 0 && n >= b && saquePossivel(n-b, x, a, y-1, b)) {
    return true;
  }

  // Se não é possível compor o saque com a nota a ou b, retorna false
  return false;
}

int main() {

	vector<int> v = {4, 5, 2, 1, 3};
	cout << "somaElementos" << endl;
	cout << somaElementos(v, 0, 2) << endl;
	cout << somaElementos(v, 2, 4) << endl;

	cout << "ehPalindromo" << endl;
	cout << ehPalindromo("fbabg", 1, 3) << endl;
	cout << ehPalindromo("fbabg", 0, 4) << endl;
	cout << ehPalindromo("arara", 0, 4) << endl;
	cout << ehPalindromo("araara", 0, 5) << endl;

	cout << "qtdElementos3n1" << endl;
	cout << qtdElementos3n1(5) << endl;
	cout << qtdElementos3n1(6) << endl;

	cout << "somaDigitos" << endl;
	cout << somaDigitos(810027) << endl;
	cout << somaDigitos(-1823) << endl;

	cout << "gerarPalindromo" << endl;
	cout << gerarPalindromo('z') << endl;
	cout << ehPalindromo(gerarPalindromo('f'), 0, 4) << endl;

	cout << "potencia" << endl;
	cout << potencia(2, 3) << endl;
	cout << potencia(3, 3) << endl;

	cout << "saquePossivel" << endl;
	//saquePossivel(int n, int x, int a, int y, int b)
	cout << saquePossivel(10, 1, 5, 1, 10) << endl; //(compor 10 reais, 1 nota de 5 reais, 1 nota de 10 reais)
	cout << saquePossivel(13, 4, 1, 3, 5) << endl; //(compor 13 reais, 4 notas de 1 real, 3 notas de 5 reais)
	cout << saquePossivel(13, 2, 1, 3, 5) << endl; //(compor 13 reais, 2 notas de 1 real, 3 notas de 5 reais)

	return 0;

}

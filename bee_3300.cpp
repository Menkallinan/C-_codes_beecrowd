/*Um número é de má sorte se contém um 1 seguido por um 3 entre seus dígitos. Por exemplo, o número 341329 é de má sorte, enquanto o número 26771 não é.

Dado um inteiro N, seu programa terá que determinar se N é azarado ou não.

Entrada
A entrada consiste em um número positivo N (0 <= N <= 10^100).

Saída
Imprima a mensagem "N es de Mala Suerte" se N é de má sorte, caso contrário imprima "N NO es de Mala Suerte".*/

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;


int main() {

    vector<char>vetor;
    string palavra;
    int esmalo = 0;
    getline(cin, palavra);
    string::iterator caracter_inicial;
    caracter_inicial = palavra.begin();
    for(caracter_inicial; caracter_inicial !=palavra.end(); caracter_inicial++){

        vetor.push_back(*caracter_inicial);
    }
    for(int i =0 ;i<vetor.size();i++){
        if(vetor[i]=='1' and vetor[i+1]=='3')
            esmalo++;
        cout<<vetor[i];
    }

    if(esmalo ==0)
        cout<<" NO es de Mala Suerte"<<endl;
    else
        cout<<" es de Mala Suerte"<<endl;



    return 0;
}

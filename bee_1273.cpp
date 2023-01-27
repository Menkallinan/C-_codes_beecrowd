/*Nós temos algumas palavras e queremos justificá-las à direita, ou seja, alinhar todas elas à direita. Crie um programa que, após ler várias palavras, reimprima estas palavras com suas linhas justificadas à direita.

Entrada
A entrada contém diversos casos de testes. A primeira linha de cada caso de teste conterá um inteiro N (1 ≤ N ≤ 50), que indicará o número de palavras que virão a seguir. Cada uma das N palavras contém no mínimo uma letra e no máximo 50 letras maiúsculas (‘A’-‘Z’). O fim da entrada é indicado por N = 0.

Saída
Para cada caso de teste imprima as palavras inserindo tantos espaços quanto forem necessários à esquerda de cada palavra, para que elas apareçam todas alinhadas à direita e na mesma ordem da entrada. Deixe uma linha em branco entre os casos de teste. Não deixe espaços sobrando no final de cada linha nem imprima espaços desnecessários à esquerda, de modo que pelo menos uma das linhas impressa em cada texto inicie com uma letra.*/

#include <iostream>
#include <set>
#include <vector>
#include <string>


using namespace std;
int tamanho_String(string palavra);

int main() {

    int valor;
    int tamanho;
    int maior;
    int u = 0;
    vector<string>vetor;
    vector<int>tamanho_vezes;
    cin>>valor;

    while(valor!= 0){
        vector<string>palavras;
        vector<int>quantidade;
        tamanho_vezes.push_back(valor);
        for(int i = 0; i < valor;i++){
            string palavra;
            cin>>palavra;
            palavras.push_back(palavra);
            tamanho = tamanho_String(palavra);
            quantidade.push_back(tamanho);
            if(i == 0){
                maior = tamanho;
            }
            if(tamanho>maior){
                maior = tamanho;
            }
        }
        for(int i = 0; i <valor;i++){
            string palavra;
            int valor_absoluto;
            valor_absoluto = maior - quantidade[i];
            if(valor_absoluto== 0){
                vetor.push_back(palavras[i]);

            }
            if(valor_absoluto > 0){
                int j;
                for(j = 0; j<valor_absoluto;j++){
                    palavras[i] = " "+palavras[i];
                }
               vetor.push_back(palavras[i]);
            }
        }
        u++;
        cin>>valor;
    }
    int i = 0;
    int j = 0;
    while(i < vetor.size()){
        for(int z =0; z<tamanho_vezes[j]; z++){
            cout<<vetor[i]<<endl;
            i++;
        }
        if(j < u - 1){
            printf("\n");
        }
        j++;
    }
    return 0;
}
int tamanho_String(string palavra){
    int contador = 0;
    string::iterator inicio = palavra.begin();
    string::iterator fim =palavra.end();
    for(inicio; inicio<fim;inicio++){
        contador++;
    }
    return contador;
}

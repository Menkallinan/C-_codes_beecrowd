#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main() {
    int quantidade;
    cin>>quantidade;
    int k = 0;
    vector<string>vetor_principal;

    for(int i =0 ; i <quantidade;i++){
        vector<char>vetor;
        string palavra;
        cin.ignore();
        getline(cin, palavra);
        int valor_subir;
        cin>>valor_subir;
        string::iterator caracter_inicial;
        string::iterator caracter_final;
        int j = 0;

        caracter_inicial = palavra.begin();
        for(caracter_inicial; caracter_inicial != palavra.end();caracter_inicial++){
            if((*caracter_inicial - valor_subir) >=65 and (*caracter_inicial - valor_subir) <=90){
                vetor.push_back(*caracter_inicial - valor_subir);
                cout<<vetor[j];
                j++;

            }
            else{
                 vetor.push_back((*caracter_inicial - valor_subir)+26);
                 cout<<vetor[j];
                 j++;
            }

        }
        cout<<endl;


    }

    return 0;
}

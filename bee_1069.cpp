
/* João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.*/
#include <stack>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int amount(string word){
    stack<char>diamond;
    int aux = 0;
    for(int i = 0; i <word.size(); i++){
        if(word[i] == '<'){
            diamond.push(word[i]);
        }
        else if(word[i] == '>'){
            if(!diamond.empty() && diamond.top() == '<'){
                diamond.pop();
                aux++;
            }
        }
    }
    return aux;
}

int main(){
    
    int i;
    cin>>i;
    vector<int>awnser;
    
    for(int j = 0; j < i; j++){
        string word;
        cin>>word;
        awnser.push_back(amount(word));
    }
    for(int i =0 ; i <awnser.size();i++)
        cout<<awnser[i]<<endl;
    

    return 0;
}

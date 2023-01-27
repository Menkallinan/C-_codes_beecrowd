/*Neste problema você deve ler um número, indicando uma linha da matriz na qual uma operação deve ser realizada, um caractere maiúsculo, indicando a operação que será realizada, e todos os elementos de uma matriz M[12][12]. Em seguida, calcule e mostre a soma ou a média dos elementos que estão na área verde da matriz, conforme for o caso. A imagem abaixo ilustra o caso da entrada do valor 2 para a linha da matriz, demonstrando os elementos que deverão ser considerados na operação.

Entrada
A primeira linha de entrada contem um número L (0 ≤ L ≤ 11) indicando a linha que será considerada para operação. A segunda linha de entrada contém um único caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média) que deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto flutuante que compõem a matriz, sendo que a mesma é preenchida linha por linha, da linha 0 até a linha 11, sempre da esquerda para a direita.

Saída
Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
*/

#include <iostream>

using namespace std;

int main()
{
    int posicao;
    cin>>posicao;

    char operacao;
    cin>>operacao;

    float matriz[12][12];
    for(int i = 0; i < 12;i++){
        for(int j = 0 ; j<12;j++){
            float valor;
            cin>>valor;
            matriz[i][j] = valor;
        }
    }

    float soma_total = 0;
    for(int j =0; j < 12;j++){
       soma_total= soma_total + matriz[posicao][j];
    }
    if(operacao == 'S')
        printf("%.1f\n", soma_total);
    if(operacao == 'M')
        printf("%.1f\n", soma_total/12);


    return 0;
}

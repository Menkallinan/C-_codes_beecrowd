
#include <list>
#include<vector>
#include<math.h>
#include <iostream>
using namespace std;

void add(vector<int>vetor1, vector<int>vetor2){
    list<int>awnser;
    int max = ((vetor1.size()> vetor2.size()) ?vetor1.size() : vetor2.size()) - 1;
    int size1 = vetor1.size() - 1;
    int size2 = vetor2.size() - 1;
    int sum = 0;
    int i = 0;
    
    while(i <= max){

        if(size1 < 0){
            awnser.push_front((vetor2[size2]+sum)%10);
            sum = (vetor2[size2]+sum)/10;
        }
        else if(size2 < 0){
            awnser.push_front((vetor1[size1]+sum)%10);
            sum =(vetor1[size1]+sum)/10;
        }
        else{
            int temp = vetor1[size1] + vetor2[size2] + sum;
            awnser.push_front(temp%10);
            sum = temp/10;
        }
        i++; 
        size1--;
        size2--;
    }
    if (sum != 0)
        awnser.push_front(sum);
        
    for (auto it = awnser.begin(); it !=awnser.end(); ++it)
        cout <<*it;
    printf("\n");
}

int main()
{
    string word1, word2;
    cin>>word1>>word2;
    
    vector<int>vetor1;
    vector<int>vetor2;
    
    for(int i = 0; i < word1.size();i++){
        vetor1.push_back(word1[i] - 48);
    }
    for(int i = 0; i < word2.size();i++){
        vetor2.push_back(word2[i]- 48);
    }
    add(vetor1, vetor2);
    
    return 0;
}

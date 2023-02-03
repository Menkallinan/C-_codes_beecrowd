#include <iostream>
#include <string>
#include <vector>

int conversao(const std::string &palavra) {
  int valor = 0;
  
  for (int i = 2; i < palavra.size(); i++) {
    if (palavra[i] >= 'A' && palavra[i] <= 'F') 
    
      valor = 16 * valor + (palavra[i] - 'A' + 10);
    else if (palavra[i] >= 'a' && palavra[i] <= 'f') 
      valor = 16 * valor + (palavra[i] - 'a' + 10);
 
    else 
      valor = 16 * valor + (palavra[i] - '0');
    
  }
  return valor;
}

int main() {
  std::string palavra;
  std::vector<int> decimal;
  std::vector<int> valores;
  while (std::cin >> palavra && palavra != "-1") {
    if (palavra[1] == 'x') {
      decimal.push_back(0);
      valores.push_back(conversao(palavra));
    } 
    else {
      decimal.push_back(1);
      valores.push_back(std::stoul(palavra));
    }
  }
  for (int i = 0; i < decimal.size(); i++) {
      
    if (decimal[i] == 1) {
      printf("0x%X\n", valores[i]);
    } 
    else {
      printf("%d\n", valores[i]);
    }
    
  }
  return 0;
}

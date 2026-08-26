//  Incremento e Decremento de Variáveis, Operadores pós e pré-fixados
#include <iostream>
using namespace std;

int main(){

    int n1;

    n1=20;

    cout << n1 << "\n\n"; // Se colocar o pré fixado ++n ele soma 1 mas se usar o n++ não vai mostrar o incremento por que ele foi realizado depois de chamar o n

    // n1=n1+5; forma padrão de incremento 
    // n1=+5; forma simplificada
    // n1++; adicionando o número 1 ou n--; para subtrair
    ++n1;
    n1*=2;

    cout << n1 << "\n\n";

    return 0;
}
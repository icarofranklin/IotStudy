#include <iostream>
using namespace std;

int main(){

    int n1,n2;

    n1=2;
    n2=5;

    cout << "Resultado antes do incremento: \n";
    std::cout << n1 << "\n" << n2 << std::endl;

    n1 = n1 * n2 + 10; //forma tradicional de incremento
    n2 = n2 * n1;

    cout << "Resultado após do incremento: \n";
    std::cout << n1 << "\n" << n2 << std::endl;

    return 0;
}
//std::cout << n2 << std::endl; Caso eu quisesse imprimir o número inteiro na tela
// Invertendo valores de variáveis
#include <iostream>
using namespace std;

int main (){

    int num=10;

    cout << num << "\n\n";

    /*
    num = num * -1; Maneira 1 de inversão de valores
    O menos ( - ) é o simbolo padrão de inversão de valores
    */

    num=-num; // essa forma é foda 

    cout << num << "\n\n"; // se você colocar "-num" ele faz a inversão temporariamente

    return 0;
}
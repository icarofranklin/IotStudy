#include <iostream>

using namespace std;
int main(){
    
    int n1, x;

    x = 5;

    cout << "Digite um número: ";
    cin >> n1; 

    (n1 > 5) ? x++ : x--;

    cout << "\nValor final é: " << x << "\n";

    return 0;
}
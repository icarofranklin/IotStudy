#include <iostream>

using namespace std;
int main(){

    // (expressão) ? valor1 : valor2; 
    int n1, n2, nota;
    string res;

    cout << "Digite a primeira nota: ";
    cin >> n1;
    cout << "Digite a segunda nota: ";
    cin >> n2;

    nota = n1+n2;

    /* 
    >= 60 aprovado 
    <60 reprovado
    */

    //(nota >= 60) ? res = "Aprovado!" : res = "Reprovado!";

    res = (nota >= 60) ? "Aprovado" : "Reprovado";

    cout << "\nSituacao do aluno: " << res << "\n";

    return 0;
}
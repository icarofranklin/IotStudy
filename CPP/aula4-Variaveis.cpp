// Aula de variveis
#include <iostream>
using namespace std;
int main(){
    //TIPO nome;
    //TIPO nome = VALOR;
    int vidas=0; // Numeros inteiros
    char letra = 'A'; // letras que ocupam 1 byte
    //char primeiroNome [5]; // Entre "[]" você pode escolher quantos caracteres vão ficar no char
    double decimal = 2.4999999;
    float decimal2 = 2.5; // Identico ao "double" só que com uma precisão menor
    bool vivo = true; // true ou false - 0 ou 1
    string nome = "ICARO"; // Cabe uma palavra, difente do "char" que cabe apenas uma letra

    cout << "Qual o seu nome: ";
    cin >> nome; 
    cout << "Digite o numero de vidas: ";
    cin >> vidas; 
    cout << "Digite uma letra: ";
    cin >> letra; 
    cout << "Salário: ";
    cin >> decimal; 
    cout << "Dinheiro em conta: ";
    cin >> decimal2; 
    cout << "Vivo: ";
    cin >> vivo; 

    // cout << nome << "\n";
    // cout << vidas << "\n";
    // cout << letra << "\n";
    // //cout << primeiroNome << "\n";
    // cout << decimal << "\n";
    // cout << decimal2 << "\n";
    // cout << vivo << "\n";

    cout << nome << "\n" << vidas << "\n" << letra << "\n" << decimal << "\n" << decimal2 << "\n" << vivo << "\n";

    return 0;
}
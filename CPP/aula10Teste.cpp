#include <iostream>
using namespace std;
int main(){

    int n1,n2,res;
    //char opc;

    cout << "Digite o valor da nota 1: ";
    cin >> n1;

    while (n1 > 10 || n1 < 0){   
        cout << "Nota inválida! A nota máxima é 10.\n\n Digite a nota novamente: ";
        cin >> n1;
    }

    cout << "Digite o valor da nota 2: ";
    cin >> n2;

    while (n2 > 10 || n2 < 0 ){   
        cout << "Nota inválida! A nota máxima é 10.\n\n Digite a nota novamente: ";
        cin >> n2;
    }

    res=(n1+n2)/2;

    if(res>=7){
        cout << "\nO aluno foi aprovado!\n";
    }else if(res>=5){
        cout << "\nAluno de recuperação!\n";
    }else{
        cout << "\nAluno reprovado!\n";
    }

    return 0;
}
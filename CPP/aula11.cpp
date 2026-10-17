#include <iostream>

using namespace std;
int main(){
// Curso de C++ #11 - Operadores AND, OR, NOT
    
    int num;

    /* 
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    <3 ou >8
    */
   
    num = 9;

    if(num < 3 || num > 8){
        cout << "\n\nValor aceito\n";
    }else{
        cout << "\n\nValor não aceito\n";
    }

    return 0;
}

 /*
    PRIMEIRO TESTE COM O AND

     num = 5;

    if(num > 4 && num < 7){
        cout << "\n\nValor aceito\n";
    }else{
        cout << "\n\nValor não aceito\n";
    }
 */
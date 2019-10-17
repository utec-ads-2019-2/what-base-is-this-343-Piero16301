#include<bits/stdc++.h>

using namespace std;

int minimaBase(const char* numero) {

    int maximo = 2;
    while (*numero) {
        if (std::isdigit(*numero)) {
            maximo = (int(*numero) - 47 > maximo) ? int(*numero) - 47 : maximo;
        }
        else if (std::isalpha(*numero)) {
            maximo = (int(*numero) - 54 > maximo) ? int(*numero) - 54 : maximo;
        }
        numero++;
    }
    return maximo;

}

long long valor(char caracter) {

    if (std::isdigit(caracter)) {
        return (int)caracter - '0';
    } else {
        return (int)caracter - 'A' + 10;
    }

}

long long convertirDecimal(const char* numero, int base) {

    int size = strlen(numero);
    int potencia = 1;
    int resultado = 0;
    for (int i = size - 1; i >= 0; --i) {
        resultado += valor(numero[i]) * potencia;
        potencia *= base;
    }
    return resultado;

}

bool sonIguales(const char* numero1, const char* numero2) {

    int menorValor1 = minimaBase(numero1);
    int menorValor2 = minimaBase(numero2);
    while (menorValor1 <= 36 && menorValor2 <= 36) {
        if (convertirDecimal(numero1, menorValor1) > convertirDecimal(numero2, menorValor2)) {
            menorValor2++;
        }
        else if (convertirDecimal(numero1, menorValor1) < convertirDecimal(numero2, menorValor2)) {
            menorValor1++;
        }
        else if (convertirDecimal(numero1, menorValor1) == convertirDecimal(numero2, menorValor2)) {
            cout << numero1 << " (base " << menorValor1 << ") = " << numero2 << " (base " << menorValor2 << ')' << endl;
            return true;
        }
    }
    return false;

}

int main() {
    
    char numero1 [100];
    char numero2 [100];
    while (scanf("%s %s", &numero1, &numero2) == 2) {
        if (!sonIguales(numero1, numero2)) {
            cout << numero1 << " is not equal to " << numero2 << " in any base 2..36" << endl;
        }
    }

    return 0;
}
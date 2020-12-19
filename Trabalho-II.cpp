#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Feito por Davi de Paula Oliveira - ES98896

// Declarando as funções

long double leibniz(int n);

long double wallis(int n);

long double euler(int n);

long double viete(int n);

long double brouncker(int n);

int main() {

    // Declarando as variáveis

    int resposta, n;
    long double pi;

    // Informando as opções

    cout << "1 - Leibniz\n";
    cout << "2 - Wallis\n";
    cout << "3 - Euler\n";
    cout << "4 - Viete\n";
    cout << "5 - Brouncker\n";
    cout << "0 - Sair\n\n";

    cout << "Informe a opcao:\n";

    cin >> resposta;

    while(resposta != 0) {

        if(resposta == 1) {

            cout << "\nInforme a quantidade de termos da sequencia:\n";
            cin >> n;
            pi = leibniz(n);
            cout << "\nPi = " << fixed << setprecision(20) << pi << endl << endl;

        } else if(resposta == 2) {

            cout << "\nInforme a quantidade de termos da sequencia:\n";
            cin >> n;
            pi = wallis(n);
            cout << "\nPi = " << fixed << setprecision(20) << pi << endl << endl;

        } else if(resposta == 3) {

            cout << "\nInforme a quantidade de termos da sequencia:\n";
            cin >> n;
            pi = euler(n);
            cout << "\nPi = " << fixed << setprecision(20) << pi << endl << endl;

        } else if(resposta == 4) {

            cout << "\nInforme a quantidade de termos da sequencia:\n";
            cin >> n;
            pi = viete(n);
            cout << "\nPi = " << fixed << setprecision(20) << pi << endl << endl;

        } else if(resposta == 5) {

            cout << "\nInforme a quantidade de termos da sequencia:\n";
            cin >> n;
            pi = brouncker(n);
            cout << "\nPi = " << fixed << setprecision(20) << pi << endl << endl;

        }

        cout << "1 - Leibniz\n";
        cout << "2 - Wallis\n";
        cout << "3 - Euler\n";
        cout << "4 - Viete\n";
        cout << "5 - Brouncker\n";
        cout << "0 - Sair\n\n";

        cout << "Informe a opcao:\n";

        cin >> resposta;

    }

    return 0;

}

// Sequência de Leibniz

long double leibniz(int n) {

    // Declarando as variáveis

    long double pi = 0;
    int contador = 1;

    // Calculando o valor de Pi

    for(int i = 1; i <= n; i++) {

        if(i % 2 == 0) {

            pi -= 1.0/contador;

        } else {

            pi += 1.0/contador;

        }

        contador += 2;

    }

    pi *= 4.0;

    // Retornando o resultado

    return pi;

}

// Sequência de Wallis

long double wallis(int n) {

    // Declarando as variáveis

    long double pi = 1;
    int numerador = 0;
    int denominador = 1;

    // Calculando o valor de Pi

    for(int i = 1; i <= n; i++) {

        if(i % 2 == 0) {

            denominador += 2;

        } else {

            numerador += 2;

        }

        pi *= (long double)numerador/denominador;

    }

    pi *= 2.0;

    // Retornando o resultado

    return pi;

}

// Sequência de Euler

long double euler(int n) {

    // Declarando as variáveis

    long double pi = 0;

    // Calculando o valor de Pi

    for(int i = 1; i <= n; i++) {

        pi += 1.0/(i * i);

    }

    pi *= 6.0;
    pi = sqrt(pi);

    // Retornando o resultado

    return pi;

}

// Sequência de Viète

long double viete(int n) {

    // Declarando as variáveis

    long double pi, q = 0, numerador = 1, denominador = 1;

    // Calculando o valor de Pi

    for(int i = 0; i < n; i++) {

        q = sqrt(2 + q);
        numerador *= q;
        denominador *= 2;

    }

    pi = denominador/numerador;
    pi *= 2;

    // Retornando o resultado

    return pi;

}

// Sequência de Brouncker

long double brouncker(int n) {

    // Declarando as variáveis

    long double pi, soma, i,  j;

    // Calculando o valor de Pi

    n -= 2;
    j = pow(2 * n + 1,2) / 2.0;
    i = n - 1;

    while(i >= 0) {

        j = pow(2 * i + 1,2) / (2.0 + j);
        i -= 1;

    }

    pi =  4.0/(1.0 + j);

    // Retornando o resultado

    return pi;

}

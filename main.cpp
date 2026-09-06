#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long max_cubica(const int l[], int n)
{
    long long maximo = l[0];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long parcial = 0;

            for (int k = i; k < j; k++) {
                parcial = parcial + l[k];
            }

            if (parcial > maximo) {
                maximo = parcial;
            }
        }
    }

    return maximo;
}

long long max_cuadratica(const int l[], int n)
{
    long long maximo = l[0];

    for (int i = 0; i < n; i++) {
        long long parcial = 0;

        for (int j = i; j < n; j++) {
            parcial = parcial + l[j];

            if (parcial > maximo) {
                maximo = parcial;
            }
        }
    }

    return maximo;
}

long long max_lineal(const int l[], int n)
{
    long long maximo = l[0];
    long long parcial = l[0];

    for (int i = 1; i < n; i++) {
        if (parcial + l[i] > l[i]) {
            parcial = parcial + l[i];
        } else {
            parcial = l[i];
        }

        if (parcial > maximo) {
            maximo = parcial;
        }
    }

    return maximo;
}

double tiempo_cubica(const int l[], int n)
{
    int repeticiones = 1;

    if (n == 1000) {
        repeticiones = 4;
    }

    clock_t inicio = clock();
    volatile long long resultado = 0;

    for (int i = 0; i < repeticiones; i++) {
        resultado = max_cubica(l, n - i % 2);
    }

    clock_t fin = clock();

    (void)resultado;
    return (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;
}

double tiempo_cuadratica(const int l[], int n)
{
    int repeticiones = 100000000LL / ((long long)n * n);

    if (repeticiones < 1) {
        repeticiones = 1;
    }

    clock_t inicio = clock();
    volatile long long resultado = 0;

    for (int i = 0; i < repeticiones; i++) {
        resultado = max_cuadratica(l, n - i % 2);
    }

    clock_t fin = clock();

    (void)resultado;
    return (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;
}

double tiempo_lineal(const int l[], int n)
{
    int repeticiones = 10000000 / n;

    if (repeticiones < 1) {
        repeticiones = 1;
    }

    clock_t inicio = clock();
    volatile long long resultado = 0;

    for (int i = 0; i < repeticiones; i++) {
        resultado = max_lineal(l, n - i % 2);
    }

    clock_t fin = clock();

    (void)resultado;
    return (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;
}

int main()
{
    srand(2026);

    for (int prueba = 0; prueba < 100; prueba++) {
        int n = 2 + rand() % 19;
        int *l = new int[n];

        for (int i = 0; i < n; i++) {
            l[i] = -10 + rand() % 21;
        }

        l[0] = -1 - rand() % 10;
        l[1] = 1 + rand() % 10;

        long long r1 = max_cubica(l, n);
        long long r2 = max_cuadratica(l, n);
        long long r3 = max_lineal(l, n);

        if (r1 != r2 || r2 != r3) {
            cout << "ERROR en la prueba " << prueba + 1 << "\n";
            cout << "Arreglo: ";

            for (int i = 0; i < n; i++) {
                cout << l[i] << " ";
            }

            cout << "\nCubica: " << r1 << "\n";
            cout << "Cuadratica: " << r2 << "\n";
            cout << "Lineal: " << r3 << "\n";

            delete[] l;
            return 1;
        }

        delete[] l;
    }

    cout << "Las 3 soluciones coinciden en las 100 pruebas.\n\n";

    int calentamiento[2000];

    for (int i = 0; i < 2000; i++) {
        calentamiento[i] = -10 + i % 21;
    }

    volatile long long resultado_calentamiento = max_cubica(calentamiento, 2000);
    (void)resultado_calentamiento;

    int tamanos[] = {1000, 2000, 4000, 8000};
    int cantidad = sizeof(tamanos) / sizeof(tamanos[0]);

    double anterior_cubica = 0.0;
    double anterior_cuadratica = 0.0;
    double anterior_lineal = 0.0;

    double ultimo_cubica = 0.0;
    double ultimo_cuadratica = 0.0;
    double ultimo_lineal = 0.0;
    int ultimo_n = 0;

    cout.setf(ios::fixed);
    cout.setf(ios::right, ios::adjustfield);
    cout.precision(9);

    cout.width(6);
    cout << "n" << " | ";
    cout.width(14);
    cout << "Cubica(s)" << " | ";
    cout.width(8);
    cout << "Razon" << " | ";
    cout.width(16);
    cout << "Cuadratica(s)" << " | ";
    cout.width(8);
    cout << "Razon" << " | ";
    cout.width(14);
    cout << "Lineal(s)" << " | ";
    cout.width(8);
    cout << "Razon" << "\n";
    cout << "--------------------------------------------------------------------------------------------\n";

    for (int x = 0; x < cantidad; x++) {
        int n = tamanos[x];
        int *l = new int[n];

        for (int i = 0; i < n; i++) {
            l[i] = -10 + rand() % 21;
        }

        double tc = tiempo_cubica(l, n);
        double tq = tiempo_cuadratica(l, n);
        double tl = tiempo_lineal(l, n);

        cout.precision(9);
        cout.width(6);
        cout << n << " | ";
        cout.width(14);
        cout << tc << " | ";

        cout.precision(2);
        cout.width(8);

        if (x == 0) {
            cout << "-";
        } else {
            cout << tc / anterior_cubica;
        }

        cout << " | ";
        cout.precision(9);
        cout.width(16);
        cout << tq << " | ";

        cout.precision(2);
        cout.width(8);

        if (x == 0) {
            cout << "-";
        } else {
            cout << tq / anterior_cuadratica;
        }

        cout << " | ";
        cout.precision(9);
        cout.width(14);
        cout << tl << " | ";

        cout.precision(2);
        cout.width(8);

        if (x == 0 || anterior_lineal == 0.0) {
            cout << "-\n";
        } else {
            cout << tl / anterior_lineal << "\n";
        }

        anterior_cubica = tc;
        anterior_cuadratica = tq;
        anterior_lineal = tl;

        ultimo_cubica = tc;
        ultimo_cuadratica = tq;
        ultimo_lineal = tl;
        ultimo_n = n;

        delete[] l;
    }

    int n_grande = 100000000;
    double factor = (double)n_grande / ultimo_n;

    double pred_cubica = ultimo_cubica * factor * factor * factor;
    double pred_cuadratica = ultimo_cuadratica * factor * factor;
    double pred_lineal = ultimo_lineal * factor;

    cout.precision(2);
    cout << "\nPredicciones para n = 10^8 usando n = " << ultimo_n << ":\n";
    cout << "Cubica: " << pred_cubica << " segundos\n";
    cout << "Cuadratica: " << pred_cuadratica << " segundos\n";
    cout << "Lineal: " << pred_lineal << " segundos\n\n";

    cout << "Versiones estimadas en menos de un minuto:\n";
    bool hay_alguna = false;

    if (pred_cubica < 60.0) {
        cout << "Cubica\n";
        hay_alguna = true;
    }
    if (pred_cuadratica < 60.0) {
        cout << "Cuadratica\n";
        hay_alguna = true;
    }
    if (pred_lineal < 60.0) {
        cout << "Lineal\n";
        hay_alguna = true;
    }
    if (!hay_alguna) {
        cout << "Ninguna\n";
    }

    if (pred_lineal < 60.0) {
        cout << "\nGenerando el arreglo de 10^8 elementos...\n";
        int *l_grande = new int[n_grande];

        for (int i = 0; i < n_grande; i++) {
            l_grande[i] = -10 + rand() % 21;
        }

        double tiempo_real = tiempo_lineal(l_grande, n_grande);
        double diferencia = tiempo_real - pred_lineal;

        if (diferencia < 0.0) {
            diferencia = -diferencia;
        }

        cout.precision(6);
        cout << "Tiempo predicho de la version lineal: " << pred_lineal << " segundos\n";
        cout << "Tiempo medido de la version lineal: " << tiempo_real << " segundos\n";
        cout << "Diferencia: " << diferencia << " segundos\n";

        delete[] l_grande;
    }

    return 0;
}

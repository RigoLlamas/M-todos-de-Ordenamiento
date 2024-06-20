#include <iostream>
using namespace std;
class Metodos
{
public:
    void Insercion(double Numeros[50], int Tam, char Respuesta);
};
void Metodos::Insercion(double Numeros[50], int Tam, char Respuesta)
{
    double Aux = 0;
    if (Respuesta == 'S')
    {
        cout << "Cuantos numeros vas a ingresar" << endl;
        cin >> Tam;
        if (Tam <= 0 || Tam >= 51)
        {
            cout << "Tamaño no compatible" << endl;
            Tam = 0;
        }
        else
        {
            for (int i = 1; i <= Tam; i++)
            {
                cout << "Introduce tu " << i << " numeros: " << endl;
                cin >> Numeros[i];
            }
        }
    }
    for (int i = 1; i <= Tam; i++)
    {
        if (Respuesta == 'N')
        {
            for (int m = 1; m < i; m++)
            {
                cout << Numeros[m] << "\t";
            }
            cout << "\nIntroduce tu " << i << " numeros (-1000 para salir): " << endl;
            cin >> Numeros[i];
            if (Numeros[i] == -1000)
            {
                cout << "Terminando" << endl;
                break;
            }
            Tam++;
        }
        Aux = Numeros[i];
        int p = (i - 1);
        while (p >= 0 && Numeros[p] >= Aux)
        {
            Numeros[p + 1] = Numeros[p];
            p--;
        }
        Numeros[p + 1] = Aux;
        if (i != 1 && Respuesta == 'S')
        {
            for (int i = 1; i <= Tam; i++)
            {
                cout << Numeros[i] << "\t";
            }
            cout << "\n";
        }
    }

};
int main()
{
    int Tam = 1;
    char R;
    double Numeros[50];
    cout << "Desea almacenar previamente los nuemros? \n[S] Si\n[N] No" << endl;
    cin >> R;
    Metodos Ins;
    Ins.Insercion(Numeros, Tam, R);
    return 0;
};
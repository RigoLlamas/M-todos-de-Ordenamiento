#include <iostream>
using namespace std;
class Metodos
{
public:
    void Seleccion(double Numeros[50], int Tam, char Respuesta);
};
void Metodos::Seleccion(double Numeros[50], int Tam, char Respuesta)
{
    for (int i = Tam; i >= 0; i--)
    {
        int Intercambios = 0;
        int NumMax = i;
        double Aux;
        for (int j = i - 1; j >= 0; j--)
        {
            if (Numeros[j] > Numeros[NumMax])
            {
                NumMax = j;
                Intercambios++;
            }
        }
        if (NumMax != i)
        {
            Aux = Numeros[i];
            Numeros[i] = Numeros[NumMax];
            Numeros[NumMax] = Aux;

        }
        if (Respuesta == 'S')
        {
            for (int i = 1; i <= Tam; i++)
            {
                cout << "\t" << Numeros[i];
            }
            cout << endl;
        }
        if (Intercambios == 0)
        {
            break;
        }
    }
    if (Respuesta == 'N')
    {
        for (int i = 1; i <= Tam; i++)
        {
            cout << "\t" << Numeros[i];
        }
    }
};
int main()
{
    int Tam;
    char R;
    cout << "Cuantos numeros vas a ingresar" << endl;
    cin >> Tam;
    if (Tam < 0 || Tam > 51)
    {
        cout << "Tamaño no compatible" << endl;
    }
    else
    {
        double Numeros[50];
        for (int i = 1; i <= Tam; i++)
        {
            cout << "Introduce tus numeros: " << endl;
            cin >> Numeros[i];
        }
        cout << "Desea ver el proceso de ordenamiento? \n[S] Si\n[N] No" << endl;
        cin >> R;
        Metodos Sel;
        cout << "Estos son tus numeros ordenados : \n" << endl;
        Sel.Seleccion(Numeros, Tam, R);
    }
    return 0;
};
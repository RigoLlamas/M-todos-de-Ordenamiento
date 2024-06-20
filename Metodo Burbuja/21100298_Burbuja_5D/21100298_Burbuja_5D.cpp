#include <iostream>
using namespace std;
class Metodos
{
public:
    void Burbuja(double Numeros[50], int Tam, char Respuesta);
};

void Metodos::Burbuja(double Numeros[50], int Tam, char Respuesta)
{
    int TamBur = Tam;
    for (int x = 1; x <= Tam; x++)
    {
        int Intercambios = 0;
        for (int i = 1; i < TamBur; i++)
        {
            if (Numeros[i] > Numeros[i + 1])
            {
                double Aux = Numeros[i];
                Numeros[i] = Numeros[i + 1];
                Numeros[i + 1] = Aux;
                Intercambios++;
            }
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
        TamBur--;
    }
    if (Respuesta == 'N')
    {
        for (int i = 1; i <= Tam; i++)
        {
            cout << "\t" << Numeros[i];
        }
    }
}
int main()
{
    int Tam;
    char R;
    cout << "Cuantos numeros vas a ingresar" << endl;
    cin >> Tam;
    if (Tam < 0 || Tam > 51)
    {
        cout << "Tamano no compatible" << endl;
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
        Metodos Buj;
        cout << "Estos son tus numeros ordenados : \n" << endl;
        Buj.Burbuja(Numeros, Tam, R);
    }
    return 0;
}
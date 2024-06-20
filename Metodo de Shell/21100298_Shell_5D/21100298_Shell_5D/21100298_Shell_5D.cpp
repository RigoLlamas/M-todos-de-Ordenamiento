#include <iostream>
using namespace std;
class Metodos
{
public:
    void Shell(double Numeros[50], int Tam, char Respuesta);
};
void Metodos::Shell(double Numeros[50], int Tam, char Respuesta)
{
    int Salto = (Tam + 1) / 2;
    int Pos = 0;
    double Aux = 0;
    while (Salto > 0)
    {
        if (Respuesta == 'S')
        {
            for (int i = 1; i <= Tam; i++)
            {
                cout << Numeros[i] << "\t";
            }
            cout << endl;
        }
        for (int i = Salto + 1; i <= Tam; i++)
        {
            Aux = Numeros[i];
            Pos = i;
            while (Pos >= Salto + 1 && Numeros[Pos - Salto] > Aux)
            {
                Numeros[Pos] = Numeros[Pos - Salto];
                Pos -= Salto;
            }
            Numeros[Pos] = Aux;
        }
        if (Salto == 1)
        {
            Salto /= 2;
        }
        else
        {
            Salto = (Salto + 1) / 2;
        }
    }
}
int main()
{
    Metodos Shell;
    double Numeros[50];
    int Tam;
    char R;
    cout << "Cuantos numeros vas a ingresar: " << endl;
    cin >> Tam;
    if (Tam <= 0 || Tam > 50)
    {
        cout << "Tamaño no compatible" << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= Tam; i++)
        {
            cout << "Introduce el " << i << " numero: " << endl;
            cin >> Numeros[i];
        }
    }
    cout << "Desea ver el proceso de ordenamiento? \n[S] Si\n[N] No" << endl;
    cin >> R;
    cout << "Estos son tus numeros ordenados : \n" << endl;
    Shell.Shell(Numeros, Tam, R);
    for (int i = 1; i <= Tam; i++)
    {
        cout << Numeros[i] << "\t";
    }
    cout << endl;
    return 0;
}
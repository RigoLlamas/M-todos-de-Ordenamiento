#include <iostream>
#include <cmath>
using namespace std;
class Metodos
{
public:
    void Radix(int Numeros[50], int Tam, char Respuesta);
};
void Metodos::Radix(int Numeros[50], int Tam, char Respuesta)
{
    int NumMax = Numeros[0];
    for (int i = 1; i < Tam; i++) 
    {
        if (Numeros[i] > NumMax)
        {
            NumMax = Numeros[i];
        }
    }
    int PosDig = 1;
    int* SubNum = new int[Tam];
    while (NumMax / PosDig > 0)
    {
        int DigNum[10] = { 0 };
        for (int i = 0; i < Tam; i++)
        {
            int Dig = (Numeros[i] / PosDig) % 10;
            DigNum[Dig]++;
        }
        for (int i = 1; i < 10; i++)
        {
            DigNum[i] += DigNum[i - 1];
        }

        for (int i = Tam - 1; i >= 0; i--) 
        {
            int Dig = (Numeros[i] / PosDig) % 10;
            SubNum[DigNum[Dig] - 1] = Numeros[i];
            DigNum[Dig]--;
        }
        for (int i = 0; i <= Tam; i++) 
        {
            Numeros[i] = SubNum[i];
        }
        PosDig *= 10;
        if (Respuesta == 'S')
        {
            for (int i = 0; i < Tam; i++)
            {
                cout << "\t" << Numeros[i];
            }
            cout << endl;
        }
    }
    if (Respuesta == 'N')
    {
        for (int i = 0; i < Tam; i++)
        {
            cout << "\t" << Numeros[i];
        }
    }
}
int main() 
{
    Metodos Rad;
    int Numeros[50];
    int Tam;
    char R;
    cout << "Desea ver el proceso de ordenamiento? \n[S] Si\n[N] No" << endl;
    cin >> R;
    cout << "Cuantos numeros vas a ingresar: " << endl;
    cin >> Tam;
    if (Tam <= 0 || Tam > 50)
    {
        cout << "Tamaño no compatible" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < Tam; i++)
        {
            cout << "Introduce el " << i + 1 << " numero: " << endl;
            cin >> Numeros[i];
        }
    }
    cout << "Estos son tus numeros ordenados : \n" << endl;
    Rad.Radix(Numeros, Tam, R);
    return 0;
}
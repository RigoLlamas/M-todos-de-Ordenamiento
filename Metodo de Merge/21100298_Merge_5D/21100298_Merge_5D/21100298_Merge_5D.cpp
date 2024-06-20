#include <iostream>
using namespace std;

class Metodos
{
public:
    void Merge(double Numeros[50], int Inicio, int Final);
};
void Metodos::Merge(double Numeros[50], int Inicio, int Final)
{
    int Mitad = Inicio + (Final - Inicio) / 2;
    if (Inicio < Final) 
    {
        int PosIzq;
        int PosDer;
        Merge(Numeros, Inicio, Mitad);
        Merge(Numeros, Mitad + 1, Final);
        int Izq = Mitad - Inicio + 1;
        int Der = Final - Mitad;
        double* NumIzq = new double[Izq];
        double* NumDer = new double[Der];
        for (PosIzq = 0; PosIzq < Izq; PosIzq++) 
        {
            NumIzq[PosIzq] = Numeros[Inicio + PosIzq];
        }
        for (PosDer = 0; PosDer < Der; PosDer++) 
        {
            NumDer[PosDer] = Numeros[Mitad + 1 + PosDer];
        }
        PosIzq = 0;
        PosDer = 0;
        while (PosIzq < Izq && PosDer < Der) 
        {
            if (NumIzq[PosIzq] <= NumDer[PosDer]) 
            {
                Numeros[Inicio + PosIzq + PosDer] = NumIzq[PosIzq];
                PosIzq++;
            }
            else 
            {
                Numeros[Inicio + PosIzq + PosDer] = NumDer[PosDer];
                PosDer++;
            }
        }
        while (PosDer < Der) 
        {
            Numeros[Inicio + PosIzq + PosDer] = NumDer[PosDer];
            PosDer++;
        }
        while (PosIzq < Izq) 
        {
            Numeros[Inicio + PosIzq + PosDer] = NumIzq[PosIzq];
            PosIzq++;
        }
    }
}

int main()
{
    Metodos Merge;
    double Numeros[50];
    int Tam;
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
    Merge.Merge(Numeros, 0, Tam - 1);
    for (int i = 0; i < Tam; i++) 
    {
        cout << Numeros[i] << "\t";
    }
    cout << endl;
    return 0;
}
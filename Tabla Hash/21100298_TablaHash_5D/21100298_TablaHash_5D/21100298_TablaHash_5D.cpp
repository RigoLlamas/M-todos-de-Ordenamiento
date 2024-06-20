#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct PersonaDatos
{
    char Nombre[50];
    char Apellido[50];
    int Registro;
    int Edad;
};
class TablaHash
{
public:
    stack<PersonaDatos> Tabla[113];
    void Leer(PersonaDatos Datos);
    void Buscar(int registro);
};
void TablaHash::Leer(PersonaDatos Datos)
{
    Tabla[Datos.Registro % 113].push(Datos);
}
void TablaHash::Buscar(int registro)
{
    stack<PersonaDatos> Pos = Tabla[(registro % 113)];
    if (!Pos.empty())
    {
        while (!Pos.empty())
        {
            PersonaDatos Datos = Pos.top();
            if (Datos.Registro == registro)
            {
                cout << "Nombre: " << Datos.Nombre << endl;
                cout << "Apellido: " << Datos.Apellido << endl;
                cout << "Registro: " << Datos.Registro << endl;
                cout << "\nEdad: " << Datos.Edad << endl;
                Pos.pop();
            }
        }
    }
    else
    {
    cout << "\nElemento no encontrado.\n" << endl;
    }
};
int main()
{
    int Registro = 0;
    TablaHash Tabla;
    char R = 0;
    while (R != 'C')
    {
        cout << "\nQue quieres hacer?\n[A] Introducir datos\n[B] Buscar\n[C] Salir" << endl;
        cin >> R;
        switch (R)
        {
        case 'A':
        {
            cout << "Se eligio [A]" << endl;
            PersonaDatos Datos;
            cout << "Ingrese el nombre: " << endl;
            fgets(Datos.Nombre, 50, stdin);
            fgets(Datos.Nombre, 50, stdin);
            cout << "Ingrese el apellido: " << endl;
            fgets(Datos.Apellido, 50, stdin);
            cout << "Ingrese el registro: " << endl;
            cin >> Datos.Registro;
            if (Datos.Registro <= 0)
            {
                cout << "El registro entrado no es valido" << endl;
                while (Datos.Registro > 0)
                {
                    cout << "Ingrese el registro: " << endl;
                    cin >> Datos.Registro;
                }
            }
            cout << "Ingrese la edad: " << endl;
            cin >> Datos.Edad;
            if (Datos.Edad <= 0)
            {
                cout << "La edad entrada no es valido" << endl;
                while (Datos.Edad > 0)
                {
                    cout << "Ingrese la edad: " << endl;
                    cin >> Datos.Edad;
                }
            }
            Tabla.Leer(Datos);
            break;
        }
        case 'B':
        {
            cout << "Se eligio [B]" << endl;
            cout << "Ingrese el registro a buscar: ";
            cin >> Registro;
            Tabla.Buscar(Registro);
            break;
        }
        case 'C':
        {
            cout << "Se eligio [C]\nSaliendo del programa" << endl;
            break;
        }
        }
        if (R > 68 || R < 64)
        {
            cout << "Opcion no disponible, inrese lo suguerido" << endl;
            R = 0;
        }
    };
    return 0;
};
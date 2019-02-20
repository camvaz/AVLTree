#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
using namespace std;

const int MAX_IDSIZE = 7;

template <class T>
class ArbolAVL;

template <class T>
class NodoArbolAVL;

class Insecto
{
private:
    int id;
    string nombre;
    string alimento;
    string loc;
    string region;

public:
    Insecto(){}
    friend ostream& operator<< (ostream&, Insecto&);
    bool operator>(const Insecto&);
    bool operator<(const Insecto&);
    bool operator==(const Insecto&);
//    void operator=(const Insecto&);
    void setParameters(int, string&, string&, string&, string&);
    string getRegion(){return region;}
    string getLoc(){return loc;}
    string getAlimento(){return alimento;}
    void setID();
    void printInsecto();
    void writeParameters();
    friend class NodoArbolAVL<Insecto>;
};

//void Insecto::operator=(const Insecto &obj)
//{
//    id = id;
//    nombre = obj.nombre;
//    alimento = obj.alimento;
//    loc = obj.loc;
//    region = obj.region;
//}

ostream& operator<<(ostream& o, Insecto& objInsecto)
{
    o << "\n\t\tINSECTO: " << objInsecto.nombre;
    o << "\n\n\tID: " << objInsecto.id;
    o << "\n\tAlimentacion: " << objInsecto.alimento;
    o << "\n\tLocalizacion: " << objInsecto.loc;
    o << "\n\tArea : " << objInsecto.region;
    return o;
}

bool Insecto::operator>(const Insecto &obj)
{
    return id > obj.id;
}

bool Insecto::operator<(const Insecto &obj)
{
    return id < obj.id;
}

bool Insecto :: operator==(const Insecto &obj)
{
    return id == obj.id;
}

void Insecto::setID()
{
    cin>>id;
}

void Insecto::setParameters(int idParametro, string &nombreParametro, string &alimentoParametro, string &locParametro, string &regionParametro)
{
    id = idParametro;
    nombre = nombreParametro;
    alimento = alimentoParametro;
    loc=locParametro;
    region=regionParametro;
}

void Insecto::writeParameters() {

    cout << "\t\tNUEVO INSECTO\n\n";
    cout << "Ingrese el ID del insecto (Maximo 6 caracteres, sin espacios): \n\t";
    cin >> id;
    cout << "\n\nIngrese el nombre del insecto:\n\t";
    cin.ignore();
    getline(cin, nombre);
    cout << "\n\nIngrese alimentacion del insecto:\n\t";
    getline(cin, alimento);
    cout << "\n\nIngrese localizacion:\n\t";
    getline(cin, loc);
    cout << "\n\nIngrese area:\n\t";
    getline(cin, region);

}

void Insecto::printInsecto()
{
    cout << "\n\t\tINSECTO: " << nombre;
    cout << "\n\n\tID: " << id;
    cout << "\n\tAlimentacion: " << alimento;
    cout << "\n\tLocalizacion: " << loc;
    cout << "\n\tArea : " << region;
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

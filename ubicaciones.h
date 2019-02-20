#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class node_Localidad
{
private:
    string nombre;
    int index;
    node_Localidad *next;

public:
    node_Localidad(): next(NULL), i(0) {}
    node_Localidad(string& newName, int& posicion): nombre(newName), index(0), next(NULL){}
    friend class list_Region;
};

class list_Region
{
private:
    string nombre;
    int posicion;
    int cardinalidad;
    node_Localidad *head;

public:
    list_Region(){}
    list_Region(string& newName): index(0), cardinalidad(1), nombre(newName), head(NULL){}
    void insertaInicio(node_Localidad*);
    void insertar(string&);
    void imprimir();
    bool eliminar(string&);
    node_Localidad* buscar(string&);
};

void list_Region::insertaInicio(node_Localidad *nuevo)
{
    head->next = nuevo;
    head = nuevo;
}

void list_Region::insertar(string &e)
{
    node_Localidad *nuevo = new node_Localidad(e, cardinalidad);
    cardinalidad++;

    if(!head)
        insertaInicio(nuevo);
    else
    {
        node_Localidad *p = head;
        while(p->next)
            p=p->next;
        if(!p)
            cout << "error de insercion";
        else
        {
            p->next = nuevo;
            cout << "Localidad insertada: " << p->nombre << endl;
        }
    }
}

void list_Region::imprimir()
{
    node_Localidad *p = head;
    int i = 1;
    while(p)
    {
        cout << "\n" << i << ".- " << p->nombre << "\n";
        p = p->next;
        i++;
    }
}

bool list_Region::eliminar(string &key)
{
    if(!head)
        return false;
    else
    {
        node_Localidad *p, *q;
        p = head;
        while(p && p->nombre != key)
        {
            q=p;
            p=p->next;
        }

        if(!p)
        {
            cout << "\nNo se encontro una localidad con el nombre ingresado\n";
            return false;
        }
        else
        {
            if(p->nombre == key)
            {
                node *temp = p->next;
                q->next = temp;
                cout << "\nLocalidad: " << p->nombre << "eliminada con exito.\n";
                delete(p);
                cardinalidad--;
                return true;
            }
        }

    }
}

node_Localidad* list_Region::buscar(string &key)
{
    if(!head)
        cout << "\nSin elementos para buscar.\n";
    else
    {
        node_Localidad *p = head;
        while(p && p->nombre!=key)
            p=p->next;

        if(!p)
        {
            cout << "\nNo se encontro la localidad ingresada\n";
            return NULL;
        }
        else
        {
            if(p->nombre == key)
                return p;
        }
    }
}

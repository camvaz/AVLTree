#include "insecto.h"

using namespace std;
/* Prototipo de la plantilla de la clase ArbolAVL. De esta forma, en la clase
NodoArbolAVL se podr� hacer referencia a ella. */

template <class T>
class ArbolAVL;

/* Declaraci�n de la clase de un nodo de un �rbol avl. Adem�s de almacenar la
informaci�n, las direcciones de los hijos izquierdo y derecho, guarda el factor
de equilibrio. */
template <class T>
class NodoArbolAVL
{
	private:
		NodoArbolAVL<T> *HijoIzq;
		NodoArbolAVL<T> *HijoDer;
		T Info;
		int FE;
	public:
		NodoArbolAVL();
		T RegresaInfo();
		void ActualizaInfo(T);
		friend class ArbolAVL<T>;
		friend void printbyRegion(NodoArbolAVL<Insecto> *root, string&);
		friend void printbyLoc(NodoArbolAVL<Insecto> *, string&);
		friend void printbyAlimento(NodoArbolAVL<Insecto> *, string&);
};

/* Declaraci�n del m�todo constructor. Inicializa los apuntadores a ambos hijos
con el valor de NULL, indicando vac�o. */
template <class T>
NodoArbolAVL<T>::NodoArbolAVL()
{
	HijoIzq=NULL;
	HijoDer=NULL;
}

/* M�todo que regresa la informaci�n almacenada en el nodo. */
template <class T>
T NodoArbolAVL<T>::RegresaInfo()
{
	return Info;
}

/* M�todo que permite actualizar la informaci�n almacenada en el nodo. */
template <class T>
void NodoArbolAVL<T>::ActualizaInfo(T Dato)
{
	Info=Dato;
}

/* Declaracion de la clase ArbolAVL. Se incluyen s�lo los protoripos de los
m�todos presentados anteriormente. */
template <class T>
class ArbolAVL
{
	private:
		NodoArbolAVL<T> *Raiz;
	public:
		ArbolAVL();
        NodoArbolAVL<T> *RegresaRaiz();
		NodoArbolAVL<T> *Busca(NodoArbolAVL<T> *, T);
		void InsertaAVL(T, NodoArbolAVL<T> *, int *);
		NodoArbolAVL<T> * RotacionHI_HD(NodoArbolAVL<T> *, NodoArbolAVL<T> *);
		NodoArbolAVL<T> * RotacionHD_HI(NodoArbolAVL<T> *, NodoArbolAVL<T> *);
		NodoArbolAVL<T> * RotacionHI_HI(NodoArbolAVL<T> *, NodoArbolAVL<T> *);
		NodoArbolAVL<T> * RotacionHD_HD(NodoArbolAVL<T> *, NodoArbolAVL<T> *);
        NodoArbolAVL<T> * ReestructuraI(NodoArbolAVL<T> *, int *);
		NodoArbolAVL<T> * ReestructuraD(NodoArbolAVL<T> *, int *);
		void EliminaAVL(NodoArbolAVL<T> *, NodoArbolAVL<T> *, int *, T);
		void Sustituye (NodoArbolAVL<T> *, NodoArbolAVL<T> *, int *);
		void Imprime(NodoArbolAVL<T> *);
};

/* Declaraci�n del m�todo constructor. Inicializa el apuntador a la ra�z con el
valor NULL, indicando que el �rbol est� vac�o. */
template <class T>
ArbolAVL<T>::ArbolAVL()
{
	Raiz=NULL;
}

/* M�todo que regresa el apuntador a la ra�z de �rbol. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::RegresaRaiz()
{
	return Raiz;
}

/* M�todo que busca un valor dado como par�metro en el �rbol. Recibe como
par�metros el apuntador del nodo a visitar (la primera vez es la ra�z) y el
dato a buscar. Regresa el apuntador al nodo donde lo encontr� o NULL si no
est� en el �rbol. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::Busca(NodoArbolAVL<T> *Apuntador, T Dato)
{
	if (Apuntador !=NULL)
		if (Apuntador->Info==Dato)
			return Apuntador;
		else
			if (Apuntador->Info > Dato)
				return Busca(Apuntador->HijoIzq, Dato);
		    else
			    return Busca(Apuntador->HijoDer, Dato);
	else
		return NULL;
}

/* M�todo que imprime el contenido del �rbol. Recibe como par�metro el
apuntador al nodo a visitar (la primera vez es la ra�z del �rbol).
Utiliza recorrido en-orden para que el contenido se imprima en orden
creciente. */
template <class T>
void ArbolAVL<T>::Imprime(NodoArbolAVL<T> *Apuntador)
{
	if (Apuntador !=NULL)
	{
		Imprime(Apuntador->HijoIzq);
	    cout << Apuntador->Info << "\n\n";
		Imprime(Apuntador->HijoDer);
	}
}

/* M�todo que realiza la rotacion simple HI-HI en un �rbol AVL. Adem�s, reasigna
   el FE del nodo involucrado en la rotaci�n. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::RotacionHI_HI(NodoArbolAVL<T> *Apunt, NodoArbolAVL<T> *ApAux1)
{
    Apunt->HijoIzq=ApAux1->HijoDer;
    ApAux1->HijoDer=Apunt;
    Apunt->FE=0;
    return ApAux1;
}

/* M�todo que realiza la rotaci�n simple HD-HD en un �rbol AVL. Adem�s, reasigna
   el FE del nodo involucrado en la rotaci�n. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::RotacionHD_HD(NodoArbolAVL<T> *Apunt, NodoArbolAVL<T> *ApAux1)
{
    Apunt->HijoDer=ApAux1->HijoIzq;
    ApAux1->HijoIzq=Apunt;
    Apunt->FE=0;
    return ApAux1;
}

/* M�todo que realiza la rotaci�n compuesta HI-HD en un �rbol AVL. Adem�s,
   reasigna los FE de los nodos involucrados en la rotaci�n. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::RotacionHI_HD(NodoArbolAVL<T> *Apunt, NodoArbolAVL<T> *ApAux1)
{
   NodoArbolAVL<T> *ApAux2;
   ApAux2=ApAux1->HijoDer;
   Apunt->HijoIzq=ApAux2->HijoDer;
   ApAux2->HijoDer=Apunt;
   ApAux1->HijoDer=ApAux2->HijoIzq;
   ApAux2->HijoIzq=ApAux1;
   if (ApAux2->FE==-1)
      Apunt->FE=1;
   else
      Apunt->FE=0;
   if (ApAux2->FE==1)
      ApAux1->FE=-1;
   else
      ApAux1->FE=0;
   return ApAux2;
}

/* M�todo que realiza la rotaci�n compuesta HD-HI en un �rbol AVL. Adem�s,
   reasigna los FE de los nodos involucrados en la rotaci�n. */
template <class T>
NodoArbolAVL<T> *ArbolAVL<T>::RotacionHD_HI(NodoArbolAVL<T> *Apunt, NodoArbolAVL<T> *ApAux1)
{
   NodoArbolAVL<T> *ApAux2;
   ApAux2=ApAux1->HijoIzq;
   Apunt->HijoDer=ApAux2->HijoIzq;
   ApAux2->HijoIzq=Apunt;
   ApAux1->HijoIzq=ApAux2->HijoDer;
   ApAux2->HijoDer=ApAux1;
   if (ApAux2->FE==1)
      Apunt->FE=-1;
   else
      Apunt->FE=0;
   if (ApAux2->FE==-1)
      ApAux1->FE=1;
   else
      ApAux1->FE=0;
   return ApAux2;
}

/* M�todo que inserta un nuevo elemento en un �rbol AVL. Recibe como par�metros
   el dato a insertar, un apuntador al nodo a visitar (la primera vez es la
   raiz) y un entero (Band) que la primera vez tiene el valor 0. */
template <class T>
void ArbolAVL<T>::InsertaAVL(T Dato, NodoArbolAVL<T> *Apunt, int *Band)
{
   NodoArbolAVL<T> *ApAux1, *ApAux2;
   if (Apunt!=NULL)
   {
      if (Dato<Apunt->Info)
      {
         /* Se invoca el m�todo con el subarbol izq.*/
         InsertaAVL(Dato, Apunt->HijoIzq, Band);
         Apunt->HijoIzq=Raiz;
         if (0<*Band)   /* Verifica si crecio el subarbol izquierdo.*/
            switch (Apunt->FE)
            {
               case 1: {
                         Apunt->FE=0;
                         *Band=0;
                         break;
                       }
               case 0: {
                         Apunt->FE=-1;
                         break;
                       }
               case -1: {
                          ApAux1=Apunt->HijoIzq;
                          if (ApAux1->FE<=0)
                             Apunt=RotacionHI_HI(Apunt, ApAux1);
                          else
                             Apunt=RotacionHI_HD(Apunt, ApAux1);
                          Apunt->FE=0;
                          *Band=0;
                        }
            }
      }
      else
         if (Dato>Apunt->Info)
         {
           /* Invoca el m�todo con el subarbol derecho. */
           InsertaAVL(Dato, Apunt->HijoDer, Band);
		   Apunt->HijoDer=Raiz;
           if (0<*Band)   /* Verifica si crecio el subarbol derecho. */
             switch (Apunt->FE)
             {
                case -1: {
                          Apunt->FE=0;
                          *Band=0;
                          break;
                        }
                case 0: {
                          Apunt->FE=1;
                          break;
                        }
                case 1: {
                          ApAux1=Apunt->HijoDer;
                          if (ApAux1->FE>=0)
                             Apunt=RotacionHD_HD(Apunt, ApAux1);
                          else
                             Apunt=RotacionHD_HI(Apunt, ApAux1);
                          Apunt->FE=0;
                          *Band=0;
                         }
             }
         }
         Raiz=Apunt;
   }
   else
   {
      /* Inserta un nuevo nodo y actualiza el valor de Band indicando que el
         arbol crecio. */
      ApAux2=new NodoArbolAVL<T>();
      ApAux2->Info=Dato;
      ApAux2->FE=0;
      *Band=1;
      Raiz=ApAux2;
   }
}

/* Metodo auxiliar del metodo EliminaAVL que reestructura el �rbol cuando la
   altura de la rama izquierda ha disminuido. */
template <class T>
NodoArbolAVL<T>* ArbolAVL<T>::ReestructuraI(NodoArbolAVL<T> *Nodo, int *Aviso)
{
   NodoArbolAVL<T> *ApAux;
   if (*Aviso>0)
   {
     switch (Nodo->FE)
     {
        case -1: Nodo->FE=0;
                 break;
        case 0:  Nodo->FE=1;
                 break;
        case 1:  ApAux=Nodo->HijoDer;
                 if (ApAux->FE>=0) // Rotacion HD-HD
                 {
                    Nodo->HijoDer=ApAux->HijoIzq;
                    ApAux->HijoIzq=Nodo;
                    switch (ApAux->FE)
                    {
                       case 0: Nodo->FE=1;
                               ApAux->FE=-1;
                               *Aviso=0;
                               break;
                       case 1: Nodo->FE=0;
                               ApAux->FE=0;
                               break;
                    }
                    Nodo=ApAux;
                 }
                 else   // Rotacion HD-HI
                 {
                    Nodo=RotacionHD_HI(Nodo, ApAux);
                    Nodo->FE=0;
                 }
                 break;
     }
   }
   return Nodo;
}

/* Metodo auxiliar del metodo EliminaAVL que reestructura el �rbol cuando la
   altura de la rama derecha ha disminuido. */
template <class T>
NodoArbolAVL<T>* ArbolAVL<T>::ReestructuraD(NodoArbolAVL<T> *Nodo, int *Aviso)
{
   NodoArbolAVL<T> *ApAux;
   if (*Aviso>0)
   {
     switch (Nodo->FE)
     {
        case 1:  Nodo->FE=0;
                 break;
        case 0:  Nodo->FE=-1;
                 *Aviso=0;
                 break;
        case -1: ApAux=Nodo->HijoIzq;
                 if (ApAux->FE<=0) // Rotacion HI-HI
                 {
                    Nodo->HijoIzq=ApAux->HijoDer;
                    ApAux->HijoDer=Nodo;
                    switch (ApAux->FE)
                    {
                       case 0: Nodo->FE=-1;
                               ApAux->FE=1;
                               *Aviso=0;
                               break;
                       case -1:Nodo->FE=0;
                               ApAux->FE=0;
                               break;
                    }
                    Nodo=ApAux;
                 }
                 else   // Rotacion HI-HD
                 {
                    Nodo=RotacionHI_HD(Nodo, ApAux);
                    Nodo->FE=0;
                 }
                 break;
     }
   }
   return Nodo;
}

/* M�todo auxiliar del m�todo EliminaAVL que sustituye el elemento que se desea
   eliminar por el que se encuentra m�s a la derecha del sub�rbol izquierdo. */
template <class T>
void ArbolAVL<T>::Sustituye(NodoArbolAVL<T> *Nodo, NodoArbolAVL<T> *ApAux, int *Avisa)
{
   if (Nodo->HijoDer!=NULL)
   {
      Sustituye(Nodo->HijoDer, ApAux, Avisa);
      if (ApAux->HijoIzq==NULL)
         Nodo->HijoDer=NULL;
      else
         Nodo->HijoDer=ApAux->HijoIzq;
      Nodo=ReestructuraD(Nodo, Avisa);
   }
   else
   {
      ApAux->Info=Nodo->Info;
      Nodo=Nodo->HijoIzq;
      *Avisa=1;
   }
   ApAux->HijoIzq=Nodo;
}

/* M�todo que elimina un elemento en un �rbol AVL. Luego de la eliminaci�n se
   actualizan los factores de equilibrio de cada nodo hasta la ra�z y se
   reestructura el �rbol si fuera necesario. */
template <class T>
void ArbolAVL<T>::EliminaAVL(NodoArbolAVL<T> *Apunt, NodoArbolAVL<T> *ApAnt, int *Avisa, T Dato)
{
   NodoArbolAVL<T> *ApAux;
   int Bandera;
   if (Apunt!=NULL)
     if (Dato<Apunt->Info)
     {
        if (*Avisa>0)
          Bandera=1;
        else
          if (*Avisa!=0)
            Bandera=-1;
        *Avisa=-1;
        EliminaAVL(Apunt->HijoIzq, Apunt, Avisa, Dato);
        Apunt=ReestructuraI(Apunt, Avisa);
        if (ApAnt!=NULL)
          switch(Bandera)
          {
            case -1: ApAnt->HijoIzq=Apunt;
                     break;
            case 1:  ApAnt->HijoDer=Apunt;
                     break;
            default: break;
          }
        else
          Raiz=Apunt;
     }
     else
     {
       if (Dato>Apunt->Info)
       {
          if (*Avisa<0)
             Bandera=-1;
          else
             if (*Avisa!=0)
                Bandera=1;
          *Avisa=1;
          EliminaAVL(Apunt->HijoDer, Apunt, Avisa, Dato);
          Apunt=ReestructuraD(Apunt, Avisa);
          if (ApAnt!=NULL)
            switch (Bandera)
            {
               case -1: ApAnt->HijoIzq=Apunt;
                        break;
               case 1:  ApAnt->HijoDer=Apunt;
                        break;
               default: break;
            }
          else
            Raiz=Apunt;
       }
       else
       {
          ApAux=Apunt;
          if (ApAux->HijoDer==NULL)
          {
             Apunt=ApAux->HijoIzq;
             if (*Avisa!=0)
                if (*Avisa<0)
                   ApAnt->HijoIzq=Apunt;
                else
                   ApAnt->HijoDer=Apunt;
             else
                if (Apunt==NULL)
                   Raiz=NULL;
                else
                   Raiz=Apunt;
                *Avisa=1;
          }
          else
             if (ApAux->HijoIzq==NULL)
             {
                Apunt=ApAux->HijoDer;
                if (*Avisa!=0)
                  if (*Avisa<0)
                     ApAnt->HijoIzq=Apunt;
                  else
                     ApAnt->HijoDer=Apunt;
                else
                  if (Apunt==NULL)
                     Raiz=NULL;
                  else
                     Raiz=Apunt;
                *Avisa=1;
             }
             else
             {
                 Sustituye(ApAux->HijoIzq, ApAux, Avisa);
                 Apunt=ReestructuraI(Apunt, Avisa);
                 if (ApAnt!=NULL)
                    if (*Avisa<=0)
                       ApAnt->HijoIzq=Apunt;
                    else
                       ApAnt->HijoDer=Apunt;
                 else
                    Raiz=Apunt;
             }
     }
     }
     else
       cout << "\n\nEl dato a eliminar no se encuentra!.\n\n";
}

void printbyRegion(NodoArbolAVL<Insecto> *root, string& region)
{
    if(root)
    {
        printbyRegion(root->HijoIzq, region);
        if(root->Info.getRegion() == region )
            root->Info.printInsecto();
        printbyRegion(root->HijoDer, region);
    }
}

void printbyLoc(NodoArbolAVL<Insecto> *root, string &loc)
{
    if(root)
    {
        printbyLoc(root->HijoIzq, loc);
        if(root->Info.getLoc() == loc)
            root->Info.printInsecto();
        printbyLoc(root->HijoDer, loc);
    }
}


void printbyAlimento(NodoArbolAVL<Insecto> *root, string &alimento)
{
    if(root)
    {
        printbyAlimento(root->HijoIzq, alimento);
        if(root->Info.getAlimento() == alimento)
            root->Info.printInsecto();
        printbyAlimento(root->HijoDer, alimento);
    }
}

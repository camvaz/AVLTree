#include "AVLTree.h"

int main()
{

    ArbolAVL<Insecto> Arbol;
    NodoArbolAVL<Insecto> *auxRoot = Arbol.RegresaRaiz();
    Insecto auxInsecto;
    char auxSearchKey[MAX_IDSIZE];
    string auxSearchCKey;
    int opc;
    char dale;
    int Band;
    bool flag = true;

    string a, b, c, d;

    a = "Herrerillo";
    b = "Gusanos";
    c = "Mediterraneo Europeo";
    d = "Europa";

    auxInsecto.setParameters(142, a, b, c, d);
    Arbol.InsertaAVL(auxInsecto, auxRoot, &Band);

    a = "Escorpion";
    b = "Hormigas";
    c = "Desierto de Rub Al-Jali";
    d = "Oriente Medio";

    Band = 0;
    auxRoot = Arbol.RegresaRaiz();
    auxInsecto.setParameters(166, a,b,c,d);
    Arbol.InsertaAVL(auxInsecto, auxRoot, &Band);

    a = "Tarantula";
    b = "Moscas";
    c = "Desierto de Sonora";
    d = "Norteamerica";

    Band = 0;
    auxRoot = Arbol.RegresaRaiz();
    auxInsecto.setParameters(255, a,b,c,d);
    Arbol.InsertaAVL(auxInsecto, auxRoot, &Band);


    a = "Hormiga australiana";
    b = "Hojas";
    c = "Australia";
    d = "Oceania";

    Band = 0;
    auxRoot = Arbol.RegresaRaiz();
    auxInsecto.setParameters(412, a,b,c,d);
    Arbol.InsertaAVL(auxInsecto, auxRoot, &Band);

    int idAux;
    string nombreAux, alimentoAux, locAux, regionAux;


    clear();

    while(flag)
    {
        //MENU
        cout<<'\t'<<'\t'<<'\t'<<"REGISTRO DE INSECTOS"<<endl<<endl;
        cout<<'\t'<<"Opciones: "<<endl<<endl;
        cout<<'\t'<<'\t'<<"Registrar nuevo insecto: 1"<<endl;
        cout<<'\t'<<'\t'<<"Eliminar Insecto: 2"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte de todos los insectos: 3"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte por area: 4"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte por localizacion: 5"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte por alimentacion: 6"<<endl;
        cout<<'\t'<<'\t'<<"Salir: 7"<<endl<<endl;


        cout<<'\t'<<"Ingrese una opcion: ";


        cin>>opc;
        clear();
        cout<<endl;

        switch(opc)
        {
            case 1:

                Band = 0;
                auxRoot = Arbol.RegresaRaiz();
//                auxInsecto.writeParameters();

                cout << "\t\tNUEVO INSECTO\n\n";
                cout << "Ingrese el ID del insecto: \n\t";
                cin >> idAux;
                cout << "\n\nIngrese el nombre del insecto:\n\t";
                cin.ignore();
                getline(cin, nombreAux);
                cout << "\n\nIngrese alimentacion del insecto:\n\t";
                getline(cin, alimentoAux);
                cout << "\n\nIngrese localizacion:\n\t";
                getline(cin, locAux);
                cout << "\n\nIngrese area:\n\t";
                getline(cin, regionAux);

                auxInsecto.setParameters(idAux, nombreAux, alimentoAux, locAux, regionAux);
                Arbol.InsertaAVL(auxInsecto, auxRoot, &Band);
                cout << "\n\tInsecto insertado con exito. Imprimiendo a continuacion... \n";
                auxInsecto.printInsecto();

                cout<<"\nDesea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;
                clear();
                break;

            case 2:

                cout<<"Inserta ID del insecto a eliminar: ";

                auxInsecto.setID();
                cout << auxInsecto;
                Band = 0;
                auxRoot = Arbol.RegresaRaiz();

                Arbol.EliminaAVL(auxRoot, NULL, &Band, auxInsecto);

                cout<<endl<<"\n\nDesea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;
                clear();
                break;

            case 3:

                auxRoot = Arbol.RegresaRaiz();
                Arbol.Imprime(auxRoot);


                cout<<"\n\nDesea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 4:

                cout << "\n\tA continuacion, ingresa el area a buscar: ";
                cin.ignore();
                getline(cin, auxSearchCKey);
                auxRoot = Arbol.RegresaRaiz();
                printbyRegion(auxRoot, auxSearchCKey);

                cout<<"\n\nDesea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 5:

                cout << "\n\tA continuacion, ingresa la localizacion a buscar: ";
                cin.ignore();
                getline(cin, auxSearchCKey);
                auxRoot = Arbol.RegresaRaiz();
                printbyLoc(auxRoot, auxSearchCKey);

                cout<<"\n\n\nDesea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 6:

                cout << "\n\tA continuacion, ingresa la alimentacion a buscar: ";
                cin.ignore();
                getline(cin, auxSearchCKey);
                auxRoot = Arbol.RegresaRaiz();
                printbyAlimento(auxRoot, auxSearchCKey);

                cout<<"\nSeguro que desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 7:

                cout<<"\nSeguro que desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            default:

                cout<<"Opcion invalida, intentar de nuevo"<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;
        }
    }

    return 0;

}

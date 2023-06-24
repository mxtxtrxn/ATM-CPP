#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
class dispensador{
 	private:
    long int NumeroCuenta;
    string Nombre;
    int PIN;
    double Saldo;
    string NumeroMovil;

    public:
    void setData(long int NumeroCuenta_a, string Nombre_a, int PIN_a, double Saldo_a,string NumeroMovil_a){

        NumeroCuenta = NumeroCuenta_a;
        Nombre = Nombre_a;
        PIN = PIN_a;
        Saldo = Saldo_a;
        NumeroMovil = NumeroMovil_a;
};

    long int ObtenerNumeroCuenta(){
        return NumeroCuenta;

    }

    string ObtenerNombre(){
        return Nombre;
    }
    int ObtenerPIN(){

        return PIN;

    }
    double ObtenerSaldo(){
        return Saldo;
    }
    string ObtenerNumeroMovil(){

        return NumeroMovil;
    }

    void ActualizarNumeroMovil(string Num_viejo, string Num_nuevo){

        if(Num_viejo== NumeroMovil){
            NumeroMovil = Num_nuevo;
            cout<<endl<<"Numero actualizado exitosamente";
            _getch();
        }
    else{
        cout<<endl<<"Error!!! Numero antiguo";
        _getch();

    }
}
    void RetirarDinero(int cantidad_a){
    	

        if(cantidad_a > 0 && cantidad_a < Saldo ){

            Saldo -= cantidad_a;
            cout << endl << "Retire su dinero, por favor";
            cout << endl << "Saldo disponible: "<< Saldo; 
            _getch();
            

        }
        else{

            cout << endl << "Cantidad erronea o saldo insuficiente";
            _getch();
        }
    }
};
    
    
    int main(int argc, char** argv){
        int Opcion=0, numeroPIN;
        long int guardaNumeroCuenta;
        system("cls");
        //usuario creado (objeto)
        dispensador usuario1;
        usuario1.setData(1234567,"Andrea", 1111, 60000,"4621234567");
        do{
            system("cls");
            cout<< endl << "BIENVENIDO"<< endl;
            cout<< endl <<"Introduce tu numero de cuenta: ";
            cin >> guardaNumeroCuenta;
            cout<< endl << "Introduce tu PIN: ";
            cin >> numeroPIN;
            // revisar si los valores introducidos coinciden con los datos de usuario
            if ((guardaNumeroCuenta == usuario1.ObtenerNumeroCuenta()) && (numeroPIN == usuario1.ObtenerPIN())){
                do{
                    int cantidad= 0;
                    string NumeroMovil_viejo, NumeroMovil_nuevo;
                    system("cls");
                    //Interfaz de usuario
                    cout<< endl << "BIENVENIDO"<< endl;
                    cout<< endl << "Seleccion de opciones";
                    cout<< endl << "1. revisar saldo";
                    cout<< endl << "2. Retirar dinero";
                    cout<< endl << "3. Detalles de usuario";
                    cout<< endl << "4. Actualizar el numero movil";
                    cout<< endl << "5. Salir \n";
                    cin >> Opcion;


                    switch(Opcion){
                        case 1:
                        cout << endl << "Tu saldo es de: "<<usuario1.ObtenerSaldo();
                        _getch();
                        break;

                        case 2:
                        cout<< endl << "Introduce la cantidad: ";
                        cin >> cantidad;
                        usuario1.RetirarDinero(cantidad);
                        break;

                        case 3: 
                        cout<< endl << "Los detalles del usuario son: ";
                        cout<< endl << "-> Numero de cuenta: "<< usuario1.ObtenerNumeroCuenta();
                        cout<< endl << "-> Nombre: "<< usuario1.ObtenerNombre();
                        cout<< endl << "-> Saldo: "<< usuario1.ObtenerSaldo();
                        cout<< endl << "-> Numero: "<< usuario1.ObtenerNumeroMovil();
                        _getch();
                        break;

                        case 4:
                        cout<< endl << "Introduce tu numero anterior: ";
                        cin>> NumeroMovil_viejo;

                        cout<< endl << "introduce tu numero nuevo: ";
                        cin>> NumeroMovil_nuevo;
                        usuario1.ActualizarNumeroMovil(NumeroMovil_viejo, NumeroMovil_nuevo);
                        break;

                        case 5:
                        exit(0);

                        default:
                        cout<< endl << "Introduce informacion valida";
						break;
                    } 

                }while(1);

            }
        }while(1);
        return 0;
}




// program_base.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <time.h>
#include <Windows.h>
#include <string>

using namespace std;

class Analizador {
public:
    char lenguaje[18] = {'a','u','t','o','m','s','p','r','g','r','c','i','n','f','l','e','s','j',};//este sera [SIGMA],lenguaje
public://estos arreglos seran W, palabras
    char cadena_aceptada_1[12]{ 'p','r','o','g','r','a','m','a','c','i','o','n' };char *puntero_aceptacion_1 = cadena_aceptada_1;
    char cadena_aceptada_2[9]{ 'a','u','t','o','m','a','t','a','s' }; char* puntero_aceptacion_2 = cadena_aceptada_2;
    char cadena_aceptada_3[8]{ 'f','o','r','m','a','l','e','s'}; char* puntero_aceptacion_3 = cadena_aceptada_3;
    char cadena_aceptada_4[9]{ 'l','e','n','g','u','a','j','e','s' }; char* puntero_aceptacion_4 = cadena_aceptada_4;
    
private:
    char caracter = ' ';
public:
    string cadena_interna = "";
public:
    Analizador() { this->caracter = caracter;}

    void transicion(char* diagrama, int tabla) {
        for (int a = 0; a < tabla; a++)
        {
            if (diagrama[a] != NULL && diagrama[a] != ' ')
            {
                std::cout << "\t**\t\t*\n\t**\t      *\n\t**           *\n"; Sleep(150);
                std::cout << "******************" << endl; Sleep(150);
                std::cout << "**\t\t**" << endl; Sleep(150);
                std::cout << "**\t" << diagrama[a] << "\t**  *" << endl; Sleep(150);
                std::cout << "**\t\t**   *" << endl; Sleep(150);
                std::cout << "******************    *   " << diagrama[a + 1] << endl; Sleep(150);
                Sleep(100);
            }
            else
            {
                break;
            }
        }
    }
};

class Tablas_transicion {
public:
    Tablas_transicion() {}

public:
    void generador(char *filas,int columnas) {
        std::cout << "\n\n";
        std::cout << "\tDiagrama de transicion\n\n";
        for (int a = 0; a < columnas; a++)
        {
            if (filas[a] != NULL)
            {
                std::cout << " *-* |"<<filas[a]<<"| *-* |";
            }
            else
            {
                break;
            }
        }
        std::cout << endl;
        string difference = "| *-* | *-* |";
        for (int b = 0; b < columnas; b++)
        {
            if (filas[b] != NULL)
            {
                std::cout <<" *-* |"<<filas[b]<<difference<<filas[b+1]<<difference <<endl;
            }
            else
            {
                break;
            }
            difference += " | *-* | *-* |";
        }
    }

};



int main(int argc,char *argv[])
{
    std::cout << "\t\t\tBienvenido al programa\nEste es un automata finito determinista.\nY determina si una cadena pertenece a las expresiones regulares del lenguaje\npero no todas finalizan en el estado de aceptacion por su naturaleza";
    std::cout << "\nPor favor, ingrese una cadena y compruebe si el automata lo acepta.\n";
    std::cout << "\nEntre las cadenas aceptadas se encuentran:"
        <<"\nPROGRAMACION\nLENGUAJES\nAUTOMATAS\nFORMALES\n";
    char cadena[CHAR_MAX];
    std::cin >> cadena; std::cout << endl;
    char *puntero_cadena = &*cadena;
    
    Analizador conexion;
    Tablas_transicion conexion_2;
    
    //algoritmo de aceptacion, no admite caracteres ajenos al lenguaje definido
    for (short i = 0; i < CHAR_MAX; i++)
    {
        if (cadena[i] != ' ' && cadena[i] != NULL)
        {
        for (short a = 0; a < 18; a++)
        {
                if (conexion.lenguaje[a] == cadena[i])
                {
                    conexion.cadena_interna += cadena[i];
                    break;
                } 
            }
        }
        else { continue; }
    }
    //valores en formato cadena de texto
    string auxiliar_1 = &*puntero_cadena;
    string auxiliar_2 = &*conexion.puntero_aceptacion_1;
    string auxiliar_3 = &*conexion.puntero_aceptacion_2;
    string auxiliar_4 = &*conexion.puntero_aceptacion_3;
    string auxiliar_5 = &*conexion.puntero_aceptacion_4;
    
    //proceso de verificacion si el automata llega a un estado de aceptacion o solo acepta la cadena para un estado neutro
        if (*puntero_cadena != *conexion.puntero_aceptacion_1 && *puntero_cadena != *conexion.puntero_aceptacion_2 && *puntero_cadena != *conexion.puntero_aceptacion_3 && *puntero_cadena != *conexion.puntero_aceptacion_4)
        {
            conexion.transicion(&*puntero_cadena, 12);
            std::cout << "La cadena es aceptada, pero no llega al estado esperado.";
            conexion_2.generador(&*puntero_cadena, 12);
        }
        else if (*conexion.puntero_aceptacion_1 == *puntero_cadena)
        {
            conexion.transicion(&*puntero_cadena, 12);
            conexion_2.generador(&*puntero_cadena, 12);
        }
        else if (*conexion.puntero_aceptacion_2 == *puntero_cadena)
        {
            conexion.transicion(&*puntero_cadena, 9);
            conexion_2.generador(&*puntero_cadena, 9);
        }
        else if (*conexion.puntero_aceptacion_3 == *puntero_cadena)
        {
            conexion.transicion(&*puntero_cadena, 8);
            conexion_2.generador(&*puntero_cadena, 8);
        }
        else if (*conexion.puntero_aceptacion_4 == *puntero_cadena)
        {
            conexion.transicion(&*puntero_cadena, 9);
            conexion_2.generador(&*puntero_cadena, 9);
        }
        else 
        {
            std::cout << "CADENA RECHAZADA POR EL AUTOMATA";
        }

        std::cout << "\n\t\t\tCadena formada con las letras pertenecientes al lenguaje\n\t\t" << conexion.cadena_interna << "\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

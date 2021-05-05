#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
/*
Desarrollar un programa que permita guardar los datos de 5 alumnos.
Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
Se debe utilizar estructuras, permitiendo al usuario trabajar con los datos a través de un ABM.
*/
#define TAM 3
int main()
{
    eAlumno alumnos[TAM];
    int seguir=0;
    int posicionAlta;
    int posicionBaja;
    int posicionModificar;
    int legajo=1000;
    int flagInicializar=0;
    int flagAlta=0;
    int error;
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(inicializarAlumnos(alumnos, TAM)==1)
            {
                printf("Inicializado con exito\n");
                flagInicializar=1;
            }
            break;
        case 2:
            if(flagInicializar!=1)
            {
                printf("Hay que inicializar para cargar\n");
            }
            else
            {
                posicionAlta=buscarAlumnoVacio(alumnos, TAM, &error);
                if(error==1)
                {
                    flagAlta=1;
                    altaAlumno(alumnos, TAM, posicionAlta,legajo);
                    legajo++;
                }
                else
                {
                    printf("No encontre espacio vacio\n");
                }
            }
            break;
        case 3:
            if(flagAlta!=1)
            {
                printf("No hay alumnos cargados\n");
            }
            else
            {
                mostrarAlumnos(alumnos,TAM);
            }
            break;
        case 4:
            if(flagAlta!=1)
            {
                printf("No hay alumnos cargados\n");
            }
            else
            {
                posicionBaja=bajaAlumno(alumnos, TAM);
                if(posicionBaja==1)
                {
                    printf("Baja exitosa\n");
                }
                else
                {
                    printf("No se encontro la posicion\n");
                }
            }
            break;
        case 5:
            if(flagAlta!=1)
            {
                printf("No hay alumnos cargados\n");
            }
            else
            {
                posicionModificar = moficicarAlumno(alumnos, TAM);
                if(posicionModificar!=1)
                {
                    printf("No se pudo moficar\n");
                }
            }
            break;
        case 6:
            if(flagAlta!=1)
            {
                printf("No hay alumnos cargados\n");
            }
            else
            {
                switch(subMenuOrdenar())
                {
                case 1:
                    ordenarPorApellido(alumnos, TAM);
                    printf("Ordenamiento por apellido exitoso\n");
                    break;
                case 2:
                    ordenarPorEdad(alumnos, TAM);
                    printf("Ordenamiento por edad exitoso\n");
                    break;
                case 3:
                    ordenarPorPromedio(alumnos, TAM);
                    printf("Ordenamiento por promedio exitoso\n");
                    break;
                }
            }
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
        system("pause");
    }
    while(seguir==0);

    return 0;
}

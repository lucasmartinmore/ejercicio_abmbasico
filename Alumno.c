#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"

int menu()
{
    int opcion;
    printf("-----MENU-----\n\n");
    printf("1) INICIALIZAR\n");
    printf("2) ALTAS\n");
    printf("3) LISTAR\n");
    printf("4) BAJA\n");
    printf("5) MODIFICAR\n");
    printf("6) ORDENAR\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>6)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int inicializarAlumnos(eAlumno alumnos[], int tam)
{
    int error=-1;
    if(alumnos!=NULL && tam>0)
    {
        error=1;
        for(int i=0; i<tam; i++)
        {
            alumnos[i].isEmpty=1;
        }
    }
    return error;
}

void mostrarAlumno(eAlumno alumno)
{
    printf("LEGAJO  SEXO  EDAD  NOTA1  NOTA2  PROMEDIO  APELLIDO  EMPIEZO\n");
    printf("%d      %c     %d    %d      %d       %.2f     %s       %d\n",alumno.legajo,alumno.sexo,
           alumno.edad,alumno.nota1,alumno.nota2,alumno.promedio,
           alumno.apellido,alumno.isEmpty);
}

int mostrarAlumnos(eAlumno alumnos[], int tam)
{
    int error=-1;
    if(alumnos!=NULL && tam>0)
    {
        error=0;
        for(int i=0; i<tam; i++)
        {
            if(alumnos[i].isEmpty==0)
            {
                mostrarAlumno(alumnos[i]);
            }
        }
    }
    return error;
}

int buscarAlumnoVacio(eAlumno alumnos[], int tam, int* error)
{
    *error=-1;
    int posicion=-1;
    if(alumnos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(alumnos[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaAlumno(eAlumno alumnos[], int tam, int posicion, int legajo)
{
    int error=-1;
    if((alumnos!=NULL && tam>0) && posicion>-1)
    {
        alumnos[posicion].isEmpty=0;

        alumnos[posicion].legajo = legajo;

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &alumnos[posicion].sexo);

        printf("ingrese edad: ");
        scanf("%d", &alumnos[posicion].edad);

        printf("ingrese nota1: ");
        scanf("%d", &alumnos[posicion].nota1);

        printf("ingrese nota2: ");
        scanf("%d", &alumnos[posicion].nota2);

        alumnos[posicion].promedio=(float)(alumnos[posicion].nota1+alumnos[posicion].nota2)/2;

        printf("ingrese apellido: ");
        fflush(stdin);
        gets(alumnos[posicion].apellido);
        error=1;
    }
    return error;
}

int buscarAlumno(eAlumno alumno[], int tam)
{
    int posicion;
    int error=-1;
    if(alumno!=NULL && tam>0)
    {
        printf("Ingrese posicion: ");
        scanf("%d", &posicion);
        for(int i=0; i<tam; i++)
        {
            if(alumno[i].legajo == posicion)
            {
                mostrarAlumno(alumno[i]);
                error=0;
            }
        }
    }
    return error;
}

int subMenuModificar()
{
    int opcion;
    system("cls");
    printf("-----MENU MODIFICAR-----\n\n");
    printf("1) APELLIDO\n");
    printf("2) SEXO\n");
    printf("3) EDAD\n\n");
    printf("Que deseas modificar: "),
           scanf("%d", &opcion);
    while(opcion<1 || opcion >3)
    {
        printf("Error, que deseas modificar: "),
               scanf("%d", &opcion);
    }
    return opcion;
}

int bajaAlumno(eAlumno alumnos[], int tam)
{
    int posicion;
    int error=-1;
    if(alumnos!=NULL && tam>0)
    {
        printf("Ingrese legajo a dar de baja: ");
        scanf("%d", &posicion);
        while(posicion<1000)
        {
            printf("Incorrecto. Ingres nueva pos: ");
            scanf("%d", &posicion);
        }
        for(int i=0; i<tam; i++)
        {
            if(alumnos[i].legajo==posicion)
            {
                error=1;
                alumnos[i].isEmpty=1;
            }
        }
    }
    return error;
}

int moficicarAlumno(eAlumno alumnos[], int tam)
{
    int posicion;
    char nuevoApellido[20];
    char nuevoSexo;
    int nuevaEdad;
    int error=-1;
    if(alumnos!=NULL && tam>0)
    {
        printf("Ingrese legajo a dar de baja: ");
        scanf("%d", &posicion);
        while(posicion<1000)
        {
            printf("Incorrecto. Ingres nueva pos: ");
            scanf("%d", &posicion);
        }
        for(int i=0; i<tam; i++)
        {
            if(alumnos[i].legajo==posicion)
            {
                switch(subMenuModificar())
                {
                case 1:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(nuevoApellido);
                    strcpy(alumnos[i].apellido, nuevoApellido);
                    printf("Cambio apellido exitoso\n");
                    error=1;
                    break;
                case 2:
                    printf("Ingrese nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &nuevoSexo);
                    alumnos[i].sexo = nuevoSexo;
                    printf("Cambio de sexo exitoso\n");
                    error=1;
                    break;
                case 3:
                    printf("Ingrese nueva edad: ");
                    scanf("%d", &nuevaEdad);
                    alumnos[i].edad = nuevaEdad;
                    printf("Cambio de edad exitoso\n");
                    error=1;
                    break;
                default:
                    printf("Opcion incorrecta\n");
                    break;
                }
            }
        }
    }
    return error;
}

int subMenuOrdenar()
{
    int opcion;
    system("cls");
    printf("-----MENU ORDENAR-----\n\n");
    printf("1) POR APELLIDO\n");
    printf("2) POR EDAD\n");
    printf("3) POR PROMEDIO\n\n");
    printf("Porque criterio deseas ordenar: "),
    scanf("%d", &opcion);
    while(opcion<1 || opcion >3)
    {
        printf("Error, porque criterio deseas ordenar: "),
        scanf("%d", &opcion);
    }
    return opcion;
}

void ordenarPorApellido(eAlumno alumnos[], int tam)
{
    eAlumno aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(alumnos[i].apellido, alumnos[j].apellido)>0)
            {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = aux;
            }
        }
    }
}

void ordenarPorEdad(eAlumno alumnos[], int tam)
{
    eAlumno aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(alumnos[i].edad > alumnos[j].edad)
            {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = aux;
            }
        }
    }
}

void ordenarPorPromedio(eAlumno alumnos[], int tam)
{
    eAlumno aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(alumnos[i].promedio > alumnos[j].promedio)
            {
                aux = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = aux;
            }
        }
    }
}




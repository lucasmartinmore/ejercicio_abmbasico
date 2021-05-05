#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
    int legajo;
    char sexo;
    int edad;
    int nota1;
    int nota2;
    float promedio;
    char apellido[25];
    int isEmpty;
} eAlumno;

#endif // ALUMNO_H_INCLUDED

int menu();
int inicializarAlumnos(eAlumno alumnos[], int tam);
int mostrarAlumnos(eAlumno alumnos[], int tam);
void mostrarAlumno(eAlumno alumno);
int buscarAlumnoVacio(eAlumno alumnos[], int tam, int* error);
int altaAlumno(eAlumno alumnos[], int tam, int posicion, int legajo);
int buscarAlumno(eAlumno alumno[], int tam);
int subMenuModificar();
int bajaAlumno(eAlumno alumnos[], int tam);
int moficicarAlumno(eAlumno alumnos[], int tam);
void ordenarPorApellido(eAlumno alumnos[], int tam);
void ordenarPorEdad(eAlumno alumnos[], int tam);
void ordenarPorPromedio(eAlumno alumnos[], int tam);
int subMenuOrdenar();

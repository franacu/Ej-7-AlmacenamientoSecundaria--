//Escribir un archivo que elimine un número de línea específico dentro de un archivo
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int main()
{
   char *archivo="ejercicio7.txt";
   FILE *fp;
   fp= fopen(archivo,"a");
   if(fp==NULL)
   {
       printf("No se abrio con exito\n");
       return -1;
   }
   fprintf(fp, "Línea 1\nLínea 2\nLínea 3\nLínea 4\nLínea 5\n");
   fclose(fp);

   int linea_a_eliminar = 3;  // Número de línea a eliminar
   fp = fopen(archivo, "r");
   FILE *temp = fopen("temp.txt", "w");
   char palabras[256];
   int cont= 1;

   while (fgets(palabras,sizeof(palabras),fp)!=NULL)
   {
       if (cont != linea_a_eliminar)
       {
           fputs(palabras, temp);
       }
       cont++;
    }
    remove(archivo);
    rename("temp.txt", archivo);

    printf("La línea %d ha sido eliminada con éxito.\n", linea_a_eliminar);

    return 0;
}
void eliminar(char num)
{

}
#include <stdio.h>
#include <string.h>
#include <dirent.h>
 
int main(int argc, char *argv[])
{
    if (argc==1) {
        printf("intenta usar: ./p1 PalabraABuscar \n \n Intenta De Nuevo \n");
        return 0;
    }

    char * searching = argv[1];
    struct dirent *de;  // Directorio target
    DIR *dr = opendir(".");
 
    if (dr == NULL)  //opendir debuelve NULL si no puede abrir el directo
    {
        printf("No se puede abrir el directorio" );
        return 0;
    }
 
    while ((de = readdir(dr)) != NULL) {
        if (strstr(de->d_name,searching) != NULL){
            printf("Encontre: %s\n", de->d_name);
		remove (de->d_name);
		printf("Elimine: %s\n", de->d_name);
	}
    } 
    closedir(dr);    
    return 0;
}

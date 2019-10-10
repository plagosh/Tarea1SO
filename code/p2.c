#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "p2_options.h" 

int main(int argc, char *argv[]) {
    // receiving command line arguments
    struct options opt;
    parseOptions(argc,argv,&opt);

    struct dirent *de;  // Folder pointers
    DIR *dr = opendir(opt.folder);
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("No encontre la carpeta solicitada :'(\n" );
        exit(EXIT_FAILURE);
    }

 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open searching folder" );
        exit(EXIT_FAILURE);
    }
 
    while ((de = readdir(dr)) != NULL) {

        if (strstr(de->d_name,opt.word) != NULL) {
            printf("FOUND: %s/%s\n",opt.folder,de->d_name);
            break;
        }

        else if (de->d_type == DT_DIR && 
            strcmp(de->d_name,".")!=0 && 
            strcmp(de->d_name,"..")!=0) {

            if (fork()==0) {
                char newFolder[300]; // extending current folder
                strcpy(newFolder,opt.folder);
                strcat(newFolder,"/");
                strcat(newFolder,de->d_name);

                char *argvf[5] = {argv[0],opt.word,"-f",newFolder,NULL}; 
                execv(argv[0],argvf);
                }
            }

    }
 
    closedir(dr);    
    return 0;
}

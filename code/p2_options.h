#ifndef P2_OPTIONS
#define P2_OPTIONS

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Struct declaration for usage in function's prototypes
struct options;

// Function's prototypes
void initOptions(struct options* opt);
void parseOptions(int argc, char* argv[], struct options* opt);
void usageAndExit();


struct options {
    char* word;
    char* folder;
};

void initOptions(struct options *opt) {
    // default options!!
    opt-> word = NULL; // no word
    opt-> folder = ".";
}


void parseOptions(int argc, char* argv[], struct options* opt) {
    int currentOption = 0;

    // Initialize options!
    opt-> folder = ".";

    if (argc > 1)
        opt->word = argv[1];
    else
        usageAndExit();

    // Pass through all the options
    // Starts from &(argv[1]) to avoid the first one (the searching word)
    // In coherence with that, getopt receives (argc-1) arguments
    // As just option 'f' receives an argument (the folder), in the list
    // of options ("f:h?") after the 'f' goes ':'
    while ( (currentOption = getopt(argc-1, &(argv[1]), "f:h?rif")) != -1) {
        int this_option_optind = optind ? optind : 1;
        switch (currentOption) {
            case 'f':
		opt->folder = optarg;
		printf("Opcion -f: Buscando '%s' en carpeta '%s'\n\n",opt->word,opt->folder);
                break;
            case 'h': 
		printf("Opciones\n\n");
		printf("-f: revisar en otro directorio\n");
		printf("-r: buscar en subcarpetas\n");
		printf("-i: eliminar todo lo que no este en el argumento\n");
		break;
            case '?': // help too
		printf("Para Ayuda escribe argumento -h\n");// help 
		break;
	    case 'r': 
		printf("caso r\n");// help 

		break;
            case 'i': // help too
		printf("caso i\n");// help 
		break;

            default:
                usageAndExit();
        }
    }

   
}

void usageAndExit() {
    printf("Usage: ./p2 wordToBeFound [-f seachingFolder] \n\nTry again\n");
    //exit(EXIT_FAILURE);
}

#endif // P2_OPTIONS

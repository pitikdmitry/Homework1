//Homework1 Var1;
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "words.h"

int main(int argc, char *argv[]) {

    if (argc != 3) 
    {
        printf("Usage: %s number_of_words_to_generate\n", argv[0]);
        return EXIT_FAILURE;
    }

    const int n_files= atoi(argv[2]);
	
    if(n_files <=0)
    {
	   printf("Usage: %s number_of_files must be >0\n", argv[0]);
	   return EXIT_FAILURE;
    }

    int mass[n_files];
    int result=0;

    for(int i=0;i<n_files;i++)
    {
        int n_words_to_generate;
        printf("enter the number of words in %d",(i+1) );
        printf(": ");
        scanf("%d", &n_words_to_generate);

        if (n_words_to_generate <= 0)
        {
            printf("Usage: %s number_of_words_to_generate\nnumber_of_words_to_generate must be > 0\n", argv[0]);   
        }
	
        const int source_data = generate_data_with_words(n_words_to_generate, argv[1]);

        if (!source_data) 
        {
            printf("Can't generate data\n");
            break;
        }
        
        mass[i]=source_data;
        result+=source_data;
    }

    int up=0;

    for(int i=0;i<n_files;i++) 
    {
	   up+=(mass[i] - (result/n_files)*(mass[i] - (result/n_files)));
    }

    float disp=0;
    disp=sqrt(up/(n_files-1));
    printf("%f",disp);

return EXIT_SUCCESS;
}
	



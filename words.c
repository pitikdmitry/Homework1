#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

static const char *generate_word() {
    static const char *uniq_words[] = {
        "go",
        "good",
        "great",
        "had",
        "has",
        "have",
        "he",
        "help",
        "her",
        "here",
        "him",
        "his"
    };
    const size_t uniq_words_n = sizeof(uniq_words) / sizeof(uniq_words[0]);
    return uniq_words[rand() % uniq_words_n];
}

const int generate_data_with_words(int needed_words_n,char *a) {
    int counter=0;   
    assert(needed_words_n);
 
    for (int i = 0; i < needed_words_n;i++) 
    {
        const char *next_word=generate_word();
        if(!strcmp(a, next_word))
        {
	       counter++;
        }
    }
    printf("%d",counter);
    printf("\n");
    return counter;
}



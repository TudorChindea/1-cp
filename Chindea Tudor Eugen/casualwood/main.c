#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 255
#define ACTORS 255
#define MAX 255
#define Max_length 255

typedef struct {
    char *title;
    char **cast;
    int movieCount;
} Hollywood;

void initializeMovies(Hollywood *movie) {
    movie->title = (char *) malloc(sizeof(char) * MAX_TITLE);
    movie->cast = (char **) malloc(sizeof(char *) * ACTORS);
    for (int i = 0; i < ACTORS; i++) {
        movie->cast[i] = (char *) malloc(sizeof(char) * MAX);
    }
}


int main() {
    FILE *f = fopen("input.txt", "r");
    Hollywood *movie = (Hollywood *) malloc(sizeof(Hollywood) * MAX);
    for (int i = 0; i < MAX; i++) {
        initializeMovies(&movie[i]);
    }
    char *strbuf = (char *) malloc(sizeof(char) * Max_length);
    char * actorName = (char*) malloc (sizeof(char)*Max_length);
    int count = 0;
    while (fgets(strbuf, Max_length, f) != NULL) {
        char *p;
        p = strtok(strbuf, ",");
        strcpy(movie[count].title, p);
        puts(movie[count].title);
        p = strtok(NULL, ",");
        while (p) {
            strcpy(movie[count].cast[movie[count].movieCount], p);
            puts(movie[count].cast[movie[count].movieCount]);
            movie[count].movieCount++;
            p = strtok(NULL, ",");
        }
        count++;
    }
    printf ("Enter the actor name: \n");
    scanf("%[^\n]",actorName);
    printf("You entered : %s",actorName);
    return 0;
}

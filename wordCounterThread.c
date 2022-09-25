#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 1024

clock_t start;
clock_t end;

float timeConsumed;

pthread_t thread1;
pthread_t thread2;
pthread_t thread3;
pthread_t thread4;
pthread_t thread5;

char word[16];

char filename[16];

FILE *fp = NULL;

int finalResult = 0;

// function that look for the word in a single line
int wordCounter(char *line) {

    int lineLenght = 0;
    int wordLengnt = 0;
    int counter = 0;
    int flag = 0;

    int i = 0;
    int j = 0;

    lineLenght = strlen(line);
    wordLengnt = strlen(word);

    for (i = 0; i <= lineLenght - wordLengnt; i++) {
        
        flag = 1;

        for (j = 0; j < wordLengnt; j++) {

            if (line[i + j] != word[j]) {

                flag = 0;

                break;

            }

        }

        // word found
        if (flag == 1) {

            counter++;

        }

    }

    return counter;

}

// function that open the file and read line by line
void * readFile(void *counter) {

    int result = *((int *) counter);   
    
    char buffer[MAX_LENGTH];

    // loop to read line by line
    while (fgets(buffer, MAX_LENGTH, fp)) {

        result += wordCounter(buffer);

    }

    printf("%i \n", result);

    finalResult += result;

    free(counter);

}

int main() {

    strcat(filename,  "bigText.txt");

    fp = fopen(filename, "r");

    strcat(word, "for");

    start = clock();

    int *counter1 = malloc(sizeof(*counter1));
    int *counter2 = malloc(sizeof(*counter2));
    int *counter3 = malloc(sizeof(*counter3));
    int *counter4 = malloc(sizeof(*counter4));
    int *counter5 = malloc(sizeof(*counter5));

    *counter1 = 0;
    *counter2 = 0;
    *counter3 = 0;
    *counter4 = 0;
    *counter5 = 0;

    // create threads
    pthread_create(&thread1, NULL, readFile, (void *)counter1);
    pthread_create(&thread2, NULL, readFile, (void *)counter2);
    pthread_create(&thread3, NULL, readFile, (void *)counter3);
    pthread_create(&thread4, NULL, readFile, (void *)counter4);
    pthread_create(&thread5, NULL, readFile, (void *)counter5);
    
    // wait until threads are done
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    fclose(fp);

    end = clock();

    timeConsumed = (float)(end - start) / CLOCKS_PER_SEC;

    printf("The word '%s' appears %d times in the text\n", word, finalResult);
    printf("Time consumed: %10.6f s\n", timeConsumed);

    return 0;

}

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

clock_t start;
clock_t end;

float timeConsumed;

char word[16];

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
int readFile() {

    char *filename = "bigText.txt";

    FILE *fp = fopen(filename, "r");

    int result = 0;
        
    char buffer[MAX_LENGTH];

    // loop to read line by line
    while (fgets(buffer, MAX_LENGTH, fp)) {

        result += wordCounter(buffer);

    }

    fclose(fp);

    return result;

}

int main() {
    
    int finalResult = 0;

    strcat(word, "for");

    start = clock();

    finalResult = readFile();

    end = clock();
    
    timeConsumed = (float)(end - start) / CLOCKS_PER_SEC;

    printf("The word '%s' appears %d times in the text\n", word, finalResult);
    printf("Time consumed: %10.6f s\n", timeConsumed);

    return 0;

}

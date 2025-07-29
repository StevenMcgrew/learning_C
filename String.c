#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char* chars;
    int length;
} String;

String* String_Create(char* string) {
    String* newString = (String*)malloc(sizeof(String));
    if (newString == NULL) {
        fprintf(stderr, "***ERROR in String_Create method***: Failed to allocate memory for a String pointer\n");
        exit(1);
    }

    int i = 0;
    while(string[i] != '\0') {
        i++;
    }

    newString->chars = string;
    newString->length = i;
    return newString;
}

void String_Destroy(String* string) {
    if (string != NULL) {
        free(string);
    }
}
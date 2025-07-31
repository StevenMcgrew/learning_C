#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char* chars;
    int length;
} String;

String* String_Create(const char* string) {
    if (string == NULL) {
        fprintf(stderr, "***ERROR in String_Create function***: NULL pointer was passed to the function but is not allowed\n");
        exit(1);
    }

    String* newString = (String*)malloc(sizeof(String));
    if (newString == NULL) {
        fprintf(stderr, "***ERROR in String_Create function***: Failed to allocate memory for the String\n");
        exit(1);
    }

    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    newString->length = len;
    
    newString->chars = (char*)malloc(len + 1);
    if (newString->chars == NULL) {
        free(newString);
        fprintf(stderr, "***ERROR in String_Create function***: Failed to allocate memory for the chars\n");
        exit(1);
    }
    
    int i = 0;
    while (string[i] != '\0') {
        newString->chars[i] = string[i];
        i++;
    }
    newString->chars[i] = '\0';
    
    return newString;
}

void String_Destroy(String* string) {
    if (string != NULL) {
        free(string->chars);
        free(string);
        string = NULL;
    }
}

String* String_Concat_And_Destroy(String* string1, String* string2) {
    if (string1 == NULL || string2 == NULL) {
        fprintf(stderr, "***ERROR in String_Concat_And_Destroy function***: NULL pointer was passed to the function but is not allowed\n");
        exit(1);
    }

    String* newString = (String*)malloc(sizeof(String));
    if (newString == NULL) {
        fprintf(stderr, "***ERROR in String_Concat_And_Destroy function***: Failed to allocate memory for the new String\n");
        exit(1);
    }

    int len = string1->length + string2->length;
    newString->length = len;
    
    newString->chars = (char*)malloc(len + 1);
    if (newString->chars == NULL) {
        free(newString);
        fprintf(stderr, "***ERROR in String_Concat_And_Destroy function***: Failed to allocate memory for the chars\n");
        exit(1);
    }

    for (int i = 0; i < string1->length; i++) {
        newString->chars[i] = string1->chars[i];
    }
    for (int i = 0; i < string2->length; i++) {
        newString->chars[string1->length + i] = string2->chars[i];
    }
    newString->chars[len] = '\0';

    String_Destroy(string1);
    String_Destroy(string2);
    
    return newString;
}

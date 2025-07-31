#include <stdio.h>
#include "String.c"



int main() {

    String* myString1 = String_Create("Hello, ");
    String* myString2 = String_Create("World!");
    
    printf("String content: %s\n", myString1->chars);
    printf("String length: %d\n", myString1->length);
    printf("String content: %s\n", myString2->chars);
    printf("String length: %d\n", myString2->length);

    String* combined = String_Concat_And_Destroy(myString1, myString2);

    printf("Combined content: %s\n", combined->chars);
    printf("Combined length: %d\n", combined->length);
    
    String_Destroy(combined);
    
    return 0;
}
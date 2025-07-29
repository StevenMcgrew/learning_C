#include <stdio.h>
#include "String.c"



int main()
{

    
    String* myStr = String_Create("Happy Birthday to you!");

    printf("length: %d\nstring: %s\n", myStr->length, myStr->chars);

    String_Destroy(myStr);

    return 0;
}
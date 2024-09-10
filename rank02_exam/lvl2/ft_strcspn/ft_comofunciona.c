#include <stdio.h>
#include <string.h>
 
#define SIZE 40
 
int main(void)
{
  char string[SIZE] = "Hola esta es una prueba";
  char * substring = "Hole";
 
  printf( "The first %li characters in the string \"%s\" "
          "are not in the string \"%s\" \n",
            strcspn(string, substring), string, substring);
 
}


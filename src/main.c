#include <stdio.h>
#include <stdlib.h>
#include "fhndlr.h"

void copy_string(char* dest, const char* src) 
{
    while (*src != '\0') 
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

#define BUFFER_SIZE 8192

int main() 
{

    FILE *file = fopen("../inputs/lorem.txt", "r");
    if (file == NULL) 
    {
        printf("Error: No se pudo abrir ../inputs/lorem.txt\n");
        return 1; 
    }

    char original_text[BUFFER_SIZE];
    size_t bytes_read = fread(original_text, 1, BUFFER_SIZE - 1, file);
    original_text[bytes_read] = '\0'; 
    fclose(file);


    char work_buffer[BUFFER_SIZE];

    copy_string(work_buffer, original_text);
    lowercase(work_buffer);

    FILE *f_lower = fopen("../build/out/lower.txt", "w");
    if (f_lower) 
    {
        fputs(work_buffer, f_lower);
        fclose(f_lower);
    }


    copy_string(work_buffer, original_text);
    uppercase(work_buffer);

    FILE *f_upper = fopen("../build/out/upper.txt", "w");
    if (f_upper) 
    {
        fputs(work_buffer, f_upper);
        fclose(f_upper);
    }

    copy_string(work_buffer, original_text);
    capitalize(work_buffer);
    
    FILE *f_cap = fopen("../build/out/capitalize.txt", "w");
    if (f_cap) 
    {
        fputs(work_buffer, f_cap);
        fclose(f_cap);
    }

    printf("Archivos generados correctamente para el autograder.\n");
    return 0;
}
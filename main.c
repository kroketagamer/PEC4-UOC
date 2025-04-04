/*
* Author: Alejandro Garcia
* Date: 04-05-2025
* Description: This program reads two cell phone specifications from files and compares them based on their display size and memory. 
* Escribio los comentarios en ingles porque así me voy a costumbrando a escribirlos de cara al futuro.
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 11+1                  // Maximum length of the filename   
#define MAX_NAME 25+1                    // Maximum length of the phone name
#define MAX_PHONES 2                     // Maximum number of phones

typedef struct {                         // Structure Tupla
    char name[MAX_NAME];
    int display;
    int memory;
} tPhone;

int main() {
    int i;
    tPhone phone[MAX_PHONES];
    char filename[MAX_LENGTH];
    int bestPhone;
    FILE *file;

    for (i = 0; i < MAX_PHONES; i++) {                           // Bucle for to read two files
        printf("FILENAME %i?\n", i + 1);         
        scanf("%s", filename);           
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error al abrir el archivo %s\n", filename);  // Not found file error message                                                              
        } 

        fscanf(file, "%s %d %d", phone[i].name, &phone[i].display, &phone[i].memory);
        fclose(file);
    }

    if (phone[0].display == phone[1].display) {                  // Compare if displays are equal
        if (phone[0].memory == phone[1].memory) {                // Compare if memory is equal
            bestPhone = 1;                                       // Memory is equal, so choose the second phone                
        } else {
            if (phone[0].memory > phone[1].memory) {             // If memory is different, choose the one with the higher memory
                bestPhone = 0;
            } else {
                bestPhone = 1;
            }
        }            
    } else {
        if (phone[0].display > phone[1].display) {               // If display is different, choose the one with the higher display
            bestPhone = 0;
        } else {
            bestPhone = 1;
        }
    }

    printf("OUTPUT\n");
    printf("THE BEST CELL PHONE IS %s\n", phone[bestPhone].name); // Print the name of the best phone using bestPhone as an index

    return 0;
}

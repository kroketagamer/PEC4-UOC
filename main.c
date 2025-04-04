/*
* Author: Alejandr Garcia
* Date: 4-05-2025
* Description: This program reads two cell phone specifications from files and compares them based on their display size and memory. 
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 11+1                      // Maximum length of the filename   
#define MAX_NAME 25+1                     // Maximum length of the phone name
#define MAX_PHONES 2                     // Maximum number of phones

typedef struct {                         // Structure Tupla
    char name[MAX_NAME];
    int display;
    int memory;
} tPhone;

int main() {
    tPhone phone[MAX_PHONES];
    char filename[MAX_LENGTH];
    int bestPhone;
    FILE *file;

    printf("FILENAME 1?\n");
    scanf("%s", filename);               // Read the filename from the user             
    file = fopen(filename, "r");           
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
    } else {
        fscanf(file, "%s %d %d", phone[0].name, &phone[0].display, &phone[0].memory);
        fclose(file);

        printf("FILENAME 2?\n");
        scanf("%s", filename);           // Read the second filename from the user
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error al abrir el archivo %s\n", filename);
        } else {
            fscanf(file, "%s %d %d", phone[1].name, &phone[1].display, &phone[1].memory);
            fclose(file);

            if (phone[0].display == phone[1].display) {                     // Compare if displays are equal
                if (phone[0].memory == phone[1].memory) {                   // Compare if memory is equal
                    bestPhone = 1;                                          // Memory is equal, so choose the second phone                
                } else {
                    if (phone[0].memory > phone[1].memory) {
                        bestPhone = 0;
                    } else {
                        bestPhone = 1;
                    }
                }            
            } else {
                if (phone[0].display > phone[1].display) {                  // If display is different, choose the one with the higher display
                    bestPhone = 0;
                } else {
                    bestPhone = 1;
                }
            }

            printf("OUTPUT\n");
            printf("THE BEST CELL PHONE IS %s\n", phone[bestPhone].name);   // Print the name of the best phone using bestPhone as an index
        }        
    }
    return 0;
}

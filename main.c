/*
* Author: Alejandro Garcia
* Date: 04-05-2025
* Description: This program reads two cell phone specifications from files and compares them based on their display size and memory.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>                    // Include for bool type
#define MAX_LENGTH 12                   // Maximum length of the filename (11 + 1 for null terminator)
#define MAX_NAME 26                     // Maximum length of the phone name (25 + 1 for null terminator)
#define MAX_PHONES 2                    // Maximum number of phones

typedef struct {                        // Tupla to store phone details
    char name[MAX_NAME];
    int display;
    int memory;
} tPhone;

int main() {
    tPhone phones[MAX_PHONES];
    char filename[MAX_LENGTH];
    int bestPhoneIndex;
    bool displaysEqual, memoriesEqual;
    bool fileFound = true;                 // Boolean variable to check if the file was found
    FILE *file;

    for (int i = 0; i < MAX_PHONES; i++) {                // Loop to read phone details from files
        printf("FILENAME %i?\n", i + 1);
        scanf("%s", filename);

        file = fopen(filename, "r");
        if (file == NULL) {
            printf("File not found: %s\n", filename);     // Error message for missing file
            fileFound = false;                            // Set fileFound to false                                    
        }else { 
        fscanf(file, "%s %d %d", phones[i].name, &phones[i].display, &phones[i].memory);
        fclose(file);
        }
    }
    
    if (fileFound){                                                    // Check if both files were found    
    displaysEqual = phones[0].display == phones[1].display;            // Bolean variables to check if displays and memories are equal
    memoriesEqual = phones[0].memory == phones[1].memory;

    if (displaysEqual) {                                 // Compare displays
        if (memoriesEqual) {                             // Compare memories if displays are equal
            bestPhoneIndex = 1;                          // Choose the second phone if both are equal
        } else {
            if (phones[0].memory > phones[1].memory) {
                bestPhoneIndex = 0;                      // Incex 0 if the first phone has more memory
            } else {
                bestPhoneIndex = 1;                      // Index 1 if the second phone has more memory
            }
        }
    } else {
        if (phones[0].display > phones[1].display) {
            bestPhoneIndex = 0;                          // Intex 0 if the first phone has a greater display
        } else {
            bestPhoneIndex = 1;                          // Index 1 if the second phone has a greater display
        }
    }

    printf("OUTPUT\n");
    printf("THE BEST CELL PHONE IS %s\n", phones[bestPhoneIndex].name); // Print the best phone name using the index bestPhneIndex
    }
    return 0;
}

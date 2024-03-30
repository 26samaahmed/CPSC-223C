// Author: Sama Ahmed
// Contact: 26samahmed@csu.fullerton.edu
// Course ID: CPSC223C
// This product: Midterm Test
// Due Date: 2024-March-14 at 11:00 AM
// Compile:  gcc -c -Wall -m64 -no-pie -o search.o array_search.c -lm -std=c2x
// Link:  gcc -m64 -no-pie -o search.out search.o -lm -std=c2x

//======== Begin source code ==========

#include <stdio.h> //Provides access to printf and scanf
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{

  FILE *file; // Pointer to input file
  const unsigned int max_length_file_name = 64;
  char file_name[max_length_file_name];

  printf("Welcome to String Analysis by Sama Ahmed.\n\n");
  printf("Please enter the name of a file to analyze: ");
  scanf("%s", file_name);

  file = fopen(file_name, "r"); // open the file for reading

  // Prompt the user to enter a valid file name that's in the directory
  while (file == NULL) {
    printf("File not found.  Please try again: ");
    scanf("%s", file_name);
    file = fopen(file_name, "r"); // open the file for reading
  }

    int num_of_lines = 0; // to keep track of how many lines the file

    fseek(file, 0L, SEEK_END);
    long fileLength = ftell(file); // gets the size of the file
    rewind(file);

    // NOTE: a 2D array of characters is a 1D array of strings

    char *myData[50]; // the array to hold each line in the file.
    char temp[1024];  // temporary line to store each line


    // read line from file and store them in array. This will keep going until we reach NULL which means EOF
    while (fgets(temp, 1024, file))
    {
      // Check if the we have a new line to replace it with a null character
    int length = strlen(temp);
    if (temp[length - 1] == '\n') {
      temp[length - 1] = '\0';
    }

    // allocate memory for the current line
    myData[num_of_lines] = (char *)malloc((strlen(temp) + 1) * sizeof(char));

    // copy whatever is in the temp variable to store it in the myData array
    strcpy(myData[num_of_lines], temp);

    // Increment line counter
    num_of_lines++;
    }

    printf("\n\nThe file has been copied to 2-dimensional array of row where each row is a string of chars.\n");
    printf("There are %d of lines and %ld characters in the array.", num_of_lines, fileLength);
    rewind(file);

    printf("\n\nHere are the data of the array\n\n");
    for (unsigned int i = 0; i < num_of_lines; i++) {
      printf("%s", myData[i]);
      printf("\n");
    }

    printf("\n");

    char target[256]; // user input
    do {
        if (!feof(stdin)) {
          printf("\nPlease enter a string to search or press enter to quit: ");
          scanf("%255s", target);
          char *point;

          printf("The string is in lines # ");
          for (unsigned int i = 0; i < num_of_lines + 1; i++)
          {
            point = strstr(myData[i], target);
            if (point != NULL) {
              printf("%d ", i + 1);
            }
          }
          printf("\n");
        }

    } while (!feof(stdin));
    printf("Have a good day.  Bye\n");
    fclose(file);

    return 0;
  } // End of main

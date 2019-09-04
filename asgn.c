#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"
#include <getopt.h>

#define DEFAULT 113

int main(int argc, char *argv[]) {
    const char *optstring = "c:deps:t:h";
    char option;
    char *wordIn = NULL;
    htable h;
    char *filename;
    char str[900];
    
    /*
      These flags determine what command line arguments have been passed.
      By default they are all false (0).
     */

    /*This flag determines whether the hash table to created will use
     double hashing, or linear probing.
    */
    int doubleHash = 0;
    /*
      This flag determines whether or not to call the display_entire_contents
      method on the hash table.
     */
    int displayAllContents = 0;
    /*
      This flag determines whether to call the print_stats method on
      the hash table, or print out the frequencies and words of the hash table.
     */
    int printStats = 0;
    /*
      This flag determines whether or not to display up to a given number of
      stat snapShots.
      if enabled, numSnapshots determines how many snapshots to display.
     */
    int snapshots = 0;
    int numSnapshots = 0;
    /*
      This is the table size of the table to be created. If it is not given,
      the default size is 113.
      If a size is given, the tableSize variable will be set to that given size.
     */
    int tableSize = DEFAULT;
    
    /*
      I had to do this to stay within the 80 character per line limit
     */
    /*--------------Building the Help String--------------*/
    strcpy(str, "Options for this program:");
    strcat(str, "\n\n-c filename:\nPass a file with to ");
    strcat(str, "this program to check the");
    strcat(str, "\nspelling of words based on words");
    strcat(str, "read from stdin as the dictionary.");
    strcat(str, "\n\n-d:\nUse double hashing as the collision resolution for ");
    strcat(str, "\nthe hash table. Linear probing is the default.");
    strcat(str, "\n\n-e:\nDisplay the entire contents");
    strcat(str, " of the table to stderr in ");
    strcat(str, "\na format showing the position,");
    strcat(str, "frequency, number of collisions ");
    strcat(str, "\nduring insertion, and the string value (if it exists).");
    strcat(str, "\n\n-p:\nPrint statistics information about the hash table.");
    strcat(str, "\n\n-s snapshots:\nDisplays up to a ");
    strcat(str, "given number of stat snapshots ");
    strcat(str, "\nif -p is also called. If the table is ");
    strcat(str, "not full fewer snapshots ");
    strcat(str, "\nwill be displayed. Snapshots with ");
    strcat(str, "0 entries are not displayed.");
    strcat(str, "\n\n-t tablesize:\nUses the first");
    strcat(str, " prime >= tablesize as the size ");
    strcat(str, "\nof the hash table. 113 is the default size.");
    strcat(str, "\n\n-h\nDisplays a helpful message.\n\n");
    /*--------------Building the Help String--------------*/

    
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'c':
                strcpy(filename, optstring);
                break;
            case 'd':
                doubleHash = 1;
                break;
            case 'e':
                displayAllContents = 1;
                break;
            case 'p':
                printStats = 1;
                break;
            case 's':
                snapshots = 1;
                numSnapshots = atoi(optstring);
                break;
            case 't':
                /*
                  At the moment the program breaks if you pass a table size
                  as an argument. It comes up with the error:
                  Floating point exception (core dumped)
                 */
                tableSize = atoi(optstring);
                break;
            case 'h':
                printf("%s\n", str);
                break;
            default:
                break;
                printf("%s\n", str);
        }
    }
    if(doubleHash){
        h = htable_new(tableSize, DOUBLE_H);
    }else{
        h = htable_new(tableSize, LINEAR_P);
    }
    
    
    /*while(1 == scanf("%s", wordIn)){
        htable_insert(h, wordIn);
        }*/

    htable_insert(h, "Test1");
    htable_insert(h, "Test1");
    htable_insert(h, "Test2");
    htable_insert(h, "Test3");
    htable_insert(h, "Test2");
    htable_insert(h, "Test3");

    htable_print(h, stdout);
    
    return (EXIT_SUCCESS);
}


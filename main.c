#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main() {
  FILE *f;
  char operation = '#';
  int amountRecords, input;

  do {
    f = fopen(OUTPUT_FILE, "rb");
    
    if(f == NULL) {
      scanf("%d", &amountRecords);
      createOutputFile(amountRecords);
    }
    else {
      if(operation == 'i') {
        scanf("%d", &input);
        insertRecord(input);
      }
      else if(operation == 'r') {
        scanf("%d", &input);
        removeRecord(input);
      }
      else if(operation == 'p') {
        printReports();
      }
    }

    scanf("%c", &operation);
  } while(operation != 'e');
}
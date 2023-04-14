#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

int main() {
  char operation = '#';

  do {
    int amountRecords, input;
    scanf("%d", &amountRecords);

    FILE *f;
    f = fopen(OUTPUT_FILE, "rb");

    if(f == NULL) {
      createOutputFile(amountRecords);

      while(1) {
        if (scanf("%d", &input) == EOF) break;
        insertRecord(input);
      }
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
  }
  while(operation != 'e');
}
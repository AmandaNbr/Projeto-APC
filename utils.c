#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rtrim(char *str, const char *seps);
char *ltrim(char *str, const char *seps);
void trim(char *str, const char *seps);
void convertToLowercase(char text[]);
int stringIsEmpty(char *stringChecked);


void convertToLowercase(char text[]) {
   int c = 0;

   while (text[c] != '\0') {
      if (text[c] >= 'A' && text[c] <= 'Z') {
         text[c] = text[c] + 32;
      }
      c++;
   }
}

char *ltrim(char *str, const char *seps) {
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

char *rtrim(char *str, const char *seps) {
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

void trim(char *str, const char *seps) {
    ltrim(rtrim(str, seps), seps);
}

int stringIsEmpty(char *stringChecked) {
    if (stringChecked[0] == '\0'){
        return 1;
	} else {
	    return 0;
	}
}


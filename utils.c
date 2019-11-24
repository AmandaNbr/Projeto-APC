int findAge(int birthdate[3]);
char *rtrim(char *str, const char *seps);
char *ltrim(char *str, const char *seps);
void trim(char *str, const char *seps);
void convertToLowercase(char text[]);
int stringIsEmpty(char *stringChecked);
void printPerson(struct Person *person);
void formatPersonStructData(struct Person *readPerson, char *line);

void deletePerson(char *lineToBeDeleted) {
    char line[256];
    struct Person *readPerson;
    readPerson = (struct Person*) malloc(sizeof(struct Person));

    FILE *personFile;
    personFile = fopen("people.txt", "r");

    FILE *replica;
    replica = fopen("replica.txt", "a+");

    while(fgets(line, sizeof(line), personFile) != NULL) {
        if (strcmp(line,"\n") != 0) {
            formatPersonStructData(readPerson, line);
            if (strcmp(lineToBeDeleted, line) != 0) {
                fprintf(replica, "%s", line);
            } else {
                //Nothing to do
            }
        }
    }
    fclose(personFile);
    fclose(replica);
    if (remove("people.txt") == 0) {
        printf("\nDeletou\n");
    } else {
        printf("\nErro deletar\n");
    }
    if (rename("replica.txt", "people.txt") == 0) {
        printf("\nRenomeou\n");
    } else {
        printf("\nErro renomear\n");
    }
}

// function to calculate current age
int findAge(int birthdate[3]) {
    time_t ts;
    struct tm *ct;

    ts = time(NULL);
    ct = localtime(&ts);

	// current dd/mm/yyyy
	int current_day = ct->tm_mday;
	int current_month = ct->tm_mon + 1;
	int current_year = ct->tm_year + 1900;

    // days of every month
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// if birth date is greater then current birth month then do not count this month and add 30
	// to the date so as to subtract the date and get the remaining days
	if (birthdate[0] > current_day) {
		current_day = current_day + month[birthdate[1] - 1];
		current_month = current_month - 1;
	}

    // if birth month exceeds current month, then do
	// not count this year and add 12 to the month so that we can subtract and find out the difference
	if (birthdate[1] > current_month) {
		current_year = current_year - 1;
		current_month = current_month + 12;
	}

	// calculate date, month, year
	int calculated_day = current_day - birthdate[0];
	int calculated_month = current_month - birthdate[1];
	int calculated_year = current_year - birthdate[2];

	return calculated_year;
}

void formatPersonStructData(struct Person *readPerson, char *line){
    sscanf(line, "%[^|]|%[^|]|%d/%d/%d|%[^|]|%[^\n]\n",
           readPerson->fullName,
           readPerson->gender,
           &readPerson->birthdate[0],
           &readPerson->birthdate[1],
           &readPerson->birthdate[2],
           readPerson->wantedCourse,
           readPerson->state);
}

void printPerson(struct Person *person) {
    printf("\n           ---           \n");
    printf("Nome Completo: %s\nGenero: %s\nData de Nascimento: %d/%d/%d\nCurso Desejado: %s\nEstado: %s\n",
           person->fullName,
           person->gender,
           person->birthdate[0],
           person->birthdate[1],
           person->birthdate[2],
           person->wantedCourse,
           person->state);
}

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

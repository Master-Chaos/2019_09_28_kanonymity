#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 50 //MAXIMUM SIZE OF INPUT
#define MAXBUFFFERSIZE 1024 //MAXIMUM SIZE OF BUFFER FOR READ

typedef struct management //STRUCT FOR MANAGE ALL ELEMENTS/ROWS
{
    char nameOfqi1[MAXSIZE]; //QUASI-IDENTIFIER (PLZ OR NUMBER, AGE)
    char nameOfqi2[MAXSIZE]; //QUASI-IDENTIFIER (GENDER)
    char nameOfqi3[MAXSIZE]; //QUASI-IDENTIFIER (DATE)
    char nameOfsensitive1[MAXSIZE]; //SENSITIVE (REGION)
    char nameOfsensitive2[MAXSIZE]; //SENSITIVE (JOB)
    char nameOfsensitive3[MAXSIZE]; //SENSITIVE (MONEY)
    unsigned int elementcount; //ELEMENTCOUNTER IS THE NUMBER OF ALL ELEMENTS/ROWS IN STORAGE
    struct row* first; //POSITION OF THE FIRST ELEMENT/ROW IN STORAGE
} management_struct;

typedef struct row //STRUCT FOR ONE ELEMENT/ROW
{
    int qi1; //QUASI-IDENTIFIER (PLZ OR NUMBER, AGE)
    char qi2[MAXSIZE]; //QUASI-IDENTIFIER (GENDER)
    char qi3[MAXSIZE]; //QUASI-IDENTIFIER (DATE)
    char sensitive1[MAXSIZE]; //SENSITIVE (REGION)
    char sensitive2[MAXSIZE]; //SENSITIVE (JOB)
    char sensitive3[MAXSIZE]; //SENSITIVE (MONEY)
    struct row *next; //POSITION OF THE NEXT ELEMENT/ROW IN STORAGE
} row_struct;

int initManagementRow(management_struct *managementrow, FILE *debugfile)  //INIT MANAGEMENT STRUCT
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfqi1), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfqi2), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfqi3), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfsensitive1), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfsensitive2), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((managementrow->nameOfsensitive3), "", (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    fprintf(debugfile, "Init Management Row.\n");  //WRITE TO DEBUGFILE

    managementrow->elementcount = 0; //SET ELEMENT COUNTER TO 0; BECAUSE NO DATA/ROWS ARE IN STORAGE
    managementrow->first =  NULL; //SET FIRST ELEMENT TO NULL; BECAUSE NO DATA/ROWS ARE IN STORAGE

    return 0;
}

int sortRows(management_struct *managementrow) //SORT THE ROWS BY BUBBLE SORT
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    struct row *currentrow; //STORAGE FOR CURRENT ELEMENT/ROW AND FOR INIT STORE THE FIRST ELEMENT OF MANAGEMENT STRUCT IN IT
    int tempqi1; //VARIABLE FOR STORE TEMP RESULT FROM QI1
    char tempqi2[MAXSIZE]; //VARIABLE FOR STORE TEMP RESULT FROM QI2
    char tempqi3[MAXSIZE]; //VARIABLE FOR STORE TEMP RESULT FROM QI3
    char tempsensitive1[MAXSIZE]; //VARIABLE FOR STORE TEMP RESULT FROM SENSITIVE1
    char tempsensitive2[MAXSIZE]; //VARIABLE FOR STORE TEMP RESULT FROM SENSITIVE2
    char tempsensitive3[MAXSIZE]; //VARIABLE FOR STORE TEMP RESULT FROM SENSITIVE3
    int cyclecounter = 0; //COUNT CURRENT CYCLE OF SORTING
    int check = 0; //CHECK IS A BOOLEAN FOR CHECK IF BUBBLE SORT IS FINISH

    while (check == 0) //CHECK IF BUBBLE SORT IS FINISH
    {
        check = 1; //SET CHECK TO 1 FOR CHECK CHANGES
        cyclecounter = 0; //SET COUNTER FOR CYCLE TO 0
        currentrow = managementrow->first; //STORE FIRST ELEMENT/ROW IN CURRENTROW
        while (currentrow->next != NULL) //CHECK IF NEXT ELEMENT/ROW AFTER THE CURRENT ELEMENT/ROW IS NULL
        {
            if(cyclecounter > managementrow->elementcount-1) //CHECK IF COUNTER IS GREATER THAN ELEMENTS/ROWS
            {
                break; //STOP THE LOOP
            }

            if (currentrow->qi1 > currentrow->next->qi1)
            {
                tempqi1 = currentrow->qi1; //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                currentrow->qi1 = currentrow->next->qi1; //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                currentrow->next->qi1 = tempqi1; //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW

                //CURRENT TO TEMP
                if( (strncpy(tempqi2, currentrow->qi2, (MAXSIZE -1))) == NULL) //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(tempqi3, currentrow->qi3, (MAXSIZE -1))) == NULL) //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(tempsensitive1, currentrow->sensitive1, (MAXSIZE -1))) == NULL) //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(tempsensitive2, currentrow->sensitive2, (MAXSIZE -1))) == NULL) //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(tempsensitive3, currentrow->sensitive3, (MAXSIZE -1))) == NULL) //STORE VALUE OF CURRENT ELEMENT/ROW IN TEMP VARIABLE
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }
                //CURRENTNEXT TO CURRENT
                if( (strncpy(currentrow->qi2, currentrow->next->qi2, (MAXSIZE -1))) == NULL) //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->qi3, currentrow->next->qi3, (MAXSIZE -1))) == NULL) //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->sensitive1, currentrow->next->sensitive1, (MAXSIZE -1))) == NULL) //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->sensitive2, currentrow->next->sensitive2, (MAXSIZE -1))) == NULL) //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->sensitive3, currentrow->next->sensitive3, (MAXSIZE -1))) == NULL) //COPY VALUE OF NEXT ELEMENT/ROW IN CURRENT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }
                //TEMP TO CURRENTNEXT
                if( (strncpy(currentrow->next->qi2, tempqi2, (MAXSIZE -1))) == NULL) //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->next->qi3, tempqi3, (MAXSIZE -1))) == NULL) //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->next->sensitive1, tempsensitive1, (MAXSIZE -1))) == NULL) //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->next->sensitive2, tempsensitive2, (MAXSIZE -1))) == NULL) //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }

                if( (strncpy(currentrow->next->sensitive3, tempsensitive3, (MAXSIZE -1))) == NULL) //COPY VALUE OF TEMP TO NEXT ELEMENT/ROW
                {
                    printf("ERROR 4: NULLPOINTER in strncpy in sortRows\n"); //ERROR MESSAGE
                    return -1;
                }
                check = 0; //SET CHECK TO 0 BECAUSE SOME CHANGES WERE MADE
            }
            cyclecounter++; //INCREASE COUNTER OF CYCLE
            currentrow = currentrow->next; //GET NEXT ELEMENT/ROW
        }
    }

    return 1;
}

int addNewRow(management_struct *managementrow, int qi1, char *qi2, char *qi3, char *sensitive1, char *sensitive2, char *sensitive3, FILE *debugfile) //ADD A NEW ELEMENT/ROW TO STORAGE
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    struct row *nextrow = NULL; //CREATE A NEW STRUCT OF TYP ROW

    nextrow = malloc( sizeof(row_struct) ); //ALLOCATE MEMORY FOR NEW STRUCT
    if( nextrow == NULL ) { //CHECK IF NEXTROW IS NULL
        return -1;
    }

    fprintf(debugfile, "Add new rows to storage.\n");  //WRITE TO DEBUGFILE

    nextrow->qi1 = qi1; //STORE VARIABLE IN STRUCT
    if( (strncpy((nextrow->qi2), qi2, (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((nextrow->qi3), qi3, (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((nextrow->sensitive1), sensitive1, (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((nextrow->sensitive2), sensitive2, (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    if( (strncpy((nextrow->sensitive3), sensitive3, (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
    {
        printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
        return -1;
    }

    nextrow->next = managementrow->first; //SET POSITION OF LAST ELEMENT/ROW IN MANAGEMENTROW AS NEXT ELEMENT/ROW IN THE NEW STRUCT
    managementrow->first = nextrow; //SET POSITION OF THE NEW STRUCT AS FIRST ELEMENT/ROW IN MANAGEMENTROW

    managementrow->elementcount++; //INCREASE ELEMENT COUNTER BY 1

    return 1;
}

int makeKanonymity(const management_struct *managementrow, int k, FILE *debugfile) //MAKE K-ANONYMITIY
{
    int i; //VARIABLE FOR FOR-LOOP

    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    row_struct* currentrow = managementrow->first; //STORE FIRST STRUCT IN THIS CURRENT STRUCT

    if(currentrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    fprintf(debugfile, "Make K-Anonymity.\n");  //WRITE TO DEBUGFILE

    for(i = 1; i < managementrow->elementcount; i++) { //LOOP FOR CHECK ALL ROWS (ELEMENTS) OF THE DATAFILE -> ONE LOOP CYCLE IS ONE ROW
        //QUASI-IDENTIFIER QI1 AGE
        switch(currentrow->qi1) { //CHECK NUMBER  //TODO UMBAUEN AUF IF else mit + vorher checken, ob is integer oder string
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                currentrow->qi1 = 10; //IF NUMBER IS BETWEEN 1 AND 10, STORE 10
                break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                currentrow->qi1 = 20; //IF NUMBER IS BETWEEN 11 AND 20, STORE 20
                break;
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
                currentrow->qi1 = 30; //IF NUMBER IS BETWEEN 21 AND 30, STORE 30
                break;
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
                currentrow->qi1 = 40; //IF NUMBER IS BETWEEN 31 AND 40, STORE 40
                break;
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
            case 50:
                currentrow->qi1 = 50; //IF NUMBER IS BETWEEN 41 AND 50, STORE 50
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
            case 59:
            case 60:
                currentrow->qi1 = 60; //IF NUMBER IS BETWEEN 51 AND 60, STORE 60
                break;
            case 61:
            case 62:
            case 63:
            case 64:
            case 65:
            case 66:
            case 67:
            case 68:
            case 69:
            case 70:
                currentrow->qi1 = 70; //IF NUMBER IS BETWEEN 61 AND 70, STORE 70
                break;
            case 71:
            case 72:
            case 73:
            case 74:
            case 75:
            case 76:
            case 77:
            case 78:
            case 79:
            case 80:
                currentrow->qi1 = 80; //IF NUMBER IS BETWEEN 71 AND 80, STORE 80
                break;
            case 81:
            case 82:
            case 83:
            case 84:
            case 85:
            case 86:
            case 87:
            case 88:
            case 89:
            case 90:
                currentrow->qi1 = 90; //IF NUMBER IS BETWEEN 81 AND 90, STORE 90
                break;
            case 91:
            case 92:
            case 93:
            case 94:
            case 95:
            case 96:
            case 97:
            case 98:
            case 99:
            case 100:
                currentrow->qi1 = 100; //IF NUMBER IS BETWEEN 91 AND 100, STORE 100
                break;
            default: currentrow->qi1 = 0; break; //IF NUMBER IS NOT BETWEEN 1 AND 100, STORE 0
        }

        //QUASI-IDENTIFIER QI3 DATE
        char *store[MAXSIZE] = {NULL}; //ARRAY FOR STORE THE STRING PARTS
        char *part = 0; //POINTER FOR CURRENT POSITION IN STRING
        int j = 0; //COUNTER FOR INCREASE ARRAY

        part = strtok(currentrow->qi3, ". "); //START POSITION BY FIRST DELIMITER OF STRING
        while (part)
        {
            store[j] = part; //STORE PARTS OF THE STRING IN ARRAY
            part = strtok(NULL, ". "); //GO TO NEXT POSITION OF DELIMITER IN THE STRING
            j++; //INCREASE COUNTER BY 1
        }

        strcpy(currentrow->qi3, store[1]); //REPLACE/COPY DATE TO MONTH

        //SENSITIVE sensitive1 COUNTRY
        if (strcmp(currentrow->sensitive1, "England") == 0) //CHECK IF COUNTRY IS IN DATAFILE
        {
            strcpy(currentrow->sensitive1, "Europe"); //IF YES REPLACE IT BY EUROPE
        }

        if (strcmp(currentrow->sensitive1, "Wales") == 0) //CHECK IF COUNTRY IS IN DATAFILE
        {
            strcpy(currentrow->sensitive1, "Europe"); //IF YES REPLACE IT BY EUROPE
        }

        if (strcmp(currentrow->sensitive1, "Northern Ireland") == 0) //CHECK IF COUNTRY IS IN DATAFILE
        {
            strcpy(currentrow->sensitive1, "Europe"); //IF YES REPLACE IT BY EUROPE
        }

        if (strcmp(currentrow->sensitive1, "Scotland") == 0) //CHECK IF COUNTRY IS IN DATAFILE
        {
            strcpy(currentrow->sensitive1, "Europe"); //IF YES REPLACE IT BY EUROPE
        }

        currentrow = currentrow->next; //GET NEXT STRUCT (=ROW OF THE DATAFILE) AND STORE IT IN CURRENT STRUCT
    }

    return 1;
}

int printRow(const management_struct *managementrow, int number, FILE *debugfile) //PRINT OUT A ROW BY NUMBER
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR6: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    int i; //VARIABLE FOR FOR-LOOP
    row_struct* currentrow = managementrow->first; //STORAGE FOR CURRENT ELEMENT/ROW AND FOR INIT STORE THE FIRST ELEMENT OF MANAGEMENT STRUCT IN IT

    fprintf(debugfile, "Print row with number[%d]:\n", number); //WRITE TO DEBUGFILE

    if (managementrow->elementcount <= number) //CHECK IF NO ELEMENT/ROW IS IN STORAGE = CASE IF NUMBER IS
    {
        fprintf(debugfile, "Sorry, no row available.\n");  //WRITE TO DEBUGFILE
    }

    for(i = 1; i < managementrow->elementcount; i++) {  //GET ALL ELEMENTS/ROWS

        if(i == number) //PRINT OUT DATA OF CURRENT ELEMENT/ROW
        {
            fprintf(debugfile, "Print row[%d]: %d, %s, %s, %s, %s, %s \n", i, currentrow->qi1, currentrow->qi2, currentrow->qi3, currentrow->sensitive1, currentrow->sensitive2, currentrow->sensitive3); //WRITE TO DEBUGFILE THE DATA OF CURRENT ELEMENT/ROW
        }
        currentrow = currentrow->next; //GET NEXT ELEMENT/ROW AND STORE IT IN CURRENT STRUCT
    }
    return 1;
}

int printAllRows(const management_struct *managementrow, FILE *debugfile) //PRINT OUT ALL ROWS
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR7: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    int i; //VARIABLE FOR FOR-LOOP
    row_struct* currentrow = managementrow->first; //STORAGE FOR CURRENT ELEMENT/ROW AND FOR INIT STORE THE FIRST ELEMENT OF MANAGEMENT STRUCT IN IT

    fprintf(debugfile, "Print All Rows\n"); //WRITE TO DEBUGFILE

    for(i = 1; i < managementrow->elementcount; i++) { //GET ALL ELEMENTS/ROWS

        fprintf(debugfile, "Print row with number[%d]: %d, %s, %s, %s, %s, %s", i, currentrow->qi1, currentrow->qi2, currentrow->qi3, currentrow->sensitive1, currentrow->sensitive2, currentrow->sensitive3); // //WRITE TO DEBUGFILE THE DATA OF CURRENT ELEMENT/ROW
        currentrow = currentrow->next; //GET NEXT ELEMENT/ROW AND STORE IT IN CURRENT STRUCT
    }
    return 1;
}

int readFromCSV (management_struct *managementrow, char *filename, FILE *debugfile) //READ DATA FROM CSV-FILE
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR8: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    FILE *inputfile = fopen(filename,"r"); //CREATE FILE AND OPEN FILE WITH READ MODE

    if(inputfile == NULL)   { //CHECK IF INPUTFILE CANNOT OPENED
        printf("ERROR9: file opening failed in read from CSV.\n"); //ERROR MESSAGE
        return -1 ;
    }

    fprintf(debugfile, "Read from CSV - File: %s\n", filename); //WRITE TO DEBUGFILE

    char buffer[MAXBUFFFERSIZE]; //CREATE A BUFFER FOR READ A ROW FROM INPUTFILE
    char *store[MAXSIZE] = {NULL}; //CREATE ARRAY FOR STORE EVERY PART OF THE ROW
    char *token = 0; //POINTER FOR CURRENT POSITION IN ROW



    while (fgets(buffer, sizeof(buffer), inputfile)) //READS DATA FROM INPUTFILE INTRO THE BUFFER
    {
        int i = 0; //VARIABLE FOR POSITION IN ARRAY
        token = strtok(buffer, ","); //STORE FIRST POSITION IN TOKEN - THE SEPARATOR IS THE COMMA
        while (token)
        {
            store[i] = token; //STORE PART OF THE ROW IN THE ARRAY
            fprintf(debugfile, "Read Part of Row with Partnumber[%d] and store it: %s\n", i,  store[i]); //WRITE TO DEBUGFILE
            token = strtok(NULL, ","); //STORE NEXT POSITION IN TOKEN - THE SEPARATOR IS THE COMMA
            i++; //INCREASE COUNTER FOR NEXT POSITION IN ARRAY
        }
        if (managementrow->elementcount == 0)
        {
            if( (strncpy((managementrow->nameOfqi1), store[4], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }


            if( (strncpy((managementrow->nameOfqi2), store[3], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }

            if( (strncpy((managementrow->nameOfqi3), store[7], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }

            if( (strncpy((managementrow->nameOfsensitive1), store[5], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }

            if( (strncpy((managementrow->nameOfsensitive2), store[6], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }

            if( (strncpy((managementrow->nameOfsensitive3), store[8], (MAXSIZE -1))) == NULL) //STORE VARIABLE IN STRUCT
            {
                printf("ERROR 4: NULLPOINTER in strncpy in addNewRow\n"); //ERROR MESSAGE
                return -1;
            }

            managementrow->elementcount++;
        }
        else
        {
            addNewRow(managementrow, atoi(store[4]), store[3], store[7], store[5], store[6], store[8], debugfile); //CALL FUNCTION FOR ADD A NEW ROW IN STORAGE
        }


    }

    fclose(inputfile); //CLOSE INPUTFILE

    return 1;
}

int writeToCSV (management_struct *managementrow, char *filename, FILE *debugfile) //WRITE DATA TO CSV-FILE
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR10: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    FILE *outputfile = fopen(filename,"w"); //CREATE FILE AND OPEN FILE WITH WRITE MODE

    if(outputfile == NULL)   { //CHECK IF OUTPUTFILE CANNOT OPENED
        printf("ERROR11: file opening failed in write from CSV.\n"); //ERROR MESSAGE
        return -1 ;
    }

    fprintf(debugfile, "Write to CSV - File: %s\n", filename);  //WRITE TO DEBUGFILE

    int i; //VARIABLE FOR FOR-LOOP
    row_struct* currentrow = managementrow->first; //STORAGE FOR CURRENT ELEMENT/ROW AND FOR INIT STORE THE FIRST ELEMENT OF MANAGEMENT STRUCT IN IT
   fprintf(outputfile, "%s, %s, %s, %s, %s, %s", managementrow->nameOfqi1, managementrow->nameOfqi2, managementrow->nameOfqi3, managementrow->nameOfsensitive1, managementrow->nameOfsensitive2, managementrow->nameOfsensitive3);  //WRITE COLUMN NAMES TO OUTPUTFILE
    for(i = 1; i < (managementrow->elementcount); i++) {  //GET ALL ELEMENTS/ROWS
        fprintf(outputfile, "%d, %s, %s, %s, %s, %s", currentrow->qi1, currentrow->qi2, currentrow->qi3, currentrow->sensitive1, currentrow->sensitive2, currentrow->sensitive3); //WRITE ROW INTO OUTPUTFILE (ROW BY ROW)
        currentrow = currentrow->next; //GET NEXT ELEMENT/ROW AND STORE IT IN CURRENT STRUCT
    }
    printf("Finished\n");
    fclose(outputfile); //CLOSE OUTPUTFILE

    return 1;
}

int freeAllRows(management_struct *managementrow, FILE *debugfile) //FREE MEMORY BY DELETE ALL ELEMENTS/ROWS IN STORAGE
{
    if(managementrow == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR12: NULLPOINTER in managementrow.\n"); //ERROR MESSAGE
        return -1;
    }

    if(debugfile == NULL) {	//CHECK IF STRUCT IS NULL
        printf("ERROR5: NULLPOINTER in debugfile.\n"); //ERROR MESSAGE
        return -1;
    }

    row_struct* freeelement = managementrow->first; //CREATE A STRUCT FOR STORE THE CURRENT ELEMENT/ROW FOR DELETE THE ELEMENT/ROW AND STORE THE FIRST ELEMENT/ROW TO DELETE IN IT
    row_struct* next; //CREAT A STRUCT FOR STORE THE NEXT ELEMENT/ROW IN IT

    fprintf(debugfile, "Free Memory and delete all rows in storage.\n");  //WRITE TO DEBUGFILE

    while (freeelement != NULL) //DELETE ALL ELEMENTS/ROWS
    {
        next = freeelement->next; //STORE THE NEXT ELEMENT/ROW IN THE STRUCT NEXT
        free(freeelement); //FEE THE MEMORY AND DELETE THE CURRENT ELEMENT/ROW
        freeelement = next; //STORE THE NEXT ELEMENT/ROW AS THE CURRENT ELEMENT/ROW TO FREE IT
    }
    managementrow->elementcount = 0; //FINALLY SET THE COUNTER OF ELEMENTS/ROWS TO 0

    return 1;
}

void printTests(management_struct *managementrow) //PRINT OUT ALL ROWS
{
    int i;

    row_struct* currentrow = managementrow->first; //STORAGE FOR CURRENT ELEMENT/ROW AND FOR INIT STORE THE FIRST ELEMENT OF MANAGEMENT STRUCT IN IT

        for(i = 1; i < managementrow->elementcount; i++) { //GET ALL ELEMENTS/ROWS

            printf("ELEMENT [%d]: %d, %s, %s, %s, %s, %s", i, currentrow->qi1, currentrow->qi2, currentrow->qi3, currentrow->sensitive1, currentrow->sensitive2, currentrow->sensitive3); //PRINT OUT DATA OF CURRENT ELEMENT/ROW
            currentrow = currentrow->next; //GET NEXT ELEMENT/ROW AND STORE IT IN CURRENT STRUCT
        }
    }

int main(int argc, char **argv)
{
    if(argc == 0) //CHECK IF ARGC IS NULL
    {
        printf("ERROR1: NULLPOINTER in argc.\n"); //ERROR MESSAGE
        return -1;
    }

    char *ptr;
    long convertk =  strtol(argv[2], &ptr, 10); //CONVERT TYPE FROM ARGV FROM STRING TO LONG
    int k = convertk; //CONVERT TYPE LONG TO INT

    if((argc == 6) && (strcmp(argv[1], "–anonymize") == 0)) // –anonymize 5 inputFile.csv outputFile.csv [debugfile.txt]
    {
        FILE *debugfile = fopen(argv[5],"w"); //CREATE FILE AND OPEN FILE WITH WRITE MODE

        if(debugfile == NULL)   { //CHECK IF OUTPUTFILE CANNOT OPENED
            printf("ERROR2: Debugfile opening failed. \n"); //ERROR MESSAGE
            return -1 ;
        }
        fprintf(debugfile, "#########################################################################################################################################################\n");  //WRITE TO DEBUGFILE
        fprintf(debugfile, "argc = %d + %d\n", argc, k);  //WRITE TO DEBUGFILE
        fprintf(debugfile, "argv[0] = %s\n", argv[0]); //WRITE ARGV[0] = PATH OF PROGRAM TO DEBUGFILE
        fprintf(debugfile, "argv[1] = %s\n", argv[1]); //WRITE ARGV[1] = COMMAND TO DEBUGFILE
        fprintf(debugfile, "argv[2] = %s\n", argv[2]); //WRITE ARGV[2] = K VALUE TO DEBUGFILE
        fprintf(debugfile, "argv[3] = %s\n", argv[3]); //WRITE ARGV[3] = INPUTFILE TO DEBUGFILE
        fprintf(debugfile, "argv[4] = %s\n", argv[4]); //WRITE ARGV[4] = OUTPUTFILE  TO DEBUGFILE
        fprintf(debugfile, "argv[5] = %s\n", argv[5]); //WRITE ARGV[5] = DEBUGFILE TO DEBUGFILE
        fprintf(debugfile, "#########################################################################################################################################################\n");  //WRITE TO DEBUGFILE
        fprintf(debugfile, "Command is anonymize:\n");  //WRITE TO DEBUGFILE
        management_struct managementrow; //STORAGE FOR MANAGEMENT OF ALL ELEMENTS/ROWS
        initManagementRow(&managementrow, debugfile); //CALL FUNCTION TO INIT MANAGEMENT STRUCT
        readFromCSV(&managementrow, argv[3], debugfile); //CALL FUNCTION TO READ FROM CSV FILE
        makeKanonymity(&managementrow, k, debugfile); //CALL FUNCTION TO MAKE K-ANONYMITY
        sortRows(&managementrow); //CALL FUNCTION TO SORT ALL ELEMENTS/ROWS
        printTests(&managementrow); //CALL FUNCTION TO PRINT ELEMENTS/ROWS FOR TEST
        writeToCSV (&managementrow, argv[4], debugfile); //CALL FUNCTION TO WRITE TO CSV FILE
        freeAllRows(&managementrow, debugfile); //CALL FUNCTION TO DELETE ALL ELEMENTS/ROWS
        fclose(debugfile); //CLOSE DEBUGFILE
    }
    else if((argc == 3) && (strcmp(argv[1], "–findk") == 0)) //-findk inputFile.csv
    {
        return k;
    }
    else
    {
        printf("ERROR3: The number of arguments is wrong.\n"); //ERROR MESSAGE
        exit(1);
    }

    return 0 ;
}


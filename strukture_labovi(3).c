#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _student{
    char name[20];
    char surname[20];
    int birthYear;
    struct _student* next;
    }student;

student* NewElement(){
    student* NewStudent = NULL;
    NewStudent = (student*)malloc(sizeof(student));

    scanf(" %s", NewStudent->name);
    scanf(" %s", NewStudent->surname);
    scanf("%d", &NewStudent->birthYear);

    return NewStudent;
}
int Printer(student*head){
    student* SomeStudent;
    SomeStudent = head->next;

    while(SomeStudent != NULL){
        printf("Ime studenta je %s", SomeStudent->name);
        printf("Prezime studenta je %s", SomeStudent->surname);
        printf("Godina rodjenja studenta je %d", SomeStudent->birthYear);

        SomeStudent = SomeStudent->next;

        return 0;
    }
}
int AddToTheStart(student* head){
    student* NewStudent = NULL;
    NewStudent = NewElement();

    NewStudent->next = head->next;
    head->next = NewStudent;

    return 0;
    }
int AddToTheEnd(student* head){
    student* NewStudent = NULL;
    student* NewStudent = NewElement();

    student* SomeStudent = head->next;

    while(SomeStudent != NULL){
        SomeStudent = SomeStudent->next;
    }
    NewStudent->next = NULL;
    SomeStudent->next = NewStudent;

    return 0;
}
int FindStudent(student* head, char* name){
    student* SomeStudent = head->next;

    while(strcmp(SomeStudent->surname, *name) != 0){
        SomeStudent = SomeStudent->next;
    }
    printf("Ime i prezime studenta kojeg trazimo je %s %s", SomeStudent->name, SomeStudent->surname);

    return 0;
        }
student* FindPreviousOf(student* head, student* element){
    student*SomeStudent = head->next;

    while(SomeStudent->next != element){
        SomeStudent = SomeStudent->next;
    }
    return SomeStudent;
}
int DeleteElement(student* head, char surname){
    student* SomeStudent = head->next;

    Previous = FindPreviousOf(head, element);

    while(strcmp(SomeStudent->surname, surname) != 0){
        SomeStudent = SomeStudent->next;
    }

    free(SomeStudent);

    return 0;
    }
int InsertAfter(student* element){
    student* NewStudent = NewElement();

    NewStudent->next = element->next;
    element->next = NewStudent;

    return 0;

}
int InsertBefore(student* head, student* element){
    student* NewStudent = NewElement();
    student* Previous = NULL;

    Previous = FindPreviousOf(head, element);

    NewStudent->next = element;
    Previous->next = NewStudent;

    return 0;

}
student* SortList(student* head){
    student* numberStudent = head->next;
    student* previous = FindPreviousOf(head, numberStudent);
    student* last = NULL;
    while(last != head)
    while(numberStudent->next != last){
        if(strcmp(numberStudent->surname, numberStudent->next->surname)>0){
            numberStudent = numberStudent->next;
            numberStudent->next = numberStudent;
            previous->next = numberStudent->next;
        }
        numberStudent = numberStudent->next;
        last = FindPreviousOf(head, last);
    }
    return head;
    }
int printFile(FILE* fp, char* name, student* head){
    student* someStudent = head->next;
    if(fp = fopen(name, "w")==NULL)
    {
        printf("Datoteka nije uspjesno otvorena");
        return -1;
    }
    else return 0;
    while(someStudent != NULL)
    {
        fprintf(fp, "%s %s %d", someStudent->name, someStudent->surname, someStudent->birthYear);
    }
    fclose(fp);
}
int readFile(student* head, FILE* fp, char*name){
    student* someStudent = head->next;

    if(fp = fopen(name, "r") == NULL)
    {
        printf("Datoteku nije moguce otvoriti");
        return -1;
    }
    else return 0;

    while(!feof(fp)){
        someStudent = (student*)malloc(sizeof(student));
        fscanf(fp, "%s %s %d", someStudent->name, someStudent->surname, someStudent->birthYear);
        someStudent = someStudent->next;
    }
    fclose(fp);
    }

    int main()
    {

        student head = {.name = {0},.surname = {0},.birthYear = 0,.next = NULL };
        AddToTheEnd(head);
        AddToTheEnd(head);
        AddToTheEnd(head);

        AddToTheStart(head);
        AddToTheStart(head);
        AddToTheStart(head);

        DeleteElement(head, "Krakan");

        Printer(head);

        FindStudent(head, "Matej");

        return 0;
    }









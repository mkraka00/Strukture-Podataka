#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 50
typedef struct _polinom* polinom;
struct _polinom
{
    int koeficijent;
    int eksponent;
    polinom next;
};

void SortiraniUnos(polinom, FILE*, char*);
int AddPolinom(polinom, polinom, polinom);
int MultiPolinom(polinom, polinom, polinom);
polinom NewPolinom(int, int);
void SortInsertedElement(polinom, polinom);
int PrintList(polinom);


int main()
{
    struct _polinom head1 = {.koeficijent = 0, .eksponent = 0, .next = NULL};
    struct _polinom head2 = {.koeficijent = 0, .eksponent = 0, .next = NULL};
    struct _polinom headAdd = {.koeficijent = 0, .eksponent = 0, .next = NULL};
    struct _polinom headMulti = {.koeficijent = 0, .eksponent = 0, .next = NULL};

    char ime[20];
    scanf("%s", &ime);
    FILE* pok = NULL;

    SortiraniUnos(&head1, pok, ime );
	SortiraniUnos(&head2, pok , ime );

	AddPolinom(&head1, &head2, &headAdd);
	printf("Ispis zbrajanja polinoma:\n");
	PrintList(&headAdd);

	MultiPolinom(&head1, &head2, &headMulti);
	printf("Ispis pomnozenih polinoma:\n");
	PrintList(&headMulti);

    return 0;
}

polinom CreateNewElement(int koeficijent, int eksponent)
{
    polinom NewPolinom;

    NewPolinom->koeficijent = koeficijent;
    NewPolinom->eksponent = eksponent;

    return NewPolinom;

}
void SortInsertedElement(polinom head, polinom NewPolinom)
{
    polinom SomePolinom = head->next;
    while(SomePolinom != NULL)
    {
        while(SomePolinom->next->eksponent > NewPolinom->eksponent)
            SomePolinom = SomePolinom->next;
        if(SomePolinom->next->eksponent == NewPolinom->eksponent)
            SomePolinom->next->koeficijent = SomePolinom->next->koeficijent + NewPolinom->koeficijent;
        else
        {
            NewPolinom->next = SomePolinom->next;
            SomePolinom->next = NewPolinom;
        }
    }

}
void SortiraniUnos(polinom head, FILE* fp, char* name)
{
    /*Deklaracija varijabli*/

    polinom Polinom = NULL;
    char* buffer;
    int pomak;
    char n;
    int koeficijent, eksponent;

    Polinom = (polinom)malloc(sizeof(polinom));
    Polinom = head->next;
    buffer = (char*)malloc(MAX*sizeof(char));

    /*Otvaranje datoteke*/

    fp = fopen("name.txt", "r");
    if(fp == NULL)
        printf("Datoteka nije uspješno otvorena");
    else
        printf("Datoteka uspješno otvorena");

    /*Unos iz datoteke u buffer*/

    if(fgets(buffer, MAX, fp) == NULL)
        printf("Nemamo što učitati");

    /*Sortirani unos iz buffera u listu*/

    while(buffer != NULL)
    {
        pomak = sscanf(buffer, "%d %d %n", &koeficijent, &eksponent, &n);
        SortInsertedElement(head, CreateNewElement(koeficijent, eksponent));
        buffer = buffer + pomak;
    }
}
int AddPolinom(polinom head1, polinom head2, polinom headAdd)
{
    polinom Polinom1 = head1->next;
    polinom Polinom2 = head2->next;
    polinom PolinomAdd = headAdd->next;

    while(Polinom1 != NULL)
    {
        while(Polinom1->eksponent > Polinom2->eksponent || Polinom2 != NULL)
        Polinom2 = Polinom2->next;
        if(Polinom1->eksponent == Polinom2->eksponent)
        {
            PolinomAdd->eksponent = Polinom1->eksponent;
            PolinomAdd->koeficijent = Polinom1->koeficijent + Polinom2->koeficijent;
            PolinomAdd = PolinomAdd->next;
        }
        else if(Polinom2->eksponent < Polinom1->eksponent)
        {
            PolinomAdd->eksponent = Polinom1->eksponent;
            PolinomAdd->koeficijent = Polinom1->koeficijent;
            PolinomAdd = PolinomAdd->next;
        }
        Polinom1 = Polinom1->next;
    }
    while(Polinom2 != NULL)
    {
            while(Polinom2->eksponent < Polinom1->eksponent || Polinom1 != NULL)
            Polinom1 = Polinom1->next;
            if(Polinom2->eksponent > Polinom1->eksponent)
            {
                PolinomAdd->eksponent = Polinom2->eksponent;
                PolinomAdd->koeficijent = Polinom2->koeficijent;
                PolinomAdd = PolinomAdd->next;
            }
            Polinom2 = Polinom2->next;



    return 0;
}

int MultiPolinom(polinom head1, polinom head2, polinom headMulti)
{
	polinom p1 = head1->next;
	polinom p2 = head2->next;

    polinom Multi = headMulti->next;
    while(p1 != NULL)
    {
         struct _polinom temp;
         temp = { .koeficijent = 0, .eksponent = 0, .next = NULL};
        while(p2 != NULL)
        {
            temp.koeficijent = p1->koeficijent * p2->koeficijent;
            temp.eksponent = p2->eksponent + p2->eksponent;
        }
        AddPolinom(head1, headMulti, headMulti);
        p1 = p1->next;
    }
    return 0;
}
int PrintList(polinom head)
{
    polinom Polinom = head->next;

    while(Polinom !=NULL)
    {
        printf("%dX^%d+", &Polinom->koeficijent, &Polinom->eksponent);
        Polinom = Polinom->next;
    }
    return 0;
}

#include <stdio.h>
// #include <stdlib.h>
// #include "StackADT.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**********************************************************/
// StackADT.h
// #include <stdbool.h>

typedef char StackElementType;           /*ο τύπος των στοιχείων της στοίβας
                                        ενδεικτικά τύπου int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
    StackElementType Data;
    StackPointer Next;
} StackNode;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

// QueueADT.h
#include <stdbool.h>

typedef char QueueElementType;           /*ο τύπος των στοιχείων της συνδεδεμένης ουράς
                                        ενδεικτικά τύπου int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
    QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
/**********************************************************/


// filename TestStack.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include "StackADT.h"

void TraverseStack(StackPointer Stack);
void TraverseQ(QueueType Queue);
void menu(int *choice);

int main() {
    char alfarithmitiko[100];
    StackPointer stack;
    QueueType queue;
    int i, is_karkiniko = 1;

    // Δημιουργία κενής στοίβας και ουράς
    CreateStack(&stack);
    CreateQ(&queue);

    printf("DWSE TO ALFARITHMITIKO: ");
    scanf("%s", alfarithmitiko);

    // Εισαγωγή χαρακτήρων στη στοίβα και την ουρά
    for (i = 0; i < strlen(alfarithmitiko); i++) {
        Push(&stack, alfarithmitiko[i]);
        AddQ(&queue, alfarithmitiko[i]);
    }

    // Εμφάνιση στοιχείων στοίβας και ουράς
    printf("Stack of characters\n");
    TraverseStack(stack);
    printf("Queue of characters\n");
    TraverseQ(queue);

    // Έλεγχος αν το αλφαριθμητικό είναι καρκινικό
    while (!EmptyStack(stack) && is_karkiniko) { 
        char stack_char, queue_char;
        Pop(&stack, &stack_char);
        RemoveQ(&queue, &queue_char);
        if (stack_char != queue_char) {
            is_karkiniko = 0;
        }
    }

    // Εμφάνιση αποτελέσματος
    if (is_karkiniko) {
        printf("%s ACCEPTED\n", alfarithmitiko);
    } else {
        printf("%s REJECTED\n", alfarithmitiko);
    }

    return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1 ---- DHMIOYRGIA STOIBAS\n");
    printf("2 ---- ADEIASMA THS STOIBAS\n");
    printf("3 ---- ELEGXOS KENHS STOIBAS\n");
    printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
    printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
    printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
    printf("7 ---- EXIT\n");
    printf("Choice: ");
    do
    {
        scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void TraverseStack(StackPointer Stack)
{
    StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
           printf("EMPTY Stack\n");
    }
   else
   {
           CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
               printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void TraverseQ(QueueType Queue)
{
    QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
           printf("EMPTY Queue\n");
    }
   else
   {
           CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
               printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

/**********************************************************/
// Filename: StackADT.c

/* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΔΥΝΑΜΙΚΑ ΜΕ ΔΕΙΚΤΕΣ*/

// #include <stdio.h>
// #include <stdlib.h>
// #include "StackADT.h"

void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
    *Stack = NULL;
}

bool EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
    return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
    StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
           printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}


// QueuePADT.c
                        /*ΥΛΟΠΟΙΗΣΗ ΟΥΡΑΣ ΔΥΝΑΜΙΚΑ ΜΕ ΔΕΙΚΤΕΣ*/

// #include <stdio.h>
// #include <stdlib.h>
// #include "QueueADT.h"

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
    Queue->Front = NULL;
    Queue->Rear = NULL;
}

bool EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
    return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
    QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
           printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
/**********************************************************/

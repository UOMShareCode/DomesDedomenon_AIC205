// include's
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**********************************************************/
// Filename ListPADT.h

#define MAX_NAME 40

typedef struct {
    char name[MAX_NAME];
    int balance;
} BankCustomer;

typedef BankCustomer ListElementType;

typedef struct ListNode *ListPointer;
typedef struct ListNode {
    ListElementType Data;
    ListPointer Next;
} ListNode;

void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List, void (*Visit)(ListElementType));

/**********************************************************/

void printCustomer(ListElementType customer);
void CreateCustomerList(ListPointer *List, char *filename);
void PrintCustomerList(ListPointer List);
void CreateBlackList(ListPointer List, ListPointer *BlackList);

int main()
{
    ListPointer customerList, blackList;
    
    CreateList(&customerList);
    CreateList(&blackList);
    
    CreateCustomerList(&customerList, "I4F4.DAT");
    
    printf("INITIAL LIST\n");
    PrintCustomerList(customerList);
    
    CreateBlackList(customerList, &blackList);
    
    printf("BLACK LIST\n");
    PrintCustomerList(blackList);

    return 0;
}

void CreateCustomerList(ListPointer *List, char *filename) {
    FILE *fp;
    ListElementType customer;
    char line[100]; // Adjust the size if necessary to accommodate the longest possible line
    int nscan;
    int line_number = 1;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Use sscanf to parse the line read by fgets
        nscan = sscanf(line, " %39[^,], %d", customer.name, &customer.balance);
        if (nscan == 2) { // Only two items should be read: name and balance
            LinkedInsert(List, customer, NULL);
        } else {
            printf("Error: Improper file format on line %d\n", line_number);
            fclose(fp); // Ensure the file is closed before exiting
            exit(1);
        }
        line_number++;
    }

    fclose(fp);
}

void printCustomer(ListElementType customer)
{
    printf("%s %d\n", customer.name, customer.balance);
}

void PrintCustomerList(ListPointer List)
{
    if(EmptyList(List)) {
        printf("EMPTY LIST\n");
    }
    else {
        LinkedTraverse(List, printCustomer);
        printf("\n");
    }
}

void CreateBlackList(ListPointer List, ListPointer *BlackList)
{
    ListPointer currPtr;
    
    currPtr = List;
    while(currPtr != NULL) {
        if(currPtr->Data.balance < 0) {
            LinkedInsert(BlackList, currPtr->Data, NULL);
        }
        currPtr = currPtr->Next;
    }
}

/**********************************************************/
// ListPADT.c
/*              ΥΛΟΠΟΙΗΣΗ ΣΥΝΔΕΔΕΜΕΝΗΣ ΛΙΣΤΑΣ ΔΥΝΑΜΙΚΑ - ΜΕ ΔΕΙΚΤΕΣ
                ΤΑ ΣΤΟΙΧΕΙΑ ΤΩΝ ΚΟΜΒΩΝ ΕΙΝΑΙ ΤΥΠΟΥ BankCustomer */

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
    *List = NULL;
}

bool EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
    return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
    ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
    if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο της
                 και έναν δείκτη PredPtr.
   Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα τον κόμβο που έχει
                για προηγούμενό του αυτόν στον οποίο δείχνει ο PredPtr
                ή διαγράφει τον πρώτο κόμβο, αν ο PredPtr είναι μηδενικός,
                εκτός και αν η λίστα είναι κενή.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο
                να δεικτοδοτείται από τον List.
   Έξοδος:     Ένα μήνυμα κενής λίστας αν η συνδεδεμένη λίστα ήταν κενή .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
           printf("EMPTY LIST\n");
   else
   {
           if (PredPtr == NULL)
        {
                TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
               TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List, void (*Visit)(ListElementType))
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
    ListPointer CurrPtr;

   if (EmptyList(List))
           printf("EMPTY LIST\n");
   else
   {
           CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             (*Visit)(CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}
/**********************************************************/
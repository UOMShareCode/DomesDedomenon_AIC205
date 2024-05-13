
// include's
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**********************************************************/
// Filename ListPADT.h

// #include <stdbool.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);
/**********************************************************/
// #include <stdio.h>
// #include <ctype.h>
// #include "ListPADT.h"

void menu(int *choice);
void list_insertion(ListPointer *List, int choice1);

void append_to_list(ListPointer*, ListElementType);

int main()
{
    ListPointer AList;
    int N, Item, i;

    CreateList(&AList);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, NULL);
    }

    LinkedTraverse(AList);
    printf("\n");

    printf("DWSE TON ARI8MO GIA EISAGWGH STO TELOS THS LISTAS: ");
    scanf("%d", &Item);
    append_to_list(&AList, Item);

    LinkedTraverse(AList);
    printf("\n");

    return 0;
}

void append_to_list(ListPointer *List, ListElementType Item) {
    ListPointer PredPtr, CurrPtr;

    PredPtr = NULL;
    CurrPtr = *List;

    while (CurrPtr != NULL) {
        PredPtr = CurrPtr;
        CurrPtr = CurrPtr->Next;
    }

    LinkedInsert(List, Item, PredPtr);
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Eisagwgh stoixeiwn sth lista\n");
    printf("2. Diasxish stoixeiwn ths listas\n");
    printf("3. Anazhthsh stoixeiou sth lista\n");
    printf("4. Diagrafh stoixeiou apo th lista\n");
    printf("5. Anazhthsh stoixeiou se ordered lista\n");
    printf("6. Telos\n");
    printf("Epilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void list_insertion(ListPointer *List,int choice1)
{
 	ListElementType Item;
    char ch;
    ListPointer PredPtr;
    bool Found;

	do
    {
   	    printf("Enter a number for insertion in the list: "); scanf("%d", &Item);
   	    if (choice1==1)
   	        OrderedLinearSearch(*List, Item, &PredPtr, &Found);
   	    else
            PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
        printf("\nContinue Y/N: ");
        do
        {
      	     scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');
}

/**********************************************************/
// ListPADT.c
/*              ΥΛΟΠΟΙΗΣΗ ΣΥΝΔΕΔΕΜΕΝΗΣ ΛΙΣΤΑΣ ΔΥΝΑΜΙΚΑ - ΜΕ ΔΕΙΚΤΕΣ
                ΤΑ ΣΤΟΙΧΕΙΑ ΤΩΝ ΚΟΜΒΩΝ ΕΙΝΑΙ ΤΥΠΟΥ int */

// #include <stdio.h>
// #include <stdlib.h>
// #include "ListPADT.h"

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

void LinkedTraverse(ListPointer List)
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
   	    // printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
             printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Εκτελεί μια γραμμική αναζήτηση στην μη ταξινομημένη συνδεδεμένη
              λίστα για έναν κόμβο που να περιέχει το στοιχείο Item.
  Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true, ο CurrPtr δείχνει
                στον κόμβο που περιέχει το Item και ο PredPtr στον προηγούμενό του
                ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
    ListPointer CurrPtr;

    CurrPtr = List;
    *PredPtr=NULL;
   *Found= false;
    while (!(*Found) && CurrPtr!=NULL)
    {
         if (CurrPtr->Data==Item )
         	*Found = true;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found)
/* Δέχεται:    Ένα στοιχείο Item και μια ταξινομημένη συνδεδεμένη λίστα,
                που περιέχει στοιχεία δεδομένων σε αύξουσα διάταξη και στην οποία
                ο δείκτης List δείχνει στον πρώτο  κόμβο.
   Λειτουργία: Εκτελεί γραμμική αναζήτηση της συνδεδεμένης ταξινομημένης λίστας
                για τον πρώτο κόμβο που περιέχει το στοιχείο Item ή για μια θέση
                για να εισάγει ένα νέο κόμβο που να περιέχει το στοιχείο Item.
   Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true,
                ο CurrPtr δείχνει στον κόμβο που περιέχει το Item και
                ο PredPtr στον προηγούμενό του ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   bool DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = false;
   *Found = false;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = true;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

/**********************************************************/

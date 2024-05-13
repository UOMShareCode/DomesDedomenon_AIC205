/********************************************************************************/
// Filename TestL_List.c
#include <stdio.h>
#include <ctype.h>
// #include "L_ListADT.h"

// Filename L_ListADT.c
// #include <stdio.h>
// #include "L_ListADT.h"
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// Filename L_ListADT.h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NumberOfNodes 10    /*ενδεικτικό μέγεθος λίστας. Επανορίζεται ανάλογα με την εφαρμογή */

#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef struct {
    int am;
    int mark;
} StudentType;

typedef StudentType ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                ενδεικτικά επιλέχθηκε ο τύπος int. Επανορίζεται ανάλογα με την εφαρμογή*/
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
bool FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// * TestL_List.c
// void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
  ListPointer AList;
  NodeType Node[NumberOfNodes];
  ListPointer FreePtr,PredPtr;
  ListElementType AnItem;
  int i;

  // Βήμα A: Αρχικοποίηση storage pool
  InitializeStoragePool(Node, &FreePtr);

  // Βήμα B: Δημιουργία κενής ΣΛ (μέγιστο μέγεθος 10)
  CreateList(&AList);

  // Βήμα C: Εμφάνιση της storage pool
  printf("Question C\n");
  printAll(AList, FreePtr, Node);

  // Βήμα D: Εμφάνιση των στοιχείων της ΣΛ
  printf("Question D\n");
  TraverseLinked(AList, Node);

  // Βήμα E: Εισαγωγή 5 στοιχείων στην ΣΛ. (Η εισαγωγή στοιχείου θα γίνεται πάντα στην αρχή της ΣΛ)
  printf("Question E\n");
  for (i=0; i<5; i++) {
    printf("DWSE am: ");
    scanf("%d", &AnItem.am);
    printf("DWSE mark: ");
    scanf("%d", &AnItem.mark);
    // insert the new student
    PredPtr=NilValue;
    Insert(&AList, Node, &FreePtr, PredPtr, AnItem);
  }

  // Βήμα F: Εμφάνιση της storage pool
  printf("Question F\n");
  printAll(AList, FreePtr, Node);

  // Βήμα G: Εμφάνιση των στοιχείων της ΣΛ
  printf("Question G\n");
  TraverseLinked(AList, Node);

  // Βήμα H: Διαγραφή ενός στοιχείου της ΣΛ
  printf("Question H\n");
  printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
  scanf("%d", &PredPtr);
  Delete(&AList, Node, &FreePtr, PredPtr);
  
  // Βήμα I: Εμφάνιση της storage pool
  printf("Question I\n");
  printAll(AList, FreePtr, Node);

  // Βήμα J: Εμφάνιση των στοιχείων της ΣΛ
  printf("Question J\n");
  TraverseLinked(AList, Node);
}

// int main()
// {
//     ListPointer AList;
//     NodeType Node[NumberOfNodes];
//     ListPointer FreePtr,PredPtr;

//     ListElementType AnItem;

//    int choice;
//    char ch;

//    InitializeStoragePool(Node, &FreePtr);
//    printAll(AList, FreePtr, Node);
//    do
//    {
//    	menu(&choice);
//       switch(choice)
//       {
//       	  case 1: CreateList(&AList);          //DHMIOYRGIA LISTAS
//       	             break;
//           case 2:	do
//                     {
//    	                    printf("FreePtr=%d\n",FreePtr);
//                         printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
//                         scanf("%d", &AnItem);
//                         /*H EISAGWGH STOIXEIOY GINETAI PANTA STHN ARXH THS LISTAS (STO PX SYMPERIFERETAI WS STOIBA)
//                         * SE PERIPTWSH POY 8ELW PX  TAXINOMHMENH LISTA 8A PREPEI NA YLOPOIHSW EPIPLEON SYNARTHSH SEARCH
//                         * POY 8A EPISTREFEI TH TIMH THS PredPtr
//                         */
//                         PredPtr=NilValue;
//                         Insert(&AList, Node,&FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH PredPtr STH LISTA
//                         printf("AList=%d\n",AList);
//                         printf("Continue Y/N: ");
//                         do
//                         {
//       	                     scanf("%c", &ch);
//                         } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
//                     } while (toupper(ch)!='N');
//                     printAll(AList, FreePtr, Node);
//                     break;
//           case 3:	printf("FreePtr=%d\n",FreePtr);
//                     TraverseLinked(AList, Node);      //DIASXISH LISTAS
//          			break;
//           case 4:   if (EmptyList(AList))
//       	                 printf("Empty List\n");
//       	            else
//       	            {
//                         printAll(AList, FreePtr, Node);
//                         printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
//                         scanf("%d", &PredPtr);
//                         Delete(&AList, Node, &FreePtr, PredPtr);  //DIAGRAFH STOIXEIOY META TH 8ESH PredPtr STH LISTA
//                         printAll(AList, FreePtr, Node);
//                     }
//          			break;
//           case 5:   if (EmptyList(AList))
//       	                 printf("Empty List\n");
//       	            else printf("Not an Empty List\n");
//       	            break;
//       	case 6:   if (FullList(FreePtr))
//       	                 printf("Full List\n");
//       	            else printf("Not a Full List\n");
//       	            break;
//       	 case 7:	printAll(AList, FreePtr, Node);     //EMFANISH STORAGE POOL
//          			break;
// 	  }
//    } while (choice!=8);
// 	return 0;
// }

// void menu(int *choice)
// {
//     printf("                  MENOY                  \n");
//     printf("-------------------------------------------------\n");
//     printf("1. Create List\n");
//     printf("2. Insert an element to List\n");
//     printf("3. Traverse List\n");
//     printf("4. Delete an element from the List\n");
//     printf("5. Check if List is empty\n");
//     printf("6. Check if List is full\n");
//     printf("7. Print storage pool\n");
//     printf("8. Telos\n");
//     printf("Choice 1-8 : ");
//     do
//     {
//     	scanf("%d", choice);
//     } while (*choice<1 && *choice>7);
// }

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d, %d->%d) ", i, Node[i].Data.am, Node[i].Data.mark, Node[i].Next);
    printf("\n");
}
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// * L_ListADT.c
/*               ΥΛΟΠΟΙΗΣΗ ΣΥΝΔΕΔΕΜΈΝΗΣ ΛΊΣΤΑΣ ΜΕ ΠΙΝΑΚΑ
         TA ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΥΝΔΕΔΕΜΕΝΗΣ ΛΙΣΤΑΣ ΕΙΝΑΙ ΤΥΠΟΥ int
*/

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
    int i;

    // Initialize each node in the array
    for (i = 0; i < NumberOfNodes - 1; i++) {
        Node[i].Next = i + 1;
        Node[i].Data.am = -1;    // Initialize with -1 (optional, for printing)
        Node[i].Data.mark = -1;  // Initialize with -1 (optional, for printing)
    }
    
    // Last node points to NilValue to indicate end of the list
    Node[NumberOfNodes - 1].Next = NilValue;
    Node[NumberOfNodes - 1].Data.am = -1;    // Initialize with -1 (optional, for printing)
    Node[NumberOfNodes - 1].Data.mark = -1;  // Initialize with -1 (optional, for printing)

    // Set FreePtr to point to the first available node (index 0)
    *FreePtr = 0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

bool EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

bool FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  Node[P].Data.mark = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.am =Item.am;
        Node[TempPtr].Data.mark =Item.mark;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
        CurrPtr = List;
        while (CurrPtr != NilValue)
        {
            printf("(%d: %d, %d->%d) ", CurrPtr, Node[CurrPtr].Data.am, Node[CurrPtr].Data.mark, Node[CurrPtr].Next);
            CurrPtr = Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else
    {
        printf("Empty List ...\n");
    }
}

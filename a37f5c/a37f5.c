// include's
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**********************************************************/
// * Filename   BstUsADT.h

// #include <stdbool.h>

typedef struct
{
    int id;
    char password[10];
} BinTreeElementType;                   /*ο τύπος των στοιχείων του ΔΔΑ είναι
                                        τύπου struct */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
/**********************************************************/



/**********************************************************/
// filename ValUsers.c

// ΕΛΕΓΧΟΣ ΤΑΥΤΟΤΗΤΑΣ ΧΡΗΣΤΩΝ

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "BstUsADT.h"

void Login(BinTreeElementType *UserRec,bool *MoreUsers);
void BuildTree(FILE *UsersFile,BinTreePointer *UserTree, bool *stop);

int main()
{
    FILE *UsersFile;
    BinTreeElementType UserRec;
    BinTreePointer UserTree;
    BinTreePointer LocPtr;
    bool Found, MoreUsers, stop;

    UsersFile = fopen("Users.txt", "r");
    if (UsersFile == NULL)
        printf("Cannot open Users file\n");
    else
    {
        printf("DWSE 0 GIA NA TERMATISEI TO PROGRAMMA\n");
        BuildTree(UsersFile,&UserTree,&stop);
        if (!stop)
        {
            InorderTraversal(UserTree);
            Login(&UserRec,&MoreUsers);
            while (MoreUsers)
            {
                BSTSearch(UserTree,UserRec,&Found,&LocPtr);
                if (Found)
                    if (strcmp(LocPtr->Data.password,UserRec.password)==0)
                        printf("EGKYROS XRHSTHS!\n");
                    else
                        printf("MH EGKYRO password!\n");
                else
                    printf("MH EGKYRO User-Id!\n");
                Login(&UserRec,&MoreUsers);
            }
        }
    }
    return 0;
}

void BuildTree(FILE *UsersFile,BinTreePointer *UserTree, bool *stop)
{
    BinTreeElementType UserRec;
    int nscan;
    char termch;

    CreateBST(&(*UserTree));
    while (true)
    {
        nscan = fscanf(UsersFile, "%d, %10[^\n]%c",
                               &UserRec.id, UserRec.password,&termch);
        if (nscan == EOF) break;
        if (nscan != 3 || termch != '\n')
        {
            printf("Improper file format\n");
            exit(1);
        }
        else
            BSTInsert(&(*UserTree),UserRec);
   }
}

void Login(BinTreeElementType *UserRec,bool *MoreUsers)
{
    printf("User-Id? ");
    scanf("%d",&(UserRec->id));
    if (UserRec->id ==0)
        *MoreUsers=false;
    else
    {
        *MoreUsers=true;
        printf("Password? ");
        scanf("%s",UserRec->password);
   }
}
/**********************************************************/



/**********************************************************/
// Filename   BstUsADT.c
/*                 ΥΛΟΠΟΙΗΣΗ ΔΔΑ ΔΥΝΑΜΙΚΑ ΜΕ ΔΕΙΚΤΕΣ
                    ΤΑ ΣΤΟΙΧΕΙΑ ΤΩΝ ΚΟΜΒΩΝ ΤΟΥ ΔΔΑ ΕΙΝΑΙ ΤΥΠΟΥ struct*
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "BstUsADT.h"

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

bool EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: true αν το ΔΔΑ είναι κενό και false διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    bool Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = false;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.id < LocPtr ->Data.id)
            LocPtr = LocPtr ->LChild;
        else if (Item.id > LocPtr ->Data.id)
            LocPtr = LocPtr ->RChild;
        else
            Found = true;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
 //       LocPtr ->Data = Item;
        LocPtr ->Data.id = Item.id;
        strcpy(LocPtr ->Data.password,Item.password);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.id < Parent ->Data.id)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή true και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή false
*/
{
    bool stop;

    *LocPtr = Root;
    stop = false;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.id < (*LocPtr)->Data.id)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.id > (*LocPtr)->Data.id)
                *LocPtr = (*LocPtr)->RChild;
            else stop = true;
    }
   *Found=stop;
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή true, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή false.
*/
{
    bool stop;
    BinTreePointer TempParent;

    *LocPtr = Root;
    TempParent=NULL;
    stop = false;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.id < (*LocPtr)->Data.id) {
            TempParent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.id > (*LocPtr)->Data.id) {
                TempParent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else stop = true;
    }
   *Found=stop;
   *Parent=TempParent;
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   R,
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   bool Found;       // true AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     R=*Root;
     BSTSearch2(R, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO DEN EINAI STO DDA\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d, %s\n",Root->Data.id,Root->Data.password);
        InorderTraversal(Root->RChild);
    }
}
/**********************************************************/
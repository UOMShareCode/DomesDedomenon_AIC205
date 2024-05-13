/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "ListADT.h"
// #include <stdio.h>
// #include <stdlib.h>
#include <ctype.h>
// #include "ListADT.h"
/********************************************************************************/
// * ListADT.h
#define ListLimit 100    //ενδεικτικό μέγεθος λίστας. Επανορίζεται ανάλογα με την εφαρμογή

// my structure
typedef struct {
    int am;
    char name[20];
} Student;

typedef Student ListElementType;   /*τύπος δεδομένων για τα στοιχεία της λίστας. ενδεικτικά επιλέχθηκε ο τύπος int.
                                Επανορίζεται ανάλογα με την εφαρμογή */
typedef struct {
    int Size;
    ListElementType Element[ListLimit];
} ListType;

void CreateList(ListType *List);
bool EmptyList(ListType List);
bool FullList(ListType List);
void Insert(ListType *List, ListElementType Item, int Pos);
void Delete(ListType *List, int Pos);
void TraverseList(ListType List);
/********************************************************************************/

/**
 * Τμήμα Εφαρμοσμένης Πληροφορικής
ΔΟΜΕΣ ΔΕΔΟΜΕΝΩΝ
Εξάμηνο Β' Φύλλο Ασκήσεων 4: ΛΙΣΤΑ (σειριακή αποθήκευση), ΣΥΝΔΕΔΕΜΕΝΗ ΛΙΣΤΑΣΤΟΙΒΑ – ΟΥΡΑ (υλοποίηση με δείκτες)
Μάγια Σατρατζέμη, Γεωργία Κολωνιάρη, Αλέξανδρος Καρακασίδης

---

Παρατηρήσεις για τις ασκήσεις με Απλή Συνδεδεμένη Λίστα (ΑΣΛ):

1. Τα δεδομένα εισόδου διαβάζονται πάντα με ξεχωριστές εντολές scanf( ) το καθένα και με τη σειρά που δηλώνονται στιςεκφωνήσεις.
2. Αντίστοιχα για τα δεδομένα εξόδου και όπου δεν υπάρχουν περαιτέρω διευκρινήσεις για τη μορφή τους, αυτάθαεμφανίζονται με ξεχωριστές εντολές printf( ) το καθένα και με τη σειρά που δηλώνονται στις εκφωνήσεις.
3. Τα στοιχεία των κόμβων της Α.Σ.Λ. θα εμφανίζονται σε μια γραμμή με ένα κενό χαρακτήρα μεταξύ τους. Σε περίπτωσηπουοι κόμβοι της Α.Σ.Λ. περιέχουν περισσότερα από ένα στοιχεία, τότε τα στοιχεία κάθε κόμβου θα εμφανίζονται σεμιαγραμμή με ένα κενό χαρακτήρα μεταξύ τους, ενώ κάθε κόμβος θα εμφανίζεται σε διαφορετική γραμμή.  Αν κατά τη διάσχιση της λίστας διαπιστώσετε ότι η Α.Σ.Λ. είναι κενή, τότε να εμφανίζετε το μήνυμα‘EMPTYLIST’.
4. Σ’ όλα τα προγράμματα η ΑΣΛ ή οι ΑΣΛ θεωρούνται δεδομένες, βέβαια θα πρέπει να την/τις κατασκευάσετε διαβάζονταςταδεδομένα ως εξής : πλήθος στοιχείων λίστας, στοιχεία λίστας ή αν πρόκειται για 2 λίστες τότε θα τα διαβάζετεωςεξής:πλήθος στοιχείων λίστας1, στοιχεία λίστας1, πλήθος στοιχείων λίστας2, στοιχεία λίστας
5. ΠΡΟΣΟΧΗ: Οι ασκήσεις θα πρέπει να λύνονται με χρήση του κώδικα που υλοποιεί τον ΑΤΔ ΑΣΛ. Oκώδικαςπουσαςδίνεται περιλαμβάνεται στο code.zip στην αντίστοιχη διάλεξη. Οι συναρτήσεις που υλοποιούν τις βασικές λειτουργίεςτου ΑΤΔ ΑΣΛ δεν τροποποιούνται. Τροποποιήσεις μπορούν να γίνουν ανάλογα με τη άσκηση και εφόσον χρειάζεται στοπλήθος των στοιχείων της ΑΣΛ, στον τύπο του στοιχείου της ΑΣΛ και στη συνάρτηση (διάσχιση) που εμφανίζει τουςκόμβους

---

Σε μια Λίστα καταχωρούμε τα στοιχεία ενός μαθητή και συγκεκριμένα τον Αριθμό Μητρώο(int) καιτοονοματεπώνυμο του (20 χαρακτήρες).

Τα στοιχεία της λίστας επιθυμούμε να είναι ταξινομημένα ως προς τονΑριθμόΜητρώο.

Υλοποιείστε τη συνάρτηση search η οποία θα μπορεί να χρησιμοποιηθεί πριν την εισαγωγή ενός στοιχείουστηλίστα ώστε αυτή να διατηρείται ταξινομημένη.

Η συνάρτηση θα επιστρέφει μια bool τιμή η οποία δείχνει αν βρέθηκεήόχιτο αναζητούμενο στοιχείο και θα έχει παραμέτρους τη λίστα, το αναζητούμενο στοιχείο στη λίστα, τη θέσηστηλίστατουπροηγούμενου στοιχείου σε σχέση με το αναζητούμενο.

Επιπλέον η συνάρτηση search θα πρέπει ναμπορείναχρησιμοποιηθεί εκτός από την εισαγωγή στοιχείου στην ταξινομημένη λίστα, για τη διαγραφή στοιχείου, ώστεηλίσταναπαραμένει ταξινομημένη όπως και για την αναζήτηση στοιχείου.

Γράψτε πρόγραμμα στο οποίο θα εισάγετε 3μαθητέςστηλίστα, με κάθε εισαγωγή η λίστα θα πρέπει να διατηρείται ταξινομημένη.

Στη συνέχεια θα εμφανίσετε ταστοιχείατηςλίστας, θα καλέσετε την search για να εντοπίσετε αν ένα στοιχείο υπάρχει στην ταξινομημένη λίστα, θα καλέσετετηsearchγια να διαγράφετε ένα στοιχείο από τη λίστα.

Στη συνέχεια θα εμφανίζετε τα στοιχεία της λίστας. Για την υλοποίησητουΑΤΔ λίστα κάντε χρήση του πακέτου ΑΤΔ Λίστα με Πίνακα (ListADT.h, ListADT.c).

Δίνονται 2 στιγμιότυπα εκτέλεσης:

| Στιγμιότυπο 1 | Στιγμιότυπο 2 |
| --- | --- |
| DWSE AM : 12<br><br/>DWSE Name: ANNA NIKOLAOU<br><br/>DWSE AM : 3<br><br/>DWSE Name: NIKOS APOSTOLOU<br><br/>DWSE AM : 15<br><br/>DWSE Name: KWSTAS IWANNOU<br><br/><br/>Plithos stoixeiwn sth lista 3<br><br/>3, NIKOS APOSTOLOU<br><br/>12, ANNA NIKOLAOU<br><br/>15, KWSTAS IWANNOU<br><br/><br/>DWSE AM : 23<br><br/>Not found<br><br/>DWSE AM : 12<br/>Plithos stoixeiwn sth lista 2<br><br/>3, NIKOS APOSTOLOU<br><br/>15, KWSTAS IWANNOU | DWSE AM : 12 <br/>DWSE Name: ANNA NIKOLAOU <br/>DWSE AM : 3 <br/>DWSE Name: NIKOS APOSTOLOU <br/>DWSE AM : 15 <br/>DWSE Name: KWSTAS IWANNOU <br/><br/>Plithos stoixeiwn sth lista 3 <br/>3, NIKOS APOSTOLOU <br/>12, ANNA NIKOLAOU <br/>15, KWSTAS IWANNOU <br/><br/>DWSE AM : 15 <br/>15, KWSTAS IWANNOU <br/>DWSE AM : 3<br/>Plithos stoixeiwn sth lista 2 <br/>12, ANNA NIKOLAOU <br/>15, KWSTAS IWANNOU |
*/

/********************************************************************************/
/********************************************************************************/
/********************************************************************************/


/* my code
 @author Aristeidis Alexandridis
 @copyright 2024
 @note this is my code
*/

// prototypes
bool search(ListType list, ListElementType item, int *pos);

// main
int main()
{
    // create list
    ListType AList;
    ListElementType AnItem;
    int i = 0;
    int pos = -1;

    // create student list
    CreateList(&AList);

    // insert 3 students
    for (i = 0; i < 3; i++) {
        printf("DWSE AM : ");
        scanf("%d", &AnItem.am);

        printf("DWSE Name: ");
        scanf(" %[^\n]", AnItem.name);

        // search for the correct position to insert the new student
        int index = 0;
        while (index < AList.Size && AList.Element[index].am < AnItem.am) {
            index++;
        }

        // insert the new student at the correct position
        for (int j = AList.Size; j > index; j--) {
            AList.Element[j] = AList.Element[j - 1];
        }
        AList.Element[index] = AnItem;
        AList.Size++;
    }

    // show the list
    TraverseList(AList);

    // search for a student
    printf("DWSE AM : ");
    scanf("%d", &AnItem.am);
    if (search(AList, AnItem, &pos)) {
        printf("%d, %s\n", AList.Element[pos].am, AList.Element[pos].name);
    } else {
        printf("Not found\n");
    }

    // delete a student
    printf("DWSE AM : ");
    scanf("%d", &AnItem.am);
    if (search(AList, AnItem, &pos)) {
        for (int j = pos; j < AList.Size - 1; j++) {
            AList.Element[j] = AList.Element[j + 1];
        }
        AList.Size--;
    }

    // show the list
    TraverseList(AList);

    return 0;
}

// functions
bool search(ListType list, ListElementType item, int *pos)
{
    *pos = -1;
    for (int i = 0; i < list.Size; i++) {
        if (list.Element[i].am == item.am) {
            *pos = i;
            return true;
        }
    }
    return false;
}

/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// Filename TestList.c

// void menu(int *choice);

// int main()
// {
//     int Apos;
//     ListElementType AnItem;
//     ListType AList;

//    int choice;
//    char ch;

//    do
//    {
//    	menu(&choice);
//       switch(choice)
//       {
//       	  case 1: CreateList(&AList);          //DHMIOYRGIA LISTAS
//       	             break;
//           case 2: do
//                 {
//    	                printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
//                     scanf("%d", &AnItem);
//                     do {
//                         printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
//                         scanf("%d", &Apos);
//                     } while (Apos<-1 || Apos>AList.Size-1);
//                     Insert(&AList, AnItem, Apos);    //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
//                     printf("Continue Y/N: ");
//                     do
//                     {
//       	                 scanf("%c", &ch);
//                     } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
//                 } while (toupper(ch)!='N');
//                 break;
//           case 3:	TraverseList(AList);      //DIASXISH LISTAS
//          			break;
//           case 4:  if (EmptyList(AList))
//       	                 printf("Empty List\n");
//       	            else
//                     {
//                         do {
//                             printf("DWSE TH 8ESH TOY STOIXEIOY GIA DIAGRAFH: ");
//                             scanf("%d", &Apos);
//                         } while (Apos<0 || Apos>AList.Size-1);
//                         Delete(&AList,Apos);  //DIAGRAFH STOIXEIOY STH 8ESH POS STH LISTA
//                     }
//          			    break;

//           case 5:   if (EmptyList(AList))
//       	                 printf("Empty List\n");
//       	            else printf("Not an Empty List\n");
//       	            break;
// 	  }
//    } while (choice!=6);
//     system("pause");
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
//     printf("6. Telos\n");
//     printf("Choice 1-6 : ");
//     do
//     {
//     	scanf("%d", choice);
//     } while (*choice<1 && *choice>6);
// }
/********************************************************************************/
/********************************************************************************/
// * ListADT.c
/*                     (* YLOPOIHSH LISTAS ME PINAKA *)
              (*TA STOIXEIA THS LISTAS EINAI TYPOY integer*)
*/
void CreateList(ListType *List)
/* Λειτουργία: Δημιουργεί μια κενή λίστα.
   Επιστρέφει: Μια κενή λίστα
*/
{
    List -> Size = 0;
}

bool EmptyList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι κενή.
   Επιστρέφει: True αν η λίστα List είναι άδεια, false διαφορετικά
*/
{
    return (List.Size == 0);
}

bool FullList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Ελέγχει αν η λίστα List είναι γεμάτη.
   Επιστρέφει: True αν η λίστα List είναι γεμάτη, false διαφορετικά
*/
{
    return (List.Size == (ListLimit));
}

void Insert(ListType *List, ListElementType Item, int Pos)
/* Δέχεται:    Μια λίστα List, το στοιχείο Item και τη θέση Pos μέσα στη λίστα.
   Λειτουργία: Εισάγει, στη λίστα List, αν δεν είναι γεμάτη, μετά τη θέση Pos
                το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Εξοδος:     Mήνυμα γεμάτης λίστας, αν η λίστα List είναι γεμάτη
*/
{
    int i;
    if (FullList(*List))
        printf("Full list...\n");
    else
    {
        for (i=List->Size-1; i>=Pos+1;i--)
            List->Element[i+1] = List ->Element[i];
        List->Element[Pos+1]=Item;
        List->Size++;
    }
}

void Delete(ListType *List, int Pos)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Διαγράφει από τη λίστα List, αν δεν είναι κενή,
                το στοιχείο που βρίσκεται στη θέση Pos.
   Επιστρέφει: Την τροποποιημένη λίστα List.
   Έξοδος:     Μήνυμα κενής λίστας, αν η λίστα List είναι κενή

*/
{
    int i;
    if (EmptyList(*List))
        printf("Empty list...\n");
    else
    {
        for (i=Pos; i<List->Size-1; i++)
            List->Element[i] = List ->Element[i+1];
        List->Size--;
    }
}

void TraverseList(ListType List)
/* Δέχεται:    Μια λίστα List.
   Λειτουργία: Κάνει διάσχιση της λίστα List, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
    int i;
    if (EmptyList(List))
      	printf("Empty List\n");
    else
    {
        printf("\nPlithos stoixeiwn sth lista %d\n",List.Size);
        for (i=0;i<List.Size;i++) {
            printf("%d, %s\n",List.Element[i].am, List.Element[i].name);
        }
        printf("\n");
    }
}
/********************************************************************************/
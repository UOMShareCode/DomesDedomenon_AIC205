/********************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 20  //το όριο μεγέθους της ουράς
/********************************************************************************/


/********************************************************************************/
// * QueueADT.h
typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
/********************************************************************************/



/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// * TestQueue.c
// void menu(int *choice);
void TraverseQ(QueueType Queue);


// my functions
void RemoveAndAdd(QueueType *Queue, int num) {
    for(int i = 0; i < num; i++) {
        QueueElementType removedItem;
        RemoveQ(Queue, &removedItem);
        AddQ(Queue, removedItem);
    }
}

int main()
{
    /**
    Παρατηρήσεις:
        1. Τα δεδομένα εισόδου διαβάζονται πάντα με ξεχωριστές εντολές scanf( ) το καθένα και με τη σειράπουδηλώνονται στις εκφωνήσεις. 
        2. Αντίστοιχα για τα δεδομένα εξόδου και όπου δεν υπάρχουν περαιτέρω διευκρινήσεις για τη μορφή τους, αυτάθαεμφανίζονται με ξεχωριστές εντολές printf(“ ..\n”) το καθένα και με τη σειρά που δηλώνονται στις εκφωνήσεις.
            i) Τα στοιχεία των κόμβων της ουράς θα εμφανίζονται σε μια γραμμή με ένα κενό χαρακτήρα μεταξύτους. Σεπερίπτωση που οι κόμβοι της ουράς περιέχουν περισσότερα από ένα στοιχεία, τότε τα στοιχείακάθεκόμβου θα εμφανίζονται σε μια γραμμή με ένα κενό χαρακτήρα μεταξύ τους, ενώ κάθε κόμβοςθαεμφανίζεται σε διαφορετική γραμμή.
        3. Σε όσες από τις ασκήσεις θεωρείται δεδομένη η ύπαρξη ουράς θα πρέπει προηγουμένως να τη δημιουργήσετε.
        4. ΠΡΟΣΟΧΗ: Οι ασκήσεις θα πρέπει να λύνονται με χρήση του κώδικα που υλοποιεί τον ΑΤΔ ουρά. Oκώδικαςπου σας δίνεται περιλαμβάνεται στο code.zip στην αντίστοιχη διάλεξη. Οι συναρτήσεις που υλοποιούντιςβασικές λειτουργίες του ΑΤΔ ουρά δεν τροποποιούνται. Τροποποιήσεις μπορούν να γίνουν ανάλογαμετηάσκηση και εφόσον χρειάζεται μόνο στο πλήθος των στοιχείων της ουράς και στον τύπο του στοιχείουτηςουράς και στη συνάρτηση TraverseQ (είναι βοηθητική συνάρτηση, δεν υλοποιεί λειτουργία του ΑΤΔουρά).
    */

    /**
        Γράψτε ένα πρόγραμμα που δημιουργεί 2 ουρές μια για άρτιους και μια για περιττούς αριθμούς (QueueLimit =20).
        Στη συνέχεια, θα ζητείται ένας αριθμός και θα διαγράφεται αντίστοιχος αριθμός στοιχείων από κάθεουρά.
        Κάθε φορά που διαγράφεται ένα στοιχείο θα εισάγεται εκ νέου στην αντίστοιχη ουρά.
        Η διαγραφή των στοιχείωνκαι επανεισαγωγή τους θα γίνει με συνάρτηση με 2 παραμέτρους την ουρά και τον αριθμό.
        Για τον έλεγχοτηςορθότητας του κώδικα εμφανίστε τα στοιχεία της κάθε ουράς (χρήση της TraverseQ).
        Δίνεται ένα στιγμιότυποεκτέλεσης:
        ```
        EvenQueue
        0 2 4 6 8 10 12 14 16 18
        OddQueue
        1 3 5 7 9 11 13 15 17 19
        Give number of items = 4
        EvenQueue
        8 10 12 14 16 18 0 2 4 6
        Give number of items = 3
        OddQueue
        7 9 11 13 15 17 19 1 3 5
        ```
    */

    QueueType evenQueue, oddQueue;
    CreateQ(&evenQueue);
    CreateQ(&oddQueue);

    int i, num;
    QueueElementType item;

    // Add elements to the queues
    for (i = 0; i < QueueLimit; i++) {
        if (i % 2 == 0) {
            AddQ(&evenQueue, i);
        } else {
            AddQ(&oddQueue, i);
        }
    }

    // Print the initial state of the queues
    printf("EvenQueue\n");
    TraverseQ(evenQueue);
    printf("OddQueue\n");
    TraverseQ(oddQueue);

    // Prompt the user for the number of items to be removed and added back for the EvenQueue
    printf("Give number of items = ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        RemoveQ(&evenQueue, &item);
        AddQ(&evenQueue, item);
    }

    // Print the updated state of the EvenQueue
    printf("EvenQueue\n");
    TraverseQ(evenQueue);

    // Prompt the user for the number of items to be removed and added back for the OddQueue
    printf("Give number of items = ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        RemoveQ(&oddQueue, &item);
        AddQ(&oddQueue, item);
    }

    // Print the updated state of the OddQueue
    printf("OddQueue\n");
    TraverseQ(oddQueue);

	return 0;
}

// void menu(int *choice)
// {
//     printf("                  MENOY                  \n");
//     printf("-------------------------------------------------\n");
//     printf("1 ---- DHMIOYRGIA OURAS\n");
//     printf("2 ---- ADEIASMA THS OYRAS\n");
//     printf("3 ---- ELEGXOS KENHS OYRAS\n");
//     printf("4 ---  DIAGRAFH STOIXEIOY APO THN ARXH THS OYRAS\n");
//     printf("5 ---  PROS8HKH STOIXEIOY STO TELOS THS OYRAS\n");
//     printf("6 ---- EMFANISH STOIXEIWN OURAS (BOH8HTHKH)\n");
//     printf("7 ---- EXIT\n");
//     printf("Choice: ");
//     do
//     {
//     	scanf("%d", choice);
//     } while (*choice<1 && *choice>7);
// }

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/



/********************************************************************************/
// QueueADT.c
void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

bool EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

bool FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}
/********************************************************************************/

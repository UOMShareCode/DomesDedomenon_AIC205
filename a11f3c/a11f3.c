/********************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define QueueLimit 8  //το όριο μεγέθους της ουράς
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
QueueElementType minElement(QueueType Queue) {
    QueueElementType min = Queue.Element[Queue.Front];
    for(int i = (Queue.Front + 1) % QueueLimit; i != Queue.Rear; i = (i + 1) % QueueLimit) {
        if(Queue.Element[i] < min) {
            min = Queue.Element[i];
        }
    }
    return min;
}

QueueElementType maxElement(QueueType Queue) {
    QueueElementType max = Queue.Element[Queue.Front];
    for(int i = (Queue.Front + 1) % QueueLimit; i != Queue.Rear; i = (i + 1) % QueueLimit) {
        if(Queue.Element[i] > max) {
            max = Queue.Element[i];
        }
    }
    return max;
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
        Γράψτε δύο συναρτήσεις minElement, maxElement, που θα δέχονται την ουρά (με αναφορά) και θα επιστρέφουντο μικρότερο και μεγαλύτερο στοιχείο μίας ουράς αντίστοιχα.
        Για την υλοποίηση των παραπάνωσυναρτήσεωνμπορούν να χρησιμοποιηθούν μόνο οι λειτουργίες EmptyQ, AddQ και RemoveQ και η ουρά θαπαραμένει
        αναλλοίωτη μετά την κλήση των συναρτήσεων.
        Στη συνέχεια γράψτε κυρίως πρόγραμμα, στοοποίοδημιουργείται ουρά μεγέθους 8, η οποία γεμίζει από το πληκτρολόγιο με χαρακτήρες, εκτυπώνεται ηουρά, τομικρότερο και το μεγαλύτερο στοιχείο της και εκτυπώνεται η ουρά.
        Δίνεται στιγμιότυπο εκτέλεσης:
        ```
        Dwse stoixeio:C
        Dwse stoixeio:D
        Dwse stoixeio:E
        Dwse stoixeio:T
        Dwse stoixeio:B
        Dwse stoixeio:I
        Dwse stoixeio:A
        C D E T B I A
        Min: A, Max: T
        C D E T B I A
        ```
    */

    QueueType queue;
    CreateQ(&queue);

    // Add elements to the queue
    for(int i = 0; i < QueueLimit - 1; i++) {
        char item;
        printf("Dwse stoixeio:");
        scanf(" %c", &item);
        AddQ(&queue, item);
    }

    // Print the queue
    TraverseQ(queue);

    // Find the minimum and maximum element of the queue
    QueueElementType min = minElement(queue);
    QueueElementType max = maxElement(queue);
    printf("Min: %c, Max: %c\n", min, max);

    // Print the queue again to show that it is unchanged
    TraverseQ(queue);


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
            printf("%c ", Queue.Element[current]);
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

/********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// #include "QueueADT.h"
// #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include "QueueADT.h"
/********************************************************************************/
// * QueueADT.h
#define QueueLimit 100  //το όριο μεγέθους της ουράς

typedef struct {
    char name[20];
    float price;
    int weight;
    char expiration_date[10];
} Product;

typedef Product QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
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












    /**
     * Παρατηρήσεις:
    1. Τα δεδομένα εισόδου διαβάζονται πάντα με ξεχωριστές εντολές scanf( ) το καθένα και με τη σειράπουδηλώνονται στις εκφωνήσεις.
    2. Αντίστοιχα για τα δεδομένα εξόδου και όπου δεν υπάρχουν περαιτέρω διευκρινήσεις για τη μορφή τους, αυτάθαεμφανίζονται με ξεχωριστές εντολές printf(“ ..\n”) το καθένα και με τη σειρά που δηλώνονται στις εκφωνήσεις.
        1. Τα στοιχεία των κόμβων της ουράς θα εμφανίζονται σε μια γραμμή με ένα κενό χαρακτήρα μεταξύτους. Σεπερίπτωση που οι κόμβοι της ουράς περιέχουν περισσότερα από ένα στοιχεία, τότε τα στοιχείακάθεκόμβου θα εμφανίζονται σε μια γραμμή με ένα κενό χαρακτήρα μεταξύ τους, ενώ κάθε κόμβοςθαεμφανίζεται σε διαφορετική γραμμή.
    3. Σε όσες από τις ασκήσεις θεωρείται δεδομένη η ύπαρξη ουράς θα πρέπει προηγουμένως να τη δημιουργήσετε.
    4. ΠΡΟΣΟΧΗ: Οι ασκήσεις θα πρέπει να λύνονται με χρήση του κώδικα που υλοποιεί τον ΑΤΔ ουρά. Oκώδικαςπου σας δίνεται περιλαμβάνεται στο code.zip στην αντίστοιχη διάλεξη. Οι συναρτήσεις που υλοποιούντιςβασικές λειτουργίες του ΑΤΔ ουρά δεν τροποποιούνται. Τροποποιήσεις μπορούν να γίνουν ανάλογαμετηάσκηση και εφόσον χρειάζεται μόνο στο πλήθος των στοιχείων της ουράς και στον τύπο του στοιχείουτηςουράς και στη συνάρτηση TraverseQ (είναι βοηθητική συνάρτηση, δεν υλοποιεί λειτουργία του ΑΤΔουρά).
    ---
    16. Δίνεται το αρχείο κειμένου product.dat με τα προϊόντα ψυγείου μιας εταιρείας τροφίμων το οποίογιακάθεπροϊόν περιλαμβάνει τα εξής στοιχεία:
    Ονομα προϊόντος (20 χαρακτήρες)
    Τιμή (float)
    Βάρος (int)
    Ημερομηνία λήξης (10 χαρακτήρες)
    Τα προϊόντα στο αρχείο είναι ταξινομημένα σε αύξουσα σειρά ως προς την ημερομηνία λήξης. Να γίνει πρόγραμμα που θα περιλαμβάνει τις εξής συναρτήσεις:
    1. readInput: δέχεται ως παράμετρο μια ουρά. Θα διαβάζει τις εγγραφές του αρχείου product.dat και θατιςκαταχωρεί σε μια ουρά.
    2. removeExpiredProducts: δέχεται ως παράμετρο μια ουρά. Η συνάρτηση θα διαβάζει μια ημερομηνίααπότοπληκτρολόγιο και θα διαγράφει από την ουρά όσα προϊόντα έχουν ημερομηνία ίση ή προηγούμενητηςδοθείσας ημερομηνίας.
    3. getFront: δέχεται ως παράμετρο μια ουρά και επιστρέφει το εμπρός στοιχείο της ουράς χωρίς νατοδιαγράφει από την ουρά. Για την υλοποίηση της getFront δεν απαιτείται η χρήση των βασικών λειτουργιώντου ΑΤΔ ουρά, μπορεί να γίνει με άμεση προσπέλαση του εμπρός στοιχείου. Η getFront θα χρησιμοποιηθεί
        στην υλοποίηση της RemoveExpiredproducts.
    Θα εμφανίζετε τα στοιχεία της ουράς μετά το διάβασμα των εγγραφών του αρχείου και την εισαγωγήτους στηνουρά όπως και μετά την διαγραφή των προϊόντων που έχουν λήξει, όπως φαίνεται στο στιγμιότυπο εκτέλεσης.
    Επίσης κάθε φορά που εκτελείται η getFront θα εμφανίζετε τις τιμές του εμπρός στοιχείου της ουράς όπωςφαίνεται στο στιγμιότυπο εκτέλεσης.
    */
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// * TestQueue.c

// prototypes
void TraverseQ(QueueType Queue);
void readInput(QueueType *queue);
void removeExpiredProducts(QueueType *queue);
void getFront(QueueType Queue, Product *p);

int main()
{
    QueueType Q;
    Product p;

    CreateQ(&Q);
    readInput(&Q);
    printf("Products in queue:\n");
    TraverseQ(Q);

    printf("\n");

    removeExpiredProducts(&Q);
    getFront(Q, &p);
    printf("Products in queue:\n");
    TraverseQ(Q);
    
    printf("\n");
    return 0;
}

// my functions
void readInput(QueueType *Queue) {
    FILE *fp;
    Product p;

    fp = fopen("product.dat", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, " %20[^,],%f,%d, %10[^\n]", p.name, &p.price, &p.weight, p.expiration_date) == 4) {
        AddQ(Queue, p);
    }

    fclose(fp);
}


void removeExpiredProducts(QueueType *queue) {
    Product p;
    char date[10];
    printf("Give date:");
    scanf("%s", date);

    while (!EmptyQ(*queue)) {
        getFront(*queue, &p);
        if (strcmp(p.expiration_date, date) <= 0) {
            RemoveQ(queue, &p);
            printf("Front item=%s, %.2f, %d, %s\n", p.name, p.price, p.weight, p.expiration_date);
        } else {
            break;
        }
    }
}


void getFront(QueueType Queue, Product *Item) {
    if (!EmptyQ(Queue)) {
        *Item = Queue.Element[Queue.Front];
    }
}

void TraverseQ(QueueType Queue) {
    int current;
    if (!EmptyQ(Queue)) {
        current = Queue.Front;
        while (current != Queue.Rear) {
            printf("%s, %.2f, %d, %s\n", Queue.Element[current].name,
                   Queue.Element[current].price, Queue.Element[current].weight,
                   Queue.Element[current].expiration_date);
            current = (current + 1) % QueueLimit;
        }
    } else {
        printf("Empty Queue"); // remove newline character
    }
}


/********************************************************************************/
/********************************************************************************/
/********************************************************************************/












/********************************************************************************/
// * QueueADT.c
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

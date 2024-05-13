/********************************************************************************/
// * ListADT.h
#include <stdbool.h>
#define ListLimit 50    //ενδεικτικό μέγεθος λίστας. Επανορίζεται ανάλογα με την εφαρμογή

typedef struct {
    int am;
    char name[21];
} ListElementType;   /*τύπος δεδομένων για τα στοιχεία της λίστας. ενδεικτικά επιλέχθηκε ο τύπος int.
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




/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
// * TestList.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "ListADT.h"

//void menu(int *choice);

/**
 * @brief Searches for an element in a list based on a specific field.
 * 
 * @param List The list to search in.
 * @param Item The element to search for.
 * 
 * @return The position of the element in the list, or -1 if the element was not found.
 */
int search(ListType List, ListElementType Item)
{
    int pos=-1;
    int i=0;

    bool found=false;
    if(!EmptyList(List)){
        while(!found&&i<List.Size)
        {
            // we need to check the am number if is the same as parameter
            if(List.Element[i].am==Item.am){ 
                found=true;
                pos=i;
            }

            i++;
        }

    }

    return pos;
}

int main()
{
    ListType AList;
    ListElementType AnItem;
    int i=0;
    int pos=-1;

    CreateList(&AList);
    //
    for (i=0;i<3;i++) {
        printf("DWSE AM : ");
        scanf("%d",&AnItem.am);

        while (getchar() != '\n');

        printf("DWSE Name: ");
        gets(AnItem.name);

        Insert(&AList,AnItem,pos);
    }

    // show the list
    TraverseList(AList);

    // delete an element
    printf("DWSE AM : ");
    scanf("%d",&AnItem.am);
    // we need to search the element in the list
    pos = search(AList,AnItem);
    // if the element was found we delete it else nothing happens
    if (pos!=-1) {
        Delete(&AList,pos);
    }

    // show the list
    TraverseList(AList);

	return 0;
}

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
/********************************************************************************/









/********************************************************************************/
// * ListADT.c
/*                     (* YLOPOIHSH LISTAS ME PINAKA *)
              (*TA STOIXEIA THS LISTAS EINAI TYPOY integer*)
*/

#include <stdio.h>
#include <stdlib.h>
//#include "ListADT.h"


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
        for (i=0;i<List.Size;i++)
            printf("%d, %s\n",List.Element[i].am ,List.Element[i].name);
        printf("\n");
    }
}
/********************************************************************************/

if the LinkedTraverse code the output
```c
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
        while (CurrPtr != NULL)
        {
            printf("%d ", CurrPtr->Data);
            CurrPtr = CurrPtr->Next;
        }
        printf("\n");
    }
}
```

```
DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: 5
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 1
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 2
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 3
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 4
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 5
Initial List
5 4 3 2 1 
Final List
1 2 3 4 5 
```

if the LinkedTraverse code the output
```c
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
   	    printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
             printf("%p\t%d\t%p\n",CurrPtr,(*CurrPtr).Data, (*CurrPtr).Next);
             CurrPtr = CurrPtr->Next;
        }
   }
}
```

```
DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: 5
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 1
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 2
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 3
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 4
DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: 5
Initial List
CurrPtr                 Data    Next            
0x555555559b40  5       0x555555559b20
0x555555559b20  4       0x555555559b00
0x555555559b00  3       0x555555559ae0
0x555555559ae0  2       0x555555559ac0
0x555555559ac0  1       (nil)
Final List
CurrPtr                 Data    Next            
0x555555559ac0  1       0x555555559ae0
0x555555559ae0  2       0x555555559b00
0x555555559b00  3       0x555555559b20
0x555555559b20  4       0x555555559b40
0x555555559b40  5       (nil)
```
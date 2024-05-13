#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MaxWord 15

typedef struct {
    char onoma[MaxWord];
    char epitheto[MaxWord];
    int thlefwno;
    int typos_eisithriou;
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode {
    QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct {
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);

int main() {
    QueueType Queue;
    QueueElementType Customer;
    int plithos, i, eleftheres_theseis;

    CreateQ(&Queue);

    printf("DWSE TO PLITHOS TWN ATOMWN: ");
    scanf("%d", &plithos);

    for (i = 0; i < plithos; i++) {
        printf("DWSE ONOMA ");
        scanf("%s", Customer.onoma);
        printf("DWSE EPITHETO ");
        scanf("%s", Customer.epitheto);
        printf("DWSE THLEFWNO ");
        scanf("%d", &Customer.thlefwno);
        printf("DWSE TYPOS EISITHRIOY(0=olokliro, 1=miso): ");
        scanf("%d", &Customer.typos_eisithriou);
        AddQ(&Queue, Customer);
    }

    printf("Initial Queue\n");
    TraverseQ(Queue);

    printf("DWSTE ARITHMO ELEUTHERWN THESEWN: ");
    scanf("%d", &eleftheres_theseis);

    QueueType TempQueue;
    CreateQ(&TempQueue);
    while (!EmptyQ(Queue) && eleftheres_theseis > 0) {
        RemoveQ(&Queue, &Customer);
        eleftheres_theseis--;
        if (eleftheres_theseis > 0) {
            AddQ(&TempQueue, Customer);
        }
    }
    while (!EmptyQ(Queue)) {
        RemoveQ(&Queue, &Customer);
        AddQ(&TempQueue, Customer);
    }
    Queue = TempQueue;

    printf("Final Queue\n");
    TraverseQ(Queue);

    return 0;
}

void CreateQ(QueueType *Queue) {
    Queue->Front = NULL;
    Queue->Rear = NULL;
}

bool EmptyQ(QueueType Queue) {
    return (Queue.Front == NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item) {
    QueuePointer TempPtr;

    TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front == NULL)
        Queue->Front = TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear = TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item) {
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
        printf("EMPTY Queue\n");
    } else {
        TempPtr = Queue->Front;
        *Item = TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front == NULL)
            Queue->Rear = NULL;
    }
}

void TraverseQ(QueueType Queue) {
    QueuePointer CurrPtr;

    if (EmptyQ(Queue))
        printf("EMPTY LIST\n");
    else {
        CurrPtr = Queue.Front;
        while (CurrPtr != NULL) {
            printf("%s, %s, %d, %d\n", CurrPtr->Data.onoma, CurrPtr->Data.epitheto, CurrPtr->Data.thlefwno, CurrPtr->Data.typos_eisithriou);
            CurrPtr = CurrPtr->Next;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NumberOfNodes 10
#define NilValue -1

typedef struct {
    int code;
    float salary;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef struct {
    int top;
    int items[NumberOfNodes];
} StackType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
bool FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void TraverseStack(StackType Stack);
void PrintStoragePool(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main() {
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr;
    StackType Stack;
    Stack.top = -1;

    ListElementType AnItem;
    float maxSalary;

    // A. Αρχικοποίηση storage pool
    InitializeStoragePool(Node, &FreePtr);

    // B. Δημιουργία κενής ΣΛ (μέγιστο μέγεθος 10)
    CreateList(&AList);

    // C. Εμφάνιση της storage pool
    printf("Question C\n");
    PrintStoragePool(AList, FreePtr, Node);

    // D. Εμφάνιση των στοιχείων της ΣΛ
    printf("Question D\nLinked list\n");
    TraverseLinked(AList, Node);

    // E. Εισαγωγή 5 στοιχείων στην ΣΛ
    printf("Question E\n");
    for (int i = 0; i < 5; i++) {
        printf("DWSE KWDIKO: ");
        scanf("%d", &AnItem.code);
        printf("DWSE MISTO: ");
        scanf("%f", &AnItem.salary);
        Insert(&AList, Node, &FreePtr, NilValue, AnItem);
    }

    // F. Εμφάνιση της storage pool
    printf("Question F\n");
    PrintStoragePool(AList, FreePtr, Node);

    // G. Εμφάνιση των στοιχείων της ΣΛ
    printf("Question G\nLinked list\n");
    TraverseLinked(AList, Node);

    // H. Έλεγχος εάν η ΣΛ είναι άδεια
    printf("Question H\n");
    if (EmptyList(AList))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

    // I. Έλεγχος εάν η ΣΛ είναι γεμάτη
    printf("Question I\n");
    if (FullList(FreePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    // J. Εμφάνιση του μέγιστου μισθού και των κωδικών των εργαζόμενων με το μέγιστο μισθό
    printf("Question J\n");
    maxSalary = FindMaxs(AList, Node, &Stack);
    printf("Max salary=%.1f\n", maxSalary);
    printf("Code(s) with max salary are: ");
    while (Stack.top != -1) {
        printf("%d, ", Stack.items[Stack.top--]);
    }
    printf("\n");

    // K. Κλήση της TraverseStack για την επαλήθευση της ορθής υλοποίησης του ερωτήματος J
    printf("Question K\n");
    TraverseStack(Stack);

    // L. Εμφάνιση της storage pool
    printf("Question L\n");
    PrintStoragePool(AList, FreePtr, Node);

    // M. Εμφάνιση των στοιχείων της ΣΛ
    printf("Question M\nLinked list\n");
    TraverseLinked(AList, Node);

    return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
    int i;

    for (i = 0; i < NumberOfNodes - 1; i++) {
        Node[i].Next = i + 1;
        Node[i].Data.code = -1;
        Node[i].Data.salary = -1.0;
    }
    Node[NumberOfNodes - 1].Next = NilValue;
    Node[NumberOfNodes - 1].Data.code = -1;
    Node[NumberOfNodes - 1].Data.salary = -1.0;
    *FreePtr = 0;
}

void CreateList(ListPointer *List) {
    *List = NilValue;
}

bool EmptyList(ListPointer List) {
    return (List == NilValue);
}

bool FullList(ListPointer FreePtr) {
    return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]) {
    *P = *FreePtr;
    if (!FullList(*FreePtr))
        *FreePtr = Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr) {
    Node[P].Next = *FreePtr;
    Node[P].Data.code = -1;
    Node[P].Data.salary = -1.0;
    *FreePtr = P;
}

void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item) {
    ListPointer TempPtr;
    GetNode(&TempPtr, FreePtr, Node);
    if (!FullList(TempPtr)) {
        Node[TempPtr].Data = Item;
        Node[TempPtr].Next = *List;
        *List = TempPtr;
    } else
        printf("Full List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[]) {
    ListPointer CurrPtr;

    if (!EmptyList(List)) {
        CurrPtr = List;
        while (CurrPtr != NilValue) {
            printf("(%d:<%d,%.1f> ->%d) ", CurrPtr, Node[CurrPtr].Data.code, Node[CurrPtr].Data.salary, Node[CurrPtr].Next);
            CurrPtr = Node[CurrPtr].Next;
        }
        printf("\n");
    } else
        printf("Empty List ...\n");
}

float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack) {
    ListPointer CurrPtr;
    float maxSalary = -1.0;

    if (!EmptyList(List)) {
        CurrPtr = List;
        while (CurrPtr != NilValue) {
            if (Node[CurrPtr].Data.salary > maxSalary) {
                maxSalary = Node[CurrPtr].Data.salary;
                Stack->top = -1;
                Stack->items[++Stack->top] = Node[CurrPtr].Data.code;
            } else if (Node[CurrPtr].Data.salary == maxSalary) {
                Stack->items[++Stack->top] = Node[CurrPtr].Data.code;
            }
            CurrPtr = Node[CurrPtr].Next;
        }
    }
    return maxSalary;
}

void TraverseStack(StackType Stack) {
    printf("\nplithos sto stack %d\n\n", Stack.top + 1);
}

void PrintStoragePool(ListPointer List, ListPointer FreePtr, NodeType Node[]) {
    int i;
    printf("Storage pool\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i = 0; i < NumberOfNodes; i++) {
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.code, Node[i].Data.salary, Node[i].Next);
    }
    printf("\n");
}
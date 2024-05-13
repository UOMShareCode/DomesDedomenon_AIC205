#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
/**********************************************************/
/**********************************************************/
/**********************************************************/
// StackADT.h
struct Item {
    float weight;
    float value;
};

typedef struct Item StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
    StackElementType Data;
    StackPointer Next;
} StackNode;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

struct Platform {
    StackPointer items;
};

struct Truck {
    StackPointer items;
};

void add_item_to_truck(struct Truck *truck, struct Item item);
void print_platform_and_truck(struct Platform *platform, struct Truck *truck);
int is_profitable_to_add_item(struct Truck *truck, struct Item item);
void rearrange_items(struct Platform *platform, struct Truck *truck, struct Item item);
void move_all_items_to_truck(struct Platform *platform, struct Truck *truck);
/**********************************************************/
/**********************************************************/
/**********************************************************/


void add_item_to_truck(struct Truck *truck, struct Item item);
void print_platform_and_truck(struct Platform *platform, struct Truck *truck);
int is_profitable_to_add_item(struct Truck *truck, struct Item item);
void rearrange_items(struct Platform *platform, struct Truck *truck, struct Item item);
void move_all_items_to_truck(struct Platform *platform, struct Truck *truck);

int main() {
    struct Truck truck;
    struct Platform platform;

    CreateStack(&truck.items);
    CreateStack(&platform.items);

    // Add initial items to the truck
    add_item_to_truck(&truck, (struct Item){3.0f, 0});
    add_item_to_truck(&truck, (struct Item){2.0f, 0});
    add_item_to_truck(&truck, (struct Item){1.0f, 0});
    add_item_to_truck(&truck, (struct Item){0.5f, 0});
    add_item_to_truck(&truck, (struct Item){0.4f, 0});


    struct Item new_item;
    float weight, value;

    while (1) {
        printf("Give the weight: ");
        scanf("%f", &weight);

        if (weight < 0) {
            move_all_items_to_truck(&platform, &truck);
            break;
        }

        printf("Give the value: ");
        scanf("%f", &value);
        new_item = (struct Item){weight, value};

        if (!is_profitable_to_add_item(&truck, new_item)) {
            printf("Not enough space available\n");
            continue;
        }

        rearrange_items(&platform, &truck, new_item);
        add_item_to_truck(&truck, new_item);

        print_platform_and_truck(&platform, &truck);
    }

    print_platform_and_truck(&platform, &truck);

    return 0;
}

void add_item_to_truck(struct Truck *truck, struct Item item) {
    Push(&truck->items, item);
}

void print_platform_and_truck(struct Platform *platform, struct Truck *truck) {
    StackPointer tempStack;
    struct Item item;

    CreateStack(&tempStack);

    if (!EmptyStack(platform->items)) {
        printf("Platform\n");
        while (!EmptyStack(platform->items)) {
            Pop(&platform->items, &item);
            printf("%.1f\n", item.weight);
            Push(&tempStack, item);
        }
        while (!EmptyStack(tempStack)) {
            Pop(&tempStack, &item);
            Push(&platform->items, item);
        }
    }

    if (!EmptyStack(truck->items)) {
        printf("Truck\n");
        while (!EmptyStack(truck->items)) {
            Pop(&truck->items, &item);
            printf("%.1f\n", item.weight);
            Push(&tempStack, item);
        }
        while (!EmptyStack(tempStack)) {
            Pop(&tempStack, &item);
            Push(&truck->items, item);
        }
    }
}

int is_profitable_to_add_item(struct Truck *truck, struct Item item) {
    float total_weight = 0;
    float total_value = 0;
    struct Item temp_item;
    StackPointer tempStack;

    CreateStack(&tempStack);

    while (!EmptyStack(truck->items)) {
        Pop(&truck->items, &temp_item);
        if (temp_item.weight < item.weight) {
            total_weight += temp_item.weight;
            total_value += temp_item.value;
        }
        Push(&tempStack, temp_item);
    }

    while (!EmptyStack(tempStack)) {
        Pop(&tempStack, &temp_item);
        Push(&truck->items, temp_item);
    }

    if (total_weight + item.weight > 10) {
        return 0;
    }

    return total_value + item.value > total_value;
}

void rearrange_items(struct Platform *platform, struct Truck *truck, struct Item item) {
    struct Item temp_item;

    while (!EmptyStack(truck->items)) {
        Pop(&truck->items, &temp_item);
        if (temp_item.weight < item.weight) {
            Push(&platform->items, temp_item);
        } else {
            Push(&truck->items, temp_item);
            break;
        }
    }
}

void move_all_items_to_truck(struct Platform *platform, struct Truck *truck) {
    struct Item item;

    while (!EmptyStack(platform->items)) {
        Pop(&platform->items, &item);
        add_item_to_truck(truck, item);
    }
}

/**********************************************************/
/**********************************************************/
/**********************************************************/
// StackADT.c

void CreateStack(StackPointer *Stack)
{
    *Stack = NULL;
}

bool EmptyStack(StackPointer Stack)
{
    return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
{
    StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
        printf("EMPTY Stack\n");
    }
    else
    {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
/**********************************************************/
/**********************************************************/
/**********************************************************/

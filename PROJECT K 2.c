#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display() {
    if (head == NULL) {
        printf("\nLinked List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("\nLinked List Elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insertAtPos() {
    int pos, value, i = 0;
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    printf("\n--- Simulation of Insertion in Linked List ---\n");

    if (pos == 0) {
        printf("Inserting at head...\n");
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && i < pos - 1) {
        printf("Traversing node %d with value %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    printf("Linking new node after node %d...\n", i);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteAtPos() {
    int pos, i = 0;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("\n--- Simulation of Deletion in Linked List ---\n");

    struct Node* temp = head;

    if (pos == 0) {
        printf("Deleting head node with value %d\n", head->data);
        head = head->next;
        free(temp);
        printf("Deletion complete.\n");
        return;
    }

    struct Node* prev = NULL;

    while (temp != NULL && i < pos) {
        printf("Traversing node %d with value %d\n", i, temp->data);
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    printf("Deleting node at position %d with value %d\n", pos, temp->data);
    prev->next = temp->next;
    free(temp);

    printf("Deletion complete.\n");
}

void search() {
    int key, index = 0;
    struct Node* temp = head;

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    printf("\n--- Simulation of Linear Search in Linked List ---\n");

    while (temp != NULL) {
        printf("Comparing key with node %d having value %d\n", index, temp->data);

        if (temp->data == key) {
            printf("Element found at index %d.\n", index);
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("Element not found in the list.\n");
}

void update() {
    int index, value, i = 0;

    printf("\nEnter index to update: ");
    scanf("%d", &index);

    struct Node* temp = head;

    while (temp != NULL && i < index) {
        printf("Traversing node %d with value %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    printf("\nUpdating node %d from %d → %d\n", index, temp->data, value);
    temp->data = value;

    printf("Update successful.\n");
}

void createInitialList(int n) {
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

int main() {
    int choice, n;

    printf("Enter initial size of linked list: ");
    scanf("%d", &n);

    createInitialList(n);

    do {
        printf("\n========= LINKED LIST SIMULATION MENU =========\n");
        printf("1. Display\n");
        printf("2. Insert at Position\n");
        printf("3. Delete from Position\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: display(); break;
            case 2: insertAtPos(); break;
            case 3: deleteAtPos(); break;
            case 4: search(); break;
            case 5: update(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
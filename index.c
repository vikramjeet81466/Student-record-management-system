#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    char branch[20];
    struct Student* next;
};

struct Student* head = NULL;

void addStudentRecord() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\n--- Add New Record --- \n");
    printf("Enter Roll Number: ");
    scanf("%d", &newNode->rollNo);
    printf("Enter Name: ");
    scanf(" %s", newNode->name);
    printf("Enter Branch: ");
    scanf("%s", newNode->branch);
    
    newNode->next = head;
    head = newNode;
    
    printf("\nRecord saved successfully!\n");
}

void displayRecords() {
    struct Student* temp = head;
    
    if (temp == NULL) {
        printf("\nNo records found!\n");
        return;
    }
    
    printf("\n--- Student List --- \n");
    printf("%-10s %-20s %-15s\n", "Roll No", "Name", "Branch");
    printf("--------------------------------------------\n");
    
    while (temp != NULL) {
        printf("%-10d %-20s %-15s\n", temp->rollNo, temp->name, temp->branch);
        temp = temp->next;
    }
}

void searchRecord() {
    int rNo;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rNo);
    
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rNo) {
            printf("\nRecord Found!");
            printf("\nRoll No: %d\nName: %s\nBranch: %s\n", temp->rollNo, temp->name, temp->branch);
            return;
        }
        temp = temp->next;
    }
    printf("\nRecord not found!\n");
}

void deleteRecord() {
    int rNo;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rNo);
    
    struct Student *temp = head, *prev = NULL;
    
    if (temp != NULL && temp->rollNo == rNo) {
        head = temp->next;
        free(temp);
        printf("\nRecord deleted successfully!\n");
        return;
    }
    
    while (temp != NULL && temp->rollNo != rNo) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("\nRecord not found!\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("\nRecord deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Student Record Management System ***");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");
        printf("\n\nSelect choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStudentRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
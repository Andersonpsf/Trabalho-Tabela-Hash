#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Fun??o hash simples (M?todo da Divis?o)
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Inser??o na tabela hash
void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Busca na tabela hash
int search(int key) {
    int hashIndex = hashFunction(key);
    Node* current = hashTable[hashIndex];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // N?o encontrado
}

// Exibi??o da tabela hash
void displayTable() {
    int i;
	for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* current = hashTable[i];
        while (current) {
            printf("(Chave %d, Valor: %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int i; 
    
    // Inicializando todos os elementos da tabela hash com NULL
	for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    //insert(key, value)
	insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 15);

    printf("Tabela Hash:\n");
    displayTable();

    int key = 11;
    int value = search(key);
    if (value != -1) {
        printf("Valor encontrado para a chave %d: %d\n", key, value);
    } else {
        printf("Chave %d n?o encontrada.\n", key);
    }

    return 0;
}



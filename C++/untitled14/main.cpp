#include <iostream>

using namespace std;

class node {
public:
    int value;
    node *next;
};

class stack {
public:
    node *top;
};

class Queue {
public:
    int *tab;
    int head;
    int tail;
    int size;
};

stack *createStack() {
    stack *s = new stack;
    s->top = NULL;
    return s;
}

void push(stack *s, int value) {
    node *n = new node;
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int pop(stack *s) {
    if (s->top == NULL) {
        cout << "Stos jest pusty" << endl;
        return -1;
    }
    int value = s->top->value;
    node *n = s->top;
    s->top = s->top->next;
    delete n;
    return value;
}

void printStack(stack *s) {
    node *n = s->top;
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

int sum(stack *s) {
    int sum = 0;
    node *n = s->top;
    while (n != NULL) {
        sum += n->value;
        n = n->next;
    }
    return sum;
}

void addAverage(stack *s) {
    int sum = 0;
    int count = 0;
    node *n = s->top;
    while (n != NULL) {
        sum += n->value;
        count++;
        n = n->next;
    }
    push(s, sum / count);
}

void removeMax(stack *s) {
    int max = s->top->value;
    node *n = s->top;
    while (n != NULL) {
        if (n->value > max) {
            max = n->value;
        }
        n = n->next;
    }
    n = s->top;
    node *prev = NULL;
    while (n != NULL) {
        if (n->value == max) {
            if (prev == NULL) {
                s->top = n->next;
            } else {
                prev->next = n->next;
            }
            node *tmp = n;
            n = n->next;
            delete tmp;
        } else {
            prev = n;
            n = n->next;
        }
    }
}

void sumAndSort(Queue *q) {
    int sum = 0;
    int count = 0;
    for (int i = q->head; i != q->tail; i = (i + 1) % q->size) {
        sum += q->tab[i];
        count++;
    }
    int *tab = new int[count];
    int j = 0;
    for (int i = q->head; i != q->tail; i = (i + 1) % q->size) {
        tab[j] = q->tab[i];
        j++;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        q->tab[i] = tab[i];
    }
    q->head = 0;
    q->tail = count;
}

int main() {
srand(time(NULL));
    stack *s = createStack();
    for (int i = 0; i < 10; i++) {
        push(s, rand() % 10);
    }
    printStack(s);
    cout << "Suma: " << sum(s) << endl;
    addAverage(s);
    printStack(s);
    removeMax(s);
    printStack(s);

    return 0;
}

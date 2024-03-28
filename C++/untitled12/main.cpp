#include <iostream>
#include <cmath>

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


stack *StosL(int l, int M) {
    stack *s = createStack();
    int i = 1;
    while (i * l <= M) {
        push(s, i * l);
        i++;
    }

    //printStack(s);
    return s;

}


stack *reverse(stack *base) {
    stack *s = createStack();
    node *n = base->top;

    while (n != NULL) {
        push(s, n->value);
        n = n->next;
    }
    printStack(s);
    return s;
}


void remove(stack *base, int n) {
    stack *s = createStack();
    int i = 1;
    while (i < n) {
        push(s, pop(base));
        i++;
    }
    pop(base);
    while (s->top != NULL) {
        push(base, pop(s));
    }
    printStack(base);
}

stack *combination(stack *base1, stack *base2) {
    stack *s1 = createStack();
    stack *s2 = createStack();
    while(base1->top != NULL) {
        push(s1, pop(base1));
    }
    while(base2->top != NULL) {
        push(s2, pop(base2));
    }
    while(s1->top != NULL) {
        push(base1, pop(s1));
        push(base1, pop(s2));
    }
    while (s2->top != NULL) {
        push(base1, pop(s2));
    }
    //printStack(base1);
    return base1;
}

void init(Queue *queue, int size) {
    queue->tab = new int[size];
    queue->head = 0;
    queue->tail = 0;
    queue->size = size + 1;
}

void enqueue(Queue *queue, int value) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        return;
    }
    queue->tab[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->size;
}

int dequeue(Queue *queue) {
    if (queue->head == queue->tail) {
        return -1;
    }
    int value = queue->tab[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return value;
}

void removeX(Queue *queue, int x) {
    Queue *queue2 = new Queue;
    init(queue2, queue->size);
    while (queue->head != queue->tail) {
        int value = dequeue(queue);
        if (value != x) {
            enqueue(queue2, value);
        }
    }
    queue->head = queue2->head;
    queue->tail = queue2->tail;
    queue->size = queue2->size;
    queue->tab = queue2->tab;
}
void print(Queue *queue) {
    int i = queue->head;
    while (i != queue->tail) {
        cout << queue->tab[i] << " ";
        i = (i + 1) % queue->size;
    }
    cout << endl;
}

int main() {
    stack *s1 = StosL(5,50);
    stack *s2 = StosL(3,50);
    //reverse(s);
    //remove(s, 3);
    //reverse(combination(s1, s2));
//    Queue *q1 = new Queue;
//    init(q1, 5);
//    enqueue(q1, 1);
//    enqueue(q1, 2);
//    enqueue(q1, 3);
//    enqueue(q1, 4);
//    enqueue(q1, 5);
//    print(q1);
//    removeX(q1, 2);
//    print(q1);

    return 0;
}

//struktury stosu, kolejki i listy oraz przydatne funkcje
struct Stack {
    int value;
    Stack *next;
};

struct Queue {
    int value;
    Queue *next;
};

struct List {
    int value;
    List *next;
};

Stack *createStack() {
    Stack *s = new Stack;
    s->next = NULL;
    return s;
}

void push(Stack *s, int value) {
    Stack *n = new Stack;
    n->value = value;
    n->next = s->next;
    s->next = n;
}

int pop(Stack *s) {
    if (s->next == NULL) {
        cout << "Stos jest pusty" << endl;
        return -1;
    }
    int value = s->next->value;
    Stack *n = s->next;
    s->next = s->next->next;
    delete n;
    return value;
}

void printStack(Stack *s) {
    Stack *n = s->next;
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

Queue *createQueue() {
    Queue *q = new Queue;
    q->next = NULL;
    return q;
}

void enqueue(Queue *q, int value) {
    Queue *n = new Queue;
    n->value = value;
    n->next = q->next;
    q->next = n;
}

int dequeue(Queue *q) {
    if (q->next == NULL) {
        cout << "Kolejka jest pusta" << endl;
        return -1;
    }
    Queue *n = q->next;
    int value = n->value;
    q->next = q->next->next;
    delete n;
    return value;
}

void printQueue(Queue *q) {
    Queue *n = q->next;
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

List *createList() {
    List *l = new List;
    l->next = NULL;
    return l;
}

void add(List *l, int value) {
    List *n = new List;
    n->value = value;
    n->next = l->next;
    l->next = n;
}

void printList(List *l) {
    List *n = l->next;
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

void deleteList(List *l) {
    List *n = l->next;
    while (n != NULL) {
        List *tmp = n;
        n = n->next;
        delete tmp;
    }
    delete l;
}
//zwraca stos zawierajacy wielokrotnosci liczby l mniejsze od M
Stack *StosL(int l, int M) {
    Stack *s = createStack();
    int i = 1;
    while (i * l <= M) {
        push(s, i * l);
        i++;
    }
    return s;
}

//zwraca kolejke zawierajaca wielokrotnosci liczby l mniejsze od M

Queue *KolejkaL(int l, int M) {
    Queue *q = createQueue();
    int i = 1;
    while (i * l <= M) {
        enqueue(q, i * l);
        i++;
    }
    return q;
}

//zwraca liste zawierajaca wielokrotnosci liczby l mniejsze od M

List *ListaL(int l, int M) {
    List *l1 = createList();
    int i = 1;
    while (i * l <= M) {
        add(l1, i * l);
        i++;
    }
    return l1;
}

//napisz funkcje, ktora zwraca stos zawierajacy sume dwoch stosow

Stack *suma(Stack *s1, Stack *s2) {
    Stack *s3 = createStack();
    while (s1->next != NULL && s2->next != NULL) {
        push(s3, pop(s1) + pop(s2));
    }
    while (s1->next != NULL) {
        push(s3, pop(s1));
    }
    while (s2->next != NULL) {
        push(s3, pop(s2));
    }
    return s3;
}

//napisz funkcje ktora sortuje stos

void sort(Stack *s) {
    Stack *s2 = createStack();
    while (s->next != NULL) {
        int value = pop(s);
        while (s2->next != NULL && s2->next->value > value) {
            push(s, pop(s2));
        }
        push(s2, value);
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
}

//napisz funkcje ktora sortuje kolejke

void sort(Queue *q) {
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        int value = dequeue(q);
        while (q2->next != NULL && q2->next->value > value) {
            enqueue(q, dequeue(q2));
        }
        enqueue(q2, value);
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
}

//napisz funkcje ktora sortuje liste

void sort(List *l) {
    List *l2 = createList();
    while (l->next != NULL) {
        int value = l->next->value;
        l->next = l->next->next;
        while (l2->next != NULL && l2->next->value > value) {
            add(l, l2->next->value);
            l2->next = l2->next->next;
        }
        add(l2, value);
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
}

//napisz funkcje ktora sortuje odwrotnie stos

void sortReverse(Stack *s) {
    Stack *s2 = createStack();
    while (s->next != NULL) {
        int value = pop(s);
        while (s2->next != NULL && s2->next->value < value) {
            push(s, pop(s2));
        }
        push(s2, value);
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
}

//napisz funkcje ktora sortuje odwrotnie kolejke

void sortReverse(Queue *q) {
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        int value = dequeue(q);
        while (q2->next != NULL && q2->next->value < value) {
            enqueue(q, dequeue(q2));
        }
        enqueue(q2, value);
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
}

//napisz funkcje ktora sortuje odwrotnie liste

void sortReverse(List *l) {
    List *l2 = createList();
    while (l->next != NULL) {
        int value = l->next->value;
        l->next = l->next->next;
        while (l2->next != NULL && l2->next->value < value) {
            add(l, l2->next->value);
            l2->next = l2->next->next;
        }
        add(l2, value);
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
}

//napisz funkcje ktora usuwa n-ty element stosu

void deleteN(Stack *s, int n) {
    Stack *s2 = createStack();
    int i = 0;
    while (s->next != NULL) {
        if (i != n) {
            push(s2, pop(s));
        } else {
            pop(s);
        }
        i++;
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
}

//napisz funkcje ktora usuwa n-ty element kolejki

void deleteN(Queue *q, int n) {
    Queue *q2 = createQueue();
    int i = 0;
    while (q->next != NULL) {
        if (i != n) {
            enqueue(q2, dequeue(q));
        } else {
            dequeue(q);
        }
        i++;
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
}

//napisz funkcje ktora usuwa n-ty element listy

void deleteN(List *l, int n) {
    List *l2 = createList();
    int i = 0;
    while (l->next != NULL) {
        if (i != n) {
            add(l2, l->next->value);
            l->next = l->next->next;
        } else {
            l->next = l->next->next;
        }
        i++;
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
}

//napisz funkcje ktora usuwa elementy o wartosci wiekszej od x ze stosu

void deleteGreater(Stack *s, int x) {
    Stack *s2 = createStack();
    while (s->next != NULL) {
        if (s->next->value <= x) {
            push(s2, pop(s));
        } else {
            pop(s);
        }
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
}

//napisz funkcje ktora usuwa elementy o wartosci wiekszej od x z kolejki

void deleteGreater(Queue *q, int x) {
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        if (q->next->value <= x) {
            enqueue(q2, dequeue(q));
        } else {
            dequeue(q);
        }
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
}

//napisz funkcje ktora usuwa elementy o wartosci wiekszej od x z listy

void deleteGreater(List *l, int x) {
    List *l2 = createList();
    while (l->next != NULL) {
        if (l->next->value <= x) {
            add(l2, l->next->value);
            l->next = l->next->next;
        } else {
            l->next = l->next->next;
        }
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z listy do stosu

void add(List *l, Stack *s) {
    while (l->next != NULL) {
        push(s, l->next->value);
        l->next = l->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z listy do kolejki

void add(List *l, Queue *q) {
    while (l->next != NULL) {
        enqueue(q, l->next->value);
        l->next = l->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z stosu do listy

void add(Stack *s, List *l) {
    while (s->next != NULL) {
        add(l, s->next->value);
        s->next = s->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z stosu do kolejki

void add(Stack *s, Queue *q) {
    while (s->next != NULL) {
        enqueue(q, s->next->value);
        s->next = s->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z kolejki do listy

void add(Queue *q, List *l) {
    while (q->next != NULL) {
        add(l, q->next->value);
        q->next = q->next->next;
    }
}

//napisz funkcje ktora dodaje elementy z kolejki do stosu

void add(Queue *q, Stack *s) {
    while (q->next != NULL) {
        push(s, q->next->value);
        q->next = q->next->next;
    }
}

//napisz funkcje ktora usunie losowy element stosu

void deleteRandom(Stack *s) {
    int n = 0;
    Stack *s2 = createStack();
    while (s->next != NULL) {
        n++;
        push(s2, pop(s));
    }
    int r = rand() % n;
    n = 0;
    while (s2->next != NULL) {
        if (n != r) {
            push(s, pop(s2));
        } else {
            pop(s2);
        }
        n++;
    }
}

//napisz funkcje ktora usunie losowy element kolejki

void deleteRandom(Queue *q) {
    int n = 0;
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        n++;
        enqueue(q2, dequeue(q));
    }
    int r = rand() % n;
    n = 0;
    while (q2->next != NULL) {
        if (n != r) {
            enqueue(q, dequeue(q2));
        } else {
            dequeue(q2);
        }
        n++;
    }
}

//napisz funkcje ktora usunie losowy element listy

void deleteRandom(List *l) {
    int n = 0;
    List *l2 = createList();
    while (l->next != NULL) {
        n++;
        add(l2, l->next->value);
        l->next = l->next->next;
    }
    int r = rand() % n;
    n = 0;
    while (l2->next != NULL) {
        if (n != r) {
            add(l, l2->next->value);
            l2->next = l2->next->next;
        } else {
            l2->next = l2->next->next;
        }
        n++;
    }
}

//napisz funkcje ktora obliczy srednia wartosc elementow stosu

float average(Stack *s) {
    int n = 0;
    float sum = 0;
    Stack *s2 = createStack();
    while (s->next != NULL) {
        n++;
        sum += s->next->value;
        push(s2, pop(s));
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
    return sum / n;
}

//napisz funkcje ktora obliczy srednia wartosc elementow kolejki

float average(Queue *q) {
    int n = 0;
    float sum = 0;
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        n++;
        sum += q->next->value;
        enqueue(q2, dequeue(q));
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
    return sum / n;
}

//napisz funkcje ktora obliczy srednia wartosc elementow listy

float average(List *l) {
    int n = 0;
    float sum = 0;
    List *l2 = createList();
    while (l->next != NULL) {
        n++;
        sum += l->next->value;
        add(l2, l->next->value);
        l->next = l->next->next;
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
    return sum / n;
}

//napisz funkcje ktora zwraca najmniejsza wartosc stosu

int min(Stack *s) {
    int min = s->next->value;
    Stack *s2 = createStack();
    while (s->next != NULL) {
        if (s->next->value < min) {
            min = s->next->value;
        }
        push(s2, pop(s));
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
    return min;
}

//napisz funkcje ktora zwraca najmniejsza wartosc kolejki

int min(Queue *q) {
    int min = q->next->value;
    Queue *q2 = createQueue();
    while (q->next != NULL) {
        if (q->next->value < min) {
            min = q->next->value;
        }
        enqueue(q2, dequeue(q));
    }
    while (q2->next != NULL) {
        enqueue(q, dequeue(q2));
    }
    return min;
}

//napisz funkcje ktora zwraca najmniejsza wartosc listy

int min(List *l) {
    int min = l->next->value;
    List *l2 = createList();
    while (l->next != NULL) {
        if (l->next->value < min) {
            min = l->next->value;
        }
        add(l2, l->next->value);
        l->next = l->next->next;
    }
    while (l2->next != NULL) {
        add(l, l2->next->value);
        l2->next = l2->next->next;
    }
    return min;
}

//napisz funkcje ktora zwraca najwieksza wartosc stosu

int max(Stack *s) {
    int max = s->next->value;
    Stack *s2 = createStack();
    while (s->next != NULL) {
        if (s->next->value > max) {
            max = s->next->value;
        }
        push(s2, pop(s));
    }
    while (s2->next != NULL) {
        push(s, pop(s2));
    }
    return max;
}
//napisz liste klientow z polami imie, wiek, zarobki, w kazdej jednostce czasu istnieje 50% szans na to ze do banku wejdzie kolejny klient, oraz 25% szans ze klient bedzie musial uzupelnic dokumenty(trafi wtedy na koniec kolejni)

struct Client {
    string name;
    int age;
    int salary;
    Client *next;
};

Client *createClient(string name, int age, int salary) {
    Client *c = new Client;
    c->name = name;
    c->age = age;
    c->salary = salary;
    c->next = NULL;
    return c;
}

void addClient(Client *c, string name, int age, int salary) {
    while (c->next != NULL) {
        c = c->next;
    }
    c->next = createClient(name, age, salary);
}

void addClient(Client *c, Client *c2) {
    while (c->next != NULL) {
        c = c->next;
    }
    c->next = c2;
}

void print(Client *c) {
    while (c->next != NULL) {
        cout << c->next->name << " " << c->next->age << " " << c->next->salary << endl;
        c = c->next;
    }
}

void deleteClient(Client *c) {
    while (c->next != NULL) {
        Client *c2 = c->next;
        c->next = c->next->next;
        delete c2;
    }
}

void bank() {
    Client *c = createClient("Jan", 20, 2000);
    int n = 0;
    while (n < 100) {
        if (rand() % 2 == 0) {
            addClient(c, createClient("Jan", 20, 2000));
        }
        if (rand() % 4 == 0) {
            addClient(c, createClient("Jan", 20, 2000));
        }
        n++;
    }
    print(c);
    deleteClient(c);
}

//napisz funkcje ktora zwraca srednie zarobki klientow w kolejce

float averageSalary(Client *c) {
    int n = 0;
    float sum = 0;
    Client *c2 = createClient("Jan", 20, 2000);
    while (c->next != NULL) {
        n++;
        sum += c->next->salary;
        addClient(c2, c->next);
        c = c->next;
    }
    while (c2->next != NULL) {
        addClient(c, c2->next);
        c2 = c2->next;
    }
    return sum / n;
}

//napisz funkcje ktora zwraca liste klientow ktorych zarobki nie mieszcza sie w zadnym przedziale

Client *salary(Client *c, int min, int max) {
    Client *c2 = createClient("Jan", 20, 2000);
    while (c->next != NULL) {
        if (c->next->salary < min || c->next->salary > max) {
            addClient(c2, c->next);
        }
        c = c->next;
    }
    return c2;
}

//napisz funkcje ktora pozwoli na edycje danych klienta na n-tym miejscu

void edit(Client *c, int n, string name, int age, int salary) {
    int i = 0;
    while (c->next != NULL) {
        if (i == n) {
            c->next->name = name;
            c->next->age = age;
            c->next->salary = salary;
        }
        c = c->next;
        i++;
    }
}
//Wchodząc do sklepu dysponujesz listą produktów do kupienia. Napisz reprezentację tej sytuacji
//zakładając, że:
//• Każdy produkt jest obiektem i posiada pola: nazwa, cena, kaloryczność,
//• W każdej jednostce czasu* z listy znika losowo wybrany produkt,
//1. Napisz funkcję, która usunie losowo wybraną pozycję z listy(3.0),
//2. Napisz funkcję, która połączy dwie listy z zakupami, na przemian (lista1, lista2, lista1,
//lista2)(4.0),
//3. Napisz funkcję, która zwróci n-ty element od końca listy(5.0).

struct Product {
    string name;
    float price;
    int calories;
    Product *next;
};

Product *createProduct(string name, float price, int calories) {
    Product *p = new Product;
    p->name = name;
    p->price = price;
    p->calories = calories;
    p->next = NULL;
    return p;
}

void addProduct(Product *p, string name, float price, int calories) {
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = createProduct(name, price, calories);
}

void addProduct(Product *p, Product *p2) {
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = p2;
}

void print(Product *p) {
    while (p->next != NULL) {
        cout << p->next->name << " " << p->next->price << " " << p->next->calories << endl;
        p = p->next;
    }
}

void deleteProduct(Product *p) {
    while (p->next != NULL) {
        Product *p2 = p->next;
        p->next = p->next->next;
        delete p2;
    }
}

void shop() {
    Product *p = createProduct("Jablko", 2, 100);
    int n = 0;
    while (n < 100) {
        if (rand() % 2 == 0) {
            addProduct(p, createProduct("Jablko", 2, 100));
        }
        n++;
    }
    print(p);
    deleteProduct(p);
}

//napisz funkcje ktora usunie losowo wybrana pozycje z listy

void deleteRandom(Product *p) {
    int n = 0;
    while (p->next != NULL) {
        n++;
        p = p->next;
    }
    int r = rand() % n;
    int i = 0;
    while (p->next != NULL) {
        if (i == r) {
            Product *p2 = p->next;
            p->next = p->next->next;
            delete p2;
        }
        p = p->next;
        i++;
    }
}

//napisz funkcje ktora polaczy dwie listy z zakupami, na przemian (lista1, lista2, lista1, lista2)

Product *merge(Product *p, Product *p2) {
    Product *p3 = createProduct("Jablko", 2, 100);
    while (p->next != NULL && p2->next != NULL) {
        addProduct(p3, p->next);
        addProduct(p3, p2->next);
        p = p->next;
        p2 = p2->next;
    }
    while (p->next != NULL) {
        addProduct(p3, p->next);
        p = p->next;
    }
    while (p2->next != NULL) {
        addProduct(p3, p2->next);
        p2 = p2->next;
    }
    return p3;
}

//napisz funkcje ktora zwroci n-ty element od konca listy

Product *nth(Product *p, int n) {
    int i = 0;
    while (p->next != NULL) {
        i++;
        p = p->next;
    }
    int r = i - n;
    i = 0;
    while (p->next != NULL) {
        if (i == r) {
            return p->next;
        }
        p = p->next;
        i++;
    }
}

//Napisz program, który będzie przechowywał informacje o książkach w bibliotece. Każda książka

struct Book {
    string title;
    string author;
    int year;
    Book *next;
};

Book *createBook(string title, string author, int year) {
    Book *b = new Book;
    b->title = title;
    b->author = author;
    b->year = year;
    b->next = NULL;
    return b;
}

void addBook(Book *b, string title, string author, int year) {
    while (b->next != NULL) {
        b = b->next;
    }
    b->next = createBook(title, author, year);
}

void print(Book *b) {
    while (b->next != NULL) {
        cout << b->next->title << " " << b->next->author << " " << b->next->year << endl;
        b = b->next;
    }
}

void deleteBook(Book *b) {
    while (b->next != NULL) {
        Book *b2 = b->next;
        b->next = b->next->next;
        delete b2;
    }
}

//Napisz funkcję, która usunie książkę o podanym tytule(3.0),

void deleteBook(Book *b, string title) {
    while (b->next != NULL) {
        if (b->next->title == title) {
            Book *b2 = b->next;
            b->next = b->next->next;
            delete b2;
        }
        b = b->next;
    }
}

//Napisz funkcję, która usunie książkę o podanym autorze(3.0),

void deleteBookByAuthor(Book *b, string author) {
    while (b->next != NULL) {
        if (b->next->author == author) {
            Book *b2 = b->next;
            b->next = b->next->next;
            delete b2;
        }
        b = b->next;
    }
}

//Napisz funkcję, która usunie książkę wydaną przed podanym rokiem(3.0),

void deleteBookByYear(Book *b, int year) {
    while (b->next != NULL) {
        if (b->next->year < year) {
            Book *b2 = b->next;
            b->next = b->next->next;
            delete b2;
        }
        b = b->next;
    }
}

//Napisz funkcję, która  (4.0)

//a) zwróci liczbę książek wydanych przed podanym rokiem,

int countBooksByYear(Book *b, int year) {
    int n = 0;
    while (b->next != NULL) {
        if (b->next->year < year) {
            n++;
        }
        b = b->next;
    }
    return n;
}

//b) zwróci liczbę książek o podanym autorze,

int countBooksByAuthor(Book *b, string author) {
    int n = 0;
    while (b->next != NULL) {
        if (b->next->author == author) {
            n++;
        }
        b = b->next;
    }
    return n;
}

//napisz funkcje ktora (5.0)

//a) zwroci n-ty element listy

Book *nth(Book *b, int n) {
    int i = 0;
    while (b->next != NULL) {
        i++;
        b = b->next;
    }
    int r = i - n;
    i = 0;
    while (b->next != NULL) {
        if (i == r) {
            return b->next;
        }
        b = b->next;
        i++;
    }
}

//b) zwroci n-ty element listy od konca

Book *nthFromEnd(Book *b, int n) {
    int i = 0;
    while (b->next != NULL) {
        i++;
        b = b->next;
    }
    int r = i - n;
    i = 0;
    while (b->next != NULL) {
        if (i == r) {
            return b->next;
        }
        b = b->next;
        i++;
    }
}



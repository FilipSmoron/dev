#include <iostream>
#include <ctime>
//#include <windows.h>

using namespace std;

struct FlightEvent {
    int landingTime;
    FlightEvent *left;
    FlightEvent *right;
};

FlightEvent *newFlightEvent(int landingTime) {
    FlightEvent *event = new FlightEvent;
    event->landingTime = landingTime;
    event->left = event->right = nullptr;
    return event;
}

void inorder(FlightEvent *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->landingTime << " ";
        inorder(root->right);
    }
}

FlightEvent *insert(FlightEvent *node, int landingTime) {
    if (node == nullptr) return newFlightEvent(landingTime);

    if (landingTime < node->landingTime)
        node->left = insert(node->left, landingTime);
    else if (landingTime > node->landingTime)
        node->right = insert(node->right, landingTime);

    return node;
}

FlightEvent *minValueNode(FlightEvent *node) {
    FlightEvent *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

FlightEvent *deleteNode(FlightEvent *root, int landingTime) {
    if (root == nullptr) return root;

    if (landingTime < root->landingTime)
        root->left = deleteNode(root->left, landingTime);

    else if (landingTime > root->landingTime)
        root->right = deleteNode(root->right, landingTime);

    else {
        if (root->left == nullptr) {
            FlightEvent *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            FlightEvent *temp = root->left;
            delete root;
            return temp;
        }

        FlightEvent *temp = minValueNode(root->right);

        root->landingTime = temp->landingTime;

        root->right = deleteNode(root->right, temp->landingTime);
    }
    return root;
}

FlightEvent *search(FlightEvent *root, int landingTime) {
    if (root == nullptr || root->landingTime == landingTime)
        return root;

    if (root->landingTime < landingTime)
        return search(root->right, landingTime);

    return search(root->left, landingTime);
}

bool isTimeAvailable(FlightEvent *root, int landingTime) {
    if (root == nullptr)
        return true;

    FlightEvent *current = root;
    while (current != nullptr) {
        if (abs(current->landingTime - landingTime) <= 3)
            return false;

        if (landingTime < current->landingTime)
            current = current->left;
        else
            current = current->right;
    }

    return true;
}

void printEvents(FlightEvent *root) {
    cout << "Planowane wydarzenia: ";
    inorder(root);
    cout << endl;
}

int main() {
    FlightEvent *root = nullptr;

    time_t currentTime = time(NULL);
    struct tm *timeinfo;
    timeinfo = localtime(&currentTime);
    cout << "Aktualny czas: " << asctime(timeinfo);

    root = insert(root, 41);
    insert(root, 47);
    insert(root, 50);
    insert(root, 58);

    printEvents(root);

    int request1 = 48;
    cout << "Proba zarezerwowania ladowania o czasie " << request1 << ": ";
    if (isTimeAvailable(root, request1)) {
        root = insert(root, request1);
        cout << "Sukces!" << endl;
    } else {
        cout << "Odmowa!" << endl;
    }
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);


    int request2 = 20;
    cout << "Proba zarezerwowania ladowania o czasie " << request2 << ": ";
    if (isTimeAvailable(root, request2)) {
        root = insert(root, request2);
        cout << "Sukces!" << endl;
    } else {
        cout << "Odmowa!" << endl;
    }
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);


    int request3 = 54;
    cout << "Proba zarezerwowania ladowania o czasie " << request3 << ": ";
    if (isTimeAvailable(root, request3)) {
        root = insert(root, request3);
        cout << "Sukces!" << endl;
    } else {
        cout << "Odmowa!" << endl;
    }

    //Sleep(10000);
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);
    cout << "Aktualny czas po obsludze rezerwacji: " << asctime(timeinfo);

    printEvents(root);

    root = deleteNode(root, 41);
    root = deleteNode(root, 47);
    cout << "Po usunieciu 41 i 47" << endl;
    printEvents(root);

    return 0;
}
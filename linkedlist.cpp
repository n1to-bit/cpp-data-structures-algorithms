#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *prev, *next;
    string name;
    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

// sentinel
Node* nil;

void init() {
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

void printList() {
    Node* cur = nil->next;
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " ->";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node* v) {
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    init();
    vector<string> names = {"ito", "kato", "sato", "naito"};
    Node* kato, saito;
    for(string n : names) {
        Node* node = new Node(n);
        insert(node);
        if (n == "kato") kato = node;
    }
    printList();
    erase(kato);
    printList();
}


// 1. CREATE & DISPLAY SINGLY LINKED LIST
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
int main() {
    Node* h = new Node(10); h->n = new Node(20); h->n->n = new Node(30);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 2. INSERT AT BEGINNING
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void insBeg(Node*& h, int v) { Node* p = new Node(v); p->n = h; h = p; }
int main() {
    Node* h = nullptr;
    insBeg(h, 30); insBeg(h, 20); insBeg(h, 10);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 3. INSERT AT END
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void insEnd(Node*& h, int v) {
    Node* p = new Node(v);
    if (!h) { h = p; return; }
    Node* t = h; while (t->n) t = t->n;
    t->n = p;
}
int main() {
    Node* h = nullptr;
    insEnd(h, 10); insEnd(h, 20); insEnd(h, 30);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 4. INSERT AT GIVEN POSITION
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void insPos(Node*& h, int v, int pos) {
    if (pos == 1) { Node* p = new Node(v); p->n = h; h = p; return; }
    Node* t = h;
    for (int i = 1; t && i < pos - 1; i++) t = t->n;
    if (t) { Node* p = new Node(v); p->n = t->n; t->n = p; }
}
int main() {
    Node* h = nullptr;
    insPos(h, 10, 1); insPos(h, 30, 2); insPos(h, 20, 2);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 5. DELETE FROM BEGINNING
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void delBeg(Node*& h) {
    if (!h) return;
    Node* t = h; h = h->n; delete t;
}
int main() {
    Node* h = new Node(10); h->n = new Node(20);
    delBeg(h);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 6. DELETE FROM END
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void delEnd(Node*& h) {
    if (!h) return;
    if (!h->n) { delete h; h = nullptr; return; }
    Node* t = h;
    while (t->n->n) t = t->n;
    delete t->n; t->n = nullptr;
}
int main() {
    Node* h = new Node(10); h->n = new Node(20);
    delEnd(h);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 7. DELETE FROM GIVEN POSITION
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void delPos(Node*& h, int pos) {
    if (!h) return;
    if (pos == 1) { Node* t = h; h = h->n; delete t; return; }
    Node* t = h;
    for (int i = 1; t && i < pos - 1; i++) t = t->n;
    if (!t || !t->n) return;
    Node* d = t->n; t->n = t->n->n; delete d;
}
int main() {
    Node* h = new Node(10); h->n = new Node(20); h->n->n = new Node(30);
    delPos(h, 2);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 8. SEARCH ELEMENT
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
int search(Node* h, int key) {
    for (int pos = 1; h; h = h->n, pos++)
        if (h->d == key) return pos;
    return -1;
}
int main() {
    Node* h = new Node(10); h->n = new Node(20);
    int p = search(h, 20);
    cout << (p != -1 ? "Found at pos " + to_string(p) : "Not found") << "\n";
}
*/

// 9. COUNT NODES
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
int countNodes(Node* h) {
    int c = 0; for (; h; h = h->n) c++; return c;
}
int main() {
    Node* h = new Node(10); h->n = new Node(20); h->n->n = new Node(30);
    cout << "Total Nodes: " << countNodes(h) << "\n";
}
*/

// 10. FIND MIN & MAX
/*
#include <iostream>
#include <climits>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void minMax(Node* h) {
    int mn = INT_MAX, mx = INT_MIN;
    for (; h; h = h->n) { mn = min(mn, h->d); mx = max(mx, h->d); }
    cout << "Min: " << mn << ", Max: " << mx << "\n";
}
int main() {
    Node* h = new Node(25); h->n = new Node(5); h->n->n = new Node(50);
    minMax(h);
}
*/

// 11. REVERSE A SINGLY LINKED LIST
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
Node* rev(Node* h) {
    Node *p = nullptr, *c = h, *nxt;
    while (c) { nxt = c->n; c->n = p; p = c; c = nxt; }
    return p;
}
int main() {
    Node* h = new Node(1); h->n = new Node(2); h->n->n = new Node(3);
    h = rev(h);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 12. SORT LINKED LIST (ASCENDING)
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
void sortList(Node* h) {
    for (Node* i = h; i && i->n; i = i->n)
        for (Node* j = i->n; j; j = j->n)
            if (i->d > j->d) swap(i->d, j->d);
}
int main() {
    Node* h = new Node(40); h->n = new Node(10); h->n->n = new Node(30);
    sortList(h);
    for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
    cout << "NULL\n";
}
*/

// 13. MENU DRIVEN LINKED LIST
/*
#include <iostream>
using namespace std;
struct Node { int d; Node* n; Node(int v): d(v), n(nullptr){} };
int main() {
    Node* h = nullptr;
    int ch, v;
    while (true) {
        cout << "\n1.InsBeg 2.DelBeg 3.Display 4.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            cin >> v; Node* p = new Node(v); p->n = h; h = p;
        } else if (ch == 2) {
            if (h) { Node* t = h; h = h->n; delete t; }
            else cout << "Empty\n";
        } else if (ch == 3) {
            for (Node* t = h; t; t = t->n) cout << t->d << " -> ";
            cout << "NULL\n";
        } else break;
    }
}
*/

// 14. DOUBLY LINKED LIST (INSERTION & DELETION)
/*
#include <iostream>
using namespace std;
struct DNode { int d; DNode *p, *n; DNode(int v): d(v), p(nullptr), n(nullptr){} };
void ins(DNode*& h, int v) {
    DNode* x = new DNode(v);
    if (h) { x->n = h; h->p = x; }
    h = x;
}
void del(DNode*& h) {
    if (!h) return;
    DNode* t = h; h = h->n;
    if (h) h->p = nullptr;
    delete t;
}
int main() {
    DNode* h = nullptr;
    ins(h, 20); ins(h, 10); del(h);
    for (DNode* t = h; t; t = t->n) cout << t->d << " <-> ";
    cout << "NULL\n";
}
*/

// 15. CIRCULAR LINKED LIST (INSERTION & TRAVERSAL)
#include <iostream>
using namespace std;
struct CNode { int d; CNode* n; CNode(int v): d(v), n(nullptr){} };

void insEnd(CNode*& h, int v) {
    CNode* p = new CNode(v);
    if (!h) { h = p; p->n = h; return; }
    CNode* t = h;
    while (t->n != h) t = t->n;
    t->n = p; p->n = h;
}

int main() {
    CNode* h = nullptr;
    insEnd(h, 10); insEnd(h, 20); insEnd(h, 30);
    CNode* t = h;
    if (t) {
        do { cout << t->d << " -> "; t = t->n; } while (t != h);
        cout << "(Head: " << h->d << ")\n";
    }
    return 0;
}
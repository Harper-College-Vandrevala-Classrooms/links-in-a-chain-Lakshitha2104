#include <iostream>
#include <string>
using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
private:
    ChainLink* data;
    Node* next;

public:
    Node(ChainLink* data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }

    ChainLink* get_data() {
        return data;
    }

    Node* get_next() {
        return next;
    }

    void set_next(Node* next) {
        this->next = next;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* to_delete = current;
            current = current->get_next();
            delete to_delete;
        }
    }

    void append(ChainLink* link) {
        Node* new_node = new Node(link);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->get_next() != nullptr) {
                current = current->get_next();
            }
            current->set_next(new_node);
        }
    }

    ChainLink* get_at(int index) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) {
                return current->get_data();
            }
            current = current->get_next();
            count++;
        }
        return nullptr; // Index out of bounds
    }
};

int main() {
    LinkedList chain;

    ChainLink* red_link = new ChainLink("red");
    chain.append(red_link);

    ChainLink* blue_link = new ChainLink("blue");
    chain.append(blue_link);

    ChainLink* green_link = new ChainLink("green");
    chain.append(green_link);

    cout << "ChainLink at index 0: " << chain.get_at(0)->get_color() << endl;
    cout << "ChainLink at index 1: " << chain.get_at(1)->get_color() << endl;
    cout << "ChainLink at index 2: " << chain.get_at(2)->get_color() << endl;

    return 0;
}
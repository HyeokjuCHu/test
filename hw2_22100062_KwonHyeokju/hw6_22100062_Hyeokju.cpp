#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node* next;

    void set_data(string n, double s) {
        name = n;
        score = s;
    }
};

class my_list {
private:
    node* head;
    int count;
    double sum;

public:
    my_list() {
        head = nullptr;
        count = 0;
        sum = 0.0;
    }

    void add_to_head(node& new_node) {
        node* temp = new node;
        *temp = new_node;
        temp->next = head;
        head = temp;
        count++;
        sum += temp->score;
    }

    void add_to_tail(node& new_node) {
        node* temp = new node;
        *temp = new_node;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
        } else {
            node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = temp;
        }
        count++;
        sum += temp->score;
    }

    node delete_from_head() {
        if (head == nullptr) {
            cerr << "List is empty." << endl;
            exit(EXIT_FAILURE);
        }
        node* temp = head;
        head = head->next;
        node removed_node = *temp;
        delete temp;
        count--;
        sum -= removed_node.score;
        return removed_node;
    }

    double get_score(string name) {
        node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                return current->score;
            }
            current = current->next;
        }
        return -1; // Assuming -1 indicates that name was not found
    }

    int remove_a_node(string name) {
        node* current = head;
        node* prev = nullptr;
        while (current != nullptr) {
            if (current->name == name) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                count--;
                return 1;
            }
            prev = current;
            current = current->next;
        }
        return 0;
    }

    int num_nodes() {
        return count;
    }

    double score_sum() {
        return sum;
    }
};

int main() {
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";

    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);

    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    cout << "Park’s score : " << a.get_score("Park") << "\n";

    if (a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    return 0;
}

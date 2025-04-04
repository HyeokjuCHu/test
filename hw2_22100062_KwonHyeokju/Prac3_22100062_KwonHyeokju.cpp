#include <iostream>
#include <string>

//  An ordered list using linked list
//  Practice in class

using namespace std;

class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
public:
        my_list() {
                head = NULL;
        }
        void insert_node(node   t);
        void show_all_data();
};

void my_list::insert_node(node t) {
    node *new_node = new node;
    *new_node = t;
    new_node->link = nullptr;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    node *prev = nullptr;
    node *current = head;

    while (current != nullptr && current->score < t.score) {
        prev = current;
        current = current->link;
    }

    if (prev == nullptr) {
        new_node->link = head;
        head = new_node;
    } else {
        prev->link = new_node;
        new_node->link = current;
    }
}



void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}


int main()
{
my_list    thelist;
node   tmp;
        tmp.set_data("Kim", 73.5);
        thelist.insert_node(tmp);
        tmp.set_data("Lee", 82.2);
        thelist.insert_node(tmp);
        tmp.set_data("Park", 51.3);
        thelist.insert_node(tmp);
        tmp.set_data("Choi", 95.1);
        thelist.insert_node(tmp);
        tmp.set_data("Ryu", 71.3);
        thelist.insert_node(tmp);
        tmp.set_data("Yang", 58.2);
        thelist.insert_node(tmp);
        tmp.set_data("Hong", 83.5);
        thelist.insert_node(tmp);

        cout << "-- The list after insertions \n";
        thelist.show_all_data();

        return 0;
}


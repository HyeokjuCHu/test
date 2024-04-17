#include <iostream>
#include <string>
using namespace std;

#define   YES           1
#define   NO            0
#define   SUCCESS       1
#define   FAIL          0

class node {
public:
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

void node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
public:
        my_list() {
                head = NULL;
        }
        void add_to_head(node   t);
        double get_best_score();
        int  modify_score(string tname, double tscore);
        void show_all_data();
};

void my_list::add_to_head(node t) {
        node   *p;
        p = new   node;
        (*p) = t;
        p->link = head;
        head = p;
}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}

int  my_list:: modify_score(string tname, double tscore)
{
    node* current = head;
    int check=0;
    while (current != nullptr) {
        if (current->name == tname) {
            current->score=tscore;
            check=1;
            break;
        }

    current = current->link;

    }
    return check;
}


double  my_list:: get_best_score()
{
    double bMax=0.0;
    node* current = head;
    while (current != nullptr) {
        if (current->score>bMax) {
            bMax=current->score;
        }
        current=current->link;
    }
    return bMax;
}

int main()
{
my_list    a;
node   tmp;
        tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 41.3);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        a.show_all_data();

        if ( a.modify_score("Choi", 88.2) == SUCCESS)
                cout << "Choi's score has been changed. \n";
        else
                cout << " Modification FAILED !! \n";

        cout << "-- After the modification \n";

        a.show_all_data();

        double best = a.get_best_score();

        if (best < 0)
                cout << " The list is empty. \n";
        else
                cout << "* The Best Score = " << best << endl;

        return 0;

}

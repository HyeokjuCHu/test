#include <iostream>

using namespace std;

class Weight {
private:
    int kilograms;
    int grams;

public:
    Weight() {
        kilograms = 0;
        grams = 0;
    }

    void set_weight(int kg, int g) {
        kilograms = kg;
        grams = g;
    }


    int get_weight() {
        return kilograms * 1000 + grams;
    }
};


Weight add_weight(Weight w1, Weight w2) {
    Weight result;
    int total_grams = w1.get_weight() + w2.get_weight();
    result.set_weight(total_grams / 1000, total_grams % 1000);
    return result;
}

bool less_than(Weight w1, Weight w2) {
    return w1.get_weight() < w2.get_weight();
}

int main() {
    Weight w1, w2, w3;

    w1.set_weight(3, 400);
    w2.set_weight(2, 700);

    w3 = add_weight(w1, w2);

    cout <<  w3.get_weight() << " grams\n";

    if (less_than(w1, w2))
        cout << "yes.\n";
    else
        cout << "no.\n";

}

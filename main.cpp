#include <iostream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

constexpr int NUM_TELLERS = 3;
constexpr int NUM_CUSTOMERS = 50;

void customer(int id)
{
    cout << "Customer " << id << " created\n";
}

void teller(int id)
{
    cout << "Teller " << id << " ready to serve\n";
}

int main()
{
    vector<thread> tellers;
    vector<thread> customers;

    for (int i = 1; i <= NUM_TELLERS; ++i) {
        tellers.emplace_back(teller, i);
    }

    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        customers.emplace_back(customer, i);
    }

    for (auto& c : customers) {
        c.join();
    }

    for (auto& t : tellers) {
        t.join();
    }

    return 0;
}
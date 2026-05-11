#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Class Parent ---
class User {
protected:
    static int globalId; // Variabel statis untuk menghitung ID secara global
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        generateId();
    }

    void generateId() {
        globalId++;
        this->id = globalId;
    }
};
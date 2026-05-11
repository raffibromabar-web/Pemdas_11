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

// Inisialisasi awal variabel statis
int User::globalId = 0;

// --- Class Child: Member ---
class Member : public User {
private:
    string status;

public:
    // Constructor
    Member(string nama, string email) : User(nama, email) {
        this->status = "Aktif"; // Default status
    }

    void setStatus(string statusBaru) {
        this->status = statusBaru;
    }

    string getStatus() {
        return status;
    }

    int getId() { return id; }
    string getNama() { return nama; }

    void showProfile() {
        cout << "=== Profil Member ===" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << status << endl;
        cout << "---------------------" << endl;
    }
};

// --- Class Child: Admin ---
class Admin : public User {
public:
    Admin(string nama, string email) : User(nama, email) {}

    // Fungsi untuk menampilkan semua member
    void showAllMember(const vector<Member>& daftarMember) {
        cout << "\n[Admin] Daftar Seluruh Member:" << endl;
        for (auto m : daftarMember) {
            cout << "- ID: " << m.getId() << " | Nama: " << m.getNama() << " | Status: " << m.getStatus() << endl;
        }
    }

    // Fungsi untuk mengubah status aktivasi (Toggle)
    void toggleActivationMember(Member& m) {
        if (m.getStatus() == "Aktif") {
            m.setStatus("Non-Aktif");
        } else {
            m.setStatus("Aktif");
        }
        cout << "\n[Admin] Status Member " << m.getNama() << " berhasil diubah." << endl;
    }
};
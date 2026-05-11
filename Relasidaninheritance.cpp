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

// --- Main Program ---
int main() {
    // Membuat Admin
    Admin adminUtama("Super Admin", "admin@web.com");

    // Membuat beberapa Member
    vector<Member> listMember;
    listMember.push_back(Member("helmi", "helmigantengs@mail.com"));
    listMember.push_back(Member("Siti Aminah", "siti@mail.com"));

    // Menampilkan profil awal salah satu member
    listMember[0].showProfile();

    // Admin melihat semua member
    adminUtama.showAllMember(listMember);

    // Admin mengubah status Budi
    adminUtama.toggleActivationMember(listMember[0]);

    // Lihat perubahan pada profil Budi
    listMember[0].showProfile();

    return 0;
}
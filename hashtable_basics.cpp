#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct HashTable {
    int MAX_LENGTH = 4;
    string* password = new string[MAX_LENGTH];

    void initialize_hashtable() {
        for (int i = 0; i < 4; i++) {
            password[i].clear();
        }
    }

    bool isFull() {
        bool full = true;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (password[i].empty()) {
                full = false;
            }
        }
        return full;
    }

    int hashfunc(string username) {
        int sum = 0;
        for (char c : username) {
            sum += int(c);
        }
        int hash = sum % MAX_LENGTH;
        return hash;
    }

    bool is_slot_empty(int hash) {
        bool empty = password[hash].empty();
        return empty;
    }

    void insert(string username, string user_password) {
        int hash = hashfunc(username);
        bool empty = is_slot_empty(hash);

        if (empty) {
            password[hash] = user_password;
            cout << "User inserted successfully\n";
        } else {
            cout << "Hash collision! User not inserted\n";
        }
    }

    void hash_lookup(string username) {
        int hash = hashfunc(username);
        bool empty = is_slot_empty(hash);

        if (empty) {
            cout << "User not found\n";
        } else {
            cout << "Password: " << password[hash] << endl;
        }
    }

    void delete_item(string username) {
        int hash = hashfunc(username);
        bool empty = is_slot_empty(hash);

        if (empty) {
            cout << "User not found\n";
        } else {
            password[hash].clear();
            cout << "User deleted\n";
        }
    }

    void print_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            cout << "[" << i << "]-->" << password[i] << "\n";
        }
    }
};

int main() {
    HashTable* hashtbl = new HashTable;
    hashtbl->initialize_hashtable();
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string username;
    string password;
    while (command != -1) {
        cout << "Type command: ";
        cin >> command;
        switch (command) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password to be saved: ";
                cin >> password;
                hashtbl->insert(username, password);
                break;
            case 2:
                cout << "Enter username to be deleted: ";
                cin >> username;
                hashtbl->delete_item(username);
                break;
            case 3:
                cout << "Enter username to look up password: ";
                cin >> username;
                hashtbl->hash_lookup(username);
                break;
            case 4:
                hashtbl->print_hashtable();
                break;
            case -1:
                cout << "Exiting...\n";
                break;
        }
    }

    delete hashtbl;
    return 0;
}


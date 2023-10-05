//
//  main.cpp
//  problem2
//
//  Created by Neelov Alam on 7/1/23.
//

#include <iostream>
#include <string>
using namespace std;

struct key {
    int num;
    string name;
    double balance;
};

class Hasharray {
private:

    key* array[753];
    
  
    int hash(int key, int i) {
        return (key % 753 + i) % 753;
    }

public:
    Hasharray() {
        for (int i = 0; i < 753; i++) {
            array[i] = nullptr;
        }
    }
    

void INSERT_Account(key* record) {
    int key = record->num;
    int index = hash(key, 0);
    int i = 1;
        
    while (array[index] != nullptr) {
        index = hash(key, i);
        i++;
    }
        
    array[index] = record;
}
    
    
key* SEARCH_Account(int num) {
    int index = hash(num, 0);
    int i = 1;
    
    while (array[index] != nullptr && array[index]->num != num) {
        index = hash(num, i);
        i++;
    }
        
    return array[index];
    }
};

int main() {
    int n;
    string name;
    double balance;
    
    int choice;
    Hasharray hasharray;
    key account;
    key* case2account;
    cout << "Welcome to Sun Devil Bank" << endl;
    while (true)
    {
        cout << endl << endl;
        cout << " Options " << endl;
        cout << " --------" << endl;
        cout << " 1. Insert Account " << endl;
        cout << " 2. Search Account " << endl;
        cout << " 3. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << " Enter account number (int value) to be inserted : ";
                cin >> n;
                if (n < 100001 || n > 999999) {
                    cout << "Number must be between 100001 and 999999" << endl;
                    break;
                }
                cout << " Enter account name (string value) to be inserted : ";
                cin >> name;
                cout << " Enter account balance (double value) to be inserted : ";
                cin >> balance;
                
                account = {n, name, balance};
                hasharray.INSERT_Account(&account);
                break;
            case 2:
                cout << " Enter account number (int value) you would like to find : ";
                cin >> n;
                case2account = hasharray.SEARCH_Account(n);
                
                if (case2account != nullptr) {
                    cout << "Account number :" << case2account->num <<endl;
                    cout << "Account name :" << case2account->name <<endl;
                    cout << "Account balance : $" << case2account->balance <<endl;
                }
                break;
            case 3:
                system("pause");
                return 0;
                break;
            default:
                cout << "Invalid choice";
        }
    }
}

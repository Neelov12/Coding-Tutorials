//
//  hash_Alamopen.cpp
//  CSE310_homework4
//
//  Created by Neelov Alam on 7/1/23.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class sundevilbank
{
private:
    class key
    {
    public:
        key* next;
        int number;
        string name;
        double balance;
    };


public:
    key* array[753];
    sundevilbank()
    {
        for (int i = 0; i < 753; i++) {
            array[i] = NULL;
        }
    }
    
    void INSERT_Account(key* [], key* );
    void DELETE_Account(key* [], int);
    void SEARCH_Account(key* [], int);
    
    key* CREATE_KEY(int n, string s, double d) {
        key* z = new key();
        z->next = NULL;
        z->number = n;
        z->name = s;
        z->balance = d;
        
        return z; 
    }
};

void sundevilbank::INSERT_Account(key* arg[], key* account) {
    
}

void sundevilbank::DELETE_Account((key* arg[],  account) )


int main() {
    int choice;
    sundevilbank yuh;
    int number;
    string name;
    double balance;
    
    cout << "Welcome to Sun Devil Bank/n" << endl;
    while (true)
    {
        cout << endl << endl;
        cout << " Binary Search Tree Example " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insert Account " << endl;
        cout << " 2. Delete Account " << endl;
        cout << " 3. Search Account " << endl;
        cout << " 4. Exit " << endl;
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << " Enter account number (int value) to be inserted : ";
                cin >> number;
                cout << " Enter account name (string value) to be inserted : ";
                cin >> name;
                cout << " Enter account balance (double value) to be inserted : ";
                cin >> balance;
                
                yuh.INSERT_Account(yuh.array, yuh.CREATE_KEY(number, name, balance));
                break;
            case 2:
                
            case 4:
                system("pause");
                return 0;
                break;
            default:
                cout << "Invalid choice";
        }
        return 0;
    }
}

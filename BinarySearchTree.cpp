// Neelov Alam CSE 310

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
    // This is the node
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};


public:
    // This is the first node
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
    // These are all the implementation functions
	bool isEmpty() const { return root == NULL; }
    void TREE_INSERT(int );
	void INORDER_TREE_WALK(node*);
    void POSTORDER_TREE_WALK(node*);
    void PREORDER_TREE_WALK(node*);
    int FIND_MIN(node*);
    int FIND_MAX(node*);
    void SUCCESSOR(node*, int );
    void DELETE(int );
    void REMOVE_MIN(node* );
    void MODIFIED_TREE_INSERT(int, int, string );
    // Search function 
    node* SEARCH(int n) {
        node* x = root;
        
        while(x->key != n) {
            if (n < x->key) {
                if (x-> left) x = x->left;
                else return NULL;
            }
            else {
                if (x-> right) x = x->right;
                else return NULL;
            }
        }
        return x;
    }
};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
		
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " " << x->data << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::POSTORDER_TREE_WALK(node* x) {
    if (x != NULL) {
        if (x->left) POSTORDER_TREE_WALK(x->left);
        if (x->right) POSTORDER_TREE_WALK(x->right);
        cout << " " << x->key << " " << x->data << " ";
    }
}

void BinarySearchTree::PREORDER_TREE_WALK(node* x) {
    if (x != NULL) {
        cout << " " << x->key << " " << x->data << " ";
        if (x->left) PREORDER_TREE_WALK(x->left);
        if (x->right) PREORDER_TREE_WALK(x->right);
    }
}

int BinarySearchTree::FIND_MIN(node* x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x->key;
}

int BinarySearchTree::FIND_MAX(node* x) {
    while (x->right != NULL) {
        x = x->right;
    }
    return x->key;
}

void BinarySearchTree::SUCCESSOR(node* x, int n) {
    //node* x = root;
    int max = 0;
    max = FIND_MAX(x);

    x = SEARCH(n);
    if(x == NULL) {
        cout << "Key not in list ";
        return;
    }
    // If node is max, there is no successor
    if (x->key == max) {
        cout << "There is no successor ";
        return;
    }
        
    if (x->right != NULL) {
        x = x->right;
        
        while(x->left != NULL) {
            x = x->left;
        }
        cout << " " << x->key << " ";
    }
    else {
        while(x->parent != NULL && x->parent->key < x->key)
            x = x->parent;
            
        if (x->parent) x = x->parent;
            cout << " " << x->key << " ";
        }
}


void BinarySearchTree::DELETE (int n) {
    node* x = root;
    node* parent = nullptr;
    
    x = SEARCH(n);
    
    if(x == NULL) {
        cout << "Key not in list ";
        return;
    }
    
    parent = x->parent;
    
    // Case 1: Node has no children
    
    if (x->left == NULL && x->right == NULL) {
        if (x != root) {
            if (parent->left == x) {
                parent->left = nullptr;
            }
            if (parent->right == x) {
                parent->right = nullptr;
                }
            }
            
            else {
                root = nullptr;
            }
    }
    
    // Case 2: Node has one child
    
    else if (x->left == NULL || x->right == NULL) {
        node* child = (x->left)? x->left: x->right;
        
        if (x != root) {
            if (x == parent->left) {
                parent->left = child;
            }
            else{
                parent->right = child;
            }
        }
         
        else {
            root = child;
            }
        
    // Case 3: Node has two children
        
    }
    else {
        node* y = x->right;
        
        while(y->left != NULL)
            y = y->left;
        
        if (x != root) {
                if (parent->left == x) {
                    if (x->left) {
                        node* ytemp = y;
                        ytemp->left = x->left;
                        parent->left = ytemp;
                    }
                    else
                        parent->left = y;
                }
                if (parent->right == x) {
                    if (x->left) {
                        node* ytemp = y;
                        ytemp->left = x->left;
                        parent->right = ytemp;
                    }
                    else
                        parent->right = y;
                }
            }
          
        // If node is root
        
        else {
            if (x->left) {
                node* ytemp = y;
                ytemp->left = x->left;
                root = ytemp;
            }
            else
                root = y;
        }
    }
}

void BinarySearchTree::REMOVE_MIN(node* n) {
    node* x = SEARCH(FIND_MIN(n));
    DELETE(x->key);
}

// Method for Problem 2
void BinarySearchTree::MODIFIED_TREE_INSERT(int d, int k, string name)
{
    // This implements the algorithm in page 261 of the textbook
    node* z = new node();
    z->key = d;
    z->data = name;
    z->left = NULL;
    z->right = NULL;

    node* y = NULL;
    node* x = root;

    while (x != NULL)
    {
        y = x;
        if (z->key < x->key && (x->key - z->key) >= k)
            x = x->left;
        else if (z->key > x->key && (z->key - x->key) >= k)
            x = x->right;
        else {
            cout << "Flight info not entered. Time gap is too small" << endl;
            return;
        }
    }

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
        
}

int main()
{
	BinarySearchTree bst;
	int choice, key;
    int choice2; // Im not very creative with names
    int number;
    int k;
    string name;
    bool case10 = true;
    
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion " << endl;
		cout << " 2. In-Order Traversal " << endl;
        cout << " 3. Post-Order Traversal " << endl;
        cout << " 4. Pre-Order Traversal " << endl;
        cout << " 5. Find Minimum " << endl;
        cout << " 6. Find Maximum " << endl;
        cout << " 7. Find Successor " << endl;
        cout << " 8. Delete " << endl;
        cout << " 9. Remove Min " << endl;
        cout << " 10. Enter Flight Time Simulator " << endl;
		cout << " 11. Exit " << endl;
        cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
        {
            case 1: cout << " Enter key (int value) to be inserted : ";
                cin >> key;
                bst.TREE_INSERT(key);
                break;
            case 2: cout << endl;
                cout << " In-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.INORDER_TREE_WALK(bst.root);
                break;
            case 3:
                cout << " Post-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.POSTORDER_TREE_WALK(bst.root);
                break;
            case 4:
                cout << " Pre-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.PREORDER_TREE_WALK(bst.root);
                break;
            case 5:
                cout << " Minimum value " << endl;
                cout << " -------------------" << endl;
                cout << " " << bst.FIND_MIN(bst.root) << " " << endl;
                break;
            case 6:
                cout << " Maximum value " << endl;
                cout << " -------------------" << endl;
                cout << " " << bst.FIND_MAX(bst.root) << " " << endl;
                break;
            case 7:
                cout << " Enter key (int value) whose successor you are looking for :  ";
                cin >> key;
                cout << " Successor " << endl;
                cout << " -------------------" << endl;
                bst.SUCCESSOR(bst.root, key);
                break;
            case 8:
                cout << " Enter key (int value) that you would like to delete :  ";
                cin >> key;
                bst.DELETE(key);
                cout << " Deleted " << endl;
                cout << " -------" << endl;
                break;
            case 9:
                bst.REMOVE_MIN(bst.root);
                cout << " Removed Min " << endl;
                cout << " -----------" << endl;
                break;
            case 10: // Problem 2
                bst.root = NULL;
                case10 = true;
                k = 0;
                cout << " " << endl;
                cout << " Flight Time Simulator " << endl;
                cout << " --------------------- " << endl;
                
                while(case10) {
                    cout << " " << endl;
                    cout << " 1. Request " << endl;
                    cout << " 2. In-Order Traversal " << endl;
                    cout << " 3. Post-Order Traversal " << endl;
                    cout << " 4. Pre-Order Traversal " << endl;
                    cout << " 5. Withdraw " << endl;
                    cout << " 6. Enter K Time Gap " << endl;
                    cout << " 7. Exit " << endl;
                    cout << " " << endl;
                    cout << " Enter your choice : ";
                    cin >> choice2;
                    
                    switch(choice2) {
                        case 1:
                            cout << " Enter flight number : ";
                            cin >> number;
                            cout << " Enter flight name : ";
                            cin >> name;
                            bst.MODIFIED_TREE_INSERT(number, k, name);
                            break;
                        case 2:
                            cout << " In-Order Traversal " << endl;
                            cout << " -------------------" << endl;
                            bst.INORDER_TREE_WALK(bst.root);
                            break;
                        case 3:
                            cout << " Post-Order Traversal " << endl;
                            cout << " -------------------" << endl;
                            bst.POSTORDER_TREE_WALK(bst.root);
                            break;
                        case 4:
                            cout << " Pre-Order Traversal " << endl;
                            cout << " -------------------" << endl;
                            bst.PREORDER_TREE_WALK(bst.root);
                            break;
                        case 5:
                            cout << " Enter flight number that you would like to withdraw :  ";
                            cin >> key;
                            bst.DELETE(key);
                            cout << " Withdrawn " << endl;
                            cout << " -------" << endl;
                            break;
                        case 6:
                            cout << " Enter K Time gap :  ";
                            cin >> k;
                            cout << " Entered" << endl;
                            cout << " Note: You can always change K at any time. However, changing it will not affect previously entered data. Also, K time is set to 0 by default." << endl;
                            break;
                        case 7:
                            case10 = false;
                            break;
                        default:
                            cout << "Invalid choice";
                    }
                }
        
                break;
		case 11: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}


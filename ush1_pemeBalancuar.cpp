#include <iostream>
#include <fstream>

using namespace std;

int i = 1;
struct Node {
    string word;
    Node *left;
    Node *right;
    int height;
};
int max(int x, int y) {
    if(x>y)
        return x;
    return y;
}

int height(Node *tmp) {
    if(tmp==NULL)
        return 0;
    return tmp->height;
}
bool existsWord(Node *root, string w) {
    if(root==NULL) {
        return false;
    }
    if(root->word==w) {
        return true;
    }
    if(w>root->word) {
        return existsWord(root->left,w);
    } else {
        return existsWord(root->right,w);
    }
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}
int getBalance(Node *tmp)
{
    if (tmp == NULL)
        return 0;
    return height(tmp->left) - height(tmp->right);
}
Node *newNode(string w) {
    Node *temp = new Node;
    temp->word = w;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

Node *add(Node *root, string w) {
    if(root==NULL)
        return newNode(w);

    if(existsWord(root,w))
        return root;

    if(w<root->word) {
        root->left = add(root->left,w);
    } else {
        root->right = add(root->right,w);
    }
    root->height = 1 + max(height(root->left),height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && w < root->left->word)
        return rightRotate(root);

    if (balance < -1 && w > root->right->word)
        return leftRotate(root);

    if (balance > 1 && w > root->left->word)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && w < root->right->word)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void printUniqueWords(Node *root)
{
    if (root != NULL)
    {
        printUniqueWords(root->left);
		cout<<i<<" "<<root->word<<endl;
		i++;
        printUniqueWords(root->right);
    }
}

int main(int argc, char * argv[]) {
	ifstream in;
	Node* head = new Node;
	int count = 0;
	in.open("fjalori.txt");
	while(!in.eof()){
		string str;
		in>>str;

		if(count == 0){
			head = add(NULL,str);
			count++;
		}
		else {
			head = add(head,str);
		}

	}
	in.close();
	printUniqueWords(head);

	return 0;
}

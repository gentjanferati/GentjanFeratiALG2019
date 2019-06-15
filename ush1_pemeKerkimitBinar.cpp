#include <iostream>
#include <fstream>

using namespace std;

int i = 1;

struct Node {
    string word;
    Node *left;
    Node *right;
};

bool existsWord(Node *root, string w) {
    if(root==NULL) {
        return false;
    }
    if(root->word==w) {
        return true;
    }
    if(w<root->word) {
        return existsWord(root->left,w);
    } else {
        return existsWord(root->right,w);
    }
}
Node *newNode(string w) {
    Node *temp = new Node;
    temp->word = w;
    temp->left = NULL;
    temp->right = NULL;
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
			head->word = str;
			head->left = NULL;
			head->right = NULL;
			count++;
		}
		else {
			head = add(head,str);
		}

	}
	printUniqueWords(head);

	return 0;
}


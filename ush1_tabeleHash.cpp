#include <iostream>
#include <fstream>

using namespace std;

int c = 0;  // Celsi
int j = 1;  // Printimi

struct Node {
    int key;
    string word;
    Node *next;
};

Node *addElement(Node *head, int k, string w)
{
    Node * tmp = new Node;
    tmp->key = k;
    tmp->word = w;
    tmp->next = head;

    head = tmp;

    return head;
}

bool existsWord(Node *T[], int n, string w) {
    for(int i=0;i<n;i++) {
        if(T[i]!=NULL && T[i]->word == w) {
            return true;
        }
    }
    return false;
}
void printUniqueWords(Node *T[], int n) {
    for(int i=0;i<n;i++) {
        if(T[i]!=NULL) {
            cout<<j<<" "<<T[i]->word<<endl;
            j++;
        }
    }
}
int main(int argc, char * argv[]) {

    int N = 10000;

    Node *hashTable[N];

    for(int i=0;i<N;i++) {
        hashTable[i] = NULL;
    }

	ifstream in;

	int count = 0;
	int i = 0;
	in.open("fjalori.txt");

	while(!in.eof() && i<N){
		string str;
		in>>str;
		if(!existsWord(hashTable,N,str)) {
            hashTable[i] = addElement(hashTable[i],c,str);
            i++;
            c++;
		}
	}
	in.close();
	printUniqueWords(hashTable,N);

	return 0;
}

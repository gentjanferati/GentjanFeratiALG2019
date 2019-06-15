#include <iostream>
#include <fstream>

using namespace std;

struct Node{
	string word;
	Node* next;
};

bool existsWord(Node* head, string w){
	Node* tmp = head;
	while(tmp != NULL){
		if(tmp->word == w){
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}
Node* add(Node* head, string w) {
	if(existsWord(head,w)){
		return head;
	}
	else{
		Node* tmp = new Node;
		tmp->word = w;
		tmp->next = head;
		head = tmp;
		return head;
	}
}

void printUniqueWords(Node* head){
	Node* tmp = head;
	int i = 1;
	while(tmp != NULL){
		cout<<i<<" "<<tmp->word<<endl;
		tmp = tmp->next;
		i++;
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
			head->next = NULL;
			count++;
		}
		else {
			head = add(head,str);
		}

	}
	printUniqueWords(head);

	return 0;
}

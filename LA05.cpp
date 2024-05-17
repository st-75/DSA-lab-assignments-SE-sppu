/*
A Dictionary stores keywords & its meanings. Provide facility for adding
new keywords,deleting keywords, updating values of any entry. Provide facility to
display whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Binary Search
Tree for implementation.
*/
// Dictionary store keyword and meaning

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
struct node
{
	char word[10];
	string meaning;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void adWord()
{
	struct node *temp = new node;

	cout << "\nENTER WORD : ";
	cin >> temp->word;
	cout << "\nENTER MEANING : ";
	cin.get();
	getline(cin, temp->meaning);

	temp->left = NULL;
	temp->right = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *p = root;
		struct node *q;

		while (p != NULL)
		{
			q = p;
			if (strcmp(temp->word, p->word) < 0)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}

		if (strcmp(temp->word, q->word) < 0)
		{
			q->left = temp;
		}
		else
		{
			q->right = temp;
		}
	} 
}

void displayWord(struct node *p)
{
	if (p->left != NULL)
	{
		displayWord(p->left);
	}
	cout << "\nWORD : " << p->word << "\tMEANING : " << p->meaning;
	if (p->right != NULL)
	{
		displayWord(p->right);
	}
}

void searchAndUpdate(struct node *p, char word[10])
{
	string newMeaning;
	if (strcmp(word, p->word) < 0)
	{
		searchAndUpdate(p->left, word);
	}
	if (strcmp(word, p->word) > 0)
	{
		searchAndUpdate(p->right, word);
	}
	if (strcmp(word, p->word) == 0)
	{
		cout << "\nENTER NEW MEANING OF WORD : ";
		cin.get();
		getline(cin, newMeaning);
		p->meaning = newMeaning;
	}
}

int count = 0;
void noOfComparisons(struct node *p, char word[])
{
	count++;
	if (strcmp(word, p->word) == 0)
	{
		cout << "\nTOTAL COMPARISONS : " << count;
		count = 0;
	}
	if (strcmp(word, p->word) < 0)
	{
		noOfComparisons(p->left, word);
	}
	if (strcmp(word, p->word) > 0)
	{
		noOfComparisons(p->right, word);
	}
}

void deleteNodes(struct node *p, char word[10])
{
	struct node *q;
	struct node *r;
	while (p != NULL)
	{
		q = p;
		if (strcmp(word, p->word) < 0)
		{
			p = p->left;
		}
		if (strcmp(word, p->word) > 0)
		{
			p = p->right;
		}
		if (strcmp(word, p->word) == 0)
		{
			break;
		}
	}
	while (1)
	{
		if (p == q && p->left == NULL && p->right == NULL)
		{
			root = NULL;
			delete p;
			break;
		}
		if (p == q && p->right == NULL && p->left != NULL)
		{
			strcpy(p->word, p->left->word);
			p->meaning = p->left->meaning;
			p->left = NULL;
			struct node *r = p->left;
			delete r;
			break;
		}
		if (p == q && p->left == NULL && p->right != NULL)
		{
			strcpy(p->word, p->right->word);
			p->meaning = p->right->meaning;
			p->right = NULL;
			struct node *r = p->right;
			delete r;

			break;
		}
		if (p != q && p->left == NULL && p->right == NULL)
		{
			if (q->right == p)
			{
				q->right = NULL;
				delete p;
				break;
			}
			if (q->left == p)
			{
				q->left = NULL;
				delete p;
				break;
			}
		}
		if (p->right != NULL && p->left == NULL)
		{
			if (q->right == p)
			{
				q->right = p->right;
				p->right = NULL;
				delete p;
				break;
			}
			if (q->left == p)
			{
				q->left = p->right;
				p->right = NULL;
				delete p;
				break;
			}
		}
		if (p->right == NULL && p->left != NULL)
		{
			if (q->right == p)
			{
				q->right = p->left;
				p->left = NULL;
				delete p;
				break;
			}
			if (q->left == p)
			{
				q->left = p->left;
				p->left = NULL;
				delete p;
				break;
			}
		}
		if (p->right != NULL && p->left != NULL)
		{
			/*if	(p->right->right==NULL && p->right->left==NULL && p->left->left==NULL && p->left->right==NULL){
						p->data=p->right->data;
						p->right=NULL;
						delete p->right;
			}*/
			struct node *t = p;
			struct node *r;
			p = p->right;
			char min[10];
			strcpy(min, p->word);
			while (p != NULL)
			{

				if (p->word < min)
				{
					strcpy(min, p->word);
					r = p;
				}
				p = p->left;
			}
			deleteNodes(root, min);
			strcpy(t->word, min);
			break;
		}
	}
}
// Main Function
int main()
{
	int ch, words;
	char newWord[10];
	while (true)
	{
		cout << "1.Insert The Data:" << endl;
		cout << "2.Display the Data" << endl;
		cout << "3.Search and Update" << endl;
		cout << "4.Find the Number of Comparisons" << endl;
		cout << "5.Delete the Node" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter the Choice:" << endl;
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "\nHow many words you want to add : ";
			cin >> words;
			for (int i = 0; i < words; i++)
			{
				adWord();
			}
			break;

		case 2:
			cout << "\n";
			displayWord(root);
			cout << "\n";
			break;

		case 3:
			cout << "\nEnter the word to search: ";
			cin >> newWord;
			searchAndUpdate(root, newWord);
			break;

		case 4:
			cout << "\nEnter the word to search: ";
			cin >> newWord;
			noOfComparisons(root, newWord);
			break;

		case 5:
			cout << "\nEnter the word to delete: ";
			cin >> newWord;
			deleteNodes(root, newWord);
			break;

		case 6:
			exit(0);

		default:
			cout << "\nInvalid choice!";
		}
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}





void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void Insert(Node*& pRoot, Node* pNewNode)
{
	if (!pRoot)
		pRoot = pNewNode;
	else
	{
		if (pNewNode->i < pRoot->i)
			Insert(pRoot->pLeft, pNewNode);
		else
			Insert(pRoot->pRight, pNewNode);
	}
}
int CalculateTheSumOfTheBranch(Node*pRoot,int sum)
{
	int sum;
	int right = 0;
	vector<int*> Sum;
	Node* currentNode = pRoot;
	if (right == 0)
	{
		while (pRoot->pRight != nullptr && right==0) {
			sum = pRoot->i + pRoot->pRight->i;
			return sum;
			currentNode = pRoot->pRight;
			sum = CalculateTheSumOfTheBranch(currentNode, sum);
			if (currentNode->pRight = nullptr)
				Sum.push_back(&sum);
			right = 1;
			while (pRoot->pRight != nullptr && right == 1) {
				currentNode = pRoot->pLeft;
				sum = CalculateTheSumOfTheBranch(currentNode, sum);
				if (currentNode->pRight = nullptr)
					Sum.push_back(&sum);

			}
		}
	}
		
	else
	{
		while (pRoot->pLeft != nullptr && right==1) {
			sum = pRoot->i + pRoot->pLeft->i;
			return sum;
			currentNode = pRoot->pLeft;
			sum = CalculateTheSumOfTheBranch(currentNode, sum);
			if (currentNode->pLeft = nullptr)
				Sum.push_back(&sum);
			right = 0;
			while (pRoot->pLeft != nullptr && right == 0) {
				currentNode = pRoot->pRight;
				sum = CalculateTheSumOfTheBranch(currentNode, sum);
				if (currentNode->pLeft = nullptr)
					Sum.push_back(&sum);

			}
		}

	}
}
void DisplayTheMaximumSum(vector<int*> Sum)
{
	
	int *maxsum= *max_element(Sum.begin(), Sum.end());

	cout << "maximum/largest element is: " << *maxsum << endl;

	
}

int main()
{
	int i;
	int sum;
	vector<int*> Sum;
	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
		CalculateTheSumOfTheBranch(pRoot, sum);
		DisplayTheMaximumSum(Sum);

	}
		
	
}

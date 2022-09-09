// HashTableDoubleHashing.cpp 



#include <iostream>
#define sh 10
#define p 7

using namespace std;

int h1(int key);
int h2(int key);
int DoubleHashing(int ht[], int i, int key);
void insert(int ht[], int key);




int h1(int key)
{
	return key % sh;
}

int h2(int key)
{
	return p - (key % p);
}

int DoubleHashing(int ht[],int i,int key)
{
	int vh1 = i;
	int vh2 = h2(key);
	int k = 1;

	while (ht[(vh1 + (k * vh2)) % sh] != 0)
		k++;

	return (vh1 + (k * vh2)) % sh;

}

void insert(int ht[], int key)
{
	int i = h1(key);

	if (ht[i] != 0)
	{
		i = DoubleHashing(ht, i, key);
	}

	ht[i] = key;
}

int search(int ht[], int key)
{

	int h1i = h1(key);
	int h2i = h2(key);

	int k = 0;
	while (ht[(h1i+(k*h2i))%sh] != key)
	{
		k++;
		if (ht[(h1i + (k * h2i)) % sh] == 0)
			return -1;

	}
	return (h1i + (k * h2i)) % sh;
}


int main()
{

	//hashtable 
	int ht[10] = { 0 };


	int a[] = { 5,25,15,35,95 };
	int n = sizeof(a) / sizeof(a[0]);

	//insert into the hash table
	for (int i = 0;i < n;i++)
		insert(ht, a[i]);

	//search in the hashtable
	search(ht, 95);

	//unsuccessful search
	search(ht, 105);




}

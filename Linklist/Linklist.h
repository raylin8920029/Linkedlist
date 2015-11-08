#ifndef _LINKLIST_H_
#define _LINKLIST_H_


#include <string> 
using namespace std;


const unsigned int MAX_TEXT_LENGTH = 10;


typedef struct T_Node
{
    char szName[MAX_TEXT_LENGTH + 1];
    struct T_Node* ptNext;
} TNode;


class CLinkedList  
{
// Constructor & Desctructor
public:
	CLinkedList();
	~CLinkedList();

// Operations
public:
	bool Append(const char* pszAppendName);
	bool Delete(const char* pszDeleteName);
	bool Find(const char* pszSearchName) const;
	int  GetLength() const;
	void Sort();
	void Display() const;

private:
	bool DuplicationCheck(const char* pszSearchName) const;
	
// Parameters
private:
	TNode* m_ptNode;
};


void ToLower(char *pszConvertedString);
int Compare(const void* pvVar1, const void* pvVar2);


#endif // _LINKLIST_H_
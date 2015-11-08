#include "Linklist.h"

CLinkedList::CLinkedList() :
m_ptNode(NULL)
{
}
 
CLinkedList::~CLinkedList()
{
	//[Delete & Reset - struct] -  ptNewNode
	TNode* ptTempNode = NULL; 
	while (m_ptNode != NULL)
	{
		ptTempNode = m_ptNode;
		m_ptNode = m_ptNode->ptNext;
		delete ptTempNode;
		ptTempNode = NULL;
	}
}

bool CLinkedList::Append(const char *pszAppendName)
{
	//Data checking
	if (pszAppendName == NULL || DuplicationCheck(pszAppendName)) return false;
	
	//[New - Struct] -  ptNewNode
	TNode* ptNewNode = new TNode();
	//[Ini - Struct] -  ptNewNode
	memset(ptNewNode, 0, sizeof(TNode));

	strncpy(ptNewNode->szName, pszAppendName, MAX_TEXT_LENGTH + 1);
	ptNewNode->szName[MAX_TEXT_LENGTH] = '\0';
	ptNewNode->ptNext = NULL;

	//Append new node
	if (m_ptNode == NULL)
	{
		m_ptNode = ptNewNode;
	}
	else
	{
		TNode* ptTempNode = m_ptNode;
		while (ptTempNode->ptNext != NULL ) 
		{
			ptTempNode = ptTempNode->ptNext;
		}
		ptTempNode->ptNext = ptNewNode;
	}

	return true;
}

bool CLinkedList::Delete(const char *pszDeleteName)
{
	//Data and List checking
	if (pszDeleteName == NULL || m_ptNode == NULL) return false;

	TNode* ptTempNode = m_ptNode; 
	TNode* ptPreNode = NULL;
	unsigned int uiCounter = 0 ;

	//Search and delete
	while(ptTempNode != NULL)
	{
		if (stricmp(pszDeleteName, ptTempNode->szName) == 0)
		{
			if (uiCounter == 0)
			{
				m_ptNode = ptTempNode->ptNext;
			}
			else
			{
				ptPreNode->ptNext = ptTempNode->ptNext;
			}

			delete ptTempNode;
			ptTempNode = NULL;
			return true;
		}

		ptPreNode = ptTempNode;
		ptTempNode = ptTempNode->ptNext;
		uiCounter++;
	}

	return false;
}

bool CLinkedList::Find(const char *pszSearchName) const
{	
	//Data and List checking
	if (pszSearchName == NULL || m_ptNode == NULL) return false;

	char szLowerSearchName[MAX_TEXT_LENGTH + 1] = "";
	strncpy(szLowerSearchName, pszSearchName, MAX_TEXT_LENGTH + 1);
	szLowerSearchName[MAX_TEXT_LENGTH] = '\0';
	ToLower(szLowerSearchName);

    bool bDataExist = false;
	const TNode* ptTempNode = m_ptNode; 

	//Find and display
	while (ptTempNode != NULL)
	{
		char szLowerNodeName[MAX_TEXT_LENGTH + 1] = "";
		strncpy(szLowerNodeName, ptTempNode->szName, MAX_TEXT_LENGTH + 1);
		szLowerNodeName[MAX_TEXT_LENGTH] = '\0';
		ToLower(szLowerNodeName);

		if (strstr(szLowerNodeName, szLowerSearchName) != NULL)
		{
			printf(ptTempNode->szName);
			printf("\n");
			bDataExist = true;
		}
		ptTempNode = ptTempNode->ptNext;
	}

	return bDataExist;
}

int CLinkedList::GetLength() const
{
	int iCounter = 0;

	const TNode* ptTempNode = m_ptNode; 
	while (ptTempNode != NULL)
	{
		iCounter++;
		ptTempNode = ptTempNode->ptNext;
	}
	return iCounter;
}

void CLinkedList::Sort()
{	
	//Length check
	int iLinkedListLength = CLinkedList::GetLength();
	if (iLinkedListLength == 0) return;

	int iCounter = 0;

	//[New - Struct] -  pptSortNodeArray
	TNode** pptSortNodeArray = new TNode* [iLinkedListLength];
	//[Ini - Struct] -  pptSortNodeArray
	memset(pptSortNodeArray, 0, sizeof(TNode*));

	TNode* ptTempNode = m_ptNode; 
	while (ptTempNode != NULL)
	{
		pptSortNodeArray[iCounter] = ptTempNode;
		ptTempNode = ptTempNode->ptNext;
		iCounter++;
	}
	ptTempNode = NULL;
	
	qsort(pptSortNodeArray, iLinkedListLength, sizeof(TNode*), Compare);

	for (int i = 0; i < iLinkedListLength; i++)
	{
		if (i == 0)
		{
			m_ptNode = pptSortNodeArray[i];
			m_ptNode->ptNext = NULL;
			ptTempNode = m_ptNode;
		}
		else
		{
			ptTempNode->ptNext = pptSortNodeArray[i];
			ptTempNode = ptTempNode->ptNext;
			ptTempNode->ptNext = NULL;
		}
	}
	ptTempNode = NULL;

	//[Delete & Reset - struct] -  pptSortNodeArray
	delete [] pptSortNodeArray;
	pptSortNodeArray = NULL;

	CLinkedList::Display();
}

void CLinkedList::Display() const
{
	printf("------------------------------\n");

	const TNode* ptTempNode = m_ptNode; 

	while (ptTempNode != NULL)
	{
		printf(ptTempNode->szName);
		printf("\n");
		ptTempNode = ptTempNode->ptNext;
	}
}

bool CLinkedList::DuplicationCheck(const char *pszSearchName) const
{	
	//Data and List checking
	if (pszSearchName == NULL || m_ptNode == NULL) return false;

	const TNode* ptTempNode = m_ptNode; 

	//Check each name
	while (ptTempNode != NULL)
	{
		if (stricmp(pszSearchName, ptTempNode->szName) == 0)
		{
			return true;
		}
		ptTempNode = ptTempNode->ptNext;
	}

	return false;
}

void ToLower(char *pszConvertedString)
{
	if (pszConvertedString == NULL) return;

	unsigned int uiStringLength = strlen(pszConvertedString);
	for (unsigned int i = 0; i < uiStringLength; i++)
	{
		pszConvertedString[i] = (char) tolower(pszConvertedString[i]);
	}
}

int Compare(const void* pvVar1, const void* pvVar2)
{
	TNode** pptFirstName = (TNode**) pvVar1;
	TNode** pptSecondName = (TNode**) pvVar2;
	return (strcmp((*pptFirstName)->szName, (*pptSecondName)->szName));
}
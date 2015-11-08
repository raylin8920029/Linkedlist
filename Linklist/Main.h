#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include "Linklist.h"
#include "Common.h"

using namespace std;


const unsigned int MAX_INPUT_LENGTH = 255;
const unsigned int MAX_CHOICE_LENGTH = 1;

class CTestClass
{
	// Constructor & Desctructor
public:
	static const int m_iCounter = 0;
};

void CleanCINStream();
bool GetInputAndCheckLen(char* pszInputText, const unsigned int uiMaxLength);
void AppendEmployee(CLinkedList& linkedlist);
void RemoveEmployee(CLinkedList& linkedlist);
void FindEmployee(const CLinkedList& linkedlist);

#endif // _MAIN_H_
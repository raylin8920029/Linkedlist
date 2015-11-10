#include "Main.h"

int main(void)
{	
	const char* const pszAuthorName = "Try";
	const char * pszTest1 = "1";
	char szTest[] = "123";
	char cTest = 'a';
	char * pszTest2 = &cTest;

	//*pszTest1 = '3';
	*pszTest2 = '3';
	printf("Provide by %s : \n", pszTest2);
	
	pszTest1 = szTest;
	//pszTest2 = szTest;
	printf("Provide by %s : \n", pszTest1);
	


	const std::string strProjectName = "LinkList";
	printf("Provide by %s : \n", pszAuthorName);
	printf("Project Name %s \n", strProjectName.c_str());
	printf("Test class counter is %i \n", CTestClass::m_iCounter);


	//int iNumA = 10;
	//int iNumB = 7;
	double dNumA = 11.12;
	double dNumB = 31.99;

	callWithMax(dNumA, dNumB);




	//Active cin exceptions.
	cin.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);

	CLinkedList Linklist;
	int iChoice = -1;
	
	for (;;)
	{
		//Show prompt
		printf("1. Add Employee\n");
		printf("2. Remove Employee\n");
		printf("3. Find Employee\n");
		printf("4. List All Employee\n");
		printf("5. Sort\n");
		printf("6. Exit\n");
		printf("Please input your choice \n");

		//Get input text
		char szInputText[MAX_INPUT_LENGTH + 1] = {0};
		if (GetInputAndCheckLen(szInputText, MAX_CHOICE_LENGTH) == false) continue;

		//Check format
		for (unsigned int i = 0; i < MAX_CHOICE_LENGTH; i++)
		{
			if (isdigit(szInputText[i]) == 0)
			{
				printf("[Warning] Choice is not integer.\n\n");
				continue;
			}
		}

		//Do corresponding operation.
		iChoice = atoi(szInputText);
		if (iChoice == 6) break;
		
		switch (iChoice) 
		{
			case 1 :
				AppendEmployee(Linklist);
				break;

			case 2 :
				RemoveEmployee(Linklist);
				break;

			case 3 :
				printf("------------------------------\n");
				FindEmployee(Linklist);
				break;

			case 4 :
				Linklist.Display();
				break;

			case 5 :
				Linklist.Sort();
				break;

			default:
				printf("[Warning] No this option\n");
		}
	}

	return EXIT_SUCCESS;
}


void CleanCINStream()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool GetInputAndCheckLen(char* pszInputText, const unsigned int uiMaxLength)
{
	try {
		cin.getline(pszInputText, MAX_INPUT_LENGTH);
	}
	catch (ios_base::failure& exc) {
		printf("[Warning] Input Error (exception: %s). Please try again.\n\n", exc.what());
		CleanCINStream();
		return false;
	}

	if (strlen(pszInputText) > uiMaxLength)
	{
		printf("[Warning] Input length is larger then %d characters. Please try again.\n\n", uiMaxLength);
		return false;
	}

	return true;
}

void AppendEmployee(CLinkedList& linkedlist)
{
	printf("Please input the name you want to Add (%d characters at most).\n", MAX_TEXT_LENGTH);

	char szInputText[MAX_INPUT_LENGTH + 1] = {0};
	if (GetInputAndCheckLen(szInputText, MAX_TEXT_LENGTH) == false) return;

	if (linkedlist.Append(szInputText) == false)
	{
		printf("[Warning] Input invalid data or duplicate name. Please try again.\n\n");
	}
}

void RemoveEmployee(CLinkedList& linkedlist)
{
	printf("Please input the name you want to delete (%d characters at most).\n", MAX_TEXT_LENGTH);

	char szInputText[MAX_INPUT_LENGTH + 1] = {0};
	if (GetInputAndCheckLen(szInputText, MAX_TEXT_LENGTH) == false) return;

	if (linkedlist.Delete(szInputText) == false)
	{
		printf("[Warning] Can't delete this name. Please try again.\n\n", szInputText);
	}
}


void FindEmployee(const CLinkedList& linkedlist)
{
	printf("Please input the name you want to search (%d characters at most).\n", MAX_TEXT_LENGTH);

	char szInputText[MAX_INPUT_LENGTH + 1] = {0};
	if (GetInputAndCheckLen(szInputText, MAX_TEXT_LENGTH) == false) return;

	if (linkedlist.Find(szInputText) == false)
	{
		printf("[Warning] Can't find \"%s\" related data!\n\n", szInputText);
	}
}
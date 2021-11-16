#include <iostream>

using namespace std;

class CDocument
{
public:
	void OnFileOpen()
	{
		cout << "dialog ..." << endl;
		cout << "check file status ..." << endl;
		cout<< "open file ..." <<endl;
		Serialize();
		cout << "close file ..." << endl;
		cout << "Update all views ..." << endl;
	}

	virtual void Serialize() {}
};

class CMyDoc: public CDocument
{
public:
	virtual void Serialize()
	{
		cout << "CMyDoc::Serialize()" << endl;
	}
};

int main()
{
	CMyDoc myDoc;
	myDoc.OnFileOpen();
}
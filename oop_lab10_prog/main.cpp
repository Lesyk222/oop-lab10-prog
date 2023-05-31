#include "CMultiSet.h"

using namespace std;

int main() {
	CMultiSet<int> obj;
	
	cin >> obj;
	cout << "Values in object: " << endl << obj;
	cout << "Count of certain element: " << obj.countOfCertainElement(2);
}
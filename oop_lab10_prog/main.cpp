#include "CMultiSet.h"
#include <map>
#include <unordered_set>
#include <stack>
#include <list>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

template <typename T>
struct reversion_wrapper { T& iterable; };

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse(T&& iterable) { return { iterable }; }

int main() {
	CMultiSet<int> obj;
	
	cin >> obj;
	cout << "Values in object: " << obj << endl;
	
	CMultiSet<int> obj2;

	cin >> obj2;
	cout << "Values in object 2: " << obj2 << endl;

	CMultiSet<int> sum;
	sum = obj + obj2;
	cout << "Sum multiset: " << sum;

	CMultiSet<int> difference;
	difference = obj - obj2;
	cout << "Difference multiset: " << difference;

	CMultiSet<int> intersection;
	intersection = obj / obj2;
	cout << "Intersection multiset: " << intersection;

	 //MULTIMAP
	multimap<int, string> objMap {
		{1, "Ivan"},
		{ 2, "Andriy" },
		{ 3, "Mykola" }
	};

	auto add = pair<int, string>(4, "Ira");
	objMap.insert(add);
	add = pair<int, string>(3, "Orest");
	objMap.insert(add);

	auto ptr = objMap.find(4);
	if (ptr != objMap.cend())
	{
		cout << ptr->second << endl;
	}
	else cout << "no such key" << endl;

	ptr = objMap.find(3);
	if (ptr != objMap.cend())
	{
		cout << ptr->second << endl;
	}
	else cout << "no such key" << endl;

	objMap.erase(2);
	objMap.erase(5);

	for (auto iter = objMap.begin(); iter != objMap.end(); ++iter)
	{
		cout << "Key: " << iter->first << "\tValue: " << iter->second << endl;
	}
	cout << endl;

	unordered_multiset<int> order {2, 5, 7, 3, 7, 8, 4};
	order.insert(34);
	cout << order.size() << endl;
	order.insert(3);
	cout << order.size() << endl;
	cout << *order.find(3) << endl;
	order.erase(3);
	cout << order.size() << endl;

	cout << "Values:";
	for (auto it = order.begin(); it != order.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<string> list1{"Value 1"};
	list<string> list2{"Value 2"};
	list<string> list3{"Value 3"};

	multimap<int, list<string>> myMultimap {
		{ 1, list1 },
		{ 2, list2 },
		{ 3, list3 }
	};

	cout << "Reverse values:";
	for (auto it = order.begin(); it != order.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for_each(order.begin(), order.end(), [](double c) {
		cout << c << " ";
		});


	cout << endl << endl;

		//stack
	stack<int> mystack; 
	for (size_t i = 0; i < 5; i++) {
		mystack.push(i);
	}
	cout << "\n" << "Stack:" << endl;
	for (size_t i = 0; !mystack.empty(); i++) {
		cout << mystack.top() << " ";
		mystack.pop();
	}
	cout << "\n" << "Stack is empty" << endl;


	cout << endl << endl << "Static array: ";
		//array
	array<int, 6> arr = {1, 2, 3, 4, 5, 6};
	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;





	cout << endl << endl << "For loop: ";
	list<int> myList = { 1, 2, 3, 4, 5, 6, 7 };

	for (auto it = myList.rbegin(); it!= myList.rend(); it++)
	{
		cout << *it << " ";
	}

	cout << endl << "for_each: ";
	for_each(myList.rbegin(), myList.rend(), [](int c) {
		cout << c << " ";
		});


	cout << endl << "Reverse: ";
	for (auto&& i : reverse(myList)) {
		cout << i << " ";
	}
}

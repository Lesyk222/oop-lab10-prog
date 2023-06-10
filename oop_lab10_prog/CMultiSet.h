#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class CMultiSet {
private:
    vector<T> values;

public:
    CMultiSet();
    CMultiSet(initializer_list<T> list);

    T getElement(int index) const noexcept;

    int countOfCertainElement(const T& value) const noexcept;

    int cardinality() const noexcept;
    T findMax() const;
    T findMin() const;

    void addElement(const T& temp);
    void deleteElement(const T& temp);

    void readArray();
    void printArray();
    void fillSet();

    CMultiSet<T> operator+(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T> operator-(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T> operator/(const CMultiSet<T>& other) const noexcept;
    CMultiSet<T>& operator=(const CMultiSet<T>& other);

    template <typename T>
    friend istream& operator>>(istream& input, CMultiSet<T>& other) noexcept {
        other.readArray();
        return input;
    }

    template <typename T>
    friend ostream& operator<<(ostream& output, const CMultiSet<T>& other) {
        if (other.values.empty()) {
            throw runtime_error("Empty multiset");
        }
        for (const T& value : other.values) {
            output << value << " ";
        }
        output << endl;
        return output;
    }
};

template<typename T>
CMultiSet<T>::CMultiSet() {}

template<typename T>
T CMultiSet<T>::getElement(int index) const noexcept {
    return values[index];
}

template<typename T>
int CMultiSet<T>::countOfCertainElement(const T& value) const noexcept {
    auto range = equal_range(values.begin(), values.end(), value);
    int count = distance(range.first, range.second);
    return count;
}

template<typename T>
int CMultiSet<T>::cardinality() const noexcept {
    return values.size();
}

template<typename T>
T CMultiSet<T>::findMax() const {
    if (values.empty()) {
        throw runtime_error("Empty multiset");
    }
    return *max_element(values.begin(), values.end());
}

template<typename T>
T CMultiSet<T>::findMin() const {
    if (values.empty()) {
        throw runtime_error("Empty multiset");
    }
    return *min_element(values.begin(), values.end());
}

template<typename T>
void CMultiSet<T>::addElement(const T& temp) {
    values.push_back(temp);
    sort(values.begin(), values.end());
}

template<typename T>
void CMultiSet<T>::deleteElement(const T& temp) {
    auto it = find(values.begin(), values.end(), temp);
    if (it == values.end()) {
        throw runtime_error("Element not found");
    }
    values.erase(it);
}

template<typename T>
void CMultiSet<T>::readArray() {
    int count;
    cout << "Enter count: ";
    if (!(cin >> count)) {
        throw runtime_error("Bad input");
    }
    for (int i = 0; i < count; i++) {
        T value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        if (!value) {
            throw runtime_error("Bad input");
        }
        addElement(value);
    }
}

template<typename T>
CMultiSet<T> CMultiSet<T>::operator+(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet;

    std::vector<T> result(values.size() + other.values.size());
    auto it = std::set_union(values.begin(), values.end(), other.values.begin(), other.values.end(), result.begin());
    result.resize(std::distance(result.begin(), it));

    for (const T& value : result) {
        multiSet.addElement(value);
    }

    return multiSet;
}


template<typename T>
CMultiSet<T> CMultiSet<T>::operator-(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet;
    std::set_difference(values.begin(), values.end(), other.values.begin(), other.values.end(),
        std::back_inserter(multiSet.values));
    return multiSet;
}


template<typename T>
CMultiSet<T> CMultiSet<T>::operator/(const CMultiSet<T>& other) const noexcept {
    CMultiSet<T> multiSet;
    std::set_intersection(values.begin(), values.end(), other.values.begin(), other.values.end(),
        std::inserter(multiSet.values, multiSet.values.begin()));
    return multiSet;
}


template<typename T>
CMultiSet<T>& CMultiSet<T>::operator=(const CMultiSet<T>& other) {
    if (this != &other) {
        values = other.values;
    }
    return *this;
}

template<typename T>
void CMultiSet<T>::printArray() {
    for (const T& value : values) {
        cout << value << " ";
    }
    cout << endl;
}

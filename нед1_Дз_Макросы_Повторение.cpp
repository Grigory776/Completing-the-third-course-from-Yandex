﻿// нед1_Дз_Макросы_Повторение.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "test_runner.h"

#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {

    ForwardIterator Max = first;
    bool fl = false;

    for (;first != last;first++) {

        if (pred(*first)) {

            if (*Max < *first) Max = first;
            fl = true;

        }
    }
    if (fl) return Max;
    else return last;
}

void TestUniqueMax() {
    auto IsEven = [](int x) {
        return x % 2 == 0;
    };

    const list<int> hill{ 2, 4, 8, 9, 6, 4, 2 };
    auto max_iterator = hill.begin();
    advance(max_iterator, 2);

    vector<int> numbers(10);
    iota(numbers.begin(), numbers.end(), 1);

    /*
      Мы не используем AssertEqual, потому что для итераторов
      отсутствует перегрузка оператора вывода в поток ostream.
      Разыменование здесь также недопустимо, так как оно может повлечь
      неопределенное поведение, если функция max_element_if, к примеру,
      вернула итератор, указывающий на конец контейнера.
    */
    Assert(
        max_element_if(numbers.begin(), numbers.end(), IsEven) == --numbers.end(),
        "Expect the last element"
    );
    Assert(
        max_element_if(hill.begin(), hill.end(), IsEven) == max_iterator,
        "Expect the maximal even number"
    );
}

void TestSeveralMax() {
    struct IsCapitalized {
        bool operator()(const string& s) {
            return !s.empty() && isupper(s.front());
        }
    };

    const forward_list<string> text{ "One", "two", "Three", "One", "Two",
      "Three", "one", "Two", "three" };
    auto max_iterator = text.begin();
    advance(max_iterator, 4);

    Assert(
        max_element_if(text.begin(), text.end(), IsCapitalized()) == max_iterator,
        "Expect the first \"Two\""
    );
}

void TestNoMax() {
    const vector<int> empty;
    const string str = "Non-empty string";

    auto AlwaysTrue = [](int) {
        return true;
    };
    Assert(
        max_element_if(empty.begin(), empty.end(), AlwaysTrue) == empty.end(),
        "Expect end for empty container"
    );

    auto AlwaysFalse = [](char) {
        return false;
    };
    Assert(
        max_element_if(str.begin(), str.end(), AlwaysFalse) == str.end(),
        "Expect end for AlwaysFalse predicate"
    );
}

int main() {
    /*TestRunner tr;
    tr.RunTest(TestUniqueMax, "TestUniqueMax");
    tr.RunTest(TestSeveralMax, "TestSeveralMax");
    tr.RunTest(TestNoMax, "TestNoMax");*/

    vector<int> t = { 1,3,5 };
    max_element_if(t.begin(), t.end(), [](int tmp) {
        return (tmp % 2 == 0);
        });

    return 0;
}
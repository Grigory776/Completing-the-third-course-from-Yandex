// профайлер+сложнось_алгоритмов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


/* ДЗ_1 */

//#include "student.h"
//#include "test_runner.h"
//#include"profile.h"
//
//#include <algorithm>
//
//using namespace std;
//
////Оптимизируйте эту функцию
//bool Compare(const Student& first,const Student& second) {
//    return first.Less(second);
//}
//
//void TestComparison() {
//    LOG_DURATION("t1");
//    Student newbie{
//      "Ivan", "Ivanov", {
//        {"c++", 1.0},
//        {"algorithms", 3.0}
//      },
//      2.0
//    };
//
//    Student cpp_expert{
//      "Petr", "Petrov", {
//        {"c++", 9.5},
//        {"algorithms", 6.0}
//      },
//      7.75
//    };
//
//    Student guru{
//      "Sidor", "Sidorov", {
//        {"c++", 10.0},
//        {"algorithms", 10.0}
//      },
//      10.0
//    };
//    ASSERT(Compare(guru, newbie));
//    ASSERT(Compare(guru, cpp_expert));
//    ASSERT(!Compare(newbie, cpp_expert));
//}
//
//void TestSorting() {
//    LOG_DURATION("t2");
//    vector<Student> students{
//      {"Sidor", "Sidorov", {{"maths", 2.}}, 2.},
//      {"Semen", "Semenov", {{"maths", 4.}}, 4.},
//      {"Ivan", "Ivanov", {{"maths", 5.}}, 5.},
//      {"Petr", "Petrov", {{"maths", 3.}}, 3.},
//      {"Alexander", "Alexandrov", {{"maths", 1.}}, 1.}
//    };
//    sort(students.begin(), students.end(), Compare);
//    ASSERT(is_sorted(students.begin(), students.end(),
//        [](Student first, Student second) {
//            return first.Less(second);
//        })
//    );
//}
//
//int main() {
//    LOG_DURATION("Total");
//    TestRunner tr;
//    RUN_TEST(tr, TestComparison);
//    RUN_TEST(tr, TestSorting);
//    return 0;
//}

/* ДЗ_2 */

#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>

#include "profile.h"

using namespace std;

class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string>& words) {
        int newWords = dict.size();
        for (const auto& word : words) {
           
                dict.insert(word);
            
        }
        return dict.size() - newWords;
    }

    const vector<string> KnownWords() {
        return { dict.begin(),dict.end() };
    }
};

int main() {
    

    Learner learner;
    string line;
    bool fl = false;
    while (getline(cin, line) && !fl) {
        LOG_DURATION("cycle 1");
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
        fl = true;
    }
    cout << "=== known words ===\n";
    {   LOG_DURATION("cycle 2");
        for (const auto& word : learner.KnownWords()) {

            cout << word << "\n";
        }
    }
    return 0;
}
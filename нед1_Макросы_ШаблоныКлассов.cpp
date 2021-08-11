// нед1_Макросы_ШаблоныКлассов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define My_Main int main() // Макросами можно заменть некоторые команды, в том числе функции с аргументами
//#define Finish return 0
//#define RUN_TEST(tr, func)  tr.RunTest(func,#func) // Избавление от дублированию с помощью макроса
//                                                    // оператор решетки возращает название функции типа стринг
//
//#include <iostream>
//
//#include "Фреймоворк.h";
//
//using namespace std;
//
//int Foo( int a, int b) {
//    return a + b + 1;
//}
//
//void TestFoo() {
//    AssertEqual(Foo(5, 2), 8, "t1");
//    AssertEqual(Foo(9, 5), 15, "t2");
//}
//
//My_Main
//{
//    TestRunner tr;
//    RUN_TEST(tr, TestFoo);
//   
//
//    Finish;
//}
//





/* ДЗ 1 */

//#include <string>
//#include <ostream>
//using namespace std;
//
//class Logger {
//public:
//    explicit Logger(ostream& output_stream) : os(output_stream) {
//    }
//
//    void SetLogLine(bool value) { log_line = value; }
//    void SetLogFile(bool value) { log_file = value; }
//
//    void Log(const string& message);
//
//    void SetFile(const string& filename) {
//        file = filename;
//    }
//
//    void SetLine(int line_number) {
//        line = line_number;
//    }
//
//private:
//    ostream& os;
//    bool log_line = false;
//    bool log_file = false;
//    string file;
//    int line;
//};
//
//void Logger::Log(const string& message) {
//    if (log_file && log_line) {
//        os << file << ':' << line << ' ';
//    }
//    else if (log_file) {
//        os << file << ' ';
//    }
//    else if (log_line) {
//        os << "Line " << line << ' ';
//    }
//    os << message << '\n';
//}
//
//#define LOG(logger, message) \
//  logger.SetFile(__FILE__);  \
//  logger.SetLine(__LINE__);  \
//  logger.Log(message);



/* ДЗ 2 */

//#include "test_runner.h"
//
//#include <ostream>
//using namespace std;
//
//// rewrite macro PRINT_VALUES to pass all tests;
//
//// original:
//// #define PRINT_VALUES(out, x, y) out << (x) << endl; out << (y) << endl
//
//// rewritten:
//#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl
//
//void testMacro() {
//    {
//        ostringstream output;
//        PRINT_VALUES(output, 5, "red belt");
//        ASSERT_EQUAL(output.str(), "5\nred belt\n");
//    }
//    {
//        ostringstream output;
//        if (false)
//            PRINT_VALUES(output, 5, "red belt");
//        ASSERT_EQUAL(output.str(), "");
//    }
//    {
//        ostringstream output;
//        if (false)
//            PRINT_VALUES(output, 5, "red belt");
//        else
//            PRINT_VALUES(output, 5, "yellow belt");
//
//        ASSERT_EQUAL(output.str(), "5\nyellow belt\n");
//    }
//    {
//        ostringstream output;
//        for (int i = 0; i < 5; ++i)
//            PRINT_VALUES(output, 5, "brown belt");
//
//        ASSERT_EQUAL(output.str(),
//            "5\nbrown belt\n5\nbrown belt\n5\nbrown belt\n5\nbrown belt\n5\nbrown belt\n"
//        );
//    }
//}
//
//int main() {
//    TestRunner tr;
//    RUN_TEST(tr, testMacro);
//}


/* ДЗ 3 */

//#include <string>
//#include <vector>
//using namespace std;
//
//#define UNIQ_ID f(__LINE__)
//
//#define f(a) g(a)
//
//#define g(a) _variable##a
//
//int main() {
//    int UNIQ_ID = 0;
//    string UNIQ_ID = "hello";
//    vector<string> UNIQ_ID = { "hello", "world" };
//    vector<int> UNIQ_ID = { 1, 2, 3, 4 };
//}

//#include <iostream>
//
//using namespace std;
//
//template <class T, class U>
//struct Pair{      //создание шаблона класса
//	T first;
//	U second;
//};
//
//int main() {
//	Pair<int, string> pr; // инстанцирование - создание класса конкретных типов из шаблона
//	pr.first = 1;
//	pr.second = "chill";
//
//	cout << pr.first << ' ' << pr.second << endl;
//
//	return 0;
//}


/* ДЗ_1(шаблоны классов) Таблица */

//#include "test_runner.h"
//
//using namespace std;
//
//// Реализуйте здесь шаблонный класс Table
//template <class T>
//class Table {
//public:
//    Table(size_t i, size_t j) : n(i), m(j) {
//        Matrix.resize(n);
//        for (size_t i = 0; i < n; i++)
//            Matrix[i].resize(m);
//        
//    }
//    
//
//    const vector<T>& operator[](size_t index) const
//    { return this->Matrix[index]; }
//
//     vector<T>& operator[] (size_t index)
//    { return this->Matrix[index]; }
//
//     void Resize(size_t row, size_t colm) {
//         n = row;
//         m = colm;
//         Matrix.resize(row);
//         for (size_t i = 0; i < row; i++)
//             Matrix[i].resize(colm);
//    }
//
//     pair<size_t, size_t> Size() const {
//         if (n == 0 || m == 0) return { 0,0 };
//         return { n,m };
//     }
//
//
//private:
//    size_t n = 0, m = 0;
//    vector<vector<T>> Matrix;
//};
//
//
//
//void TestTable() {
//    Table<int> t(1, 1);
//    ASSERT_EQUAL(t.Size().first, 1u);
//    ASSERT_EQUAL(t.Size().second, 1u);
//    t[0][0] = 42;
//    ASSERT_EQUAL(t[0][0], 42);
//    t.Resize(3, 4);
//    ASSERT_EQUAL(t.Size().first, 3u);
//    ASSERT_EQUAL(t.Size().second, 4u);
//}
//
//int main() {
//   /* TestRunner tr;
//    RUN_TEST(tr, TestTable);*/
//    
//    Table<string> tb(0, 5);
//    
//    cout << tb.Size().first << ' ' << tb.Size().second << endl;
//    
//    return 0;
//}


/* ДЗ_2(Дек на основе двух векторов) */

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//using namespace std;
//
//template<class T>
//class Deque {
//
//public:
//	Deque() : size(0) {}
//
//	bool Empty() const {
//		if (size == 0) return true;
//		return false;
//	}
//
//	size_t Size() const {
//		return size;
//	}
//
//	T& operator[](size_t index) {
//		if (index < VecFront.size()) return VecFront[VecFront.size() - index - 1];
//		else if (index >= VecFront.size() && index < size) return VecBack[index - VecFront.size()];
//		else  throw invalid_argument("Введен несуществующий индекс!!!"); 
//	}
//	const T& operator[](size_t index) const {
//		if (index < VecFront.size()) return VecFront[VecFront.size() - index - 1];
//		else if (index >= VecFront.size() && index < size) return VecBack[index - VecFront.size()];
//		else  throw invalid_argument("Введен несуществующий индекс!!!");
//	}
//	
//	T& At(size_t index) {
//		if (index < VecFront.size()) return VecFront[VecFront.size() - index - 1];
//		else if (index >= VecFront.size() && index < size) return VecBack[index - VecFront.size()];
//		else  throw out_of_range("Введен несуществующий индекс");
//	}
//	const T& At(size_t index) const {
//		if (index < VecFront.size()) return VecFront[VecFront.size() - index - 1];
//		else if (index >= VecFront.size() && index < size) return VecBack[index - VecFront.size()];
//		else  throw out_of_range("Введен несуществующий индекс");
//	}
//
//
//
//
//	T& Back()  {
//		if (!VecBack.empty()) {
//			
//			return *VecBack.rbegin();
//		}
//		else if (VecBack.empty() && !VecFront.empty()){
//			return *VecFront.begin();
//		}
//		else { throw out_of_range("iii"); }
//	}
//
//	const T& Back() const{
//		if (!VecBack.empty()) {
//			return *VecBack.rbegin();
//		}
//		else if (VecBack.empty() && !VecFront.empty()) {
//			return *VecFront.begin();
//		}
//		else { throw out_of_range("iii"); }
//	}
//
//	T& Front() {
//		if (!VecFront.empty()) {
//			return *VecFront.rbegin();
//		}
//		else if (VecFront.empty() && !VecBack.empty()) {
//			return *VecBack.begin();
//		}
//		else { throw out_of_range("iii"); }
//	}
//
//	const T& Front()  const {
//		if (!VecFront.empty()) {
//			return *VecFront.rbegin();
//		}
//		else if (VecFront.empty() && !VecBack.empty()) {
//			return *VecBack.begin();
//		}
//		else { throw out_of_range("iii"); }
//	}
//
//
//
//	void PushBack(T arg) {
//		VecBack.push_back(arg);
//		++size;
//	}
//
//	void PushFront(T arg) {
//		VecFront.push_back(arg);
//		++size;
//	}
//
//	
//
//private:
//	vector<T> VecBack; // konec
//	vector<T> VecFront;
//	size_t size;
//};
//
//int main() {
//	Deque<int> d1;
//	d1.PushBack(2);
//	d1.PushFront(1);
//	cout << d1.Back() << endl;
//	
//	return 0;
//}


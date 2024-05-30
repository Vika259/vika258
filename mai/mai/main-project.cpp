/*#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа #9. Git" << endl;
	cout << "Автор: Виктория Боровко" << endl;
	cout << "Группа: 23ИСиТ1д" << endl;
	return 0;
}
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <Windows.h>
using namespace std;

struct Precipitation {
    int day;
    int month;
    double amount;
    char characteristic[50];
    int duration() const {
        istringstream is(month);
        int m, d;
        if (!(is >> m>> d) || m < 0 || m > 12|| d < 0) {
            if ((d < 5 && d % 2 == 0 && d>30)) {
                throw invalid_argument("Invalid start time format");
            }
            if ((d < 5 && d % 2 != 0 && d>31)) {
                throw invalid_argument("Invalid start time format");
            }
            if (d = 5 && d > 28) {
                throw invalid_argument("Invalid start time format");
            }
            throw invalid_argument("Invalid start time format");
        }
       /*is.clear();
        istringstream iss(day);
        int d;
        if (!(iss >> d) || d < 0) {
            if ((d < 5 && d % 2 == 0 && d>30)) {
                throw invalid_argument("Invalid start time format");
            }
            if ((d < 5 && d % 2 != 0 && d>31)) {
                throw invalid_argument("Invalid start time format");
            }
            if (d = 5 && d > 28) {
                throw invalid_argument("Invalid start time format");
            }

        };*/ 
        is.clear();

    }
};

bool isRain(const char* str) {
    return strstr(str, "Дождь") != nullptr;
}

bool isLessThan15(const Precipitation& p) {
    return p.amount < 1.5;
}

bool compareByAmount(const Precipitation& a, const Precipitation& b) {
    return a.amount < b.amount;
}

bool compareByCharAndMonthAndDay(const Precipitation& a, const Precipitation& b) {
    int res = strcmp(a.characteristic, b.characteristic);
    if (res != 0) {
        return res < 0;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    return a.day < b.day;
}

void printPrecipitations(const std::vector<Precipitation>& v, const char* message) {
    std::cout << message << std::endl;
    for (const auto& p : v) {
        std::cout << "день " << p.day << " месяц " << p.month << " количество " << p.amount
            << " характеристика " << p.characteristic << std::endl;
    }
    std::cout << std::endl;
}
istream& operator>>(istream& is, Precipitation& talk) {
    is >> talk.day >> talk.month >> talk.amount >> talk.characteristic;
    return is;
}

ostream& operator<<(ostream& os, const Precipitation& talk) {
    os << talk.day << ' ' << talk.month << ' ' << talk.amount << ' ' << talk.characteristic << '\n';
    return os;
}
// Сортировка шейкером 
void Shaker_sort_1(vector<Precipitation>& talks) {
    int left = 0;
    int right = talks.size() - 1;
    bool isSorted = true;
    while (!isSorted) {
        for (int i = left; i < right; ++i) {
            if (compareByAmount(talks[i + 1], talks[i])) {
                std::swap(talks[i], talks[i + 1]);
                isSorted = false;
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (compareByAmount(talks[i - 1], talks[i])) {
                std::swap(talks[i], talks[i - 1]);
                isSorted = false;
            }
        }
        ++left;
    }
    printPrecipitations(talks, "Отсортированные по возрастанию количества осадков (шейкерная сортировка):");
}
void Shaker_sort_2(vector<Precipitation>& talks) {
    int left = 0;
    int right = talks.size() - 1;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = left; i < right; ++i) {
            if (compareByCharAndMonthAndDay(talks[i + 1], talks[i])) {
                std::swap(talks[i], talks[i + 1]);
                isSorted = false;
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (compareByCharAndMonthAndDay(talks[i - 1], talks[i])) {
                std::swap(talks[i], talks[i - 1]);
                isSorted = false;
            }
        }
        ++left;
    }
    printPrecipitations(talks, "Отсортированные по возрастанию характеристики, "
        "номера месяца и номера дня (шейкерная сортировка):");
}
void Quick_sort_2(vector<Precipitation>& talks) {
    // Быстрая сортировка 
    std::vector<Precipitation> quickSorted = talks;
    std::sort(quickSorted.begin(), quickSorted.end(), compareByCharAndMonthAndDay);
    printPrecipitations(quickSorted, "Отсортированные по возрастанию характеристики, "
        "номера месяца и номера дня (быстрая сортировка):");
}
void Quick_sort_1(vector<Precipitation>& talks) {
    // Быстрая сортировка 
    std::vector<Precipitation> quickSorted = talks;
    std::sort(quickSorted.begin(), quickSorted.end(), compareByAmount);
    printPrecipitations(quickSorted, "Отсортированные по  возрастанию количества осадков(быстрая сортировка):");
}
void vibor(vector<Precipitation>& talks) {
    int choice, choice2;
    cout << "каким методом сортировать:\n";
    cout << "1. Shaker sort\n";
    cout << "2. Quick sort\n";
    cin >> choice;
    cout << "Критерии сортировки:\n";
    cout << "1.По возрастанию количества осадков\n";
    cout << "2.По возрастанию характеристики, а в рамках одной характеристики по возрастанию номера месяца, а в рамках одного месяца по возрастанию номера дня\n";
    cin >> choice2;

    if (choice == 1 && choice2 == 1)
        Shaker_sort_1(talks);
    else if (choice == 1 && choice2 == 2)
        Shaker_sort_2(talks);
    else if (choice == 2 && choice2 == 1)
        Quick_sort_1(talks);
    else
        Quick_sort_2(talks);
}
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string f = "data.txt";
    fstream file;
    vector<Precipitation> talks;
    Precipitation talk;

    file.open(f, ios::in | ios::app);
    if (file.is_open()) {
        while (file >> talk)
        {
            talks.push_back(talk);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> talk;
            talks.push_back(talk);
        }
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл для записи " << endl;
        return 1;
    }

    file.open(f, ios::out | ios::trunc);
    if (file.is_open()) {

        vibor(talks);
       
        for (const Precipitation& talk : talks) {
            file << talk;
        }
        for (const Precipitation& talk : talks) {
            cout << talk;
        }
        file.close();
    }
    else {
        cerr << "Не удалось открыть файл для записи " << endl;
        return 1;
    }

    std::vector<Precipitation> rainyDays;
    for (const auto& p : talks) {
        if (isRain(p.characteristic)) {
            rainyDays.push_back(p);
        }
    }
    printPrecipitations(rainyDays, "Все дни, в которые шёл дождь:");

    std::vector<Precipitation> lessThan15Days;
    for (const auto& p : talks) {
        if (isLessThan15(p)) {
            lessThan15Days.push_back(p);
        }
    }
    printPrecipitations(lessThan15Days, "Все дни, в которые объём осадков был меньше 1,5:");

    return 0;
}
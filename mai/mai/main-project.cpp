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
#include <vector>
#include <algorithm>
#include <cstring>
#include<Windows.h>

struct Precipitation {
    int day;
    int month;
    double amount;
    char characteristic[50];
};

bool isRain(const char* str) {
    return strstr(str, "дождь") != nullptr;
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

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<Precipitation> precipitations = {
        {1, 1, 0.5, "мокрый снег"},
        {2, 1, 1.0, "дождь"},
        {3, 1, 1.5, "снег"},
        {4, 1, 2.0, "дождь"},
        {5, 1, 2.5, "снег"},
        {6, 1, 3.0, "дождь"},
    };

    std::vector<Precipitation> rainyDays;
    for (const auto& p : precipitations) {
        if (isRain(p.characteristic)) {
            rainyDays.push_back(p);
        }
    }
    printPrecipitations(rainyDays, "Все дни, в которые шёл дождь:");

    std::vector<Precipitation> lessThan15Days;
    for (const auto& p : precipitations) {
        if (isLessThan15(p)) {
            lessThan15Days.push_back(p);
        }
    }
    printPrecipitations(lessThan15Days, "Все дни, в которые объём осадков был меньше 1,5:");

    // Сортировка шейкером
    std::vector<Precipitation> shakerSorted = precipitations;
    int left = 0;
    int right = shakerSorted.size() - 1;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = left; i < right; ++i) {
            if (compareByAmount(shakerSorted[i + 1], shakerSorted[i])) {
                std::swap(shakerSorted[i], shakerSorted[i + 1]);
                isSorted = false;
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (compareByAmount(shakerSorted[i - 1], shakerSorted[i])) {
                std::swap(shakerSorted[i], shakerSorted[i - 1]);
                isSorted = false;
            }
        }
        ++left;
    }
    printPrecipitations(shakerSorted, "Отсортированные по возрастанию количества осадков (шейкерная сортировка):");

    // Быстрая сортировка
    std::vector<Precipitation> quickSorted = precipitations;
    std::sort(quickSorted.begin(), quickSorted.end(), compareByCharAndMonthAndDay);
    printPrecipitations(quickSorted, "Отсортированные по возрастанию характеристики, "
        "номера месяца и номера дня (быстрая сортировка):");

    return 0;
}
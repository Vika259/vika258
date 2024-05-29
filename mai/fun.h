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


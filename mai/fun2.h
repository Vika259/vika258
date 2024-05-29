void vibor(vector<Talk>& talks) {
    int choice, choice2;
    cout << "каким методом сортировать:\n";
    cout << "1. Heap sort\n";
    cout << "2. Merge sort\n";
    cin >> choice;
    cout << "Критерии сортировки:\n";
    cout << "1.По убыванию длительности доклада\n";
    cout << "2.По возрастанию фамилии автора доклада, а в рамках одного автора по возрастанию темы доклада\n";
    cin >> choice2;

    if (choice == 1 && choice2 == 1)
        heap_sort_duration(talks);
    else if (choice == 1 && choice2 == 2)
        heap_sort_last_name(talks);
    else if (choice == 2 && choice2 == 1)
        merge_sort_duration(talks);
    else
        merge_sort_last_name(talks);

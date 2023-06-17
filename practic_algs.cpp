#include "Headers.h"



class AlgorithmPractice {
private:
    std::wstring algorithmName;
    std::wstring algorithmCode;

public:
    AlgorithmPractice(const std::wstring& name, const std::wstring& code)
        : algorithmName(name), algorithmCode(code) {}

    void displayCode() const {
        CLS;
        std::wcout << L"Algorithm: " << algorithmName << std::endl;
        std::wcout << L"Code:\n" << algorithmCode << std::endl;
    }

    void displayTimeComplexity() const {
        CLS;
        std::wcout << L"Algorithm: " << algorithmName << std::endl;
        std::wcout << L"Time Complexity: " << timeComplexity << std::endl;
    }

    void sortList() const {
        CLS;
        std::vector<int> unsortedList = { 5, 2, 8, 1, 9 };
        std::wcout << "Unsorted List: ";
        for (const auto& num : unsortedList) {
            std::wcout << num << " ";
        }
        std::wcout << std::endl;

        if (algorithmName == L"Bubble Sort") {
            bubbleSort(unsortedList);
            std::wcout << "Sorted List (Bubble Sort): ";
            for (const auto& num : unsortedList) {
                std::wcout << num << " ";
            }
            std::wcout << std::endl;
        }
        else if (algorithmName == L"Quick Sort") {
            quickSort(unsortedList, 0, unsortedList.size() - 1);
            std::wcout << "Sorted List (Quick Sort): ";
            for (const auto& num : unsortedList) {
                std::wcout << num << " ";
            }
            std::wcout << std::endl;
        }
        else {
            mergeSort(unsortedList, 0, unsortedList.size() - 1);
            std::wcout << "Sorted List (mergeSort): ";
            for (const auto& num : unsortedList) {
                std::wcout << num << " ";
            }
            std::wcout << std::endl;
        }
    }

private:
    void bubbleSort(std::vector<int>& list) const {
        int n = list.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (list[j] > list[j + 1]) {
                    std::swap(list[j], list[j + 1]);
                }
            }
        }
    }

    int partition(std::vector<int>& list, int low, int high) const {
        int pivot = list[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (list[j] < pivot) {
                i++;
                std::swap(list[i], list[j]);
            }
        }

        std::swap(list[i + 1], list[high]);
        return (i + 1);
    }

    void quickSort(std::vector<int>& list, int low, int high) const {
        if (low < high) {
            int pi = partition(list, low, high);
            quickSort(list, low, pi - 1);
            quickSort(list, pi + 1, high);
        }
    }


    void merge(std::vector<int>& list, int left, int mid, int right) const {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        L[i] = list[left + i];
       for (int j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                list[k] = L[i];
                i++;
            } else {
                list[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            list[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            list[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(std::vector<int>& list, int left, int right) const {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(list, left, mid);
            mergeSort(list, mid + 1, right);
            merge(list, left, mid, right);
        }
    }
};

int Choice_pr() {
    CLS;
    // Creating an instance of AlgorithmPractice for Bubble Sort
    AlgorithmPractice bubbleSort(L"Bubble Sort",
        LR"(
void bubbleSort(std::vector<int>& list) const {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}
)");
    // Creating an instance of AlgorithmPractice for Quick Sort
    AlgorithmPractice quickSort(L"Quick Sort",
        LR"(
int partition(std::vector<int>& list, int low, int high) const {
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& list, int low, int high) const {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}
)");
    // Creating an instance of AlgorithmPractice for MergeSort
    AlgorithmPractice mergeSort(L"MergeSort",
        LR"(
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
)");




    int cho = 0;
    do {
        CLS;
        std::wcout << L"                               ---------------------------------------------------------------------"<<std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    WELCOME TO Практическая часть                                  |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    1 - Kод пузырьковой сортировки                                 |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;        
        std::wcout << L"                               |    2 - Тестирование алгоритма пузырьковой сортировки              |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;        
        std::wcout << L"                               |    3 - Kод  быстрой сортировки                                    |"<< std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    4 - Тестирование алгоритма быстрой сортировки                  |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    5 - Код алгоритма сортировки слиянием                          |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    6 - Тестирование алгоритма сортировки слиянием                 |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    ESC - Выход в главное меню                                     |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               ---------------------------------------------------------------------"<<std::endl;                     


        cho = _getch();
        switch (cho) {
            case '1':bubbleSort.displayCode();break;
            case '2': bubbleSort.sortList(); break;
            case '3': quickSort.displayCode(); break;
            case '4': quickSort.sortList(); break;
            case '5': mergeSort.displayCode(); break;
            case '6': mergeSort.sortList(); break;
        }
        if (cho != 27)
            PAUSE;
    } while (cho != 27); // Пока не нажата клавиша Esc

    return 0;
}
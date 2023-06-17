#include "Headers.h"



class Algorithm {
private:
    std::wstring name;
    std::wstring timeComplexity;
    std::wstring spaceComplexity;
    std::wstring algorithmDescription;
    int performanceRating;

public:
    // Constructor
    Algorithm(const std::wstring& n, const std::wstring& tc, const std::wstring& sc,
        const std::wstring& desc, int rating) : name(n), timeComplexity(tc),
        spaceComplexity(sc), algorithmDescription(desc),
        performanceRating(rating) {}


    
    // Method to display algorithm details

    void displayAlgorithm() const 
    {   
        _setmode(_fileno(stdout), _O_U16TEXT);
	    _setmode(_fileno(stdin), _O_U16TEXT);

	    SetConsoleCP(1200);
        CLS;
        std::wcout << L"|  Algorithm: " << name.c_str() << std::endl;
        std::wcout << L"Time Complexity: " << timeComplexity.c_str() << std::endl;
        std::wcout << L"Space Complexity: " << spaceComplexity.c_str() <<  std::endl;
        std::wcout << L"Algorithm Description: " << algorithmDescription.c_str() <<  std::endl;
        std::wcout << L"Performance Rating (1-10): " << performanceRating <<   "\n"<< std::endl;
    }
};

int Choice_teor() {
    // Creating an instance of the Algorithm class
    Algorithm bubble_sort(
        L"Пузырьковая сортировка\n",
        L"В худшем и среднем случаях Пузырьковая сортировка имеет время выполнения O(n^2), где n - количество элементов в массиве. Это делает его неэффективным для сортировки больших массивов.\n",
        L"Пузырьковая сортировка выполняется на месте, то есть не требует дополнительной памяти за исключением нескольких переменных. Его пространственная сложность составляет O(1)\n",
        L"Пузырьковая сортировка сравнивает пары соседних элементов и, если они находятся в неправильном порядке, меняет их местами. Этот процесс повторяется до тех пор, пока массив не будет полностью отсортирован.\n",
        3);

    Algorithm quick_sort(
        L"Быстрая сортировка",
        L"В среднем, Быстрая сортировка имеет время выполнения O(n log n). В худшем случае (когда выбирается плохой опорный элемент), время выполнения может составлять O(n^2). Однако, благодаря стратегии выбора опорного элемента и разделению массива на две части, Quick Sort в большинстве случаев демонстрирует хорошую производительность.",
        L"Быстрая сортировка требует O(log n) дополнительной памяти для рекурсивных вызовов стека. В худшем случае может потребоваться O(n) дополнительной памяти, если используется неравномерное разделение.",
        L"Быстрая сортировка использует стратегию 'разделяй и властвуй'. Он выбирает опорный элемент из массива и перемещает все элементы, меньшие опорного, влево, а все элементы, большие опорного, вправо. Затем процесс рекурсивно повторяется для двух подмассивов слева и справа от опорного элемента.",
        8);
    
    Algorithm merge_sort(
        L"Сортировка слиянием",
        L"Сортировка слиянием имеет время выполнения O(n log n) в худшем, среднем и лучшем случаях. Он гарантирует стабильное время выполнения независимо от расположения элементов в массиве.",
        L"Сортировка слиянием требует O(n) дополнительной памяти для временного массива, используемого при слиянии подмассивов. Это делает его несколько менее эффективным по использованию памяти по сравнению с Quick Sort.",
        L"Сортировка слиянием также использует стратегию 'разделяй и властвуй'. Он разделяет массив пополам, рекурсивно сортирует каждую половину и затем сливает их в один отсортированный массив.",
        9);
    
    int cho = 0;
    do {
        CLS;
        std::wcout << L"                               ---------------------------------------------------------------------"<<std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    WELCOME TO Теоретическая часть                                 |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    1 - Пузырьковая сортировка                                     |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;       
        std::wcout << L"                               |    2 - Быстрая сортировка                                         |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               |    3 - Сортировка слиянием                                        |"<< std::endl;   
        std::wcout << L"                               |                                                                   |" << std::endl;       
        std::wcout << L"                               |    ESC - Выход в главное меню                                     |" << std::endl;
        std::wcout << L"                               |                                                                   |" << std::endl;
        std::wcout << L"                               ---------------------------------------------------------------------"<<std::endl;                     


        cho = _getch();
        switch (cho) {
            case '1': bubble_sort.displayAlgorithm(); break;
            case '2': quick_sort.displayAlgorithm(); break;
            case '3': merge_sort.displayAlgorithm(); break;
        }

        if (cho != 27)
            PAUSE;
    } while (cho != 27); // Пока не нажата клавиша Esc
    
    

    return 0;
}
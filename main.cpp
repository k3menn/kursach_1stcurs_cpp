#include "Headers.h"



// Main function
int main() {
    
    _setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	SetConsoleCP(1200);
    unsigned char ch = 0;
    do {
        CLS;
        std::wcout << L"                               --------------------------------------" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |      App made by kemen <3          |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |      WELCOME TO MENU:              |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |      1 - Теория об алгоритмах      |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;        
        std::wcout << L"                               |      2 - Практическая часть        |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |                                    |" << std::endl;
        std::wcout << L"                               |      ESC - Выход из программы      |" << std::endl;
        std::wcout << L"                               --------------------------------------" << std::endl;



        ch = _getch();
        switch (ch) {
            case '1': Choice_teor(); break;

            case '2': Choice_pr(); break;
        }
        

    } while (ch != 27); // Пока не нажата клавиша Esc

    PAUSE;
    return 0;
}
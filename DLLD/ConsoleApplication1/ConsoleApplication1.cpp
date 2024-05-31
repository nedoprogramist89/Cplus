#include <iostream>
#include <Windows.h>
#include <string>

typedef bool(*FindCharsFunc)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите строку: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "Введите символы для поиска: ";
    std::string chars;
    std::getline(std::cin, chars);

    HMODULE lib = LoadLibrary(L"DLLD.dll");
    if (!lib) {
        std::cerr << "Ошибка загрузки библиотеки" << std::endl;
        return 1;
    }

    FindCharsFunc proc = reinterpret_cast<FindCharsFunc>(GetProcAddress(lib, "FindChars"));
    if (!proc) {
        std::cerr << "Ошибка" << std::endl;
        FreeLibrary(lib);
        return 1;
    }
    bool result = proc(str.c_str(), chars.c_str());
    std::cout << "Символы найдены: " << (result ? "true" : "false") << std::endl;

    return 0;
}

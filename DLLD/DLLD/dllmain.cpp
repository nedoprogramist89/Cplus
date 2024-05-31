#include <cstring>

extern "C" __declspec(dllexport) bool FindChars(const char* str, const char* chars) {
    for (const char* p = chars; *p; ++p) {
        if (!strchr(str, *p)) {
            return false;
        }
    }
    return true;
}
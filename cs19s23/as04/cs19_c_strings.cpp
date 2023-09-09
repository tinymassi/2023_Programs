#include "cs19_c_strings.h"

namespace cs19 {

unsigned atoi(const char* str){  // DONE
    unsigned int num = 0;
    for (; *str; ++str){
        if (*str >= 48 && *str <= 57){
            num = num * 10 + (*str - 48);
        }
    }
    return num;
}

const char *strchr(const char *haystack, const char needle){  // DONE
    for (; *haystack; ++haystack){
        if (*haystack == needle){
            return haystack;
        }
    }
    return nullptr;
}

int strcmp(const char *str1, const char *str2){  // DONE
    if (strlen(str1) >= strlen(str2)){
        for (; *str1; ++str1, ++str2){
            int num = *str1 - *str2;
            if (num != 0){
                return num;
            }
        }
    } else {
        for (; *str2; ++str2, ++str1){
            int num = *str1 - *str2;
            if (num != 0){
                return num;
            }
        }
    }
    return 0;
}

std::size_t strlen(const char *str){  // DONE
    std::size_t size = 0;
    for (; *str; ++str){
        if (*str){
            size++;
        }
    }
    return size;
}

const char *strstr(const char *haystack, const char *needle){  // DONE
    if (strlen(haystack) < strlen(needle)){
        return nullptr;
    }
    if (strlen(needle) == 0){
        return haystack;
    }

    int needle_size = strlen(needle);
    int check = 0;
    bool match = true;
    const char* ndl_temp = needle;
    const char* hstck_temp1;
    const char* hstck_temp2;

    for (; *haystack; ++haystack){
        hstck_temp2 = haystack;
        for (; *ndl_temp && *hstck_temp2; ++ndl_temp, ++hstck_temp2){
            if (*haystack == '\0' && *ndl_temp != '\0'){
                match = false;
            }
            if (*hstck_temp2 != *ndl_temp || !match){
                break;
            }
            if (check == 0){
                hstck_temp1 = haystack;
            }
            check++;
            if (check == needle_size){
                return hstck_temp1;
            }
        }
        check = 0;
        ndl_temp = needle;
    }

    return nullptr;
}

const char *strpbrk(const char *haystack, const char *char_list){  // DONE
        const char* temp = char_list;
        for (; *haystack; ++haystack){
            for (; *temp; ++temp){
                if (*haystack == *temp){
                    return haystack;
                }
            }
            temp = char_list;
        }
    return nullptr;
}

const char *strrchr(const char *haystack, const char needle){  // DONE
    const char* temp;
    bool check = false;
    if (strlen(haystack) == 0){
        return nullptr;
    }
    for (; *haystack; ++haystack){
        if (*haystack == needle){
            temp = haystack;
            check = true;
        }
    }
    if (*haystack == 0 && check){
        return temp;
    }
    return nullptr;
}

void strzip(const char *str1, const char *str2, char *output){  // DONE
    int a = 0;
    int b = 0;
    int c = 0;
    int j = 0;
    int k = 0;

    while (str1[k] != '\0' && str2[j] != '\0'){
        output[a++] = str1[b++];
        output[a++] = str2[c++];
        k++;
        j++;
    }
    while (str1[k] == '\0' && str2[j] != '\0'){
        output[a++] = str2[c++];
        j++;
    }
    while (str2[j] == '\0' && str1[k] != '\0'){
        output[a++] = str1[b++];
        k++;
    }
    output[a++] = '\0';
}

char *str_rot13(char *str){  // DONE
    for (unsigned int i = 0; i < strlen(str); ++i){
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            if ((str[i] >= 'N' && str[i] <= 'Z')  || (str[i] >= 'n' && str[i] <= 'z')){
                str[i] = str[i] - 13;
            } else {
                str[i] = str[i] + 13;
            }
        }
    }
    return str;
}

char *strrev(char *str){  // DONE
    int str_size = strlen(str);
    if (str_size == 1){
        return str;
    }
    char* ptr = &str[str_size - 1];
    char* original_str = str;
    char temp;

    for (int i = 0; i < str_size/2; i++, --ptr, ++str){
        temp = *str;
        *str = *ptr;
        *ptr = temp;
    }

    return original_str;
}

}  // namespace cs19
#include <iostream>
using namespace std;

int main() {
    char str[] = "asdf333";
    int max = 0;

    int len = 0;
    while (str[len] != '\0')
        len++;

    for (int i = len - 1; i >= 1; i--) {
        // generate substrings of len-1 while substrings length > 1
        for (int j = 0; j <= len - i; j++) {
            int tempMax = 0;
            int a = j, b = i;  // set a -> beg of substring, b -> end of substring
            while (str[a] == str[b]) {
                tempMax++;
                if (a - b <= 1) {
                    if (tempMax > max)
                        max = tempMax;
                }
                a++;
                b--;
            }
        }
    }
    // for (int i = 0; i < len - 2; i++) {
    //     int i2 = i;
    //     tempMax = 0;
    //     for (int j = len - 1; j >= i + 1; j--) {
    //         int j2 = j;
    //         while (str[i2] == str[j2]) {
    //             tempMax++;
    //             if (i2 - j2 <= 2) {
    //                 if (max < tempMax)
    //                     max = tempMax;
    //             }
    //             i2++;
    //             j2--;
    //         }
    //     }
    // }

    cout << "Largest palindrome of length " << max;

    return 0;
}
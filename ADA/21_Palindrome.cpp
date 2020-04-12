#include <iostream>
using namespace std;

int main() {
    char str[] = "abcdRACECAR";
    int max = 0;
    int tempMax = 0;

    int len = 0;
    while (str[len] != '\0')
        len++;

    for (int i = 0; i < len - 1; i++) {
        int k = i;
        tempMax = 0;
        for (int j = len - 1; j >= i + 1; j--) {
            if (str[k] == str[j]) {
                tempMax++;
                if (k == j - 1) {
                    if (max < tempMax)
                        max = tempMax;
                }
                k++;
            }
        }
    }

    cout << "Largest palindrome of length " << max;

    return 0;
}
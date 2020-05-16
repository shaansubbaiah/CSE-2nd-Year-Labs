#include <iostream>
using namespace std;

static int total_nodes;

void printSubset(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i];
    }
    cout << endl;
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    total_nodes++;

    if (target_sum == sum) {
        printSubset(t, t_size);

        if (ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum) {
            subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;

    } else {
        if (ite < s_size && sum + s[ite] <= target_sum) {
            for (int i = ite; i < s_size; i++) {
                t[t_size] = s[i];

                if (sum + s[i] <= target_sum) {
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}
void bsort(int s[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int *tuplet_vector = (int *)malloc(size * sizeof(int));

    int total = 0;
    int i;
    bsort(s, size);

    for (int i = 0; i < size; i++) {
        total += s[i];
    }

    if (s[0] <= target_sum && total >= target_sum) {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }

    free(tuplet_vector);
}

int main() {
    int i, n, sets[10], target;

    cout << "Enter number of elements in array";
    cin >> n;

    cout << "Enter elements of sets";
    for (i = 0; i < n; i++)
        cin >> sets[i];

    cout << "Enter sum";
    cin >> target;

    generateSubsets(sets, n, target);
}

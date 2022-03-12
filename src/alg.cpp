// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int itog = 0, tmp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = (size - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }

    bool flag = false;
    int l = 0;
    int r = size--;
    int mid;

    while ((l < r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr[mid] < value) {
            l = mid + 1;
        }
        if (arr[mid] > value) {
            r = mid - 1;
        }
        if (arr[mid] == value) {
            for (int i = mid + 1; i <= r; ++i) {
                if (arr[i] == value) {
                    itog++;
                } else {
                    break;
                }
            }
            for (int i = mid; i >= l; --i) {
                if (arr[i] == value) {
                    itog++;
                } else {
                    break;
                }
            }
            flag = true;
        }
    }
    return itog;
}

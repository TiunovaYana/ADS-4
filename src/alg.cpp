// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
      int kolvo = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                kolvo++;
            }
        }
    }
    return kolvo;
}
int countPairs2(int *arr, int len, int value) {
    int kolvo = 0;
    int end2 = len - 1;
    for (int i = len; i > 0; i--) {
        if (arr[end2] > value) {
            end2--;
        }
    }
    for (int begin2 = 0; begin2 < end2; begin2++) {
        for (int j = end2; j > begin2; j--) {
            if (arr[begin2] + arr[j] == value) {
                kolvo++;
            }
        }
        if (arr[begin2] != arr[begin2 + 1]) {
            end2--;
        }
    }
    return kolvo;
}
int countPairs3(int *arr, int len, int value) {
    int kolvo = 0;
    int middle = 0;
    int begin3, end3;
    for (int i = 0; i < len; i++) {
        begin3 = i + 1;
        end3 = len;
        while (begin3 < end3) {
            middle = (begin3 + end3) / 2;
            if (arr[middle] < (value - arr[i])) {
                begin3 = ++middle;
            } else {
                end3 = middle;
            }
        }
        while (arr[begin3] == (value - arr[i])) {
            kolvo++;
            begin3++;
        }
    }
    return kolvo;
}

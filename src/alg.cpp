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
    int end = len - 1;
    for (int i = len; i > 0; i--) {
        if (arr[end] > value) {
            end--;
        }
    }
    for (int begin = 0; begin < end; begin++) {
        for (int j = end; j > begin; j--) {
            if (arr[begin] + arr[j] == value) {
                kolvo++;
            }
        }
        if (arr[begin] != arr[begin + 1]) {
            end--;
        }
    }
    return kolvo;
}
int countPairs3(int *arr, int len, int value) {
    int kolvo = 0;
    int middle = 0, 
    int begin, end;
    for (int i = 0; i < len; i++) {
        begin = i + 1;
        end = len;
        while (begin < end) {
            middle = (begin + end) / 2;
            if (arr[middle] < (value - arr[i])) {
                begin = ++middle;
            } else {
                end = middle;
            }
        }
        while (arr[begin] == (value - arr[i])) {
            kolvo++;
            begin++;
        }
    }
    return kolvo;
}

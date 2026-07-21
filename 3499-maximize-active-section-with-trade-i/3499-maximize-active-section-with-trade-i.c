int maxActiveSectionsAfterTrade(char* s) {
    int n = strlen(s);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt1++;
    }

    int* zeroBlocks = (int*)malloc(n * sizeof(int));
    int m = 0;
    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && s[i] == s[start]) {
            i++;
        }
        if (s[start] == '0') {
            zeroBlocks[m++] = i - start;
        }
    }

    if (m < 2) {
        free(zeroBlocks);
        return cnt1;
    }

    int bestGain = 0;  // Optimal Increment
    for (int j = 0; j < m - 1; j++) {
        int gain = zeroBlocks[j] + zeroBlocks[j + 1];
        if (gain > bestGain) {
            bestGain = gain;
        }
    }

    free(zeroBlocks);
    return cnt1 + bestGain;
}
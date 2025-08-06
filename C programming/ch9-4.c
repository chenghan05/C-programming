//重要必學
#include <stdio.h>

void read_word(int counts[]) {
    char c;
    printf("Enter word: ");
    while ((c = getchar()) != '\n') {
        counts[c-'a']++;
    }
}

_Bool equal_array(int counts1[26], int counts2[26]) {
    for (int i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i])
            return 0;
    }
    return 1;
}

int main() {
    int counts[26] = {0};
    int counts2[26] = {0};

    read_word(counts);
    read_word(counts2);

    if (equal_array(counts, counts2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}


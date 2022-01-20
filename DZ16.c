#include <stdio.h>
#include <stdlib.h>

//=============== Task 1 ================//

char* ceasar (char* arr, int key, int flag) {
    if (arr == NULL) return NULL;
    const int length = strlen(arr);
    if (length == 0) return NULL;
    char* answ = (char*) malloc(sizeof(char) + length);
    for (int i = 0; i < length; ++i) {
        answ[i] = arr[i] + ((flag) ? (char) key : (char) -key);
    }
    answ[length] = 0;
    return answ;
}

//=============== Task 2 ================//

char* permutation(char* arr, int key, int flag) {
    int l = strlen(arr);
    if (l == 0) return NULL;
    const int len = key * (1 + ((l - 1) / key));
    char* answ = (char*) malloc(sizeof(char) + len);
    if (flag == 0) key = len / key;
    int cur = 0;
    for (int i = 0; i < key; ++i) {
        for (int j = i; j < len; j += key) {
            answ[cur++] = (*(arr + j)) ? *(arr + j) : (char) rand() % 255;
        }
    }
    answ[len] = 0;
    return answ;
}
int main()
{
    char* origMes = "Somesupersecretmessage";
    printf("origin - %s\n", origMes);
    char* encrypt = ceasar(origMes, 10, 1);
    printf("encrypt - %s\n", encrypt);
    char* decoding = ceasar(encrypt, 10, 0);
    printf("decoding - %s\n", decoding);

    printf("\n");

    char* origMes2 = "Thesecondsupermegasecretmessage";
    printf("origin - %s\n", origMes2);
    char* permut_encrypt = permutation(origMes2, 5, 1);
    printf("permut_encrypt - %s\n", permut_encrypt);
    char* permut_decoding = permutation(permut_encrypt, 5, 0);
    printf("permut_decoding - %s\n", permut_decoding);

    return 0;
}

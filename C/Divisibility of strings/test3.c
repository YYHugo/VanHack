#include <stdio.h>

int checkSubstringInString(char* s, int lenS, char* t, int lenT) { 
    int tInS = lenS/lenT;

    printf("s = %s\t", s);
    printf("t = %s\n", t);

    // Check if in every sizeof(T)-string contained in S is equals to T, return -1 if not
    for (int i=0; i < tInS; i++) {
        for (int j=0; j < lenT; j++) {
            if (s[lenT*i + j] != t[j]) {
                printf("s[%d] is '%c' whereas t[%d] is '%c'\n", lenT*i + j, s[lenT*i + j], j, t[j]);
                return -1;
            }
        }
    }

    // return tInS;
    return lenT;
}

int findSmallestDivisor(char* s, char* t) {
    //get the size of each string (exclude the last char '\r')
    int lenT = strlen(t);
    int lenS = strlen(s);

    // If division is not met or if any of them is null, stop
    if (lenS%lenT != 0 || s == NULL || t == NULL)
        return -1;
    // Check if there are K occurences in of T in S
    if ( checkSubstringInString(s, lenS, t, lenT) < 1)
        return -1;
    // Then check inside T what is the least substring 'p' that appears inside 't'
    // We know that inside T has at least 1 repetition (string T itself)
    // And we would like to find a substring P that fits k-times in string T
    int lenP = 0;
    char* p = t;
    do {
        lenP++;
    }while(checkSubstringInString(t, lenT, p, lenP) < 0);
    
    return lenP;
}

int findSmallestDivisor(char* s, char* t) {
    //get the size of each string (exclude the last char '\r')
    int lenT = strlen(t);
    int lenS = strlen(s);

    // If:
    // S is smaller than T
    // division is not met or
    // any of them is null, stop
    if (lenS < lenT || lenS%lenT != 0 || s == NULL || t == NULL)
        return -1;
    // Check if there are K occurences in of T in S
    if ( checkSubstringInString(s, lenS, t, lenT) < 1)
        return -1;
    // Then check inside T what is the least substring 'p' that appears inside 't'
    // We know that inside T has at least 1 repetition (string T itself)
    // And we would like to find a substring P that fits k-times in string T
    int lenP = 0;
    char* p = t;
    do {
        lenP++;
    }while(checkSubstringInString(t, lenT, p, lenP) < 0);
    
    return lenP;
}

int main() {
    char s[]= "brbb";
    char t[]= "brbb";

    printf("%d", findSmallestDivisor(&s, &t));
    
}
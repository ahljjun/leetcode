
/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();
    if ( m == 0 ) return 0;

    for(int i=0; i < n-m+1; i++){
        int j=0;
        for(; j<m; j++){
            if(haystack[i+j] != needle[j])
                break;
        }
        if ( j== m ) return i;
    }
    return -1;
}

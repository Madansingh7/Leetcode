void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseString(char* s, int sSize) {
      // two pointer approach
        int i=0, j=sSize-1;
        while(i<j){
            swap(&s[i++],&s[j--]);
        }
}
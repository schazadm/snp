#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char SPACE = ' ';
const char TAB = '\t';
const char EOL = '\n';
const char NUL = '\0';

int main(void) {
    char ch;
    char lastChar = NUL;
    int charCount = 0;
    int wordCount = 0;
    int wordCharCount = 0;
    
    while ((ch = getchar()) != EOL) {
        if(ch == SPACE || ch == TAB) {
            if (lastChar != NUL && lastChar != SPACE && lastChar != TAB) {
                if(isalpha(lastChar)) {
                    wordCount++;
                }
            }
        } else {
            wordCharCount++;
        }
        charCount++;
        lastChar = ch;
    }
    
    if((wordCount == 0 && wordCharCount > 0) || (lastChar != SPACE && lastChar != TAB)) {
        wordCount++;
    }
     
    (void)printf("Words: %d\nChars: %d\n", wordCount, charCount);
    return EXIT_SUCCESS;
}

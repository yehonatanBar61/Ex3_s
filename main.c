#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* substring(char *destination, const char *source, int beg, int n)
{
    // extracts `n` characters from the source string starting from `beg` index
    // and copy them into the destination string
    while (n > 0)
    {
        *destination = *(source + beg);
 
        destination++;
        source++;
        n--;
    }
 
    // null terminate destination string
    *destination = '\0';
 
    // return the destination string
    return destination;
}


int is_letter(char ch){
    if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;
    else
        return 0;
}


int gematrical(char check[1024]){
    int gemValue = 0;
    for (int i = 0; i < strlen(check); i++)
    {
        char ch = check[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            gemValue += ch - 'A' + 1;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            gemValue += ch - 'a' + 1;
        }
    }
    return gemValue;
}



void print_substrings(char *str,char word[30], int n)
{ 
    int gematrial_word = gematrical(word);
    int flage = 0;
    for (int len = 0; len <= n; len++)//run over the text string
    {     
        for (int i = len; i <= n; i++)//run over part of the string 
        {
            
            if(is_letter(str[len]) == 1 && is_letter(str[i-1]) == 1){
                char check[1024];
                substring(check, str, len, abs(i-len));
                if(gematrial_word == gematrical(check)){
                     if(flage == 1){
                        printf("~");
                     }                     
                    printf("%s",check);
                    flage = 1;
                }
            }

        }
    } 
}

int is_correct(char *str, char word[30]){//1-true , 0-false
    char word2[30];
    int flage = 0;
    for(int i = 0; i<30; i++){
        word2[i] = '\0';
    }
    for(int i = 0; i<strlen(word); i++){
        word2[i] = word[i];
    }
    if(strlen(str) < strlen(word))
        return 0;
    for(int i = 0; i<strlen(str); i++){
        flage = 0;
        for(int j=0; j<strlen(word2); j++){
            if(str[i] == ' '){
                flage = 1;
                break;
            }
            if(str[i] == word2[j]){
                flage = 1;
                word2[j] = ' ';
            }
        }
        if(flage == 0){
            return 0;
        }
    }
    for(int i = 0; i<strlen(word2); i++){
        if(word2[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void print_substrings3(char *str,char word[30], int n)
{ 
    int flage = 0;
    for (int len = 0; len <= n; len++)//run over the text string
    {     
        for (int i = len; i <= n; i++)//run over part of the string 
        {
            
            if(is_letter(str[len]) == 1 && is_letter(str[i-1]) == 1){
                char check[1024];
                substring(check, str, len, abs(i-len));
                if(is_correct(check,word) == 1){
                     if(flage == 1){
                        printf("~");
                     }                     
                    printf("%s",check);
                    flage = 1;
                }
            }

        }
    } 
}

int has_it(char temp_text[1024]){// 1-has it, 0 - doesent
    for(int i = 0; i<strlen(temp_text); i++){
        if(temp_text[i] == '~'){
            return 1;
        }
    }
    return 0;
}

void getin(char temp_text[1024], char text[1024]){
    for(int i = 0; i<strlen(text); i++){
        if(text[i] == text[strlen(text-1)]){
            for(int j = 0; j<strlen(temp_text); i++){
                text[i+j] = temp_text[j];
            }
            break;
        }
    }
}


int reversok(char word[30], char text2[1024]){
    int counter = 0;
    for(int i = strlen(text2)-1; i>=0; i--){
        if(text2[i] != word[counter]){
            return 0;
        }
        counter++;
    }
    return 1;
}

int equals(char word[30], char text_temp[1024]){
    int flage1 = 1;
    int flage2 = 1;
    if(strlen(word) != strlen(text_temp)){
        return 0;
    }
    for(int i = 0; i<strlen(text_temp); i++){
        if(word[i] != text_temp[i]){
            flage1 = 0;
        }
    }
    int counter = 0;
    for(int i = strlen(text_temp)-1; i>=0; i--){
        if(word[counter] != text_temp[i]){
            flage2 = 0;
        }
        counter++;
    }
    if(flage2 == 1){
        return 1;
    }
    if(flage1 == 1){
        return 1;
    }
    return 0;
}

int test(char str1[30], char text[1024]){
    char alf[26] = "zyxwvutsrqponmlkjihgfedcba";
    char alf2[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char text_temp[1024];
    for(int i = 0; i<1024; i++){
        text_temp[i] = '\0';
    }
    for (int k = 0,j = 0; k < strlen(text); k++){
        if(text[k] != ' '){
            text_temp[k] = text[k];
            j++;
        }
    }

    for (int i = 0; i < strlen(text_temp); i++){
        if(is_letter(text_temp[i])){
            if(isupper(text_temp[i])){
                text_temp[i] = alf2[text_temp[i] - 'A'];
            }
            else{
                text_temp[i] = alf[text_temp[i] - 'a'];
            }
                
        }
    }
    if(equals(str1,text_temp) == 1){
        return 1;
        
    }
    else{
        return 0;
    }
}


void print_substrings2(char *str,char word[30], int n)
{ 
    int flage = 0;
    for (int len = 0; len <= n; len++)//run over the text string
    {     
        for (int i = len; i <= n; i++)//run over part of the string 
        {
            
            if(is_letter(str[len]) == 1 && is_letter(str[i-1]) == 1){
                char check[1024];
                substring(check, str, len, abs(i-len));
                if(test(word, check) == 1){
                     if(flage == 1){
                        printf("~");
                     }                     
                    printf("%s",check);
                    flage = 1;
                }
                
            }

        }
    } 
}







int main()  
{ 
    char word[30];
    scanf("%s",word);
    char text[1024];
    scanf("%[^~]s",text);

    printf("Gematria Sequences: ");
    print_substrings(text, word, strlen(text));
    printf("\n"); 
    printf("Atbash Sequences: ");
    print_substrings2(text, word, strlen(text)); 
    printf("\n"); 
    printf("Anagram Sequences: ");
    print_substrings3(text, word, strlen(text));  

    
    return 0; 
} 


 

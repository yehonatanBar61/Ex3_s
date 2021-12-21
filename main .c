#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void print_string(char check[256]){
    for(int i=0; i<strlen(check); i++){
        printf("%c",check[i]);
    }
}

int is_letter(char ch){
    if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;
    else
        return 0;
}


int gematrical(char check[256]){
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
    for (int len = 1; len <= n; len++)//run over the text string
    {     
        for (int i = 0; i <= n - len; i++)//run over part of the string 
        {
            
            if(is_letter(str[i]) == 1 && is_letter(str[i+len-1]) == 1){
                char check[256];
                substring(check, str, i, len);
                if(gematrial_word == gematrical(check)){
                     if(flage == 1){
                        printf("~");
                     }                     
                    print_string(check);
                    flage = 1;
                }
            }

        }
    } 
}
int is_correct(char *str, char word[30]){//1-true , 0-false
    char word2[30];
    int flage = 0;
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
    for (int len = 1; len <= n; len++)//run over the text string
    {     
        for (int i = 0; i <= n - len; i++)//run over part of the string 
        {
            
            if(is_letter(str[i]) == 1 && is_letter(str[i+len-1]) == 1){
                char check[256];
                substring(check, str, i, len);
                if(is_correct(check,word) == 1){
                     if(flage == 1){
                        printf("~");
                     }                     
                    print_string(check);
                    flage = 1;
                }
            }

        }
    } 
}

int has_it(char temp_text[256]){// 1-has it, 0 - doesent
    for(int i = 0; i<strlen(temp_text); i++){
        if(temp_text[i] == '~'){
            return 1;
        }
    }
    return 0;
}

void getin(char temp_text[256], char text[256]){
    for(int i = 0; i<strlen(text); i++){
        if(text[i] == text[strlen(text-1)]){
            for(int j = 0; j<strlen(temp_text); i++){
                text[i+j] = temp_text[j];
            }
            break;
        }
    }
}


int reversok(char word[30], char text2[256]){
    int counter = 0;
    for(int i = strlen(text2)-1; i>=0; i--){
        if(text2[i] != word[counter]){
            return 0;
        }
        counter++;
    }
    return 1;
}

int test(char str1[30], char text[256]){
    char alf[26] = "zyxwvutsrqponmlkjihgfedcba";
    char alf2[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char textt[256];
    for (int i = 0; i < strlen(text); i++){
        textt[i] = text[i];
    } 
    for (int i = 0; i < strlen(textt); i++){
        if(is_letter(textt[i]) == 1){
            if(text[i] >=91 && text[i]<=122){
            textt[i] = alf2[textt[i] - 'A'];
            }
            if(text[i] >=65 && text[i]<=90){
            textt[i] = alf[textt[i] - 'a'];
            }
        }
    }
    char text2[256];
    int counter = 0;
    for (int i = 0; i < strlen(textt); i++){
        if(textt[i] != ' '){
            text2[counter] = textt[i];
            counter++;
        }
    }
    if(strlen(text2) != strlen(str1)){
        return 0;
    }

    for (int i = 0; i < strlen(text2); i++){
        if(str1[i] != text2[i]){
            return 0;
        }
    }
    return 1;
}

int test2(char str1[30], char text[256]){
    char alf[26] = "zyxwvutsrqponmlkjihgfedcba";
    char alf2[26] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char textt[256];
    for (int i = 0; i < strlen(text); i++){
        textt[i] = text[i];
    } 
    for (int i = 0; i < strlen(textt); i++){
        if(is_letter(textt[i]) == 1){
            if(text[i] >=97 && text[i]<=122){
            textt[i] = alf[textt[i] - 'a'];
            }
            if(text[i] >=65 && text[i]<=90){
            textt[i] = alf2[textt[i] - 'A'];
            }
        }
    }
    char text2[256];
    int counter = 0;
    for (int i = 0; i < strlen(textt); i++){
        if(textt[i] != ' '){
            text2[counter] = textt[i];
            counter++;
        }
    }
    if(strlen(text2) != strlen(str1)){
        return 0;
    }
    if(reversok(str1,text2) == 1){
        return 1;
    }
    return 0;
    
}

void print_substrings2(char *str,char word[30], int n)
{ 
    int flage = 0;
    for (int len = 1; len <= n; len++)//run over the text string
    {     
        for (int i = 0; i <= n - len; i++)//run over part of the string 
        {
            
            if(is_letter(str[i]) == 1 && is_letter(str[i+len-1]) == 1){
                char check[256];
                substring(check, str, i, len);
                if(test(word, check) == 1){
                     if(flage == 1){
                        printf("~");
                     }                     
                    printf("%s",check);
                    flage = 1;
                }
                if(test2(word, check) == 1){
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
    char word[30] = "abcd";
    char text[256];
    char temp_text[256];
    fgets(temp_text,256, stdin);
    for(int i = 0; i<strlen(temp_text); i++){
        if(temp_text[i] != '~'){
            text[i] = temp_text[i];
        }
        else
            break;
    }

    printf("Gematria Sequences: ");
    print_substrings(text, word, strlen(text));
     printf("\n"); 
    //printf("Atbash Sequences: ");
    //print_substrings2(text, word, strlen(text)); 
    printf("Anagram Sequences: ");
    print_substrings3(text, word, strlen(text));  
    printf("\n");

    return 0; 
} 


 

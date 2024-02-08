#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

int* countSymbols(char* text){
    int* ascii = (int*)malloc(sizeof(int)*128);
    size_t tlen = strlen(text);
    for (int i = 0; i<tlen; i++){
        if(text[i]>=0 && text[i]<128){
            ascii[text[i]]++;
        }
    }
    return ascii;
}

int main(int argc, char* argv[]){

    char text[1000];
    strcpy(text, argv[1]);
    int file = open(text,O_RDONLY);
    read(file, text, sizeof(text));
    int* result;
    result = countSymbols(text);
    close(file);
    size_t argvLength = strlen("text.txt");
    char* newtext = (char*)malloc(argvLength+10);
    strcpy(newtext, "text.txt");
    strcpy(newtext+argvLength-4,"stat.txt");
    int file2 = open(newtext,O_WRONLY | O_CREAT | O_TRUNC, 0644);
    unsigned int length;
    for(int i = 0; i<128; i++){
        if (isalpha(i)){
            char ch[2] = {(char)i};
            char ch1[2] = {'-'};
            char num[4];
            sprintf(num, "%d", result[i]);
            char ln[3]="\n";
            length = strlen(ch)+strlen(ch1)+strlen(num)+strlen(ln);  
        }
    }
    char * toWrite = (char*)malloc(length*sizeof(char));
    for(int i = 0; i<128; i++){
        if (isalpha(i)){
            char ch[2] = {(char)i};
            char ch1[2] = {'-'};
            char num[4];
            sprintf(num, "%d", result[i]);
            char ln[3]="\n";
            strcat(toWrite, ch);
            strcat(toWrite, ch1);
            strcat(toWrite, num);
            strcat(toWrite, ln);
        }
    }
    size_t t = strlen(toWrite);
    write(file2, toWrite,t);
    close(file2);
    free(toWrite);
    free(result);
    free(newtext);
}

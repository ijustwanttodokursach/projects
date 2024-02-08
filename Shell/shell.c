#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <stdlib.h>
#include<stdbool.h>

#define TERMINAL_LIMIT 1000

struct commandFlags
{
    char** writeFile;
    bool* toFile;
    int *separator;
    int commandCount;
};

char **getCommands(char *terminal, int *termLen, struct commandFlags *cf)
{
    char **words = (char **)malloc(sizeof(char *) * TERMINAL_LIMIT);
    char space[] = " \n";
    char line[] = "|";
    char *token = strtok(terminal, space);
    int getWrd = 0;
    cf->separator = (int *)malloc(sizeof(int) * TERMINAL_LIMIT);
    cf->commandCount = 1;
    memset(cf->separator, 0, TERMINAL_LIMIT);
    while (token != NULL)
    {
        words[getWrd] = token;
        if (!strcmp(line, words[getWrd]))
        {
            cf->separator[cf->commandCount] = getWrd;
            cf->commandCount++;
        }
        getWrd++;
        token = strtok(NULL, space);
    }
    *termLen = getWrd;
    return words;
}

void runTerminal(char **words, const int *termLen, struct commandFlags *cf){
    char arrow[] = ">";
    char cd[] = "cd";
    char ***commands = (char ***)malloc(sizeof(char **) * TERMINAL_LIMIT);
    cf->writeFile = (char**)malloc(sizeof(char*)* cf->commandCount);
    cf->toFile = (bool*)malloc(sizeof(bool)*cf->commandCount);
    char line[] = "|";
    for (int i = 0; i < TERMINAL_LIMIT; i++){
        commands[i] = (char **)malloc(TERMINAL_LIMIT * sizeof(char *));
        for (int j = 0; j < TERMINAL_LIMIT; j++) {
            commands[i][j] = (char *)malloc(TERMINAL_LIMIT * sizeof(char));
        }
    }
    char n[2] = " ";
    strcpy(commands[0][0],n);
    cf->separator[cf->commandCount] = *termLen; 
    for (int i = 0; i < cf->commandCount; i++)
    {
        int skip = -1;
        unsigned int k = 0;
            for (int j = cf->separator[i]; j < cf->separator[i + 1]; j++)
            {
                
                if (strcmp(line, words[j]) && j!=skip)
                {
                    
                    if (!strcmp(arrow, words[j]) ){
                        cf->toFile[i] = true;
                        cf->writeFile[i] = words[j+1];
                        skip = j+1;
                        continue;
                    }
                    if(!strcmp(words[j],cd)){
                        chdir(words[j+1]);
                        return;
                    }
                    else{
                        strcpy(commands[i][k],words[j]);
                        k++;
                    }
                }
            }
            commands[i][k] = NULL;
    }
    int pip[2*cf->commandCount];
    for (int i = 0; i < cf->commandCount; i++) {
        pipe(&pip[2*i]);
    }
    for(int i = 0;i<cf->commandCount;i++){
        int fd;
        pid_t toExecute = fork();
        if (toExecute == 0){
            
            if(i!=cf->commandCount-1 && cf->commandCount>1){
                dup2(pip[2*i+1], STDOUT_FILENO);
            }
            if (i>0){
                dup2(pip[2*(i-1)], STDIN_FILENO);
            }
            if (cf->toFile[i] == true){
                fd = open(cf->writeFile[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                dup2(fd, STDOUT_FILENO);
            }
            if(commands[i][0]!=NULL){

                if(execvp((const char*)commands[i][0], (char* const*)commands[i])==-1){
                    printf(">>> Command failed\n");
                }
            }
            exit(0);
        }
        else{
            if(i != cf->commandCount-1){
            close(pip[2*i+1]);
            }
            close(fd);
            waitpid(toExecute, NULL, 0);
        }
    }
    for (int i = 0; i < TERMINAL_LIMIT; i++){
        for (int j = 0; j < TERMINAL_LIMIT; j++) {
            free(commands[i][j]);
        }
        free(commands[i]);
    }
    free(commands);
    free(words);
    free(cf->separator);
    free(cf->writeFile);
    free(cf->toFile);
}

int main(int agrc, char *argv[])
{
    char terminal[TERMINAL_LIMIT];
    char **words;
    int termLen;
    struct commandFlags cf;
    char ext[] = "exit";
    char ifExt[5];
    strncpy(ifExt, terminal, 5);
    while (1)
    {
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        printf("%s >>> ", cwd);
        fgets(terminal, sizeof(terminal), stdin);
        
        strncpy(ifExt, terminal, 4);
        if (strcmp(ext, ifExt)!=0){
            words = getCommands(terminal, &termLen, &cf);
            runTerminal(words, &termLen, &cf);
        }
        else{
            return 0;
        }
    }
}
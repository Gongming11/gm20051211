#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>    
  
typedef struct 
{  
    char word[100];  
    int total_count; //单词总共出现的次数  
    int line_counts[100]; //单词在每行中出现的次数 
} DUqudanci;  
  
DUqudanci words[1000];  
int word_count = 0; //当前已存储的单词数  
int line_num = 0; //当前行号  
    
void addword(char *word, int line_index) //添加读取到的单词到数组
{  
    for (int i = 0; i < word_count; ++i) 
    {  
        if (strcmp(words[i].word, word) == 0) 
        {    
            words[i].total_count++;  
            words[i].line_counts[line_index]++;  
            return;//读取到出现过的单词后更新该单词的信息
        }  
    }  
    if (word_count < 1000) 
    {    
        strcpy(words[word_count].word, word);  
        words[word_count].total_count = 1;  
        words[word_count].line_counts[line_index] = 1;  
        word_count++;  //读取到新单词后进行相同的处理
    }  
}  
    
void readwords() //读取每行的单词并对单词进行分类计数
{  
    char line[1024];  
  
    while (fgets(line, sizeof(line), stdin)) 
    {  
        if (strcmp(line, "END\n") == 0) 
        {  
            break;   
        }    
        line[strcspn(line, "\n")] = 0;  //去除每一行最后的换行符以防读取混乱
        char *word = strtok(line, " \t\n\r\f\v"); //运用各种转义字符对不同的单词进行分离并且进行制表 
        while (word) 
        {    
            addword(word, line_num);  
            word = strtok(NULL, " \t\n\r\f\v");  
        }  
        line_num++; // 更换到下一行进行检查遍历  
    }  
}  
   
void printword() 
{  
    for (int i = 0; i < word_count; i++) 
    {  
        printf("Word: %s, Total Count: %d\n", words[i].word, words[i].total_count);  
        for (int j = 0; j < line_num; j++) 
        {  
            if (words[i].line_counts[j] > 0) 
            {  
                printf("  Line %d: %d\n", j + 1, words[i].line_counts[j]);  
            }  
        }  
    }  
}  
  
int main() 
{  
    printf("Enter lines of text. Type 'END' to finish:\n");  
    readwords();  
    printword();  
    return 0;  
}
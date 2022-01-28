#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
string filename = "5_letter.txt";

class WordDictionary {
public:
    struct TrieNode{
        TrieNode *child[26];
        bool isWord;
        TrieNode(){
            isWord = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    
    TrieNode *trie;
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *currNode = trie;
        for(char c : word){
            c -= 'a';
            if(currNode->child[c] == NULL){
                currNode->child[c] = new TrieNode();
            }
            currNode = currNode->child[c];
        }
        currNode->isWord = true;
        return;
    }
    
    void dfs(string word, int index, TrieNode *currNode, vector<string> &ans, string currString, vector<bool> &excluding_list){
        //printf("%s %s\n", word.c_str(), currString.c_str());
        int len = word.size();
        for(int i = index; i < len; i++){
            if(word[i] == '*'){
                for(int j = 0; j < 26; j++){
                    if(currNode->child[j] != NULL && excluding_list[j] == false){
                        char ch = 'a' + j;
                        dfs(word, i + 1, currNode->child[j], ans, currString + ch, excluding_list);
                    }    
                }
                return;
            }
            else{
                int c = word[i] - 'a';
                if(currNode->child[c] == NULL){
                    return;
                }
                currString += word[i];
                currNode = currNode->child[c];
            }
        }
        if(currNode->isWord){
            ans.push_back(currString);
        }
        return;
    }
    
    vector<string> search(string word, string excluding_string) {
        vector<string> ans;
        string currString;
        vector<bool> excluding_list(26, false);
        for(char ch : excluding_string){
            excluding_list[ch - 'a'] = true;
        }
        dfs(word, 0, trie, ans, currString, excluding_list);
        return ans;
    }
};

int main(void){
    vector<string> words;
    WordDictionary* obj = new WordDictionary();
    ifstream inputFile(filename);
    string str;
    while(getline(inputFile, str)){
        if(str.size() > 0){
            words.push_back(str);
            obj->addWord(str);
        }
    }
    
    printf("Usage: \n");
    printf("[word pattern]\n");
    printf("[excluded characters]\n");
    printf("For example, if we want to find a word with pattern \"app**\", excluding characters 'b', 'y', 'g' and 'n'\n");
    printf("--------------------\n");
    printf("$./search\n");
    printf("app**\n");
    printf("bygn\n");
    printf("Possible words:\n[0] appal\n[1] apple\n[2] appro\n");
    printf("--------------------\n");
    printf("Note that if you don't want to exclude any character, just leave it empty and type enter\n");

    char word[32], exclude[32];
    while(true){
        //scanf("%s", word);
        printf("Enter word pattern: ");
        fgets(word, 32, stdin);
        if(strcmp(word, "exit") == 0){
            break;
        }
        printf("Enter excluded characters: ");
        fgets(exclude, 32, stdin);

        str = string(word,  strlen(word) - 1); // strip '\n'
        string excluding_string(exclude, strlen(exclude) - 1);
        vector<string> rev = obj->search(str, excluding_string);
        printf("Possible words:\n");
        for(int i = 0; i < rev.size(); i++){
            printf("[%d] %s\n", i, rev[i].c_str());
        }
        printf("--------------------\n");
    }
    //printf("%d\n", words.size());
    //bool param_2 = obj->search(word);
    return 0;
}

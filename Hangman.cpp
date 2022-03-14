#include <iostream>
#include <algorithm>
#include<fstream>
#include<time.h>
#include<vector>

using namespace std;
// temporary image src
string frame[] = {"_____________ ","|           | ","|             ","|             ","|             ","|             " };
string hangman[] = {"|           O ","|           | ","|          /| ","|          /|\\","|          /  ","|          / \\"};
string keyb[] = {"A B C D E F G H I","J K L M N O P Q R","S T U V W X Y Z"};

vector <string> readfile(string namefile)
{
    ifstream file(namefile);
    vector <string> lisword;
    while(!file.eof())
    {
        string line;
        file >> line;
        lisword.push_back(line);
    }
    return lisword;
}

void customH(const string filename)
{
    char tmp ;
	vector <string> v;
	string word = "";
	while(tmp != '.')
	{
		cin >> tmp;
		if(tmp == ',' || tmp == '.')
		{
			v.push_back(word);
			word = "";
		}else{
			word+= tmp;
		}
	}
	ofstream file(filename);
    for(int i =0;i < v.size();i++)
    {
        file << v[i] << endl;
    }
}

void initGame(string& hiddenWord,string& guessWord,int& guessCount)
{
    int n = readfile("HIDDENW.doc").size();
    hiddenWord = readfile("HIDDENW.doc")[rand()%n];
    transform(hiddenWord.begin(),hiddenWord.end(),hiddenWord.begin(),::toupper);
    guessWord = string(hiddenWord.length(),'_');
    guessCount = 0;
}

void box(int length,string word[],int size,bool top = true ,bool bottom =true)
{       
        string border = "|" + string(length-2,'=') + "|";
        if(top)
        {
            cout << border <<endl;
        }
        for(int i =0;i< size ;i++)
        {   
            string copy = word[i];
            while(copy.size() < length-2)
            {
                if(copy.size() < length-2)
                {
                    copy = copy + " ";
                }
                if(copy.size() < length-2)
                {
                    copy = " " + copy;
                }
            }
            copy = "|" + copy + "|";
            cout << copy << endl;
        }
        if(bottom)
        {
            cout << border <<endl;
        }
        
}

void keyboardHandling(char input,string key[])
{
    for(int i = 0;i < 3;i++)
    {
        for(int j= 0;j < key[i].size();j++)
        {
            if(key[i][j] == input)
            {
                keyb[i][j] = ' ';
            }
        }
    }
}    

void renderGame(string framei[],string& guessWord,int& WrongGuess)
{   
    for(int i = 0;i <20;i++)
    {
        cout << endl;
    }
    for(int i= 0;i < WrongGuess;i++)    
    {   
        if(i < 1)
        {
            framei[2] = hangman[i];
        }else if(i < 4){
            framei[3] = hangman[i];
        }else{
            framei[4] = hangman[i];
        }
    }
    box(32,framei,6);
    string hword[] = {guessWord};
    box(32,hword,1,false);
    box(32,keyb,3,false);
    

}

char userInput()
{   
    string input;
    cin >> input;
    return toupper(input[0]);
}

void updateGame(char input,string& guessWord,const string& hiddenWord,int& wrongGuess)
{
    if(hiddenWord.find(input) == string::npos )
    {
        wrongGuess++;
    }else{
        for(int i = 0;i < hiddenWord.size();i++)
        {
            if(input == hiddenWord[i])
            {
                guessWord[i] = hiddenWord[i];
            }
        }
        
    }
    keyboardHandling(input,keyb);
}

bool Gameover(const string& hiddenword,const string& guessWord,int wrongGuess)
{   
    if(hiddenword == guessWord || wrongGuess == 6)
    {
        return true;
    }

    return false;
    
}

void displayResult(const string& hiddenword, string& guessWord)
{   
    for(int i =0 ;i< 20;i++)
    {
        cout << endl;
    }
    if(hiddenword == guessWord)
    {   
        string word[] = {"","","VICTORY","",""};
        box(32,word,5);
    }else{
        string word[] = {" ","","LOST","Hidden Word: " + hiddenword,""};
        box(32,word,5);
    }
}

int main()
{	
    srand(time(0));
    string hiddenWord;
    string guessWord;
    int wrongGuess;
    customH("HIDDENW.doc");
	initGame(hiddenWord,guessWord,wrongGuess);
    while(!Gameover(hiddenWord,guessWord,wrongGuess))
    {
        renderGame(frame,guessWord,wrongGuess);
        char input = userInput();
        updateGame(input,guessWord,hiddenWord,wrongGuess);
    }
    renderGame(frame,guessWord,wrongGuess);
    displayResult(hiddenWord,guessWord);
    return 0;
} 

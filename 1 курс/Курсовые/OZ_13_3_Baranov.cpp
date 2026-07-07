#include <string>
#include <iostream>

using namespace std;

int main(){
    string line;
    string result = "";
    int brackets_open = 0;
    int brackets_close = 0;
    bool proverka = true;
    cout << "Введите строчку: ";
    getline(cin, line);
    for (int i = 0; i < line.length(); ++i){
        if (line[i] != '(' && line[i] != ')' && (brackets_close == brackets_open)){
            result += line[i];
        }
        else if (line[i] == '('){
            if (brackets_open == brackets_close){
                result += ' ';
            }
            brackets_open += 1;
        }
        else if(line[i] == ')'){
            brackets_close += 1;
        }
    }

    cout << result;
}


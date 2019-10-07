// Dorian Holmes and Oluchi Chukwunyere COMP 360-01 Programming Languages   Fall 2019 Project 1
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
    char keywords[32][10] =
            {"auto", "break", "case", "char", "const", "continue", "default",
             "do", "double", "else", "enum", "extern", "float", "for", "goto",
             "if", "int", "long", "register", "return", "short", "signed",
             "sizeof", "static", "struct", "switch", "typedef", "union",
             "unsigned", "void", "volatile", "while"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void identifiers(int idCount, vector<char> idList) {
    printf("Identifiers: ");
    if (!idList.size()) {
        cout << "/n";
    } else {
        for (int f = 0; f < idCount; ++f) {
            if (f == idCount - 1) {
                cout << idList[f] << "\n";
            } else {
                cout << idList[f] << ", ";
            }
        }
    }
}

void logicalOperators(int logicalOperatorsCount, vector<char> logicalOperatorsList, int idCount, vector<char> idList) {
    printf("Logical Operators: ");
    if (!logicalOperatorsList.size()) {
        cout << "\n";
    } else {
        for (int f = 0; f < logicalOperatorsCount; ++f) {
            if (f == logicalOperatorsCount - 1) {
                cout << logicalOperatorsList[f] << "\n";
            } else {
                cout << logicalOperatorsList[f] << ", ";
            }
        }
    }
    identifiers(idCount, idList);
}

void mathOperators(int mathOperatorsCount, vector<char> mathOperatorsList, int logicalOperatorsCount, vector<char> logicalOperatorsList, int idCount, vector<char> idList) {
    printf("Math Operators: ");
    if (!mathOperatorsList.size()) {
        cout << "\n";
    } else {
        for (int f = 0; f < mathOperatorsCount; ++f) {
            if (f == mathOperatorsCount - 1) {
                cout << mathOperatorsList[f] << "\n";
            } else {
                cout << mathOperatorsList[f] << ", ";
            }
        }
    }
    logicalOperators(logicalOperatorsCount, logicalOperatorsList, idCount, idList);
}

void keyword(int keywordCount, vector<string> keywordList, int mathOperatorsCount, vector<char> mathOperatorsList, int logicalOperatorsCount, vector<char> logicalOperatorsList, int idCount, vector<char> idList) {
    printf("Keywords: ");
    if (!keywordList.size()) {
        cout << "\n";
    } else {
        for (int f = 0; f < keywordCount; ++f) {
            if (f == keywordCount - 1) {
                cout << keywordList[f] << "\n";
            } else {
                cout << keywordList[f] << ", ";
            }
        }
    }
    mathOperators(mathOperatorsCount, mathOperatorsList, logicalOperatorsCount, logicalOperatorsList, idCount, idList);
}



void others(int othersCount, vector<char> othersList, int keywordCount, vector<string> keywordList, int mathOperatorsCount, vector<char> mathOperatorsList, int logicalOperatorsCount, vector<char> logicalOperatorsList, int idCount, vector<char> idList) {
    printf("Others: ");
    for (int f = 0; f < othersCount; ++f) {
        if (f == othersCount - 1) {
            cout << othersList[f] << "\n";
        } else {
            cout << othersList[f] << " ";
        }
    }
    keyword(keywordCount, keywordList, mathOperatorsCount, mathOperatorsList, logicalOperatorsCount, logicalOperatorsList, idCount, idList);
}

int main() {
    char ch, buffer[15], logical_op[] = "><", math_op[] = "+-*/=", other[] = ",;\(){}[]'':";
    ifstream fin(R"(C:\Users\Doetheman\Documents\ProgrammingLanguages\Lexical-Analyzer-in-Cpp\program1.txt)");
    int mark[1000] = {0};
    int i, j = 0, keywordCount = 0, idCount = 0, logicalOperatorsCount = 0, mathOperatorsCount = 0, otherCount = 0;
    vector<string> keywordList;
    vector<char> idList;
    vector<char> logicalOperatorsList;
    vector<char> mathOperatorsList;
    vector<string> nu;
    vector<char> otherList;

    if (!fin.is_open()) {
        cout << "error while opening the file\n";
        exit(0);
    }

    // Condition statement that loops until you are at the end of the file.
    while (!fin.eof()) {
        ch = fin.get();
        for (i = 0; i < 12; ++i) {
            if (ch == other[i]) {
                int aa = ch;
                if (mark[aa] != 1) {
                    otherList.push_back(ch);
                    mark[aa] = 1;
                    ++otherCount;
                }
            }
        }

        for (i = 0; i < 5; ++i) {
            if (ch == math_op[i]) {
                int aa = ch;
                if (mark[aa] != 1) {
                    mathOperatorsList.push_back(ch);
                    mark[aa] = 1;
                    ++mathOperatorsCount;
                }
            }
        }

        for (i = 0; i < 2; ++i) {
            if (ch == logical_op[i]) {
                int aa = ch;
                if (mark[aa] != 1) {
                    logicalOperatorsList.push_back(ch);
                    mark[aa] = 1;
                    ++logicalOperatorsCount;
                }
            }

        }

        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1) {
                keywordList.push_back(buffer);
                ++keywordCount;
            } else {
                if (buffer[0] >= 97 && buffer[0] <= 122) {
                    if (mark[buffer[0] - 'a'] != 1) {
                        char x = fin.get();
                        cout << x;
                        idList.push_back(buffer[0]);
                        ++idCount;
                        mark[buffer[0] - 'a'] = 1;
                    }
                }
            }
        }
    }

    fin.close();
//    keyword(keywordCount, keywordList);
//    mathOperators(mathOperatorsCount, mathOperatorsList);
//    logicalOperators(logicalOperatorsCount, logicalOperatorsList);
//    identifiers(idCount, idList);
    others(otherCount, otherList, keywordCount, keywordList, mathOperatorsCount, mathOperatorsList, logicalOperatorsCount, logicalOperatorsList, idCount, idList);
    return 0;
}

/*
    Brainfuck interpreter
    Created by SigmaBalls
*/


#include <iostream>
#include <fstream>

void interpreter(std::string file) {
    std::ifstream fin(file);
    std::string text{""};

    char chunk;
    char DATA[30000] = {};
    char *p = &DATA[15000];

    int j{}, k{}, x_copy{};

    while(fin >> chunk) {
        text = text + chunk;
        j++;
    }

    for(int x{}; x < j; x++) {

        switch(text[x]) {
            case '.':
                std::cout << *p;
                break;
            case '+':
                ++*p;
                break;
            case '-':
                --*p;
                break;
            case ',':
                std::cin >> *p;
                break;
            case '>':
                ++p;
                break;
            case '<':
                --p;
                break;
            case ']':
                x_copy = x - 1;
                k = 0;
                for(int flag{1}; flag != 0; x_copy--, k++) {
                    if(text[x_copy] == ']') {
                        flag++;
                    }
                    else if(text[x_copy] == '[') {
                        flag--;
                    }
                }

                if(*p != 0) {
                    x -= k;
                }

                break;
            default:
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        std::cout << "USAGE: bfuck [input file]\n";
        std::cout << "Exemple: bfuck main.bf\n\n";
    }
    else if(argc == 2) {
        std::string file = argv[1];
        interpreter(file);
        std::cout << "\n\n";
    }
    else {
        std::cout << "ERROR: too many arguments!\n\n";
    }
    


    return 0;
}
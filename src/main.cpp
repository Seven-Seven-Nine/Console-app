#include <iostream>
#include <string>
#include "debug.hpp"
#include <cstdlib>

void userInput();

// Глобальные переменные.
bool debug = false;
std::string nameProgram = "_Console App_ 0.0.2";

/**
 * Точка старта X_X
 */
int main(int argc, char* argv[]) {
    std::cout << nameProgram << std::endl;
    
    if (argc > 1) {
        if (std::strcmp(argv[1], "--debug") == 0 || std::strcmp(argv[1], "debug") == 0) {
            std::cout << "Debugging mode is enabled!" << std::endl;
            debug = true;
        } else if (std::strcmp(argv[1], "--help") == 0 || std::strcmp(argv[1], "help") == 0) {
            std::cout << "Available arguments: " << std::endl;
            std::cout << "\033[33m" << "--help" << "\033[0m" << " - list of all arguments." << std::endl;
            std::cout << "\033[33m" << "--debug" << "\033[0m" << " - debugging mode." << std::endl;
            return 0;
        } else {
            std::cout << "Unknown argument!" << std::endl;
            return 1;
        }
    } else {
        std::cout << "No arguments found." << std::endl;
    }

    userInput();

    return 0;
}

/**
 * Ввод пользователя и дальнейшие варианты работы от зависимости ввода.
 */
void userInput() {
    bool exit = false;
    
    std::string userInput;

    while (exit == false) {
        std::cout << "\033[92m" << ">> " << "\033[0m";
        std::getline(std::cin, userInput);
        if (userInput == "help") {
            std::cout << "Available commands: " << std::endl;
            std::cout << "\033[33m" << "help" << "\033[0m" << " - list all commands." << std::endl;
            std:: cout << "\033[33m" << "clear" << "\033[0m" << " - clear the terminal." << std::endl;
            std:: cout << "\033[33m" << "debug" << "\033[0m" << " - switching the debugging mode." << std::endl;
            std:: cout << "\033[33m" << "exit" << "\033[0m" << " - close this program." << std::endl;
        } else if (userInput == "clear") {
            system("cls");
            std::cout << nameProgram << std::endl;
        } else if (userInput == "debug") {
            if (debug) {
                debug = false;
            } else {
                debug = true;
            }
        } else if (userInput == "exit") {
            break;
        } else if (userInput == "") {
            std::cout << "\033[91m" << "Void input!" << "\033[0m" << std::endl;
            std::cout << "Enter 'exit' to close this program." << std::endl;
        } else {
            std::cout << "\033[91m" << "Unknown commands!" << "\033[0m" << std::endl;
        }

        debugLog("user input", userInput);
    }
}

#include <iostream>
#include "debug.hpp"

/**
 * Вывод лога сообщения.
 */
void debugLog(std::string message) {
    if (debug) {
        std::cout << "\033[32m" << "Debug log (" << message << ") " << "\033[0m" << std::endl;
    }
}

/**
 * Вывод лога числа.
 */
void debugLog(int number) {
    if (debug) {
        std::cout << "\033[32m" << "Debug log (" << number << ") " << "\033[0m" << std::endl;
    }
}

/**
 * Вывод лога сообщения с дополнительной текстовой информацией.
 */
void debugLog(std::string message, std::string textMessage) {
    if (debug) {
        std::cout << "\033[32m" << "Debug log (" << message << "): " << textMessage << "\033[0m" << std::endl;
    }
}

/**
 * Вывод лога сообщения с дополнительной численной информацией.
 */
void debugLog(std::string message, int number) {
    if (debug) {
        std::cout << "\033[32m" << "Debug log (" << message << "): " << number << "\033[0m" << std::endl;
    }
}
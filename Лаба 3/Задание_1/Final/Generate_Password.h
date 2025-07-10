/**
 * @file password_generator.h
 * @brief Заголовочный файл для генератора паролей
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Генерирует случайный пароль заданной длины из указанных символов
 * @param length Длина пароля
 * @param chars Строка с символами, из которых генерируется пароль
 * @return Сгенерированный пароль
 */
string generatePassword(int length, const string& chars);

/**
 * @brief Инициализирует генератор случайных чисел
 */
void initRandomGenerator();

/**
 * @brief Получает набор символов и длину пароля на основе выбора пользователя
 * @param choice Выбор пользователя (1-3)
 * @param chars Ссылка на строку, в которую будет записан набор символов
 * @param length Ссылка на переменную, в которую будет записана длина пароля
 * @return true, если выбор корректен, false в противном случае
 */
bool getPasswordParameters(int choice, string& chars, int& length);

/**
 * @brief Выводит меню выбора сложности пароля
 */
void displayMenu();
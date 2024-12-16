/** @file tableсipher.h
 * @author Белов А.Р.
 * @version 1.0
 * @date 06.12.2024
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
/** @brief Шифрование методом табличной маршрутной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */
class tablecipher {
private:
    int st; ///< количество столбцов
    /**
     * @brief Проверка валидации ключа
     * 
     * Проверяет, что ключ не более половины длины шифруемого сообщения.
     * 
     * @param s Входная строка, представляющая ключ, строка с текстом.
     * @return ключ, который равен половины длины строки.
     */
    int isValidKey(int key,string s);
    /**
     * @brief Проверка символов строки
     * 
     * Проверяет, есть ли в сообщении символы, отличные от букв английского алфавита
     * 
     * @param s Входная строка, представляющая текст.
     * @throw cipher_error, если присутствуют некорректные символы
     */ 
    bool isPlusKey(int key);
    /**
     * @brief Валидация зашифрованного текста
     * 
     * Убирает пробелы из текста
     * 
     * @param ws Входная строка, представляющая текст.
     * @throw cipher_error если строка пуста
     */
    string getValidOpenText(const std::string& s);
public:
    tablecipher(int key); ///< конструктор
    tablecipher() = delete; ///< запрект конструктора без параметров
    /**
 	* @brief Зашифровывание
 	* @param [in] text Открытый текст. Не должен быть пустой строкой.
 	* Пробелы удаляются
 	* @return Зашифрованная строка
 	* @throw cipher_error, если текст пустой
 	*/
    string encrypt(string text);
    /**
 	* @brief Расшифровывание
 	* @param [in] text Шифрованный текст должен быть пустой строкой.
 	* Все пробелы убираются из текста
 	* Все не-буквы удаляются
 	* @return расшифрованная строка
 	* @throw cipher_error, если текст пустой
 	*/
    string decrypt(string text);
/**
 * @brief Обработка исключений
 * 
 * Класс, созданный для обработки ошибок
 * 
 */
 };
class cipher_error : public std::invalid_argument
{
public:
	 /**
     * @brief Конструктор с аргументом типа std::string
     * 
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const std::string& what_arg): 
    std::invalid_argument(what_arg){}
     /**
     * @brief Конструктор с аргументом типа const char*
     * 
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const char* what_arg): 
    std::invalid_argument(what_arg){}
};

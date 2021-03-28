#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// read mode macro for opening a file
#define READ_MODE "r+"
// append mode macro for opening a file
#define APPEND_MODE "a+"
// write mode macro for opening a file
#define WRITE_MODE "w+"
// buffer size macro for a word
#define BUFFER_SIZE 256

/**
 * @brief Functie ce deschide fisierul si returneaza un pointer catre acesta
 * @param filename - numele, path-ul absolut/relativ catre fisierul ce trebuie deschis
 * @param mode - modul in care va fi deschis fisierul (APPEND_MODE/WRITE_MODE/READ_MODE)
 * @return FILE* - pointer asociat noului fisier deschis
 */
FILE *openFile(const char *filename, const char *mode);

/**
 * @brief Functie ce testeaza daca argumentul primit este null
 * 
 * @param argument - pointer-ul ce trebuie testat
 * @return true/false
 */
bool isNull(void *argument);


/**
 * @brief Functie ce testeaza ca argumentul primit sa nu fie null
 * 
 * @param argument - pointer-ul ce trebuie testat
 * @return true/false
 */
bool isNotNull(void *argument);
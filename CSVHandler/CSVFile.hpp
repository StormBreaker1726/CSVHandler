#ifndef C3ABA26E_F0DD_4CB4_9CF5_BAFC7D93CA94
#define C3ABA26E_F0DD_4CB4_9CF5_BAFC7D93CA94

/**
 * @file CSVFile.hpp
 * @author João Víctor Costa de Oliveira (joaovictoroliveira1452@gmail.com)
 * @brief The base CSV file implementation
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <fstream>
#include <string.h>
#include <string>

class CSVFile
{
    public:
        CSVFile(const char* file_name, size_t num_columns);
        ~CSVFile();
    protected:
        size_t num_columns;
        char file_name[50];
    private:
};

CSVFile::CSVFile(const char* file_name, size_t num_columns)
{
    strcpy(this->file_name, file_name);
    this->num_columns = num_columns;
}

CSVFile::~CSVFile()
{
    
}

#endif /* C3ABA26E_F0DD_4CB4_9CF5_BAFC7D93CA94 */

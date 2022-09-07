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
        /**
         * @brief Construct a new CSVFile object
         * 
         * @param file_name path to the file that will be open
         * @param num_columns number of columns of the file
         */
        CSVFile(const char* file_name, size_t num_columns);
        /**
         * @brief Destroy the CSVFile object
         * 
         */
        ~CSVFile();
        void to_binary();
    protected:
        /**
         * @brief number of columns
         * 
         */
        size_t num_columns;
        /**
         * @brief path to the file that will be open
         * 
         */
        std::string file_name;
    private:
};

CSVFile::CSVFile(const char* file_name, size_t num_columns)
{
    this->file_name = file_name;
    this->num_columns = num_columns;
}

CSVFile::~CSVFile()
{
    
}

void CSVFile::to_binary()
{
    std::ifstream binary_file(this->file_name, std::ios::binary);
}

#endif /* C3ABA26E_F0DD_4CB4_9CF5_BAFC7D93CA94 */

#ifndef D27A5236_B17B_4BA4_8875_C14509F66308
#define D27A5236_B17B_4BA4_8875_C14509F66308

/**
 * @file CSVReader.hpp
 * @author João Víctor Costa de Oliveira (joaovictoroliveira1452@gmail.com)
 * @brief The CSV reader implementation
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../CSVHandler/CSVFile.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <string>
#include <sstream>

class CSVReader : public CSVFile
{
    public:
        /**
         * @brief Construct a new CSVReader object
         * 
         * @param file_name path to the file that will be open
         * @param num_columns number of columns of the file
         */
        CSVReader(const char* file_name, size_t num_columns);
        /**
         * @brief Destroy the CSVReader object
         * 
         */
        ~CSVReader();
        /**
         * @brief Returns the csv file content
         * 
         * @return std::vector<std::vector<std::string>> the content of the csv file 
         */
        std::vector<std::vector<std::string>> read_from_file();
        /**
         * @brief Read just one row of the file and returns it
         * 
         * @param row row position
         * @return std::vector<std::string> row that was read
         */
        std::vector<std::string> read_row(int row);
        /**
         * @brief Close the csv file
         * 
         */
        void close();
    private:
        /**
         * @brief The file name
         * 
         */
        std::ifstream file;
};

CSVReader::CSVReader(const char* file_name, size_t num_columns):CSVFile(file_name, num_columns)
{
    this->file.open(file_name);
}

CSVReader::~CSVReader()
{
    
}

std::vector<std::vector<std::string>> CSVReader::read_from_file()
{
    std::vector<std::vector<std::string>> csv_return;

    std::vector<std::string> row;

    std::string line, word, temp;

    char comma = 44;

    while (std::getline(this->file, line))
    {
        row.clear();

        std::stringstream ss(line);

        while (std::getline(ss, word, comma)) 
        {
            row.push_back(word);
        }

        csv_return.push_back(row);
    }
    
    return csv_return;
}

std::vector<std::string> CSVReader::read_row(int row)
{
    std::vector<std::string> row_to_return;

    std::string line, word, temp;

    char comma = 44;

    int i = 0;
    while(i < row)
    {
        std::getline(this->file, temp);
        i++;
    }

    std::getline(this->file, line);
    std::stringstream ss(line);

    while (std::getline(ss, word, comma)) 
    {
        row_to_return.push_back(word);
    }

    return row_to_return;
}

void CSVReader::close()
{
    this->file.close();
}

#endif /* D27A5236_B17B_4BA4_8875_C14509F66308 */

#ifndef D684E722_6269_4478_9FD6_496D1E248C2F
#define D684E722_6269_4478_9FD6_496D1E248C2F

/**
 * @file CSVWriter.hpp
 * @author João Víctor Costa de Oliveira (joaovictoroliveira1452@gmail.com)
 * @brief The CSV writer implementation
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
#include <iostream>
#include <string.h>
#include <string>

class CSVWriter : public CSVFile
{
    public:
        /**
         * @brief Construct a new CSVWriter object
         * 
         * @param file_name path to the file that will be open
         * @param num_columns number of columns of the file
         * @param app true: append in the file; false: rewrite the file
         */
        CSVWriter(const char* file_name, size_t num_columns, bool app);
        /**
         * @brief Destroy the CSVWriter object
         * 
         */
        ~CSVWriter();
        /**
         * @brief Write a new row in the file
         * 
         * @param row the row to be written 
         */
        void write_in_file(std::vector<std::string> row);
        /**
         * @brief Closes the file
         * 
         */
        void close();
    private:
        /**
         * @brief The file name
         * 
         */
        std::ofstream file;
};

CSVWriter::CSVWriter(const char* file_name, size_t num_columns, bool app):CSVFile(file_name, num_columns)
{
    if(app)
        this->file.open(file_name, std::ios::app);
    else 
        this->file.open(file_name);
}

CSVWriter::~CSVWriter()
{
    
}

void CSVWriter::write_in_file(std::vector<std::string> row)
{
    if(row.size() != this->num_columns)
    {
        std::cerr<<"Line needs to have the same size as the number of columns of the CSV file"<<std::endl;
        std::cerr<<"Number of columns = "<<this->num_columns<<std::endl;
        return;
    }

    for (size_t i = 0; i < this->num_columns; i++)
    {
        this->file<<row.at(i);
        if(i != this->num_columns - 1)
        {
            this->file<<",";
        }
    }
    this->file<<std::endl;
}

void CSVWriter::close()
{
    this->file.close();
}


#endif /* D684E722_6269_4478_9FD6_496D1E248C2F */

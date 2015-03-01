#ifndef XSTREAM_DATA_READER_H
#define XSTREAM_DATA_READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#define OPEN        "OpenFile(char flag): "
#define CLOSE       "ClosrFile(): "
#define READ        "ReadData(): "
#define WRITE       "WriteData(): "

#define ERROR       "error"

using namespace std;

class Data
{
public:
    /*
    Constructor:
        set file_name_
     */
    Data(string file_name);

    int ReadData();

    int WriteData();

    std::list<std::string> data_;


private:
    // file_name_: the relative path to the file.
    std::string file_name_;
    // *data_file_: the stream to read and write to the data file.
    std::fstream *data_file_;

    /*
    OpenFile:
        private method that handles the opening of files. It is
        always called on read or write.
        RETURN 0 on success, -1 on failure.
     */
    int OpenFile(char flag);

    /*
    CloseFile:
        private method that handles the closing of files. Is is
        always called on read or write.
        RETURN 0 on success, -1 on failure.
     */
    int CloseFile();
};

#endif // XSTREAM_DATA_READER_H
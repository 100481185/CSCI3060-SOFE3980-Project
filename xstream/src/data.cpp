#include "../include/data.h"

Data::Data(string file_name) : file_name_(file_name) {
}

int Data::ReadData() {
    if (OpenFile('r')) {
        std::string line;
        while (getline(*data_file_, line)) {
            try
            {
                if (line.substr(0, 3) == "END") {
                    break;
                }
                data_.push_back(line);
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
                this->CloseFile();
                return -1;
            }
        }
    } else {
        return -2;
    }
    this->CloseFile();
    return 0;
}

int Data::WriteData() {
    if (this->OpenFile('w')) {
        list<string>::iterator data_ptr = data_.begin();
        for (data_ptr; data_ptr != data_.end(); data_ptr++) {
            *data_file_ << *(data_ptr) << '\n';
        }

        this->CloseFile();

    } else {
        cout << OPEN << ERROR << endl;
        return -1;
    }
    return 0;
}

int Data::OpenFile(char flag) {
    try {
        if (flag == 'w') {
            data_file_ = new fstream(file_name_);
        } else if (flag == 'r')
            data_file_ = new fstream(file_name_);
        else
            __throw_bad_exception();
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    bool open = data_file_->is_open();
    return open;
}

int Data::CloseFile() {
    data_file_->close();
    return 0;
}
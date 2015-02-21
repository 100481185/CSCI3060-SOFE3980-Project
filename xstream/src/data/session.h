class session
{

private:
    string name_;
    bool loggedIn_ = false;
    string type_;

    std::map<int, Data()> transactions;

public:
    string getName() {
        return name_;
    }
    void setName(string name);
    
    bool getloggedIn(){
        return loggedIn_;
    }

    void setloggedIn(bool status);
    
    string getType(){
        return type_;
    }

    void setType(char *type_);

    void commit()
};

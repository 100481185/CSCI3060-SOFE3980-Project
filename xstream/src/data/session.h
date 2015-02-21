class session
{

private:
    string name_;
    bool loggedIn_ = false;
    string type_;

    std::map<int, Data()> transactions;

public:
    void setName(string name);

    void setloggedIn(bool status);

    void setType(char *type_);

    void commit()
};
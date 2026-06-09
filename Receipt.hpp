#include <string>

class Receipt {
    private: 
        std::string transactionDetails;
    public: 
        explicit Receipt(std::string details) : transactionDetails(std::move(details)) {}
        std::string getDetails() const {
            return transactionDetails;
        }
};

Receipt example("Receipt Details Go here");
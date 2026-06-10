#include <string>
#include <iostream>


class BankAccount{
    protected: 
        std::string accountNumber;
        std::string pin; 
        double balance; 
        std::string accountHolderName;
    public: 
        BankAccount(std::string accountNumber, std::string pin, double balance, std::string accountHolderName) : 
            accountNumber(std::move(accountNumber)), 
            pin(std::move(pin)), 
            balance(balance), 
            accountHolderName(std::move(accountHolderName)) {}
        bool validatePin(const std::string& inputPin) const {
            return inputPin == pin;
        }
        double getBalance() const {
            return balance;
        }
        std::string getAccountNumber() const {
            return accountNumber;
        }

        virtual void deposit (double amount) = 0;
        virtual void withdraw (double amount) = 0;
        virtual void printStatement() const = 0;
};

class SavingsAccount : public BankAccount {
    private: 
        double interestRate;
    public:
      using BankAccount::BankAccount;

      void deposit (double amount) override {
          balance += amount;
      }

      void withdraw (double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
            return;
          balance -= amount;
        }
      }
      void addInterest() {
          balance += balance * interestRate;
      }

      void printStatement() const override {
          std::cout << "Savings Account Statement" << std::endl;
          std::cout << "Account Number: " << accountNumber << std::endl;
          std::cout << "Account Holder: " << accountHolderName << std::endl;
          std::cout << "Balance: $" << balance << std::endl;
          std::cout << "Your earnings this month: $" << balance * interestRate << std::endl;
      }

};

class CheckingAccount : public BankAccount {
public:
    using BankAccount::BankAccount;

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
            return;
            balance -= amount;
        }
    }
    void cashOutCheck(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
            return;
            balance -= amount;
        }
    }

    void printStatement() const override {
        std::cout << "Checking Account Statement" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "Your earnings this month: $" << balance * interestRate << std::endl;
    }
};

class CreditAccount : public BankAccount {
private:
    double interestRate;
    double availableCredit;
public:
    using BankAccount::BankAccount;

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
            return;
            balance -= amount;
        }
    }
    void calculateInterest() {
        balance += balance * interestRate;
    }

    void calculateAvailablCredit() {

    }

    void printStatement() const override {
        std::cout << "Credit Account Statement" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};
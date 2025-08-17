#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <array>
#include <limits>
using namespace std;

void waitEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void bankGreeting() {
    cout << "=== Welcome to the Bank Management System ===\n";
    cout << "Hello, valued customer!\n";
    cout << "We are here to serve your banking needs.\n";
}

void bankDataCalculations() {
    cout << "\n=== Bank Data & Calculations ===\n";
    int a = 10;
    double b = 3.5;
    char c = 'X';
    bool flag = true;
    auto sum = a + b;
    cout << "int a = " << a << "\n";
    cout << "double b = " << b << "\n";
    cout << "char c = " << c << "\n";
    cout << "bool flag = " << (flag ? "true" : "false") << "\n";
    cout << "a + b = " << sum << "\n";
    cout << "\nOperations:\n";
    cout << "a * 2 = " << (a * 2) << "\n";
    cout << "b / 2 = " << (b / 2.0) << "\n";
    cout << "a % 3 = " << (a % 3) << "\n";
    cout << "++a -> " << (++a) << "\n";
}

void customerStatusCheck() {
    cout << "\n=== Customer Status Check ===\n";
    int num;
    cout << "Enter an integer: ";
    while(!(cin >> num)) {
        cout << "Please enter a valid integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (num > 0) cout << num << " is positive.\n";
    else if (num < 0) cout << num << " is negative.\n";
    else cout << num << " is zero.\n";
    cout << "Switch example - last digit: ";
    int last = abs(num) % 10;
    switch(last) {
        case 0: cout << "ends with 0\n"; break;
        case 1: cout << "ends with 1\n"; break;
        default: cout << "ends with other digit\n"; break;
    }
}

void transactionProcessingLoop() {
    cout << "\n=== Transaction Processing ===\n";
    cout << "For loop: processing 1..5\n";
    for (int i = 1; i <= 5; ++i) cout << i << " ";
    cout << "\n";
    cout << "While loop: countdown 5..1\n";
    int x = 5;
    while (x > 0) {
        cout << x << " ";
        --x;
    }
    cout << "\n";
    cout << "Do-while loop: repeat until 0\n";
    int y;
    do {
        cout << "Enter 0 to stop, other number to repeat: ";
        while(!(cin >> y)) {
            cout << "Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (y != 0);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int add(int x, int y) { return x + y; }

void bankingFunctions() {
    cout << "\n=== Banking Functions ===\n";
    cout << "Adding amounts 7 and 5: " << add(7,5) << "\n";
    auto greet = [](const string &name = "Guest") {
        cout << "Hello, " << name << "!\n";
    };
    greet("Kareem");
    greet();
}

class Account {
private:
    string owner;
    int accNumber;
    double balance;
public:
    Account(string owner_, int accNumber_, double balance_=0.0)
        : owner(owner_), accNumber(accNumber_), balance(balance_) {}
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    void print() const {
        cout << "Account " << accNumber << " | Owner: " << owner
             << " | Balance: $" << balance << "\n";
    }
};

void accountManagement() {
    cout << "\n=== Account Management ===\n";
    Account a("Alice", 1001, 250.0);
    a.print();
    a.deposit(50); a.print();
    if (a.withdraw(100)) cout << "Withdraw successful\n";
    else cout << "Withdraw failed\n";
    a.print();
}

void bankRecordsStorage() {
    cout << "\n=== Bank Records Storage ===\n";
    int arr[5] = {1,2,3,4,5};
    cout << "C-array elements: ";
    for (int i = 0; i < 5; ++i) cout << arr[i] << " ";
    cout << "\n";
    array<int, 4> a = {10, 20, 30, 40};
    cout << "std::array elements: ";
    for (int v : a) cout << v << " ";
    cout << "\n";
    vector<string> customers = {"Alice","Bob","Charlie"};
    cout << "vector elements: ";
    for (auto &f : customers) cout << f << " ";
    cout << "\n";
}

void customerNameOperations() {
    cout << "\n=== Customer Name Operations ===\n";
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + ", " + s2 + "!";
    cout << "Concatenation: " << s3 << "\n";
    cout << "Length: " << s3.length() << "\n";
    cout << "Substring (7,5): " << s3.substr(7,5) << "\n";
    cout << "Find 'World': " << s3.find("World") << "\n";
}

void transactionHistory() {
    cout << "\n=== Transaction History (Stack) ===\n";
    stack<string> st;
    st.push("Deposit $100");
    st.push("Withdraw $50");
    st.push("Deposit $200");
    cout << "Top: " << st.top() << "\n";
    st.pop();
    cout << "After pop, top: " << st.top() << "\n";
    while (!st.empty()) {
        cout << " - " << st.top() << "\n";
        st.pop();
    }
}

void serviceQueue() {
    cout << "\n=== Service Queue (FIFO) ===\n";
    queue<string> q;
    q.push("Customer 1");
    q.push("Customer 2");
    q.push("Customer 3");
    cout << "First in queue: " << q.front() << "\n";
    while (!q.empty()) {
        cout << "Serving: " << q.front() << "\n";
        q.pop();
    }
}

int main() {
    bankGreeting();
    waitEnter();

    bankDataCalculations();
    waitEnter();

    customerStatusCheck();
    waitEnter();

    transactionProcessingLoop();
    waitEnter();

    bankingFunctions();
    waitEnter();

    accountManagement();
    waitEnter();

    bankRecordsStorage();
    waitEnter();

    customerNameOperations();
    waitEnter();

    transactionHistory();
    waitEnter();

    serviceQueue();
    waitEnter();

    cout << "\n=== Thank you for using the Bank Management System! ===\n";
    return 0;
}

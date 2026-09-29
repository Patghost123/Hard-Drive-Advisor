// Storage Advisor - HDD vs SSD recommendation tool
// Part 2 (C++ Programming) - Innovation Technology Life Cycle project
// Technology: Hard Disk Drive (disruptive innovation: HDD -> SSD)
// Group 12, Section FCI4
//
// Inputs : storage needed (GB), budget (RM), main use, portability
// Outputs: recommended drive, estimated cost, RAMAC (1956) comparison

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

// Price assumptions (RM per GB). Change here to update the whole program.
const double HDD_PRICE = 0.12;
const double SSD_PRICE = 0.35;

// The first hard drive: IBM 350 RAMAC (1956) stored 5 MB.
const double RAMAC_MB = 5.0;
// ---------- Display functions ----------

void showMenu() {
    cout << "\n=========== STORAGE ADVISOR ===========\n";
    cout << "1. Get a storage recommendation\n";
    cout << "2. View price assumptions\n";
    cout << "3. Compare my storage to the 1956 IBM RAMAC\n";
    cout << "4. Exit\n";
    cout << "=======================================\n";
}

void showPrices() {
    cout << fixed << setprecision(2);
    cout << "\n--- Price assumptions (estimates, not live prices) ---\n";
    cout << "HDD : RM " << HDD_PRICE << " per GB\n";
    cout << "SSD : RM " << SSD_PRICE << " per GB\n";
}
double readPositiveNumber(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {                
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a number.\n";
        } else if (value <= 0) {          
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a number greater than 0.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int readChoice(string prompt, int low, int high) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a whole number.\n";
        } else if (value < low || value > high) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please choose between " << low << " and " << high << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

bool readYesNo(string prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (answer == 'y' || answer == 'Y') return true;
        if (answer == 'n' || answer == 'N') return false;
        cout << "  Please type Y or N.\n";
    }
}

void showRamac(double storageGB) {
    double drives = storageGB * 1024 / RAMAC_MB;   // GB -> MB, then divide
    cout << fixed << setprecision(0);
    cout << "\n--- From RAMAC to today ---\n";
    cout << "The first hard drive (IBM RAMAC, 1956) held only 5 MB.\n";
    cout << "To store " << storageGB << " GB you would need about "
         << drives << " RAMAC drives!\n";
}
void recommend() {
    cout << "\n--- Storage Recommendation ---\n";

    // 1. Inputs
    double storageGB = readPositiveNumber("Storage needed (GB): ");
    double budget    = readPositiveNumber("Your budget (RM): ");

    cout << "\nMain use:\n";
    cout << "1. Study / documents\n";
    cout << "2. Gaming\n";
    cout << "3. Video editing\n";
    cout << "4. Backup / archiving\n";
    int use = readChoice("Choose (1-4): ", 1, 4);

    bool portable = readYesNo("Do you need it to be portable? (Y/N): ");

    // 2. Calculate costs
    double hddCost = storageGB * HDD_PRICE;
    double ssdCost = storageGB * SSD_PRICE;

    // 3. Decide (if / else)
    string advice;
    double cost;

    if (budget < hddCost) {
        advice = "Your budget is too low. Reduce the storage or increase the budget.";
        cost = hddCost;
    } else if (use == 1) {                       // study
        if (portable && budget >= ssdCost) {
            advice = "SSD - small, light and shock-resistant.";
            cost = ssdCost;
        } else {
            advice = "HDD - cheapest, and plenty for documents.";
            cost = hddCost;
        }
    } else if (use == 2) {                       // gaming
        if (budget >= ssdCost) {
            advice = "SSD - faster game loading times.";
            cost = ssdCost;
        } else {
            advice = "HDD - fits your budget (SSD is better if you can afford it).";
            cost = hddCost;
        }
    } else if (use == 3) {                       // video editing
        if (budget >= ssdCost + hddCost) {
            advice = "BOTH - SSD for editing, HDD for storing finished videos.";
            cost = ssdCost + hddCost;
        } else if (budget >= ssdCost) {
            advice = "SSD - fast for editing large video files.";
            cost = ssdCost;
        } else {
            advice = "HDD - the most storage for your money.";
            cost = hddCost;
        }
    } else {                                     // backup
        if (portable && budget >= ssdCost) {
            advice = "SSD - portable and durable for backups.";
            cost = ssdCost;
        } else {
            advice = "HDD - best price per GB for large backups.";
            cost = hddCost;
        }
    }

    // 4. Output
    cout << fixed << setprecision(2);
    cout << "\n--- Result ---\n";
    cout << "Storage needed : " << storageGB << " GB\n";
    cout << "Budget         : RM " << budget << "\n";
    cout << "Recommendation : " << advice << "\n";
    cout << "Estimated cost : RM " << cost << "\n";
    cout << "(HDD would cost RM " << hddCost << ", SSD would cost RM " << ssdCost << ")\n";

     showRamac(storageGB);
}


int main() {
    int choice;

    do {
        showMenu();
        choice = readChoice("Enter your choice (1-4): ", 1, 4);

        switch (choice) {
            case 1:
                recommend();
                break;
            case 2:
                showPrices();
                break;
            case 3:
                showRamac(readPositiveNumber("\nStorage to compare (GB): "));
                break;
            case 4:
                cout << "\nThank you for using Storage Advisor. Goodbye!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
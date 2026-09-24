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
int main() {
    showMenu();
    showPrices();
    return 0;
}
// Amanda Taylor //

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

struct MemorySlot {
    unsigned int start;
    unsigned int size;
};

struct Process {
    string id;
    unsigned int size;
};

// Function to convert hex string to integer
unsigned int hexToInt(const string& hexStr) {
    unsigned int value;
    stringstream ss;
    ss << hex << hexStr;
    ss >> value;
    return value;
}

// Function to read input file and parse memory slots and processes
void readInputFile(const string& filename, vector<MemorySlot>& slots, vector<Process>& processes) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    int numSlots;
    file >> numSlots;

    vector<unsigned int> slotStarts(numSlots);
    for (int i = 0; i < numSlots; ++i) {
        string hexAddr;
        file >> hexAddr;
        slotStarts[i] = hexToInt(hexAddr);
    }

    vector<unsigned int> slotSizes(numSlots);
    for (int i = 0; i < numSlots; ++i) {
        string hexSize;
        file >> hexSize;
        slotSizes[i] = hexToInt(hexSize);
    }

    for (int i = 0; i < numSlots; ++i) {
        slots.push_back({slotStarts[i], slotSizes[i]});
    }

    cout << "Number of starting locations of the slots as read from the input file: " << numSlots << endl;
    cout << "\nCurrent slot map:\n";
    for (const auto& slot : slots) {
        cout << "0x" << hex << uppercase << slot.start << " ";
    }
    cout << "\n";
    for (const auto& slot : slots) {
        cout << "0x" << hex << uppercase << slot.size << " ";
    }
    cout << "\n\n";

    int numProcesses;
    file >> numProcesses;
    for (int i = 0; i < numProcesses; ++i) {
        string hexSize;
        file >> hexSize;
        processes.push_back({string(1, 'A' + i), hexToInt(hexSize)});
    }

    cout << "The list of process sizes as read from the input file:\nProcesses:\n";
    for (const auto& process : processes) {
        cout << process.id << " ";
    }
    cout << "\n";
    for (const auto& process : processes) {
        cout << "0x" << hex << uppercase << process.size << " ";
    }
    cout << "\n\n";
}

// First Fit Memory Allocation
void firstFit(vector<MemorySlot>& slots, const vector<Process>& processes) {
    for (const auto& process : processes) {
        cout << "Taking up Process " << process.id << endl;
        bool allocated = false;
        for (auto it = slots.begin(); it != slots.end(); ++it) {
            if (it->size >= process.size) {
                cout << "Slot assignment successful. " << process.id << " - Base location: 0x" << hex << uppercase << it->start << ".\n";
                unsigned int remaining = it->size - process.size;
                it->start += process.size;
                it->size = remaining;
                if (it->size == 0) {
                    slots.erase(it);
                }
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            cout << "\nSlot assignment NOT successful for " << process.id << ".\n";
            cout << "Allocation cannot proceed further\n";
            cout << "Ending the program now...\n";
            return;
        }

        cout << "Current slot map:\n";
        for (const auto& slot : slots) {
            cout << "0x" << hex << uppercase << slot.start << " ";
        }
        cout << "\n";
        for (const auto& slot : slots) {
            cout << "0x" << hex << uppercase << slot.size << " ";
        }
        cout << "\n\n";
    }
    cout << "All processes in the list were successfully allocated memory slots.\n";
}

int main() {
    vector<MemorySlot> slots;
    vector<Process> processes;

    readInputFile("25S_COP4610_Project1_InputFile.txt", slots, processes);
    firstFit(slots, processes);
    return 0;
}
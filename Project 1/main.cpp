#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "memory_manager.h"

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("25S_COP4610_Project1_InputFile.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    // Read number of memory slots
    int numSlots;
    inputFile >> numSlots;

    vector<int> slotStartLocations(numSlots);
    vector<int> slotSizes(numSlots);

    // Read memory slot starting locations (hexadecimal)
    for (int i = 0; i < numSlots; i++) {
        inputFile >> hex >> slotStartLocations[i];
    }

    // Read memory slot sizes (hexadecimal)
    for (int i = 0; i < numSlots; i++) {
        inputFile >> hex >> slotSizes[i];
    }

    // Display the current memory slots
    cout << "This memory manager program allocates slots to processes using the First Fit Dynamic Relocation.\n";
    cout << "\nNumber of starting locations of the slots as read from the input file: " << numSlots << "\n";
    cout << "\nCurrent slot map:\n";
    for (int i = 0; i < numSlots; i++) {
        cout << "0x" << uppercase << hex << slotStartLocations[i] << "  ";
    }
    cout << "\n";
    for (int i = 0; i < numSlots; i++) {
        cout << "0x" << uppercase << hex << slotSizes[i] << "  ";
    }
    cout << "\n\n";

    // Read number of processes
    int numProcesses;
    inputFile >> dec >> numProcesses;

    vector<int> processSizes(numProcesses);

    // Read process sizes (hexadecimal)
    for (int i = 0; i < numProcesses; i++) {
        inputFile >> hex >> processSizes[i];
    }

    // Display process list
    cout << "The list of process sizes as read from the input file:\n";
    char processLabel = 'A';
    for (int i = 0; i < numProcesses; i++) {
        cout << static_cast<char>('A' + i) << "   ";
    }
    cout << "\n";
    for (const auto& process : processSizes) {
        cout << "0x" << uppercase << hex << process << "  ";
    }
    cout << "\n\n";

    // Initialize memory manager
    MemoryManager memoryManager(slotStartLocations, slotSizes);

    // Process allocation using First Fit Algorithm
    for (int i = 0; i < numProcesses; i++) {
        int allocatedAddress = memoryManager.allocateMemory(processSizes[i]);

        if (allocatedAddress != -1) {
            cout << "Taking up Process " << static_cast<char>('A' + i) << "\n";
            cout << "Slot assignment successful. " << static_cast<char>('A' + i) << " - Base location: 0x" << uppercase << hex << allocatedAddress << ".\n";
            cout << "Current slot map:\n";
            memoryManager.displayMemory();
        } else {
            cout << "Allocation failure for Process " << static_cast<char>('A' + i) << ". Cannot find a suitable slot.\n";
            break; // Stop allocation if a process cannot be assigned
        }
    }

    // Check if all processes were allocated
    if (memoryManager.allProcessesAllocated(numProcesses)) {
        cout << "\nAll processes in the list were successfully allocated memory slots.\n";
    }

    return 0;
}



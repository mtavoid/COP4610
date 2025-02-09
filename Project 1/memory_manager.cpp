#include "memory_manager.h"
#include <iostream>
#include <iomanip>

using namespace std;

MemoryManager::MemoryManager(vector<int> startLocations, vector<int> sizes)
    : slotStartLocations(startLocations), slotSizes(sizes), processesAllocated(0) {}

int MemoryManager::allocateMemory(int processSize) {
    for (size_t i = 0; i < slotStartLocations.size(); i++) {
        if (slotSizes[i] >= processSize) {
            int allocatedAddress = slotStartLocations[i];
            slotStartLocations[i] += processSize;
            slotSizes[i] -= processSize;
            if (slotSizes[i] == 0) {
                slotStartLocations.erase(slotStartLocations.begin() + i);
                slotSizes.erase(slotSizes.begin() + i);
            }
            processesAllocated++;
            return allocatedAddress;
        }
    }
    return -1; // Allocation failed
}

void MemoryManager::displayMemory() const {
    for (size_t i = 0; i < slotStartLocations.size(); i++) {
        cout << "0x" << uppercase << hex << slotStartLocations[i] << "  ";
    }
    cout << "\n";
    for (size_t i = 0; i < slotSizes.size(); i++) {
        cout << "0x" << uppercase << hex << slotSizes[i] << "  ";
    }
    cout << "\n\n";
}

bool MemoryManager::allProcessesAllocated(int totalProcesses) const {
    return processesAllocated == totalProcesses;
}

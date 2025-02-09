#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>

class MemoryManager {
private:
    std::vector<int> slotStartLocations;
    std::vector<int> slotSizes;
    int processesAllocated;

public:
    MemoryManager(std::vector<int> startLocations, std::vector<int> sizes);
    int allocateMemory(int processSize);
    void displayMemory() const;
    bool allProcessesAllocated(int totalProcesses) const;
};

#endif

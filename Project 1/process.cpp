#include "process.hpp"
#include <iomanip>

using namespace std;

void printProcesses(const vector<int>& processSizes) {
    cout << "\nProcesses (Size):\n";
    for (size_t i = 0; i < processSizes.size(); i++) {
        cout << "Process " << (char)('A' + i) << ": Size = "
             << hex << uppercase << processSizes[i] << endl;
    }
}

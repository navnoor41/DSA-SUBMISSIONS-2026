#include <iostream>

void towersOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << "\n";
        return;
    }

    towersOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << "\n";
    towersOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_disks = 3;
    
    // A = Source, B = Helper, C = Destination
    towersOfHanoi(num_disks, 'A', 'C', 'B');
    
    return 0;
}

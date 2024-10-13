#include <iostream> //This is for the input and output

using namespace std;

/*Problem 3: Tower of Hanoi problem, where the packages need to be moved from one location to another using a buffer.*/
//The H is the number of packages or disks
//The sourcerod is the rod where the disks are currently located
//The bufferprocess is the rod used to help the process
//The destinationofdisk is the rod where the packages or disks needs to be moved
void towerOfHanoigame(int H, char sourcerod, char bufferprocess, char destinationofdisk){
    //This is the base case where there is one disk, it will be move from the sourcerod to the destinationofdisk
    if (H == 1) {
        cout << "Move the disk 1 from " << sourcerod << " to " << destinationofdisk << endl;
        return;
    }
    //This is the recursive where it move the H-1 disk from the sourcerod to the bufferprocess using the destinationdisk
    towerOfHanoigame(H - 1, sourcerod, destinationofdisk, bufferprocess);
    //This will move the largest disk from the sourcerod to the destinationdisk
    cout << "Move the disk " << H << " from " << sourcerod << " to " << destinationofdisk << endl;
    //This will move the H-1 disk from bufferprocess to the destinationdisk 
    towerOfHanoigame(H - 1, bufferprocess, sourcerod, destinationofdisk);
}

int main() {
    int H; //This is the number of disk
    cout << "Enter the number of Disks: "; //This is where the user will be ask to enter the number of disk for the tower of Hanoi
    cin >> H;

    //This is where it displays the sequence of moves that is required to solve the problem of the Tower of Hanoi
    cout << "The sequence of moves required to move " << H << " packages:\n";
    //L is the sourcerod
    //A is the bufferprocess
    //Y is the destinationdisk
    towerOfHanoigame(H, 'L', 'A', 'Y');  

    //This will display and calculate the total moves
    int totalMovesUsed = (1 << H) - 1;  
    cout << "Total number of moves: " << totalMovesUsed << endl;

    return 0; //It will return to 0 if it the program success in executing or there is no errors
}



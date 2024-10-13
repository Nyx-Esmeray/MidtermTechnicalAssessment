#include <iostream> //This is for the input and output
#include <vector> //This is for dynamic arrays
#include <cmath> //This is for mathematical functions like the square root(sqrt) and power (pow)

using namespace std;

/*Problem 1: Calculating the total distance between delivery points*/
/*This function takes the two delivery points but it takes as a coordinates
then it will calculate the distance between those two points*/
double calculatingtheDistance(pair<int, int> point_delivery1, pair<int, int> point_delivery2) {
    //Caculate the distance of the two points using this Euclidean formula
    double distance = sqrt(pow(point_delivery2.first - point_delivery1.first, 2) + pow(point_delivery2.second - point_delivery1.second, 2));
    return distance;
}

int main() {
    int D; //D: is the varibale where it store the number of delivery points
    cout << "---------------Welcome to the Program---------------" << endl;
    cout << "Enter number of Delivery Points: "; //This will ask the user to enter the deliver points
    cin >> D; //This will get the number of delivery points that the user entered

    //This will check if the user entered two points, since it will need at least 2 points to calculate the distance
    if (D < 2) {
        cout << "Two points are required to calculate the distance!" << endl;
        return 1; //This will exit the program if the user enters below 2 points
    }

    //Creating a vector where it will store the delivery points as pairs of a and b coordinates
    vector<pair<int, int>> points(D);
    cout << "Enter Coordinates of the Delivery Points (a, b): " << endl; //This will ask the user to enter the deliver points coordinates and should be separated by a comma
    //This loop is to get the coordinates of each delivery points that the user entered
    for (int d = 0; d < D; d++) {
        cin >> points[d].first >> points[d].second;
    }

    double totalDistanceoftheCoordinates = 0.0; //The totalDistanceoftheCoordinates is a variable where it store the total Distance 
    //This will calculate the total distance by adding or summing the distances between the two points
    for (int d = 0; d < D - 1; d++) {
        totalDistanceoftheCoordinates += calculatingtheDistance(points[d], points[d + 1]);
    }

    //This will calculate the sum of the first D Natural numbers using the formula below 
    int sumoftheNaturalNumbers = (D * (D + 1)) / 2;
    //This will output the total distance between the two points
    cout << "Total Distance: " << totalDistanceoftheCoordinates << endl;
    //This will output the sum of the first D Natural numbers 
    cout << "Sum of the First " << D << " Natural Numbers: " << sumoftheNaturalNumbers << endl;
    cout << "---------------------------------------------------" << endl;

    return 0; //It will return to 0 if it the program success in executing or there is no errors
}

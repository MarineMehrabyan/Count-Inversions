#include <fstream>
#include <iostream>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++) {
        int count_I = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                count_I++;
                inv_count++;
        }
        cout << arr[i] << " is  inversion " << count_I << " times \n";
    }

    return inv_count;
}

int main()
{
    string filename("input.txt");
    int number;
    int arr[100000] = {};

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"<< filename << "'" << endl;
        return EXIT_FAILURE;
    }

    int index = 0;

    while (input_file >> number) {
        cout << number << "  ";
       arr[index++] = number;
    }
    cout << endl;
    input_file.close();   


    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\n Number of inversions are " << getInvCount(arr, n)<<endl;
    return 0;
}

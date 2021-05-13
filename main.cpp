/* Panopto Lecture Captions Project
 Created by: Jessamyn Lopez
 Project originally completed: 2/15/2021
 Last updated completed: 5/12/2021
 Project Description: Inspired by my archaeology class.
 This C++ program takes a .txt file filled with the captions from a Panopto Lecture and
 generates a new .txt file that removes time stamps and newlines from the old .txt file.
 */

// Standard libraries necessary for file input/output stream and using strings
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // File containing text from Panopto
    string fileName = "C:\\Users\\jlope81\\CLionProjects\\anthlectures\\old.txt";
    // Variable to hold text of current line taken from old.txt
    string line;
    // Keeps track of which line of old.txt program has run through
    int lineCounter = 0;

    ifstream inFile(fileName);
    // Open file and if not properly opened then give error message
    if(!inFile.is_open()){
        cout << "Invalid file" << endl;
        exit(1);
    }
    cout << "File opened successfully." << endl;

    // Create new.txt file for cleaned up text
    ofstream outFile ("new.txt");

    while(!inFile.eof()){
        // Store line from old.txt in string line variable
        getline(inFile, line, '\n');
        if(!inFile.fail()){
            // Update line counter to keep track of even and odd lines
            lineCounter++;
            // If line is odd, meaning it doesn't contain a time stamp, then add to new.txt file
            if(lineCounter % 2 != 0){
                outFile << line << " ";
            }
        }
    }
    // Once file is completed output success message and close file
    cout << "Completed new file";
    outFile.close();
    return 0;
}
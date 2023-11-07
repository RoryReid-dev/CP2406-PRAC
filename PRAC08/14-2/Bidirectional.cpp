#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <stdexcept> // Include the <stdexcept> header for runtime_error.

using namespace std;

// Throws runtime_error on error.
void changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
    // Trigger exceptions intentionally
    try {
        // Trigger exception when the file doesn't exist
        changeNumberForID("nonexistent.txt", 263, "415-555-3333");
    } catch (const exception& caughtException) {
        cerr << "Exception 1: " << caughtException.what() << endl;
    }

    try {
        // Trigger exception when failing to open the file (read-only file)
        changeNumberForID("readonly.txt", 263, "415-555-3333");
    } catch (const exception& caughtException) {
        cerr << "Exception 2: " << caughtException.what() << endl;
    }

    try {
        // Trigger exception when seeking to an invalid position (empty file)
        changeNumberForID("empty.txt", 263, "415-555-3333");
    } catch (const exception& caughtException) {
        cerr << "Exception 3: " << caughtException.what() << endl;
    }

    try {
        // Trigger exception when writing to the file fails (read-only file)
        changeNumberForID("read-only.txt", 263, "415-555-3333");
    } catch (const exception& caughtException) {
        cerr << "Exception 4: " << caughtException.what() << endl;
    }
}

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
    fstream ioData{ filename.data() };
    if (!ioData) {
        throw runtime_error{ "Error while opening file " + string(filename) };
    }

    // Loop until the end of file
    while (ioData) {
        // Read the next ID.
        int idRead;
        ioData >> idRead;
        if (!ioData)
            break;

        // Check to see if the current record is the one being changed.
        if (idRead == id) {
            // Seek the write position to the current read position.
            ioData.seekp(ioData.tellg());
            if (!ioData) {
                throw runtime_error{ "Failed to seek to the proper position in the output stream." };
            }
            // Output a space, then the new number.
            ioData << " " << newNumber;
            if (!ioData) {
                throw runtime_error{ "Failed to write to the output stream." };
            }
            break;
        }

        // Read the current number to advance the stream.
        string number;
        ioData >> number;
        if (!ioData) {
            throw runtime_error{ "Failed to read the next number from the input stream." };
        }
    }
}

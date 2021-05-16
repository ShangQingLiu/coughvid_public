#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;

    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ',')) {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({ colname, std::vector<int> {} });
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}

void create()
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("reportcard.csv", ios::out | ios::app);

	cout << "Enter the details of 5 students:"
		<< " roll name maths phy chem bio" << endl;

	int i, roll, phy, chem, math, bio;
	string name;

	// Read the input
	for (i = 0; i < 5; i++) {

		cin >> roll;
		cin >> math;
		cin >> phy;
		cin >> chem;
		cin >> bio;

		// Insert the data to file
		fout << roll << ", "
			<< math << ", "
			<< phy << ", "
			<< chem << ", "
			<< bio
			<< "\n";
	}
}

void read_record()
{

	// File pointer
	fstream fin;

	// Open an existing file
	fin.open("data.csv", ios::in);

	// Get the roll number
	// of which the data is required
	int rollnum, roll2, count = 20;
	std::string::size_type sz = 32;

	// Read the Data from the file
	// as String Vector
	vector<float> row;
	string line, word, temp;

	while (fin >> temp) {

		row.clear();

		// read an entire row and
		// store it in a string variable 'line'
		getline(fin, line);

		// used for breaking words
		stringstream s(line);

		// read every column data of a row and
		// store it in a string variable, 'word'
		while (getline(s, word, ',')) {

			// add all the column data
			// of a row to a vector
			row.push_back(std::stof(word,&sz));
		}

	
	}
	for (auto i = row.begin(); i != row.end(); ++i)
		std::cout << *i << ' ';
	if (count == 0)
		cout << "Record not found\n";
}

int main() {
	//create();
	read_record();

	return 0;
}

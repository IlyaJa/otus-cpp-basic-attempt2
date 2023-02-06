#include <iostream>
#include <fstream>
#include <string>
#include "check_value.h"


int write_data(std::string file_name);
int extract_data(std::string file_name);

int main(int argc, char *argv[]) {

	std::string high_scores_filename = "high_scores.txt";	
	if(argc>1)	
	{		std::string value_argv=argv[1];
		if(value_argv=="table")
			{	extract_data(high_scores_filename);
			return 0;	}		
	}
	
	write_data(high_scores_filename);
	extract_data(high_scores_filename);		

	return 0;
}


int write_data(std::string file_name)
{
    std::string user_name;
	std::ofstream out_file{file_name, std::ios_base::app};

	std::cout << "Hi! Enter your name, please:" << std::endl;	
	std::cin >> user_name;

	int attempts_count = check_value();	

	if (std::cin.fail()) {
		std::cout << "Bad value!" << std::endl;
		return -1;
	}
	if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << file_name << "!" << std::endl;
			return -1;
		}
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;

		return 0;
}

int extract_data(std::string file_name)
{
	std::ifstream in_file{file_name};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
		return 0;
	}



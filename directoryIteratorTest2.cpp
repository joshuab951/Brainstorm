#include <string>
#include <iostream>
#include "dirent.h"

using namespace std;

int main()
{
	DIR *dir;
	struct dirent *ent;
	
	if ((dir = opendir ("\\lists\\")) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			cout << ent->d_name << endl;
		}
		closedir(dir);
	}
	else
	{
		perror ("");
		return EXIT_FAILURE;
	}
	return (0);
}

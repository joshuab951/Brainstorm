#include <string>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem::v1;

int main()
{
	string path = "/lists";
	for (auto & p : fs::directory_iterator(path))
		cout << p << endl;
}

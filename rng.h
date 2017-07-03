using namespace std;

class rng
{
	public:
		// Constructors
		// Default constructor
		rng();
		rng(int lowLimitSet, int highLimitSet);
	
		int generateNumber(); // Generate the random number.	
	private:
		int lowLimit; // The random number cannot be lower than this number.
		int highLimit; // The random number cannot be higher than this number.
		int randomNumber; // This variable stores the random number.
};

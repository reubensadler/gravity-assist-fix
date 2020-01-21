#include <iostream>
#include <vector>

void fillArray(std::vector<int>& array)
{
	std::cout << "Input data: ";
	int value{};
	while (std::cin >> value)		//put all data into the array
	{
		array.push_back(value);		//put current value at the end of the array
	}
}
int determineInput(const std::vector<int>& array)
{
	std::vector<int> tempArray;

	int addressMax{ static_cast<int>(array.size()) };

	//the "noun" is the value in address 1, the "verb" is the value in address 2
	//required to determine the noun and verb to complete the task
	int noun{ 0 };
	int verb{ 0 };

	//try all combinations of nouns and verbs until the program outputs 19690720
	for (noun; noun < 100; noun++)
	{
		verb = 0;
		for (verb; verb < 100; verb++)
		{
			int addressCount{ 0 };	//every iteration starts at address 0
			tempArray = array;		//the following code will alter the values in tempArray, so reset for each iteration
			tempArray[1] = noun;	//insert the noun and verb into code
			tempArray[2] = verb;
			
			for (addressCount; addressCount + 3 < addressMax; addressCount += 4)
			{
				int opCode{ tempArray[addressCount] };	//determines what action to take with three successive values (parameters)
				int parameter1{ tempArray[addressCount + 1] };
				int parameter2{ tempArray[addressCount + 2] };
				int parameter3{ tempArray[addressCount + 3] };

				switch (opCode) {
					case (1) :
						tempArray[parameter3] = tempArray[parameter1] + tempArray[parameter2];
						break;

					case (2) :
						tempArray[parameter3] = tempArray[parameter1] * tempArray[parameter2];
						break;

					case (99) :
						if (tempArray[0] == 19690720)
						{
							std::cout << "\nFound input noun and verb that output 19690720. Noun is " << noun << " and verb is " << verb << '\n';
							return 0;
						}
						break;
					default :
						std::cout << "\nEncountered invalid opcode. Only opcodes 1, 2 and 99 are allowed. Check code and input data\n";
						return 0;
				}
			}
		}
	}
	std::cout << "\nSolution not found. Check code and input data. \n";
	return 0;
}

int main()
{
	std::vector<int> array;
	fillArray(array);
	
	determineInput(array);

	return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
	int array[999] = { 0 };
	int tempArray[999];
	std::copy(std::begin(array), std::end(array), std::begin(tempArray));
	int i{ 0 };

	std::cout << "input data: ";
	while (i < 153)
	{
		std::cin >> array[i];
		i++;
	}
	int noun{ 0 };
	int verb{ 0 };

	for(noun; noun < 100; noun++)
	{
		verb = 0;
		for (verb; verb < 100; verb++)
		{
			std::cout << noun << " , " << verb << '\n';
			std::copy(std::begin(array), std::end(array), std::begin(tempArray));
			i = 0;
			tempArray[1] = noun;
			tempArray[2] = verb;
			int opCode{};
			int address1{};
			int address2{};
			int address3{};
			while (i < 153)
			{
				opCode = tempArray[i];
				if (tempArray[i] == 1)
				{
					address1 = tempArray[i + 1];
					address2 = tempArray[i + 2];
					address3 = tempArray[i + 3];
					if (address3 > 153)
					{
						i=153;
					}
					else
						tempArray[address3] = tempArray[address1] + tempArray[address2];
					//std::cout << "(sum) array" << x << " = " << array[x] << '\n';

				}
				if (tempArray[i] == 2)
				{
					address1 = tempArray[i + 1];
					address2 = tempArray[i + 2];
					address3 = tempArray[i + 3];
					if (address3 > 153)
					{
						i=153;
					}
					else
						tempArray[address3] = tempArray[address1] * tempArray[address2];
					//std::cout << "(product) array" << x << " = " << array[x] << '\n';
				}
				if (tempArray[i] == 99)
				{
					if (tempArray[0] == 19690720)
					{
						std::cout << "output: " << tempArray[0] << '\n';
						return 0;
					}
				}
				i = i + 4; 
			}
		}
	}


	return 0;
}
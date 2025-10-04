/**
	 * Class Name:		CollatzSolver.cpp
	 * Description:		Iterates on the Collatz Conjecture for large integers using Boost Multiprecision library. Will stop running when it finds a number that disproves the conjecture.
	 * Author:			Duncan Wade
	 * Date:			October 4th, 2025
*/

#include <iostream>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

// Safety limit to prevent runaway sequences (arbitrarily chosen)
const long long MAX_ITERATIONS = 1000000;

int main() {
	//this is the largest number tested for the collatz conjecture according to wikipedia
	//2,361,183,241,434,822,606,848, or 2^71 ~= 2.361e21
	cpp_int startingNumber = 1;
	startingNumber <<= 71;//bit shift left by 71 is equivalent to multiplying by 2^71, this is fastest way to do it
	
	while (true) {
		cpp_int n = startingNumber;
		long long iteration_count = 0;

		// Use a set to detect non-trivial cycles
		unordered_set<cpp_int> visited_numbers;

		cout << "Starting number: " << n << endl;

		while (n != 1) {//conjecture always ends at 1, so this detects if the number proves the conjecture
			if (visited_numbers.count(n)) {//count() checks if we've seen this number before. If we have, we have a non 4-2-1 cycle.
				cout << "Detected a cycle starting with number " << startingNumber << ". Sequence does not terminate." << endl;
				return 0;
			}

			visited_numbers.insert(n);//add current number to set of seen numbers, otherwise this whole thing won't work

			if (iteration_count++ >= MAX_ITERATIONS) {//detects if sequence is going on forever, and since we detect if we reach 1, we can assume it is not a 4-2-1 cycle
				cout << "Exceeded maximum iterations for starting number " << startingNumber << ". Possible non-terminating sequence." << endl;
				return 0;
			}

			//collatz conjecture step
			if (n % 2 == 0) {//even
				n /= 2;
			}
			else {//odd
				n = (3 * n + 1) / 2;//as 3x-1 will always be even, automatically dividing by 2 saves time
			}

			cout << "Current number: " << n << endl;
		}

		startingNumber++;//iterate to test next number
		cout << "Reached 1, moving to next starting number." << endl;

	}

	return 0;
}

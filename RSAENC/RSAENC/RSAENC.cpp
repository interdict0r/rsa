#include <iostream>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {

	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {

	double m, p, q, e{}, i, d;
	int fl;

	std::cout << "enter the number to be encrypted/decrypted\n";
	std::cin >> m;

	std::cout << "enter the first prime number: \n";
	std::cin >> p;

	std::cout << "enter the second prime number: \n";
	std::cin >> q;

	int n = p * q;
	int phi = (p - 1) * (q - 1);

	for (i = 2; i < phi; i++) {

		if (gcd(i, phi) == 1) {
			e = i;
			break;
		}
	}

	i = 1;
	while (true) {

		int j = (phi * i) + 1;
		if (fmod(j, e) == 0) {
			d = j / e;
			break;
		}
		i++;
	}

	std::cout << "value of phi: " << phi << '\n';
	std::cout << "value of d: " << d << '\n';
	std::cout << "value of e: " << e << '\n';
	std::cout << "public encryption key: (" << e << " , " << n << ") " << '\n';
	std::cout << "private decryption key: (" << d << " , " << n << ") " << '\n';

	int cipher = fmod(pow(m,e), n);
	std::cout << "encrypted ciphertext: " << cipher << '\n';

	int plain = fmod(pow(cipher, d), n);
	std::cout << "encrypted plaintext: " << plain << '\n';

	return EXIT_SUCCESS;
}
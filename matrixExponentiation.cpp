#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

class matrix {
public:
	ll a[2][2];
	matrix(): a{{1, 1}, {1, 0}} {}
};

ll fibonacci(ll n);
matrix matrixMul(matrix m1, matrix m2);
std::vector<ll> break_powers(ll n);
ll powers(ll n);

int main() {
	ll n{};
    std::cout << "Enter n : ";
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;

	return 0;
}

ll fibonacci(ll n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	std::vector <ll> nums;
	nums = break_powers(n - 1);

	std::vector <matrix> matrices(nums[0] + 1);
	for (auto i = 1; i < matrices.size(); ++i) {
		matrices[i] = matrixMul(matrices[i - 1], matrices[i - 1]);
	}

	matrix resultMatrix{ matrices[nums[0]] };
	for (auto i = 1; i < nums.size(); ++i) {
		resultMatrix = matrixMul(resultMatrix, matrices[nums[i]]);
	}

	return resultMatrix.a[0][0];
}

matrix matrixMul(matrix m1, matrix m2) {
	matrix m3;
	ll sum{};
	for (auto i = 0; i < 2; ++i) {
		for (auto j = 0; j < 2; ++j) {
			sum = 0;
			for (auto k = 0; k < 2; ++k) {
				sum += (m1.a[i][k] % 100)* (m2.a[k][j] % 100);
			}
			m3.a[i][j] = sum % 100;
		}
	}
	return m3;
}

std::vector<ll> break_powers(ll n) {
	std::vector <ll> nums;
	ll curr{1}, prev{1};
	while (n > 0) {
		if (n - curr > 0) {
			prev = curr;
			curr *= 2;
		}
		else if (n - curr == 0) {
			n -= curr;
			nums.push_back(powers(curr));
			curr = prev = 1;
		}
		else {
			n -= prev;
			nums.push_back(powers(prev));
			curr = prev = 1;
		}
	}
	return nums;
}

ll powers(ll n) {
	ll k{};
	while (n > 1) {
		n /= 2;
		k++;
	}
	return k;
}

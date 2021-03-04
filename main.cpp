#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

bool is_prime(int n) {
	if (n == 1) {
		return false;
	}
	for (auto i = 2; i <= sqrt(n); ++i) {
		if (n % 1 == 0)
			return false;
	}
	return true;
}

int main() {
	std::vector<int> v_1(10, 0);
	int num;
	std::default_random_engine dre;
	std::uniform_int_distribution<int> smth(1, 10);
	std::uniform_int_distribution<int> smth_else(1, 10000000);
	for (auto i = 0U; i < 10; ++i) {/// 1) создали и заполнили П1
		v_1[i] = smth(dre);
	}
	std::cout << "The first sequence (volume 1): ";
	for (auto i = 0U; i < 10; ++i) {
		std::cout << v_1[i] << ", ";
	}
	std::cout << std::endl;

	std::cout << "Input 5 numbers: ";
	for (auto i = 0U; i < 5; ++i) {/// 2) положили в конец П1 еще 5 чиселок
		std::cin >> num;
		v_1.push_back(num);
	}
	std::cout << "\nThe first sequence (volume 2): ";
	std::cout << std::endl;
	for (auto i = 0U; i < 15; ++i) {
		std::cout << v_1[i] << ", ";
	}
	std::cout << std::endl;

	std::shuffle(std::begin(v_1), std::end(v_1), dre); // 3) перемешали случайным образом
	std::cout << std::endl;
	std::cout << "The first sequence (volume 3): ";
	for (auto i = 0U; i < 15; ++i) {
		std::cout << v_1[i] << ", ";
	}
	std::cout << std::endl;

	std::sort(std::begin(v_1), std::end(v_1)); // 4) удалили одинаковые элементы
	auto last = std::unique(v_1.begin(), v_1.end());
	v_1.erase(last, v_1.end());
	std::cout << std::endl;
	std::cout << "The first sequence (volume 4): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last); ++i) {
		std::cout << v_1[i] << ", ";
	}
	std::cout << std::endl;

	int count = std::count_if(std::begin(v_1), std::end(v_1), [](int elem) {return (elem % 2) == 1; });
	std::cout << std::endl << "Number of odd numbers: " << count << std::endl;

	auto mm = std::minmax_element(std::begin(v_1), std::end(v_1)); // 6) определяем наименьший mm.first и наибольший mm.second элементы
	std::cout << "Min: " << *mm.first << "		Max: " << *mm.second << std::endl;

	auto prime = find_if(std::begin(v_1), std::end(v_1), is_prime); // 7) нашли нечетное число(или не нашли)
	if (prime != std::end(v_1)) {
		std::cout << *prime << " is prime" << std::endl;
	}
	else {
		std::cout << "There is none of odd numbers" << std::endl;
	}

	std::transform(std::begin(v_1), std::end(v_1), std::begin(v_1), // 8) возвели в квадрат
		[](int elem) {
			return elem * elem;
		});
	std::cout << "\nThe first sequence (volume 5): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last); ++i) {
		std::cout << v_1[i] << ", ";

	}
	std::cout << std::endl;

	std::vector<int> v_2(10);

	for (auto i = 0U; i < 10; ++i) {/// 9) создали и заполнили П2
		v_2[i] = smth_else(dre);
	}
	std::cout << "The second sequence (volume 1): ";
	for (auto i = 0U; i < 10; ++i) {
		std::cout << v_2[i] << ", ";
	}
	std::cout << std::endl;

	auto sum = std::accumulate(std::begin(v_2), std::end(v_2), 0);// 10) сумма всех
	std::cout << "Sum: " << sum << std::endl;

	std::fill_n(std::begin(v_2), 3, 1);// 11) заменили 3 первых чиселки на 1
	std::cout << "The second sequence (volume 2): ";
	for (auto i = 0U; i < 10; ++i) {
		std::cout << v_2[i] << ", ";
	}
	std::cout << std::endl;


	std::vector <int> v_3;
	std::transform(std::begin(v_1), std::end(v_1), std::begin(v_2), std::back_inserter(v_3), [](int v_1, int v_2)  //12) вычли вторую последовательность из первой
		{return v_1 - v_2; }); //12) вычли вторую последовательность из первой
	std::cout << "The third sequence (volume 1): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last); ++i) {
		std::cout << v_3[i] << ", ";
	}
	std::cout << std::endl;


	std::replace_if(std::begin(v_3), std::end(v_3), [](int elem)
		{return elem < 0; }, 0); // 13) заменили отрицательные элементы нулем
	std::cout << "The third sequence (volume 2): ";
	int quantity_of_zero = 0;
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last); ++i) {
		std::cout << v_3[i] << ", ";
		if (v_3[i] == 0)
			quantity_of_zero++;

	}
	std::cout << std::endl;

	v_3.erase(std::remove(std::begin(v_3), std::end(v_3), 0), std::end(v_3)); // 14) удалили нулевые элементы
	std::cout << "The third sequence (volume 3): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last) - quantity_of_zero; ++i) {
		std::cout << v_3[i] << ", ";
	}
	std::cout << std::endl;


	std::reverse(std::begin(v_3), std::end(v_3)); // 15) развернули последовательность
	std::cout << "The third sequence (volume 4): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last) - quantity_of_zero; ++i) {
		std::cout << v_3[i] << ", ";
	}
	std::cout << std::endl;


	std::nth_element(std::begin(v_3), std::end(v_3) - 3, std::end(v_3)); // 16) вырезали три самых больших элемента и засунули их в конец
	std::cout << "The third sequence (volume 2): ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last) - quantity_of_zero; ++i) {
		std::cout << v_3[i] << ", ";
	}
	std::cout << std::endl;


	std::sort(std::begin(v_1), std::end(v_1)); //17) просто сортировка П1 и П2
	std::sort(std::begin(v_2), std::end(v_2));
	std::cout << "Sort the first sequence: ";
	for (auto i = 0U; i < sizeof(v_1) - sizeof(last); ++i) {
		std::cout << v_1[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "Sort the second sequence: ";
	for (auto i = 0U; i < 10; ++i) {
		std::cout << v_2[i] << ", ";
	}
	std::cout << std::endl;



	std::vector <int> v_4;
	std::merge(std::begin(v_1), std::end(v_1), std::begin(v_2), std::end(v_2), std::back_inserter(v_4)); // 18) слили 2 отсортированнын последовательности
	std::cout << "The fourth sequence (volume 1): ";
	for (auto i = 0U; i < sizeof(v_4); ++i) {
		std::cout << v_4[i] << ", ";
	}
	std::cout << std::endl;

	auto ed = std::equal_range(std::begin(v_4), std::end(v_4), 1);
	std::cout << "1 could get position " << *ed.first + 1 << " up to " << *ed.second + 1 << std::endl; //19) не уверен, что правильно понял задание, но вроде это
	return 0;
}
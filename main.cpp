#include <iostream>
#include <data_structures/data_structures.h>
#include <fstream>
#include <set>
#include <chrono>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <future>
#include <limits>
#include <numeric>
#include <execution>
#include <random>
#include <algorithm>
using namespace std;

struct Stopwatch
{
    Stopwatch(std::chrono::nanoseconds &result) : result{result}, start{chrono::high_resolution_clock::now()} {}

    ~Stopwatch()
    {
        result = chrono::high_resolution_clock::now() - start;
    }

private:
    chrono::nanoseconds &result;
    const chrono::time_point<chrono::high_resolution_clock> start;
};

template <typename T>
vector<T> factorize(T x)
{
    vector<T> result{1};

    for (T candidate{2}; candidate <= x; candidate++)
    {
        if (x % candidate == 0)
        {
            result.push_back(candidate);
            x /= candidate;
            candidate = 1;
        }
    }

    return result;
}

string factor_task(unsigned long long x){
    chrono::nanoseconds elapsed_ns;
    vector<unsigned long long> factors;
    {
        Stopwatch stopwatch{ elapsed_ns};
        factors = factorize(x);
    }

    const auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
    stringstream ss;
    ss << elapsed_ms << "ms: Factoring " << x << " ( ";
    for(auto factor : factors)
        ss << factor << " ";
    ss << ")\n";

    return ss.str();
}

array<unsigned long long, 7> numbers{9'699'690, 179'426'549, 1'000'000'007, 4'294'967'291, 4'294'967'296, 1'307'674'368'000, 4'000};

void funcOne(){
    chrono::nanoseconds elapsed_ns;
    {
        Stopwatch stopwatch{elapsed_ns};
        vector<future<string>> factor_tasks;
        for (auto number : numbers)
            factor_tasks.emplace_back(async(launch::async, factor_task, number));
        for (auto &task : factor_tasks)
            cout << task.get();
    }
    const auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
    cout << elapsed_ms << "ms : total program time\n";
}

vector<long> make_random_vector(){
    vector<long> numbers(1'000'000'000);
    iota(numbers.begin(), numbers.end(), 0);
    mt19937_64 urng{121216};
    shuffle(numbers.begin(), numbers.end(), urng);
    return numbers;
}

void funcTwo(){
    cout << "Constructing random vectors...";
    auto numbers_a = make_random_vector();
    auto numbers_b{ numbers_a };
    chrono::nanoseconds time_to_sort;
    cout << " " << numbers_a.size() << " elements.\n";
    cout << "Sorting with execution::seq...";
    {
        Stopwatch stopwatch{ time_to_sort };
        sort(execution::seq, numbers_a.begin(), numbers_a.end());
    }
    cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";

    cout << "Sorting with execution::par...";
    {
        Stopwatch stopwatch{ time_to_sort };
        sort(execution::par, numbers_b.begin(), numbers_b.end());
    }
    cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";
}



int main()
{
    // funcOne();
    funcTwo();

    return 0;
}
#include <cstdlib>
#include <cstdint>
#include <type_traits>
#include <iterator>
#include <array>
#include <chrono>
#include <algorithm>

template <int trials, typename Function>
std::array<std::pair<std::chrono::high_resolution_clock::duration, typename std::result_of<Function&&()>::type>, trials> benchmark(Function&& f) {
  std::array<std::pair<std::chrono::high_resolution_clock::duration, decltype(f())>, trials> results;
  std::generate(results.begin(), results.end(), [&f]() {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::make_pair(end - start, result);
  });
  return results;
}

#include <vector>
#include <numeric>

template <typename Iterator>
Iterator median(Iterator begin, Iterator end) {
  std::vector<decltype(begin)> lifted(std::distance(begin, end));
  std::iota(lifted.begin(), lifted.end(), begin);
  std::sort(lifted.begin(), lifted.end(), [](decltype(begin) a, decltype(begin) b) {
    return *a < *b;
  });
  auto med = lifted.begin() + lifted.size() / 2;
  return med == lifted.end() ? end : *med;
}

template <typename ToRep = double, typename Duration>
std::chrono::duration<ToRep> as_seconds(Duration duration) {
  return std::chrono::duration<ToRep, typename Duration::period>{duration};
}

#include <iostream>
#include <limits>
#include <iomanip>
#include <numeric>
#include <cmath>

template <int trials, typename Function>
void pretty_benchmark(std::string name, Function&& f, std::ostream& out = std::cout) {
  auto results = benchmark<trials>(std::forward<Function>(f));
  auto med = median(results.begin(), results.end());
  out << std::fixed << std::setprecision(3);
  out << name << ", ";
  decltype(as_seconds(med->first)) sum;
  for (auto& result: results) {
    auto [elapsed, ans] = result;
    sum += as_seconds(elapsed);
    if (&result == &*med) {
      out << "*";
    }
    out << as_seconds(elapsed).count() << ", ";
  }
  out << "sum: " << sum.count() << ", ";
  auto mean = sum.count() / trials;
  decltype(mean) sumsqerr;
  for (auto [elapsed, ans]: results) {
    auto err = as_seconds(elapsed).count() - mean;
    sumsqerr += err * err;
  }
  auto variance = sumsqerr / (trials == 1 ? 1 : trials - 1);
  auto stddev = std::sqrt(variance);
  out << "mean: " << mean << " ± " << stddev << ",";
  //out << " ans: " << med->second;
  out << "\n";
}

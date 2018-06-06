#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template<typename ForwardIterator> void counting_sort(ForwardIterator begin,
                                                      ForwardIterator end) {
  auto min_max = std::minmax_element(begin, end);
  if (min_max.first == min_max.second) {  // empty range
    return;
  }
  auto min = *min_max.first;
  auto max = *min_max.second;
  std::vector<unsigned> count((max - min) + 1, 0u);
  for (auto i = begin; i != end; ++i) {
    ++count[*i - min];
  }
  for (auto i = min; i <= max; ++i) {
    for (auto j = 0; j < count[i - min]; ++j) {
      *begin++ = i;
    }
  }
}

const int Min = -100;
const int Max = 100;
const int N = 50;

int main() {
    srand(time(0));

    int a[N];
    for(int i = 0; i < N; i++){
        a[i] = Min + (rand() % (Max - Min + 1));
        std::cout << a[i] << ' ';
    }
    std::cout << "\n\n\t Sorting..... \n\n";
    counting_sort(std::begin(a), std::end(a));
    copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

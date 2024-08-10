#include <bits/stdc++.h>

#ifdef DEBUG
#include "debug.cc"
#define cout cerr
#else
#define debug(...) ""
#endif


using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vvi = std::vector<std::vector<int>>;
using vvll = std::vector<std::vector<ll>>;

ll n, l, r;

template <typename T>
void read_array(std::vector<T>& vec, size_t size);

ll helper()
{
  return 0;
}

void solve(size_t test_num)
{
  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> arr(n), arr_;
  read_array(arr, n);

  std::transform(arr.begin(), arr.end(), std::back_inserter(arr_), [k](ll e){ return e % k; });
  auto end = std::unique(arr_.begin(), arr_.end());
  auto t = *max_element(arr.begin(), arr.end());
  for (auto it = arr_.begin(); it <= end; it++){
    auto check = [t, k, arr](ll e) { return (t- e - 2*k*((t-e)/(2*k))) < k; };
    if (std::all_of(arr.begin(), arr.end(), check)){
      std::cout << t << std::endl;
      return;
    }
    t += *it;
  }

  std::cout << -1 << std::endl;
  
}

int main(void)
{
  size_t test_num;
  std::cin >> test_num;
  for (size_t i=1; i<= test_num; i++)
    solve(i);
  return EXIT_SUCCESS;
}


template <typename T>
void read_array(std::vector<T>& vec, size_t size)
{
  vec = std::vector<T>(size);
  for (size_t i=0; i<size; i++)
    std::cin >> vec[i];
}

// Project Euler: 60
// Prime Pair Sets

#include "helper.h"

using Int_T = unsigned long long;

bool is_concat_prime(const Int_T num1, const Int_T num2) {
  const auto num1_str = std::to_string(num1);
  const auto num2_str = std::to_string(num2);

  const auto concat_num_1_str = num1_str + num2_str;
  const auto concat_num_2_str = num2_str + num1_str;

  const auto concat_num_1 = std::stoull(concat_num_1_str);
  const auto concat_num_2 = std::stoull(concat_num_2_str);

  if(!is_prime(concat_num_1)) return false;
  if(!is_prime(concat_num_2)) return false;

  return true;
}

int main() {
  const auto primes = get_list_of_primes(10000);
  const auto N = primes.size();

  bool found_pair_set = false;
  Int_T sum = 0;

  for(Int_T a = 0; a < N; ++a) {

    for(Int_T b = a + 1; b < N; ++b) {
      const auto pair_ab = is_concat_prime(primes[a], primes[b]);

      if(!pair_ab) continue;

      for(Int_T c = b + 1; c < N; ++c) {
        const auto pair_ac = is_concat_prime(primes[a], primes[c]);
        const auto pair_bc = is_concat_prime(primes[b], primes[c]);

        if(!pair_ac || !pair_bc) continue;

        for(Int_T d = c + 1; d < N; ++d) {
          const auto pair_ad = is_concat_prime(primes[a], primes[d]);
          const auto pair_bd = is_concat_prime(primes[b], primes[d]);
          const auto pair_cd = is_concat_prime(primes[c], primes[d]);

          if(!pair_ad || !pair_bd || !pair_cd) continue;

          for(Int_T e = d + 1; e < N; ++e) {
            const auto pair_ae = is_concat_prime(primes[a], primes[e]);
            const auto pair_be = is_concat_prime(primes[b], primes[e]);
            const auto pair_ce = is_concat_prime(primes[c], primes[e]);
            const auto pair_de = is_concat_prime(primes[d], primes[e]);

            if(!pair_ae || !pair_be || !pair_ce || !pair_de) continue;

            sum = primes[a] + primes[b] + primes[c] + primes[d] + primes[e];
            found_pair_set = true;
          }

          if(found_pair_set) break;
        }

        if(found_pair_set) break;
      }

      if(found_pair_set) break;
    }

    if(found_pair_set) break;
  }

  std::cout << sum << std::endl;

  return 0;
}
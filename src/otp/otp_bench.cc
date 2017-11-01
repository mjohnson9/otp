#include "otp/otp.h"

#include "benchmark/benchmark.h"

namespace otp {

void OtpEncrypt(benchmark::State& state) {
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(encrypt('A', 'Y'));
  }
}
BENCHMARK(OtpEncrypt);

void OtpDecrypt(benchmark::State& state) {
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(decrypt('A', 'Y'));
  }
}
BENCHMARK(OtpDecrypt);

}  // namespace otp

int main(int argc, char** argv) {
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}

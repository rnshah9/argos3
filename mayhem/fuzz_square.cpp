#include <stdint.h>
#include <stdio.h>
#include <climits>
#include <argos3/core/utility/math/general.h>
#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    int t_v = provider.ConsumeIntegral<int>();
    argos::Square(t_v);

    return 0;
}
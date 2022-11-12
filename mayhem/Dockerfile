FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libfreeimage-dev clang

COPY . /repo
WORKDIR /repo/src/build
RUN cmake ..
RUN make -j8
RUN cp /repo/src/build/core/config.h /repo/src/argos3/core/
RUN clang++ /repo/mayhem/fuzz_square.cpp -fsanitize=fuzzer,address -I/repo/src/ -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /fuzz /fuzz_square
COPY --from=builder /repo/src/build/core/argos3 /
COPY --from=builder /repo/src/build/core/libargos3core_simulator.so /deps/
ENV LD_LIBRARY_PATH=/deps

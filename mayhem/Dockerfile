FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libfreeimage-dev

COPY . /repo
WORKDIR /repo/src/build
RUN cmake ..
RUN make -j8

FROM ubuntu:22.04 as package
COPY --from=builder /repo/src/build/core/argos3 /
COPY --from=builder /repo/src/build/core/libargos3core_simulator.so /deps/
ENV LD_LIBRARY_PATH=/deps

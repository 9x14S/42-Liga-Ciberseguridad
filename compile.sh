#!/bin/bash

CONTAINER_PROG=docker
if [ -f /usr/bin/podman ] && [ -x /usr/bin/podman ]; then
  CONTAINER_PROG=podman
fi

echo "Using containerization program: $CONTAINER_PROG"

"$CONTAINER_PROG" build -f - -t liga_cybersec_container << EOF
FROM ubuntu:latest

RUN apt update
RUN apt upgrade -y
RUN apt install -y build-essential make
EOF

"$CONTAINER_PROG" run -v "$(pwd):/io:Z" liga_cybersec_container /usr/bin/make -B -C /io/pwn/ all

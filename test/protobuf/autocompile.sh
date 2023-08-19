#!/bin/bash

protoc test.proto --cpp_out=./

g++ *.cc -lprotobuf -lpthread

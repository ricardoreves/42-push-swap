#!/bin/bash
./push_swap "5 8 5 6 2"
./push_swap 5 8 5 6 2
./push_swap "5 8 ft 6 2"
./push_swap 5 8 ft 6 2
./push_swap "5 8 42424242424242 6 2"
./push_swap 5 8 42424242424242 6 2
./push_swap "5"
./push_swap 5
./push_swap
ARG='1 2 3'; ./push_swap $ARG | ./checker $ARG
ARG='1 3 2'; ./push_swap $ARG | ./checker $ARG
ARG='2 1 3'; ./push_swap $ARG | ./checker $ARG
ARG='2 3 1'; ./push_swap $ARG | ./checker $ARG
ARG='3 1 2'; ./push_swap $ARG | ./checker $ARG
ARG='3 2 1'; ./push_swap $ARG | ./checker $ARG
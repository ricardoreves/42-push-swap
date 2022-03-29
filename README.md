# 42 Push Swap
![Language](https://img.shields.io/static/v1?label=language&message=c&color=blue) ![Licence](https://img.shields.io/badge/license-MIT-green) ![Score](https://42-project-badge.glitch.me/users/rpinto-r/project/push-swap) [![norminette](https://github.com/ricardoreves/42-push-swap/actions/workflows/norminette.yml/badge.svg)](https://github.com/ricardoreves/42-push-swap/actions/workflows/norminette.yml)

## 🪧 Overview
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## 📷 Preview
#### Console
```bash
root@a5df87da6a06:/project# ARG='4 8 2 11 -7 -6'; ./push_swap $ARG
ra
ra
pb
ra
pb
pb
rrb
pa
pa
pa
ra
ra
ra
pb
pb
pb
pa
pa
pa
ra
ra
ra
```
#### Visualizer
![](imgs/psviz.gif)

## 🚀 Getting Started
1. Clone the project.
```
git clone git@github.com:ricardoreves/42-push-swap.git
```
2. Navigate to the project directory.
```
cd 42-push-swap
```
3. Compile the push_swap.
```
make
```

## :joystick: Usage
1. Run push_swap
```
# single argument
./push_swap "4 0 1 3 2"

# multiple arguments
./push_swap 4 0 1 3 2
```
2. Run instructions checker
```
ARG='4 0 1 3 2'; ./push_swap $ARG | ./checker $ARG
```

## 🔬 Testing
### Prerequisites
#### MacOS
1. Install python 
```
brew install python3
```
#### Debian/Ubuntu
1. install python
```
sudp apt update
sudo apt install python3 python3-pip python3-venv
```
2. Make a virtualenv
```
# create an environnement
python3 -m venv .env

# activate env
source ./.env/bin/activate
```
3. Install dependancies
```
pip install -r requirements.txt
```

### Usage
1. Run average tester
```
make test
```
- With 3 numbers, we need to sort it with not more than 3 instructions.
- With 5 numbers, we need to sort it with not more than 12 instructions.
- With 100 numbers, we can get
```
5 points if the size of the list of instructions is less than 700
4 points if the size of the list of instructions is less than 900
3 points if the size of the list of instructions is less than 1100
2 points if the size of the list of instructions is less than 1300
1 points if the size of the list of instructions is less than 1500
```
- With 500 numbers, we can get
```
5 points if the size of the list of instructions is less than 5500
4 points if the size of the list of instructions is less than 7000
3 points if the size of the list of instructions is less than 8500
2 points if the size of the list of instructions is less than 10000
1 points if the size of the list of instructions is less than 11500
```

2. Run visualizer
```
make viz
```

## 🧰 Tools
- [PushSwapVisualizer](https://github.com/xbeheydt/push_swap_visualizer) - This is a python GUI app that helps visualize how the 42 project `push_swap` project works.
- [PushSwapTester](https://github.com/lmalki-h/push_swap_tester) - This tester shows the performance of your push_swap program.

## :books: References
- [medium.com](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) - Introduction to the `push_swap` project.
- [medium.com](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - The least amount of moves with two stacks.
- [geeksforgeeks.org](https://www.geeksforgeeks.org/median/) - How to calculate a median.
- [commentcamarche.net](https://www.commentcamarche.net/faq/7636-liste-doublement-chainee
) -  Liste doublement chaînée.


## 📝 License
Distributed under the MIT License. See [LICENSE](LICENSE) for more information.
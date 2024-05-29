#!/bin/bash

# Flag to track if memory leaks are detected
memory_leaks_detected=0

# Function to perform Betty style checks
perform_betty_checks() {
    local checks=$1
    local betty_output=$(mktemp)
    
    echo "Running Betty $checks checks..."
    if [ "$checks" == "style" ]; then
        betty-style *.c > $betty_output
    elif [ "$checks" == "doc" ]; then
        betty-doc *.c > $betty_output
    else
        echo "Invalid option!"
        # rm $betty_output
    fi
    
    if [ -s $betty_output ]; then
        echo "Fix Betty $checks errors before compiling!"
        cat $betty_output
        # rm $betty_output
    fi
    # rm $betty_output
}

# Function to run Valgrind
run_valgrind() {
    memory_leaks_detected=0
    none_detected=0

    # Define the new tests
    tests=(
        "echo 'ls > /tmp/hbtn_checker_tmp_16043 && cat -e /tmp/hbtn_checker_tmp_16043' | ./hsh"
        "echo 'ls > /tmp/hbtn_checker_tmp_13055 && cat -e /tmp/hbtn_checker_tmp_13055' | ./hsh"
        "echo 'ls >/tmp/hbtn_checker_tmp_32476 && cat -e /tmp/hbtn_checker_tmp_32476' | ./hsh"
        "echo 'ls >/tmp/hbtn_checker_tmp_20406 && cat -e /tmp/hbtn_checker_tmp_20406' | ./hsh"
        "echo 'ls> /tmp/hbtn_checker_tmp_21690 && cat -e /tmp/hbtn_checker_tmp_21690' | ./hsh"
        "echo 'hbtn > /tmp/hbtn_checker_tmp_5009 && cat -e /tmp/hbtn_checker_tmp_5009' | ./hsh"
    )

    echo "Running Valgrind..."
    echo "########################################################"
    echo "                                                        "
    for test_cmd in "${tests[@]}"; do
        eval "$test_cmd" |& grep -q "definitely lost" && { echo -e "\e[31m@@@@@@@ LOST MEMORY for $test_cmd @@@@@@@\e[0m"; memory_leaks_detected=1; none_detected=0; }
        eval "$test_cmd" |& grep -q "no leaks are possible" && { echo -e "\e[32m@@@@@@@ NO MEMORY LEAKS for $test_cmd @@@@@@@\e[0m"; none_detected=1; memory_leaks_detected=0; }
        if [ $none_detected -eq 0 ]; then
            eval "$test_cmd"
        else none_detected=0
        fi
        echo "                                                        "
        echo "########################################################"
        echo "                                                        "
    done
}

# Function to compile the code using Makefile
compile_with_makefile() {
    echo "Compiling with Makefile..."
    if make; then
        echo "Compiled successfully!"
    else
        echo "Compilation failed!"
    fi
}

# Main menu function
clear
main_menu() {
echo -e "\e[34m Thank You for using Matt Checker 1.0 \e[0m"
    while true; do
        echo -e "\e[34mSelect an option:\e[0m"
        echo "1. Perform Betty style checks"
        echo "2. Perform Betty documentation checks"
        echo "3. Compile only"
        echo "4. Run Valgrind"
        echo -e "\e[31m5. Compile and Run Valgrind (Check for memory leaks)\e[0m"
        echo "6. Push your code - dont use"
        echo "7. Exit"
    
        read -p "Enter your choice (1-6): " choice
    
        case $choice in
            1)
                clear
                perform_betty_checks "style"
                ;;
            2)
                clear
                perform_betty_checks "doc"
                ;;
            3)
                clear
                compile_with_makefile
                ;;
            4)
                clear
                run_valgrind
                ;;
            5)
                clear
                echo "Compiling..."
                compile_with_makefile
                if [ $memory_leaks_detected -eq 1 ]; then
                    echo -e "\e[31m@@@@@@@ YOU HAVE MEMORY LEAKS! @@@@@@@\e[0m"
                else
                    echo -e "\e[32mAll good!\e[0m"
                fi
                ;;
            6)
                clear
                pusher
                ;;
            7)
                clear
                exit 0
                ;;
            *)
                echo "Invalid choice!"
                ;;
        esac
    done
}

# Start the main menu
main_menu

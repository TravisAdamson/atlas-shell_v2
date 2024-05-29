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
    fi
    
    if [ -s $betty_output ]; then
        echo "Fix Betty $checks errors before compiling!"
        cat $betty_output
    fi
}

# Function to run Valgrind
run_valgrind() {
    memory_leaks_detected=0
    none_detected=0

    # Define the new tests
    tests=(
        "echo Holberton School > test"
        "cat -e test"
        "rm -f test"
        "echo Holberton School >> test"
        "echo Holberton School >> test"
        "cat -e test"
        "cat -e small_file"
        "rev < small_file"
        "cat -e << HOLBERTON
        > qwertyuiop
        > ls -l                          
        > cat -e small_file
        > HOLBERTONnope
        > nopeHOLBERTON
        > HOLBERTON 
        > HOLBERTON"
        "ls /var > var_output"
        "ls /var >> var_output"
        "cat < var_output"
        "cat << END
        > Hello
        > World
        > END"
        "ls /var | rev"
        "ls -lr /var | cat -e"
        "echo 'Holberton' | wc -c"
        "ls /var ; ls /var"
        "ls /hbtn ; ls /var"
        "ls /var ; ls /hbtn"
        "ls /var ; ls /hbtn ; ls /var ; ls /var"
        "ls /var && ls /var"
        "ls /hbtn && ls /var"
        "ls /var && ls /var && ls /var && ls /hbtn"
        "ls /var && ls /var && ls /var && ls /hbtn && ls /hbtn"
        "ls /var || ls /var"
        "ls /hbtn || ls /var"
        "ls /hbtn || ls /hbtn || ls /hbtn || ls /var"
        "ls /hbtn || ls /hbtn || ls /hbtn || ls /var || ls /var"
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

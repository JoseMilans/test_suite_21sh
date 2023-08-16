
#include <stdio.h>
#include <stdlib.h>
void run_test(const char *description, const char *command)
{
    printf("Running test: %s\n", description);
    system(command);
    printf("\n-------------------------------------\n");
}
int main()
{
    run_test("Cmd execution", "echo 'ls' | ./hsh");
    run_test("Cmd with arguments execution", "echo 'ls -la' | ./hsh");
    run_test("Commands in PATH", "echo 'ls' | ./hsh");
    
    run_test("Exit cmd", "echo 'exit' | ./hsh");
    
    run_test("Direct cmd execution using full path", "echo '/bin/ls' | ./hsh");
    run_test("Direct cmd execution in the current directory", "echo './my_script.sh' | ./hsh");
    
    run_test("Cmd not found", "echo 'nonexistent_command' | ./hsh");
    
    run_test("Tokenising input", "echo 'ls     -la' | ./hsh");
    
    run_test("Memory management (valgrind)", "echo 'ls' | valgrind --leak-check=full ./hsh");
    
    run_test("Error handling", "echo '/nonexistent_path/ls' | ./hsh");
    
    run_test("Handling input and output redirection", "echo 'ls > output.txt' | ./hsh");
    
    run_test("PATH parsing", "echo 'test_script.sh' | ./hsh");
    
    run_test("Edge case - long input", "echo \"$(printf 'a%.0s' {1..8000})\" | ./hsh");
    
    run_test("Edge case - empty input", "echo '' | ./hsh");
    
    run_test("Environment variables", "echo 'echo $HOME' | ./hsh");
    
    return (0);
}

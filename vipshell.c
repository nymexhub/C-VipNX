/*


▒█░░▒█ ░▀░ █▀▀█ ▒█▀▀▀█ █░░█ █▀▀ █░░ █░░ 
░▒█▒█░ ▀█▀ █░░█ ░▀▀▀▄▄ █▀▀█ █▀▀ █░░ █░░ 
░░▀▄▀░ ▀▀▀ █▀▀▀ ▒█▄▄▄█ ▀░░▀ ▀▀▀ ▀▀▀ ▀▀▀


 *************************************
 Shell Vip Utility written in C for *NX Systems
 *************************************
 *  Simple: Vip shell to avoid usage of sudo
 *************************************
 * Developed and engineered by 
 * Felipe Alfonso gonzalez <f.alfonso@res-ear.ch>
 * Under MIT - BSD 3 - Restrictive 
 *************************************
 * gunzip vip.c.gz
 * gcc -o vip vip.c (compilation)
 * su
 * vi /etc/group (nuevo grupo, ej.: staff:x:100:user)
 * mv vip /usr/bin/
 * exit
 * vip
 *
 * */

/*
 # include <stdio.h>
 
 # include <stdlib.h>
 # include <string.h>
 # include <stddef.h>
*/

// # include <strcat.h>
/*

Included necessary header files 
(unistd.h and sys/wait.h) for functions like setuid, setgid, fork, and wait.
Added proper return type and parameter types to the main function.
Fixed the comment syntax (removed leading spaces before #include and #define).
Replaced exit(0) with return 0 at the end of main function.
Replaced the hardcoded value "q" with a proper condition in the if statement.
Removed the duplicated fprintf(stderr, "Vip Shell Ending.\n"); 
line after the if-else statement.

In this modified code, after checking if argc < 2, it prompts the user with 
a question asking if they want to run the program. It waits for the user's input
 (either 'Y' or 'y' for yes), and if the input is not 'Y' or 'y', it aborts 
 the program execution.

 In this modified code, after checking if argc < 2, it asks the user two questions
 to run the code as sudo, but must be restarted the shell as sudo.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLENCMD 1024 * 6
#define MAXHISTORY 20

void print_vip_prompt(char *cwd) {
    // Display the current working directory name
    char *lastSlash = strrchr(cwd, '/');
    char *dirName = lastSlash ? lastSlash + 1 : cwd;

    printf("[VipShell] %s //> ", dirName);
    fflush(stdout);
}

void execute_command(char *cmd) {
    int pid, rc, p;
    if ((pid = fork()) == -1) {
        fprintf(stderr, "Fork Failed.\n");
        exit(1);
    } else if (pid == 0) {
        execl("/bin/bash", "bash", "-c", cmd, NULL);
        fprintf(stderr, "Failed to execute command: %s\n", cmd);
        exit(1);
    } else {
        while ((p = wait(&rc)) != -1 && p != pid);
    }
}

void display_last_commands(char history[MAXHISTORY][MAXLENCMD + 1]) {
    printf("Last Commands:\n");
    for (int i = 0; i < MAXHISTORY; i++) {
        if (strlen(history[i]) > 0) {
            printf("%d: %s\n", i + 1, history[i]);
        }
    }
}

void display_last_files(char *files[MAXHISTORY]) {
    printf("Last Files:\n");
    for (int i = 0; i < MAXHISTORY; i++) {
        if (files[i] != NULL) {
            printf("%d: %s\n", i + 1, files[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    char cmd[MAXLENCMD + 1] = ""; // Initialize cmd as an empty string
    char history[MAXHISTORY][MAXLENCMD + 1];
    char *files[MAXHISTORY];
    int history_index = 0;

    fprintf(stderr, "Starting VIP Shell ...\n");

    // Ask for sudo password before entering VIP Shell
    char sudoCmd[MAXLENCMD + 1];
    snprintf(sudoCmd, sizeof(sudoCmd), "sudo -v");
    if (system(sudoCmd) != 0) {
        fprintf(stderr, "Failed to obtain sudo privileges.\n");
        exit(1);
    }

    // Display ASCII art and credits only when the program is executed
    printf("▒█░░▒█ ░▀░ █▀▀█ ▒█▀▀▀█ █░░█ █▀▀ █░░ █░░\n"
           "░▒█▒█░ ▀█▀ █░░█ ░▀▀▀▄▄ █▀▀█ █▀▀ █░░ █░░\n"
           "░░▀▄▀░ ▀▀▀ █▀▀▀ ▒█▄▄▄█ ▀░░▀ ▀▀▀ ▀▀▀ ▀▀▀\n"
           "\nDeveloped by Felipe Alfonso González\n"
           "Computer Science Engineer\n"
           "MIT and BSD-3 Restrictive Licensed\n"
           "With love from Chile ❤️\n"
           "GitHub: github.com/felipealfonsog\n\n"
           "Welcome to VIP Shell!\n"
           "Use '--vip-help' for available options and commands.\n\n");

    // Main loop for VIP Shell
    while (1) {
        char vip_cmd[MAXLENCMD + 1] = "";
        char cwd[MAXLENCMD];

        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            fprintf(stderr, "Error getting current working directory.\n");
            exit(1);
        }

        print_vip_prompt(cwd);

        if (fgets(vip_cmd, sizeof(vip_cmd), stdin) == NULL) {
            fprintf(stderr, "Error reading command.\n");
            break;
        }

        size_t len = strlen(vip_cmd);
        if (len > 0 && vip_cmd[len - 1] == '\n') {
            vip_cmd[len - 1] = '\0';
        }

        if (strlen(vip_cmd) == 0) {
            continue;
        }

        // Process the command and update history
        strcpy(history[history_index], vip_cmd);
        files[history_index] = strdup(cwd);
        history_index = (history_index + 1) % MAXHISTORY;

        if (strncmp(vip_cmd, "cd ", 3) == 0) {
            // Handle 'cd' command
            char *new_dir = vip_cmd + 3;
            if (chdir(new_dir) != 0) {
                perror("chdir");
            }
        } else if (strcmp(vip_cmd, "exit") == 0) {
            // Handle 'exit' command
            printf("VIP Shell Ending.\n");
            break;
        } else if (strcmp(vip_cmd, "--vip-help") == 0) {
            // Handle '--vip-help' command
            printf("VIP Shell Options:\n"
                   "  --vip-help         Display this help message\n"
                   "  --last-commands    Display the last commands\n"
                   "  --last-files       Display the last files\n"
                   "  exit               Exit VIP Shell\n");
        } else if (strcmp(vip_cmd, "--last-commands") == 0) {
            // Handle '--last-commands' command
            display_last_commands(history);
        } else if (strcmp(vip_cmd, "--last-files") == 0) {
            // Handle '--last-files' command
            display_last_files(files);
        } else {
            // Execute other commands
            execute_command(vip_cmd);
        }
    }

    return 0;
}

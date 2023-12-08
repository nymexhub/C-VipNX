#!/bin/bash

# *************************************************
# The VIP Shell provides a basic yet functional command-line 
# environment with added features for command history and file 
# tracking, enhancing the user experience in a Unix-like shell.
# *************************************************
# * Developed and engineered by:
# * Felipe Alfonso Gonzalez <f.alfonso@res-ear.ch>
# * Computer Science Engineer
# * Chile
# *************************************************
# * Important Notes:
# * - The application has been tested on Linux and macOS.
# * - For Windows, additional configurations may be required.
# * - Make sure to fulfill the prerequisites before running the application.
# * - For more information, please refer to the project documentation.
# *************************************************

welcome_message() {
    echo
    echo "▒█░░▒█ ░▀░ █▀▀█ ▒█▀▀▀█ █░░█ █▀▀ █░░ █░░"
    echo "░▒█▒█░ ▀█▀ █░░█ ░▀▀▀▄▄ █▀▀█ █▀▀ █░░ █░░"
    echo "░░▀▄▀░ ▀▀▀ █▀▀▀ ▒█▄▄▄█ ▀░░▀ ▀▀▀ ▀▀▀ ▀▀▀"
    echo "---------------------------------------------------"
    echo "VIP Shell - Simple and Interactive Command Line Shell"
    echo "---------------------------------------------------"
    echo "*  Welcome to the VIP Shell, a user-friendly shell"
    echo "*  for executing commands in a Unix-like environment."
    echo "---------------------------------------------------"
    echo
    echo "╭─────────────────── TERMS OF USE ─────────────────╮"
    echo "│  This software is licensed under - MIT and BSD-3 │"
    echo "│  Restrictive Licenses.                           │"
    echo "│  Developed by Felipe Alfonso González            │"
    echo "│  Computer Science Engineer                       │"
    echo "│  GitHub: github.com/felipealfonsog               │"
    echo "╰──────────────────────────────────────────────────╯"
    echo
    echo "Welcome to the VIP Shell Installer!"
    echo "This script will install the VIP Shell program on your system."
    echo "Please make sure you have the necessary permissions to perform the installation."
    read
}


download_source_vipshellp() {
    local os=$(uname -s)
    local installer_url="https://github.com/felipealfonsog/C-VipNX/raw/main/vipshell.c"

    if [[ "$os" == "Darwin" || "$os" == "Linux" ]]; then
        echo "Downloading the shell vip source..."
        curl -o shellvip.c -L "$installer_url"
    else
        echo "Unsupported platform."
        exit 1
    fi
}

compile_source_vipshell() {
    echo "Compiling source ..."
    
    gcc -o vipshell vipshell.c || { 
        echo "Error: Compilation failed." 
        exit 1
    }
    sudo chmod +x vipshell
    echo "Compilation successful."
}

move_to_bin_directory() {
    echo "Moving compiled binary to bin directory..."

    sudo mv vipshell "/usr/local/bin"
 
    sudo chmod +x "/usr/local/bin/vipshell"

    echo "Binary moved to '/usr/local/bin' and permissions set."
}


run_vipshell() {
    echo "Running the Vip Shell from Bash script..."
    
    /usr/local/bin/vipshell
    #echo "Vip Shell executed."
}

remove_compiled_file() {
    echo "Removing unnecessary files..."
    rm -rf *.c
    rm installer.sh
    echo "Cleanup complete."
}

set_permissions() {
    echo "Setting permissions..."

    # chmod 755 ./

    echo "Permissions set."
}



welcome_message
download_source_vipshell
compile_source_vipshell
move_to_bin_directory
# run_shellvip
remove_compiled_file
# set_permissions

echo "Vipshell has been successfully installed as 'vipshell' command!"

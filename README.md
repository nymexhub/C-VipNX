# C-VipNX
Shell Vip Utility written in C for *NX Systems.
Simple: Vip shell to avoid usage of sudo.

![Version](https://img.shields.io/github/release/NymexData/C-VipNX.svg?style=flat&color=blue)
[![Open Source? Yes!](https://badgen.net/badge/Open%20Source%20%3F/Yes%21/blue?icon=github)](https://github.com/Naereen/badges/)

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/)
<!--
[![GPL license](https://img.shields.io/badge/License-GPL-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
-->

### Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Instructions](#instructions)
  - [File Structure](#file-structure)
- [Contributing](#contributing)
- [Creator / Maintainer](#creator--maintainer)
- [Additional Information](#additional-information)

---

### Getting Started

![Raspberry Pi Pico](readme-files/ScreenShot_2023-06-03_at_01.15.22.png)

### Prerequisites

#### Instructions

You need to install tcsh in your Linux/Unix like flavor. 

 | gunzip vip.c.gz
 
 | sudo gcc -o vip vip.c (compilation)
 
 
 | su
 
 | vi /etc/group (nuevo grupo, ej.: staff:x:100:user
 | vim visudo
 | #


#### User privilege specification
root    ALL=(ALL:ALL) ALL
 
vip     ALL=(ALL:ALL) ALL
 
 | mv vip /usr/bin/
 
 | exit
 
 | vip
 
 then,
execute it as a user:
 sudo vip

#### File Structure

```
 |-- vip.c
 |-- vip
```
#### Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate. But i would prefer if you could contact me first. 

#### How To Contribute

1. Fork the repository to your own Github account.
2. Clone the project to your machine.
3. Create a branch locally with a succinct but descriptive name. You can use 'development' directly. 
4. Commit changes to the branch.
5. Following any formatting and testing guidelines specific to this repo.
6. Push changes to your fork.
7. Open a Pull Request in my repository - Before start a conversation.

-For Development, use the development branch and then we can do a pull request to the main branch. use : git --help for swtiching ... e.g.:

```
felipe@Felipes-MacBook-Air webserver-raspberry-pico % git branch development
felipe@Felipes-MacBook-Air webserver-raspberry-pico % git branch        
  development
  * main
felipe@Felipes-MacBook-Air webserver-raspberry-pico % git checkout development
```

When git push for 'development':

```
git push --set-upstream origin development
git branch --set-upstream-to=origin development

git clone -b <branchname> <remote-repo-url>
```

---

#### Creator / Maintainer
Computer Science Engineer:
Felipe Alfonso González L. ([felipealfonsog](https://github.com/felipealfonsog))

If you have any questions, comments, or concerns, feel free to contact me by Email [f.alfonso@res-ear.ch](mailto:f.alfonso@res-ear.ch).


#### Support

If you like my content or find this code useful, give it a :star: or support me by buying me a coffee :coffee::grinning:

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-Donate-orange.svg)](https://www.buymeacoffee.com/felipealfonsog)


---

#### Additional Information

- [brew](https://brew.io/)
- [GCC](https://gcc.gnu.org/)

#### Developed with: 

[![Vim](https://img.shields.io/badge/--019733?logo=vim)](https://www.vim.org/)
[![Visual Studio Code](https://img.shields.io/badge/--007ACC?logo=visual%20studio%20code&logoColor=ffffff)](https://code.visualstudio.com/)



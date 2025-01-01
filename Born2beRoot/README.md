# Born2beRoot

This project's goal is to help you set up your `Virtual Machine` under specific instructions to get you close and close to know more about to world of virtualization.


## Resources :
#### 📘 Articles
 - [How to enable SSH](https://phoenixnap.com/kb/how-to-enable-ssh-on-ubuntu)
 - [How to setup UFW Firewall](https://phoenixnap.com/kb/configure-firewall-with-ufw-on-ubuntu#ftoc-heading-6)
 - [How to Add a User to a Linux Group](https://phoenixnap.com/kb/add-user-to-linux-group)
 - [How To Set Password Policies In Linux](https://ostechnix.com/how-to-set-password-policies-in-linux/)
 - [Useful Sudoers Configuring sudo Command in Linux](https://www.geeksforgeeks.org/useful-sudoers-configurations-for-setting-sudo-in-linux/)
 - [TTY Command in Linux](https://www.geeksforgeeks.org/tty-command-in-linux-with-examples/)
 - [How to get the mac address](https://www.geeksforgeeks.org/how-to-get-the-mac-address-10-different-methods-kali-linux/)
 - [How to Check CPU Utilization](https://phoenixnap.com/kb/check-cpu-usage-load-linux#ftoc-heading-3)


#### 💻 Videos
- [Linux Directories Explained in 100 Seconds](https://www.youtube.com/watch?v=42iQKuQodW4)
- [Linux File System](https://www.youtube.com/watch?v=A3G-3hp88mo)
- [Virtualization (Part 1): Hypervisors & VMs](https://www.youtube.com/watch?v=a75fC8xnBn8)
- [Virtualization (Part 2): How hypervisors work](https://www.youtube.com/watch?v=L0IDOQneyRE)
- [Virtualization in Arabic](https://www.youtube.com/watch?v=3HChgNmRYJU)
- [Introduction to LVM | Linux Academy](https://www.youtube.com/watch?v=dMHFArkANP8&list=PLAoA-usw1t-4sIlwNXKS2RIn0ZBx4VQhn)

## ⚠️ Need to know :

#### 🔷 How does a virtual machine work ? And what its purpose ?
    
- **Virtualization** is the process of creating virtual versions of physical resources, such as servers, storage, networks, or applications. **The purpose of virtualization** is to optimize resource utilization, improve efficiency, and reduce costs by allowing multiple virtual systems or applications to run on a single physical hardware.
---
#### 🔷 Hypervisor ?

- **Hypervisor** is a software that can manage and create a virtual machine on your host and there is two types of hypervisor:
- **Type1 (bare metal)** : which is installed directly on top of your host
- **Type2** : which is installed on top of your operating system
---
#### 🔷 What's the difference between Debian and Rocky? and If you choose one on another explain why?

The main difference between community-driven and enterprise Linux distributions is their target audience and focus. Community-driven distros like Debian are created by volunteers and focus on flexibility, open-source principles, and freedom, making them great for developers and tech enthusiasts. On the other hand, enterprise distros like Rocky Linux are designed with businesses in mind, offering long-term support, stability, and professional help for critical systems. Debian is perfect for those who want control and customization, while Rocky Linux is more suited for companies that need reliable, secure, and supported systems for their operations.

---
#### 🔷 What's a partition ? And more generally how does LVM (Logical Volume Management) work ?
- **Partition** is a logically divided section of a physical storage device 

* **LVM (Logical Volume Manager)** is a software-based system in Linux for **managing disk storage dynamically**. **LVM** is built into Linux.

    - **Physical Volumes (PVs):**
        > These are raw storage devices (e.g., /dev/sda1).
        > LVM uses them as building blocks.

    - **Volume Groups (VGs):**
        > A pool of storage created by combining one or more physical volumes. 
        > 
        > Example: Combine a 500GB and a 1TB disk into a single 1.5TB volume group.

    - **Logical Volumes (LVs):**
        > Flexible, virtual partitions carved out of a Volume Group.
        >
        > Example: Create an LV for /, another for /home, and one for swap.
        > Logical volumes can be resized, moved, or combined dynamically.

- With **LVM**, adding a new disk is easy, and the storage is managed as a unified pool. Logical Volumes can grow without needing to repartition or move data manually. Applications and users don’t notice any changes.

- With **Manual partitioning**, each new disk requires extra effort to partition, format, and mount. It often leads to fragmented storage, with data scattered across multiple locations, making management more complex as the system grows.
---
#### 🔷 What's sudo ?

**sudo** (short for superuser do) is a command in Unix-like operating systems (like Linux and macOS) that allows a permitted user to execute a command with the privileges of a superuser (root user) or another user. This is particularly useful because many system-level operations require administrative (root) permissions that a regular user does not have by default.

---
#### 🔷 What's the difference between apt and aptitued ?
- **Apt:**
apt is a command-line tool for managing packages on Debian-based systems. It performs tasks like installing, upgrading, and removing software packages.

- **aptitude:**
aptitude is a more advanced package management tool that extends apt's functionality. It provides a graphical interface and better handling of package dependency issues.
 - **Package:**
    A package is a collection of files providing specific software functionality.
    Example: A web browser package might include its executable, libraries, configuration files, and documentation.

 - **Dependency Issue:**
    Dependencies are other software or libraries required for a program to function.
    Example: If you're installing a video player, it might require a specific version of a codec library.

- **Differences:**
Apt: Simple and intuitive, primarily for basic tasks.
Aptitude: Offers advanced features like resolving complex dependency issues and a GUI for ease of use.
---
#### 🔷 What's SSH (Secure Shell) and what's the value of using it ?
**SSH** (Secure Shell) is a network protocol used to securely connect to and manage remote machines over a network It is primarily used for logging into remote systems and executing commands, but it can also be used for file transfer and tunneling network traffic.

 - **Port**: By default, SSH listens on port 22, but you can change the port for added security or to avoid conflicts with other services.

 - **Encryption**: SSH encrypts the entire session, ensuring that any data transmitted between the client and server is secure and cannot be easily intercepted.
---
#### 🔷 What's an UFW (Uncomplicated Firewall) and what's the value of using it ?
A firewall is a network security system that monitors and controls incoming and outgoing network traffic based on predetermined security rules. It acts as a barrier between your computer or network and potential threats from external networks, such as the internet.
> **For example:** when you allow port 22, it means you are opening your system to accept incoming traffic on port 22, which is the default for SSH (Secure Shell).
>
> It works by creating rules that either allow or deny traffic based on ports, IP addresses, and protocols (such as TCP or UDP).

---
#### 🔷 What's APPArmor ?
AppArmor is a security system that allows a computer administrator (Admin) to predefine operational permissions (profiles) for applications. Each application is restricted to operate within the defined permissions. If an application attempts to exceed its allowed permissions, AppArmor detects this behavior and blocks it.
- **Admin:**
An administrator is a user with full permissions to manage the computer.
Example: The admin can configure permissions for an application like a web browser, limiting its access to certain files or network connections.
- **Profile:**
Permission/Profile:
A profile is a set of predefined rules that specify what an application can and cannot do.
> Example:
> **Allowed:** Reading files in the /home/user directory.
> **Restricted:** Writing to /etc/system files.
**Use Case Example:**
Suppose an email app has permission to read user emails but not access the system's kernel. If a hacker exploits the app to attempt kernel access, AppArmor detects and prevents this action.

---
#### 🔷 What's Cron ?
**Cron** is a time-based job scheduler in Unix-like operating systems (such as Linux and macOS). It allows users to run commands, scripts, or programs at specific intervals or times automatically. For example, you can schedule tasks to run daily, weekly, monthly, or even every minute.
It is widely used for automating repetitive tasks such as backups, system monitoring, updates, and sending notifications.

---
## 📋 Instructions :

#### 1. Create Virtual Machine with VirtualBox
> **Your hostname must be your “login” + 42 (ex: imellali42).**
>
> **You must create at least 2 encrypted partitions using LVM :**

```sh
0. boot
1. root (mandatory part)
2. swap (mandatory part)
3. home (mandatory part)
4. var (bonus part)
5. srv (bonus part)
6. tmp (bonus part)
7. var/log (bonus part)
```
> **You must install GRUB Boot loader in your disk !**
---
#### 2. Installing sudo using apt

```sh
imellali@imellali42:~$ su
root@imellali42:/home/imellali# apt install sudo
root@imellali42:/home/imellali# apt install vim
```

> **If sudo not working :**

```sh
root@imellali42:/home/imellali# vi /etc/sudoers
```
> **Then and add this to sudoers file :**

```sh
"your user" ALL=(ALL) ALL
```

> **Example :**
```sh
imellali ALL=(ALL) ALL
```
> **Save and quit vim, Then quit su and try sudo again.**

---
#### 3. Installing & Configuring SSH
    
> **To install ssh  :**

```sh
sudo apt install openssh-server
sudo systemctl status ssh (to check if ssh is active)
```
> **To edit port to 4242  :**

```sh
sudo vi /etc/ssh/sshd_config
port 4242 (edit this)
```
> **To make the connection not as a root :**

```sh
sudo vi /etc/ssh/sshd_config
PermitRootLogin no (edit this)
```
---   
#### 4. Installing & Configuring UFW
    
> **To install UFW :**

```sh
sudo apt install ufw
sudo ufw version (to check if UFW installed)
sudo ufw enable (to unable UFW)
```

> **To allow SSH connection :**

```sh
sudo ufw allow ssh
```

> **To configure UFW with port 4242 :**

```sh
sudo ufw status numbered
sudo ufw delete 1 (to remove port 22)
sudo ufw delete 2 (to remove port 22/v6)
sudo ufw allow 4242
sudo ufw status (check if only port 4242 is there)
```
---   
#### 5. Create a new user and assign it to a group
> **To create a new user :**

```sh
sudo adduser "username"
```
> **To create a new group :**

```sh
sudo addgroup "groupname"
```
> **To create a user to a group :**

```sh
sudo adduser "username" "groupname"
```
> **To check if the user is within a group:**

```sh
getent group
```
> **To delete a group or a user :**

```sh
sudo -r deluser "username" (-r to delete its directory in /home)
sudo delgroup "groupname"
```
---
#### 6. Set up a strong password policy
> **Step 1 : (Install this package to enforce password quality)**
 
```sh
sudo apt install libpam-pwquality
```

> **Step 2 :**

```sh
sudo vi /etc/login.defs
PASS_MAX_DAYS 30 (It's the max days till password expiration)
PASS_MIN_DAYS 2 (It's the min days till password change)
MAX_WARN_AGE 7 (It's the days till password warning)
```
> **Step 3 :**

```sh
sudo vi /etc/pam.d/common-password
minlen=10 (The minimun characters a password must contain)
ucredit=-1 (The password at least have to contain a capital letter)
lcredit=-1 (The password at least have to contain a lowercase letter)
dcredit=-1 (The passworld at least have to containt a digit)
maxrepeat=3 (The password can not have the same character repeated three contiusly times)
reject_username (The password can not contain the username inside itself)
enforce_for_root (We will implement this password policy to root)

This rule will be on seperate line (not gonna be applied on root user) :
difok=7 (The new password must have at least 7 different characters from the old password
```

---
#### 7. Set up a sudo configuration
> Configuration for sudo:
```sh
sudo vi /etc/sudoers
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults	log_input, log_output
Defaults	logfile="/var/log/sudo/sudo_logs.log"
Defaults	iolog_dir="/var/log/sudo/"
Defaults	requiretty
Defaults	passwd_tries=3
Defaults	badpass_message="type here your custom message"
```
---
#### 8. Create a simple script called **monitoring.sh**
> This is the script used for crontab:
```sh
#!/bin/bash
echo "#Architecture:" $(uname -a)
echo "#CPU physical :" $(nproc)
echo "#vCPU :" $(nproc)
echo "#Memory Usage:" $(free -m | awk 'NR==2 {printf "%d/%dMB (%.2f%%)", $3, $2, $3/$2*100}')
echo "#Disk Usage:" $(df -m --exclude-type=tmpfs --total | awk 'END{print $3}')"/"$(df -h --exclude-type=tmpfs --total | awk 'END{printf "%dGb (%d%%)", $2, $5}')
echo "#CPU load:" $(vmstat 1 2 | tail -1 | awk '{printf "%.1f%%", 100-$15}')
echo "#Last boot:" $(who -b | awk '{print $3" "$4}')
echo "#LVM use:" $(lsblk | awk '{if ($6=="lvm") {print "yes";flag=1;exit} else if (flag) {print "no";exit} }')
echo "#Connections TCP :" $(ss -t state established | awk 'NR > 1' | wc -l) ESTABLISHED
echo "#User log:" $(who | cut -d " " -f1 | sort -u | wc -l)
echo "#Network: IP" $(hostname -I)"("$(cat /sys/class/net/enp0s3/address)")"
echo "#Sudo :" $(journalctl -q _COMM=sudo | grep "COMMAND" | wc -l) cmd
```
---

## Questions Aside :


- ➜ **What is the difference between creating new a partiition with type primary or logical ?**
    - Use **primary partitions** for boot-related purposes and operating systems.
    - Use **logical partitions** for additional storage or non-boot-critical partitions to save primary slots.

- ➜ **What is the meaning of jornaling file system (ext4, ext3) ?**

    - A file system is a method used by an operating system to store, retrieve, and organize data on a partition. Without a file system, a partition is just raw, unstructured storage.
    - When creating a partition, the system asks you to choose a **file system** (e.g., ext4, ext3, FAT32, swap, etc.). This decision determines how data will be stored, organized, and accessed on that partition. Each file system is optimized for different purposes

- ➜ **What is the meaning of mount point ?**

    - **Mount Point**: Determines where the partition’s contents appear in the file system.
    - Assigning appropriate mount points improves organization, security, and recoverability.
    - Ensures partitions are used for their intended purpose.

- ➜ **GRUB Boot loader ?**

    - GRUB is a **boot loader** that loads the operating system kernel into memory and transfers control to it.
    - Without a boot loader, your computer wouldn’t know how to start your operating system.

- ➜ **How to change the hostname**

    - To modify your hostname just use this command on your machine's terminal:
        ```sh
        sudo hostnamectl set-hostname "new hostname"
        ```

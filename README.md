<h1 align="center">
<br>
<img src=img/linux.png height="400" border="2px solid #555">
<br>
<strong>Custom Linux Kernel and Busybox Setup</strong>
</h1>


This guide provides detailed steps to build a custom Linux kernel and Busybox to create a minimalistic and customizable Linux operating system. Follow the steps below to set up your custom environment.

## Step 1: Install Dependencies

Ensure that the required dependencies are installed on your system. Run the following command to install necessary packages:

```bash
debian: sudo apt-get install bzip2 git vim make gcc libncurses-dev flex bison bc cpio libelf-dev libssl-dev syslinux dosfstools nano git
fedora: sudo dnf install bzip2 git vim make gcc ncurses-devel flex bison bc cpio elfutils-libelf-devel openssl-devel syslinux dosfstools nano git

```

## Step 2: Clone the Linux Kernel Repository

Clone the Linux Kernel repository from Linus Torvalds' GitHub repository:

```bash
git clone --depth 1 https://github.com/torvalds/linux.git
cd linux
```

## Step 3: Configure the Kernel

Run the following command to configure the kernel:

```bash
make menuconfig
```

This command opens a configuration menu. Add the desired configurations to the kernel and save the changes.

## Step 4: Build the Kernel

Build the kernel using the following command. Adjust the `-j` parameter according to your processor count:

```bash
make -j 4
```

The compiled kernel image will be located at `arch/x86/boot/bzImage`.

## Step 5: Copy Kernel Image

Create a directory to store boot files and copy the kernel image to it:

```bash
mkdir /boot-files
cp arch/x86/boot/bzImage /boot-files
```

## Step 6: Clone Busybox

Clone the Busybox repository for the userspace utilities:

```bash
git clone --depth 1 https://git.busybox.net/busybox
cd busybox
```

## Step 7: Configure Busybox

Configure Busybox to build a static binary:

```bash
make menuconfig
```

Select "Build static binary" from the configuration menu and save the changes.

## Step 8: Build Busybox

Build Busybox with the following command. Adjust the `-j` parameter according to your processor count:

```bash
make -j 4
```

## Step 9: Create Initramfs

Create an initial RAM filesystem (initramfs) to be loaded by the kernel after boot:

```bash
mkdir /boot-files/initramfs
make CONFIG_PREFIX=/boot-files/initramfs install
cd /boot-files/initramfs/
nano init
```

Add the following content to the `init` file:

```bash
#!/bin/sh
/bin/sh
```

Remove the `linuxrc` file:

```bash
rm linuxrc
```

Make the `init` file executable:

```bash
chmod +x init
```

Create the initramfs archive:

```bash
find . | cpio -o -H newc > ../init.cpio
```

## Step 10: Prepare Boot Environment

Install syslinux and create a bootable file system:

```bash
sudo apt-get install syslinux
dd if=/dev/zero of=boot bs=1M count=50
ls
sudo apt-get install dosfstools
mkfs -t fat boot
syslinux boot
mkdir m && mount boot m
cp bzImage init.cpio m
```

## Step 11: Finalize Boot Environment

Unmount the boot file system:

```bash
umount m
```

Now, your boot file is ready to boot into the x86_64 architecture. In the boot section, add the following:

```
boot: /bzImage -initrd=/init.cpio
```

This configuration will initiate the boot process for your custom Linux OS.

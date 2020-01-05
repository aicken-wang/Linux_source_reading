# Linux源码阅读笔记
# 虚拟环境安装 略... 
安装内核编译依赖
yum install gcc gcc-c++ make ncurses-devel openssl-devel elfutils-libelf-devel flex bison
- ncurses-devel  在执行make menuconfig时的图形菜单需要用到的依赖
- openssl-devel  安全链接openssl
- elfutils-libelf-devel elf工具

官网：[https://www.kernel.org](https://www.kernel.org/)
```shell
# 请使用 root权限
# 下载Linux源码
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.4.7.tar.xz
# 解压源码 注意 这里是xz
tar xvf linux-5.4.7.tar.xz -C /usr/src/kernels
配置内核编译参数
cd /usr/src/kernels/linux-5.4.7

# 使用当前系统内核配置文件，即当前的/boot/configxxx文件，
    cp /boot/config-kernelversion.platform /usr/src/kernels/linux-5.4.7/.config
# make 参数
# make menuconfig|allyesconfig|allnoconfig
# 会出现一个菜单选择，无脑什么都配置，最小内核可能启动不了，只有基本的参数
# 选择编译方式
    make menuconfig # 会出现图形界面 上下 和回车


# 查看CPU
    lscpu
# 编译 
    make -j2 all # j8 使用八个物理核心编译;all 配置的所有模块都编译
# 安装内核
# step1:先安装内核支持的模块
    make modules_install 
# step2:再安装内核本身
    make install
# 成功后重启系统
reboot
```
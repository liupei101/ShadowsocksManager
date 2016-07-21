# ShadowsocksManager
### 用途
主要用户管理ShadowSocks软件上端口，包括增加端口，修改密码，删除端口等功能

### 由来
之前搭建过一个VPS，并且在VPS上搭建了ShadowSocks，简单的配置下文件/etc/sss.json就ok了。由于一起使用ShadowSocks的人越来越多，每次都要去修改文件，然后停止ss服务器，打开ss服务器重新加载配置文件，并且SSH登录下更加的繁琐。我本身比较懒，所以就想写一个简单的程序来管理端口的配置！

### 命令行参数
- CAT 查看所有端口信息（端口号，密码）
- CAT port_number 查看指定端口信息
- ADD port_number password 增加一个新的端口
- PWD port_number new_password 修改端口密码
- DEL port_number 删除一个指定端口

### 使用方法
- git clone https://github.com/liupei101/ShadowsocksManager.git
- make (可能会出现一些warning，但是不影响编译)
- cd bin
- ./ssmanager
- 输入配置文件所在的绝对路径（也就是/etc/sss.json）
- 使用上面的命令行参数管理端口
- 输入EXIT退出（程序退出，程序最后会自动重新启动ShadowSocks，载入新写入的配置文件）

### 待完善
- 增加端口输入错误的提示
- 增加同步iptables功能
- 增加命令行参数利用iptables查看各个端口流量使用情况

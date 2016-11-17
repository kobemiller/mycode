# ubuntu软件包操作

ubuntu
---

**1、软件安装**
    # apt-get install softname
    # apt-get -f install softname 强制安装
**2、软件卸载**
    移除试卸载：    # apt-get remove softname
    清除式卸载：    # apt-get --purge remove softname(同时清除配置)
                    # apt-get purge softname
                    # apt-get autoremove --purge softname(删除包以及依赖的软件包和配置文件等)
**3、软件搜索**
    # apt-cache search package
**4、更新**
    # apt-get update        更新源
    # apt-get upgrade       更新已安装的包
    # apt-get dist-upgrade  升级系统
**5、依赖**
    # apt-cache depends     了解包的依赖关系
    # apt-cache rdepends    了解某个具体的依赖
**6、其他**
    # apt-get build-dep     安装相关的编译环境
    # apt-get source        下载包的源码
    # apt-get clean         清理下载文件的存档
    # apt-get autoclean     只清理过时的包
**7、解压命令**
注意：tar是打包，不是压缩
    解压xx.tar.gz： tar zxf xx.tar.gz
    解压xx.tar.Z：  tar zxf xx.tar.Z
    解压xx.tgz：    tar zxf xx.tgz
    解压xx.bz2：    bunzip2 xx.bz2  / bzip2 -d xx.bz2
    解压xx.tar：    tar xf xx.tar
    解压xx.zip：    unzip xx.zip
**压缩命令**
    压缩xx.tar：    tar cvf xx.tar dirname
    压缩xx.gz ：    gzip filename
    压缩xx.tar.gz:  tar zcvf xx.tar.gz dirname
    






